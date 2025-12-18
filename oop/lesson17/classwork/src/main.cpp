#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
#include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>



// #define COMPOSITION
// #define AGREEGATION
// #define ASOCIATION
// #define TRENING1
#define TRENING2



using namespace std;



#ifdef COMPOSITION

class Point
{
private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) :
        x{ x },
        y{ y } 
    {
    }

    void set( int x = 0, int y = 0 )
    {
        this->x = x;
        this->y = y;
    }


    friend ostream& operator<<(ostream& out, const Point& p);


};

ostream& operator<<(ostream& out, const Point& p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}



class Unit
{
private:
    int id;
    string title;
    Point* position;

public:
    Unit(int id, const string& title, const Point& p) :
        id{ id },
        title{ title },
        position{ new Point{ p } }
    {}






    ~Unit()
    {
        if(this->position != nullptr)
        {
            delete position;
        }
    }




};


int main()
{
    Unit a{101,"warrior",{3,4}};

    return 0;
}



#endif


#ifdef AGREEGATION

class Engine
{
public:
    int id;
    int power;

    Engine(int id, int power) :
        id{ id },
        power{ power }
    {}


    void start()
    {
        cout<< this->power <<':'<<"brum brum"<<'\n';
    }

};


class Car
{
public:
    int id;
    Engine* engine;

    Car(int id, Engine* engine) :
        id{ id },
        engine{ engine }
    {}

    void setEngine(Engine* engine)
    {
        this->engine = engine;
    }


    void go()
    {
        cout<<"Car::go\n";
        this->engine->start();
    }

};


int main()
{
    Engine a{ 101, 150 };
    Engine b{ 102, 180 };
    Engine c{ 103, 210 };

    Car car{ 201, &a };
    car.go();


    car.setEngine(&c);
    car.go();


    return 0;
}


#endif


#ifdef ASOCIATION

class Teacher
{
public:
    int id;
    string name;

};


class Group
{
public:
    int id;
    string name;
    vector<Teacher*> teachers;


    void addTreacher(Teacher* teacher)
    {
        this->teachers.push_back(teacher);
    }

};







int main()
{   
    


    return 0;
}
#endif


#ifdef TRENING1

class Category
{
public:
    string title;
    Category* parengCategory = nullptr;
    // vector<Category*> childCategory;


};


#endif



#ifdef TRENING2

class Category
{
public:
    int id;
    string title;

};


class product
{
public:
    int id;
    string title;
    int categoryId;


};




#endif





