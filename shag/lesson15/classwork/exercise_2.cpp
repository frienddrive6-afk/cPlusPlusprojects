#include <iostream>
#include <fstream>//работа с .txt файлами
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>


using namespace std;



int main() {
    srand(time(NULL));

    cout<<"Файлы"<<endl;


    cout<<"Что именно надо сделать с файлам:\n1)почитать\n2)Записать\n3)Дозаписать\nВаш выбор: ";
    int choise;
    cin>>choise;
    cin.ignore();


    string line = "";


    if(choise == 2)
    {
        //запись файла
        ofstream fileW("/home/nomantb/c++ trening/shag/lesson15/classwork/txt_felese/file.txt");
        if(!fileW.is_open())
        {
            cout<<"Система не нашла файл"<<endl;
            return 1;
        }

        cout<<"Введите * для окончания: ";
    
        
        do
        {
            getline(cin,line);
            if(line == "*")
            {
                break;
            }

            fileW<<line<<endl;
        } while (line != "*");

        fileW.close();
        
    }else if(choise == 1)
    {
        //чтение файла

        ifstream fileR("/home/nomantb/c++ trening/shag/lesson15/classwork/txt_felese/file.txt");

        if(!fileR)
        {
            cout<<"Система не нашла файл"<<endl;
            return 1;
        }

        cout<<"Выводим информацию с файла"<<endl;

        while (getline(fileR,line))
        {
            cout<<line<<endl;
        }
        


        fileR.close();
    }else if(choise == 3)
    {
        //Дозапись файла
        ofstream fileA("/home/nomantb/c++ trening/shag/lesson15/classwork/txt_felese/file.txt",ios::app);

        if(!fileA.is_open())
        {
            cout<<"Система не нашла файл"<<endl;
            return 1;
        }

        while (true)
        {
            getline(cin,line);

            if(line == "*")
            {
                break;
            }

            
            fileA<<line<<endl;
        }

        fileA.close();
        
    }

    
    




    return 0;
}