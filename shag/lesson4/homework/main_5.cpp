#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    srand(time(NULL));
    const int size_1 = 10;
    const int size_2 = size_1*2;
    int A[size_1];
    int B[size_1];
    int X[size_2];

    for(int i = 0; i<size_1;i++)
    {
        A[i] = 1 + rand() % (9 - 1 + 1);
        B[i] = 1 + rand() % (9 - 1 + 1);
    }

    cout<<"Массив_1: ";
    for(int i = 0; i<size_1;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    cout<<"Массив_2: ";
    for(int i = 0; i<size_1;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;



    for(int i = 0; i < size_2; i++) { 
        if (i % 2 == 0) { 

            X[i] = A[i / 2]; 
        } else {         
  
            X[i] = B[i / 2]; 
        }
    }


    cout<<"перемешаный масив: ";
    for(int i = 0;i<size_2;i++)
    {
        cout<<X[i]<<" ";
    }
    cout<<endl;



    return 0;
}