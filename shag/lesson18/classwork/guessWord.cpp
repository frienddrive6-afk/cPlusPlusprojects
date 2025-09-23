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
#include <sstream>

#include "header.h"

using namespace std;





int guessWord() {
    srand(time(NULL));

    ifstream fileR("./txt/riddle.txt");
    if(!fileR.is_open())
    {
        cout<<"не удалось открыть файл"<<endl;
        return 1;
    }        
    
    vector<string> arr;
    string line;
    while (getline(fileR,line))
    {
        arr.push_back(line);
    }
    fileR.close();    


    int randRow = rand() % arr.size();

    string arRndRow = arr[randRow];
    // vector<string> resLine = split(arRndRow);
    string resLine = arr[randRow].substr(0,arr[randRow].find('|'));
    string resLineTwo = arr[randRow].substr(arr[randRow].find('|')+1,arr[randRow].size()-1);

    cout<<resLine<<endl;
    cout<<resLineTwo<<endl;

    return 0;
}