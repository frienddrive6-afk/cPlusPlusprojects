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
#include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>

using namespace std;




// class Point
// {
// private:
//     int x;
//     int y;
//     bool flag;

// public:
//     explicit Point(int x,int y) :
//         x{x},
//         y{y},
//         flag{false}
//     {}

//     //создается НЕЯВНО
//     //конструктор копирования
//     //осуществяет по битовое копирование
//     // Point(const Point& obj)
//     // {
//     //     this->x = obj.x;
//     //     this->y = obj.y;
//     // }

// };






// int main()
// {
    
//     Point p{3,4};

//     Point q{ p };
    
//     return 0;
// }












// class Box
// {
// private:
//     int* ptr;

// public:
//     Box():
//         ptr{nullptr}
//     {}

//     Box(int val):
//         ptr{ new int{val} }
//     {}

//     // Box(const Box& obj)
//     // {
//     //     this->ptr = new int;

//     //     *(this->ptr) = *(obj.ptr);
//     // }

//     Box(const Box& obj) :
//         ptr{new int{*(obj.ptr)}}
//     {}

//     int getVal()
//     {
//         return ptr != nullptr ? *ptr : -1;
//     }

//     void setVal(int val)
//     {
//         if (this->ptr == nullptr)
//         {
//             ptr = new int;

//             *ptr = val;
//         }
//     }

//     ~Box()
//     {
//         if(this->ptr != nullptr)
//         {
//             delete ptr;
//         }

//     }

// };



// int main()
// {



//     Box a{ 10 };

//     Box b{ a };   //вызывается конструктор копирования


//     cout <<a.getVal()<<endl;
//     cout <<b.getVal()<<endl;

//     a.setVal(500);

//     cout <<a.getVal()<<endl;
//     cout <<b.getVal()<<endl;

//     return 0;
// }








class Point
{
private:
    int* x;
    int* y;

public:
    Point():
        x{new int{}},
        y{new int{}}
    {}

    Point(int x,int y):
        x{new int { x }},
        y{new int { y }}
    {}

    Point(const Point& obj):
        x{new int{*obj.x}},
        y{new int{*obj.y}}
    {
        cout<<"Вызвался конструктор копирования"<<endl;
    }

    int getX()
    {
        return *(this->x);
    }

    int getY()
    {
        return *(this->y);
    }


    ~Point()
    {
        if(this->x != nullptr && this->y != nullptr)
        {
            delete this->x;
            delete this->y;
        }

        cout<<"Деструктор вызван"<<endl;
    }
};

double getVectorlength(Point p)   //Point p{ a }
{
    return sqrt( pow(p.getX(),2) + pow(p.getY(),2) );
}

Point getVectorCenter(Point p)
{
    int x = p.getX() / 2;
    int y = p.getY() / 2;

    //Вариант 1
    // Point res{x,y};
    // return res;


    //Вариант 2
    return Point{ x, y };

}


int main()
{

    //случай вызова конструктора копирования

    //1. Инициалзация другим обьектом
    // Point a{ 10 , 3 };
    // Point b{ a };

    //2. Передача в функцию значения обьета (по значению)
    // Point a { 3, 4 };
    // getVectorlength(a);
    // getVectorlength({ 6, 4 });
    // getVectorlength({ });

    //3. Возврат функции
    // Point p{ 5, 7 };
    // Point res{ getVectorCenter(p)};


    // Эллизия
    // Point p{ Point{ 3, 4 } };


    return 0;
}

