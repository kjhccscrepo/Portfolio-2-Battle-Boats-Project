
#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "player.hpp"


//this is the player class, ais and players are players, and thier grids are accessed through thier playerdata.

//constructor
Player::Player(std::string nameP, int length, bool ai, int howmanyboats, settings intSettings) {

    glength = length;
    name = nameP;
    isAI = ai;
    totalBoats = howmanyboats;
    myGrid.setGridLength(glength);
    difficulty = 0;
    myHiddenGrid.setGridLength(glength);
    cheats = intSettings.hasCheats();
    myGrid.setBoatIcon(intSettings.getBoat());
    if (!isAI) {
        if (name == "Player" || name == "Player 1") {
            vicEmote = intSettings.p1WinMessage();
        }
        else {
            vicEmote = intSettings.p2WinMessage();
        }
    }
    else {
        vicEmote = intSettings.CPUWinMessage();
    }
    

}

std::string attackTarget("B2");
std::vector<std::string> allTargets;
Grid myHiddenGrid;



//setters
void Player::setTarget(std::string target) {
    allTargets.clear();
    attackTarget = target;
}
void Player::addTarget(std::string freshTarget) {
    allTargets.push_back(freshTarget);
}
void Player::setDiff() {
    std::string setDiffMsg = "What would you like the difficulty of the CPU oppenent to be (0-10) (0 = easy, 10 = very hard)\nDifficulty: ";
    difficulty = numValidInput(10, setDiffMsg, 0);
}


std::string Player::getVicEmote() {
    return vicEmote;
}
//getter
std::string Player::pGetHeader() {
    return myGrid.getHeader();
}
//getter
std::string Player::pGetRow(int i) {
    return myGrid.getRow(i);
}
//getter
std::string Player::pGetHiddenRow(int i) {
    return myHiddenGrid.getRow(i);
}
//getter
int Player::getMax() const {
    return glength;
}
//getter
std::string Player::getName() {
    return name;
}
//getter
std::string Player::pGetRemainingBoats() {
    return myGrid.getRemainingBoats();
}
//getter
int Player::pGetRemainingBoatsINT() {
    return myGrid.getRemainingBoatsINT();
}
//getter
bool Player::isBot() const {
    return isAI;
}
//getter
int Player::getDiff() const {
    return difficulty;
}
//getter
std::string Player::getTarget() {
    return attackTarget;
}
//getter
std::string Player::showTarget(int i) {
    return allTargets[i];
}
//getter
int Player::howManyTargets() {
    return allTargets.size();
}
//getter
int Player::howManyBoats() {
    return myGrid.getRemainingBoatsINT();
}
//getter
bool Player::pIsBoat(std::string cords) {
    int a = getY(cords);
    int b = getX(cords);
    if (myGrid.isBoat(a, b)) {
        return true;
    }
    return false;
}

void Player::pCatchupHiddenBoard(std::string cords, std::string specialCac) {
    int a = getY(cords);
    int b = getX(cords);
    myHiddenGrid.catchupHiddenBoard(a, b, specialCac);
}

//returns true if the cords passed in via string is empty, false if it isnt
bool Player::emptyspace(std::string passedString) {
    int a = getY(passedString);
    int b = getX(passedString);
    if (myGrid.isNotGuessable(a, b) || myGrid.isBoat(a, b)) {
        return false;
    }
    else {
        //position is Empty!!!
        return true;
    }
}
//returns true if the cords passed in via ints is empty, false if it isnt
bool Player::emptyspace(int a, int b) {
    if (myGrid.isNotGuessable(a, b) || myGrid.isBoat(a, b)) {
        return false;
    }
    else {
        //position is Empty!!!
        return true;
    }
}

std::string Player::randCords() const {
    int yA = (rand() % (getMax()));
    std::string input = intToAsciiString(yA);
    int xI = (rand() % (getMax()));
    input = input + std::to_string(xI + 1);
    return input;
}

std::string Player::randBoat() {
    std::string input = randCords();
    int a = getX(input);
    int b = getY(input);
    if (emptyspace(a, b)) {
        return input;
    }
    else {
        return randBoat();
    }
}

//checks if the cordinate is in a valid input
std::string Player::cordValidInput(int xybound, int xymin = 1) {
    std::string input;
    std::string a = "A1";
    std::string b = intToAsciiString(xybound - 1) + std::to_string(xybound);

    std::cout << "Input a cordinate between " << a << " and " << b << "\nCord: ";

    std::cin >> input;
    input[0] = toupper(input.at(0));

    if (std::cin.fail() || input.size() != 2) {
        std::cout << invalidMessage(a, b);
        Buffer_Clear();
        return cordValidInput(xybound, xymin);
    }
    else if (validateCords(input, xybound)) {
        //success!?

        return input;
    }
    else
    {
        std::cout << invalidMessage(a, b);
        Buffer_Clear();
        return cordValidInput(xybound, xymin);
    }
    return cordValidInput(xybound, xymin);
}


std::string Player::ppDisplay() {
    return (name + ": \n\n" + myGrid.display());
}

std::string Player::placeDisplay(std::string input) {
    std::string tempstring(ppDisplay());
    tempstring.append("Boat succesfully placed at ");
    tempstring.append(input);
    tempstring.append("!\n");
    return tempstring;
}

void Player::genBoats() {
    if (totalBoats == 1) {
        if (isAI) {
            std::string cords = randBoat();
            myGrid.addBoat(cords);
        }
        else {
            //player generation
            std::cout << "Where would you like to hide your first boat?\nPosition: ";
            std::string input = cordValidInput(glength);
            myGrid.addBoat(input);
            std::cout << placeDisplay(input);
        }
    }
    else {
        //for more than 1 boat
        if (isAI) {
            // rnd gen pos
            std::string cords;
            for (int i = 0; i < totalBoats; i++) {
                cords = randBoat();
                myGrid.addBoat(cords);
            }
        }
        else {
            //player generation
            std::string cords;
            for (int i = 0; i < totalBoats; i++) {
                std::cout << "Where would you like boat #" << (i + 1) << "?" << std::endl;
                cords = cordValidInput(glength);
                if (emptyspace(cords)) {
                    myGrid.addBoat(cords);
                    std::cout << placeDisplay(cords);
                }
                else {
                    std::cout << std::endl << "You have picked a coordinate that already contained a boat... Try again." << std::endl;
                    i--;
                }
            }
        }
    }

}
bool Player::wrongPos(int a, int b) {
    if (myGrid.isNotGuessable(a, b)) {
        return true;
    }
    else {
        return false;
    }
}


bool Player::guessableCord(std::string passedString) {
    int a = getY(passedString);
    int b = getX(passedString);
    if (myGrid.isNotGuessable(a, b)) {
        return false;
    }
    else {
        //position could be a boat!!!
        return true;
    }
}




std::string Player::fireBall(std::string cords) {
    if (guessableCord(cords)) {
        int a = getY(cords);
        int b = getX(cords);
        if (myGrid.isBoat(a, b)) {
            myHiddenGrid.catchupHiddenBoard(a, b, myGrid.getFireIcon());
            return myGrid.fireShot(a, b);
        }
        else {
            myHiddenGrid.catchupHiddenBoard(a, b, myGrid.getMissIcon());
            return myGrid.missShot(a, b);
        }
    }
    else {
        return "ERROR";
    }
}

//bot cheating attack
std::string Player::evilBotAttack(Player defender, std::string cords) {
    //cheater
    if (defender.pIsBoat(cords)) {
        return cords;
    }
    else {
        cords = randCords();
        return evilBotAttack(defender, cords);
    }
}

std::string Player::already_Guessed(Player defender, std::string input) {
    if (defender.guessableCord(input)) {
        return input;
    }
    else {
        input = randCords();
        return already_Guessed(defender, input);
    }
}

//bot attack difficuly attacks
std::string Player::botAttack(Player defender) {
    //cheating bot
    std::string genCords = already_Guessed(defender, randCords());
    int hownice = rand() % 125 + 1;
    if (hownice > pow((getDiff() + 1), 2)) {
        return genCords;
    }
    else {
        return evilBotAttack(defender, genCords);
    }
}

void Player::forceUpdateGrid(int a, int b) {
    myGrid.hardCodeTest(a, b);
}