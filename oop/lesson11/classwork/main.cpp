#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
// #include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>


using namespace std;


//l-value
//-------------------------
//Модифицируемые(неконстантные): int a; string name = "Vasia"
//Немофицируемые(константные): const int a{ 45 }




//r-value
//-------------------------
//Литераллы, временные значения, анонимные обьекты
//Существую в рамках выражения(стейтмента)


//l-value reference (классические)
//-------------------------
//1. Обычные
//      Инициализируется только не константными l-value
    
//2. Ссылка на константное значение (константная ссылка)
//      Инициализируется const l-value,l-value,r-value(!!!)


//r-value reference
//----------------------
//      инициализируются ТОЛЬКО r-value!!!!
//int&& rref{ 2 };


class Box
{
private:
    int val;
public:
    Box(int val = 0):
        val{val}
    {}

    
};



void f(const int& lref)
{
    cout<<"l-value-ref"<<endl;
}

void f(int&& lref)
{
    cout<<"r-value-ref"<<endl;
}



int main()
{
    // Box a{ 34 };  //ctor
    // Box b{ a };    //copy ctor
    
    // Box&& ref{ Box{ 23 } };

    int a{ 7 };

    f(a);
    f(7);


    
    return 0; 
}

