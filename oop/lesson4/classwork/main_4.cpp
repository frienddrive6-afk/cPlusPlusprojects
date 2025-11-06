#include <iostream>
// #include <fstream>
// #include<string>
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


class SmartArray
{
private:
    int size = 10;
    int** array;
    int current_count = 0;

public:

    void zapovnNULL()
    {
        array = new int*[size];
        for (int i = 0; i < size; ++i)
        {
            *(array + i) = nullptr;
        }
        cout << "SmartArray создан" << std::endl;
    }

    void reset()
    {
        for(int i = 0;i < size;++i)
        {
            delete *(array + i);
            *(array + i) = nullptr;
        }
        current_count = 0;
        cout<<"Массивбыл очищен"<<endl;
    }

    bool push(int num)
    {
        if(current_count >= size)
        {
            cout << "Массив полон" <<endl;
            return false;
        }
        
        *(array + current_count) = new int{num};
        current_count++;
        return true;
        
    }

    int pop()
    {
        int return_znach = *(*(array + --current_count));
        
        delete *(array + current_count);
        *(array + current_count) = nullptr;

        return return_znach;
    }

    void print()
    {
        if (current_count == 0) {
            cout << "Массив пуст" <<endl;
            return;
        }

        for(int i = 0;i < current_count;++i)
        {
            if(*(array + i) != nullptr)
            {
                cout<<*(*(array + i))<<" ";
            }
        }
        cout<<endl;
    }

    void delateArray()
    {
        for(int i = 0;i < size;++i)
        {
           delete *(array + i); 
        }

        delete[] array;
    }

};



int main()
{

    SmartArray arr;
    arr.zapovnNULL();

    arr.push(10);
    arr.push(25);
    arr.push(7);
    arr.print();

    int popped_value = arr.pop();
    cout << "Извлеченный элемент: " << popped_value << endl;
    arr.print();

    arr.reset();
    arr.print();
    
    for(int i = 0; i < 11; ++i) {
        cout << "Добавляем " << i*5 << "... ";
        if (!arr.push(i*5)) {
            cout << "Не удалось добавить элемент." << endl;
        }
    }
    arr.print();

    arr.delateArray();
    
    
    return 0;
}