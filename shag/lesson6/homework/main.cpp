#include <iostream>
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

int main() {

    srand(time(NULL));
    int rows = 4,cols = 5;

    int ar[rows][cols];

    for(int row = 0;row < rows; row++)
    {
        for(int col = 0;col < cols; col++)
        {
            ar[row][col] = rand() % 100;
            cout<<ar[row][col]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    int choise_user;
    cout<<"Как вы хотите отсортировать:\n1)по столбикам\n2)по рядам\n->";
    cin>>choise_user;

    int ar2[cols][rows];
    int ar3[rows * cols];
    int ar3_index = 0;

    switch (choise_user)
    {
    case 1:
        
        for(int row = 0;row < rows; row++)
        {
            for(int col = 0;col < cols; col++)
            {
                ar2[col][row] = ar[row][col];
                // cout<<ar2[col][row]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;

        for(int col = 0;col < cols;col++)
        {
            sort(ar2[col], ar2[col] + rows);
        }
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                // Читаем из отсортированного ar2 и выводим
                cout << ar2[col][row] << "\t";
            }
            cout << endl;
        }


        break;


    case 2:
        for(int row = 0;row < rows; row++)
        {
            for(int col = 0;col < cols; col++)
            {
                ar3[ar3_index++] = ar[row][col];
                // cout<<ar3[ar3_index]<<" ";
            }
        }

        for( int i = 0; i < (rows * cols); i++)
        {
            cout<<ar3[i]<<" ";
        }
        cout<<endl;

        sort(ar3,ar3 + (rows * cols));

        for( int i = 0; i < (rows * cols); i++)
        {
            cout<<ar3[i]<<" ";
        }
        cout<<endl;

        ar3_index = 0;
        for(int row = 0;row < rows; row++)
        {
            for(int col = 0;col < cols; col++)
            {
                ar[row][col] = ar3[ar3_index++];
            }
        }

        for(int row = 0;row < rows; row++)
        {
            for(int col = 0;col < cols; col++)
            {
                cout<<ar[row][col]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;


        break;
    
    default:
    cout<<"error"<<endl;
        break;
    }

    return 0;
}