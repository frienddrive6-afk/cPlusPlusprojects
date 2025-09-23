#include <iostream>
// #include <fstream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

#include "header.h"

using namespace std;





int Menu() {
    srand(time(NULL));

    
    cout<<"\033[32m КОЛЕКЦИЯ ИГР"<<endl;
    cout<<"[1]Скорость печати\n[2]Угадай слово\n[3]Отгадай загадку\033[0m\n";

    int choice;
    cout<<"Ваш выбор:";
    cin>>choice;

    int info_box;

    switch (choice)
    {
        case 1:
        {
            info_box = printSpeed();
            break;
        }

        case 2:
        {
            info_box = guessWord();
            break;
        }

        case 3:
        {
            info_box = answerQuestion();
            break;
        }
    
        default:
            cout<<"Неизвестное значение"<<endl;
            break;
    }


    return 0;
}