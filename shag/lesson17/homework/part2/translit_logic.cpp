#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "translit_logic.h"

using namespace std;

int start_translit_app() {
    cout << "--- Программа транслитерации ---" << endl;
    cout << "Выберите направление перевода:" << endl;
    cout << "1) С русского на английский (RU -> EN)" << endl;
    cout << "2) С английского на русский (EN -> RU)" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Ошибка неверный выбор" << endl;
        return 1;
    }

    vector<string> ru_alphabet = { "щ", "ш", "ч", "ц", "ю", "я", "ё", "ж", "ъ", "ы", "ь", "э", "а", "б", "в", "г", "д", "е", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х" };
    vector<string> en_translit = { "shch", "sh", "ch", "ts", "yu", "ya", "yo", "zh", "'", "y", "'", "e", "a", "b", "v", "g", "d", "e", "z", "i", "y", "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f", "kh" };

    vector<string> en_alphabet = { "shch", "sh", "ch", "ts", "yu", "ya", "yo", "zh", "kh", "a", "b", "v", "g", "d", "e", "z", "i", "y", "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f" };
    vector<string> ru_translit = { "щ", "ш", "ч", "ц", "ю", "я", "ё", "ж", "х", "а", "б", "в", "г", "д", "е", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф" };

    string input_filename = "input.txt";
    string output_filename = "output.txt";

    ifstream fileR(input_filename);
    if (!fileR.is_open()) {
        cout << "Ошибка не удалось открыть входной файл " << input_filename<< endl;
        return 1;
    }

    ofstream fileW(output_filename);
    if (!fileW.is_open()) {
        cout << "Ошибка не удалось создать выходной файл " << output_filename<< endl;
        return 1;
    }

    string line;

    while (getline(fileR, line)) {
        
        string new_line = line; 

        if (choice == 1) { 
            for (int i = 0; i < ru_alphabet.size(); i++) {
                int pos = 0;
                while ((pos = new_line.find(ru_alphabet[i], pos)) != string::npos) {
                    new_line.replace(pos, ru_alphabet[i].length(), en_translit[i]);
                    pos += en_translit[i].length(); 
                }
            }
        } else { 
            for (int i = 0; i < en_alphabet.size(); i++) {
                int pos = 0;
                while ((pos = new_line.find(en_alphabet[i], pos)) != string::npos) {
                    new_line.replace(pos, en_alphabet[i].length(), ru_translit[i]);
                    pos += ru_translit[i].length();
                }
            }
        }
        
        fileW << new_line << endl;
    }

    fileR.close();
    fileW.close();

    cout << "Транслитерация завершена. Результат в файле " << output_filename<< endl;

    return 0;
}