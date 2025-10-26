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


// struct Rect
// {
//   int x;
//   int y;
//   int w;
//   int h;
// };

// int area(const Rect* r)
// {
//   return r->h * r->w;
// }
// int perimeter(const Rect* r)
// {
//   return 2 * (r->w + r->h);
// }
// void move(Rect* r, int x, int y)
// {
//   r->x = x;
//   r->y = y;
// }
// void render(const Rect* r)
// {
//   std::cout << '(' << r->x << ';' << r->y << ')' << " size: " << r->w << '*' << r->h << '\n';
// }

// int main()
// {
//   Rect a{ 0, 0, 5, 2 };

//   std::cout << area(&a) << '\n';
//   std::cout << perimeter(&a) << '\n';
//   move(&a, 10, 10);
//   render(&a);
// }


class Rect
{
public:
    int x;
    int y;
    int w;
    int h;


    int area()
    {
        return w * h;
    }

    int perimetr()
    {
        return 2 * (h + w);
    }

    void move(int newX,int newY)
    {
        x = newX;
        y = newY;
    }

    void render()
    {
        cout << '(' << x << ';' << y << ')' << " size: " << w << '*' << h << '\n';
    }

};


int main()
{
    Rect a{0,0,5,2};   

    cout<<a.area()<<endl;
    cout<<a.perimetr()<<endl;
    a.move(10,10);
    a.render();


    Rect* rect = new Rect{0,0,10,5};
    rect->render();

    return 0;
}