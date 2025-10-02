#include <iostream>
#include <unistd.h> 
#include <vector> 
// #include <conio.h> //Для работы с клавишами 
// #include <io.h> //Вывод символов Юникод та псевдографики
// #include <fcntl.h>

#include <ncurses.h>


#include "textGame.h"
#include "graficgame.h"


using namespace std;

void play_sound(const string& sound_file) {
    string command = "aplay " + sound_file + " >/dev/null 2>&1 &";
    system(command.c_str());
}


void pause_animation_2() {
    for (int i = 0; i < 3; i++) {
        usleep(1000 * 1000); 
    }
}

void draw_dice(int start_y, int start_x, int number) {
    mvprintw(start_y + 0, start_x, "----------------");
    mvprintw(start_y + 1, start_x, "|              |");
    mvprintw(start_y + 2, start_x, "|              |");
    mvprintw(start_y + 3, start_x, "|              |");
    mvprintw(start_y + 4, start_x, "|              |");
    mvprintw(start_y + 5, start_x, "|              |");
    mvprintw(start_y + 6, start_x, "----------------");
    
    switch (number) {
        case 1:
            mvprintw(start_y + 3, start_x + 7, "##");
            break;
        case 2:
            mvprintw(start_y + 2, start_x + 3, "##");
            mvprintw(start_y + 4, start_x + 11, "##");
            break;
        case 3:
            mvprintw(start_y + 2, start_x + 3, "##");
            mvprintw(start_y + 3, start_x + 7, "##");
            mvprintw(start_y + 4, start_x + 11, "##");
            break;
        case 4:
            mvprintw(start_y + 2, start_x + 3, "##");
            mvprintw(start_y + 2, start_x + 11, "##");
            mvprintw(start_y + 4, start_x + 3, "##");
            mvprintw(start_y + 4, start_x + 11, "##");
            break;
        case 5:
            mvprintw(start_y + 2, start_x + 3, "##");
            mvprintw(start_y + 2, start_x + 11, "##");
            mvprintw(start_y + 3, start_x + 7, "##");
            mvprintw(start_y + 4, start_x + 3, "##");
            mvprintw(start_y + 4, start_x + 11, "##");
            break;
        case 6:
            mvprintw(start_y + 2, start_x + 3, "##");
            mvprintw(start_y + 2, start_x + 11, "##");
            mvprintw(start_y + 3, start_x + 3, "##");
            mvprintw(start_y + 3, start_x + 11, "##");
            mvprintw(start_y + 4, start_x + 3, "##");
            mvprintw(start_y + 4, start_x + 11, "##");
            break;
    }
}



int show_horizontal_menu(vector<string> items,int user_count,int pc_count,string& path)
{

    int current = 0;
    int key_pressed;

    while (true)
    {
        // clear();
        for (int y = 0; y <= 3; ++y) {
            move(y, 0);      
            clrtoeol();      
        }
    
        int cur_y,cur_x;

        getmaxyx(stdscr, cur_y, cur_x);

        mvprintw(0, (cur_x / 2) - 22, "Баллы :  Игрок - %d  Бот - %d",user_count,pc_count);

        if(current == 0){attron(COLOR_PAIR(1));}

        mvprintw(1, (cur_x / 2) - 25, "==============");
        mvprintw(2, (cur_x / 2) - 25, "|%s|",items[0].c_str());
        mvprintw(3, (cur_x / 2) - 25, "==============");

        if(current == 0){attroff(COLOR_PAIR(1));}


        if(current == 1){attron(COLOR_PAIR(1));}
        
        mvprintw(1, (cur_x / 2) - 7, "==============");
        mvprintw(2, (cur_x / 2) - 7, "| %s |",items[1].c_str());
        mvprintw(3, (cur_x / 2) - 7, "==============");

        if(current == 1){attroff(COLOR_PAIR(1));}

        if(current == 2){attron(COLOR_PAIR(1));}

        mvprintw(1, (cur_x / 2) + 11, "==============");
        mvprintw(2, (cur_x / 2) + 11, "|    %s   |",items[2].c_str());
        mvprintw(3, (cur_x / 2) + 11, "==============");

        if(current == 2){attroff(COLOR_PAIR(1));}


        key_pressed = getch();
        switch (key_pressed) {
            case KEY_LEFT:
                play_sound(path);
                if (current > 0) current--;
                break;
            case KEY_RIGHT:
                play_sound(path);
                if (current < 3 - 1) current++;
                break;
            case 10: 
            case KEY_ENTER:
                return current; 
        }

    }
}





int main()
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    curs_set(0);
    // use_default_colors(); 

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(2));

    //sound path files
    string path_1 = "./sfx/menu.wav";
    string path_2 = "./sfx/gamekost.wav";
    string path_3 = "./sfx/restart.wav";



    vector<string> items = {"Кинуть кости","Новая игра","Выход"};

    int user_count = 0,pc_count = 0;
    int cord_y,cord_x;

    getmaxyx(stdscr, cord_y, cord_x);

    while(true)
    {


        int choice = show_horizontal_menu(items,user_count,pc_count,path_1);

        
        if(choice == 0)
        {
            play_sound(path_2);


            int user_pos = 1 + rand()%5,pc_pos = 1 + rand()%6;
            mvprintw(5,(cord_x/2)-5,"Ваш бросок:");
            draw_dice(6, cord_x/2,user_pos);

            mvprintw(14,(cord_x/2)-5,"Бросок робота:");
            draw_dice(15, cord_x/2,pc_pos);

            if(user_pos > pc_pos)
            {
                user_count++;
            }else if(pc_pos > user_pos)
            {
                pc_count++;
            }


        }else if(choice == 1)
        {
            play_sound(path_3);

            user_count = 0;
            pc_count = 0;

            for (int y = 5; y <= 22; ++y) {
            move(y, 0);      
            clrtoeol();      
            }

        }else if(choice == 2)
        {
            break;
        }

        // getch();
    
    }

    play_sound(path_3);
    usleep(500 * 1000);
    refresh();
    // getch();


    endwin();
    return 0;
}