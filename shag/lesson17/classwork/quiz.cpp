#include <iostream>
#include <fstream>
#include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

#include "header.h"

using namespace std;





int ques() {
    cout<<"Ваш выбор - Викторина\n\n";

    ifstream fileR("./test.txt");
    if(!fileR.is_open())
    {
        cout<<"Файл не удалось открыть"<<endl;
    }

    string lens;
    int nomer = 1;
    int count = 0;
    while (getline(fileR,lens))
    {
        cout<<"\nВопрос#" <<nomer++<<endl;
        cout<<lens<<endl;
        for(int i = 1; i < 4;i++)
        {
            getline(fileR,lens);
            cout<<i<<")"<<lens<<endl;;
        }

        string vid = "";
        cout<<"Ввидите ответ: ";
        cin>>vid;
        fileR>>lens;
        fileR.ignore();
        if(lens == vid)
        {
            cout<<"Правильный ответ";
            count++;
        }


        // cout<<"Правильный ответ -> "<< lens<<endl;

    }
    cout<<"Из 5 вопросов правильно вы ответили на "<< count<<endl;
    


    cout<<"Меню [1] | выход[2] ->";

    int choice;
    cin>>choice;
    int res = 0;

    switch (choice)
    {
    case 1:
    {
        res=main();
        break;
    }
    case 2:
    {
        exit;
        break;
    }
    

    }



    
    return 0;
}