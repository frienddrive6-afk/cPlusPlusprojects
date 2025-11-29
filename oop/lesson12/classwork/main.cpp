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

// #define first
// #define second
// #define thirth
// #define fouth
// #define fifth
// #define fifth_part_2
#define sixth


using namespace std;




#ifdef first

class Box
{
private:
    int arr[10];


public:
    Box()
    {
        for(int i{};i < 10;++i)
        {
            arr[i] = i * i;
        }

    }

    int getElement(int index)
    {
        return arr[index];
    }

    void render() const
    {
        for(int i{};i < 10;++i)
        {
            cout<< arr[i] <<' ';
        }
        cout<<"\n\n";
    }

    // int operator[](int index)
    // {
    //     return this->arr[index];
    // }

    // const int& operator[](const int index) const
    // {
    //     return this->arr[index];
    // }


    int* operator[](const int index)
    {
        return this->arr + index;
    }

};



int main()
{

    // Box a;

    // a.render();

    // cout<<a.getElement(5)<<endl;
    // cout<<a[5]<<endl;


    // Box a{};
    // int res{ a[5] };
    // cout<< a[5] <<endl;
    // a[5] = 100;
    // cout<<a[5]<<endl;
    // a.render();



    Box a{};
    int res{ *a[5] };
    cout<< res <<endl;
    *a[5] = 100;
    a.render();





    return 0; 
}


#endif


#ifdef second

class Matrix
{
private:
    int arr[5][5] {};

public:
    void operator()()
    {
        for(int i{}; i < 5;++i)
        {
            for(int j{};j < 5;j++)
            {
                arr[i][j] = 9;
            }
        }
    }

    int& operator()(int row,int col)
    {
        return arr[row][col];
    }


    const int& operator()(int r,int c) const
    {
        return arr[r][c];
    }



};


int main()
{

    Matrix a{};

    a();                      // <--------- Функтор

    cout<< a(3,4)<<endl;

    a(3,4) = 100;

    return 0;
}


#endif


#ifdef thirth

class Box
{
private:
    int val;

public:
    Box(int val = 1) :
        val{val}
    {}


    int& operator()(int inc)
    {
        this->val += inc;

        return this->val;
    }


    void render()
    {
        cout<<"val= "<<this->val <<endl;
    }

};


int main()
{

    Box a{100};
    Box b{};


    a(20);
    b(30);





    return 0;
}



#endif


#ifdef fouth

class Counter
{
private:
    int val;


public:
    Counter(int init) :
        val{init}
    {}

    Counter& operator()()
    {
        this->val++;
        return *this;
    }


    void render()
    {
        cout<<"conster = " <<this->val<<endl;

    }


};



int main()
{

    Counter a{ 100 };

    a()()()()();
    a.render();


    return 0;
}



#endif


#ifdef fifth

class Pocket
{
private:
    int val;

public:
    explicit Pocket(int val) :
        val{val}
    {}

    int getVal() const
    {
        return this->val;
    }

    void setVal(int val)
    {
        this->val = val;
    }


    operator int() const
    {
        return this->val;
    }




};




int main()
{
    Pocket a{ 100 };
    a.setVal( 500 );
    cout<<a.getVal()<<endl;
    
    cout<< (int)a <<endl;



    return 0;
}



#endif

#ifdef fifth_part_2

class Point
{
public:
    int x;
    int y;

    Point(int x,int y) :
        x{ x },
        y{ y }
    {}

};

class Circle
{
private:
    Point centre;
    int r;

public:
    Circle(const Point& centre, int r) :
        centre{ centre },
        r{ r }

    {}

    void render()
    {
        cout<<"x = " <<this->centre.x << " y = " <<this->centre.y <<" r = " <<this->r <<endl;
    }


};

class Square
{
private:
    Point c;
    int size;


public:
    explicit Square(const Point& p,int size) :
        c{p},
        size{ size }
    {}

    void render()
    {
        cout<<"x = " << this->c.x <<" y = " << this->c.y <<" size = " <<this->size <<endl;
    }

    operator Circle()
    {
        int radius = this->size / 2;
        
        return Circle{this->c,radius};
    }



};



int main()
{

    Square a{Point{10,10}, 4};

    a.render();

    Circle b{ (Circle)a };
    b.render();



    return 0;
}




#endif

#ifdef sixth

class Point
{




};

std::ofstream& operator<<(const std::ofstream& out, const Point&)
{

    


}



int main()
{
    Point p{};
    cout << a;

    return 0;
}



#endif