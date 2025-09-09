#include <iostream>
#include <algorithm>

using namespace std;

int main() {


    const int SIZE = 7;

    long long mP[SIZE] = {  //long long 8 байтів (64 біти)	від -9,223,372,036,854,775,808 до 9,223,372,036,854,775,807
        380971234567,
        380668765432,
        380931112233,
        380504455667,
        380678899001,
        380991213141,
        380635657585
    };

    long long hP[SIZE] = {  //long long 8 байтів (64 біти)	від -9,223,372,036,854,775,808 до 9,223,372,036,854,775,807
        442345678,
        448765432,
        441112233,
        444455667,
        448899001,
        441213141,
        445657585
    };

    int choice;

    do {
        cout << endl << "===== МЕНЮ СПРАВОЧНИКА =====" << endl;
        cout << "1. Отсортировать по номерам мобильных" << endl;
        cout << "2. Отсортировать по домашним номерам телефонов" << endl;
        cout << "3. Вывести список пользователей" << endl;
        cout << "4. Выход" << endl;
        cout << "---------------------------" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < SIZE - 1; ++i) {
                    for (int j = 0; j < SIZE - i - 1; ++j) {
                        if (mP[j] > mP[j + 1]) {
                            long long tempMobile = mP[j];
                            mP[j] = mP[j + 1];
                            mP[j + 1] = tempMobile;
                            
                            long long tempHome = hP[j];
                            hP[j] = hP[j + 1];
                            hP[j + 1] = tempHome;
                        }
                    }
                }
                cout << endl << "[!] Список отсортирован по мобильным номерам." << endl;
                
                for (int i = 0; i < SIZE; ++i) {
                    cout << mP[i] << " ";
                }
                cout << endl;

                for (int i = 0; i < SIZE; ++i) {
                    cout << hP[i] << " ";
                }
                cout << endl;

                break;
            }
            case 2: {
                for (int i = 0; i < SIZE - 1; ++i) {
                    for (int j = 0; j < SIZE - i - 1; ++j) {
                        if (hP[j] > hP[j + 1]) {
                            long long tempHome = hP[j];
                            hP[j] = hP[j + 1];
                            hP[j + 1] = tempHome;
                            
                            long long tempMobile = mP[j];
                            mP[j] = mP[j + 1];
                            mP[j + 1] = tempMobile;
                        }
                    }
                }
                cout << endl << "[!] Список отсортирован по домашним номерам." << endl;
                
                for (int i = 0; i < SIZE; ++i) {
                    cout << hP[i] << " ";
                }
                cout << endl;

                for (int i = 0; i < SIZE; ++i) {
                    cout << mP[i] << " ";
                }
                cout << endl;

                break;
            }
            case 3: {
                cout << endl << "===== СПИСОК НОМЕРОВ =====" << endl;
                cout << "Мобильный\t\tДомашний" << endl;
                cout << "----------------------------------" << endl;
                for (int i = 0; i < SIZE; ++i) {
                    cout << "+"<< mP[i] << "\t" << hP[i] << endl;
                }
                break;
            }
            case 4:
                cout << endl << "Завершение работы программы." << endl;
                break;
            default:
                cout << endl << "[!] Неверный выбор. Пожалуйста, попробуйте еще раз." << endl;
        }

    } while (choice != 4);

    return 0;
}