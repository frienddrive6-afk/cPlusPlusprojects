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

// #define INTO
#define STATIC_METODS

using namespace std;




#ifdef INTO

int count{ 0 };

// class Container
// {
// public:
//     int val;



//     void render()
//     {
//         cout<<this->val << ' ' << count <<endl;
//     }

// };


static int a;
static const int b{0};

class Container
{
public:
    static int count;
    static const int id{ 101 }; //как исключения для static const
    int val;


};
//Инициализация только за пределами класса
//Не привязана к модификаторам доступа
int Container::count{ 10 };

int main()
{

    Container a;
    Container b;

    a.val = 10;
    b.val = 20;

    a.count = 500;                  //обращение через обьект
    Container::count = 700;         //обращение через имя класса(даже если не создан ни один обьект)


    cout << b.val << ' ' << b.count <<endl;
    cout << Container::count <<endl;

    return 0;
}



#endif



#ifdef STATIC_METODS

class Container
{
private:
    static int count;

public:
    int val;


    static int getCount()
    {
        //нет *this!!!

        return Container::count;
    }


};


int Container::count{};


int main()
{
    cout << Container::getCount() <<endl;   //OK

    Container a{};
    cout << a.getCount() <<endl;                            //NOT OK



    return 0;
}


#endif
