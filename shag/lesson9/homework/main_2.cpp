#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector> 
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;






int main() {

    srand(time(NULL));
    

    vector<string> firstNames;
    string firstNl;

    for(int i = 0;i < 5;i++)
    {
        cout<<"Введите фамилию №"<<i+1<<": ";
        cin>>firstNl;
        firstNames.push_back(firstNl);
    }


    
    sort(firstNames.begin(),firstNames.end());




    for(string f: firstNames)
    {
        cout<<f<<" ";
    }
    cout<<endl;

    return 0;
}







