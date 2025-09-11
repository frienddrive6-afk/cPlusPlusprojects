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
    ofstream fileW("text/ex2.txt");

    string line_copy = "";

    while (getline(fileR,line_copy))
    {
        fileW<<line_copy<<endl;
    }
    

    fileR.close();
    fileW.close();


    return 0;
}