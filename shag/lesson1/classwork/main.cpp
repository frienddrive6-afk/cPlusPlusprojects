#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    // cout << "\033[32mStart course \nwith\r \033[0mprogramming" << endl;
    // cout << "c++ best langlig" <<endl;


    // cout << "\033[33m\"Hello, World\" \n\033[0m/Bjarne Stroustrup/" << endl;
    // cout << "Hello, World!\n\\\\Dennis Ritchi\\\\" << endl;

    // cout<< "To be, \033[31mor not \033[0mto be: that is the question:\nWhether \033[33m'tis nobler in the mind to suffer \nThe slings and arrows of outrageous fortune, \nOr to take arms against a sea of troubles, \nAnd by opposing end them? \nWilliam Shakespeare" <<endl;


    //питы данных
    // int year = 365;
    // int hour = 24;
    
    // cout <<"on 2025 year "<<year*hour<<" huures" <<endl;


    //задание один
    // int min_capacity;
    // cout<<"input: ";
    // cin >> min_capacity;

    // cout << "min_capacity is " <<min_capacity*3 <<endl;



    //Задание 2
    // int eat_on_gramm;
    
    // cout <<"сколько есть хомяк в граммах за один день?: ";
    // cin >>eat_on_gramm;
    // cout<<eat_on_gramm<<endl;
    // cout << "Обьем корма на 30 дней: " <<eat_on_gramm*30/1000.0<<"кг" <<endl;


    //Задание 3
    // const double dum = 2.54;
    // int d;
    // cout<<"Введите диагональ экрана: ";
    // cin >>d;

    // cout<<"Диагональ в сантиметрах -> " << round(d*dum) <<"см" <<endl;

    // return 0;



    //Завдання 4
    // float price, discount, res;
    // short tovar;

    // cout<<"Введите цену за товар: ";
    // cin >> price;

    // cout<< "Введите кол товар: ";
    // cin >> tovar;

    // cout<< "Введите скидку: ";
    // cin >> discount;

    // cout << "Цена за товар: " <<price-(price*tovar*(discount/100)) <<"грн" <<endl;



    //Задание 5
    // int col_belok, col_orehov;

    // cout<<"Количество белок и орешков: ";
    // cin >>col_belok >>col_orehov;

    // cout <<"поровну получат белочки:" << col_orehov / col_belok <<endl;
    // cout<<"осталось - " <<col_orehov % col_belok <<endl;


    //Задание 6
    // int number;

    // cout <<"Введите число: ";
    // cin>>number;

    // int n1,n2,n3;
    // cout << number/100 + (number/10)%10 + number%10 <<endl;


    //Задание 7
    
    // double number;
    // cout<<"Введите число: ";
    // cin >> number;
    
    // cout << number - int(number);
    
    
    //задание 8
    // double number;
    
    // cout<<"Введите число: ";
    // cin>>number;
    
    // double nubmb_after_tocka = (number - int(number));
    // cout<< int(nubmb_after_tocka*10);


    //Задание 9

    double grivn,cop;

    cout<<"Введите гривны и копейки: ";
    cin>>grivn >>cop;

    double cel = int(cop/100);
    grivn+=cel;
    cop= cop - float(int(cop/100)) * 100;
    cout<<"гривен: "<<grivn <<" копеек: " <<cop  <<endl;

}