#include <iostream>
#include <vector> 
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


void Draw(int size = 5,char s = '+')
{
    for(int i = 1;i < size+1; i++)
    {
        for(int g = 0;g < i; g++)
        {
            cout<<s;
        }
        cout<<endl;
    }
    cout<<endl;
}


short MinNum(short a = 5,short b = 1)
{
    return (a < b) ? a:b;
}


vector<int> Zapovn(int leght,vector<int> ar)
{
    srand(time(NULL));

    for(int i = 0; i < leght; i++)
    {
        // ar[i] = rand() % 100;
        ar.push_back(rand() % 100);
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return ar;
}


vector<int> IfSort(vector<int> ar,int int_sort_v)
{
    switch (int_sort_v)
    {
    case 1:
        sort(ar.begin(),ar.end());
        reverse(ar.begin(),ar.end());
        break;
    
    case 2:
        sort(ar.begin(),ar.end());
        break;
    default:
        cout<<"err"<<endl;
        break;
    }
    for(int i : ar) cout<< i << " ";

    return ar;
}



void Mas(int row,int col,vector<vector<int>> ar)
{
    srand(time(NULL));

    for(int i = 0;i < row; i++)
    {
        for(int j = 0; j < col;j++)
        {
            ar[i][j]= rand() % 100;
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}


int main() {

    
    //Функции

    // int size;
    // char s;
    // cout<<"Введите рахмер: ";
    // cin>>size;
    // cout<<"Введите символ: ";
    // cin>>s;

    // Draw(size,s);
    // Draw();
    // Draw(s = '$');






    // cout<<MinNum()<<endl;

    //Задание 1
    // int leght;
    // cout<<"Введите длину масива: ";
    // cin>>leght;
    // vector<int> ar;

    // Zapovn(leght,ar);

    // int int_sort_v;
    // vector<int> a = Zapovn(leght,ar);
    // cout<<"Как сортировать\n1)За спаданием\n2)За поднятиям\n->";
    // cin>>int_sort_v;
    // // IfSort(ar,int_sort_v);

    // a = IfSort(a,int_sort_v);




    //Задание 2
    int row,col;
    cout<<"Введите размер строк стлбцов: ";
    cin>>row>>col;

    vector<vector<int>> ar(row,vector<int>(col));
    Mas(row,col,ar);



    return 0;
}