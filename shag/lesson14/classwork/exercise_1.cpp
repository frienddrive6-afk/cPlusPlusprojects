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

enum Type
{
    ptax = 1,
    hudoba,
    people

};

union Life
{
    float ptax_speed;
    bool yes_no;
    int iq_human;
};

struct St
{
    int speed;
    string color;
    Type t;
    Life h;
};

void enter(St& entity)
{
    cout<<"Тип 1)птица/2)худоба/3)человек: ";
    int choice;
    cin>>choice;
    entity.t = Type(choice);

    switch (entity.t)
    {
        case Type::ptax :
            cout<<"Ввдите скорость полета: ";
            cin>>entity.h.ptax_speed;
            break;

        case Type::hudoba :
            cout<<"Является ли худоба парнокопытным?(1|0): ";
            cin>>entity.h.yes_no;
            break;

        case Type::people :
            cout<<"Уровень iq: ";
            cin>>entity.h.iq_human;
            break;
        
        default:
            cout<<"error";
            break;
    }

    cout<<"Введите скорость передвижения: ";
    cin>>entity.speed;
    
    cout<<"Введите цвет: ";
    cin>>entity.color;
}

void info(St& entity)
{
    cout<<"Тип:";
    switch (entity.t)
    {
        case 1:
        cout<<"птица"<<endl;
            break;

        case 2:
        cout<<"худоба"<<endl;
            break;

        case 3:
        cout<<"человек"<<endl;
            break;
    
    }

    switch (entity.t)
    {
        case Type::ptax :
            cout<<"скорость полета птицы:"<<entity.h.ptax_speed<<endl;
                break;

        case Type::hudoba :
            cout<<"Является парнокопытным: "<<entity.h.yes_no<<endl;
            break;

        case Type::people :
            cout<<"Его iq составляет: "<<entity.h.iq_human<<endl;
            break;
    }

    cout<<"Скорость передвижения: "<<entity.speed<<endl;
    
    cout<<"Цвет: "<<entity.color<<endl;
}

void Dia(St array[], int rax)
{
    if (rax == 0)
    {
        cout << "Список пуст, нечего редактировать." << endl;
        return;
    }

    int choice;
    cout << "\nБудете ли вычто делать?: (1-Да | 2-Нет): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Выберете действие:\n1)Редактировать данные\n2)показать весь список\n3)поиск по характерстике\n";
        int vubor_dia;
        cin >> vubor_dia;

        switch (vubor_dia)
        {
            case 1:
            {
                cout << "\nВыберете номер сужечтва которое хотите отредактировать: ";
                int number_sushestva;
                cin >> number_sushestva;

                if (number_sushestva >= 1 && number_sushestva <= rax)
                {
                    int index = number_sushestva - 1;

                    cout << "Выберете что хотете отредактировать: \n1)Характеристику конкретного вида\n2)Скорость передвижения\n3)Цвет\n";
                    int kakyu_menaem_harakteristiky_sushestvy;
                    cin >> kakyu_menaem_harakteristiky_sushestvy;

                    switch (kakyu_menaem_harakteristiky_sushestvy)
                    {
                        case 1:
                            switch (array[index].t)
                            {
                                case ptax:
                                    cout << "Характеристика этого существа есть скорость полета Введите его значение: ";
                                    cin >> array[index].h.ptax_speed;
                                    break;
                                case hudoba:
                                    cout << "Характеристика - парнокопытность (1|0). Введите новое значение: ";
                                    cin >> array[index].h.yes_no;
                                    break;
                                case people:
                                    cout << "Характеристика - IQ. Введите новое значение: ";
                                    cin >> array[index].h.iq_human;
                                    break;
                            }
                            break;

                        case 2:
                            cout << "Вы выбрали скорость передвижения Введите его значение: ";
                            cin >> array[index].speed;
                            break;

                        case 3:
                            cout << "Вы выбрали цвет Введите его значение: ";
                            cin >> array[index].color;
                            break;

                        default:
                            cout << "не известен такой параметр" << endl;
                            break;
                    }

                } else {
                    cout << "Ошибка: существа с таким номером нет в списке." << endl;
                }
                break;
            }
            case 2:
                cout << endl << "--- Весь список существ ---" << endl;
                for (int i = 0; i < rax; i++)
                {
                    cout << "=======================================================" << endl;
                    cout << "Сущность " << i + 1 << ") " << endl;
                    info(array[i]);
                }
                break;

            case 3:
            {
                cout << "список всех характеристик\n1)скорость полета\n2)Является парнокопытным\n3)Его iq\n4)Скорость\n5)Цвет" << endl;
                int redack_haract;
                cin >> redack_haract;

                bool found = false; 

                switch (redack_haract)
                {
                    case 1: { 
                        float value;
                        cout << "Введте значение которое хотите найти: ";
                        cin >> value;
                        cout << "\n--- Результаты поиска ---" << endl;
                        for (int i = 0; i < rax; ++i) {
                            if (array[i].t == ptax && array[i].h.ptax_speed == value) {
                                cout << "Ура нам повезло мы нашли существо с такой характиристикой и его значением это существо под номером -> " << i + 1 << endl;
                                info(array[i]);
                                found = true;
                            }
                        }
                        break;
                    }
                    case 2: { 
                        bool value;
                        cout << "Введте значение которое хотите найти(1-ДА | 0-Нет): ";
                        cin >> value;
                        cout << "\n--- Результаты поиска ---" << endl;
                        for (int i = 0; i < rax; ++i) {
                            if (array[i].t == hudoba && array[i].h.yes_no == value) {
                                cout << "Ура нам повезло мы нашли существо с такой характиристикой и его значением это существо под номером -> " << i + 1 << endl;
                                info(array[i]);
                                found = true;
                            }
                        }
                        break;
                    }
                    case 3: { 
                        int value;
                        cout << "Введте значение которое хотите найти: ";
                        cin >> value;
                        cout << "\n--- Результаты поиска ---" << endl;
                        for (int i = 0; i < rax; ++i) {
                            if (array[i].t == people && array[i].h.iq_human == value) {
                                cout << "Ура нам повезло мы нашли существо с такой характиристикой и его значением это существо под номером -> " << i + 1 << endl;
                                info(array[i]);
                                found = true;
                            }
                        }
                        break;
                    }
                    case 4: { 
                        int value;
                        cout << "Введте значение которое хотите найти: ";
                        cin >> value;
                        cout << "\n--- Результаты поиска ---" << endl;
                        for (int i = 0; i < rax; ++i) {
                            if (array[i].speed == value) {
                                cout << "Ура нам повезло мы нашли существо с такой характиристикой и его значением это существо под номером -> " << i + 1 << endl;
                                info(array[i]);
                                found = true;
                            }
                        }
                        break;
                    }
                    case 5: { 
                        string value;
                        cout << "Введте значение которое хотите найти: ";
                        cin >> value;
                        cout << "\n--- Результаты поиска ---" << endl;
                        for (int i = 0; i < rax; ++i) {
                            if (array[i].color == value) {
                                cout << "Ура нам повезло мы нашли существо с такой характиристикой и его значением это существо под номером -> " << i + 1 << endl;
                                info(array[i]);
                                found = true;
                            }
                        }
                        break;
                    }
                    default:
                        cout << "Неизвестная характеристика." << endl;
                        break;
                }

                if (!found) {
                    cout << "\nНе удалось найти существ с таким значением характеристики :(" << endl;
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
    St array[size];
    int rax = 0;

    cout << "Введите данный сущности: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << "\nБудете водить животных?(1-Да | 2-Нет): ";
        int m;
        cin >> m;

        if (m == 2)
        {
            break;
        }

        cout << i + 1 << ") ";
        enter(array[i]);
        rax++;
    }

    cout << endl << endl << "Информация по каждой сущности: " << endl;
    for (int i = 0; i < rax; i++)
    {
        cout << "=======================================================" << endl;
        cout << "Сущность " << i + 1 << ") " << endl;
        info(array[i]);
    }

    Dia(array, rax);

    cout << endl << endl << "Информация по каждой сущности после всех действий: " << endl;
    for (int i = 0; i < rax; i++)
    {
        cout << "=======================================================" << endl;
        cout << "Сущность " << i + 1 << ") " << endl;
        info(array[i]);
    }

    return 0;
}