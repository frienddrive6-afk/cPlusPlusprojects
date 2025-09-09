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

    int *tempResult = new int[M];
    int tempSize = 0;

    for (int i = 0; i < M; ++i) {
        if (!contains(B, N, *(A + i))) {
            if (!contains(tempResult, tempSize, *(A + i))) {
                *(tempResult + tempSize) = *(A + i);
                tempSize++;
            }
        }
    }

    int *finalResult = new int[tempSize];
    for(int i = 0; i < tempSize; ++i) {
        *(finalResult + i) = *(tempResult + i);
    }


    cout << "Масив A: ";
    printArray(A, M);
    cout << "Масив B: ";
    printArray(B, N);
    cout << "Результат : ";
    printArray(finalResult, tempSize);

    delete[] A;
    delete[] B;
    delete[] tempResult;
    delete[] finalResult;

    return 0;
}