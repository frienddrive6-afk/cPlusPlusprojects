#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    const int full_day_time = 86400;

    int time_on_start_day;

    cout<<"Введите время от начала дня ";
    cin>>time_on_start_day;

    cout<<"Текущее время в часах " <<(float(time_on_start_day)/60)/60 <<" время в минутах " <<time_on_start_day/60 <<" время в секундах " <<time_on_start_day <<" до ночи осталось -> " <<full_day_time-time_on_start_day <<" секунд"<<endl;

    



    return 0;
} 