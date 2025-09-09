#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct 
{
    string firstname;
    string stat;
    int sar_ocenka; 
} Students;

void Zapovn(vector<Students> &peoples) 
{
    for(int i = 0; i < peoples.size(); i++)
    {
        cout << "\n--- Студент " << i + 1 << " ---" << endl;
        cout << "Введите фамилию: ";
        cin >> peoples[i].firstname;

        cout << "Введите пол (m/g): ";
        cin >> peoples[i].stat;

        cout << "Введите средний балл: ";
        cin >> peoples[i].sar_ocenka;
    }
}

void filterAndRes(const vector<Students> &peoples) 
{
    float ser_ocenka_girls = 0.0f;
    int col_girls = 0;
    
    float ser_ocenka_boys = 0.0f;
    int col_boys = 0;

    for(int i = 0; i < peoples.size(); i++)
    {
        if(peoples[i].stat == "m")
        {
            ser_ocenka_boys += peoples[i].sar_ocenka;
            col_boys++;
        }
        else if(peoples[i].stat == "g")
        {
            ser_ocenka_girls += peoples[i].sar_ocenka;
            col_girls++; 
        }
    }

    float avg_boys = 0.0f;
    if (col_boys > 0) {
        avg_boys = ser_ocenka_boys / col_boys;
    }

    float avg_girls = 0.0f;
    if (col_girls > 0) {
        avg_girls = ser_ocenka_girls / col_girls;
    }

    cout << "\n--- Результаты ---" << endl;
    cout << "Средний балл парней: " << (col_boys > 0 ? to_string(avg_boys) : "нет данных") << endl;
    cout << "Средний балл девушек: " << (col_girls > 0 ? to_string(avg_girls) : "нет данных") << endl;
    
    if (col_boys > 0 && col_girls > 0) 
    {
        if (avg_boys > avg_girls)
        {
            cout << "Парни выиграли, так как их средний балл (" << avg_boys << ") выше, чем у девушек (" << avg_girls << ")." << endl;
        }
        else if (avg_girls > avg_boys)
        {
            cout << "Девушки выиграли, так как их средний балл (" << avg_girls << ") выше, чем у парней (" << avg_boys << ")." << endl;
        }
        else
        {
            cout << "Ничья! Средние баллы одинаковы." << endl;
        }
    } else {
        cout << "Невозможно сравнить, так как одна из групп пуста." << endl;
    }
}

int main() {
    srand(time(NULL));

    int size;
    cout << "Введите количество студентов: ";
    cin >> size;

    if (size <= 0) {
        cout << "Количество должно быть положительным." << endl;
        return 1;
    }

    vector<Students> peoples(size);

    Zapovn(peoples);

    filterAndRes(peoples);

    return 0;
}