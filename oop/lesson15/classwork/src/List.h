#pragma once
#include "ListItem.h"
#include <iostream>

using namespace std;

//Конструктор копирования
//конструктор
//getCount()
//isEmpty()
//добавить элемент в tail
//добавить элемент в head
//operator[]
//insert(Tval, int index)
//удаление элемента
//render()

//деструктор



template <typename T>
class List
{
private:
    ListItem<T>* head;
    ListItem<T>* tail;
    int count;

    ListItem<T>* find(int index)
    {
        ListItem<T>* current = this->head;

        for(int i{}; i < index; ++i)
        {
            current = current->getNext();
        }

        return current;
    }

public:
    List<T>() :
        head{ nullptr },
        tail{ nullptr },
        count{ 0 }
    {}

    List<T>(const ListItem<T>& obj) :
        head{ nullptr },
        tail{ nullptr },
        count{ 0 }
    {
        push(obj.getVal());
    }


    List<T>(const List<T>& obj) :
        head{ nullptr },
        tail{ nullptr },
        count{ 0 }
    {
        if(obj.isEmpty())
        {
            return;
        }

        ListItem<T>* objCurrent{ obj.head };
        ListItem<T>* newItem{ nullptr };
        ListItem<T>* prev{ nullptr };

        for(int i{}; i < obj.getCount(); ++i)
        {
            newItem = new ListItem<T>{ *objCurrent };

            this->tail = newItem;
            if(i == 0)
            {
                this->head = newItem;
            }else
            {
                prev->setNext(newItem);
            }


            prev = newItem;
            objCurrent = objCurrent->getNext();


        }

        this->count = obj.getCount();
        

    }




    int getCount() const
    {
        return this->count;
    }


    bool isEmpty() const
    {
        return this->count == 0;
    }

    void clear()
    {
        while (!isEmpty())
        {
            remove(0);
        }
    }


    void push(T val)
    {
        ListItem<T>* newItem = new ListItem<T>{ val };

        if(this->isEmpty())
        {
            this->head = newItem;
        }else
        {
            this->tail->setNext(newItem);
        }

        this->tail = newItem;
        ++this->count;
    }


    void pushToHead(T val)
	{
		ListItem<T>* newItem = new ListItem<T>{ val };

		if (this->isEmpty())
			this->tail = newItem;
		else
			newItem->setNext(this->head);

		this->head = newItem;

		++this->count;
	}



    void insert(T val,int index)
    {
        if(index > count)
        {
            return;
        } 
        
        if(index == count)
        {
            this->push(val);
            return;
        }
        
        if(index == 0)
        {
            this->pushToHead(val);
            return;
        }


        ListItem<T>* newItem = new ListItem<T>{ val };

        ListItem<T>* prev = this->find(index - 1);

        ListItem<T>* next = prev->getNext();

        prev->setNext(newItem);
        newItem->setNext(next);

    }



    void render() const
    {
        cout <<"count = " << this->count << '\n';
        cout<<"List: ";

        if(this->isEmpty())
        {
            cout << "empty\n\n";
            return;
        }else
        {
            cout<<'\n';
        }


        ListItem<T>* temp = this->head;

        while(temp != nullptr)
        {
            cout << temp->getVal() << ' ';
            temp = temp->getNext();
        }

        cout<<"\n\n";
    }




    //update(homework)

    List<T>& operator=(const List<T>& obj)
    {
        if(this == &obj)
        {
            return *this;
        }

        this->clear();

        ListItem<T>* temp = obj.head;
        while(temp != nullptr)
        {
            this->push(temp->getVal());
            temp = temp->getNext();
        }

        return *this;
    }

    T operator[](int index)
    {

        return find(index)->getVal();
    }

    void remove(int index)
    {
        if (index < 0 || index >= count)
        {
            return;
        }

        ListItem<T>* itemToDelete = nullptr;

        if (index == 0)
        {
            itemToDelete = head;
            head = head->getNext(); 
            
            if (count == 1) 
            {
                tail = nullptr;
            }
        }
        else 
        {
            ListItem<T>* prev = find(index - 1);
            itemToDelete = prev->getNext(); 

            prev->setNext(itemToDelete->getNext());

            if (itemToDelete == tail)
            {
                tail = prev;
            }
        }

        delete itemToDelete;
        count--;
    }




    void swap(int el1, int el2)
    {
        if (el1 == el2) return;
        if (el1 < 0 || el1 >= count || el2 < 0 || el2 >= count) return;


        ListItem<T>* prev1 = nullptr;
        ListItem<T>* curr1 = head;
        for (int i = 0; i < el1; ++i) {
            prev1 = curr1;
            curr1 = curr1->getNext();
        }

        ListItem<T>* prev2 = nullptr;
        ListItem<T>* curr2 = head;
        for (int i = 0; i < el2; ++i) {
            prev2 = curr2;
            curr2 = curr2->getNext();
        }

        
        if (prev1 == nullptr) {
            head = curr2; 
        } else {
            prev1->setNext(curr2); 
        }

        if (prev2 == nullptr) {
            head = curr1;
        } else {
            prev2->setNext(curr1);
        }

        
        ListItem<T>* tempNext1 = curr1->getNext();
        ListItem<T>* tempNext2 = curr2->getNext();

        if (curr1->getNext() == curr2) 
        {
            curr2->setNext(curr1);
            curr1->setNext(tempNext2);
        } 
        else 
        {
            curr2->setNext(tempNext1);
            curr1->setNext(tempNext2);
        }

        if (tail == curr1) 
        {
            tail = curr2;
        }
        else if (tail == curr2)
        { 
            tail = curr1;
        }
    }




    ~List<T>()
    {

        clear();
    

    }


};