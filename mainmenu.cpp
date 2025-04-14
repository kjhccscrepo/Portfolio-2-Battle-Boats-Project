#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "mainmenu.hpp"



void playerVersusAI(settings iniFile) {
    std::cout << std::endl << "You have selected to Play Versus Computer!" << std::endl;
    std::string msgQgrid = "How big should the grid be?   (min 4, max 9)\nGrid Size: ";
    int uniLength = numValidInput(9, msgQgrid, 4);

    int maxBoat = ((uniLength * uniLength) / 5);
    std::string msgQbta = "How many boats do you want to place? (min 1, max " + std::to_string(maxBoat) + ")\nAmount: ";
    int uniBoat = numValidInput(maxBoat, msgQbta);

    Player player("Player", uniLength, false, uniBoat, iniFile);
    player.genBoats();

    Player enemyai("CPU", uniLength, true, uniBoat, iniFile);
    enemyai.setDiff();
    enemyai.genBoats();

    std::cout << std::endl << combat(player, enemyai).getName() << " has won!" << std::endl;
}
void playerVersusPlayer(settings iniFile) {
    //for pvp
    std::cout << std::endl << "You have selected to Play Versus Friend!" << std::endl;
    std::string msgQgrid = "How big should the grid be?   (min 4, max 9)\nGrid Size: ";
    int uniLength = numValidInput(9, msgQgrid, 4);
    int maxBoat = ((uniLength * uniLength) / 4);
    std::string msgQbta = "How many boats do you want to place? (min 1, max " + std::to_string(maxBoat) + ")\nAmount: ";
    int uniBoat = numValidInput(maxBoat, msgQbta);
    std::cout << "Player 2, no peeking!!!\n";
    Player player1("Player 1", uniLength, false, uniBoat, iniFile);
    player1.genBoats();
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Player 1, no peeking!!!\n";
    Player player2("Player 2", uniLength, false, uniBoat, iniFile);
    player2.genBoats();
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\n         " << combat(player1, player2).getName() << " has won!" << std::endl;
}
std::string howToPlay() {
    //not done, wanted to make this to explain things like the AI, pvp, and basic rules if I felt like it
    return "Guess cordinates to take down enemy ships! The player to lose all thier ships first loses!\nIf you are struggling to win, try playing on a lower difficuly!\n";
}

int mainMenu() {
    std::cout << "\n(1) Play game versus Computer" << std::endl;
    std::cout << "(2) Play game versus Friend (locally)" << std::endl;
    std::cout << "(3) How to play" << std::endl;
    std::cout << "(4) Settings" << std::endl;
    std::cout << "(5) Close game" << std::endl;
    //validations and navigation
    std::string msgQmenu = "\nYour Input: ";
    int mainMenuResult = numValidInput(5, msgQmenu);
    if (mainMenuResult == 1) {
        return 1;
    }
    else if (mainMenuResult == 2) {
        return 2;
    }
    else if (mainMenuResult == 3) {
        return 3;
    }
    else if (mainMenuResult == 4) {
        return 4;
    }
    else if (mainMenuResult == 5) {
        closeGame();
    }
    else {
        std::cerr << "error! wrong result on main menu!";
        closeGame();
    }
    std::cerr << "error! wrong result on main menu!";
    closeGame();
    return 0;
}

