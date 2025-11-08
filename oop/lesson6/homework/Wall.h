#pragma once

#include <iostream>
#include<string>



class Wall
{
private:
    float width;

public:
    Wall() :
        width{}
    {}


    float get_width()
    {
        return width;
    }


};