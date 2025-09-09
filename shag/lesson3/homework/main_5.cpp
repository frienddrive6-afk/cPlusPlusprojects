#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    int speed = 13,leght = 0,days = 0;
    
    cout<<"Сколько дней ползла улитка: ";
    cin>>days;

    for(int i = 0;i<days;i++)
    {
        speed+=2;
        leght+=speed;
    }

    cout<<"За "<<days<<" дней улитка проползла "<<leght<<" см"<<endl; 
    
    





    return 0;
}