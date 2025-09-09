#include <iostream>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;



void Funk(int limit,bool reset = false)
{
    
    static int count = 0;

    if(reset == true)
    {
        count = 0;
        cout<<"счетчик скинут"<<endl;
        return;
    }

    if(count < limit)
    {
        count++;
        cout<<"Вызов №"<<count<<"Функция выполнена"<<endl;
    }else
    {
        cout<<"Лимит привышен"<<endl;
    }


}



int main() {

    srand(time(NULL));
    
    int limit;
    cout<<"Введите лимит:";
    cin>>limit;

    for(int i = 0;i < limit+1;i++)
    {
        Funk(limit);
    }

    Funk(limit,true);
    
    Funk(limit);
    Funk(limit);


    return 0;
}

