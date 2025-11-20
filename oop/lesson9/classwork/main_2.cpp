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


// #define CONST_OBJECT
// #define CONST_FUNCTION_METODS
#define METODS_WITH_CONST_THIS


using namespace std;



#ifdef CONST_OBJECT

class Point
{
public:
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


    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }


};



int main()
{

    const int b = 54;

    const Point a{ };
    const Point c{ 3, 4};

    c.x = 34;


    return 0;
}

#endif


#ifdef CONST_FUNCTION_METODS

class Box
{
private:
    int x;

public:
    Box() :
        x{}
    {}

    void setX(int val)
    {
        this->x = val;
    }

    const int getX()
    {
        return this->x;
    }

};


int main()
{
    Box a{};
    a.setX(12);

     const int val{ a.getX() };

    return 0;
}


#endif


#ifdef METODS_WITH_CONST_THIS

class Box
{
private:
    int x;

public:
    explicit Box() :                        //ERROR запрезены конструкторы с константным this
        x{}
    {}

    Box(int val)
    {
        this->x = val;
    }

    static void f()
    {

    }

    void setX(int val)           //(Box* const this)
    {
        this->x = val;
    }

    int getX() const              //(const Box* const this)
    {
        return this->x;
    }

    void show() const
    {
        cout << this->x <<endl;
    }


};


#endif