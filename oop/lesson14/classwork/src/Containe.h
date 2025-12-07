#pragma once
#include <iostream>


template <typename T>
class Container
{
private:
    int size;
    T* arr;

public:
    Container(int size = 10);

    Container(const Container& obj);

    Container<T>& operator=(const Container& obj);

    void erase();
    
    void render();
    
    T& operator[](int index);

    ~Container();

    int getSize();



};