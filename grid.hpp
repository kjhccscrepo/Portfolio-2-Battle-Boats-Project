
#pragma once

#include <iostream>
#include <vector>
#include "other_logic_and_functions.hpp"

class Grid {
private:
    //the boat is defined like this so i can easily make it custumized later
    std::string boat;
    int gridMaxIndex;
    std::vector<std::vector<std::string>> rowValues;
    std::vector<std::string> yAlphaNames;
    int leftBoats;
    std::string generateRow(int index);
    std::string generateHeader() const;
public:

    //constructor
    Grid(int length);
    Grid();

    void catchupHiddenBoard(int a, int b, std::string specialCac);

    //setters
    void setBoatIcon(std::string newBoat);

    //a catchup constructor
    void setGridLength(int length);

    void increaseBoatCount();

    void decreaseBoatCount();

    //getters
    std::string getBoatIcon();

    std::string getHeader();

    std::string getRow(int i);
    std::string getRemainingBoats() const;
    int getRemainingBoatsINT() const;
    int getSize() const;

    // getters for if hidden boats are on or off
    
    std::string getFireIcon();
    std::string getMissIcon();


    //silly little void statments
    void addBoat(std::string boatCoords);
    
    bool isBoat(int a, int b);

    void hardCodeFire(int a, int b);
    void hardCodeMiss(int a, int b);
    std::string fireShot(int a, int b);
    std::string missShot(int a, int b);

    bool winCheck() const;



    bool isNotGuessable(int a, int b);
    // checks if a string is in a grids bounds values
    bool inBounds(std::string input) const;

    //actualy display
    std::string display();

    void hardCodeTest(int a, int b);
};

