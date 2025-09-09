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
    int sum = 0;

    for(int i = 0; i<size;i++)
    {
        ar[i] = -100 + rand() % (100 + 100 + 1);
        cout<<ar[i]<<" ";
        sum+= ar[i];
    }
    cout<<"\n\n";
    cout<<"sum: "<<sum<<endl;
    int ser = sum/size;
    cout<<"ser: "<<ser<<endl;

    int size_for;
    if(ser > 0)
    {
       size_for = size*2/3; 
    }else
    {
        size_for = size*1/3;
    }
    cout<<"size_for: "<<size_for<<endl;

    for(int i = 0; i<size_for-1;++i)
    {
        int min = i;
        for(int j = i; j<size_for;++j)
        {
            if(ar[j]<ar[min])
            {
                min = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[min];
        ar[min] = temp;
    }

    if(ser<0)
    {
        for(int i = 0; i<size_for;++i)
        {
            cout<<ar[i]<<" ";
        }

        for(int i = size-1; i>=(size-(size-size_for));i--)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }else
    {
        for(int i: ar) cout<< i <<" ";
        cout<<endl;
    }







    return 0;
}