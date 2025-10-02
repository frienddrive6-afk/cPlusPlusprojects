#include <iostream>
// #include <fstream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>


using namespace std;


void play_sound(const string& sound_file) {
    string command = "aplay " + sound_file + " >/dev/null 2>&1 &";
    system(command.c_str());
}

struct Data
{
    int day;
    string month;
    int year;
};

struct Man
{

    string surname;
    string name;
    int age;
    Data birth;

};


void printOnDisplay(vector<Man> &arr)
{
    for(Man &i:arr)
    {
        cout<<"Фамилия: "<<i.surname<<endl;
        cout<<""<<i.name<<endl;
        cout<<""<<i.age <<" года"<<endl;
        cout<<""<<i.birth.day <<" " << i.birth.month <<" "<<i.birth.year<<endl;
    }
    cout<<endl;
}


void diyi(vector<Man> &dt)
{
    cout << "---------------Меню-------------\n\n1)Редактирование\n2)Удаление\n3)Добавление\n\nВаш выбор: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            cout << "Введите номер записи для редактирования (начиная с 1): ";
            int nomer;
            cin >> nomer;
            nomer--; 

            if (nomer >= 0 && nomer < dt.size())
            {
                cout << "Введите новые значения" << endl;
                
                cout << "Фамилия: ";
                cin >> dt[nomer].surname;
                
                cout << "Имя: ";
                cin >> dt[nomer].name;
                
                cout << "Возраст: ";
                cin >> dt[nomer].age;
                
                cout << "Дата рождения (день месяц год): ";
                cin >> dt[nomer].birth.day >> dt[nomer].birth.month >> dt[nomer].birth.year;

                cout << "Запись номер " << nomer + 1 << " успешно обновлена." << endl;
            }
            else
            {
                cout << "Ошибка" << endl;
            }
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
    
        default:
            cout << "Неправильный выбор" << endl;
            break;
    }
}


bool sortS(Man& s1,Man& s2)
{
return s1.surname<s2.surname;

}
bool sortS2(Man& s1,Man& s2)
{
return s1.name<s2.name;

}

void sortR(vector<Man> &arr)
{
cout << "---------------Меню-------------\nСортировать по\n1)Фамилии\n2)Имени\n\nВаш выбор: ";
    int choice;
    cin >> choice;


    switch (choice)
    {
        case 1:
        {
            sort(arr.begin(),arr.end(),sortS);
            break;
        }
        case 2:
        {
            sort(arr.begin(),arr.end(),sortS2);
            break;
        }
    

    }

}





int main()
{
    //sound path files
    string path_1 = "./sfx/menu.wav";
    string path_2 = "./sfx/gamekost.wav";
    string path_3 = "./sfx/restart.wav";

    vector<Man> arr = 
    {
        {"Самонин","Медведь",13,{4,"Июли",2002}},
        {"Петров","Петро",24,{1,"Сентябрь",2008}},
        {"Микитенко","Александр",25,{1,"Ноябрь",2023}}
        

    };
    int choice;

    

    do
    {

        play_sound(path_1);
        cout<<endl;
        cout<<"\nМеню программы:\n1)Вывести все записи\n2)Действия с запросом\n3)Сортировка записей\n4)Поиск записи\n5)Вывод именинников\nВаш выбор:";
        cin>>choice;


        switch (choice)
        {
            case 1:
            {
                printOnDisplay(arr);
                break;
            }
            case 2:
            {
                diyi(arr);
                break;
            }
            case 3:
            {
                sortR(arr);
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }

            default:
                play_sound(path_3);
                cout<<"Программа окончена"<<endl;
                break;
        }



    } while (choice <=5 && choice>= 1);
    
    
    return 0;
}