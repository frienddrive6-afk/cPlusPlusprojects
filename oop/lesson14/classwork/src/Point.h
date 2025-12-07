#pragma once
#include <iostream>

class Point
{
private:
    int x;
    int y;

public:
    Point(int x = 0,int y = 0);

    friend std::ostream& operator<<(std::ostream&,const Point&);

};

