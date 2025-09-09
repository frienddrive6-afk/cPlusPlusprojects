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

    int resSize = M + N;

    int *resArr = new int[resSize];

    for (int i = 0; i < M; ++i) {
        *(resArr + i) = *(A + i);
    }

    for (int i = 0; i < N; ++i) {
        *(resArr + M + i) = *(B + i);
    }

    cout << "Масив A: ";
    printArray(A, M);
    cout << "Масив B: ";
    printArray(B, N);
    cout << "Результат: ";
    printArray(resArr, resSize);

    delete[] A;
    delete[] B;
    delete[] resArr;

    return 0;
}