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
    ofstream fileW("./txt/file2.txt");
    if (!fileW.is_open()) {
        return 1;
    }

    string previous_line;
    string current_line;

    if (getline(fileR, previous_line)) {
        
        while (getline(fileR, current_line)) {
            fileW << previous_line << endl;
            
            previous_line = current_line;
        }
    }


    fileW.close();
    fileR.close();

    cout << "Копіювання завершено." << endl;

    return 0;
}