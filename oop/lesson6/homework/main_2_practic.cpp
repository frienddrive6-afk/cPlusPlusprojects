#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
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

#include "Roll.h"
#include "vector.h"
#include "Room.h"


using namespace std;



int main()
{   
    // Roll roll{0.9,10,700,"Romashka"};
    // cout<<roll.getArea()<<endl;
    // cout<<roll.getPrise()<<endl;


    MyVector<int> int_vector{2};
    int_vector.push_back(10);
    int_vector.push_back(20);
    cout << "Int vector: ";
    for(int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.print_index(i) << " ";
    }
    cout << endl;

    int_vector.change_by_index(0,23);
    int_vector.change_by_index(1,12);

    cout << "Int vector: ";
    for(int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.print_index(i) << " ";
    }
    cout << endl;

    return 0;
}


