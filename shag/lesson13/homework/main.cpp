#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


struct Monitors
{
    string name;
    int garant_days;
    int price;
};



void zapovn(vector<Monitors>& m1,int size)
{
    for(int i = 0;i < size;i++)
    {
        cout<<"Введите название монитора: ";
        cin>>m1[i].name;

        cout<<"Введите термин гаранитии: ";
        cin>>m1[i].garant_days;

        cout<<"Введите цену: ";
        cin>>m1[i].price;
    }
}

void OnDisplay(vector<Monitors>& m1,int size)
{
    for(int i = 0;i < size;i++)
    {
        cout<<"Название монитора -> "<<m1[i].name<<" Термин гарантии этого монитора составляет -> "<<m1[i].garant_days<<" и цена этого монитора составляет -> "<<m1[i].price<<endl;
    }
}


void filter(vector<Monitors>& m1,vector<Monitors>& fillter_rsults)
{
    // int m1_leght = m1.size();
    while (m1.size() > 0)
    {
        int min_price = 2147483647;
        int min_index = -1;
        for(int i = 0;i < m1.size();i++)
        {
            if(m1[i].price < min_price )
            {
                min_price = m1[i].price;
                min_index = i;
            }
        }
        // int index = find(m1.begin(),m1.end(),min_price);
        fillter_rsults.push_back(m1[min_index]);

        m1.erase(m1.begin() + min_index);
    }
     
}


int main() {

    srand(time(NULL));

    int size;

    cout<<"Введите количество мониторов: ";
    cin>>size;
    vector<Monitors> m1(size);
    vector<Monitors> fillter_rsults;

    zapovn(m1,size);
    OnDisplay(m1,size);

    cout<<endl<<endl;
    cout<<"Отсортированые мониторы: "<<endl;
    filter(m1,fillter_rsults);
    OnDisplay(fillter_rsults,size);
    


    return 0;
}