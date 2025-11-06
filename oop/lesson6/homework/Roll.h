#pragma once

#include <iostream>
#include<string>

class Roll
{
private:
    float width;
    float len;
    float price;
    std::string title;

public:
    Roll(float w,float l,float p,std::string t = "") :
    width{ w },
    len{ l },
    price{ p },
    title{ t}
    {}

    float getArea();
    float getPrise();
};