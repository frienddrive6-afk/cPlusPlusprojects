#include <iostream>
// #include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


void TurnOver(int* ar1,int size)
{
    int* p_start = ar1;                  
    int* p_end = ar1 + size - 1;         

    while (p_start < p_end)
    {
        int temp = *p_start; 
        *p_start = *p_end;   
        *p_end = temp;       

        p_start++; 
        p_end--;   
    }

    for(int i =0; i < size;i++)
    {
        cout<<*(ar1 + i)<<" ";
    }
    cout<<endl;
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

    TurnOver(ar1,size);

    



    return 0;
}