#include <iostream>
#include <fstream>
#include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
#include <chrono>

#include "header.h"

using namespace std;
using namespace std::chrono;



vector<string> inputChars(const string& line) 
{
    // cout << "Длинна сточки в байтах: " << line.length() << endl;
    vector<string> chars;

    for (int i = 0; i < line.length(); ) 
    {
        unsigned char b = line[i]; 

        int bytes_to_grab = 1; //по умолчанию занимает 1 байт


        if (b >= 0xF0) { //если символ занимает 4 байта
            bytes_to_grab = 4;
        } else if (b >= 0xE0) {//если символ занимает 3 байта
            bytes_to_grab = 3;
        } else if (b >= 0xC0) { //если символ занимает 2 байта
            bytes_to_grab = 2;
        }
        
        //Вырезаем нужный символ зная сколько байт он занимает
        if (i + bytes_to_grab <= line.length()) { // проверка по длинне
            chars.push_back(line.substr(i, bytes_to_grab));
        }

        i += bytes_to_grab; //Увеличиваем итерацию на длину символа
    }

    // cout << "Розбито на символи: ";
    // for (const string& ch : chars)
    // {
    //     cout << ch << " ";
    // }
    // cout << endl;

    return chars;
}




int guessWord() {
    srand(time(NULL));

    ifstream fileR("./txt/riddle.txt");
    if(!fileR.is_open())
    {
        cout << "не удалось открыть файл" << endl;
        return 1;
    }        
    
    vector<string> arr; 
    string line;
    while (getline(fileR, line))
    {
        arr.push_back(line);
    }
    fileR.close();    

    while (true) 
    {
        if (arr.empty()) {
            cout << "\nПоздравляю! Вы отгадали все слова!" << endl;
            break; 
        }


        int randRow = rand() % arr.size(); 

        string arRndRow = arr[randRow];
        string resLine = arRndRow.substr(0, arRndRow.find('|'));
        string resLineTwo = arRndRow.substr(arRndRow.find('|') + 1);

        vector<string> chars_first = inputChars(resLine);
        string refresh_word = ""; 

        int len = chars_first.size();
        for(int i = 0; i < len; i++)
        {
            int el = rand() % chars_first.size();
            refresh_word += chars_first[el];
            chars_first.erase(chars_first.begin() + el);
        }

        bool is_podskaska_use = false;
        
        while (true)
        {
            auto start = steady_clock::now();

            cout << "\nУгадайте слово: " << refresh_word << endl;

            cout << "Введите правильное слово: ";
            string user_res;
            cin >> user_res;

            int user_choice;
            if (user_res == resLine)
            {
                auto end = steady_clock::now();
                duration<double> elapsed = end - start; 
                double time = elapsed.count();
                if (is_podskaska_use == true) 
                {
                    cout << "Поздравляю вы угадали за " << time + 5 << " секунд с учетом штрафа за подсказку" << endl;
                }
                else
                {
                    cout << "Поздравляю вы угадали за " << time << " секунд" << endl;
                }

                arr.erase(arr.begin() + randRow);
                break; 
            }
            else
            {
                cout << "Не правильно\nвы можете воспользоватся подсказкой\nХотите(1)ДА/2)НЕТ): ";
                cin >> user_choice;
            }

            if (user_choice == 1)
            {
                is_podskaska_use = true;
                cout << "Подсказка ->  " << resLineTwo << endl;
            }
        } 

        if (arr.empty()) { 
            continue; 
        }
        
        cout << "\nХотите продолжить игру?\n1) ДА\n2) НЕТ\nВаш выбор: ";
        int continue_choice;
        cin >> continue_choice;
        if (continue_choice != 1) {
            cout << "Спасибо за игру!" << endl;
            break; 
        }
        system("clear"); 
        
    } 

    return 0;
}