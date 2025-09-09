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



int main() {
    srand(time(NULL));

    // St entity;
    
    // enter(entity);
    // info(entity);


    const int size = 10;
    St array[size];
    int rax = 0;

    cout<<"Введите данный сущности: "<<endl;


    for(int i = 0;i < size;i++)
    {
        cout<<"Будете водить животных?(1-Да | 2-Нет): ";
        int m;
        cin>>m;

        if(m == 2)
        {
            break;
        }

        cout<<i+1<<") ";
        enter(array[i]);
        rax++;
        
    }


    cout<<endl<<endl<<"Информация по каждой сущности: "<<endl;
    for(int i = 0;i < rax;i++)
    {
        cout<<"======================================================="<<endl;
        cout<<"Сущность "<<i+1<<") "<<endl;
        info(array[i]);
    }





    return 0;
}