#include <iostream>
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

int main() {


    //Теория

    //Общее
    // srand(time(NULL));
    // const int rows = 3,cols = 3;
    // int ar[rows][cols];


    // for(int row = 0; row < rows;row++)
    // {
    //     for(int col = 0;col<cols;col++)
    //     {
    //         ar[row][col] = rand() % 10;
    //         cout<< ar[row][col] <<" ";
    //     }
    //     cout<<endl;
    // }
    //end





    // for(int row = 0; row < rows;row++)
    // {
    //     int minR = ar[row][0];
    //     for(int col = 0;col<cols;col++)
    //     {
    //         if(ar[row][col] < minR)
    //         {
    //             minR = ar[row][col];
    //         }
    //     }
    //     cout<<"|"<<minR<<endl;
    // }

    


    // int max = ar[0][0],min = ar[0][0];


    // for(int row = 0; row < rows;row++)
    // {
    //     for(int col = 0;col<cols;col++)
    //     {
    //         if(ar[row][col] > max)
    //         {
    //             max = ar[row][col];
    //         }

    //         if(ar[row][col] < min)
    //         {
    //             min = ar[row][col];
    //         }
    //     }
    //     // cout<<endl;
    // }


    // cout<<"max: "<<max<<endl;
    // cout<<"min: "<<min<<endl;



    // //V2
    // for(int row = 0; row < rows;row++)
    // {
    //     for(int col = 0;col<cols;col++)
    //     {
    //         ar[row][col] = rand() % 10;
    //         cout<< ar[row][col] <<" ";
    //     }

    //     int minR = ar[row][0];
    //     for(int col = 0;col<cols;col++)
    //     {
    //         if(ar[row][col] < minR)
    //         {
    //             minR = ar[row][col];
    //         }
    //     }
    //     cout<<"|"<<minR<<endl;
    // }
    // //


    
    //2 сортировка по строчкам
    // cout<<endl;

    // for(int row = 0; row < rows;row++)
    // {
    //     sort(ar[row],ar[row]+3);
    // }


    // for(int row = 0; row < rows;row++)
    // {
    //     for(int col = 0;col<cols;col++)
    //     {
    //         cout<< ar[row][col] <<" ";
    //     }
    //     cout<<endl;
    // }

    


    //3 перевод из двух мирового масива в одномировой
    // int ar1[rows * cols];
    // int index = 0;

    // for(int row = 0; row < rows;row++)
    // {
    //     for(int col = 0;col<cols;col++)
    //     {
    //         ar1[index++] = ar[row][col];
    //     }
    // }

    // for(int i = 0; i < (rows * cols);i++)
    // {
    //     cout<<ar1[i]<<" ";
    // }
    // cout<<endl;




    //Задача1
    // srand(time(NULL));
    // const int rows = 3,cols = 4;
    // int ar[rows][cols];

    // for(int row = 0; row < rows; row++)
    // {
    //     int userNumberStart;
    //     cout<<"Введите начальное число: ";
    //     cin>>userNumberStart;
    //     for(int col = 0;col < cols;col++)
    //     {
    //         ar[row][col] = userNumberStart+col;
    //     }
    // }


    // for(int row = 0; row < rows;row++)
    // {
    //     for(int col = 0;col<cols;col++)
    //     {
    //         cout<< ar[row][col] <<" ";
    //     }
    //     cout<<endl;
    // }





    //Задача2
    // srand(time(NULL));
    // const int rows = 3,cols = 4;
    // int ar[rows][cols];

    // int userNumberStart;
    // cout<<"Введите начальное число: ";
    // cin>>userNumberStart;
    // int numbPlus = 0;

    // for(int row = 0; row < rows; row++)
    // {
    //     for(int col = 0;col < cols;col++)
    //     {
    //         ar[row][col] = userNumberStart+numbPlus++;
    //     }
    // }


    // for(int row = 0; row < rows;row++)
    // {
    //     for(int col = 0;col<cols;col++)
    //     {
    //         cout<< ar[row][col] <<"\t";
    //     }
    //     cout<<endl;
    // }
    









    //Задача2
    // srand(time(NULL));
    // int rows_A = 4,cols_A = 5;
    // int rows_B = 5,cols_B = 7;

    // int A[rows_A][cols_A],B[rows_B][cols_B];

    // int numbMinus = 0;

    // for(int row = 0; row<rows_A;row++)
    // {
    //     for(int col = 0; col<cols_A;col++)
    //     {
    //         A[row][col] = -10 + rand() % (10 + 10 + 1);

    //         if(A[row][col] < 0)
    //         {
    //             numbMinus++;
    //         }
    //     }
        
    // }

    // for(int row = 0; row<rows_A;row++)
    // {
    //     for(int col = 0; col<cols_A;col++)
    //     {
    //         cout<<A[row][col]<<"\t";
    //     }
    //     cout<<endl;   
    // }



    // cout<<endl;



    // for(int row = 0; row<rows_B;row++)
    // {
    //     for(int col = 0; col<cols_B;col++)
    //     {
    //         B[row][col] = -10 + rand() % (10 + 10 + 1);

    //         if(B[row][col] < 0)
    //         {
    //             numbMinus++;
    //         }
    //     }
        
    // }

    // for(int row = 0; row<rows_B;row++)
    // {
    //     for(int col = 0; col<cols_B;col++)
    //     {
    //         cout<<B[row][col]<<"\t";
    //     }
    //     cout<<endl;   
    // }



    // cout<<"col min: "<<numbMinus<<endl;

    // int AB[numbMinus];
    // int AB_index = 0;

    // for(int row = 0; row<rows_A;row++)
    // {
    //     for(int col = 0; col<cols_A;col++)
    //     {
    //         if(A[row][col] < 0)
    //         {
    //             AB[AB_index++] = A[row][col];
    //         }
    //     }
    // }

    // for(int row = 0; row<rows_B;row++)
    // {
    //     for(int col = 0; col<cols_B;col++)
    //     {
    //         if(B[row][col] < 0)
    //         {
    //             AB[AB_index++] = B[row][col];
    //         }
    //     }
    // }


    // for(int i = 0; i< numbMinus; i++)
    // {
    //     cout<<AB[i]<<" ";
    // }
    // cout<<endl;








    //Задача3
    // srand(time(NULL));
    // int rows_M = 5,cols_M = 7;

    // int M[rows_M][cols_M],L[cols_M][rows_M];


    // for(int row = 0; row < rows_M;row++)
    // {
    //     for(int col = 0; col < cols_M; col++)
    //     {
    //         M[row][col] = rand() % 10;
    //     }
    // }



    // for(int row = 0; row < rows_M;row++)
    // {
    //     for(int col = 0; col < cols_M; col++)
    //     {
    //         cout<<M[row][col]<<"\t";
    //     }
    //     cout<<endl;
    // }


    // int ar[rows_M*cols_M];
    // int index = 0;

    // for(int row = 0; row < rows_M;row++)
    // {
    //     for(int col = 0; col < cols_M; col++)
    //     {
    //         ar[index++] = M[row][col];
            
    //     }
    //     // cout<<endl;
    // }
    // cout<<endl;

    // for(int i = 0;i < (rows_M * cols_M); i++)
    // {
    //     cout<<ar[i]<<" ";
    // }
    // cout<<endl<<endl;


    // int index_2 = 0;
    // for(int row = 0; row < cols_M;row++)
    // {
    //     for(int col = 0; col < rows_M; col++)
    //     {
    //         L[row][col] = ar[index_2++];
    //         cout<<L[row][col]<<"\t";
            
    //     }
    //     cout<<endl;
    // }




    //Задача4
    // int A[2][3][4] =
    // {
    //     {{8, 3, -5, 2},{-3, 2, 8, 4},{1, 0, 3, -9}},
    //     {{-2, 9, 5, 4},{1, 0, 2, 5},{-8, 3, 4, 2}}
    // };

    // for (int k = 0; k < 2; k++) {
    //     for (int r = 0; r < 3; r++) {
    //         for (int s = 0; s < 4; s++) {
    //             cout << A[k][r][s] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }




    //Задача5
    // int A[2][3][4] =
    // {
    //     {{8, 3, -5, 2},{-3, 2, 8, 4},{1, 0, 3, -9}},
    //     {{-2, 9, 5, 4},{1, 0, 2, 5},{-8, 3, 4, 2}}
    // };

    // for (int k = 0; k < 2; k++) {
    //     int sumB = 0; 
    //     for (int r = 0; r < 3; r++) {
    //         for (int s = 0; s < 4; s++) {
    //             cout << A[k][r][s] << ' ';
    //             sumB+=A[k][r][s];
    //         }
    //         cout << endl;
    //     }
    //     cout<<"Ser: "<<(float)sumB/12 << endl;

    // }



    //Задача6
    int bloks = 2,rows = 3,cols = 4;
    int A[bloks][rows][cols];

    for (int block = 0; block < bloks; block++) {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                A[block][row][col]  = rand() % 10;
                cout<<A[block][row][col]<<"\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    int ar[bloks*rows*cols];
    int index = 0;

    for (int block = 0; block < bloks; block++) {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                ar[index++] = A[block][row][col];
            }
            // cout << endl;
        }
        // cout << endl;
    }

    for(int i = 0; i < (bloks*rows*cols); i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}