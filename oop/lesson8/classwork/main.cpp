#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
#include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>


// #define PARTITION_1
#define PARTITION_2

using namespace std;


#ifdef PARTITION_1

class Fraction
{
private:
    int num;
    int denom;

public:
    Fraction(int num = 0,int denom = 1):
        num{num},
        denom{denom}
    {}

    // Fraction(const Fraction& f)
    // {


    // }


    int getNum()
    {
        return this->num;
    }

    void setNum(int val)
    {
        this->num= val;
    }


    void render()
    {
        cout << this->num << '/' << this->denom <<endl;
    }

};


Fraction doNegative(Fraction f)
{
    f.setNum(-f.getNum());

    return f;
}


int main()
{

    
    
    Fraction x{ 12 , 5 };      //Вызов конструктора Fraction(int num = 0,int denom = 1)

    Fraction y{ x };         //Вызов конструктора Fraction(const Fraction& f)

    Fraction k{ 5 };         //конструктор Fraction(int num = 0,int denom = 1) используется как преобразователь

    Fraction a = doNegative(5);
    a.render();


    return 0;
}

#endif


#ifdef PARTITION_2

class MyString
{
private:
    string str;

public:
    MyString(bool flag) = delete;      //запретить использование такого конструктора
    MyString(char ch) = delete; 

    explicit MyString(int size)
    {
        str.resize(size);
    }

    explicit MyString(const char* str)
    {
        this->str = str;
    }


    void render()
    {
        cout << this->str <<endl;
    }

};


int main()
{

    // MyString str = 'a';                //error
    // str.render();


    return 0;
}





#endif