#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
// #include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>

#include "Roll.h"
#include "vector.h"
#include "Room.h"
#include "Wall.h"
#include "NonActiveArea.h"
#include "Flat.h"
#include "Report.h"


using namespace std;



Roll inpuRollData()
{
    string title;
    float temp_width,temp_len,temp_price;

    std::cout << "\n--- Ввод нового типа обоев ---" << std::endl;
    cout<<"Введите название рулона: ";
    // cin.ignore(1000,'\n');
    getline(cin,title);

    cout<<"Введите ширину рулона: ";
    cin>>temp_width;

    cout<<"Введите длину рулона: ";
    cin>>temp_len;

    cout<<"Введите цену за рулон: ";
    cin>>temp_price;

    return Roll{temp_width,temp_len,temp_price,title};
}

NonActiveArea CreateNonActiveArea()
{
    NonActiveArea non;

    cout<<"Введите высоту: ";
    float h;
    cin>>h;
    non.addHeigth(h);

    cout<<"Введите ширину: ";
    float w;
    cin>>w;
    non.addWidth(w);

    return non;
}


Room inputRoomData()
{
    Room new_room;;

    cout<<"Введите название комнаты: ";
    string temp_name;
    // cin.ignore(1000,'\n');
    getline(cin,temp_name);
    new_room.addName(temp_name);



    // for(int i{}; i < flat.return_rolls_ptr()->size();++i)
    // {
    //     cout<<flat.return_rolls_ptr()->get_element_ptr(i)->getTitle() <<" ";
    // }
    
    // cout<<"Введите название рулона какой будем использовать в этой команете: ";
    // string temp_roll_name;
    // cin>>temp_roll_name;

    // Roll* temp_roll;
    // for(int i{}; i < flat.return_rolls_ptr()->size();++i)
    // {
    //     if(temp_roll_name == flat.return_rolls_ptr()->get_element_ptr(i)->getTitle())
    //     {
    //         temp_roll = flat.return_rolls_ptr()->get_element_ptr(i);
    //     }
    // }

    // new_room.addRoll(temp_roll);



    float wall_width[4];
    cout<<"теперь вам нужно ввести ширину 4х стен: "<<endl;
    for(int i{};i < 4;++i)
    {
        cout<<"Введите ширину стены №"<<i+1<<": ";
        cin>>wall_width[i];
    }

    new_room.addAllWidthForRoom(wall_width);



    cout<<"Введите высоту стен в комнате: ";
    float temp_heigth;
    cin>>temp_heigth;
    new_room.addHeigth(temp_heigth);


    while (true)
    {
        cout<<"Вы хотите добавить окно или дверь?: (1ДА/2НЕТ)";
        int choice;
        cin>>choice;

        if(choice == 1)
        {
            new_room.push_backNonActiveArea(CreateNonActiveArea());
        }else
        {
            break;;
        }
    }
    

    return new_room;
}




int main()
{   
    Flat flat;

    cout<<"Вам нужно добавить обои какие вы будите клеить"<<endl;
    while (true)
    {
        cout<<"Хотите добавить обьену (1ДА/2НЕТ): ";
        int temp_choice;
        cin>>temp_choice;
        if(cin.fail())
        {
            cin.clear();
        }
        cin.ignore(1000, '\n');
        if(temp_choice == 1)
        {
            flat.addRoll(inpuRollData());
        }else
        {
            break;
        }
    }

    cout<<endl;
    cout<<"Вам нужно добавить ваши комнаты"<<endl;
    while (true)
    {
        cout<<"Хотите добавить комнату (1ДА/2НЕТ): ";
        int temp_choice;
        cin>>temp_choice;
        if(cin.fail())
        {
            cin.clear();
        }

        cin.ignore(1000,'\n');
        if(temp_choice == 1)
        {
            flat.addRoom(inputRoomData());
        }else
        {
            break;
        }
    }

    cout<<endl;
    cout<<"Теперь нужно выбрать в какой комнате какие обои клеить"<<endl;
    for(int i{}; i < flat.return_rooms_ptr()->size();++i)
    {
        cout<<"Выбрана комната "<<flat.return_rooms_ptr()->get_element_ptr(i)->return_name() <<" какую обоину вы хотите поклеить "<<endl;
        
        cout<<"Вот существующие варианты"<<endl;
        for(int j{}; j < flat.return_rolls_ptr()->size();++j)
        {
            cout<<j+1<<")"<<flat.return_rolls_ptr()->get_element_ptr(j)->getTitle()<<" ";
        }
        cout<<endl;

        cout<<"Введите номер обоины какую хотите поклеить: ";
        int num_roll;
        cin>>num_roll;
        num_roll--;

        if (num_roll >= 0 && num_roll < flat.return_rolls_ptr()->size())
        {
            flat.assignRollToRoom(flat.return_rooms_ptr()->get_element_ptr(i)->return_name(),flat.return_rolls_ptr()->get_element_ptr(num_roll)->getTitle());
            // flat.return_rooms_ptr()->get_element_ptr(i)->addRoll(flat.return_rolls_ptr()->get_element_ptr(num_roll));
        }else
        {
            cout << "Ошибка: Неверный номер. Обои для этой комнаты не назначены." << endl;
        }

    }    



    cout << "\nВыполняется расчет..." << endl;

    MyVector<RollsSummary> report_data = flat.generateReportData();
    MyVector<Roll> all_rolls = flat.return_rolls();
    
    Report final_report;
    final_report.processData(report_data, all_rolls);

    final_report.print();

    cout << "\nРасчет завершен. Спасибо за использование программы!" << endl;


    return 0;
}


