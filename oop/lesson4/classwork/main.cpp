#include <iostream>
// #include <fstream>
// #include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>


using namespace std;


//модификаторы доступа(private,public,protected)
class Point
{
public:
    int x;     //переменная член класса(поле)
    int y;     //переменная член класса(поле)
private:
    int z;     //переменная член класса(поле)

public:
    void print()       //функция член класса(метод)
    {
        cout<< "(" << x << "," << y << "," << z <<")"<<endl;
    }

};



int main()
{
    
    // Point a;
    // a.print();


    Point* a = new Point{};
    a->print();

    
    return 0;
}