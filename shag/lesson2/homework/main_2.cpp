#include<iostream>
// #include<cmath>
using namespace std;


int main()
{
    float usr_input;

    cout<<"Введите число: ";
    cin>>usr_input;

    if(int(usr_input)%2 == 0)
    {
        usr_input *=3;
    }else
    {
        usr_input= usr_input/2;
    }

    cout<<usr_input<<endl;



    return 0;
}
