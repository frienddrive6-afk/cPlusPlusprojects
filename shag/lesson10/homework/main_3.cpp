#include <iostream>
// #include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


void CopedReverse(int* ar1,int* ar2,int size)
{

    for(int i = 0; i < size; i++)
    {
        *(ar2 + i) = *(ar1 + size - 1 - i);
    }

    for(int i =0; i < size;i++)
    {
        cout<<*(ar2 + i)<<" ";
    }
    cout<<endl;

}
    
    





int main() {

    srand(time(NULL));
    
    int size = 5;
    int ar1[size];
    int ar2[size];

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

    CopedReverse(ar1,ar2,size);

    



    return 0;
}