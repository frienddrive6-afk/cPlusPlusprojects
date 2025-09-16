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


#define G "\033[32m"
#define C "\033[36m"
#define R "\033[0m"

using namespace std;



void countWords(const string &name)
{
    ifstream fileR(name);
    if(!fileR.is_open())
    {
        cout<<"Файл не найден"<<endl;
        return;
    }
    string full_text;
    vector<string> words;


    cout<<"Введите символ какой будем искать: ";
    char simvol;
    cin>>simvol;
    simvol = toupper(simvol);

    int count = 0;
    while (fileR>>full_text)
    {
        char first = toupper(full_text[0]);
        if(simvol == first)
        {
            words.push_back(full_text);
            count++;
        }
    }

    cout<<"Количество найденых слов какие начинаются на указаный вами символ: "<<count<<endl;
    for(string word : words)
    {
        cout<<word<<" ";
    }
    cout<<endl;

    fileR.close();
}


void replace(const string& name)
{
    ifstream fileR(name);
    if(!fileR.is_open())
    {
        cout<<"Файл не найден"<<endl;
        return;
    }

    ofstream fileW("./txt/new_file.txt");
    if(!fileW.is_open())
    {
        cout<<"Файл не создан"<<endl;
        return;
    }

    string line,new_line;


    while (getline(fileR,line))
    {
        new_line = "";
        for(char simvol : line)
        {
            if(simvol == '0')
            {
                new_line.push_back('1');
            }else if (simvol == '1')
            {
                new_line.push_back('0');
            }else
            {
                new_line.push_back(simvol);
            }
        }
        fileW<<new_line<<endl;
    }
    



    fileW.close();
    fileR.close();

    cout<<"перезапись произведена успешно"<<endl;
}


void writeMassiveToFile(const string& name,vector<string>& lines)
{
    ofstream fileW(name);
    if(!fileW.is_open())
    {
        cout<<"ошибка создания файла"<<endl;
        return;
    }

    for(string stroka : lines)
    {
        fileW<<stroka<<endl;
    }


    fileW.close();
}


void countSimvols(const string& name)
{
    ifstream fileR(name);
    if(!fileR.is_open())
    {
        cout<<"Файл не открыт"<<endl;
        return;
    }

    char sim;
    int col_simvols = 0;

    while (fileR.get(sim))
    {
        col_simvols++;
    }
    
    cout<<"Количество символов в тексте равно -> "<<col_simvols<<endl;

    fileR.close();
}


void countLines(const string& name)
{
    ifstream fileR(name);
    if(!fileR.is_open())
    {
        cout<<"Файл не открыт"<<endl;
        return;
    }

    string line;
    int col_lines = 0;

    while (getline(fileR,line))
    {
        col_lines++;
    }
    
    cout<<"Количество строчек в тексте равно -> "<<col_lines<<endl;

    fileR.close();
}

int main() {
    srand(time(NULL));

    


    cout<<G<<"Меню заданий\n1)Счетчик количества слов\n2)Перезапись символов\n3)Запись масива\n4)Количесво символов в файле\n5)Количество строчек\nВаш выбор: "<<R;
    int choice;
    cin>>choice;

    switch (choice)
    {
        case 1:
        {
            countWords("./txt/inform.txt");
            break;
        }
        case 2:
        {
            replace("./txt/inform.txt");
            break;
        }
        case 3:
        {
            vector<string> lines= 
            {
                "sadasdad asdasdasda asdasdasda a asdasdasd asdasd",
                "fsdfsfsfewr werwerwer fssdfsdfe werwe wer sdfsdfsd",
                "dsfdsdfsd erwerwer wqeqwewq fsdfsdf szczxczxc svcxvxcf",
                "werwerwerwer fsdfsdfsdsdasd dfgdfgg ewrwererw sfsdfsdfzxcz",
                "asasdasderwe werwerwer sdfsdfsd cxvxcvxc",
                "Lorem Ipsum - это текст-\"рыба\", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной \"рыбой\" для текстов на латинице с начала XVI века.",
                "Aldus PageMaker, в шаблонах которых используется Lorem Ipsum"
            };

            writeMassiveToFile("./txt/thirst.txt",lines);
            break;
        }
        case 4:
        {
            countSimvols("./txt/inform.txt");

            break;
        }
        case 5:
        {
            countLines("./txt/inform.txt");

            break;
        }
    
    default:
        cout<<"Не правильный путь"<<endl;
        break;
    }



    return 0;
}