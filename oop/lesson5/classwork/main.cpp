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


// #define CONSTRUCT
// #define CLASS_IN_CLASS

#define PRACTICE_1

using namespace std;



#ifdef CONSTRUCT

class Point
{
private:
    int x;
    int y;

public:
    //Конструктор создаваемый автоматически в случае отсуцтвии явного конструктора
    // Point
    // {}


    //конструктор по умолчанию (дефолтный конструктор)
    // Point()
    // {
    //     x = 10;
    //     y = 20;
    //     cout<<"Poitn defalt ctor"<<endl;
    // }
    Point(int a = 10,int b = 20)
    {
        x = a;
        y = b;
        cout<<"Point ctor"<<endl;
    }

    void render()
    {
        cout<<'('<<x<<';'<<y<<')'<<endl;
    }


};


int main()
{
    setlocale(LC_ALL, "");

    // Point a;
    // a.render();
    
    // Point b{};
    // b.render();


    // Point* p = new Point{};
    // p->render();

    Point a;
    a.render();

    Point b{};
    b.render();

    Point* c = new Point{};
    c->render();

    Point* d = new Point;
    d->render();

    Point* e = new Point();
    e->render();

    Point f{1,2};
    f.render();

    Point g{3};
    g.render();

    Point* h = new Point{5,6};
    h->render();

    Point* i = new Point{7};
    i->render();


    return 0;
}

#endif

#ifdef CLASS_IN_CLASS

class Group
{
private:

  std::string title;

public:

  Group()
  {
    std::cout << "Group ctor\n";
  }

};
class Role
{
private:

  std::string title;

public:

  Role()
  {
    std::cout << "Role ctor\n";
  }

};

class User
{
private:

  Role role;
  Group group;
  int id;

public:

  User()
  {
    std::cout << "User ctor\n";
  }

};



int main()
{

    User u{};


    return 0;
}

#endif


#ifdef PRACTICE_1

enum Color
{
    Red,
    Green,
    Blue,
    Yellow,
    White,
    Black
};


class Point
{
private:
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    void next_x(int a)
    {
        x = a;
    }

    int get_x()
    {
        return x;
    }

    void next_y(int a)
    {
        y = a;
    }

    int get_y()
    {
        return y;
    }

    void newx_XY(int a,int b)
    {
        x = a;
        y = b;
    }

};


class Circle
{
private:
    Point p{};
    int radius{};
    Color color{};
    int array_size; 
    Circle** arr;
    


public:
    Circle()
    {
        p.newx_XY(0,0);
        radius = 0;
        color = Green;
        array_size = 0;
        arr = nullptr;

    }

    Circle(int x,int y, int r,Color c)
    {
        p.newx_XY(x, y); 
        radius = r;
        color = c;
        array_size = 0;
        arr = nullptr;

    }


    void show()
    {
        cout<<"centre: "<<'('<<p.get_x()<<';'<<p.get_y()<<')'<<" r = "<<radius<<" цвет: ";
        
        switch (color)
        {
            case Red:
            {
                cout<<"Красный";
                break;
            }

            case Green:
            {
                cout<<"Зеленый";
                break;
            }

            case Blue:
            {
                cout<<"Голубой";
                break;
            }

            case Yellow:
            {
                cout<<"Желтый";
                break;
            }

            case White:
            {
                cout<<"Белый";
                break;
            }

            case Black:
            {
                cout<<"Черный";
                break;
            }
        }

    }

    void move(int new_X,int new_Y)
    {
        p.newx_XY(new_X,new_Y);
    }

    void SetColor(Color col)
    {
        color = col;
    }




    void addElmentToArray(Circle* c)
    {
        int new_size = array_size + 1;

        Circle** new_arr = new Circle*[new_size];


        for(int i = 0; i < array_size;++i)
        {
            new_arr[i] = arr[i];
        }

        new_arr[array_size] = c;

        delete[] arr;

        arr = new_arr;

        array_size = new_size;

    }

    void PrintCircls()
    {

        for(int i = 0; i < array_size;++i)
        {
            cout<<i+1<<')';
            arr[i]->show();
            cout<<endl;
        }
        

    }

};




int main()
{   
    Circle obj{2,3,4,Yellow};
    obj.addElmentToArray(new Circle{1,2,5,Green});
    obj.addElmentToArray(new Circle{20,2,55,Green});
    obj.addElmentToArray(new Circle{3,87,23,Yellow});
    obj.addElmentToArray(new Circle{45,12,32,Red});

    obj.PrintCircls();

    cout<<endl;

    obj.show();
    obj.move(100,200);
    obj.SetColor(Black);
    cout<<endl;
    obj.show();


    return 0;
}


#endif