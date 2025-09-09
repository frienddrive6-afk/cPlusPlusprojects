#include <iostream>
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

int main() {

    srand(time(NULL));
    int rows = 4,cols = 3;

    int ar[rows][cols];


    for(int row = 0;row < rows; row++)
    {
        int sum_row = 0;
        for(int col = 0;col < cols; col++)
        {
            ar[row][col] = rand() % 100;
            cout<<ar[row][col]<<"\t";
            sum_row+=ar[row][col];
        }
        cout<<"|\t"<<sum_row<<endl;
    }
    // cout<<endl;
    int zagal_sum_row = 0;
    cout << "------------------------" << endl;
    for (int col = 0; col < cols; col++) {
        int sum_col = 0; 
        for (int row = 0; row < rows; row++) {
            sum_col += ar[row][col]; 
        }
        zagal_sum_row += sum_col;
        cout << sum_col << "\t";
    }
    cout<<"| \t"<<zagal_sum_row<< endl;
    

    return 0;
}