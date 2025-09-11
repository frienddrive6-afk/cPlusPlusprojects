#include <iostream>
#include <fstream> //работа с .txt файлами
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
    ofstream fileW("text/ex4.txt");
    if (!fileW.is_open()) {
        cout << "Ошибка: не удалось открыть файл ex1_v1.txt" << endl;
        return 1;
    }


    string line_copy = "";

    vector<string> revers;

    while (getline(fileR, line_copy))
    {
        revers.push_back(line_copy);
    }

    int last_line_without_space_index = -1; 
    
    for (int i = 0; i < revers.size(); i++)
    {
        if (revers[i].find(' ') == string::npos)  //npos цпециальное значение которое возвращает find() если символ не обнаружен https:https://codelessons.dev/ru/string-npos-in-cplusplus/#:~:text=std%3A%3Astring%3A%3Anpos%20%E2%80%94%20%D1%8D%D1%82%D0%BE%20%D1%81%D1%82%D0%B0%D1%82%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B0%D1%8F%20%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D0%B0%D0%BD%D1%82%D0%B0%20%D0%BA%D0%BB%D0%B0%D1%81%D1%81%D0%B0%20std%3A%3Astring%2C%20%D0%BF%D1%80%D0%B5%D0%B4%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D1%8F%D1%8E%D1%89%D0%B0%D1%8F%20%D0%BC%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%B0%D0%BB%D1%8C%D0%BD%D0%BE%20%D0%B2%D0%BE%D0%B7%D0%BC%D0%BE%D0%B6%D0%BD%D0%BE%D0%B5%20%D0%B7%D0%BD%D0%B0%D1%87%D0%B5%D0%BD%D0%B8%D0%B5%20%D0%B4%D0%BB%D1%8F%20%D1%82%D0%B8%D0%BF%D0%B0%20size_t.%20%D0%AD%D1%82%D0%B0%20%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D0%B0%D0%BD%D1%82%D0%B0%20%D1%87%D0%B0%D1%81%D1%82%D0%BE%20%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B5%D1%82%D1%81%D1%8F%20%D0%B4%D0%BB%D1%8F%20%D0%B8%D0%BD%D0%B4%D0%B8%D0%BA%D0%B0%D1%86%D0%B8%D0%B8%20%D0%BE%D1%82%D1%81%D1%83%D1%82%D1%81%D1%82%D0%B2%D0%B8%D1%8F%20%D0%BF%D0%BE%D0%B7%D0%B8%D1%86%D0%B8%D0%B8%20%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB%D0%B0%20%D0%B8%D0%BB%D0%B8%20%D0%BF%D0%BE%D0%B4%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8%20%D0%B2%20%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B5.//codelessons.dev/ru/string-npos-in-cplusplus/#:~:text=std%3A%3Astring%3A%3Anpos%20%E2%80%94%20%D1%8D%D1%82%D0%BE%20%D1%81%D1%82%D0%B0%D1%82%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B0%D1%8F%20%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D0%B0%D0%BD%D1%82%D0%B0%20%D0%BA%D0%BB%D0%B0%D1%81%D1%81%D0%B0%20std%3A%3Astring%2C%20%D0%BF%D1%80%D0%B5%D0%B4%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D1%8F%D1%8E%D1%89%D0%B0%D1%8F%20%D0%BC%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%B0%D0%BB%D1%8C%D0%BD%D0%BE%20%D0%B2%D0%BE%D0%B7%D0%BC%D0%BE%D0%B6%D0%BD%D0%BE%D0%B5%20%D0%B7%D0%BD%D0%B0%D1%87%D0%B5%D0%BD%D0%B8%D0%B5%20%D0%B4%D0%BB%D1%8F%20%D1%82%D0%B8%D0%BF%D0%B0%20size_t.%20%D0%AD%D1%82%D0%B0%20%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D0%B0%D0%BD%D1%82%D0%B0%20%D1%87%D0%B0%D1%81%D1%82%D0%BE%20%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B5%D1%82%D1%81%D1%8F%20%D0%B4%D0%BB%D1%8F%20%D0%B8%D0%BD%D0%B4%D0%B8%D0%BA%D0%B0%D1%86%D0%B8%D0%B8%20%D0%BE%D1%82%D1%81%D1%83%D1%82%D1%81%D1%82%D0%B2%D0%B8%D1%8F%20%D0%BF%D0%BE%D0%B7%D0%B8%D1%86%D0%B8%D0%B8%20%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB%D0%B0%20%D0%B8%D0%BB%D0%B8%20%D0%BF%D0%BE%D0%B4%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8%20%D0%B2%20%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B5.
        {
            // cout<<revers[i].find(' ')<<endl;
            last_line_without_space_index = i;
        }
    }

    for (int i = 0; i < revers.size(); i++)
    {
        fileW << revers[i] << endl;

        if (i == last_line_without_space_index)
        {
            fileW << "------------" << endl;
        }
    }

    if (last_line_without_space_index == -1)
    {
        fileW << "------------" << endl;
    }
    

    fileR.close();
    fileW.close();

    
    return 0;
}