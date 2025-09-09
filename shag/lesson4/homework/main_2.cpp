#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    

    srand(time(NULL));
    const int size = 12;
    int array[size];
    int start,end;
    int max_mounth,nim_mouth;

    for(int i = 0; i<size;i++)
    {
        array[i] = 10000 + rand() % (20000 - 10000 + 1);
        cout<<array[i]<<" ";
    }
    cout<<endl;

    cout<<"Введите начала диапазона 1-11: ";
    cin>>start;

    cout<<"Введите конец диапазона: ";
    cin>>end;

    int array_2[end-start];
    for(int i = 0; i<=(end-start)-1;i++)
    {
        array_2[i] = array[start+i-1];
        cout<<array_2[i]<<" ";
    }
    cout<<endl;

    int minInDiapazone=20001,maxInDiapazone=0;

    for(int i = 0;i<(sizeof(array_2)/sizeof(array_2[0])); i++)
    {
        if(array_2[i]>maxInDiapazone)
        {
            maxInDiapazone = array_2[i];
        }

        if(array_2[i]<minInDiapazone)
        {
            minInDiapazone = array_2[i];
        }
    }

    // cout<<maxInDiapazone<<endl;
    // cout<<minInDiapazone<<endl;

    int max_index,min_index;

    for(int i = 0; i<size;i++)
    {
        if(array[i] == maxInDiapazone)
        {
            cout<<"Из выбраного диапазона максималиная прибыль была за " <<i+1 <<" месяц"<<endl;
        }

        if(array[i] == minInDiapazone)
        {
            cout<<"Из выбраного диапазона минимальная прибыль была за " <<i+1 <<" месяц"<<endl;
        }
    }




    return 0;
}