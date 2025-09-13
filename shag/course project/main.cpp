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
                        int end_pos = line.find(';');

                        if (start_pos != string::npos && end_pos != string::npos) 
                        {
                            int length = end_pos - start_pos; 
                            title = line.substr(start_pos, length);
                        }

                        cout<<title<<endl;
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

                        cout<<autor<<endl;
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

                        cout<<year<<endl;
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
                cout<<"Ошибок чтения файла НЕТ"<<endl;
                cout<<endl;

                new_song.title = title;
                new_song.author = autor;
                new_song.year = year;
                new_song.source_filename = thisPath;

                song_catalog.push_back(new_song);
            }else
            {
                cout<<"Ошибка чтения данные не сохраняются"<<endl;
            }
            

            


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

int main()
{

    string db_dir_path = "./sound";

    vector<Sounds> song_catalog;


    loadSongs(db_dir_path,song_catalog);

    createSound(db_dir_path,song_catalog);


    return 0;
}