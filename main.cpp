#include "includes/Menu.h"
#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

int main() {
    //qualquer n diferente de 2 seleciona o data set da madeira
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
    if(dataset_choice != '1' && dataset_choice != '2'){
        throw std::logic_error("Invalid dataset choice. Exiting...");
        return 0;
    }
    else
        menu.showMenu();
    return 0;
}
