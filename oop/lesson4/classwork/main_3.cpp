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
private:
    int x;
    int y;
    int z;

public:
//сеттер
    void set(int a,int b,int c)
    {
        
        setX(a);
        setY(b);
        setZ(c);
    }

//сеттер
    void setX(int a)
    {
        
        x = a < 0 ? 0 : a;
    }
//сеттер
    void setY(int b)
    {
        
        y = b < 0 ? 0 : b;
    }
//сеттер
    void setZ(int c)
    {
        
        z = c < 0 ? 0 : c;
    }


// геттер
    int getX()
    {
        return x;
    }


    bool isOut()
    {
        return x > 100 || y > 100 || z > 100; 
    }


    void print()      
    {
        cout<< "(" << x << "," << y << "," << z <<")"<<endl;
    }

};



int main()
{

    Point3D a;
    a.set(2,3,-5);
    a.print();
    a.setZ(12);
    a.print();

    cout<<a.getX()<<endl;
    cout<<a.isOut()<<endl;
    
    return 0;
}