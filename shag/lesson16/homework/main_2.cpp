#include <iostream>
#include <fstream>
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
    string file_path = "./txt/file1.txt";

    ifstream fileR(file_path);
    if (!fileR.is_open()) {
        return 1;
    }

    string line;
    int len = 0;
    int index = 0;
    int len_index = -1;

    while (getline(fileR,line))
    {
        index++;
        if(len < line.length())
        {
            len = line.length();
            len_index = index;
        }
    }
    

    cout<<"Самая долгая строчка под номером "<<len_index <<endl;


    fileR.close();
    return 0;
}