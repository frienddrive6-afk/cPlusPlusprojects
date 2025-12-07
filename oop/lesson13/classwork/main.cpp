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





// template<typename T>
// T sum(const T a,const T b)
// {
//     return a + b;
// }





// int main()
// {

//     cout<<sum((std::string)"asasd",(std::string)" sasda")<<'\n';
//     cout<<sum(5,4)<<'\n';
//     cout<<typeid(sum(5.24221,4.23423)).name()<<'\n';
//     cout<<sum((bool)true,(bool)false)<<'\n';



//     return 0;
// }




class Box
{
private:
    int val;

public:
    Box(int val) :
        val{ val }
    {}

    Box operator+(const Box& obj) const 
    {
        return Box{this->val + obj.val};
    }

    friend std::ostream& operator<<( std::ostream& , const Box&);

};

std::ostream& operator<<( std::ostream& out, const Box& p)
{
    out<<p.val;
    return out;
}


template<typename T> 
T sum(const T& a, const T& b)
{
    return a + b;
}


int main()
{

    Box a{ 3 };
    Box b{ 4};

    cout<<sum( a, b)<<'\n';



    return 0;
}