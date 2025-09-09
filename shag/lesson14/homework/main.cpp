#include <iostream>
#include<string>
#include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

enum NumberType
{
    INT_NUMBER = 1, 
    WORD_NUMBER     
};

union Number
{
    int number_int;
    char number_word[9]; 
};

struct Car
{
    string model;
    string color;
    NumberType type; 
    Number num;
};


void enter(Car& entity) 
{
    cout << "Введите модель: ";
    cin >> entity.model;

    cout << "Введите цвет: ";
    cin >> entity.color;

    cout << "Тип номера 1)пятизначный номер / 2)слово: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        entity.type = INT_NUMBER;
    } else {
        entity.type = WORD_NUMBER;
    }

    switch (entity.type)
    {
        case INT_NUMBER:
            cout << "Введите пятизначный номер: ";
            cin >> entity.num.number_int;
            break;

        case WORD_NUMBER:
            cout << "Введите номер-слово (до 8 символов): ";
            cin >> entity.num.number_word;
            break;
    }
}

void info(Car& entity) 
{
    cout << "Модель: " << entity.model << endl;
    cout << "Цвет: " << entity.color << endl;
    cout << "Номер: ";
    
    switch (entity.type)
    {
        case INT_NUMBER:
            cout << entity.num.number_int << endl;
            break;
        case WORD_NUMBER:
            cout << entity.num.number_word << endl;
            break;
    }
}


void Dia(Car array[], int rax)
{
    if (rax == 0)
    {
        cout << "Список машин пуст, нечего делать." << endl;
        return;
    }

    int choice;
    cout << "\nБудете ли вы что-то делать?: (1-Да | 2-Нет): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Выберете действие:\n1)Редактировать машину\n2)показать весь список\n3)поиск машины по номеру\n";
        int vubor_dia;
        cin >> vubor_dia;

        switch (vubor_dia)
        {
            case 1: 
            {
                cout << "\nВыберете номер машины которую хотите отредактировать: ";
                int number_mashinu;
                cin >> number_mashinu;

                if (number_mashinu >= 1 && number_mashinu <= rax)
                {
                    int index = number_mashinu - 1;
                    cout << "Редактирование машины " << index + 1 << endl;
                    enter(array[index]);
                } else {
                    cout << "Ошибка: машины с таким номером нет в списке." << endl;
                }
                break;
            }
            case 2: 
                cout << endl << "--- Весь список машин ---" << endl;
                for (int i = 0; i < rax; i++)
                {
                    cout << "=======================================================" << endl;
                    cout << "Машина " << i + 1 << ") " << endl;
                    info(array[i]);
                }
                break;
            case 3: 
            {
                cout << "Выберите тип номера для поиска: 1)пятизначный / 2)слово\n";
                int search_type;
                cin >> search_type;

                bool found = false;
                
                if (search_type == 1) {
                    int value;
                    cout << "Введите номер-число для поиска: ";
                    cin >> value;
                    cout << "\n--- Результаты поиска ---" << endl;
                    for (int i = 0; i < rax; ++i) {
                        if (array[i].type == INT_NUMBER && array[i].num.number_int == value) {
                            cout << "Найдена машина под номером -> " << i + 1 << endl;
                            info(array[i]);
                            found = true;
                        }
                    }
                } else if (search_type == 2) {
                    char value[9];
                    cout << "Введите номер-слово для поиска: ";
                    cin >> value;
                    cout << "\n--- Результаты поиска ---" << endl;
                    for (int i = 0; i < rax; ++i) {
                        if (array[i].type == WORD_NUMBER && strcmp(array[i].num.number_word, value) == 0) {
                            cout << "Найдена машина под номером -> " << i + 1 << endl;
                            info(array[i]);
                            found = true;
                        }
                    }
                } else {
                    cout << "Неверный тип номера." << endl;
                }

                if (!found) {
                    cout << "\nМашин с таким номером не найдено :(" << endl;
                }
                break;
            }
            default:
                cout << "не известен такой параметр" << endl;
                break;
        }
    }
}

int main() {
    srand(time(NULL));

    const int size = 10;
    Car array[size];
    int rax = 0;

    cout << "Введите данные машин: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "\nБудете вводить данные для еще одной машины?(1-Да | 2-Нет): ";
        int m;
        cin >> m;

        if (m == 2)
        {
            break;
        }

        cout << "Машина " << i + 1 << ") \n";
        enter(array[i]);
        rax++;
    }

    cout << endl << endl << "Информация по каждой машине: " << endl;
    for (int i = 0; i < rax; i++)
    {
        cout << "=======================================================" << endl;
        cout << "Машина " << i + 1 << ") " << endl;
        info(array[i]);
    }

    Dia(array, rax);

    return 0;
}