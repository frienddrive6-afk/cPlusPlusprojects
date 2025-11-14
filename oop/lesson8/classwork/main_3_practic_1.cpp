#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
#include<string>
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


class Student
{
private:
    int id;
    string name;


    static int nextId;
public:
    Student(string name) :
        id{Student::nextId++},
        name{name}
    {}


    void show()
    {
        cout << this->id << ' '  <<this->name <<endl;
    }

};
int Student::nextId{ 101 };



int main()
{

    Student a{"Vasia"};
    Student b{"Petya"};
    Student c{"Dima"};

    a.show();
    b.show();
    c.show();




    
    return 0;
}




