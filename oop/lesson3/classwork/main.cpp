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


int* func()
{
    // int a = 4;
    // int* ptr = &a;

    int* ptr = new int{4};


    return ptr;
}



int main() {

    srand(time(NULL));

    int* ptr = func();

    cout<<*ptr<<endl;

    

    return 0;
}