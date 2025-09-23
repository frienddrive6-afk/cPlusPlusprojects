#include <iostream>
// #include <fstream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
#include <unistd.h>
#include <chrono>

#include "header.h"

using namespace std;
using namespace std::chrono;



vector<string> words = {"speed","animal","apple","banan","menu"};

string rndWords()
{
    return words[rand()%words.size()];
}

void modeW()
{

    cout<<"Вам надется случайное слово, введите его быстрее.\nДля старта игры нажмите - ENTER"<<endl;
    cin.ignore();

    string res = rndWords();
    cout<<"\033[31m"<< res<<"\033[0m"<<endl;
    string user;

    auto startPlayer = steady_clock::now();

    while(res != user)
    {
        cin>>user;

        if(res == user)
        {
            break;
        }

        cout<<"Слово не верное попробуйте ещё раз"<<endl;
    }

    auto endPlayer = steady_clock::now();  
    duration<double> elapsedPlayer = endPlayer - startPlayer;  
    double timePlayer = elapsedPlayer.count();

    cout<<"Ваше время - "<<timePlayer <<endl;

    cout<<"Печатает компьютер"<<endl;
    auto startComp = steady_clock::now();

    for(int i =0; i< 3;i++)
    {
        cout<<".";
        cout.flush();
        usleep(500000);
    }

    double randoma = rand() % 2000;

    auto endComp = steady_clock::now();  
    duration<double> elapsedComp = endComp - startComp;  
    double timeComp = elapsedComp.count();

    double finalComp = timeComp + (randoma/1000);

    cout<<"Время компютера - "<<finalComp <<endl;


    if(timePlayer > finalComp)
    {
        cout<<"Выиграл компьютер"<<endl;
    }else if(finalComp > timePlayer)
    {
        cout<<"Вы выиграли"<<endl;
    }
    cout<<endl;
}



void modTwo()
{
    cout<<"Введите максимальное количество слов за 1 минуту для начала нажмите - ENTER"<<endl;
    cin.ignore();

    string user_word;
    int true_words = 0;

    auto start = steady_clock::now();


    
    
    
    while(true)
    {
        string res = rndWords();
        
        while (true)
        {
            cout<<"\033[31m"<< res<<"\033[0m"<<endl;
            cin>>user_word;

            if(res == user_word)
            {
                true_words++;
                break;
            }else
            {
                cout<<"Слово не верное попробуйте ещё раз"<<endl;
            }
        }
        
        

        auto end = steady_clock::now();
        duration<double> elapsed = end - start;  
        double timeComp = elapsed.count();
        if(timeComp >= 10)
        {
            break;
        }

        
    }
        

    cout<<"За одну минуты вы ввели "<<true_words <<" правильно!"<<endl;
    





}




int printSpeed() {
    srand(time(NULL));
    system("clear");
    cout<<"\nВАШ ВЫБОР - \"СКОРОСТЬ ПЕЧАТИ\"";
    
    cout<<"Меню игры:\n[1]Режим по слову\n[2]Печать за оду менуту\nЧто выберете?";
    int game;
    cin >> game;

    switch (game)
    {
        case 1:
        {
            modeW();
            break;
        }

        case 2:
        {
            modTwo();
            break;
        }
    
        default:
        cout<<"Такой выбор отсуцтвует"<<endl;
            break;
    }


    return 0;
}