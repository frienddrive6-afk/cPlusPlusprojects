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
  int* x;
  int* y;

public:
    Point(int x = 0, int y = 0) :
        x{ new int{ x } },
        y{ new int{ y } }
    {
    }

    // copy ctor
    Point(const Point& obj) :
        x{ new int{ *obj.x } },
        y{ new int{ *obj.y } }
    {}

    //Неявная перегрузка оператора присваивания копированием
    // Point& operator=(const Point& obj)
    // {
    //     this->x = obj.x;
    //     this->y = obj.y;
    // }

    Point& operator=(const Point& obj)
    {
        if(this == &obj)
        {
            return *this;
        }

        *this->x = *obj.x;
        *this->y = *obj.y;

        return *this;
    }


    void render()
    {
        std::cout << *this->x << ';' << *this->y << '\n';
    }

    ~Point()
    {
        if (this->x != nullptr && this->y != nullptr)
        {
        delete this->x;
        delete this->y;
        }
    }
};



int main()
{

    // int a { 45 };
    // int b;
    // int c;

    // c = b = a;


    Point a{ 3, 4 };
    Point c{ a };

    Point b{};
    b = b;
    b = a;
    b.render();




    return 0;
}

