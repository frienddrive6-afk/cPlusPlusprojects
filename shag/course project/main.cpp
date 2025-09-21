#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <filesystem> 
#include <ncurses.h>

using namespace std;


struct Sounds
{
    string title;
    string author;
    int year;
    string source_filename;

};

enum ScreenState {
    MAIN_MENU,
    CREATESOUND, 
    PRINTSOUND,
    DELATESONG,
    EDITSONG,
    FINDBYAUTHOR,      
    EXIT_PROGRAM
};

//======================NCURSES FUNCSION START========================



//Создает по наданым параметрам меню с выбором, выбор осуществляется с помошью стрелочек 
int show_menu(const string& title, const vector<string>& items) {
    int highlight = 0;
    int key_pressed;

    int max_len = 0;
    for (const string& item : items) 
    {
        if (item.length() > max_len) 
        {
            max_len = item.length();
        }
    }

    while (true) {
        int y, x;
        getmaxyx(stdscr, y, x);
        clear();
        
        mvprintw(2, (x - title.length()) / 2, "%s", title.c_str());
        
        int start_x = (x - max_len) / 2;

        for (int i = 0; i < items.size(); ++i) {
            if (i == highlight) attron(A_REVERSE);
            
            mvprintw(4 + i, start_x, "%s", items[i].c_str());
            
            if (i == highlight) attroff(A_REVERSE);
        }
        refresh();

        key_pressed = getch();
        switch (key_pressed) {
            case KEY_UP:
                if (highlight > 0) highlight--;
                break;
            case KEY_DOWN:
                if (highlight < items.size() - 1) highlight++;
                break;
            case 10: case KEY_ENTER:
                return highlight;
            case 27: // Esc
                return -1;
        }
    }
}

//Функция позволяет получитать информацию в интерфейсе ncurses в виде ввода текста аналог cin
string get_string_from_user(int y, int x, const string& prompt) {
    string result = "";
    int ch;

    mvprintw(y, x, "%s", prompt.c_str());

    curs_set(1);
    echo();
    
    move(y, x + prompt.length());
    refresh(); 

    while ((ch = getch()) != '\n' && ch != KEY_ENTER) {
        if (ch == KEY_BACKSPACE || ch == 127) {
            if (!result.empty()) {
                result.pop_back();
                
                int current_y, current_x;
                getyx(stdscr, current_y, current_x); 
                mvaddch(current_y, current_x, ' ');   
                move(current_y, current_x);           
            }
        } else {
            result += ch;
        }
    }
    
    noecho();
    curs_set(0);

    return result;
}


//Выводит песни на экран ncurses
void show_song_list_screen(const vector<Sounds>& song_catalog,ScreenState &screen_state ) {
    clear();
    int y, x;
    getmaxyx(stdscr, y, x);

    mvprintw(1, 2, "--- Список всіх пісень ---");

    if (song_catalog.empty()) {
        mvprintw(3, 2, "Каталог порожній.");
    } else {
        for (int i = 0; i < song_catalog.size(); ++i) {
            if (3 + i >= y - 1) { 
                mvprintw(y - 2, 2, "...");
                break;
            }
            mvprintw(3 + i, 2, "%d. %s - %s (%d)", i + 1,
                     song_catalog[i].author.c_str(),
                     song_catalog[i].title.c_str(),
                     song_catalog[i].year);
        }
    }

    mvprintw(y - 1, 2, "Натисніть будь-яку клавішу, щоб повернутися...");
    refresh();
    getch();

    screen_state = MAIN_MENU;

}


vector<string> get_lyrics_from_user(int start_y, int start_x) {
    
    attron(A_BOLD);
    mvprintw(start_y, start_x, "Введіть текст. Натисніть Ctrl+D для завершення.");
    attroff(A_BOLD);

    start_y++; 

    vector<string> all_lines;
    string current_line = "";
    int ch;
    
    curs_set(1);
    echo();

    int y = start_y;
    int x = start_x;
    move(y, x);
    refresh();

    while (true) {
        ch = getch();

        if (ch == 4) { //Нажат ли ctrl + D
            break; 
        }

        switch (ch) {
            case KEY_ENTER:
            case 10: // Enter
                all_lines.push_back(current_line); 
                current_line.clear();              
                y++;                               
                x = start_x;
                move(y, x);
                break;

            case KEY_BACKSPACE:
            case 127: // Backspace
                if (!current_line.empty()) {
                    current_line.pop_back();

                    int current_y, current_x;
                    getyx(stdscr, current_y, current_x);
                    mvaddch(current_y, current_x, ' ');
                    move(current_y, current_x);
                }
                break;
            
            default: 
                
                int term_y, term_x;
                getmaxyx(stdscr, term_y, term_x);
                if (x + current_line.length() < term_x - 1) {
                    current_line += ch;
                }
                break;
        }
        refresh();
    }
    
    if (!current_line.empty()) {
        all_lines.push_back(current_line);
    }
    
    noecho();
    curs_set(0);

    return all_lines;
}








//======================NCURSES FUNCSION END========================




void saveSongToFile(const Sounds& song, const vector<string>& lyrics,const int choice)
{

    ofstream fileW(song.source_filename);
    if (!fileW.is_open()) {
        if(choice == 1)
        {
            cout << "ОШИБКА при открытии файла!" << endl;
        }
        return;
    }


    fileW<<"Название песни:"<<song.title<<";"<<endl;
    fileW<<"Имя автора:"<<song.author<<";"<<endl;
    fileW<<"Год выпуска:"<<song.year<<";"<<endl;

    for(int i = 0;i < 3;i++)
    {
        fileW<<endl;
    }
    fileW<<"-----------------------------"<<endl;

    for(string line : lyrics)
    {
        fileW<<line<<endl;
    }

    fileW<<"-----------------------------"<<endl;

}



void parseSongFile(string &db_dir_path,vector<Sounds> &song_catalog)
{
    if(!filesystem::is_empty(db_dir_path))
    {
        for (const auto& entry : filesystem::directory_iterator(db_dir_path))
        {
            string thisPath;
            Sounds new_song;
            thisPath = entry.path();

            ifstream fileR(thisPath);
            if(!fileR.is_open())
            {
                cout << "ОШИБКА при открытии файла!" << endl;
            }

            int line_index = 0;
            string line;

            string title,autor;
            int year = 0;

            while (getline(fileR,line))
            {
                if(line_index == 0)
                {
                    if(line.find("Название песни:") != string::npos)
                    {

                        int start_pos = line.find(':') + 1; 
                        int end_pos = line.rfind(';');

                        if (start_pos != string::npos && end_pos != string::npos) 
                        {
                            int length = end_pos - start_pos; 
                            title = line.substr(start_pos, length);
                        }

                        // cout<<title<<endl;
                        new_song.title = title;
                    }
                    line_index++;

                }else if(line_index == 1)
                {
                    if(line.find("Имя автора:") != string::npos)
                    {

                        int start_pos = line.find(':') + 1; 
                        int end_pos = line.find(';');

                        if (start_pos != string::npos && end_pos != string::npos) 
                        {
                            int length = end_pos - start_pos; 
                            autor = line.substr(start_pos, length);
                        }

                        // cout<<autor<<endl;
                        new_song.author = autor;
                    }
                    line_index++;

                }else if(line_index == 2)
                {
                    if(line.find("Год выпуска:") != string::npos)
                    {

                        int start_pos = line.find(':') + 1; 
                        int end_pos = line.find(';');

                        if (start_pos != string::npos && end_pos != string::npos) 
                        {
                            int length = end_pos - start_pos; 
                            year = stoi(line.substr(start_pos, length));
                        }

                        // cout<<year<<endl;
                        new_song.year = year;
                    }
                    line_index++;


                }else if(line_index >= 3)
                {
                    break;
                }


            }

            if(!title.empty() && !autor.empty() && year != 0)
            {
                // cout<<"Ошибок чтения файла НЕТ"<<endl;
                // cout<<endl;

                new_song.title = title;
                new_song.author = autor;
                new_song.year = year;
                new_song.source_filename = thisPath;

                song_catalog.push_back(new_song);
            }
            // else
            // {
            //     cout<<"Ошибка чтения данные не сохраняются"<<endl;
            // }
            

            


            fileR.close();
        }
    }else
    {
        cout<<"Увы пока что нет ни одной музыки"<<endl;
    }
}

void loadSongs(string &db_dir_path,vector<Sounds> &song_catalog)
{
    if(!filesystem::exists(db_dir_path))
    {
        cout<<"По пути по умолчанию папки с песнями нету :( у вас два варианта\n1)указать путь к папке если она существовала\n2)создать папку и начать добавление песен";
        int vubor;
        cin>>vubor;
        if(vubor == 1)
        {
            cout<<"уккажите новый ПОЛНЫЙ путь к папке с музыками: ";
            cin>>db_dir_path;
        }else if(vubor == 2)
        {
            filesystem::create_directory(db_dir_path);
            cout<<"Была создана папка для хранения песен по такому пути -> "<< db_dir_path <<endl; 
        }
    }

    parseSongFile(db_dir_path,song_catalog);
    
}

string zamenaSpasNa_(string &start_name)
{
    string end_name;
    for(auto b: start_name)
    {
        if(b != ' ')
        {
            end_name.push_back(b);
        }else
        {
            end_name.push_back('_');
        }
    }

    return end_name;
}

void createSound(string &db_dir_path,vector<Sounds> &song_catalog,const int choice, ScreenState* screen_state_ptr = nullptr)
{

    Sounds new_song;
    vector<string> lyrics;

    switch (choice)
    {
        case 1:
        {   
            cout<<"Введите название песни: ";
            getline(cin,new_song.title);

            cout<<"Введите имя автора: ";
            getline(cin,new_song.author);

            cout<<"Введите год выпуска: ";
            cin>>new_song.year;
            cin.ignore();

            break;
        }
        
        case 2:
        {
            clear();
            new_song.title = get_string_from_user(0, 0, "Введите название песни: ");
            
            clear();
            new_song.author = get_string_from_user(0, 0, "Введите имя автора: ");

            clear();
            new_song.year = stoi(get_string_from_user(0, 0, "Введите год выпуска: "));

            break;
        }

    }
    

    string titleNoneSpase = zamenaSpasNa_(new_song.title);
    string authorNoneSpase = zamenaSpasNa_(new_song.author);

    new_song.source_filename = db_dir_path+"/"+titleNoneSpase+"_"+authorNoneSpase+".txt";


    int vubor;
    switch (choice)
    {
        case 1:
        { 
            cout<<"теперь надо добавить текст тут два варианта\n1)добавление в ручную\n2)Добавление из файла(указать полный путь к файлу с текстом)\nВаш выбор: ";
            cin>>vubor;
            cin.ignore(); 
            break;
        }

        case 2:
        {
            vector<string> items = {"1)добавление в ручную","2)Добавление из файла(указать полный путь к файлу с текстом)"};
            vubor = show_menu("Надо добавить текст тут два варианта",items)+1;
            break;
        }

    }


    if(vubor == 1)
    {
        switch (choice)
        {
            case 1:
            { 
                cout<<"Введите * для того что бы завершить"<<endl;
                while (true)
                {
                    string line;
                    getline(cin,line);
                    if(line == "*")
                    {
                        break;
                    }else{
                        lyrics.push_back(line);
                    }
                }
                break;
            }
            case 2:
            {
                clear();
                lyrics = get_lyrics_from_user(0, 0);


                break;
            }


        }
        
    }else if(vubor == 2)
    {
        
        string fullPathToSoundText;


        switch (choice)
        {
            case 1:
            { 
                cout<<"Введите полны путь к файлу: ";
                getline(cin, fullPathToSoundText);
                break;
            }

            case 2:
            {
                clear();
                fullPathToSoundText = get_string_from_user(0, 0, "Введите полны путь к файлу: ");
                break;
            }

        }



        ifstream fileR(fullPathToSoundText);
        if(!fileR.is_open())
        {
            if(choice != 2)
            {
                cout << "ОШИБКА при открытии файла!" << endl;
            }
            return;
        }

        string line;

        while (getline(fileR,line))
        {
            lyrics.push_back(line);
        }
        
    }




    song_catalog.push_back(new_song);

    saveSongToFile(new_song,lyrics,choice);

    if(screen_state_ptr != nullptr)
    {
        *screen_state_ptr = MAIN_MENU;
    }

}


void displayAllSongs(vector<Sounds> &song_catalog)
{
    cout<<endl;
    cout<<"\033[33m----------Начало вывода-----------\033[0m\n"<<endl;
    int i = 1;
    for(Sounds song : song_catalog)
    {
        cout<<"Песня номер -> \033[31m"<< i <<"\033[0m"<<endl;
        cout<<"\033[34mНазвание песни: \033[32m" <<song.title<<endl;
        cout<<"\033[34mАвтор: \033[32m"<<song.author<<endl;
        cout<<"\033[34mГод выпуска: \033[32m"<<song.year<<"\033[0m"<<endl;
        cout<<endl;
        i++;
    }



    cout<<"\033[33m---------Конец--------\033[30m"<<endl;
    cout<<"\033[0m"<<endl;
}

void deleteSong(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr)
{
    int delated_index;
    switch (choice)
    {
        case 1:
        {
            cout<<"\nВведите номер песни какую ходите удалить(начало с 1): ";
            cin>>delated_index;
            break;
        }

        case 2:
        {
            clear();
            delated_index = stoi(get_string_from_user(0,0,"Введите номер песни какую ходите удалить(начало с 1): "));
            break;
        }

    }
    

    string delate_path_file = song_catalog[delated_index-1].source_filename;

    song_catalog.erase(song_catalog.begin()+delated_index-1);
    filesystem::remove(delate_path_file);

    if(screen_state != nullptr)
    {

        *screen_state = MAIN_MENU;
    }

}


void updateAndRenameSong(Sounds &song_to_edit,const vector<string> &soung_text,const int choice)
{

    string old_full_path = song_to_edit.source_filename;

    string new_song_name = zamenaSpasNa_(song_to_edit.title);
    string new_author_name = zamenaSpasNa_(song_to_edit.author);
    string new_file_name = new_song_name + "_" + new_author_name + ".txt";

    filesystem::path old_full_type_path = old_full_path;
    
    string new_full_path = old_full_type_path.parent_path().string() + "/" + new_file_name;


    if(old_full_path != new_full_path)
    {
        filesystem::rename(old_full_path,new_full_path);
    }

    song_to_edit.source_filename = new_full_path;

    saveSongToFile(song_to_edit, soung_text,choice);
}

vector<string> readTextFromFile(string &path_to_file)
{
    ifstream fileR(path_to_file);
    if(!fileR.is_open())
    {
        cout << "ОШИБКА при открытии файла!" << endl;
        return vector<string>();
    }

    vector<string> soung_text;

    string line;
    bool is_started = false;
    while (getline(fileR,line))
    {
        if(line == "-----------------------------")
        {
            is_started = !is_started;
            continue;
        }
        if(is_started == true)
        {
            soung_text.push_back(line);
        }
    }



    fileR.close();

    return soung_text;
}

void writeTextToFile(string &path_to_file,const vector<string> &soung_text)
{

    ofstream fileW(path_to_file);
    for(string line: soung_text)
    {
        fileW<<line<<endl;
    }

    fileW.close();
}

void editSong(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr)
{

    int redacted_index;
    switch (choice)
    {
        case 1:
        {
            cout<<"\nВведите номер песни изменить(начало с 1): ";
            cin>>redacted_index;
            break;
        }

        case 2:
        {
            clear();
            redacted_index = stoi(get_string_from_user(0, 0,"Введите номер песни изменить(начало с 1): "));
            break;
        }
    

    }
    
    
    



    if (redacted_index < 1 || redacted_index > song_catalog.size()) {
        if(choice == 1)
        {
            cout << "Ошибка не верный номер песни" << endl;
        }
        return;
    }



    vector<string> soung_text = readTextFromFile(song_catalog[redacted_index-1].source_filename);
    Sounds &song_to_edit = song_catalog[redacted_index-1];

    int vubor;

    switch (choice)
    {
        case 1:
        {
            cout<<"Введите параметр какой хотите изменить\n1)Название песни\n2)Имя автора\n3)Год выпуска\n4)Текст песни(Прийдется писать весь заново)\nВаш выбор: ";
            cin>>vubor;
            cin.ignore();
            break;
        }

        case 2:
        {
            vector<string> items_menu = {"1)Название песни","2)Имя автора","3)Год выпуска","4)Текст песни(Прийдется писать весь заново)"};
            vubor = show_menu("Параметр какой хотите изменить", items_menu)+1;
            break;
        }
    
    }

    

    
    switch (vubor)
    {
        case 1:
        {   

            switch (choice)
            {
                case 1:
                {
                    cout<<"Введите новое название песни: ";
                    getline(cin,song_to_edit.title);
                    break;
                }

                case 2:
                {
                    clear();
                    song_to_edit.title = get_string_from_user(0, 0,"Введите новое название песни: ");
                    break;
                }
            
            }
            break;
        }

        case 2:
        {

            switch (choice)
            {
                case 1:
                {
                    cout<<"Введите новое имя автора: ";
                    getline(cin,song_to_edit.author);
                    break;
                }

                case 2:
                {
                    clear();
                    song_to_edit.author = get_string_from_user(0,0,"Введите новое имя автора: ");
                    break;
                }
            
            }
            break;
        }

        case 3:
        {

            switch (choice)
            {
                case 1:
                {
                    cout<<"Введите новый год выпуска: ";
                    cin>>song_to_edit.year;
                    break;
                }

                case 2:
                {
                    clear();
                    song_to_edit.year = stoi(get_string_from_user(0,0,"Введите новый год выпуска: "));
                    break;
                }
            
            }
            break;
        }

        case 4:
        {
            soung_text.clear();


            switch (choice)
            {
                case 1:
                {
                    cout<<"Введите * для того что бы завершить"<<endl;
                    while (true)
                    {
                        string line;
                        getline(cin,line);
                        if(line == "*")
                        {
                            break;
                        }else{
                            soung_text.push_back(line);
                        }
                    }
                    break;
                }

                case 2:
                {
                    soung_text = get_lyrics_from_user(0,0);
                    break;
                }
            
            }
            break;
        }

    }

    updateAndRenameSong(song_to_edit,soung_text,choice);

    if(screen_state != nullptr)
    {
        *screen_state = MAIN_MENU;
    }
}



void findSongsByAuthor(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr)
{

    string author_name;

    switch (choice)
    {
        case 1:
        {   
            cout<<"Введтие имя автора по которому бдем искать: ";
            getline(cin,author_name);
            break;
        }

        case 2:
        {
            clear();
            author_name = get_string_from_user(0,0,"Введтие имя автора по которому бдем искать: ");
            break;
        }
    
    
    }

    int current_y = 1;
    const int x_coordinate = 4;
    switch (choice)
            {
                case 1:
                {
                    cout<<"Этому автору пренадлежат такие песни как: "<<endl;
                    break;
                }

                case 2:
                {
                    clear();
                    mvprintw(current_y,x_coordinate,"Этому автору пренадлежат такие песни как: ");
                    current_y++;
                    break;
                }
            
            }
    

    int count = 0;
    for(const Sounds& name: song_catalog)
    {
        if(name.author == author_name)
        {
            switch (choice)
            {
                case 1:
                {
                    cout<<count+1<<")"<<name.title<<" "<<name.year<<" года выпуска"<<endl;
                    break;
                }

                case 2:
                {
                    // clear();
                    mvprintw(current_y,x_coordinate,"%d)%s %d года выпуска",count+1,name.title.c_str(),name.year);
                    current_y++;
                    refresh();
                    break;
                }
            
            }

            count++;
        }
    }

    if(count == 0)
    {
        switch (choice)
            {
                case 1:
                {
                    cout<<"Песен связаных с этим автором не обнаружено :("<<endl;
                    break;
                }

                case 2:
                {
                    clear();
                    mvprintw(current_y,x_coordinate,"Песен связаных с этим автором не обнаружено :(");
                    break;
                }
            
            }

    }

    if (choice == 2) {
        int y = getmaxy(stdscr);
        mvprintw(y - 1, 2, "Нажмите любую клавишу, чтобы вернуться в главное меню...");
        refresh();
        getch(); 
    }


    if(screen_state != nullptr)
    {
        *screen_state = MAIN_MENU;
    }
}



void findSongsByWord(vector<Sounds> &song_catalog)
{
    cout<<"Введите слово которое вы хотите найти в песне(Ответ название песни в котором есть это слово если оно имеется): ";
    string word;
    cin>>word;

    for(Sounds song: song_catalog)
    {
        string path_to_file = song.source_filename;
        vector<string> soung_text = readTextFromFile(path_to_file);

        int count_this_word = 0;
        for(string linee : soung_text)
        {
            if(linee.find(word) != string::npos)
            {
                count_this_word++;
            }
        }

        if(count_this_word > 0)
        {
            // cout<<"В песне под названием " <<song.title <<" автора "<< song.author<<" было найдено это слово " <<count_this_word<<" раз"<<endl;
            cout<<"В песне под названием " <<song.title <<" автора "<< song.author<<endl;
        }

    }
}


void displayFullSong(vector<Sounds> &song_catalog)
{
    cout<<"Выбере способ отображение песни\n1)Вывести в терминал\n2)Открыть в текстовом редакторе по умолчанию\nВаш выбор: ";
    int vubor;
    cin>>vubor;


    cout<<"Выберете номер песню которую хотите вывести(Начинается с 1): ";
    int number;
    cin>>number;

    switch (vubor)
    {
        case 1:
            {
            cout<<"Название песни: "<<song_catalog[number-1].title<<endl;
            cout<<"Имя автора: "<<song_catalog[number-1].author<<endl;
            cout<<"Год выпуска: "<<song_catalog[number-1].year<<endl;
            cout<<"\n"<<endl;

            cout<<"----------Текст песни----------"<<endl;
            
            string file_path = song_catalog[number-1].source_filename;
            vector<string> soung_text = readTextFromFile(file_path);


            for(string linee : soung_text)
            {
                cout<<linee<<endl;
            }

            cout<<"----------Конец песни----------"<<endl;

            

            break;
        }
        case 2:
        {
            string command  = "xdg-open \"" + song_catalog[number-1].source_filename + "\"";
            system(command.c_str());
            break;
        }
    }
}


void saveTextSongToFile(vector<Sounds> &song_catalog)
{
    cout<<"Выберете песню которую хотите сохранить: ";
    int song_index;
    cin>>song_index;

    string path_to_file = song_catalog[song_index-1].source_filename;
    vector<string> soung_text = readTextFromFile(path_to_file);

    cin.ignore();
    cout<<"Введите полный путь в который вы хотите сохранить песню: ";
    // string path_to_file;
    getline(cin,path_to_file);


    writeTextToFile(path_to_file,soung_text);

}


void workWithUser(vector<Sounds> &song_catalog,string &db_dir_path)
{

    cout<<"Выберети тип интерфейса\n1)Стандартный(старый)\n2)Через nurses(Новый)\nВаш выбор: ";
    int choice;
    cin>>choice;

    switch (choice)
    {
        case 1:
        {

            while (true)
            {
                cout<<"Доброго времени суток пользователь.\nВас приведствует программа \"Каталог текстов и песен\".\nВот вы можете сделать:\n1)Добавить новую песню.\n2)Вывести все существующие песни на экран.\n3)Удалить песню.\n4)Редактировать информацию о песне и текст песни.\n5)Найти все песни автора.\n6)Найти песни в тексте которых есть указаное вами слово.\n7)Вывести полностью текст песни.\n8)Сохранить текст песни в txt файл в указаный вами путь.\nДля того чтобы закончить введите любую другую цыфру.\nВаш выбор: ";
                int choise;
                cin>>choise;

                cin.ignore();

                switch (choise)
                {
                    case 1:
                    {
                        createSound(db_dir_path,song_catalog,choice);
                        break;
                    }

                    case 2:
                    {
                        displayAllSongs(song_catalog);
                        break;
                    }

                    case 3:
                    {
                        deleteSong(song_catalog,choice);
                        break;
                    }

                    case 4:
                    {
                        editSong(song_catalog,choice);
                        break;
                    }

                    case 5:
                    {
                        findSongsByAuthor(song_catalog,choice);
                        break;
                    }

                    case 6:
                    {
                        findSongsByWord(song_catalog);
                        break;
                    }

                    case 7:
                    {
                        displayFullSong(song_catalog);
                        break;
                    }

                    case 8:
                    {
                        saveTextSongToFile(song_catalog);
                        break;
                    }
                
                    default:
                        return;
                        break;
                }
            }

            break;
        }

        case 2:
        {
            setlocale(LC_ALL, "");
            initscr();
            noecho();
            cbreak();
            keypad(stdscr, true);
            curs_set(0);

            vector<string> main_menu_items = { 
                "1)Добавить новую песню",
                "2)Вывести все существующие песни на экран",
                "3)Удалить песню",
                "4)Редактировать информацию о песне и текст песни",
                "5)Найти все песни автора",
                "6)Найти песни в тексте которых есть указаное вами слово",
                "7)Вывести полностью текст песни",
                "8)Сохранить текст песни в txt файл в указаный вами путь",
                "Закончить"};


            ScreenState current_screen = MAIN_MENU;

            while (current_screen != EXIT_PROGRAM) {

                switch (current_screen)
                {
                    case MAIN_MENU:
                    {
                        int show_menu_res = show_menu("Главное меню программа \"Каталог текстов и песен\"", main_menu_items);
                        if(show_menu_res == 0)
                        {
                            current_screen = CREATESOUND;

                        }else if(show_menu_res == 1)
                        {

                            current_screen = PRINTSOUND;

                        }else if(show_menu_res == 2)
                        {
                            current_screen = DELATESONG;

                        }else if(show_menu_res == 3)
                        {
                            current_screen = EDITSONG;

                        }else if(show_menu_res == 4)
                        {
                            current_screen = FINDBYAUTHOR;

                        }else if(show_menu_res == 8 || show_menu_res == -1)
                        {
                            current_screen = EXIT_PROGRAM;
                        }


                        break;
                    }

                    case CREATESOUND:
                    {

                        createSound(db_dir_path,song_catalog,choice,&current_screen);
                        break;
                    }

                    case PRINTSOUND:
                    {
                        show_song_list_screen(song_catalog,current_screen);

                        break;
                    }

                    case DELATESONG:
                    {

                        deleteSong(song_catalog,choice,&current_screen);
                        break;
                    }

                    case EDITSONG:
                    {

                        editSong(song_catalog,choice,&current_screen);
                        break;
                    }

                    case FINDBYAUTHOR:
                    {
                        findSongsByAuthor(song_catalog,choice,&current_screen);
                        break;
                    }



                }





            }






            endwin();
            break;
        }
        
        default:
        {
            cout<<""<<endl;
            break;
        }

    }
    
}


int main()
{
    setlocale(LC_ALL, "");

    string db_dir_path = "./sound";

    vector<Sounds> song_catalog;


    loadSongs(db_dir_path,song_catalog);

    // displayAllSongs(song_catalog);

    // deleteSong(song_catalog);

    // createSound(db_dir_path,song_catalog);

    // editSong(song_catalog);

    // findSongsByAuthor(song_catalog);

    // findSongsByWord(song_catalog);

    // displayFullSong(song_catalog);

    // saveTextSongToFile(song_catalog);

    workWithUser(song_catalog,db_dir_path);


    return 0;
}