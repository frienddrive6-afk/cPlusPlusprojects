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




// #define INITIALIZATORS
// #define INITIALIZATORS2
// #define INITIALIZATORS3
// #define CTOR_DELEGATION
#define DESTRUCTOR

using namespace std;





#ifdef INITIALIZATORS

class Point
{

private:

    int x;
    int y;
    const string title;
    int statArr[3];
    int dynCount;
    int* dynArr;
    

public:
    //случай без параметра
    Point() :
        x{},
        y{},
        title {"no_title"},
        statArr { 4, 5, 6},
        dynCount{3},
        dynArr{new int[3]{1, 2, 3}}
    {}

    //случай с параметрами
    Point(int a,int b,string t, int dc):
        x{ a },
        y{ b },
        title { t },
        statArr { 4, 5, 6},
        dynCount{ dc },
        dynArr{new int[dc]{}}
    {}


    void render()
    {
        cout<< x << "\t" << y <<"\t" <<title<<endl;
        cout<<"statArr\n";
        for(int i{}; i < 3;i++)
        {
            cout<<statArr[i]<<' ';
        }
        cout << endl;
    }


};



int main()
{   

    Point p{};
    p.render();

    Point b{3,4,"B",10};
    b.render();

}


#endif


#ifdef INITIALIZATORS2

class Role
{
private:
    int id;
    string title;

public:
    Role(int id, string title = "no_title") :
    id{id}, title{ title }
    {}

};


class User
{
private:
    int id;
    string email;
    Role role;

public:
    User(int id, string email, int role_id,string role_title) :
    id{id},
    email{ email },
    role{ role_id, role_title }
    {}

};



#endif

#ifdef INITIALIZATORS3

class Point
{
private:
    int x{ 1 };   //значение по умолчанию(запасной вариант инициализации)
    int y{ 1 };   //значение по умолчанию(запасной вариант инициализации)
    const int radius;

public:
    Point(int a,int b, int r = 1) : 
    x{a},
    y{b},
    radius{r}
    {}

    Point(int r) :
        radius{r}
    {}

    void render()
    {
        cout<<x<<' '<<y<<endl;
    }

};


int main()
{
    Point a{10}.render();

    return 0;
}


#endif

#ifdef CTOR_DELEGATION

class User
{
private:
    int id;
    string email;

public:
    User(int newId,string email) :
    email{ email }
    {

        id  = newId < 0 ? 0 : newId;
    
    }

    User(string email) :
        User{102,email}
    {}


};


int main()
{

    User("vasia@gmail.com");

    return 0;
}


#endif


#ifdef DESTRUCTOR

class Student
{
private:
    int id;
    int* grades;
    int gradesCount;

public:
    Student(int id, int gCount) :
    id{id},
    gradesCount{gCount},
    grades{new int[gCount]}
    {}

    // void clearMemony()
    // {
    //     if(grades != nullptr)
    //     {
    //         delete[] grades;
    //     }
    // }    

    ~Student()
    {

        if(grades != nullptr)
        {
            delete[] grades;
        }
        cout<<"Student destruktor"<<endl;
    }

};

void func()
{
    Student s{101,1000};

}

int main()
{
    func();


}

#endif