#include <iostream>
#include <fstream>
// #include<string>
// #include <cstring> 
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

#include "file_filter.h"

using namespace std;


void readBlackList(string& file_path, vector<string> &words)
{
    ifstream fileR(file_path);
    if(!fileR.is_open())
    {
        cout<<"Файл не удалось открыть"<<endl;
        return;
    }

    string word;

    while (fileR>>word)
    {
        words.push_back(word);
    }
    
    fileR.close();
}

vector<string> inputWordsFromLine(string line)
{
    vector<string> words;
    string word;

    for(char ch: line)
    {
        if(ch != ' ')
        {
            word.push_back(ch);
        }
        else
        {
            if (!word.empty()) {
                words.push_back(word);
            }
            word.clear();
        }
    }
    
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}


void redacktCopyFile(string& file_path, vector<string> &words, string& new_file_path)
{

    string line; 
    ifstream fileR(file_path);
    if(!fileR.is_open())
    {
        cout<<"Файл не удалось открыть"<<endl;
        return;
    }

    ofstream fileW(new_file_path);
    if(!fileW.is_open())
    {
        cout<<"Файл не удалось создать"<<endl;
        fileR.close();
        return;
    }

    bool is_not_bad_word; 

    while (getline(fileR, line))
    {
        vector<string> lineWords = inputWordsFromLine(line);

        for(string w: lineWords)
        {
            is_not_bad_word = true;
            for(string bw : words)
            {

                if(bw == w)
                {
                    is_not_bad_word = false;
                    break; 
                }
            }

            if(is_not_bad_word == true)
            {
                fileW << w << " "; 
            }
            else
            {
                fileW << "* ";
            }
        }
        
        fileW << endl;
    }
    
    fileW.close();
    fileR.close();
}



int file_filter() {
    srand(time(NULL));
    string file_path = "./black_list_words.txt";
    string new_file_path = "./file_filter_new.txt";
    string file_for_read = "./file.txt";

    vector<string> words;

    readBlackList(file_path, words);

    redacktCopyFile(file_for_read, words, new_file_path);

    return 0;
}