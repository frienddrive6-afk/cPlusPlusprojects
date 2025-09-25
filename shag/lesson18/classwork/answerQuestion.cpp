#include <iostream>
#include <fstream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
#include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
#include <chrono>

#include "header.h"

using namespace std;
using namespace std::chrono;



int answerQuestion() {
    srand(time(NULL));

    ofstream fileD("info.txt",ios::app);
    if(!fileD.is_open())
    {
        cout<<"Не удалось найти файл"<<endl;
        return 1;
    }

    const int riddle = 8,col = 2;

    string masiv[riddle][col] = 
    {
        {"Йде то в гору, то з гори, але залишається на місці - ","дорога"},
        {"По якій тварині ходять люди і проїжджають машини - ","зебра"},
        {"Зав'язати можна, а розв'язати не можна -","розмова"},
        {"Перед яким простим смертним навіть президент знімає шапку - ","перукар"},
        {"Без рук, без ніг, а малювати вміє - ","тінь"},
        {"Біжить, а ніг не має – ","річка"},
        {"Крила є — не літає, очі є — не моргає – ","окуляри"},
        {"Не людина, а говорить –","дзвінок"}
    };
    
    int random = rand()%riddle;

    cout<<"Загадка "<<masiv[random][0]<<endl;
    string answer = masiv[random][1];
    int len = inputChars(answer).size();
    vector<string> bol;
    int count = 0;

    for(int i = 0; i < len;i++)
    {
        bol.push_back("*");
    }
    cout<<"Слово ";
    for(string ch: bol)
    {
        cout<<ch;
    }
    cout<<endl;

    auto startPlayer = steady_clock::now();

    while (true)
    {
        cout<<"Меню игры\n1)Буква\n2)Слово\n3)Подсказка\n4)вывод\nВаш выбор";
        int choice;
        cin>>choice;
        cin.ignore();

        if(choice == 1)
        {
            string litera;
            cout<<"Введите букву: ";
            getline(cin, litera);
            int a = 0;
            vector<string> answer_two = inputChars(answer);
            for(int i = 0;i<len;i++)
            {
                if(litera == answer_two[i] && bol[i] == "*")
                {
                    bol[i] = litera;
                    a = 1;
                }
            }
            if(a == 0)
            {
                cout<<"Нет такой буквы"<<endl;
            }else
            {
                cout<<"Слово:";
                for(string ch:bol)
                {
                    cout<<ch;
                }
                cout<<endl;
            }





        }else if(choice == 2)
        {
            cout<<"Введи слово:";
            string user_answer;
            cin>>user_answer;
            if(user_answer == answer)
            {
                cout<<"Ты отгодал"<<endl;
                count++;
                // break;
            }else
            {
                cout<<"Ответ не верный попробуйте еще"<<endl;
                continue;
            }
        
        
        
        }else if (choice == 3) 
        {
            vector<string> answer_chars = inputChars(answer);

            bool has_closed_letters = false;
            for (const string& s : bol) {
                if (s == "*") {
                    has_closed_letters = true;
                    break;
                }
            }
            
            if (has_closed_letters) {
                int random_index;
                do {
                    random_index = rand() % len; 
                } while (bol[random_index] != "*");

                bol[random_index] = answer_chars[random_index];
            }

            cout << "Вы воспользовались подсказкой. Слово: ";
            for (const string& ch : bol) {
                cout << ch;
            }
            cout << endl;
        }else if(choice == 4)
        {
            cout<<"Игра закончилась, статистика сохранена";
            break;
        }



    }

    auto endPlayer = steady_clock::now();  
    duration<double> elapsedPlayer = endPlayer - startPlayer;  
    double timePlayer = elapsedPlayer.count();

    fileD<<count<<") Слово \""<<answer<<"\" было угадано за "<<timePlayer <<"сек."<<endl; 

    fileD.close();
    return 0;
}