#ifndef PROJETO1DA_MENU_H
#define PROJETO1DA_MENU_H

#include "Data.h"


class Menu {
public:
    Menu();
    Menu(bool useLargeDataset);
    void showMenu();
    void displayDisplayMenu() const;
    static void drawTop();
    static void drawBottom();
    void displayWaterNeeds();
    static int countAccentedCharacters(const std::string& str);
    int displayMaxWater(std::vector<std::string> cities);
    int extractNumberFromCode(const std::string& code);
    void displayAllWaterReservoirs() const;
    void displayAllPumpingStations() const;
    void displayAllDeliverySites() const;
    void displayAllPipes() const;
    std::unordered_map<std::string, std::pair<DeliverySites, int>> getDeliverySitesBefore();
    void showDiferences(std::unordered_map<std::string, std::pair<DeliverySites, int>> delivery_sites_before);
private:
    Data data_;
};




#endif //PROJETO1DA_MENU_H
