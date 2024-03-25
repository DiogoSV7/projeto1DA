#include "includes/Menu.h"
#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL,"Portuguese");
    char dataset_choice;
    cout << "┌─── Welcome to DAms ──────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    cout << setw(50) << "│        █████    █████  ███    ███ ███████        │" << endl;
    cout << setw(50) << "│        ██   ██ ██   ██ ████  ████ ██             │" << endl;
    cout << setw(50) << "│        ██   ██ ███████ ██ ████ ██ ███████        │" << endl;
    cout << setw(50) << "│        ██   ██ ██   ██ ██  ██  ██      ██        │" << endl;
    cout << setw(50) << "│        ██████  ██   ██ ██      ██ ███████        │" << endl;
    cout << "│" << setw(53) << "│" << endl;
    cout << "│    Choose the Dataset:                           │" << endl;
    cout << "│     [1] Madeira's Dataset                        │" << endl;
    cout << "│     [2] Portugal's Dataset                       │" << endl;
    cout << "│" << setw(53) << "│" << endl;
    cout << "└──────────────────────────────────────────────────┘" << endl;
    cout << "Please select the Dataset: ";
    std::cin >> dataset_choice;
    bool useLargeDataset = (dataset_choice == '2');
    Menu menu(useLargeDataset);
    menu.showMenu();
    return 0;
}
