#include <iostream>
#include<algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    


    //Задание1
    // const short size = 5;
    // int array[size];

    // for(int i = 0;i < size;++i)
    // {
    //     cout<<"Что в список ложим: ";
    //     cin>>array[i];
    // }


    // short k;

    // cout<<"количество сдвигов: ";
    // cin>>k;


    // for(int x = 0;x < k;++x)
    // {
    //     int temp = array[0];
    //     for(int i = 0;i<size-1;++i)
    //     {
    //         array[i]=array[i+1];
    //     }
    //     array[size-1]= temp;
    // }





    // for(int i = 0;i < size;i++)
    // {
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;





    //Задание2
    // int array[] = {0,5,0,3,0,0,7,8,0,2};
    // int size = sizeof(array)/sizeof(array[0]);
    
    
    // for(int i : array) cout<<i<<" ";
    // cout<<endl;

    // int p = 0;
    // for(int i = 0;i < size;++i)
    // {
    //     if(array[i] != 0)
    //     {
    //         array[p] = array[i];
    //         p++;
    //     }
        
    // }
    // cout<<endl;

    // while (size>p) array[p++] = -1;

    // for(int i = 0;i < size;i++)
    // {
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;








    
    
    //Сортировка масива

    //1 бульбашка
    // srand(time(NULL));
    // const int size = 10;
    // int ar[size];

    // for(int i = 0; i<size;i++)
    // {
    //     ar[i] = rand() % 100;
    //     cout<<ar[i]<<" ";
    // }
    // cout<<"\n\n";

    // for(int i = 0; i<size;i++)
    // {
    //     for(int j = 0; j<size-1;j++)
    //     {
    //         if(ar[j]>ar[j+1])
    //         {
    //             int temp = ar[j];
    //             ar[j] = ar[j + 1];
    //             ar[j+1] = temp;
    //         }
    //     }
    // }

    // for(int i: ar) cout<< i <<" ";
    // cout<<endl;




    //2 выбор
    // srand(time(NULL));
    // const int size = 10;
    // int ar[size];

    // for(int i = 0; i<size;i++)
    // {
    //     ar[i] = rand() % 100;
    //     cout<<ar[i]<<" ";
    // }
    // cout<<"\n\n";



    // for(int i = 0; i<size-1;++i)
    // {
    //     int min = i;
    //     for(int j = i; j<size;++j)
    //     {
    //         if(ar[j]<ar[min])
    //         {
    //             min = j;
    //         }
    //     }
    //     int temp = ar[i];
    //     ar[i] = ar[min];
    //     ar[min] = temp;
    // }



    // for(int i: ar) cout<< i <<" ";
    // cout<<endl;







    //3 вcтавка
    // srand(time(NULL));
    // const int size = 10;
    // int ar[size];

    // for(int i = 0; i < size; i++) {
    //     ar[i] = rand() % 100; 
    //     cout << ar[i] << " ";
    // }
    // cout << "\n\n";

    // for(int i = 1; i < size; ++i) { 
    //     int temp = ar[i];   
    //     int j = i - 1;      


    //     while (j >= 0 && ar[j] > temp) { 
    //         ar[j + 1] = ar[j]; 
    //         j--;              
    //     }
        
    //     ar[j + 1] = temp; 
    // }

    // for(int i : ar) { 
    //     cout << i << " ";
    // }
    // cout << endl;






    //4 переделаная бульбашка
    // srand(time(NULL));
    // const int size = 10;
    // int ar[size];

    // for(int i = 0; i<size;i++)
    // {
    //     ar[i] = rand() % 100;
    //     cout<<ar[i]<<" ";
    // }
    // cout<<"\n\n";

    // for(int i = 0; i<size;i++)
    // {
    //     for(int j = 0; j<size-1;j++)
    //     {
    //         if(ar[j]>ar[j+1])
    //         {
    //             // int temp = ar[j];
    //             // ar[j] = ar[j + 1];
    //             // ar[j+1] = temp;
    //             swap(ar[j],ar[j+1]);
    //         }
    //     }
    // }

    // for(int i: ar) cout<< i <<" ";
    // cout<<endl;








    //5 бинарный поиск
    srand(time(NULL));
    const int size = 10;
    int ar[size];

    for(int i = 0; i<size;i++)
    {
        ar[i] = rand() % 100;
        cout<<ar[i]<<" ";
    }
    cout<<"\n\n";



    for(int i = 0; i<size;i++)
    {
        int temp = ar[i];
        int left = 0,right = i - 1;
        
        while (left <= right)
        {
            int centre = (left+right)/2;
            if(temp<ar[centre])
            {
                right = centre -1;
            }else
            {
                left = centre + 1;
            }
        }


        for(int j = i-1; j>=left;j--)
        {
            ar[j + 1] = ar[j];
        }

        ar[left] = temp;
    }


    





    for(int i: ar) cout<< i <<" ";
    cout<<endl;


    return 0;
}