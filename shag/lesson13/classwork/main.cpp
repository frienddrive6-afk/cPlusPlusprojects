#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
#include <iomanip>

using namespace std;


// struct Data
// {
//     string day = "четверг";
//     int num = 4;
//     string month = "Сентябрь";
//     int year = 2025;
// };


// typedef struct
// {
//     string day ;
//     int num;
//     string month ;
//     int year;
// } Data;


//Задание 1
// struct Boiler
// {
//     string firma;
//     string color;
//     int potug;
//     float obem;
//     float temp;
// };







//Задание 2
// typedef struct
// {
//     string name;
//     string class_enimal;
//     string klc;
// } Animal;


// void enter(Animal &anm)
// {
//     getline(cin, anm.name);
//     getline(cin, anm.class_enimal);
//     getline(cin, anm.klc);
// }

// void IsBark(string &golos_check)
// {
//     cout<<"Важе животное издает звуки?: ";
//     cin>>golos_check;
//     cin.ignore();
// }

// void pprint(Animal& anm, string& golos_check)
// {
//     cout<<anm.name<<" "<<anm.class_enimal<<" "<<anm.klc <<" " <<golos_check<<endl;
// }



//Задание 3

typedef struct
{
    int day;
    int month;
    int year;
} BD;

typedef struct 
{
    string sioname;
    string group;
    BD data;

} Student;




int main() {

    srand(time(NULL));

    // Data less;

    // less.month = "Октябрь";
    // cout<<less.day<<" "<<less.num<<" "<<less.month<<' '<<less.year<<endl;

    
    // Data less2 = {"Субота",11,"Ноябрь",2027};

    // Data *ptr = &less2;
    // cout<<(*ptr).day<<" "<<ptr->num<<" "<<(*ptr).month<<' '<<(*ptr).year<<endl;


    // const int size = 2;
    // Data bd[size];

    // cout<<"Введите день/номер/месяц/год: "<<endl;
    // for(int i = 0;i < size;i++)
    // {
    //     cout<<i+1<<")"<<endl;
    //     cin>>bd[i].day>>bd[i].num>>bd[i].month>>bd[i].year;
    // }
    // cout<<endl<<endl;
    
    // cout<<"Вывод данных";
    // cout<<endl;
    //  for(int i = 0; i < size; i++)
    // {
    //     cout << left 
    //          << setw(5) << to_string(i + 1) + ")" 
    //          << setw(15) << bd[i].day 
    //          << setw(10) << bd[i].num 
    //          << setw(15) << bd[i].month 
    //          << setw(6) << bd[i].year 
    //          << endl; 
    // }




    //Задание 1

    // Boiler b1 = {"Sumsung","white",1500,30,90};

    // cout<<"Фирма: "<<b1.firma
    // <<"\nЦвет:"<<b1.color
    // <<"\nМощьность:"<<b1.potug
    // <<"\nОбьем:"<<b1.obem
    // <<"\nТемпература:"<<b1.temp
    // <<endl;

    // cout<<"Введите фирму /Цвет /Мощьность /Обьем /Температура";
    // cin>>b1.firma>>b1.color>>b1.potug>>b1.obem>>b1.temp;


    // cout<<"Фирма: "<<b1.firma
    // <<"\nЦвет:"<<b1.color
    // <<"\nМощьность:"<<b1.potug
    // <<"\nОбьем:"<<b1.obem
    // <<"\nТемпература:"<<b1.temp
    // <<endl;





    //Задание 2
    // int klk;
    

    // cout<<"Сколько животных у тебя есть: ";
    // cin>>klk;

    // cin.ignore();

    // vector<string> golos_check(klk);
    // vector<Animal> anm(klk);

    // cout<<"Введите данные про животные Название/Порода и кличка";

    // for(int i = 0;i< klk;i++)
    // {
    //     cout<<i+1<<")";
    //     enter(anm[i]);
    //     IsBark(golos_check[i]);
    // }

    // cout<<"Данные про ваших животных:"<<endl;
    // for(int i = 0;i< klk;i++)
    // {
    //     pprint(anm[i],golos_check[i]);
    // }




    //Задание 3

    Student st1;

    st1.sioname = "Andre Mikatulin Srokov";
    st1.group = "P51";
    st1.data.day = 12;
    st1.data.month = 3;
    st1.data.year = 2002;

    cout<<st1.sioname<<" "<<st1.group<<" "<<st1.data.day<<" "<<st1.data.month<<" "<<st1.data.year<<endl;

    Student st2 = {"sdfsd sdfsdf sdf","sdf45",{12,54,652}};
    cout<<st2.sioname<<" "<<st2.group<<" "<<st2.data.day<<" "<<st2.data.month<<" "<<st2.data.year<<endl;


    return 0;
}