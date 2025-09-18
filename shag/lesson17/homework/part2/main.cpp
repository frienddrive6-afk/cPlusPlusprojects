#include <iostream>
#include "translit_logic.h"

using namespace std;

int main() {

    int result = start_translit_app();

    if (result != 0) {
        cout << "Программа завершилась с ошибкой" << endl;
    }

    return result;
}