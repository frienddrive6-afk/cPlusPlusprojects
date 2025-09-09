#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    
    int full_num = 0,second_num = 0;

    cout<<"Введите челое число: ";
    cin>>full_num;

    while (full_num>0)
    {
        if(full_num%10 != 3 && full_num%10 != 6)
        {
            second_num*=10;
            second_num+=full_num%10;
        }
        
        full_num/=10;

        // cout<<second_num<<endl;
    }
    // cout<<endl;
    // cout<<second_num<<endl;

    while (second_num>0)
    {
        cout<<second_num%10;
        second_num/=10;
    }
    cout<<endl;
    
    
    





    return 0;
}