#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;






int main() {

    srand(time(NULL));
    
    string lines;
    char sumvol;

    cout<<"Введите строчку: ";
    getline(cin,lines);
    
    cout<<"Введите символ: ";
    cin>>sumvol;

    int vstrech = 0;
    for(int i = 0;i < lines.size();i++)
    {
        if(lines[i] == sumvol)
        {
            vstrech++;
        }
    }
    
    cout<<"Ваш символ встречается в тексте "<<vstrech <<" раз"<<endl;




    return 0;
}







