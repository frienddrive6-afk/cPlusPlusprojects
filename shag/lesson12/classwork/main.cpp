#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

//Задание 1
// enum Items
// {
//     hp,
//     fire,
//     arrow,
//     size
// };

// int Sum(int* arr)
// {
//     int s = 0;
//     for(int i = 0;i<Items::size;i++)
//     {
//         s+=arr[i];
//     }

//     return s;
// }



//Задание 2
// void masiv(int *&array,int& size)
// {
//     int dodav = 0;
//     for(int i = 0;i < size;i++)
//     {
//         if(array[i] > 0)
//         {
//             dodav++;
//         }
//     }

//     int* dinamik = new int[dodav];
//     int index = 0;

//     for(int i = 0;i < size;i++)
//     {
//         if(array[i] > 0)
//         {
//             dinamik[index++] = array[i];
//         }
//     }

//     delete[] array;

//     array = dinamik;

//     size = dodav;

// }



//Задание 3

int lenghts(string str1)
{
    return str1.size();
}


string konkat(string str1,string str2)
{
    return str1 + str2;
}

int search(string str)
{
    char symb;
    cout<<"Введите символ какой мы ищем: ";
    cin>>symb;

    int founded = str.find(symb);

    return founded;
}

int main() {

    srand(time(NULL));

    //Задание 1
    // int arr[Items::size] = {3,6,12};

    // cout<<Sum(arr)<<endl;



    //Задание 2

    // int size;

    // cout<<"Введите размер масива: ";
    // cin>>size;

    // int* array = new int[size];
    // for(int i = 0;i < size;i++)
    // {
    //     *(array + i) = -15 + rand() % (20 + 15 + 1);
    //     cout<<*(array + i)<<" ";
    // }
    // cout<<endl;

    // masiv(array,size);

    // for(int i = 0;i < size;i++)
    // {
    //     cout<<*(array + i)<<" ";
    // }
    // cout<<endl;


    // delete[] array;




    //Задание 3

    string str1,str2;

    cout<<"ряд 1: ";
    getline(cin,str1);

    cout<<"ряд 2: ";
    getline(cin,str2);

    string konttt = konkat(str1,str2);

    cout<<"Длинна рядка1: "<<lenghts(str1)<<endl;
    cout<<"Длинна рядка2: "<<lenghts(str2)<<endl;


    cout<<"Конкатетированые строчки -----  "<<konttt<<endl;

    int found_svb = search(konttt);

    if(found_svb == -1)
    {
        cout<<"такого символа нет"<<endl;
    }else
    {
        cout<<"Символ какой мы икали под таким - " <<found_svb<<" интексом"<<endl;
    }


    return 0;
}