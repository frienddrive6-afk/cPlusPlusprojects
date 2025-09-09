#include <iostream>
#include <vector> 
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

int main() {


    //Тема динамические масивы 

    // vector<short> ar{5,6,2};


    // ar.push_back(10);
    // ar.emplace(ar.begin(),31);
    // ar.insert(ar.end()-1,7);
    // ar.emplace_back(4);

    // // sort(ar.begin(),ar.end());


    // int size = ar.size();

    // for(int i = 0; i < size; i++)
    // {
    //     cout<<ar[i]<<" ";
    // }
    // cout<<endl;


    // ar.erase(ar.begin()+2,ar.end()-1);

    // int current_size = ar.size();


    // for(int i = 0; i < current_size; i++)
    // {
    //     cout<<ar[i]<<" ";
    // }
    // cout<<endl;




    //Задание 1
    // srand(time(NULL));
    // cout<<"Введите длину масива: ";
    // short lesht;
    // cin>>lesht;

    // vector<int> ar(lesht);

    // for(short i = 0; i<lesht; i++)
    // {
    //     ar[i] = rand() % 10;
    // }

    // int max = ar[0],min = ar[0];

    // for(short i = 0; i<lesht; i++)
    // {
    //     cout<<ar[i]<<" ";

    //     if(ar[i]>max)
    //     {
    //         max = ar[i];
    //     }
    //     if(ar[i] < min)
    //     {
    //         min = ar[i];
    //     }
    // }
    // cout<<endl;

    // cout<<"max: "<<max<<" min: "<<min<<endl;




    //Задание 2
    srand(time(NULL));
    short length;
    cout<<"Ведите длину пароля: ";
    cin>>length;

    string row = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:',.<>/?`~ ";
    cout<<row.size()<<endl;

    vector<char> ar;

    for(int i = 0; i < length; i++)
    {
        short index = rand() % row.size();
        ar.push_back(row[index]);
        cout<<ar[i];
    }
    cout<<endl;







    return 0;
}