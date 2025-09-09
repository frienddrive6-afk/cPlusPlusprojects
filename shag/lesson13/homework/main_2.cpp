#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
#include <iomanip>

using namespace std;


struct Info
{
    string motor_model;
    string color;
    int col_vladelc;
};

struct Cars
{
    string marka;
    string model;
    int year_vupusk;
    int price;
    bool IsTorg;
    Info danni;

};


void ZapovnMassive(vector<Cars>& Cars_massiv,int size);
void PrintCarsTable(const vector<Cars>& cars_massiv, int size);

int main() {

    srand(time(NULL));

    int size;
    cout<<"Введите количество машин: ";
    cin>>size;

    vector<Cars> cars_massiv(size);

    ZapovnMassive(cars_massiv,size);



    cout << "\n\n======================================== Каталог автомобилей ========================================" << endl;
    PrintCarsTable(cars_massiv, size);    


    return 0;
}


void ZapovnMassive(vector<Cars>& cars_massiv,int size)
{
    for(int i = 0;i < size;i++)
    {
        cout<<"Введите марку автомобиля: ";
        cin>>cars_massiv[i].marka;

        cout<<"Введите модель автомобиля: ";
        cin>>cars_massiv[i].model;

        cout<<"Введите год выпуска автомобиля: ";
        cin>>cars_massiv[i].year_vupusk;

        cout<<"Введите цену автомобиля: ";
        cin>>cars_massiv[i].price;

        cout<<"Доступенли тог у авто(Да/Нет): ";
        string _clear;
        cin>>_clear;
        if(_clear == "Да")
        {
            cars_massiv[i].IsTorg = true;
        }else
        {
            cars_massiv[i].IsTorg = false;
        }
        

        cout<<"Введите модель двигателя: ";
        cin>>cars_massiv[i].danni.motor_model;

        cout<<"Введите цвет автомобиля: ";
        cin>>cars_massiv[i].danni.color;

        cout<<"Введите количество владельцев авто: ";
        cin>>cars_massiv[i].danni.col_vladelc;
    }


}



void PrintCarsTable(const vector<Cars>& cars_massiv, int size)
{
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << left 
         << setw(15) << "Марка" 
         << setw(15) << "Модель" 
         << setw(8) << "Год" 
         << setw(12) << "Цена" 
         << setw(8) << "Торг"
         << setw(18) << "Двигатель"
         << setw(15) << "Цвет"
         << setw(10) << "Владельцы" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << left 
             << setw(15) << cars_massiv[i].marka
             << setw(15) << cars_massiv[i].model
             << setw(8) << cars_massiv[i].year_vupusk 
             << setw(12) << cars_massiv[i].price
             << setw(8) << (cars_massiv[i].IsTorg ? "Да" : "Нет")
             << setw(18) << cars_massiv[i].danni.motor_model
             << setw(15) << cars_massiv[i].danni.color
             << setw(10) << cars_massiv[i].danni.col_vladelc << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}