#include <iostream>
#include <vector>


using namespace std;

int main() {


    srand(time(NULL));

    const int GROUPS = 3;   
    const int STUDENTS = 5; 
    const int LABS = 4;     

    int journal[GROUPS][STUDENTS][LABS];

    cout << "Исходное состояние журнала:\n";
    for (int g = 0; g < GROUPS; ++g) {
        cout << "Группа " << g + 1 << ":\n";
        for (int s = 0; s < STUDENTS; ++s) {
            cout << "  Студент " << s + 1 << ": ";
            for (int l = 0; l < LABS; ++l) {
                journal[g][s][l] = rand() % 5; 
                cout << journal[g][s][l] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }


    cout << "Результаты допуска к экзамену:\n\n";

    for (int g = 0; g < GROUPS; ++g) {
        int exam_go = 0; 
        int automat = 0;   

        for (int s = 0; s < STUDENTS; ++s) {
            
            int reports = 0;  
            int defended = 0; 

            for (int l = 0; l < LABS; ++l) {
                int grade = journal[g][s][l];
                
                if (grade >= 3) {
                    reports++;
                }
                if (grade == 4) {
                    defended++;
                }
            }

            if (reports >= (LABS / 2)) {
                exam_go++;
            }

            if ((defended == LABS) || (defended == LABS - 1 && reports == LABS)) {
                automat++;
            }
        }

        cout << "--- Группа " << g + 1 << " ---" << endl;
        cout << "Допущено к экзамену: " << exam_go << " из " << STUDENTS << " студентов." << endl;
        cout << "Получат экзамен «автоматом»: " << automat << " студентов." << endl;
        cout << endl;
    }

    return 0;
}