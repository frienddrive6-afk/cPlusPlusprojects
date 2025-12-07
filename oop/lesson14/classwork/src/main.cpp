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
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>


#include "Containe.h"
#include "Point.h"

using namespace std;





int main()
{

    // Container<int> a{};
    // a.render();


    Container<Point> d{};

    Container<Point> e{ d };
    // e.render();
    // e.erase();
    // e.render();

    e[1] = Point{3 , 4};
    e.render();



    return 0;
}