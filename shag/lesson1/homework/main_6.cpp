#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int len;
    double time;

    cout<<"Введіть довжину дистанції: ";
    cin>> len;

    cout<<"Введіть час: ";
    cin>>time;

    cout<<"Вы пробежали дитанцию" <<len <<"\nЗа время "<<int(time) <<" хв " <<(time - int(time))*100 <<" сек = " <<(int(time) * 60) + (time - int(time))*100 <<" сек" <<"\nВи бігли зі швидкістю " <<((double(len)/1000)/(((int(time) * 60) + (time - int(time))*100)/3600)) <<" км/год" <<endl;

    



    return 0;
} 