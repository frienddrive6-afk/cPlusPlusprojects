#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


bool IsPalinrom(string str)
{

    if (str.size() <= 1) {
        return true;
    }

    string perevern = "";

    for(int i = str.size() - 1;i >= 0;i--)
    {
        perevern+=str[i];
    }

    // for(int i =0;i < str.size();i++)
    // {
    //     if(str[i] == perevern[i])
    //     {
    //         return true;
    //     }else
    //     {
    //         return false;
    //     }
    // }

    return str == perevern;
}



int main() {

    srand(time(NULL));
    
    string str;
    

    cout<<"Введите ваш ряд: ";
    getline(cin,str);

    bool pal = IsPalinrom(str);

    if(pal)
    {
        cout<<"Ваше предложение палиндром"<<endl;
    }else
    {
        cout<<"Ваше предложение НЕ палиндром"<<endl;
    }

    return 0;
}







