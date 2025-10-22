#include <iostream>
// #include <fstream>
// #include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>


using namespace std;


int** create_array(int& rows,int& cols)
{
    int** ptr_Array = new int* [rows];

    for(int i = 0;i < rows;++i)
    {
        *(ptr_Array + i) = new int[cols];
    }



    return ptr_Array;
}


void zapovn(int** array,int rows,int cols,int min_num,int max_num)
{
    for(int i = 0; i < rows;++i)
    {
        for(int j = 0; j < cols;++j)
        {
            *( *(array + i) + j ) = rand() % (max_num - min_num + 1) + min_num;
        }
    }


}

void print_array(int** array,int rows,int cols)
{
    for(int i = 0; i < rows;++i)
    {
        for(int j = 0; j < cols;++j)
        {
            cout<<*( *(array + i) + j )<<' ';
        }
        cout<<endl;
    }

}

void count(int** array,int rows,int cols,int* still_array)
{
    for(int i = 0;i < cols;++i)
    {
        for(int j = 0; j < rows;++j)
        {
           still_array[i] += *(*(array+ j) + i);
        }
    }

}


int main() {

    srand(time(NULL));
    
    cout<<"Введите количество строчек: ";
    int rows;
    cin>>rows;

    cout<<"Введите количество столбцов: ";
    int cols;
    cin>>cols;

    int** array = create_array(rows,cols);

    cout<<"Введите самое маленькое число диапазона: ";
    int min_num;
    cin>>min_num;

    cout<<"Введите самое большое число диапазона: ";
    int max_num;
    cin>>max_num;


    zapovn(array,rows,cols,min_num,max_num);
    print_array(array,rows,cols);

    int still_array[cols];
    for (int i = 0; i < cols; ++i) {
        still_array[i] = 0;
    }

    for(int i = 0;i < cols;++i)
    {
        cout<<"- ";
    }
    cout<<endl;

    count(array,rows,cols,still_array);

    for(int i = 0;i < cols;++i)
    {
        cout<<still_array[i]<<' ';
    }
    cout<<endl;


    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}