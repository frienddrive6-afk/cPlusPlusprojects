#include <iostream>
// #include<string>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int mystrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    if (str1[i] == str2[i]) return 0;
    else if (str1[i] > str2[i]) return 1;
    else return -1;
}


int StringToNumber(const char* str) {
    int number = 0;
    int i = 0;
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }
    while (str[i] != '\0') {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return number * sign;
}


char* NumberToString(int number) {
    if (number == 0) {
        char* str = new char[2];
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    int temp = number;
    int num_digits = 0;
    if (temp < 0) {
        num_digits = 1;
        temp = -temp;
    }
    while (temp > 0) {
        temp /= 10;
        num_digits++;
    }
    char* str = new char[num_digits + 1];
    str[num_digits] = '\0';
    if (number < 0) {
        str[0] = '-';
        number = -number;
    }
    int i = num_digits - 1;
    while (number > 0) {
        str[i] = (number % 10) + '0';
        number /= 10;
        i--;
    }
    return str;
}


char* Uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}


char* Lowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

char* mystrrev(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    char* new_str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        new_str[i] = str[len - 1 - i];
    }
    new_str[len] = '\0';
    return new_str;
}


int main() {

    const int max_len = 256; 

    cout << "1. Сравнения рядов "<< endl;
    char str1[max_len], str2[max_len];
    cout << "Введите первый ряд: ";
    cin.getline(str1, max_len);
    cout << "Введите второй ряд: ";
    cin.getline(str2, max_len);
    int cmp_result = mystrcmp(str1, str2);
    cout << "Результат: " << cmp_result << endl << endl;

    cout << "--- 2. ряд в число" << endl;
    char num_as_str[max_len];
    cout << "введите число строку: ";
    cin.getline(num_as_str, max_len);
    int num_result = StringToNumber(num_as_str);
    cout << "получаемое число: " << num_result << endl << endl;

    cout << "3. Число в строку" << endl;
    int number_to_convert;
    cout << "Введите целое число: ";
    cin >> number_to_convert;
    cin.ignore(32767, '\n');
    char* str_result = NumberToString(number_to_convert);
    cout << "Полученый ряд: \"" << str_result << "\"" << endl;
    delete[] str_result;
    cout << endl;

    cout << "4. В верхний регистр" << endl;
    char upper_str[max_len];
    cout << "Введите строчку: ";
    cin.getline(upper_str, max_len);
    cout << "Результат: " << Uppercase(upper_str) << endl << endl;

    cout << ". В нижний регистр" << endl;
    char lower_str[max_len];
    cout << "Введите строчку: ";
    cin.getline(lower_str, max_len);
    cout << "результат: " << Lowercase(lower_str) << endl << endl;

    cout << " 6. Реверс строчки " << endl;
    char rev_str[max_len];
    cout << "Введите строчку: ";
    cin.getline(rev_str, max_len);
    char* rev_res = mystrrev(rev_str);
    cout << "Результат: " << rev_res << endl;
    delete[] rev_res; 
    cout << endl;

    return 0;
}