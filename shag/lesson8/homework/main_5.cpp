#include <iostream>
#include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

int numSum(int k,...)
{
    int s = 0;

    va_list array;

    va_start(array,k);

    for (int i = 0; i < k; ++i) 
    {
        s += va_arg(array, int);
    }

    va_end(array);

    return s;
}



int main() {

    srand(time(NULL));
    
    int arr1[10];
    for(int i = 0;i < 10;i++)
    {
        arr1[i] = rand() % 10;
        cout<<arr1[i]<<"\t";
    }
    cout<<endl;

    int arr2[10];
    for(int i = 0;i < 10;i++)
    {
        arr2[i] = rand() % 10;
        cout<<arr2[i]<<"\t";
    }
    cout<<endl;

    cout << "Сумма: " << numSum(20, 
        arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], arr1[7], arr1[8], arr1[9],
        arr2[0], arr2[1], arr2[2], arr2[3], arr2[4], arr2[5], arr2[6], arr2[7], arr2[8], arr2[9]
    ) << endl;
   


    return 0;
}

