#include <iostream>
#include <vector>  

using namespace std;



void CreateTabl(vector<int> numbers) {
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << "\t";
        
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
}


int FindPosition(vector<int> numbers) {
    int min_sum = 0;
    int best_start_position = 0;

    for (int i = 0; i < 10; ++i) {
        min_sum += numbers[i];
    }
    
    for (int i = 1; i <= 90; ++i) {
        
        int current_sum = 0;
        for (int j = 0; j < 10; ++j) {
            current_sum += numbers[i + j];
        }
        
        if (current_sum < min_sum) {
            min_sum = current_sum; 
            best_start_position = i; 
        }
    }

    return best_start_position;
}


int main() {
    srand(time(NULL));

    vector<int> main_numbers;
    for (int i = 0; i < 100; ++i) {
        main_numbers.push_back(rand() % 100);
    }

    cout << "Сгенерированный массив чисел (10x10):" << endl;
    CreateTabl(main_numbers);

    int best_position = FindPosition(main_numbers);

    cout << "\nПозиция с которой начинается последовательность с минимальной суммой: " << best_position << endl;

    return 0;
}


