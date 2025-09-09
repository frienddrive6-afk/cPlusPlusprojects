#include <iostream>
#include<algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    


    srand(time(NULL));
    int size;
    cout<<"Введите количество учасников";
    cin>>size;
    int ar[size];

    for(int i = 0; i<size;i++)
    {
        ar[i] = rand() % 600;
    }

    for(int i: ar) cout<< i <<" ";
    cout<<endl<<endl;

    for(int i = 0; i<size;i++)
    {
        for(int j = 0; j<size-1;j++)
        {
            if(ar[j]<ar[j+1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j+1] = temp;
            }
        }
    }

    for(int i: ar) cout<< i <<" ";
    cout<<endl;

    for(int i = size-1; i>=0;i--)
    {
        cout<<i+1<<"   ";
    }
    cout<<endl;
    







    return 0;
}