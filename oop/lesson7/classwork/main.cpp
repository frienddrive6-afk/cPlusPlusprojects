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
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>



// #define INTO
// #define CHANING
#define PRACTICE_1


using namespace std;



#ifdef INTO

class Container
{
private:
    int val;

public:
    Container(int val)
    {
        this->val = val;
    }


    int getVal()
    {
        return this->val;
    }

    void setVal(int val)
    {
        this->val = val;
    }


    void exp()
    {
        cout<<this<<endl;
    }
};




int main()
{   
    
    // Container a { 15 };
    // Container b { 20 };

    // cout<<a.getVal()<<endl;
    // cout<<b.getVal()<<endl;

    // cout<<endl;

    // a.exp();
    // b.exp();


    Container* c = new Container{30};
    cout<< c <<endl;
    c->exp();


    return 0;
}

#endif //INTO


#ifdef CHANING

// class Calc
// {
// private:
//     int val;

// public:
//     Calc() :
//         val{}
//     {}


//     int getVal()
//     {
//         return this->val;
//     }

//     int add(int v)
//     {
//         return this->val += v;
//     }

//     int sub(int v)
//     {
//         return this->val -= v;
//     }

//     int mult(int v)
//     {
//         return this->val *= v;
//     }

//     void render()
//     {
//         cout<<"val = " <<this->val << val<<endl;
//     }

// };

class Calc
{
private:
    int val;

public:
    Calc() :
        val{}
    {}


    int getVal()
    {
        return this->val;
    }

    Calc* add(int v)
    {
        this->val += v;
        return this;
    }

    Calc* sub(int v)
    {
        this->val -= v;
        return this; 
    }

    Calc* mult(int v)
    {
        this->val *= v;
        return this;
    }

    void render()
    {
        cout<<"val = " <<this->val << val<<endl;
    }

};


int main()
{

    // Calc calc{};

    // cout << calc.add(5) <<endl;
    // cout << calc.mult(4) <<endl;
    // cout << calc.sub(17) <<endl;


    // calc.render();

    Calc* calc = new Calc{};

    calc
        ->add(5)
        ->mult(4)
        ->sub(17)
        ->render();



    return 0;
}

#endif //CHANING


#ifdef PRACTICE_1

int currentId{ 100 };

enum Gender
{
    MALE,
    FEMALE
};

class Student
{
private:
    int id;
    string name;
    short age;
    Gender gender;
    string group{""};

    int gCount{0};
    int* grades{nullptr};

public:
    Student(string name,short age,Gender gender) :
        id{ ++currentId },
        name{ name },
        age{ age },
        gender{ gender }
    {}


    void setGoup(string group)
    {
        this->group = group;
    }

    void render()
    {
        cout << "id: " <<this->id<< " name: "<<this->name <<" age: "<<this->age;
        cout<<" gender: " <<(this->gender == Gender::MALE ? "male" : "female");
        cout<<" group: " <<(this->group == "" ? "no group" : this->group);
        cout<<"\nGRADES\n";
        
        if(this->grades == nullptr)
        {
            cout<<"no grades";
        }else
        {
            for(int i{}; i < this->gCount;++i)
            {
                cout<<grades[i] <<' ';
            }
            cout<<endl;

        }
    }

    void addGrede(int grede)
    {
        if(this->grades == nullptr)
        {
            grades = new int[++this->gCount]{grede};
            
            return;
        }

        int* temp = new int[++this->gCount];
        for(int i{}; i < this->gCount-1;++i)
        {
            temp[i] = this->grades[i];
        }

        temp[this->gCount-1] = grede;

        delete[] this->grades;

        this->grades = temp;

    }


};


int main()
{

    Student s{"Vasia",23,Gender::MALE};
    s.setGoup("P42");
    s.render();

    s.addGrede(10);
    s.addGrede(10);
    s.addGrede(10);

    s.render();


    return 0;
}



#endif