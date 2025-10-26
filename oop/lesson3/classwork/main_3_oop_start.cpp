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


struct Rect
{
    int x;
    int y;
    int w;
    int h;
};

int area1(Rect r)
{
    return r.w * r.h;
}


int area2(const Rect* r)
{
    return r->w * r->h;
}



int main() {

    srand(time(NULL));

    Rect a{0,0,5,2};

    cout<< area1(a)<<endl;
    cout<< area1({0,0,10,5})<<endl;


    cout<< area2(&a)<<endl;


    return 0;
}