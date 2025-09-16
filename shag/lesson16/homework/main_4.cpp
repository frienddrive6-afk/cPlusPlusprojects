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


void replaceAll(string& source, const string& from, const string& to) {
    int start_pos = 0;
    while ((start_pos = source.find(from, start_pos)) != string::npos) {
        source.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
}

int main() {
    string file_path = "./txt/file1.txt";

    vector<string> lines;
    ifstream fileR(file_path);
    if (!fileR.is_open()) {
        return 1;
    }
    string line;
    while (getline(fileR, line)) {
        lines.push_back(line);
    }
    fileR.close();

    string word_to_find, next_word;
    cout << "Word: ";
    cin >> word_to_find;
    cout << "Next: ";
    cin >> next_word;

    for (string& current_line : lines) {
        replaceAll(current_line, word_to_find, next_word);
    }

    ofstream fileW(file_path);
    if (!fileW.is_open()) {
        return 1;
    }

    for (const string& l : lines) {
        fileW << l << endl; 
    }
    fileW.close();

    return 0;
}