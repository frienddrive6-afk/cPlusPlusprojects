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


class Vector2d
{
private:
    double x;
    double y;

public:
    Vector2d(double x = 0.0f,double y = 0.0f) :
        x{x},
        y{y}
    {}

    const double& getX() const 
    {
        return this->x;
    }

    const double& getY() const
    {
        return this->y;
    }

    Vector2d operator+(const Vector2d& obj ) const
    {
        return(Vector2d{ this->x + obj.x , this->y + obj.y });
    }

    Vector2d operator-(const Vector2d& obj ) const
    {
        return(Vector2d{ this->x - obj.x , this->y - obj.y });
    }

    Vector2d operator*(const double numb ) const
    {
        return(Vector2d{ this->x * numb , this->y * numb });
    }

    Vector2d operator/(const double numb ) const
    {
        return(Vector2d{ this->x / numb , this->y / numb });
    }


    Vector2d& operator+=(const Vector2d& obj)
    {
        this->x += obj.x;
        this->y += obj.y;

        return *this;
    }

    Vector2d& operator-=(const Vector2d& obj)
    {
        this->x -= obj.x;
        this->y -= obj.y;

        return *this;
    }

    Vector2d& operator*=(const double numb)
    {
        this->x *= numb;
        this->y *= numb;

        return *this;
    }

    Vector2d& operator/=(const double numb)
    {
        this->x /= numb;
        this->y /= numb;

        return *this;
    }

    Vector2d operator-() const
    {
        return(Vector2d( -this->x, -this->y));
    }

    bool operator==(const Vector2d& obj) const
    {
        if(this->x == obj.x && this->y == obj.y)
        {
            return true;
        }else
        {
            return false;
        }
    }

    bool operator!=(const Vector2d& obj) const
    {
        return !operator==(obj);
    }

    double operator[](int index)
    {
        if(index == 1)
        {
            return this->x;
        }else if(index == 2)
        {
            return this->y;
        }else
        {
            double num = -1.0f;
            return num;
        }
    }

    Vector2d& operator()(double x,double y)
    {
        this->x = x;
        this->y = y;

        return *this;
    }

    Vector2d& operator++()
    {
        ++this->x;
        ++this->y;

        return *this;
    }

    Vector2d& operator--()
    {
        --this->x;
        --this->y;

        return *this;
    }

    Vector2d operator++(int)
    {
        Vector2d temp = *this;

        ++this->x;
        ++this->y;

        return temp;
    }

    Vector2d operator--(int)
    {
        Vector2d temp = *this;

        --this->x;
        --this->y;

        return temp;
    }




};


std::ostream& operator<<(std::ostream& out,const Vector2d& obj)
{
    out <<'('<<obj.getX()<<','<<obj.getY()<<')';
    return out;
}



 

int main()
{
    Vector2d v1(3, 4);
    Vector2d v2(1, 2);
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    Vector2d v_sum = v1 + v2;
    cout << "v1 + v2 = " << v_sum << endl;

    Vector2d v_diff = v1 - v2;
    cout << "v1 - v2 = " << v_diff << endl;
    
    Vector2d v_mul = v1 * 3;
    cout << "v1 * 3 = " << v_mul << endl;

    Vector2d v_div = v1 / 2;
    cout << "v1 / 2 = " << v_div << endl;

    Vector2d v_assign_test(10, 10);
    cout << "Начальный v_assign_test = " << v_assign_test << endl;
    v_assign_test += v1;
    cout << "После += v1: " << v_assign_test << endl;
    v_assign_test -= v2;
    cout << "После -= v2: " << v_assign_test << endl;
    v_assign_test *= 2;
    cout << "После *= 2: " << v_assign_test << endl;
    v_assign_test /= 4;
    cout << "После /= 4: " << v_assign_test << endl;
    
    Vector2d v_neg = -v1;
    cout << "-v1 = " << v_neg << endl;
    
    Vector2d v1_copy(3, 4);
    cout << "v1 = " << v1 << ", v2 = " << v2 << ", v1_copy = " << v1_copy << endl;
    cout << "v1 == v1_copy? " << (v1 == v1_copy ? "Да" : "Нет") << endl;
    cout << "v1 == v2? " << (v1 == v2 ? "Да" : "Нет") << endl;
    cout << "v1 != v2? " << (v1 != v2 ? "Да" : "Нет") << endl;

    cout << "v1[1] (x) = " << v1[1] << endl;
    cout << "v1[2] (y) = " << v1[2] << endl;
    cout << "v1[3] (неверный индекс) = " << v1[3] << endl;

    cout << "v2 до вызова: " << v2 << endl;
    v2(8, 8); 
    cout << "v2 после v2(8, 8): " << v2 << endl;
    
    cout << "Начальный v1 = " << v1 << endl;
    ++v1;
    cout << "После ++v1: " << v1 << endl;
    --v1;
    cout << "После --v1: " << v1 << endl;

    cout << "Начальный v2 = " << v2 << endl;
    Vector2d v2_before_inc = v2++; 
    cout << "Значение v2++: " << v2_before_inc << endl;
    cout << "v2 после v2++: " << v2 << endl;

    Vector2d v2_before_dec = v2--; 
    cout << "Значение v2--: " << v2_before_dec << endl;
    cout << "v2 после v2--: " << v2 << endl;

    return 0;
}

