#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int days_input;

    cout<<"Введите количество дней: ";
    cin>>days_input;

    cout<<round(days_input/7) <<" недели " <<" и " <<(days_input - (round(days_input/7)*7)) <<" дня" <<endl;


    



    return 0;
} 