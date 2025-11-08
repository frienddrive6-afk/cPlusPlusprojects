#pragma once

#include <iostream>
#include<string>



class NonActiveArea
{
private:
    float width;
    float height;   

public:
    NonActiveArea() :
        width{},
        height{}
    {}
    
    float getArea()
    {
        return width * height;
    }

};