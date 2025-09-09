#include <iostream>
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

int main() {

    srand(time(NULL));
    int rows_1 = 5,cols_1 = 10;
    int ar[rows_1][cols_1];


    int rows_2 = 5,cols_2 = 5;
    int ar2[rows_2][cols_2];

    for(int row = 0;row < rows_1; row++)
    {
        for(int col = 0;col < cols_1; col++)
        {
            ar[row][col] = rand() % 50;
            cout<<ar[row][col]<<"\t";
        }
        cout<<endl;
    }



    for (int row = 0; row < rows_2; row++) {
        for (int col_2 = 0; col_2 < cols_2; col_2++) {
            int col_1_first = col_2 * 2;       
            int col_1_second = col_1_first + 1; 

            ar2[row][col_2] = ar[row][col_1_first] + ar[row][col_1_second];
        }
    }

    cout<< endl;
    for (int row = 0; row < rows_2; row++) {
        for (int col = 0; col < cols_2; col++) {
            cout<< ar2[row][col] <<"\t";
        }
        cout << endl;
    }
    

    return 0;
}