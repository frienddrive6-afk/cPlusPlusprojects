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

#include "ListItem.h"
#include "List.h"


using namespace std;




int main()
{  
    List<int> a{};


    a.push(12);
    a.push(34);
    a.push(45);
    a.push(21);
    a.push(17);

    a.render();



    List<int> b{ a };
    b.render();
    b.pushToHead(101);
    b.render();

    b.insert(999,2);
    b.render();

    b.remove(5);
    b.render();

    cout<<b[2]<<'\n';

    List<int> c;
    c = b;
    cout<<"this is ccccccccccccccc:"<<'\n';
    c.render();

    c.swap(2,5);
    c.render();

    return 0;
}