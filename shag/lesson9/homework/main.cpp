#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


bool Check(string str)
{
    vector<string> parts;
    string prob;
    for(int i = 0;i < str.size();i++)
    {
        if(str[i] != '.')
        {
            prob.push_back(str[i]);
        }else
        {
            // int prob_int = int(prob);
            parts.push_back(prob);
            prob.clear();

        }
    }
    parts.push_back(prob);

    if(parts.size() < 4)
    {
        return false;
    }

    for(int i = 0;i < parts.size();i++)
    {
        if(parts[i].empty())
        {
            return false;
        }

        if(parts[i].size() > 3)
        {
            return false;
        }

        if(parts[i].size() > 1 && parts[i][0] == '0')
        {
            return false;
        }

        int numb = 0;
        for(int j = 0;j < parts[i].size();j++)
        {
            numb = numb * 10 + (parts[i][j] - '0');
            //Работает по принцибу таблици ASCII зная что '0' по таблице это 48 элемент то какое число мы можем узнать отняв ноль от него на пиример '2'-'0' = 50 - 48 = 2 тольуо уже int а не char
        }

        if(numb > 255 || numb < 0)
        {
            return false;
        }

    }

    return true;
}



int main() {

    srand(time(NULL));
    

    string ip_adres;

    cout<<"Введите коректный айпи адрес: ";
    cin>>ip_adres;


    if(Check(ip_adres))
    {
        cout<<"Айпи адрес коректный"<<endl;
    }else
    {
        cout<<"Айпи адрес НЕ коректный"<<endl;
    }






    return 0;
}







