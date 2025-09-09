#include <iostream>

using namespace std;


short WhoFirst() {
    short whofirst_hod = 0;
    do {
        cout << "Игра в кости!" << endl;
        cout << "Кто ходит первым?\n1) Вы\n2) Компьютер\nВаш выбор: ";
        cin >> whofirst_hod;
    } while (whofirst_hod < 1 || whofirst_hod > 2);
    return whofirst_hod;
}


int MakeThrow(string playerName) {
    cout << "\n--- Ход игрока: " << playerName << " ---" << endl;
    
    short continue_choice = 0;
    if (playerName == "Игрок") {
        do {
            cout << "Введите 1, чтобы бросить кости: ";
            cin >> continue_choice;
        } while (continue_choice != 1);
    } else {
        cout << "Компьютер бросает кости..." << endl;
    }


    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    if (playerName == "Игрок") {
        cout << "Вам выпало: " << dice1 << " и " << dice2 << endl;
    } else {
        cout << "Компьютеру выпало: " << dice1 << " и " << dice2 << endl;
    }

    int sum = dice1 + dice2;
    cout << "Сумма за этот бросок: " << sum << endl;
    
    return sum;
}

void DeclareWinner(int playerScore, int computerScore) {
    cout << "\n=================================" << endl;
    cout << "           РЕЗУЛЬТАТЫ" << endl;
    cout << "=================================" << endl;
    cout << "Общая сумма очков Игрока: " << playerScore << endl;
    cout << "Общая сумма очков Компьютера: " << computerScore << endl;
    
    double playerAverage = (double)playerScore / 5.0;
    double computerAverage = (double)computerScore / 5.0;

    cout << "Средний балл за бросок (Игрок): " << playerAverage << endl;
    cout << "Средний балл за бросок (Компьютер): " << computerAverage << endl;
    cout << "---------------------------------" << endl;

    if (playerScore > computerScore) {
        cout << "Поздравляем! Вы победили!" << endl;
    } else if (computerScore > playerScore) {
        cout << "К сожалению, победил компьютер." << endl;
    } else {
        cout << "Ничья! Победила дружба." << endl;
    }
    cout << "=================================" << endl;
}


void Game(short whofirst_hod) {
    int playerScore = 0;
    int computerScore = 0;
    const int totalRounds = 5; 

    bool isPlayerTurn;

    if (whofirst_hod == 1) 
    {
        isPlayerTurn = true;
    } else 
    {
        isPlayerTurn = false;
    }

    for (int round = 1; round <= totalRounds; ++round) {
        cout << "\n<<<<<<<<<< РАУНД " << round << " >>>>>>>>>>" << endl;
        
        if (isPlayerTurn) {
            playerScore += MakeThrow("Игрок");
        } else {
            computerScore += MakeThrow("Компьютер");
        }
        
        isPlayerTurn = !isPlayerTurn;
    }

    DeclareWinner(playerScore, computerScore);
}

int main() {
    srand(time(NULL));

    short whofirst_hod = WhoFirst();
    
    Game(whofirst_hod);

    return 0;
}