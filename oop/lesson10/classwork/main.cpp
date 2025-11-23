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


class Point
{
private:
    int x;
    int y;

public:
    Point(): 
        x{},
        y{}
    {}

    Point(int x,int y):
        x{x},
        y{y}
    {}

    int getX() const
    {
        return this->x;
    }

    int getY() const
    {
        return this->y;
    }

    void setX(int val)
    {
        this->x = val;
    }

    void setY(int val)
    {
        this->y = val;
    }

    void render() const
    {
        cout<<"("<< this->x<<";"<<this->y<<")"<<endl;
    }

    Point operator+(const Point& p) const
    {
        return Point{this->getX() + p.getX(),this->getY() + p.getY()};
    }

    //unary -
    Point& operator-()
    {
        //Вариант 1
        // return Point{-this->x,-this->y};

        //Вариант2
        this->x = -this->x;
        this->y = -this->y;

        return *this;
    }

    Point operator+()
    {
        //Вариант 1
        return Point{this->x < 0 ? this->x * (-1) : this->x, this->y < 0 ? this->y * (-1) : this->y};

    }

};


//binary+
// Point operator+(Point a,Point b)
// {
//     return Point{a.getX() + b.getX(),a.getY() + b.getY()};
// }



int main()
{

    //======Нельзя перегружать
    // Тернарный оператор :?
    // sizeof
    //::
    //
    // .
    // * (разыменование) & (взятие адреса)

    // == == Ограничения
    //1 Перегружать можно только существующие оператор
    //2 Неповторяемость перегрузок (должна бвть неизвестная до этого перегрузка)
    //3 Количество операндов менять нельзя
    //4 Операторы сохраняют приоритет и ассоциативность

    //Особенности (рекомендации)
    // =  [] ()   ->   Іголько через метод класса
    // >> <<            только через дружественные ф-ции



    Point a{ 3, 4 };
    Point b{ 4, 5 };

    Point c{ a + b };
    c.render();

    Point d{ -a };
    d.render();

    Point e { +d };
    e.render();


    return 0;
}

