#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
    cout<<"Масив"<<endl;    


    //1
    // const int size = 4;
    // int array[size] = {4,2,8};

    // for(short i = 0; i<size;i++)
    // {
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;


    //2
    // int array2[size]{4,2,8};
    // for(int i:array2) cout<<i<<" ";
    // cout<<endl;

    //3
    // float ar[]{1.2,2.8,3.6,1.1,0};
    // for(float i:ar) cout<<i<<" ";
    // cout<<endl<<sizeof(ar)/sizeof(ar[0])<<endl;


    //4
    // float ar[]{1.2,2.8,3.6,1.1,0};
    // cout<<ar[4]<<endl;



    //Задание1
    // srand(time(NULL));

    // const int size = 10;
    // int array[size];

    // for(int i = 0; i<size;i++)
    // {
    //     array[i] = -10 + rand() % (10 + 10 + 1);
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;

    // int min_n = 11;
    // int max_n = -11;

    // for(int i = 0; i<size;i++)
    // {
    //     if(array[i]>max_n)
    //     {
    //         max_n = array[i];
    //     }else if (array[i] < min_n)
    //     {
    //         min_n = array[i];
    //     }
        
    // }

    // cout<<"min: "<<min_n<<"\n"<<"max: "<<max_n<<endl;


    // for(int i = 0; i<size;i++)
    // {
    //     (array[i]<0)?cout<<array[i]<<" ":cout<<"";
    // }
    // cout<<endl;

    // for(int i = 0; i<size;i++)
    // {
    //     (array[i]>=0)?cout<<array[i]<<" ":cout<<"";
    // }
    // cout<<endl;




    //Задание2
    // srand(time(NULL));
    // const int days = 16;
    // int min_temp = -20;
    // int max_temp = 5;
    // int sum_temp=0;
    // int user_min_temp = 6;
    // int col_raz = 0;

    // int array_temp[days];
    // for(int i = 0;i<days;i++)
    // {
    //     array_temp[i] = min_temp + rand() % (max_temp - min_temp + 1);
    //     cout<<array_temp[i]<<" ";
    //     sum_temp+=array_temp[i];
    // }
    // cout<<endl;

    // cout<<"Средняя температура за месяц: "<<sum_temp/days<<endl;

    // cout<<"Введите температуру от 4 до -20: ";
    // cin>>user_min_temp;

    // for(int i = 0;i<days;i++)
    // {
    //     if(array_temp[i]<user_min_temp)
    //     {
    //         col_raz++;
    //     }
    // }

    // cout<< col_raz<<" температура привысила заданый результат"<<endl;



    //Задание3
    // srand(time(NULL));
    // const int size = 10;
    // int min = -20;
    // int max = 5;
    // int array[size];
    // for(int i = 0;i<size;i++)
    // {
    //     array[i] = min + rand() % (max - min + 1);
    //     cout<<array[i]<<" ";
    //     // sum_temp+=array_temp[i];
    // }
    // cout<<endl;

    // for(int i = size-1; i>=0;i--)
    // {
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;


    //Задание4
    // const int size = 10;
    // int array[size];

    // for(int i = 0;i<size;i++)
    // {
    //     if(i==0 || i == size-1)
    //     {
    //         array[i] = 1;
    //     }else
    //     {
    //         array[i] = 0;
    //     }

    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;


    //Задание5
    srand(time(NULL));
    const int size = 16;
    int array[size];

    for(int i = 0;i<size;i++)
    {
        array[i] = -20 + rand() % (20 + 20 + 1);
        cout<<array[i]<<" ";
    }
    cout<<endl;

    for(int i = 0;i<size;i++)
    {
        if(array[i]<0)
        {
            cout<<"Первое отрицательное: "<<array[i];
            break;
        }

        
    }
    cout<<endl;

    for(int i = size-1;i>=0;i--)
    {
        if(array[i]>0)
        {
            cout<<"Последнее положительное: "<<array[i];
            break;
        }
        
    }
    cout<<endl;


    return 0;
}