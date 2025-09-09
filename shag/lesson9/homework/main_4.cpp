#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;



string Analiz(string str)
{
    vector<string> words;
    string word;

    for(int i = 0;i < str.size(); i++)
    {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            words.push_back(word);
            word.clear();
        }else
        {
            word.push_back(str[i]);
        }
    }
    words.push_back(word);
    word.clear();

    int max_lenght = words[0].size();
    string max_str = words[0];
    for(string stroka : words)
    {
        if(stroka.size() > max_lenght)
        {
            max_lenght = stroka.size();
            max_str = stroka;
        }
    }

    return max_str;
}




int main() {

    srand(time(NULL));
    
    string str,max_str;

    cout<<"Введите вашу строку: ";
    getline(cin,str);

    max_str = Analiz(str);

    cout<<"Самое длинное слова из вамми веденных это \""<<max_str<<"\" и его дина -> "<<max_str.size()<<endl;
    




    return 0;
}







