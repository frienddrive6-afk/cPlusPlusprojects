#pragma once

#include <iostream>
#include <string>

#include "vector.h"
#include "Flat.h" 

struct ReportLine
{
    std::string roll_name;
    int need_rolls;
    float total_price_for_roll_type;
};

class Report
{
private:
    MyVector<ReportLine> report_lines;
    Flat* flat;
    float total_price;

public:
    Report() : 
        report_lines(0),
        flat{nullptr}, 
        total_price{}
    {}
    
    void addLine(const ReportLine& line)
    {
        report_lines.push_back(line);
    }




    float find_total_price()
    {
        return flat->roomsPrice();
    }


};