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




using namespace std;


class Box
{
private:
    int num;

public:
    explicit Box(int val) :
        num{val}
    {}

    void render()
    {
        cout<<"num = " <<this->num<<endl;
    }

    Box& operator++()
    {
        ++(this->num); 

        return *this;
    }

    Box& operator--()
    {
        --(this->num); 

        return *this;
    }


    Box operator++(int)    //это костыль
    {
        Box temp = *this;
        (this->num) += 2; 

        return temp;
    }


    Box operator--(int)    //это костыль
    {
        Box temp = *this;
        (this->num) -= 2; 

        return temp;
    }

};


int main()
{

    // Box b{ 5 };
    // b.render();

    // Box c{ ++b };
    // c.render();

    // Box a{8};
    // ++a;
    // ++a;
    // ++a;
    // ++a;
    // a.render();
    
    // a++;
    // a.render();


    Box a{ 5 };

    Box b{ a++ };

    a.render();
    b.render();



    return 0;
}

