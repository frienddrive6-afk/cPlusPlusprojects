#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;



string Zamena_Word(string str,string w1,string w2)
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


    for(int i = 0;i < words.size();i++)
    {
        if(words[i] == w1)
        {
            words[i] = w2;
        }
    }

    word.clear();

    for(int i = 0;i < words.size();i++)
    {
        word += words[i];
        word+=" ";
    }

    return word;
}





int main() {

    srand(time(NULL));
    
    string str,zamenaemoe_str,zamena_str;

    cout<<"Введите вашу строку: ";
    getline(cin,str);

    cout<<"Введите слово какое надо заменить: ";
    cin>>zamenaemoe_str;

    cout<<"Введите на какое слово нужно заменить: ";
    cin>>zamena_str;
    
    string res;
    res = Zamena_Word(str,zamenaemoe_str,zamena_str);

    cout<<"Вот ваше предложение с замененным словом \n\""<<res<<"\""<<endl;

    return 0;
}







