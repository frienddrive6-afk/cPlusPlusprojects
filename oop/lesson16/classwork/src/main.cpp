#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
// #include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>



using namespace std;




class Queu
{
private:
    static const int DEFULT_STEP = 5;

    int count;
    int* arr;
    int capacity;
    int step;

    void reallocateMemory()
    {

        if(this->arr == nullptr)
        {
            this->arr = new int[this->step];
            this->capacity = step;

            return;
        }

        this->capacity = this->count + this->step;


        int* temp = new int[this->capacity];
        for(int i{}; i < this->count;++i)
        {
            temp[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = temp; 

    }


    bool isNotAllocated()
    {
        return this->arr == nullptr;
    }

public:

    Queu() :
        count{ 0 },
        arr{ nullptr },
        capacity{ 0 },
        step{ Queu::DEFULT_STEP }
    {}

    Queu(const Queu& obj) :
        count{ obj.count },
        arr{new int[obj.capacity]},
        capacity{ obj.capacity },
        step{ obj.step} 
    
    {
        for(int i{};i < this->count;++i)
        {
            arr[i] = obj.arr[i];
        }
    }


    void enqueue(int val)
    {
        if(this->isFull() || this->isNotAllocated())
        {
            this->reallocateMemory();
        }

        this->arr[this->count] = val;
        ++count;
    }

    int dequeue()
    {
        if(!this->isEmpty())
        {
            int val = arr[0];

            for(int i{}; i <count - 1;++i)
            {
                arr[i] = arr[i + 1];
            }

            --this->count;

            return val;
        }

        return -1;     //This is Kostil
    }


    bool isEmpty() const
    {
        return this->count < 1 || this->arr == nullptr;
    }


    bool isFull() const
    {
        return this->count == this->capacity;
    }


    void render()
    {
        cout<<"capacity = " <<this->capacity<<'\n';
        cout<<"count = " <<this->count<<'\n';
        cout<<"arr: ";
        for(int i{}; i < this->count;++i)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    }
    


    ~Queu()
    {
        if(!this->isNotAllocated())
        {
            delete arr;
        }
    }


    //конструктор копирования
    //operator=
    //enqueue()
    //dequeu()
    //деструктор



};




int main()
{      

    Queu a{};

    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(7);
    a.render();

    // cout << a.dequeue() <<'\n';
    // a.render();

    Queu b{a};
    b.render();


    return 0;
}