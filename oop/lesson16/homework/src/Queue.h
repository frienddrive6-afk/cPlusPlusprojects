#pragma once

#include <iostream>
#include "Person.h"

#define ERRORS

class Queue
{
private:
    static const int maxPersons = 10;

    Person array[10];
    int currentCount;


    int findMinStatusIndex() const
    {
        if (currentCount == 0) return -1;

        int minIndex = 0;
        for (int i = 1; i < currentCount; ++i) 
        {
            if (array[i].getStatus() < array[minIndex].getStatus())
            {
                minIndex = i;
            }
        }
        return minIndex;
    }

    int findMaxStatusIndex() const
    {
        if (currentCount == 0) return -1;

        int maxIndex = 0;
        for (int i = 1; i < currentCount; ++i)
        {
            if (array[i].getStatus() > array[maxIndex].getStatus())
            {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

public:
    Queue() : currentCount{ 0 } {}


    /// @return индекс песоны ниже статучом иначе -1
    int isHaveLowStatusPerson(Person& obj)
    {
        for(int i{}; i < Queue::maxPersons;++i)
        {
            if(obj.getStatus() > array[i].getStatus())
            {
                return i;
            }
        }

        return -1;
    }

    void addPerson(const Person& obj)
    {
        if (currentCount < maxPersons)
        {
            array[currentCount] = obj;
            currentCount++;
        }
        else
        {
            int minIndex = findMinStatusIndex();
            
            if (obj.getStatus() > array[minIndex].getStatus())
            {
                cout << "[Eviction] Выгнали: " << array[minIndex] << " ради " << obj << endl;
                
                array[minIndex] = obj;
            }
            else
            {
                cout << "[Fail] Мест нет, и статус " << obj.getStatus() << " слишком низок, чтобы кого-то выгнать." << endl;
            }
        }
    }

    Person Pull()
    {
        if (currentCount == 0)
        {
            cout << "Очередь пуста!" << endl;
            return Person(); 
        }

        int maxIndex = findMaxStatusIndex();
        Person result = array[maxIndex]; 

        cout << "Извлекаем: " << result << endl;

        // 2. Удаляем его из массива (Сдвиг влево)
        // [A, B(max), C, D] -> [A, C, D, (мусор)]
        for (int i = maxIndex; i < currentCount - 1; ++i)
        {
            array[i] = array[i + 1];
        }

        currentCount--;

        return result;
    }

    void Show() const
    {
        cout << "--- Queue (" << currentCount << ") ---" << endl;
        for (int i = 0; i < currentCount; ++i)
        {
            cout << "[" << i << "] " << array[i] << endl;
        }
        cout << "------------------" << endl;
    }



};