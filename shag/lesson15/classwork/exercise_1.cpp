#include <iostream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
#include<cmath>
// #include <iomanip>


#define ADD(a,b) (a+b)
#define SW(t,a,b) {t temp = a;a = b;b = temp;}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQRT(a) (a*a)
#define POW(a, b) (pow(a, b))
#define PARN(a) ((a%2==0) ? (true) : (false))
#define NEPARN(a) ((a%2!=0) ? (true) : (false))

using namespace std;







int main() {
    srand(time(NULL));

    int num1 = 10, num2 = 20;

    cout << "Менше з двох: " << MIN(num1, num2) <<endl;

    cout << "Большее з двох: " << MAX(num1, num2) <<endl;

    cout << "Число в квадраті: " << SQRT(num1) << endl;

    cout << "Вираз в степени: " << POW(2,3) << endl;

    cout << "Является ли число парным парное " << (PARN(num1) ? ("ДА") : ("НЕТ")) <<endl; 

    cout << "Является ли число НЕ парным парное " << (NEPARN(num1) ? ("ДА") : ("НЕТ")) <<endl;

    return 0;
}