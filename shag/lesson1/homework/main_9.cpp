#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int time_on_start_work, work_day = 48480;

    cout<<"Введите сколько секунд прошло с начала робочего дня: ";
    cin>>time_on_start_work;

    cout<<"До конца робочего дня осталось -> " <<work_day - time_on_start_work <<endl;
    



    return 0;
} 