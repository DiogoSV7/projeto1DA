//
// Created by tiago on 17-03-2024.
//

#include "../includes/Menu.h"
#include <iostream>

using namespace std;


/**
 * @brief Default constructor for the Menu class.
 *
 * @detail This constructor initializes an instance of the Menu class.
 *
 * Time Complexity: O(1)
 */
Menu::Menu() {
    window_ = Window();
}

/**
 * @brief Draws the top section of the menu interface.
 *
 * @detail This function is responsible for rendering the top section of the menu interface.
 *
 * Time Complexity: O(1)
 */
void Menu::drawTop(){
    cout << "____________________________________________________" << endl;
    cout << "|" << "====================== Menu ======================" << "|" << endl;
    cout << "|__________________________________________________|" << endl;
}

/**
 * @brief Draws the bottom section of the menu interface.
 *
 * @detail This function is responsible for rendering the bottom section of the menu interface.
 *
 * Time Complexity: O(1)
 */
void Menu::drawBottom(){
    cout << "|__________________________________________________|" << endl;
    cout << "|==================================================|" << endl;
    cout << "|__________________________________________________|" << endl;
}

/**
 * @brief Display the main menu and handle user interactions.
 *
 * @info This method initializes a FlightManagementSystem and Data objects, then displays a menu with different options.
 * The user can choose options related to airports, statistics, or finding the best flight options.
 *
 * @complexity Time complexity: depends on the option chosen by the user.
 */
void Menu::showMenu() {
    char key;
    bool flag = true;
    while (flag) {
        drawTop();
        cout << "| 1. Maximum Flow to Cities                        |" << endl;
        cout << "| 2. Cities in Lack of Water                       |" << endl;
        cout << "| 3.                             |" << endl;
        cout << "| 4.                       |" << endl;
        cout << "| 5. Remove               |" << endl;
        cout << "| Q. Exit                                          |" << endl;
        drawBottom();
        cout << "Choose an option: ";
        cin >> key;
        switch (key) {
            case '1': {
                char key1;
                drawTop();
                cout << "| 1. Choose All Cities                             |" << endl;
                cout << "| 2. Choose Specific City (C_1 to C_9)             |" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key1;
                switch (key1) {
                    case '1': {
                        //percorrer lista de cidades e fazer a função displayMaxWater para cada uma
                        if(window_.displayAllCitiesMaxWater()==0){
                            cout << "Output file created successfully!" << endl;
                        }
                        break;
                    }
                    case '2': {
                        string city;
                        cout << "Choose a city (C_1 to C_9): ";
                        cin >> city;
                        if(window_.displayMaxWater(city)==0){
                            cout << "Output file created successfully!" << endl;
                        }
                        break;
                    }
                    case 'Q' : {
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }

                };
                break;
            }
            case '2': {
                window_.displayWaterNeeds();
                break;
            }
            case 'Q' : {
                flag = false;
                break;
            }
            default: {
                cout << endl << "Invalid option!" << endl;
            }

        };

        cout << endl;
        cout << "Would you like to do something else? (Y/N) \n";
        char newCicle;
        cin >> newCicle;
        if (newCicle == 'N') flag = false;
        while (newCicle != 'Y') {
            if (newCicle == 'N') {
                flag = false;
                break;
            }
            cout << R"(Please type "Y" or "N".)" << endl;
            cin >> newCicle;
        }
    }
}
