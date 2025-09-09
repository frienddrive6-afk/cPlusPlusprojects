#include <iostream>
#include <unistd.h> //задежка
// #include<cmath>
#include <iomanip>

using namespace std;


int main() {
    
    // srand(time(NULL));
    // cout<<"Библиотеки: "<<endl;


    // int num = -10 + rand() % (10 + 10 + 1);
    // int num2 = -10 + rand() % 21;  
    // cout<<num<<endl;
    // sleep(1);

    // cout<<rand()%10<<endl;

    // cout<<setfill('-')<<setw(10)<<num2<<endl;
    // cout<<'|'<<left<<setw(10)<<num2<<endl;
    // cout<<'|'<<right<<setw(10)<<num2<<endl;




    //инкремент
    // int x = 5;
    // int y = x++;
    // cout<<x<<" "<<y<<endl;
    // int z = ++x;
    // cout<<x<<" "<<z<<endl;


    //дикримент
    // int x = 5;
    // int y = x--;
    // cout<<x<<" "<<y<<endl;
    // int z = --x;
    // cout<<x<<" "<<z<<endl;






    //for
    // for(int i = 1;i<10;i+=2)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // for(int i = 10; i>0;i--)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;






    //while
    // int x = 5;
    // while (x==5)
    // {
    //     cout<<x<<" ";
    //     x++;
    // }
    // cout<<endl;





    // do
    // {
    //     cout<<x<<" ";
    //     x++;
    // } while (x==5);
    // cout<<endl;










    //Задание 1
    // int star_d;
    // int end_d;

    // int sum_d = 0;

    // cout<<"Введите начало и конеч диапазона: ";
    // cin>>star_d>>end_d;

    // for (int i = star_d;i<=end_d;i++)
    // {
    //     sum_d+=i;
    //     cout<<sum_d<<endl;
    // }

    // cout<<"Ваш резульат: "<<sum_d<<endl;






    //Задание 2
    // int num = 1;
    // int sum_d = 0;
    // cout<<"Вводите числа и мы покажем их суму '0' стоп число: ";

    // // do
    // // {
    // //     cin>>num;
    // //     sum_d+=num;
    // // } while (num!=0);

    // while (num != 0)
    // {
    //     cin>>num;
    //     sum_d+=num;
    // }
    
    
    // cout<<"Ваш результат: "<<sum_d<<endl;
    




    //Задание 3

    // int num1,num2,numIn=0;

    // while (true)
    // {
    //     cout<<"Введите диапазаон: ";
    //     cin>>num1>>num2;

    //     cout<<"Введите число в диапазоне: ";
    //     cin>>numIn;

    //     if(numIn<=num2 && numIn>=num1)
    //     {
    //         cout<<"Поздравляю!"<<endl;
    //         break;
    //     }else
    //     {
    //         cout<<"Попробуйте ещё раз :("<<endl;
    //     }
    // }





    //Задание 4
    // int max_num = 0,min_num=0,sum_nubs = 0;
    // int corrent_num = 1;


    // cout<<"Начинайте вводить числа 0 это стоп: "<<endl;

    // while(corrent_num != 0)
    // {
    //     cout<<"Введите число: ";
    //     cin>>corrent_num;

    //     if(corrent_num == 0)
    //     {
    //         break;
    //     }

    //     if(corrent_num>max_num)
    //     {
    //         max_num = corrent_num;
    //     }

    //     if(corrent_num<min_num)
    //     {
    //         min_num = corrent_num;
    //     }

    //     sum_nubs+=corrent_num;
    // }

    // cout<<"sum: "<<sum_nubs<<" max: " <<max_num <<" min: "<<min_num<<endl;





    //Задание 5
    // int num;
    // cout<<"input numb: ";
    // cin>>num;

    // while (num>0)
    // {
    //     cout<<num%10;
    //     num/=10;
    // }
    // cout<<endl;


    
    //Задание 6
    // int num,max_num = 0,min_num = 9,current_num;
    // cout<<"input numb: ";
    // cin>>num;

    // while (num>0)
    // {
    //     current_num = num%10;
    //     num/=10;

    //     if(current_num>max_num)
    //     {
    //         max_num = current_num;
    //     }
    //     if(current_num<min_num)
    //     {
    //         min_num = current_num;
    //     }
    // }

    // cout<<"Min: "<<min_num<<" Max: "<<max_num<<endl;




    //Задание 6

    srand(time(NULL));

    int min_val = -15; 
    int max_val = 15;  

    

    int col,parnOrNeparn;

    cout<<"Парное или не парное число вы хотите вывести из диапазона?: \n1)да/2)Нет:";
    cin>>parnOrNeparn;

    cout<<"Введите количество числе какое надо вывести: ";
    cin>>col;

    if (parnOrNeparn != 1 && parnOrNeparn != 2) {
        cout << "Некорректный выбор. Пожалуйста, введите 1 или 2." << endl;
        return 1;
    }

    for(int i = 0; i<col; ++i)
    {
        int generatedNum;
        bool find = false;

        while (find == false)
        {
            generatedNum = min_val + rand() % (max_val - min_val + 1);

            if(parnOrNeparn == 1)
            {
                if(generatedNum % 2 == 0)
                {
                    find = true;
                }
            }else
            {
                if(generatedNum % 2 != 0)
                {
                    find = true;
                }
            }
        }
        cout << generatedNum << " ";
        
    }
    cout << endl;


    return 0;
}