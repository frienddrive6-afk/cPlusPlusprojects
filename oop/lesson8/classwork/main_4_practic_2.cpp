#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
#include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>



using namespace std;


class Virus
{
private:
    static int col_viruses;

public:
    Virus()
    {
        col_viruses++;
        cout  << col_viruses << endl;
    }


    ~Virus()
    {
        col_viruses--;
        cout  << col_viruses << endl;
    }


    static int getVirusCount()
    {
        return col_viruses;
    }

};
int Virus::col_viruses{ 0 };


void createVirus()
{
    Virus temp_virus; 
}

int main()
{

    Virus v1;
    Virus v2, v3;

    cout << "Текущее количество вирусов: " << Virus::getVirusCount() << endl;

    createVirus();

    cout << "Текущее количество вирусов: " << Virus::getVirusCount() << endl;

    
    return 0;
}




