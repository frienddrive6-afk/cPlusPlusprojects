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





// int main() {
    
//     int a = 5;
//     int* b = new int{6};

//     return 0;
// }


// int main() {
    
//     int** ptr = new int*[3];

//     *ptr = new int{1018};

//     int* val = *ptr;

//     *(ptr+1) = new int{202};

//     *(ptr+2) = new int{202};

//     return 0;
// }



int main() {
    
    int rows = 2;
    int cols = 3;

    int** arr = new int*[rows];

    for(int i = 0; i < rows;i++)
    {
        *(arr + i) = new int[cols];
        // arr[i] = new int[cols];
    }

    for(int i = 0; i < rows;i++)
    {
       int* rowsAddr = *(arr + i);
       for(int j = 0;j < cols;++j)
       {
            *(rowsAddr + j) = 8;
       }
        
    }

    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < cols;++j)
        {
            cout<<*(*(arr + i)+j)<<' ';
            // cout<<arr[i][j] <<' ';
        }
        cout<<endl;
    }

    return 0;
}