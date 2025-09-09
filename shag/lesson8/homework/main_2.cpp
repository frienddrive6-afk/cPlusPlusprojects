#include <iostream>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

const int row = 5,col = 5;


void Array_Create(int ar[], int size) {
    for(int i = 0; i < size; i++) {
        ar[i] = rand() % 100;
    }

    for(int i = 0; i < size; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}



void Array2_Create(int ar2[][col], int row,int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col ;j++)
        {
            ar2[i][j] = rand() % 100;
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col ;j++)
        {
            cout<<ar2[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout << endl;
}



int Max_arry(int array[],int size)
{
    int max_num = array[0];
    for(int i = 0;i < size;i++)
    {
        if(max_num < array[i])
        {
            max_num = array[i];
        }
    }

    return max_num;
}


int Max_arry2(int array[][col], int row,int col)
{
    int max_num = array[0][0];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col ;j++)
        {
            if(max_num < array[i][j])
            {
                max_num = array[i][j];
            }
        }
    }

    return max_num;
}



int main() {

    srand(time(NULL));
    

    const int size = 10;
    int ar[size];
    
    // const int row = 10,col = 10;
    int ar2[row][col];

    Array_Create(ar, size);
    cout<<endl; 
    
    Array2_Create(ar2,row,col);
    


    int max_num_array_1;
    max_num_array_1 = Max_arry(ar,size);
    cout<<"Максимальное число одномирного масива -> "<<max_num_array_1<<endl;

    int max_num_array_2;
    max_num_array_2 = Max_arry2(ar2,row,col);
    cout<<"Максимальное число двомирного масива -> "<<max_num_array_2<<endl;

    return 0;
}

