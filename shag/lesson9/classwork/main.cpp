#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


//Робота на уроке 2
void Check_simvol(char simvol)
{
    if(isalpha(simvol))
    {
        if(isdigit(simvol))
        {
            cout<<"Выввели цифру"<<endl;
        }else if(isspace(simvol))
        {
            cout<<"Вы ввели или пробел или табуляцию или перенос на новыю строку"<<endl;
        }
        else if(islower(simvol))
        {
            cout<<"Вы ввели маленькую букву"<<endl;
        }else if(isupper(simvol))
        {
            cout<<"Вы ввели большую букву"<<endl;
        }else
        {
            cout<<"Вы введи пунктуацию"<<endl;
        }
    }else
    {
        cout<<"В таблице ASCII нет такого символа"<<endl;
    }
}


//Робота на уроке 2
void islowerOnUpper(string str)
{
    string res = "";

    int leght_str = str.size();
    for(int i = 0;i < leght_str;i++)
    {
        if(islower(str[i]))
        {
            res.push_back(toupper(str[i]));
        }else if(isupper(str[i]))
        {
            res.push_back(tolower(str[i]));
        }

        cout<<res[i];
    }
    cout<<endl;
}




//Задание 1
void Rever_FIO(string str)
{
    while (str.empty())
    {
        cout<<"Вы вели пустую строчку"<<endl;
        cout<<"Введите ФИО: ";
        getline(cin, str);
    } 


    //V1
    // for(int i = str.size();i >= 0;i--)
    // {
    //     cout<<str[i];
    // }
    // cout<<endl;

    //V2 с использованием библиотеки algorithm
    reverse(str.begin(),str.end());
}


//Задание 2
void Change(string str, const char mas[], short size)
{
    for(int i = 0; i < str.length(); i++)
    {
        bool found = false;

        for(int j = 0; j < size; j++)
        {
            if(str[i] == mas[j] || toupper(mas[j]) == str[i])
            {
                found = true; 
                break; 
            }
        }

        if(found)
        {
            cout << "*";
        }
        else
        {
            cout << str[i];
        }
    }
    cout << endl;
}




//Задание 3

void Vstavka(string str,int index)
{
    char sumvol;
    cout<<"Введите символ на вставку: ";
    cin>>sumvol;

    str.insert(index,1,sumvol);
    cout<<str<<endl;
}

void removed(string str,int index)
{
    str.erase(index,1);
    cout<<str<<endl;
}


int main() {

    srand(time(NULL));
    

    //Робота на уроке 1
    // char s = 'a';
    // string txt = " qwert";
    // for(int i = 0;i < 10;i++)
    // {
    //     char c = 65 + rand() % (122 - 65 + 1); //V2
    //     // char c = 65 + rand() % 94; //V1
    //     cout<<c<<" ";
    // }
    // cout<<endl;
    // cout<<int(s)<<" "<<int('A')<<endl;



    //Робота на уроке 2
    // char input_user;

    // cout<<"Введите символ: ";
    // cin>>input_user;

    // Check_simvol(input_user);




    //Робота на уроке 3
    // string input_user;
    // cout<<"Введите предложения: ";
    // cin>>input_user;

    // islowerOnUpper(input_user);




    //Теория считывания строчек с пробелами 1
    // string fio;

    // cout<<"Введите ФИО: ";
    // getline(cin,fio);

    // cout<<fio<<endl;
    



    //Теория считывания строчек с пробелами 2
    // char fio[35];
    // int age;
    // cout<<"Age: ";
    // cin>>age;
    // cin.ignore();
    // cout<<"Введите ФИО: ";
    // cin.getline(fio,35);

    // cout<<fio<<endl;








    //Задание 1
    // string fio;

    // cout<<"Введите ФИО: ";
    // getline(cin,fio);

    // cout<<fio<<endl;
    // Rever_FIO(fio);
    




    //Задание 2
    // string str;

    // char mas[] = {'a','q','e','y','u','i'};
    // short len_mas = sizeof(mas)/sizeof(mas[0]);

    // cout<<"Введите предложение: ";
    // getline(cin,str);

    // Change(str,mas,len_mas);



    //Задание 3
    string str;

    cout<<"Введите предложение: ";
    getline(cin,str);

    short dia,index;
    cout<<"Что вы хотите сделать\n1)Вставить\n2)Удалить\nВаш выбор: ";
    cin>>dia;

    cout<<"Введите позицию: ";
    cin>>index;
    index--;

    switch (dia)
    {
    case 1:
        Vstavka(str,index);
        break;

    case 2:
        removed(str,index);
        break;
    
    default:
        cout<<"Такой выбор не известен"<<endl;
        break;
    }

    return 0;
}
