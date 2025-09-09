#include <iostream>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    
     srand(time(NULL));
     int res = -1;
     int yes = 0,no = 0;

     for(int i = 0;i<9;i++)
     {
        res = 0 + rand() % (1 - 0 + 1);

        if(res == 1)
        {
            yes++;
        }else if(res == 0)
        {
            no++;
        }
     }

     cout<<"За 'ДА' было проголосовано -> "<<yes<<" раз а за 'НЕТ' "<<no<<" раз"<<endl;

     if(yes>no)
     {
        cout<<"Решение принято надо действовать!"<<endl;
     }else
     {
        cout<<"Так вышло что лучше этого не делать :("<<endl;
     }
    
    





    return 0;
}