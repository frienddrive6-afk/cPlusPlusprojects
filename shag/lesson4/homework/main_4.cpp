#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    srand(time(NULL));
    const int size = 10;
    int array[size];
    int array_2[size];
    int array_3[size];

    for(int i = 0; i<size;i++)
    {
        array[i] = 1 + rand() % (9 - 1 + 1);
        array_2[i] = 1 + rand() % (9 - 1 + 1);
    }

    cout<<"Массив_1: ";
    for(int i = 0; i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    cout<<"Массив_2: ";
    for(int i = 0; i<size;i++)
    {
        cout<<array_2[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i<size;i++)
    {
        array_3[i] = array[i] + array_2[i];
        cout<<array_3[i]<<" ";
    }
    cout<<endl;




    return 0;
}