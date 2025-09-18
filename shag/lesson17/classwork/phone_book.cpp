#include <iostream>
#include <fstream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


struct Users
{
    string first_name;
    int phone_number;
};





int book() {
    // srand(time(NULL));
    ofstream fileW("./users.txt");
    if(!fileW.is_open())
    {
        cout<<"Файл не удалось создать"<<endl;
        return 1;
    }
    

    cout<<"Ваш выбор телефонная книга\n\n";

    
    vector<Users> array;
    int count = 1;

    cout<<"Введите * для того что бы закончить"<<endl;
    while (true)
    {
        Users us;

        cout<<"Обонент #"<<count++<<endl;
        cout<<"Введите фамилию: ";
        cin>>us.first_name;
        if(us.first_name == "*")
        {
            break;
        }
        
        cout<<"Введите номер телефона: ";
        cin>>us.phone_number;
        // cin.ignore();

        array.push_back(us);
        fileW<<us.first_name<<" "<<us.phone_number<<endl;
    }
    fileW.close();

    cout<<"Вся информация сохранена в файле"<<endl;

    cout<<"Меню\n1)Вывести весь список\n2)Найти номер конкретного абонента\nВаш выбор -> ";
    int choice;
    cin>>choice;

    ifstream fileR("./users.txt");
    if(!fileR.is_open())
    {
        cout<<"Не удалось открыть файл"<<endl;
        return 0;
    }

    vector<Users> new_array;
    Users info;

    int i = 0;
    while (fileR>>info.first_name >> info.phone_number)
    {

        new_array.push_back(info);

    }
    fileR.close();



    switch (choice)
    {
    case 1:
    {
        int coount = 1;
        for(Users u: new_array)
        {
            cout<<i++<<")"<<"Фамилия: "<<u.first_name<<" номер телефона "<<u.phone_number<<endl;
        }
        break;
    }
    case 2:
    {
        cout<<"Введите фамилию пользователя: ";

        break;
    }
    
    default:
    {
        cout<<"Не известен ваш выбор"<<endl;
        break;
    }
    }
    


    
    return 0;
}