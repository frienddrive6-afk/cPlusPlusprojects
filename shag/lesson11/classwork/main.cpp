#include <iostream>
// #include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


void Zapovn(vector<int> *ar)
{
    int *p = ar->data();

    for(int i = 0;i < ar->size();i++)
    {
        *(p + i) = rand() % 100;
    }
}

void Print(vector<int> *ar)
{
    int *p = ar->data();

    // for(int i = 0;i < ar->size();i++)
    // {
    //     cout<<*(p + i)<<" ";
    // }
    // cout<<endl;

    for(int i:*ar)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}



void AddArrray(vector<int>* ar,int el)
{
    vector<int> dod(el);

    for(int i = 0;i < el;i++)
    {
        dod[i] = rand() % 100;
    }

    for(int i = 0;i <el;i++)
    {
        (*ar).push_back(dod[i]);
    }


}


void Vstavka(vector<int>* ar,int el,int ind)
{
    vector<int> dod(el);

    for(int i = 0;i < el;i++)
    {
        dod[i] = rand() % 100;
        *ar->insert(ar->begin() + ind, dod.begin(),dod.end());
    }
}


void ArrDel(vector<int>* ar,int el,int ind)
{
    ar->erase(ar->begin() + ind,ar->begin() + ind + el);
}

int main() {

    srand(time(NULL));
    

    int len;
    cout<<"len";
    cin>>len;

    vector<int> ar(len);

    Zapovn(&ar);

    Print(&ar);

    int variant;
    cout<<"Введите действие\n1)Добавить\n2)Вставить\n3)Удалить\nВаш выбор: ";
    cin>>variant;

    switch (variant)
    {
    case 1:
    {
        int col;
        cout<<"Введите количество элементов: ";
        cin>>col;
        AddArrray(&ar,col);
        break;
    }
    case 2:
    {
        int col;
        cout<<"Введите количество элементов: ";
        cin>>col;
        int pos;
        cout<<"Введите позицию в какую надо вставить ";
        cin>>pos;
        pos--;

        Vstavka(&ar,col,pos);

        break;
    }
    case 3:
    {
        int col;
        cout<<"Введите количество элементов: ";
        cin>>col;
        int pos;
        cout<<"Введите позицию в какую удалить: ";
        cin>>pos;
        pos--;

        ArrDel(&ar,col,pos);

        break;
    }
    
    default:
        cout<<"Такого варианта нет"<<endl;
        break;
    }

    Print(&ar);


    return 0;
}