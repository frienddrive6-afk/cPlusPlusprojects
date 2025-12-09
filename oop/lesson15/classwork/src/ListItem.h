#pragma once

//Требования для T
//дефолтный конструктор
//конструктор копирования
//оператор вывода << для T


template<typename T>
class ListItem
{
private:
    T val;
    ListItem<T>* next;

    
public:
    ListItem():
        val{},
        next{ nullptr }
    {}

    ListItem(T val) :
        val{ val},
        next{ nullptr }
    {}

    ListItem(const ListItem<T>& obj) :
        val{ obj.val },
        next{ nullptr }
    {}


    const T& getVal() const
    {
        return this->val;
    }

    void setVal(T val)
    {
        this->val = val;
    }


    ListItem<T>* getNext()
    {
        return this->next;
    }

    void setNext(ListItem<T>* next)
    {
        this->next = next;
    }


};