#include<iostream>
// #include<cmath>
using namespace std;


int main()
{
    // short num;
    // cout <<"Введите число: ";
    // cin>>num;

    //Часть1
    // if(num%2==0)
    // {
    //     cout<<"Число парное"<<endl;
    // }else
    // {
    //     cout<<"Число не парное"<<endl;
    // }


    //Часть2
    // (num%2==0)?cout<<"Парное"<<endl:cout<<"Число не парное"<<endl;




    //Задани1
    // short num;
    // cout <<"Введите число: ";
    // cin>>num;

    // if(num<100)
    // {
    //     if(num<10 && num >0)
    //     {
    //         cout<<"Количество цифр 1 и она равна: " <<num <<endl; 
    //     }else if(num>9)
    //     {
    //         cout<<"Количество чисел 2 и первое равно " <<(num/10)%10 <<" и второе " <<num%10 <<" и их сумма " <<((num/10)%10)+(num%10) <<endl;
    //         // cout<<23%10<<endl;
    //     }




    // }else
    // {
    //     cout<<"Не верный формат числа"<<endl;
    // }



    //Задани2
    // const double d =2.54;
    // short user_input;
    // float user_number;

    // cout<<"Добро пожаловать в конвертор с дюймов в сантиметры и на оборот\nВыберете что конвертировать\n1)С дюймов в сантиметры\n2)С сантимеров в дюймы\nВыберете действие 1 или 2: ";
    // cin>>user_input;
    // cout<<"Введите изначальное число: ";
    // cin>>user_number;

    // switch (user_input)
    // {
    //     case 1:
    //         cout<<user_number*d<<" дюймов"<<endl <<endl;
    //         break;
    //     case 2:
    //         cout<<user_number/d<<" см" <<endl;

    //     default:
    //         cout<<"Не правильный выбор" <<endl;

    // }




    //Задани3
    // short num;
    
    // cout<<"Введите двух цифровое число: ";
    // cin>>num;
    // if(num<9 && num > 100)
    // {
    //     cout<<"Число не входит в диапазон"<<endl;
    //     return 1;
    // }

    // short n1 = num/10;
    // short n2 = num%10;

    // (n1>n2)?cout<<n2<<n1<<endl:cout<<num*2<<endl;



    //Задани4
    // short user_numb;

    // cout<<"Введите число от 1 до 100: ";
    // cin>>user_numb;

    // if(user_numb<1 && user_numb>99)
    // {
    //     cout<<"Не правильное число";
    //     return 1;
    // }

    // if(user_numb%3==0 && user_numb%5==0)
    // {
    //     cout<<"Fizz Buzz"<<endl;
    // }else if(user_numb%3==0)
    // {
    //     cout<<"Fizz"<<endl;
    // }else if(user_numb%5==0)
    // {
    //     cout<<"Buzz"<<endl;
    // }else
    // {
    //     cout<<user_numb<<endl;
    // }



    //Задани5
    // short n1,n2,n3,n4,n5;
    // cout<<"Введите 5 оценок ученика: "<<endl;
    // cin>>n1>>n2>>n3>>n4>>n5;

    // short ocenki_sum = n1+n2+n3+n4+n5;

    // if((ocenki_sum/5)>=4)
    // {
    //     cout<<"Допушен"<<endl;
    // }else
    // {
    //     cout<<"Не допущен"<<endl;
    // }
    



    //Задание 6
    // const double USD = 41.3;
    // const double EUR = 47.25;
    // const double PLN = 10.8;
    // short user_v;
    // float user_grivn;

    // cout<<"Введите гривны: ";
    // cin>>user_grivn;

    // cout<<"Выберете в какую валюту вы хотите перевести\n1)USD\n2)EUR\n3)PLN\nВаше число: ";
    // cin>>user_v;

    // switch (user_v)
    // {
    //     case 1:
    //         cout<<"У вас " <<user_grivn/USD <<" USD" <<endl;
    //         break;

    //     case 2:
    //         cout<<"У вас " <<user_grivn/EUR <<" EUR" <<endl;
    //         break;

    //     case 3:
    //         cout<<"У вас " <<user_grivn/PLN <<" PLN" <<endl;
    //         break;
    
    //     default:
    //         cout<<"Такой вариант недоступен"<<endl;
    //         break;
    // }

    
    
    //Задание 6

    short n1,n2,n3,n4,n5,n_max=0;

    cout<<"Введите 5 чисел"<<endl;
    cin>>n1>>n2>>n3>>n4>>n5;

    if(n_max<n1)
    {
        n_max = n1;
    }

    if(n_max<n2)
    {
        n_max = n2;
    }

    if(n_max<n3)
    {
        n_max = n3;
    }
    if(n_max<n4)
    {
        n_max = n4;
    }
    if(n_max<n5)
    {
        n_max = n5;
    }

    cout<<"Максимальное число это - " <<n_max<<endl;


    return 0;
}
