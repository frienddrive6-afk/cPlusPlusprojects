#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    srand(time(NULL));
    const int size_1 = 10;
    const int size_2 = 5;
    int array[size_1];
    int array_2[size_2];
    int array_3[size_2];

    for(int i = 0;i<size_1; i++)
    {
        array[i] = 1 + rand() % (9 - 1 + 1);
        cout<<array[i]<<" ";
    }
    cout<<endl;

    for(int i = 0;i<size_1; i++)
    {
        if(i<(size_1/2))
        {
            array_2[i] = array[i];
            cout<<array_2[i]<<" ";
        }
        cout<<endl;
        if(i>=(size_1/2))
        {
            array_3[i-(size_1/2)] = array[i];
            cout<<array_3[i-(size_1/2)];
        }
    }
    cout<<endl;




    return 0;
}