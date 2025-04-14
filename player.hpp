#pragma once


#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "grid.hpp"

class Player {
    friend class Grid;
private:
    std::string name;
    bool isAI;
    int totalBoats;
    int glength;
    Grid myGrid;
    int difficulty = 0;
    bool cheats;

    std::string vicEmote;

    std::string attackTarget = "B2";
    std::vector<std::string> myBoats;
    std::vector<std::string> allTargets;
    Grid myHiddenGrid;

public:
    //constructor
    Player(std::string nameP, int length, bool ai, int howmanyboats, settings intSettings);


    //setters
    void setTarget(std::string target);
    void addTarget(std::string freshTarget);
    void setDiff();

    std::string getVicEmote();
    //getter
    std::string pGetHeader();
    //getter
    std::string pGetRow(int i);
    //getter
    std::string pGetHiddenRow(int i);
    //getter
    int getMax() const;
    //getter
    std::string getName();
    //getter
    std::string pGetRemainingBoats();
    //getter
    int pGetRemainingBoatsINT();
    //getter
    bool isBot() const;
    //getter
    int getDiff() const;
    //getter
    std::string getTarget();
    //getter
    std::string showTarget(int i);
    //getter
    int howManyTargets();
    //getter
    int howManyBoats();
    //getter
    bool pIsBoat(std::string cords);

    void pCatchupHiddenBoard(std::string cords, std::string specialCac);

    //returns true if the cords passed in via ints is empty, false if it isnt
    bool emptyspace(int a, int b);
    //returns true if the cords passed in via string is empty, false if it isnt
    bool emptyspace(std::string passedString);

    std::string randCords() const;

    std::string randBoat();

    //checks if the cordinate is in a valid input
    std::string cordValidInput(int xybound, int xymin);


    std::string ppDisplay();
    std::string placeDisplay(std::string input);
    void genBoats();

    bool wrongPos(int a, int b);

    bool guessableCord(std::string passedString);

    std::string fireBall(std::string cords);

    //bot cheating attack
    std::string evilBotAttack(Player defender, std::string cords);

    std::string already_Guessed(Player defender, std::string input);

    //bot attack difficuly attacks
    std::string botAttack(Player defender);


    void forceUpdateGrid(int a, int b);
};