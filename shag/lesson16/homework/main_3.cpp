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

    string word = "";

    cout<<"Word: ";
    cin>>word;

    string woooord;
    int count = 0;
    while (fileR>>woooord)
    {
        if( woooord == word)
        {
            count++;
        }
    }
    
    cout<<"введеное вами слово было найдено " <<count<<" раз"<<endl;

    fileR.close();
    return 0;
}