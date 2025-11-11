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
    Roll() : 
        width{0}, 
        len{0}, 
        price{0}, 
        title{"Untitled"} 
    {}

    Roll(float w,float l,float p,std::string t = "") :
    width{ w },
    len{ l },
    price{ p },
    title{ t}
    {}

    float getArea()
    {
        return width * len;
    }

    float getPrice()
    {
        return price;
    }

    float getRollWidth()
    { 
        return width; 
    }

    float getRollLength()
    { 
        return len; 
    }

    std::string getTitle()
    {
        return title;
    }

    void addWidth(float new_width)
    {
        width = new_width;
    }

    void addTitle(std::string new_title)
    {
        title = new_title;
    }

    void addLen(float new_len)
    {
        len = new_len;
    }

    void addPrice(float p)
    {
        price = p;
    }


};