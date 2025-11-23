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


class Circle
{
private:
    int r;

public:
    Circle(int r = 1) :
        r{r}
    {}

    double getArea() const
    {
        return M_PI * this->r * this->r;
    }


};

class Rect
{
private:
    int w;
    int h;

    int calcArea() const
    {
        return w *h;
    }

public:
    Rect(int w = 1,int h = 1) :
        h{h},
        w{w}
    {}

    bool operator==(const Rect& obj) const
    {
        return this->calcArea() == obj.calcArea();


    }

    bool operator<(const Rect& obj) const
    {
        return this->calcArea() < obj.calcArea();


    }

    bool operator>(const Rect& obj) const
    {
        // return this->calcArea() > obj.calcArea();

        return !(*this < obj);
    }

    bool operator<=(const Rect& obj) const
    {
        // return this->calcArea() <= obj.calcArea();

        return *this < obj || *this == obj;
    }

    bool operator==(const Circle& obj) const
    {
        return this->calcArea() == obj.getArea();
    }

    bool operator==(const int& area) const
    {
        return this->calcArea() == area;
    }


};


int main()
{

    Rect a{ 3, 4 };
    Rect b{ 2, 6 };

    cout<< (a == b) <<endl;

    cout<< (a == 12) <<endl;

    return 0;
}

