#include <iostream>
#include<string>
#include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

enum Type
{
    ptax = 1,
    hudoba,
    people

};

union Life
{
    float ptax_speed;
    bool yes_no;
    int iq_human;
};

struct St
{
    int speed;
    string color;
    Type t;
    Life h;
};



void enter(St& entity)
{
    cout<<"Тип 1)птица/2)худоба/3)человек: ";
    cin>>entity.t;
}





int main() {
    srand(time(NULL));

    


    return 0;
}