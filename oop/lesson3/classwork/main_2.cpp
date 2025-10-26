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


void func()
{
    int* ptr = new int{56};

    delete ptr;
}



int main() {

    srand(time(NULL));

 
    func();
    

    return 0;
}