#pragma once

#include<iostream>




template <typename T> 
class MyVector
{
private:
    int array_len;
    T* array;
    
public:
    MyVector() : array_len{0}, array{nullptr} {}

    MyVector(int len) : array_len{len}, array{nullptr} {
        createArray();
    }

    ~MyVector() {
        delete[] array;
    }

    MyVector(const MyVector<T>& other) {
        array_len = other.array_len;
        if (array_len > 0) {
            array = new T[array_len];
            for (int i = 0; i < array_len; ++i) {
                array[i] = other.array[i];
            }
        } else {
            array = nullptr;
        }
    }

    MyVector<T>& operator=(const MyVector<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] array;
        array_len = other.array_len;
        if (array_len > 0) {
            array = new T[array_len];
            for (int i = 0; i < array_len; ++i) {
                array[i] = other.array[i];
            }
        } else {
            array = nullptr;
        }
        return *this;
    }

    void createArray() {
        delete[] array;
        if (array_len > 0) {
            array = new T[array_len];
        } else {
            array = nullptr;
        }
    }

    void push_back(const T& num) {
        int new_len = array_len + 1;
        T* new_array = new T[new_len];
        for(int i = 0; i < array_len; ++i) {
            new_array[i] = array[i];
        }
        new_array[array_len] = num;
        delete[] array;
        array = new_array;
        array_len = new_len;
    }

    T print_index(int index) {
        if (index >= 0 && index < array_len) {
            return array[index];
        }
        return T{}; 
    }

    void change_by_index(int index, const T& new_num) {
        if (index >= 0 && index < array_len) {
            array[index] = new_num;
        }
    }

    void delate_by_index(int index) {
        if (index < 0 || index >= array_len) {
            return; 
        }
        int new_len = array_len - 1;
        if (new_len <= 0) {
            delete[] array;
            array = nullptr;
            array_len = 0;
            return;
        }
        T* new_array = new T[new_len];
        int new_array_index = 0; 
        for (int i = 0; i < array_len; ++i) {
            if (i == index) {
                continue; 
            }
            new_array[new_array_index] = array[i];
            new_array_index++; 
        }
        delete[] array;
        array = new_array;
        array_len = new_len;
    }

    int size() {
        return array_len;
    }
};


