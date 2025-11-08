#pragma once

#include <iostream>
#include<string>

#include "Roll.h"
#include "Wall.h"
#include "vector.h"
#include"NonActiveArea.h"

class Room
{
private:
    std::string name_room;
    Roll* roll;
    Wall* walls;
    float heigth;
    MyVector<NonActiveArea> freeArea;
    

public:
    Room():
        name_room{"Неопределена"},
        roll{nullptr},
        walls{new Wall[4]},
        heigth{}
    {}

    ~Room()
    {

        delete[] walls;
    }

    std::string return_name()
    {
        return name_room;
    }

    void change_roll(Roll* new_roll)
    {
        roll = new_roll;
    }

    Roll* getRoll()  
    {
        return roll; 
    }    


    float getPrice(int& need_rolls_lines) 
    {
        if (roll == nullptr || heigth <= 0) {
            need_rolls_lines = 0; 
            return 0;          
        }


        int lines_in_roll = int(roll->getRollLength() / heigth);
        if (lines_in_roll == 0) {
            need_rolls_lines = 0;
            return 0;
        }

        float room_perimeter = 0;
        for (int i = 0; i < 4; ++i) {
            room_perimeter += walls[i].get_width();
        }

        float lines = room_perimeter / roll->getRollWidth();
        int lines_need = int(lines);
        if (lines > lines_need) {
            lines_need++; 
        }

        if (lines_need == 0) {
            need_rolls_lines = 0;
            return 0;
        }

        int required_rolls = (lines_need + lines_in_roll - 1) / lines_in_roll;
        
        
        need_rolls_lines = required_rolls; 

        return required_rolls * roll->getPrice();
    }
};