#include <iostream>
#include <vector> 
#include <algorithm>
// #include <cstdlib> // Для srand() і rand()
// #include <ctime>   // Для time()

using namespace std;


short Vubor() {
    short vubor_user = 0;
    do {
        cout << "Игра крестики Нолики" << endl;
        cout << "За кого вы хотите играть?\n1)Крестики\n2)Нолики\nВаш выбор: ";
        cin >> vubor_user;
    } while (vubor_user < 1 || vubor_user > 2);
    return vubor_user;
}

short WhoFirst() {
    short whofirst_hod = 0;
    do {
        cout << "Вам нужно выбрать кто будет ходить первым \n1)вы или 2)робот\nВаш выбор: ";
        cin >> whofirst_hod;
    } while (whofirst_hod < 1 || whofirst_hod > 2);
    return whofirst_hod;
}

void See_Pole(char pole[], int size) {
    cout << "-----------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << pole[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
    cout << "-----------------" << endl;
}

short WhoHodit(short vubor_user, char pole[9], short kto_seychas_hodit, char KRESTIK, char NOLIK) {
    if (kto_seychas_hodit == 2) {
        int robot_choice;
        do {
            robot_choice = rand() % 9;
        } while (pole[robot_choice] != '*');
        cout << "Робот выбрал -> " << robot_choice + 1 << " клетку" << endl;
        if (vubor_user == 1) {
            pole[robot_choice] = NOLIK;
        } else {
            pole[robot_choice] = KRESTIK;
        }
        return 1;
    } 
    else if (kto_seychas_hodit == 1) {
        int user_choice; 
        cout << "Выберите клетку (1-9): ";
        cin >> user_choice;
        int index = user_choice - 1; 
        if (index >= 0 && index < 9 && pole[index] == '*') {
            if (vubor_user == 1) {
                pole[index] = KRESTIK;
            } else {
                pole[index] = NOLIK;
            }
        } else {
            cout << "Некорректный ввод или клетка занята! Вы пропускаете ход." << endl;
        }
        return 2;
    }
    return kto_seychas_hodit; 
}

char CheckWinner(char pole[]) {

    if (pole[0] == pole[1] && pole[1] == pole[2] && pole[0] != '*') return pole[0];
    if (pole[3] == pole[4] && pole[4] == pole[5] && pole[3] != '*') return pole[3];
    if (pole[6] == pole[7] && pole[7] == pole[8] && pole[6] != '*') return pole[6];

    if (pole[0] == pole[3] && pole[3] == pole[6] && pole[0] != '*') return pole[0];
    if (pole[1] == pole[4] && pole[4] == pole[7] && pole[1] != '*') return pole[1];
    if (pole[2] == pole[5] && pole[5] == pole[8] && pole[2] != '*') return pole[2];

    if (pole[0] == pole[4] && pole[4] == pole[8] && pole[0] != '*') return pole[0];
    if (pole[2] == pole[4] && pole[4] == pole[6] && pole[2] != '*') return pole[2];

    return '*';
}

void Game(short vubor_user, short whofirst_hod, char pole[9], char KRESTIK, char NOLIK, char game_status) {
    int turn_count = 0; 

    char player_symbol; 

    if (vubor_user == 1) 
    {
        player_symbol = KRESTIK; 
    }else 
    {
        player_symbol = NOLIK;
    }

    while (game_status == 0 && turn_count < 9) {
        See_Pole(pole, 9);
        whofirst_hod = WhoHodit(vubor_user, pole, whofirst_hod, KRESTIK, NOLIK);
        
        char winner = CheckWinner(pole);
        if (winner != '*') {
            game_status = 1; 
            See_Pole(pole, 9); 
            if (winner == player_symbol) {
                cout << "Поздравляю! Вы победили!" << endl;
            } else {
                cout << "К сожалению, победил робот." << endl;
            }
        }
        
        turn_count++; 
    }

    if (game_status == 0) {
        See_Pole(pole, 9);
        cout << "Игра окончена! Ничья." << endl;
    } 
}





int main() {
    srand(time(NULL));

    const char KRESTIK = 'X';
    const char NOLIK = 'O';

    char game_status = 0; // 0 - гра триває, 1 - є переможець

    char pole[9] = {
        '*','*','*',
        '*','*','*',
        '*','*','*'
    };

    short vubor_user = Vubor();
    short whofirst_hod = WhoFirst();

    Game(vubor_user, whofirst_hod, pole, KRESTIK, NOLIK, game_status);

    return 0;
}


