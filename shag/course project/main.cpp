#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <filesystem> 

using namespace std;


struct Sounds
{
    string title;
    string author;
    int year;
    string source_filename;

};

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

void createSound(string &db_dir_path,vector<Sounds> &song_catalog)
{
    // string title,author_name;
    // int year;
    Sounds new_song;

    cout<<"Введите название песни: ";
    getline(cin,new_song.title);

    cout<<"Введите имя автора: ";
    getline(cin,new_song.author);

    cout<<"Введите год выпуска: ";
    cin>>new_song.year;
    cin.ignore();

    string titleNoneSpase = zamenaSpasNa_(new_song.title);
    string authorNoneSpase = zamenaSpasNa_(new_song.author);

    new_song.source_filename = db_dir_path+"/"+titleNoneSpase+"_"+authorNoneSpase+".txt";
    ofstream fileW(new_song.source_filename);
    if (!fileW.is_open()) {
        cout << "ОШИБКА при открытии файла!" << endl;
        return;
    }


    fileW<<"Название песни:"<<new_song.title<<";"<<endl;
    fileW<<"Имя автора:"<<new_song.author<<";"<<endl;
    fileW<<"Год выпуска:"<<new_song.year<<";"<<endl;

    for(int i = 0;i < 3;i++)
    {
        fileW<<endl;
    }
    fileW<<"-----------------------------"<<endl;
    
    cout<<"теперь надо добавить текст тут два варианта\n1)добавление в ручную\n2)Добавление из файла(указать полный путь к файлу с текстом)\nВаш выбор: ";
    int vubor;
    cin>>vubor;
    cin.ignore(); 
    if(vubor == 1)
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
                fileW<<line<<endl;
            }
        }
        
    }else if(vubor == 2)
    {
        string fullPathToSoundText;

        cout<<"Введите полны путь к файлу: ";
        getline(cin, fullPathToSoundText);

        ifstream fileR(fullPathToSoundText);
        if(!fileR.is_open())
        {
            cout << "ОШИБКА при открытии файла!" << endl;
            fileW.close();
            return;
        }

        string line;

        while (getline(fileR,line))
        {
            fileW<<line<<endl;
        }
        
    }



    fileW<<"-----------------------------"<<endl;

    song_catalog.push_back(new_song);
    fileW.close();
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

void deleteSong(vector<Sounds> &song_catalog)
{
    cout<<"\nВведите номер песни какую ходите удалить(начало с 1): ";
    int delated_index;
    cin>>delated_index;

    string delate_path_file = song_catalog[delated_index-1].source_filename;

    song_catalog.erase(song_catalog.begin()+delated_index-1);
    filesystem::remove(delate_path_file);
}


void editSong(vector<Sounds> &song_catalog)
{
    cout<<"\nВведите номер песни изменить(начало с 1): ";
    int redacted_index;
    cin>>redacted_index;

    ifstream fileR(song_catalog[redacted_index-1].source_filename);
    if(!fileR.is_open())
    {
        cout << "ОШИБКА при открытии файла!" << endl;
        return;
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

    cout<<"Введите параметр какой хотите изменить\n1)Название песни\n2)Имя автора\n3)Год выпуска\n4)Текст песни(Прийдется писать весь заново)\nВаш выбор: ";
    int vubor;
    cin>>vubor;

    cin.ignore();
    switch (vubor)
    {
        case 1:
            cout<<"Введите новое название песни: ";
            getline(cin,song_catalog[redacted_index-1].title);
            break;
        case 2:
            cout<<"Введите новое имя автора: ";
            getline(cin,song_catalog[redacted_index-1].author);
            break;
        case 3:
            cout<<"Введите новый год выпуска: ";
            cin>>song_catalog[redacted_index-1].year;
            break;
        case 4:
            soung_text.clear();

            

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

    ofstream fileW(song_catalog[redacted_index-1].source_filename);

    fileW<<"Название песни:"<<song_catalog[redacted_index-1].title<<";"<<endl;
    fileW<<"Имя автора:"<<song_catalog[redacted_index-1].author<<";"<<endl;
    fileW<<"Год выпуска:"<<song_catalog[redacted_index-1].year<<";"<<endl;

    for(int i = 0;i < 3;i++)
    {
        fileW<<endl;
    }
    fileW<<"-----------------------------"<<endl;

    for(string linee : soung_text)
    {
        fileW<<linee<<endl;
    }
    fileW<<"-----------------------------"<<endl;

    fileW.close();


}



void findSongsByAuthor(vector<Sounds> &song_catalog)
{
    cout<<"Введтие имя автора по которому бдем искать: ";
    string author_name;
    getline(cin,author_name);

    cout<<"Этому автору пренадлежат такие песни как: "<<endl;
    int count = 0;
    for(Sounds name: song_catalog)
    {
        if(name.author == author_name)
        {
            cout<<count+1<<")"<<name.title<<" "<<name.year<<" года выпуска"<<endl;
            count++;
        }
    }

    if(count == 0)
    {
        cout<<"Песен связаных с этим автором не обнаружено :("<<endl;
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

        ifstream fileR(path_to_file);
        if(!fileR.is_open())
        {
            cout << "ОШИБКА при открытии файла!" << endl;
            return;
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
            cout<<"В песне под названием " <<song.title <<" автора "<< song.author<<" было найдено это слово " <<count_this_word<<" раз"<<endl;
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

            ifstream fileR(song_catalog[number-1].source_filename);
            if(!fileR.is_open())
            {
                cout << "ОШИБКА при открытии файла!" << endl;
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

            for(string linee : soung_text)
            {
                cout<<linee<<endl;
            }

            cout<<"----------Конец песни----------"<<endl;

            fileR.close();

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




int main()
{

    string db_dir_path = "./sound";

    vector<Sounds> song_catalog;


    loadSongs(db_dir_path,song_catalog);

    displayAllSongs(song_catalog);

    // deleteSong(song_catalog);

    // createSound(db_dir_path,song_catalog);

    // editSong(song_catalog);

    // findSongsByAuthor(song_catalog);

    // findSongsByWord(song_catalog);

    displayFullSong(song_catalog);


    return 0;
}