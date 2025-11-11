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
    float total_price;

public:
    Report() : 
        report_lines(0),
        total_price{}
    {}
    
    void addLine(const ReportLine& line)
    {
        report_lines.push_back(line);
    }



    void processData(MyVector<RollsSummary>& summary, MyVector<Roll>& all_rolls)
    {
        report_lines.createArray();
        total_price = {0};


        for(int i{}; i < summary.size();++i)
        {
            RollsSummary* summary_line = summary.get_element_ptr(i);

            for(int j{}; j < all_rolls.size();++j)
            {
                Roll* roll_info = all_rolls.get_element_ptr(j);
                if(roll_info->getTitle() == summary_line->rull_name)
                {
                    total_price += roll_info->getPrice() * summary_line->count;
                    ReportLine Rline;
                    Rline.roll_name = summary_line->rull_name;
                    Rline.need_rolls = summary_line->count;
                    Rline.total_price_for_roll_type = roll_info->getPrice() * summary_line->count;
                    report_lines.push_back(Rline);
                    break;
                }
            }

        }

    }


    void print() 
    {
        std::cout << "\n========================================" << std::endl;
        std::cout <<   "         ИТОГОВЫЙ ОТЧЕТ ЗАКУПКИ         " << std::endl;
        std::cout <<   "========================================" << std::endl;

        for(int i = 0; i < report_lines.size(); ++i)
        {
            const ReportLine* line = report_lines.get_element_ptr(i);
            
            std::cout << "Обои:       " << line->roll_name << std::endl;
            std::cout << "Количество: " << line->need_rolls << " рул." << std::endl;
            std::cout << "Стоимость:  " << line->total_price_for_roll_type << " грн." << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }

        std::cout << "ОБЩАЯ СТОИМОСТЬ ВСЕХ ОБОЕВ: " << total_price << " грн." << std::endl;
        std::cout << "========================================" << std::endl;
    }


    float getTotalPrice()
    {
        return total_price;
    }

};