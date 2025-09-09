#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    int full_numb = 0;

    cout<<"Введите целое число: ";
    cin>>full_numb;

    for(int i = 1;i<=full_numb;i++)
    {
        if(full_numb%i == 0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    
    
    
    





    return 0;
}