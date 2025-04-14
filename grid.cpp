
#include <iostream>
#include <sstream>
#include <vector>
//this is for the issue i was having with display
#include<cassert>

#include "grid.hpp"


Grid::Grid() {
    gridMaxIndex = 4;
    leftBoats = 0;
    boat = "⛵";
}

Grid::Grid(int length) {
    gridMaxIndex = length;
    for (int i = 0; i < gridMaxIndex; i++) {
        rowValues.resize(i + 1);
        for (int j = 0; j < gridMaxIndex; j++) {
            rowValues[i].resize(j + 1);
            rowValues[i][j] = "〰";
        }
    }
    for (int a = 0; a < gridMaxIndex; a++) {
        yAlphaNames.resize(a + 1);
        yAlphaNames[a] = intToAsciiString(a);
    }
    leftBoats = 0;
    boat = "⛵";
}


std::vector<std::vector<std::string>> rowValues{};
std::vector<std::string> yAlphaNames{};


std::string Grid::generateRow(int index) {
    std::string rowWIP = yAlphaNames[index] + "  ";
    for (int xInP = 0; xInP < gridMaxIndex; xInP++) {
        rowWIP = rowWIP + rowValues[xInP][index] + " ";
    }
    rowWIP.append("\n");
    return rowWIP;
}

std::string Grid::generateHeader() const {
    std::string headWIP = " ";
    std::string temp;
    for (int i = 0; i < gridMaxIndex; i++) {
        headWIP = headWIP + "  ";
        temp = std::to_string(i + 1);
        headWIP = headWIP + temp;
    }
    headWIP.append("\n");
    return headWIP;
}


void Grid::catchupHiddenBoard(int a, int b, std::string specialCac) {
    rowValues[a][b] = specialCac;
}


//setters
void Grid::setBoatIcon(std::string newBoat) {
    boat = newBoat;
}

//a catchup constructor
void Grid::setGridLength(int length) {
    gridMaxIndex = length;
    for (int i = 0; i < gridMaxIndex; i++) {
        rowValues.resize(i + 1);
        for (int j = 0; j < gridMaxIndex; j++) {
            rowValues[i].resize(j + 1);
            rowValues[i][j] = "〰";
        }
    }
    for (int a = 0; a < gridMaxIndex; a++) {
        yAlphaNames.resize(a + 1);
        yAlphaNames[a] = intToAsciiString(a);
    }
}
void Grid::increaseBoatCount() {
    leftBoats++;
}
void Grid::decreaseBoatCount() {
    leftBoats--;
}

//getters
std::string Grid::getBoatIcon() {
    return boat;
}
std::string Grid::getHeader() {
    return Grid::generateHeader();
}
std::string Grid::getRow(int i) {
    return generateRow(i);
}
std::string Grid::getRemainingBoats() const {
    return std::to_string(leftBoats);
}
int Grid::getRemainingBoatsINT() const {
    return leftBoats;
}
int Grid::getSize() const {
    return gridMaxIndex;
}
std::string Grid::getFireIcon() {
    return "🔥";
}
std::string Grid::getMissIcon() {
    return "❎";
}


//silly little void statments
void Grid::addBoat(std::string boatCords) {
    int yVal = getY(boatCords);
    int xVal = getX(boatCords);
    rowValues[yVal][xVal] = getBoatIcon();
    increaseBoatCount();
}

//  BUGGIN
bool Grid::isBoat(int a, int b) {
    if (rowValues[a][b] == getBoatIcon()) {
        return true;
    }
    return false;
}

void Grid::hardCodeFire(int a, int b) {
    rowValues[a][b] = getFireIcon();
}
void Grid::hardCodeMiss(int a, int b) {
    rowValues[a][b] = getMissIcon();
}

std::string Grid::fireShot(int a, int b) {
    hardCodeFire(a, b);
    decreaseBoatCount();
    return "HIT!!!";
}
std::string Grid::missShot(int a, int b) {
    hardCodeMiss(a, b);
    return "Miss.";
}

bool Grid::winCheck() const {
    if (leftBoats == 0) {
        //WIN
        return true;
    }
    else {
        //game continues
        return false;
    }
}



bool Grid::isNotGuessable(int a, int b) {
    if (rowValues[a][b] == "❎" || rowValues[a][b] == "🔥") {
        return true;
    }
    else {
        return false;
    }
}
// checks if a string is in a grids bounds values
bool Grid::inBounds(std::string input) const {
    if (getY(input) <= 0 || getY(input) >= (getSize() - 1)) {
        //the Y is out of bounds
        return false;
    }
    else {
        if (getX(input) <= 1 || getY(input) >= getSize()) {
            //the X is out of bounds
            return false;
        }
        else {
            //the target is in bounds
            return true;
        }
    }
}

//actualy display
std::string Grid::display() {
    std::stringstream ss;
    ss << generateHeader();
    for (int i = 0; i < gridMaxIndex; i++) {
        ss << generateRow(i);
    }
    return ss.str();
}

void Grid::hardCodeTest(int a, int b) {
    rowValues[a][b] = "W ";
}
