#include <iostream>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;



int Max_num(int a,int b)
{
    if(a > b)
    {
        return a;
    }else
    {
        return b;
    }
}

int Max_num(int a, int b, int c) {
    int max = a; 
    if (b > max) {
        max = b; 
    }
    if (c > max) {
        max = c; 
    }
    return max;
}




int main() {

    srand(time(NULL));
    
    int res1,res2;

    res1 = Max_num(2,1);
    res2 = Max_num(1,2,3);


    cout<<"Первый "<<res1<<endl;
    cout<<"Второй "<<res2<<endl;
   


    return 0;
}

