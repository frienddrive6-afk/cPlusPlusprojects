#include <iostream>
// #include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

void MinMax(int* ar1,int size)
{
    int min = *ar1;
    int max = *ar1;
    int avg = 0;

    for(int i =0; i < size;i++)
    {
        if(*(ar1 + i) > max)
        {
            max = *(ar1 + i);
        }else if(*(ar1 + i) < min)
        {
            min = *(ar1 + i);
        }

        avg += *(ar1 + i);
    }

    cout<<"max: "<<max<<endl;
    cout<<"min: "<<min<<endl;
    cout<<"avg: "<<float(avg)/size<<endl;
}




int main() {

    srand(time(NULL));
    
    int size = 5;
    int ar1[size];

    for(int i =0; i < size;i++)
    {
        // ar1[i] = rand() % 100;
        *(ar1 + i) = rand() % 100;
    }

    for(int i =0; i < size;i++)
    {
        cout<<*(ar1 + i)<<" ";
    }
    cout<<endl;

    MinMax(ar1,size);


    return 0;
}