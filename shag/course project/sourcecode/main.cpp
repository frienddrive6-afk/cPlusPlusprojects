#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <filesystem> 
#include <ncurses.h>

#include "declarations.h"

using namespace std;



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
                        findSongsByWord(song_catalog,choice);
                        break;
                    }

                    case 7:
                    {
                        displayFullSong(song_catalog,choice);
                        break;
                    }

                    case 8:
                    {
                        saveTextSongToFile(song_catalog,choice);
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

                        }else if(show_menu_res == 5)
                        {
                            current_screen = FINDBYWORD;
                        }else if(show_menu_res == 6)
                        {
                            current_screen = TEXTONDISPLAY;

                        }else if(show_menu_res == 7)
                        {
                            current_screen = SAVETOFILE;

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

                    case FINDBYWORD:
                    {
                        findSongsByWord(song_catalog,choice,&current_screen);
                        break;
                    }

                    case TEXTONDISPLAY:
                    {
                        displayFullSong(song_catalog,choice,&current_screen);
                        break;
                    }

                    case SAVETOFILE:
                    {
                        saveTextSongToFile(song_catalog,choice,&current_screen);
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


    workWithUser(song_catalog,db_dir_path);


    return 0;
}