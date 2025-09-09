#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    
    srand(time(NULL));

    short parol_leght = 0,user_parol = 0;


    while (parol_leght<6)
    {
        cout<<"Из скольких символов вы хотите что бы состоял ваш пароль: ";
        cin>>parol_leght;
    }

    for(int i = 0; i<parol_leght;i++)
    {
        cout<<0 + rand() % (9 - 0 + 1);
    }

    cout<<endl;
    
    





    return 0;
}