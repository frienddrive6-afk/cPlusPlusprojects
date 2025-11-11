#pragma once

#include <iostream>
#include<string>

#include "vector.h"
#include "Room.h"
#include "Roll.h"

struct RollsSummary 
{   
    std::string rull_name;
    int count;
};


class Flat
{
private:

    MyVector<Room> rooms;
    MyVector<Roll> available_rolls;

    float allRooms_area;

public:

    Flat() :
        rooms(0),
        allRooms_area{}
    {}

    void addRoom(const Room& new_room)
    {
        rooms.push_back(new_room);
    }

    void addRoll(const Roll& new_roll)
    {
        available_rolls.push_back(new_roll);
    }


    MyVector<Room> return_rooms()
    {
        return rooms;
    }

    MyVector<Room>* return_rooms_ptr()
    {
        return &rooms;
    }


    MyVector<Roll> return_rolls()
    {
        return available_rolls;
    }

    MyVector<Roll>* return_rolls_ptr()
    {
        return &available_rolls;
    }


    int assignRollToRoom(const std::string& room_name,const std::string& roll_name)
    {

        Room* target_room = nullptr;
        Roll* target_roll = nullptr;

        for(int i = 0; i < rooms.size(); ++i)
        {
            Room* current_room = rooms.get_element_ptr(i);
            if (current_room != nullptr && current_room->return_name() == room_name)
            {
                target_room = current_room;
                break;
            }
        }


        for(int i = 0; i < available_rolls.size(); ++i)
        {
            Roll* current_roll = available_rolls.get_element_ptr(i);
            if (current_roll != nullptr && current_roll->getTitle() == roll_name)
            {
                target_roll = current_roll;
                break; 
            }
        }


        if (target_room != nullptr && target_roll != nullptr)
        {
            target_room->change_roll(target_roll);
            return 0;
        }
        else
        {
            return 1;
        }

    }



    MyVector<RollsSummary> generateReportData()
    {
        MyVector<RollsSummary> summary_vector;
        for(int i = 0; i < available_rolls.size(); ++i)
        {
            RollsSummary summary_line;
            summary_line.rull_name = available_rolls.print_index(i).getTitle();
            summary_line.count = 0;
            summary_vector.push_back(summary_line);
        }

        for(int i = 0; i < rooms.size(); ++i)
        {
            Room* current_room = rooms.get_element_ptr(i);
            if (current_room == nullptr) 
            {
                continue;
            }

            Roll* roll_for_this_room = current_room->getRoll();
            if (roll_for_this_room == nullptr) 
            {
                continue;
            } 

            int rolls_needed_for_room = 0;
            current_room->getPrice(rolls_needed_for_room); 

            for (int j = 0; j < available_rolls.size(); ++j)
            {
                const Roll* current_available_roll = available_rolls.get_element_ptr(j);
                
                if (current_available_roll == roll_for_this_room)
                {
                    RollsSummary* summary_to_update = summary_vector.get_element_ptr(j);
                    if (summary_to_update != nullptr)
                    {
                        summary_to_update->count += rolls_needed_for_room;
                    }
                    break; 
                }
            }
        }
        
        return summary_vector;
    }






};