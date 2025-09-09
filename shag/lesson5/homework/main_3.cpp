#include <iostream>
#include<algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    


    srand(time(NULL));
    const int size = 10;
    int ar[size];
    int obn = 0;

    for(int i = 0; i<size;i++)
    {
        ar[i] = rand() % 100;
        cout<<ar[i]<<" ";
    }
    cout<<"\n\n";



    for(int i = 0; i<size-1;++i)
    {
        int min = i;
        for(int j = i; j<size;++j)
        {
            if(ar[j]<ar[min])
            {
                min = j;
            }
            
        }
        // int temp = ar[i];
        // ar[i] = ar[min];
        // ar[min] = temp;
        // obn++;

        if (min != i) { 
            int temp = ar[i];
            ar[i] = ar[min];
            ar[min] = temp;
            obn++; 
        }
    }



    for(int i: ar) cout<< i <<" ";
    cout<<endl;

    cout<<"Сортировка за выбором сделает " <<obn <<" обменов"<<endl;
    







    return 0;
}