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
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>


using namespace std;

class Student
{
private:
    static int currentId;

    int id;
    string email;
    int gCount;
    int* grades;

    void clearGraderMemory()
    {
        if(this->grades != nullptr)
        {
            delete[] this->grades;
        }
    }

public:
    //Обычный конструктор

    explicit Student(string email = "", int gCount = 1) :
        id{ ++Student::currentId},
        email{ email },
        gCount{ gCount },
        grades{ new int[gCount] {}} 
    {
        cout<<"normal ctor"<<endl;
    }

    //Конструктор копирования
    Student(const Student& obj):
        id{ ++Student::currentId},
        email{ obj.email},
        gCount{ obj.gCount }
    {
        this->grades = new int[this->gCount];

        for(int i{}; i < this->gCount;++i)
        {
            this->grades[i] = obj.grades[i];
        }

        cout<<"copy ctor"<<endl;


    }

    //Конструктор переноса
    Student(Student&& obj) :
        id{ ++Student::currentId},
        email{ obj.email},
        gCount{ obj.gCount }
    {
        this->grades = obj.grades; //<-------- КЛЮЧЕВОЙ МОМЕНТ 
        
        obj.grades = nullptr;

        cout<<"move ctor"<<endl;
    }


    //Оператор присваивания копированием(обязательно)
    Student& operator=(const Student& obj)
    {

        if(this == &obj)
        {
            return *this;
        }

        this->email = obj.email;
        this->gCount = obj.gCount;

        clearGraderMemory();

        this->grades = new int[this->gCount];
        for(int i{}; i < this->gCount;++i)
        {
            this->grades[i] = obj.grades[i];
        }


        return *this;
    }

    //Оператор присваивания переносом
    Student& operator=(Student&& obj)
    {
        this->email = obj.email;
        this->gCount = obj.gCount;
        this->grades = obj.grades;
        obj.grades = nullptr;

        cout<<"move asiign"<<endl;

        return *this;
    }

    void render()
    {
        cout<<"id: "<<this->id<<endl;
        cout<<"email: "<<this->email<<endl;
        cout<<"Grades:"<<endl;
        for(int i{};i < this->gCount;++i)
        {
            cout<<this->grades[i] << " ";
        } 
        cout<<endl;
        cout<<endl;
    }

    //Деструктор(ОБЯЗАТЕЛЬНО)
    ~Student()
    {
        clearGraderMemory();

        cout<<"destructor"<<endl;
    }


};
int Student::currentId{100};


Student generate()
{
    cout<<"generate"<<endl;

    string  email = "vasia@mail.com";

    Student a{email,1000};

    return a;
}

int main()
{
    
    // Student a{"Vasai@gmail.com",15};
    // a.render();

    // Student b{ a };
    // b.render();


    // Student c{"sdfsdfsdf@gmail.com",30};
    // c.render();
    // c = a;
    // c.render();


    // Student a{ Student{"aasdasdasdasd@gamil.com", 5} };      // эллизия 
    // a.render();

    // Student a{};
    // a = generate();

    Student a{ *(new Student{"asdasdasd@mail.com",20})};
    a.render();


    
    return 0; 
}

