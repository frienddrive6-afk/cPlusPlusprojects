#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

void PrintAr(int* mas,int size)
{
    for(int i = 0;i < size;i++)
    {
        cout<<*(mas + i)<<" ";
    }
    cout<<endl;
}



void PrintAr2(int(* mas)[5],int row)
{
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            // cout<<mas[i][j]<<" ";
            cout<<*(*(mas+i) + j)<<" ";
        }
        cout<<endl;
    }
    
}



int LenStr(char* p)
{
    int size = 0;
    while (*p != '\0')
    {
        size++;
        p++;
    }
    return size;
}


int LenStr(string* p)
{
    int size = 0;
    while (p[size++] != "\0")
    {
        // size++;
        p++;
    }
    return size;

}


int main() {

    srand(time(NULL));
    

    // int x= 5;

    // int &y = x; //Ссылка

    // cout<<&x<<endl;
    // y = 10;
    // cout<<y<<endl;
    // int z = 11;

    // int *p = &x; 
    // cout<<p<<endl;
    // cout<<*p<<endl;

    // *p = 15; //указатель(адрес),15(число)
    // cout<<*p<<endl;

    // p = &z;//указатель
    // cout<<p<<endl;




    //Арифметика

    // int a = 5,b = 7, c = 11;

    // int *p1 = &a;
    // int *p2 = &b;
    // int *p3 = &c;


    // cout<<p1<<endl;
    // cout<<++p1<<endl;
    // cout<<p2<<endl;
    // cout<<--p2<<endl;
    // cout<<p3<<endl;

    // cout<<p3-p1<<endl;



    // const int size = 6;
    // int ar[size] = {1,2,3,4,0,1};
    // int size = sizeof(ar)/sizeof(ar[0]);

    // cout<<sizeof(ar)<<endl;

    // for(int i = 0;i < size;i++)
    // {
    //     // cout<<ar[i]<<" ";
    //     cout<<*(ar + i)<<" ";
    // }
    // cout<<endl;


    // int *p1 = ar;
    // int *p2 = &ar[5]; 

    // cout<<p2 - p1 <<endl;

    // PrintAr(ar,size);







    // int ar[3][5] = {0};
    // int(*p)[5] = ar;
    // PrintAr2(p,3);



    // char txt[] = "pointer";
    // cout<<LenStr(txt)<<endl;


    string txt = "pointer";
    int LenStr(txt);


    return 0;
}