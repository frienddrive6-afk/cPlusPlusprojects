#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    
    srand(time(NULL));

    int numb = 0,col=0;
    int robot_numb = 1 + rand() % (500 - 1 + 1);
    // cout<<robot_numb<<endl;

    cout<<"Робот загадал число попробуйте угадать"<<endl;

    do
    {
        cout<<"Ваше чило: ";
        cin>>numb;
        col++;

        if(numb == robot_numb)
        {
            cout<<"Поздравляю вы угадали за "<<col<<" попыток"<<endl;
            return 0;
        }else if (numb == 0)
        {
            cout<<"Игра окончина :("<<endl;
        }else      
        {
            cout<<"Вам не повезло вы не угадали чило :(";

            if(robot_numb>numb)
            {
                cout<<" но число что загадал робот больше вашего"<<endl;
            }

            if(robot_numb<numb)
            {
                cout<<" но число что загадал робот меньше вашего"<<endl;
            }
        }
    } while (numb != 0);
    
    
    
    





    return 0;
}