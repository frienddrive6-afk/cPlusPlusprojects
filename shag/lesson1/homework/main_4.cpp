#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int time;
    cout<<"Время в секундах: ";
    cin >> time;

    cout<<"Время в минутах" << time/60 <<"\nВремя в часах" << (time/60)/60 <<"\nВремя в днях" <<(float((time/60)/60)/24) <<endl;


    return 0;
} 