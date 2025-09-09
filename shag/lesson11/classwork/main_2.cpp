#include <iostream>
// #include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> //Динамические масивы
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;



void FillAr(int *ar,int size)
{
    for(int i = 0;i < size;i++)
    {
        *(ar + i) = rand() % 100;
        cout<<*(ar + i)<<" ";
    }
    cout<<endl;
}


void Find(int *ar,int size)
{
    int max = *ar,min = *ar;
    for(int i = 0;i < size;i++)
    {
        if(*(ar + i) > max)
        {
            max = *(ar + i);
        }else if(*(ar + i) < min )
        {
            min = *(ar + i);
        }
    }

    cout<<"min: "<<min<<" max: "<<max<<endl;
}


int main() {

    srand(time(NULL));
    

    int size;
    cout<<"Розмер масива: ";
    cin>>size;
    
    //Ручное выдиление памяти

    
    int *ar = new int[size];

    FillAr(ar,size);


    Find(ar,size);

    delete[] ar;

    return 0;
}