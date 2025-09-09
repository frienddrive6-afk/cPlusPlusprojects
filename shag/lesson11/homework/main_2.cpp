#include <iostream>
// #include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;

void fillArray(int *arr, int size) {
    cout << "Введіть " << size << " елементів масиву:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

bool contains(int *arr, int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) == element) {
            return true;
        }
    }
    return false;
}

int AddEl(int* Arr, int Size, int* checkArr, int checkSize, int* destArr, int destSize) {
    for (int i = 0; i < Size; ++i) {
        int currentElement = *(Arr + i);
        if (!contains(checkArr, checkSize, currentElement)) {
            if (!contains(destArr, destSize, currentElement)) {
                *(destArr + destSize) = currentElement;
                destSize++;
            }
        }
    }
    return destSize;
}


int main() {


    int M, N;
    cout << "Введіть розмір масиву A (M): ";
    cin >> M;
    cout << "Введіть розмір масиву B (N): ";
    cin >> N;

    int *A = new int[M];
    int *B = new int[N];

    cout << "\n--- Заповнення масиву A ---" << endl;
    fillArray(A, M);
    cout << "\n--- Заповнення масиву B ---" << endl;
    fillArray(B, N);

    int *tres = new int[M + N];
    int resSize = 0;

    resSize = AddEl(A, M, B, N, tres, resSize);

    resSize = AddEl(B, N, A, M, tres, resSize);

    int *fres = new int[resSize];
    for(int i = 0; i < resSize; ++i) {
        *(fres + i) = *(tres + i);
    }

    cout << "Масив A: ";
    printArray(A, M);
    cout << "Масив B: ";
    printArray(B, N);
    cout << "Результат: ";
    printArray(fres, resSize);

    delete[] A;
    delete[] B;
    delete[] tres;
    delete[] fres;

    return 0;
}