#include <iostream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>


#define O cout
#define N cin
#define E endl
#define F float
#define S string
#define I int

#define ADD(a,b) (a+b)
#define SW(t,a,b) {t temp = a;a = b;b = temp;}


using namespace std;







int main() {
    srand(time(NULL));

    O<<"Препроцессор"<<endl;

    I a = 2,b = 3;
    O<< a << ' ' << b <<E;

    O<<ADD(a,b)<<E;

    SW(I,a,b)
    O<< a << ' ' << b <<E;

    F x = 1.2, y= 5.2;
    SW(F,x,y)
    O<< x << ' ' << y <<E;


    return 0;
}