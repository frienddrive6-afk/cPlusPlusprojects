#include <iostream>
// #include <fstream>
#include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
#include <ncurses.h>


using namespace std;

const int a = 10;


int get_char_immediately() {
    initscr();             
    cbreak();              
    noecho();              
    keypad(stdscr, TRUE);  
    
    int ch = getch();      
    
    endwin();              
    
    return ch; 
}


void Again(char arr[a][a], int lives) { 
    system("clear");
    
    cout << "Жизни: ";
    for (int i = 0; i < lives; ++i) cout << "\033[31m♥ \033[0m";
    cout << endl << endl;

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < a; j++) {
            if (arr[i][j] == 'P') cout << "\033[31mP\033[0m "; 
            else if (arr[i][j] == 'X') cout << "\033[32mX\033[0m "; 
            else if (arr[i][j] == '!') cout << "\033[33m!\033[0m "; 
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}


void spawnTrap(char arr[a][a]) {
    int trap_y, trap_x;
    do {
        trap_y = rand() % a;
        trap_x = rand() % a;
    } while (arr[trap_y][trap_x] != ' ');
    
    arr[trap_y][trap_x] = '!';
}



void move(char arr[a][a], int* player_y, int* player_x, int key, int* lives) {
    int next_y = *player_y;
    int next_x = *player_x;

    switch (key) {
        case 'w': case 'W': case KEY_UP:
            next_y--; break; 
        case 's': case 'S': case KEY_DOWN:
            next_y++; break;
        case 'd': case 'D': case KEY_RIGHT:
            next_x++; break;
        case 'a': case 'A': case KEY_LEFT:
            next_x--; break;
    }

    if (next_y >= 0 && next_y < a && next_x >= 0 && next_x < a) {
        
        if (arr[next_y][next_x] == '!') {
            (*lives)--; 
            cout << "\nВы попали в ловушку! -1 жизнь." << endl;
            arr[*player_y][*player_x] = ' ';
            *player_y = 1;
            *player_x = 1;
            arr[1][1] = 'P';
            arr[next_y][next_x] = ' ';
            spawnTrap(arr);
            return; 
        }

        if (arr[next_y][next_x] != '#') {
            arr[*player_y][*player_x] = ' ';
            *player_y = next_y;
            *player_x = next_x;
            arr[*player_y][*player_x] = 'P';
        }
    }
}



int main()
{
    srand(time(NULL));

    

    char arr[a][a] = 
    {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','P',' ',' ','#',' ',' ',' ',' ','#'},
      {'#',' ','#',' ','#',' ','#','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ','#',' ','#'},
        {'#',' ','#','#','#','#',' ','#',' ','#'},
       {'#',' ',' ',' ',' ','#',' ','#',' ','#'},
       {'#',' ','#','#',' ','#',' ','#',' ','#'},
       {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
      {'#',' ',' ',' ','#','#',' ',' ','X','#'},
       {'#','#','#','#','#','#','#','#','#','#'}
    };

    spawnTrap(arr);

    int player_y = 1, player_x = 1;
    int lives = 3;

    while (true) {
        Again(arr, lives); 
        
        if (lives <= 0) {
            cout << "\nИгра окончена. У вас закончились жизни." << endl;
            break;
        }

        if (arr[8][8] == 'P') { 
            cout << "\nПоздравляю, вы нашли выход!" << endl;
            break;
        }

        int key = get_char_immediately();
        
        move(arr, &player_y, &player_x, key, &lives); 
    }
    
    
    return 0;
}