#include "Containe.h"

template<typename T>
Container<T>::Container(int size):
  size{size},
  arr{ new T[size]{} }
{ }

template<typename T>
Container<T>::Container(const Container<T>& obj) :
  size{ obj.size },
  arr{ new T[obj.size] {} }
{
  for (int i{}; i < this->size; ++i)
    arr[i] = obj.arr[i];
}


template<typename T>
Container<T>& Container<T>::operator=(const Container<T>& obj)
{
  if (this == &obj)
    return *this;

  if (this->arr != nullptr)
    delete[] this->arr;

  this->size = obj.size;
  this->arr = new T[this->size];

  for (int i{}; i < this->size; ++i)
    arr[i] = obj.arr[i];

  return *this;
}

template<typename T>
void Container<T>::erase()
{
  if (this->arr != nullptr)
  {
    delete[] this->arr;
    this->arr = nullptr;
    this->size = 0;
  }
}

template<typename T>
void Container<T>::render()
{
  for (int i{}; i < this->size; ++i)
    std::cout << this->arr[i] << ' ';
  std::cout << "\n\n";
}

template<typename T>
T& Container<T>::operator[](int index)
{
  return this->arr[index];
}

template<typename T>
int Container<T>::getSize()
{
  return this->size;
}

template<typename T>
Container<T>::~Container()
{
  if (this->arr != nullptr)
    delete[] this->arr;
}
