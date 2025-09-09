#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    

    const int size = 6;
    int prubytok = 0;
    int sum_pr = 0;
    int array[size];
    

    for(int i =0;i<size;i++)
    {
        cout<<"Введите зароботок за месяц: ";
        cin>>prubytok;

        array[i] = prubytok;
        sum_pr+=prubytok;
    }

    cout<<"Общая прибыль за 6 месяцев: "<<sum_pr<<endl;



    return 0;
}