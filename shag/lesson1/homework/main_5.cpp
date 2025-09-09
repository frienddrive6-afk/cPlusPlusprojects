#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double money;

    cout<<"Введите сумму: ";
    cin >> money;

    cout<<"У вас: " <<int(money) <<" грн" <<"и " <<(money- int(money))*100 <<" копеек" <<endl;



    return 0;
} 