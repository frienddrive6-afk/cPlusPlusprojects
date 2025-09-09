#include <iostream>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


void Array_Create(int ar[], int size) {
    for(int i = 0; i < size; i++) {
        ar[i] = rand() % 100;
    }
    for(int i = 0; i < size; i++) {
        cout<< ar[i] <<"\t";
        if((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}


int Search_min_index(int array[], int size, int current_index = 0, int best_index = -1, int min_sum = 0) {
    if (best_index == -1) {
        int pochatkova_suma = 0;
        for (int i = 0; i < 10; ++i) {
            pochatkova_suma += array[i];
        }
        return Search_min_index(array, size, 1, 0, pochatkova_suma);
    }


    if (current_index > size - 10) {
        return best_index;
    }


    int current_sum = 0;
    for (int j = 0; j < 10; j++) {
        current_sum += array[current_index + j];
    }

    if (current_sum < min_sum) {
        return Search_min_index(array, size, current_index + 1, current_index, current_sum);
    } else {
        return Search_min_index(array, size, current_index + 1, best_index, min_sum);
    }
}


int main() {
    srand(time(NULL));
    
    const int size = 100;
    int ar[size];

    Array_Create(ar, size);
   
    int min_index = Search_min_index(ar, size);

    if (min_index != -1) {
        cout << "Позиция с минимальной сумой: " << min_index << endl;
    }

    return 0;
}