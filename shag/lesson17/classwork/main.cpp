#include <iostream>
// #include <fstream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

#include "quiz.h"
#include "phone_book.h"
#include "Co_workers.h"

using namespace std;





int main() {
    srand(time(NULL));

    cout<<"Распределение проэкта по частям!\n\n";



    cout<<"Меню проектов\n1)Викторина\n2)Телефонная книга\n3)Сотрудник\nВаш выбор: ";
    short choice;
    cin >> choice;
    int res;

    switch (choice)
    {
    case 1 :
    {
        system("clear");
        res = ques();
        break;
    }
    case 2 :
    {
        system("clear");
        res = book();
        break;
    }
    case 3 :
    {
        break;
    }
    default:
    {
        cout<<"Нету такого проектf"<<endl;
    }
    
    }





    return 0;
}