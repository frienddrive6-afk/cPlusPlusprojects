#include <iostream>
// #include<string>
#include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


union WashingMachine {
    char brand[20];
    char color[15];
    float width;
    float height;
    int power;
};




int main() {
    srand(time(NULL));

    WashingMachine wm;
    strcpy(wm.brand, "Samsung"); 
    cout << "Brand: " << wm.brand << endl;
    strcpy(wm.color, "Red");
    cout<<"Color: "<<wm.brand<<endl;
    wm.height = 75.52;
    cout<<"Height: "<<wm.height<<endl;
    cout << "Brand: " << wm.brand << endl;
    wm.width = 62.9;
    cout<<"width: " <<wm.width <<endl;
    cout<<"Color: "<<wm.brand<<endl;
    wm.power = 1000;
    cout<<"Power: " << wm.power<<endl;


    return 0;
}