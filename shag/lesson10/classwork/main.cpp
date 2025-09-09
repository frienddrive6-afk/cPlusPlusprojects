#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

void PrintAr(int* mas,int size)
{
    for(int i = 0;i < size;i++)
    {
        cout<<*(mas + i)<<" ";
    }
    cout<<endl;
}



void PrintAr2(int(* mas)[5],int row)
{
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            // cout<<mas[i][j]<<" ";
            cout<<*(*(mas+i) + j)<<" ";
        }
        cout<<endl;
    }
    
}



int LenStr(char* p)
{
    int size = 0;
    while (*p != '\0')
    {
        size++;
        p++;
    }
    return size;
}


int LenStr2(string& p)
{
    int size = 0;
    while (p[++size] != '\0')
    {
        // size++;
        // p++;
    }
    return size;

}


//Задание 1
int WhoIsBigget(int* p1,int* p2)
{
    return (*p1 > *p2) ? *p1:*p2; 
}




//Задание 2

char PlusMinusNull(int *p)
{
    if(*p == 0)
    {
        return '0';
    }else if(*p > 0)
    {
        return '+';
    }else
    {
        return '-';
    }
}


//Задание 3
void Replase(int *p1,int *p2)
{
    int temp = *p1; 
    *p1 = *p2;      
    *p2 = temp; ;

    cout<<*p1<<" "<<*p2<<endl;

}



//Задание 4
void Calcul(int* n1,int* n2,char* dia)
{
    switch (*dia)
    {
        case '+':
            cout << *n1 + *n2 << endl;
            break; 

        case '-':
            cout << *n1 - *n2 << endl;
            break;

        case '*':
            cout << *n1 * *n2 << endl;
            break;

        case '/':
            cout << *n1 / *n2 << endl;
            break;
            
        default:
            cout << "nO UNDERSTUND"<< *dia << endl;
            break;
    }
}


//Задание 5
void Zapovn(vector<int> *ar)
{
    int *p = ar->data();

    for(int i = 0;i < ar->size();i++)
    {
        *(p + i) = rand() % 100;
        cout<<*(p + i)<<" ";
    }
    cout<<endl;
}

void DelParnOrNeparn(vector<int> *ar,int res)
{
    if(res != 1 && res != 2)
    {
        cout<<"Вы выбрали не коректное значение"<<endl;
        return;
    }

    // int *p = ar->data();

    if (res == 1)
    {
        for(int i = 0;i < ar->size();i++)
        {
            if((*ar)[i] % 2 != 0)
            {
                ar->erase(ar->begin()+i);
            }
        }
    }else
    {
        for(int i = 0;i < ar->size();i++)
        {
            if((*ar)[i] % 2 == 0)
            {
                ar->erase(ar->begin()+i);
            }
        }
    }

    for(int i = 0;i < ar->size();i++)
    {
        cout<<(*ar)[i]<<" ";    
    }
    cout<<endl;
    
}





//пример
void fillAr(int *ar,int size = 5)
{
    for(int i = 0;i < size;i++)
    {
        *(ar + i) = rand() % 100;//ar[i]
        cout<<*(ar + i)<<" ";
    }
    cout<<endl;
}


void fillMas(vector<int> *mas)
{
    //V1
    // int *p = mas->data();//mas.data()

    // for(int i = 0;i < mas->size();i++)
    // {
    //     *(p + i) = rand() % 100;//ar[i]
    //     cout<<*(p + i)<<" ";
    // }
    // cout<<endl;

    //V2
    for(int i = 0;i < mas->size();i++)
    {
        (*mas)[i] = rand() % 100;
        cout<<(*mas)[i]<<" ";
    }
    cout<<endl;
}



int main() {

    srand(time(NULL));
    

    // int x= 5;

    // int &y = x; //Ссылка

    // cout<<&x<<endl;
    // y = 10;
    // cout<<y<<endl;
    // int z = 11;

    // int *p = &x; 
    // cout<<p<<endl;
    // cout<<*p<<endl;

    // *p = 15; //указатель(адрес),15(число)
    // cout<<*p<<endl;

    // p = &z;//указатель
    // cout<<p<<endl;




    //Арифметика

    // int a = 5,b = 7, c = 11;

    // int *p1 = &a;
    // int *p2 = &b;
    // int *p3 = &c;


    // cout<<p1<<endl;
    // cout<<++p1<<endl;
    // cout<<p2<<endl;
    // cout<<--p2<<endl;
    // cout<<p3<<endl;

    // cout<<p3-p1<<endl;



    // const int size = 6;
    // int ar[size] = {1,2,3,4,0,1};
    // int size = sizeof(ar)/sizeof(ar[0]);

    // cout<<sizeof(ar)<<endl;

    // for(int i = 0;i < size;i++)
    // {
    //     // cout<<ar[i]<<" ";
    //     cout<<*(ar + i)<<" ";
    // }
    // cout<<endl;


    // int *p1 = ar;
    // int *p2 = &ar[5]; 

    // cout<<p2 - p1 <<endl;

    // PrintAr(ar,size);







    // int ar[3][5] = {0};
    // int(*p)[5] = ar;
    // PrintAr2(p,3);



    // char txt[] = "pointer";
    // cout<<LenStr(txt)<<endl;


    // string txt = "pointer";
    // cout<<LenStr2(txt)<<endl;





    //Задание 1
    // int num1,num2;

    // cout<<"num1: ";
    // cin>>num1;
    // cout<<"num2: ";
    // cin>>num2;

    // cout<<WhoIsBigget(&num1,&num2)<<endl;



    //Задание 2
    // int num;

    // cout<<"num: ";
    // cin>>num;
    // cout<<PlusMinusNull(&num)<<endl;



    //Задание 3
    // int num1,num2;

    // cout<<"num1: ";
    // cin>>num1;
    // cout<<"num2: ";
    // cin>>num2;

    // Replase(&num1,&num2);



    //Задание 4
    // int num1,num2;
    // char dia;

    // cout<<"num1: ";
    // cin>>num1;
    // cout<<"num2: ";
    // cin>>num2;
    // cout<<"dia: ";
    // cin>>dia;

    // Calcul(&num1,&num2,&dia);




    //Задание 5

    int len;
    cout<<"len";
    cin>>len;

    vector<int> ar(len);

    Zapovn(&ar);

    int res_ueser;
    cout<<"Выберете сортировку:\n1)Удаляем не парные\n2)Удаляем парные\nВаш ответ: ";
    cin>>res_ueser;

    DelParnOrNeparn(&ar,res_ueser);




    //пример
    // int ar[5];
    // vector<int> mas(5);


    // fillAr(ar);

    // fillMas(&mas);


    //после урока
    // const int* p1;//указатель на константу,защита данных от изменений (функция)
    // int *const p2;//константный указатель,привязка к конкретной переменной(адреса памяти)
    

    // int a = 2,b = 5;
    // const int* p1;//указатель на константу

    // p1 =  &a;
    // cout<<p1<<endl;
    // // *p1 = 10;//нельзя
    // p1 = &b;
    // cout<<p1<<endl;



    // int a = 2,b = 5;
    // int *const p2 = &a;//константный указатель

    // cout<<p2<<endl;
    // *p2 = 11; 
    // // p2 = &b;//нельзя
    // cout<<*p2<<endl;




    return 0;
}