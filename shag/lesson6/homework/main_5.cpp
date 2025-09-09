#include <iostream>
#include <vector>


using namespace std;

int main() {


    srand(time(NULL));

    int blocks = 2,rows = 6,cols = 15;

    int A[blocks][rows][cols];

    for(int block = 0;block < blocks; block++)
    {
        cout<<block+1<<"ГОД"<<endl;
        for(int row = 0;row < rows; row++)
        {
            cout<<"\t"<<row+1<<" МЕСЯЦ"<<endl;
            for(int col = 0;col < cols; col++)
            {
                cout<<"\t\t"<<col+1<<" ДЕНЬ:";
                A[block][row][col] = -5 + rand() % (25 - (-5) + 1);
                cout<<A[block][row][col]<<" Градусов"<<endl;
            }
        }
    }






    int max_2_year = A[0][0][0];
    int min_2_year = A[0][0][0];

    for(int block = 0;block < blocks; block++)
    {
        // cout<<block+1<<"ГОД"<<endl;
        int min_t = A[block][0][0];
        int max_t = A[block][0][0];
        for(int row = 0;row < rows; row++)
        {
            // cout<<"\t"<<row+1<<" МЕСЯЦ"<<endl;
            for(int col = 0;col < cols; col++)
            {
                if(A[block][row][col] > max_t)
                {
                    max_t = A[block][row][col];
                }

                if(A[block][row][col] < min_t)
                {
                    min_t = A[block][row][col];
                }
                // cout<<"\t\t"<<col+1<<" ДЕНЬ:";
                // A[block][row][col] = -5  + rand() % 25-5+1;
                // cout<<A[block][row][col]<<" Градусов"<<endl;
            }
        }

        cout<<"За "<<block+1<<" год самая большая температура это "<<max_t<<endl;
        if(max_t > max_2_year)
        {
            max_2_year = max_t;
        }
        cout<<"За "<<block+1<<" год самая маленькая температура это "<<min_t<<endl;
        if(min_t < min_2_year)
        {
            min_2_year = min_t;
        }
    }

    cout<<"За весь период максимальная температура "<<max_2_year<<" градусов"<<endl;
    cout<<"За весь период минимальная температура "<<min_2_year<<" градусов"<<endl;







    return 0;
}