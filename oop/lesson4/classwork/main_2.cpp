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


class Point3D
{
public:
    int x;
    int y;
    int z;


    void print()      
    {
        cout<< "(" << x << "," << y << "," << z <<")"<<endl;
    }

    void move(int a,int b,int c)
    {
        x = a;
        y = b;
        z = c;
    }



};



int main()
{

    Point3D a{0,0,0};

    a.print();
    a.move(1,2,3);
    a.print();


    
    return 0;
}