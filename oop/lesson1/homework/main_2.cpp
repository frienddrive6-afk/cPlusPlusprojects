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

int** create_array(int rows,int days_in_month[])
{
    int** ptr_Array = new int* [rows];

    for(int i = 0;i < rows;++i)
    {
        *(ptr_Array + i) = new int[days_in_month[i]];
    }



    return ptr_Array;
}


void fill_days(int** array, int rows,int days_in_month[])
{
    for (int i = 0; i < rows; ++i) { 
        for (int j = 0; j < days_in_month[i]; ++j) { 
            array[i][j] = rand() % (30 - (-30) + 1) + (-30); 
        }
    }
}

void print_calendar(int** array, int rows, const int days_in_each_row[])
{
    for (int i = 0; i < rows; ++i) {
        cout << "Месяц " << i + 1 << " (" << days_in_each_row[i] << " дней): ";
        for (int j = 0; j < days_in_each_row[i]; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {

    srand(time(NULL));

    const int MONTHS_COUNT = 12;
    
    int days_in_month[MONTHS_COUNT] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int** link_to_array = create_array(MONTHS_COUNT,days_in_month);

    fill_days(link_to_array,MONTHS_COUNT,days_in_month);

    print_calendar(link_to_array, MONTHS_COUNT, days_in_month);


    for (int i = 0; i < MONTHS_COUNT; ++i) {
        delete[] link_to_array[i];
    }
    delete[] link_to_array;

    return 0;
}