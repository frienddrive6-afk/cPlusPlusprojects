#include <iostream>
#include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;



const int week = 7;


//Используется в материале 1
void Count()
{
    static int k = 0;
    k++;
    cout<<k<<endl;
}


//Используется в задании 1
void Sravn(int numb);







//Используется в задании 2 

long max_element(int n, int array[])  { 

    int value = array[0];  

    for (int i = 1; i < n; i++)  

    value = value > array [i] ? value : array [i];  

    cout << "\nFor (int) : ";  

    return long(value);  
}  
long max_element(int n, long array[]) {  

    long value = array[0];  

    for (int i = 1; i < n; i++)  

    value = value > array[i] ? value : array[i];  

    cout << "\nFor (long) :";  

    return value;  
}  
double max_element(int n, float array[]) {  

    float value = array[0];  

    for (int i = 1; i < n; i++)  

    value = value > array[i] ? value :array[i];  

    cout << "\nFor (float) : ";  

    return double(value);  
} 


double max_element(int n, double array[]) { 

    double value = array[0];  

    for (int i = 1; i < n; i++)  

    value = value > array[i] ? value : array[i];  

    cout << "\nFor (double) : "; 

    return value;  
} 






//Используется в задании 3
int numSum(int k,...)
{
    int s = 0;

    va_list array;

    va_start(array,k);

    for (int i = 0; i < k; ++i) 
    {
        s += va_arg(array, int);
    }

    va_end(array);

    return s;
}






//Используется в задании 4
int Min_array(int k,...);





//Используется в задании 5
int Fact(int n);



//Используется в задании 6
int Dobut(int a,int b);



//Используется в задании 7
template <typename N1,typename N2>
N2 maxN(N1 x,N2 y)
{
    return (x > y) ? x:y;
}



//Используется в задании 8
// template<typename N1,typename N2>
// N1 Ser_ar(N1 size,N2 array)
// {
//     N2 sum = 0;

//     for(int i = 0;i < size;i++)
//     {
//         sum += array[i];
//     }

//     return sum/size;
// }

template<typename N1, typename N2>
double Ser_ar(N1 size, N2 array)
{
    double sum = 0.0;

    for(int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum / size;
}




int main() {

    srand(time(NULL));
    

    //Материал 1
    // for(int i = 0; i < 3;i++)
    // {
    //     Count();
    // }



    //Задание 1
    // for(int i = 0;i < 5;i++)
    // {
    //     int numb;
    //     cout<<"Введите число: ";
    //     cin>>numb;

    //     Sravn(numb);
    // }
    



    //Задание 2
    // int x[] = { 10, 20, 30, 40, 50, 60 };  

    // long f[] = { 12L, 44L, 5L, 22L, 37L, 30L };  

    // float y[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };  

    // double z[] = { 0.01, 0.02, 0.03, 0.04, 0.05, 0.06};  

    // cout << "\nmax_elem(6,x) = " << max_element(6,x);  

    // cout << "\nmax_elem(6,f) = " << max_element(6,f);  

    // cout << "\nmax_elem(6,y) = " << max_element(6,y);  

    // cout << "\nmax elem(6,z) = " << max_element(6,z);
    // cout<<endl;
    



    //Задание 3
    // cout<<numSum(3,1,2,3)<<endl;
    // cout<<numSum(7,1,2,3,4,5,6,7)<<endl;





    //Задание 4
    // cout<<Min_array(3,-1,5,3)<<endl;






    //Задание 5
    // int n;
    // cout<<"Введите число: ";
    // cin>>n;

    // cout<<Fact(3)<<endl;
    // cout<<Fact(n)<<endl;




    //Задание 6
    // cout<<Dobut(1,5)<<endl;




    //Задание 7
    // cout<<maxN(12,22)<<endl;
    // cout<<maxN(1.85,5.12)<<endl;
    // cout<<maxN('a','A')<<endl;




    //Задание 8
    int array[3] = {1,2,3};
    float array2[4] = {1.23,6.87,3.29,23.45};

    cout<<Ser_ar(3,array)<<endl;
    cout<<Ser_ar(4,array2)<<endl;


    return 0;
}






void Sravn(int numb)
{
    static int num = 0;
    if(numb > num)
    {
        cout<<"Чило что вы ввели больше прошлого"<<endl;
    }else if(numb < num)
    {
        cout<<"Число что вы ввели меньше того что было"<<endl;
    }else
    {
        cout<<"Число что вы ввели совпадает с прошедшим"<<endl;
    }
    num = numb;
}




//Используется в задании 4

//V1
// int Min_array(int k,...)
// {
//     int min = 0;

//     va_list array;

//     va_start(array,k);

//     for (int i = 0; i < k; ++i) 
//     {
//         int current_num = va_arg(array, int);
        
//         if (current_num < min)
//         {
//             min = current_num;
//         }
//     }

//     va_end(array);

//     return min;
// }

//V2
int Min_array(int k,...)
{
    int min;

    va_list array;

    va_start(array,k);

    min = va_arg(array,int);
    int n2 = 0;

    for (int i = 0; i < k; ++i) 
    {
        n2 = va_arg(array,int);
        if (min > n2)
        {
            min = n2;
        }
    }

    va_end(array);

    return min;
}




//Используется в задании 5
int Fact(int n)
{

    if(n < 1)
    {
        return 1;
    }else
    {
        return n*Fact(n-1);
    }

}



//Используется в задании 6
int Dobut(int a,int b)
{
    if(a > b)
    {
        return 0;
    }else
    {
        return a + Dobut(a+1,b);
    }

}