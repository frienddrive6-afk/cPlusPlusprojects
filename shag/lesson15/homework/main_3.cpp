#include <iostream>
#include <fstream>//работа с .txt файлами
#include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>


using namespace std;



int main() {

    
    ifstream fileR("text/ex1_v1.txt");
    if (!fileR.is_open()) {
        cout << "Ошибка: не удалось открыть файл ex1_v1.txt" << endl;
        return 1;
    }

    ofstream fileW("text/ex3.txt");
    if (!fileW.is_open()) {
        cout << "Ошибка: не удалось открыть файл ex1_v1.txt" << endl;
        return 1;
    }

    string line_copy = "";

    vector<string> revers;

    while (getline(fileR,line_copy))
    {
        // fileW<<line_copy<<endl;
        revers.insert(revers.begin(),line_copy);
    }

    for(int i = 0;i < revers.size();i++)
    {
        fileW<<revers[i]<<endl;
    }
    

    fileR.close();
    fileW.close();

    
    return 0;
}