
#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "mainmenu.hpp"


int main() {
    settings gameSettings;

    int uniLength = 4;
    std::string temp;
    bool gameloop = true;
    std::string uniBoatIcon("⛵");

    srand((unsigned int)time(NULL));

    std::cout << "\n\nGREETINGS!  ⊂(｡◕‿‿◕｡)つ  " << std::endl;
    std::cout << "\nWelcome to BATTLEBOATS!         Please select a main menu option!" << std::endl;

    while (gameloop) {
        int menu = mainMenu();
        if (menu == 1) {
            playerVersusAI(gameSettings);
            std::cout << std::endl;
        }
        else if (menu == 2) {
            playerVersusPlayer(gameSettings);
            std::cout << std::endl;
        }
        else if (menu == 3) {
            std::cout << howToPlay();
            std::cout << std::endl;
        }
        else if (menu == 4) {
            std::cout << "\nWhat would you like to change the Boat icon to?";
            std::cout << "Current:   " << gameSettings.getBoat();
            gameSettings.newBoat();
        }
        else {
            std::cerr << "error! wrong result on main menu!";
            closeGame();
            break;
            return 0;
        }
    }
    std::cerr << "ERROR exited gameloop";


    return 0;
}