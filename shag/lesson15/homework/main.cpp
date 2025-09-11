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

    string line = "";
    vector<string> word_list;

    while (getline(fileR,line))
    {
        // cout<<line<<endl;
        
        string one_word = "";

        for(int i = 0; i < line.size();i++)
        {
            char test = line[i];
            
            if(line[i] == ' ' || line[i] == ',' || line[i] == '.' || line[i] == '(' || line[i] == ')')
            {
                if(one_word.size() >= 7)
                {
                    word_list.push_back(one_word);
                    one_word = "";
                }else
                {
                    one_word = "";
                }
                continue;
            }else
            {
                one_word.push_back(line[i]);
            }


        }

    }

    string word = "";

    ofstream fileW("text/ex1_v2.txt");

    for(string word : word_list)
    {
        fileW<<word<<" ";
    }
    


    fileR.close();
    fileW.close();


    return 0;
}