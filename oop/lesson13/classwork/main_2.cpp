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
    int val;

public:
    Box(int val = 0) :
        val{ val }
    {}

    Box operator+(const Box& obj) const 
    {
        return Box{this->val + obj.val};
    }

    Box& operator+=(const Box& obj)
    {
        this->val += obj.val;
        return *this;
    }

    friend std::ostream& operator<<( std::ostream& , const Box&);

    Box operator/(int num)
    {
        return Box(this->val/num);
    }

};

std::ostream& operator<<( std::ostream& out, const Box& p)
{
    out<<p.val;
    return out;
}


template<typename T, typename K = T>
T average(T* array, int count)
{
    T temp{};

    for(int i{}; i < count; ++i)
    {
        // temp = temp + *( array + i );
        temp += array[i];
    }

    return (K)temp/count;

}





int main()
{

    int* arr0 = new int[5] {1,3,5,6,1};
    cout << average<int, double>(arr0,5)<<'\n';

    double* arr1 = new double[5] {1.4 ,3.6 ,5.7 ,6.1 ,1.0};
    cout << average<double>(arr1,5)<<'\n';

    Box* arr2 = new Box[5] { Box{3},Box{5},Box{7},Box{9},Box{1}  };
    cout << average<Box>(arr2,5)<<'\n';



    return 0;
}