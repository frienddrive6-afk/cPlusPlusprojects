#include<iostream>
// #include<cmath>
using namespace std;


int main()
{
    int user_input_number;
    short first_chast;
    short second_chast;

    cout<<"Введите 6 значное число: ";
    cin>>user_input_number;

    if(user_input_number<99999 || user_input_number>999999)
    {
        cout<<"Число не 6 значное!"<<endl;
        return 1;
    }

    first_chast = user_input_number/1000;
    cout<<first_chast<<endl;
    second_chast = user_input_number%1000;
    cout<<second_chast<<endl;

    short f_n1,f_n2,f_n3,s_n1,s_n2,s_n3;

    f_n1 = first_chast/100;
    f_n2 = (first_chast/10)%10;
    f_n3 = first_chast%10;

    s_n1 = second_chast/100;
    s_n2 = (second_chast/10)%10;
    s_n3 = second_chast%10;

    if((f_n1+f_n2+f_n3) == (s_n1+s_n2+s_n3))
    {
        cout<<"Число счасливое"<<endl;
    }else
    {
        cout<<"Число не счасливое"<<endl;
    }



    return 0;
}
