
#include <iostream>
#include <string>
#include <cmath>
#include "other_logic_and_functions.hpp"
#include <vector>

//closes the game
void closeGame() {
    std::cerr << std::endl << "closing them game...";
    std::cerr << std::endl;
    exit(0);
}

//this clears the buffer and allows for the user to input again after wrong input
void Buffer_Clear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//overloaded function that allows for two ints or two strings to be called for the message.
std::string invalidMessage(int a, int b) {

    std::string n;
    n = "\nYou have failed to input a valid character. Please give input between " + std::to_string(a) + " and " + std::to_string(b) + "...\n";
    return n;
}
std::string invalidMessage(std::string a, std::string b) {

    std::string n;
    n = "\nYou have failed to input a valid character. Please give input between " + a + " and " + b + "...\n";
    return n;
}

//converts an integer to a string based off its ASCI value
std::string intToAsciiString(int number) {
    char z = char(number + 65);
    std::string xA;
    xA.push_back(z);
    return xA;
}

//returns the ASCI num value of the cordinate so it can be checked modularly
int getX(std::string getString) {
    int x = (toupper(getString.at(0)) - '0');
    x = x - 17;
    return x;
}
int getY(std::string getString) {
    int y = getString.at(1) - '0';
    y--;
    return y;
}

bool boundValidation(int boundmax, int isValid, int boundmin) {
    //std::cout << "(in boundVal)testing" << boundmax << " " << boundmin;
    if (isValid < boundmin || isValid > boundmax) {
        return false;
    }
    else
    {
        return true;
    }
}



int numValidInput(int boundmax, const std::string inputmessage, int boundmin) {
    int temp;
    const std::string message = inputmessage;
    std::cout << inputmessage;

    std::cin >> temp;
    if (std::cin.fail()) {
        std::cout << invalidMessage(boundmin, boundmax);
    }
    else if (temp < boundmin || temp > boundmax) {
        std::cout << invalidMessage(boundmin, boundmax);

    }
    else if (temp >= boundmin && temp <= boundmax) {
        //success!
        //std::cout << "Inputted " << to_string(temp) << "!";
        Buffer_Clear();
        return temp;
    }
    else {
        std::cout << invalidMessage(boundmin, boundmax);

    }
    Buffer_Clear();
    return numValidInput(boundmax, inputmessage, boundmin);
}


//bool that returns t/f if a cord inputted is in bounds
bool validateCords(std::string cords, int bounds) {
    if (cords.size() > 2 || cords.size() < 1) {
        return false;
    }
    int a = getX(cords);
    if (a >= 0 && a < bounds) {
        int b = getY(cords);
        if (b >= 0 && b < bounds) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}



settings::settings() {
    uniBoat = "⛵";
    p1win = "\\( ﾟヮﾟ)/";
    p2win = "✌(-‿-)✌";
    cpuwin = "┌(°...°)ノ";
    cheats = false;
}

//sets the boat icon.
void settings::setUniBoatIcon(std::string icon) {
    uniBoat = icon;
}
std::string settings::p1WinMessage() {
    return p1win;
}
std::string settings::p2WinMessage() {
    return p2win;
}
std::string settings::CPUWinMessage() {
    return cpuwin;
}

std::string settings::getBoat() {
    return uniBoat;
}

int settings::newBoatM() {
    std::cout << "What would you like the new boat Icon to be?\n"
        << "1) ⛵\n"
        << "2) ✿ \n"
        << "3) ★ \n"
        << "4) 𓈉 \n"
        << "5) ඞ \n"
        << "6) Ω \n";
    std::string inputmsg = "\nPick a boat: ";
    int input = numValidInput(6, inputmsg, 1);
    return input;
}          

void settings::newBoat() {
    int whatBoat = newBoatM();
    if (whatBoat == 1) {
        setUniBoatIcon("⛵");
    } 
    else if (whatBoat == 2) {
        setUniBoatIcon("✿ ");
    } 
    else if (whatBoat == 3) {
        setUniBoatIcon("★ ");
    }
    else if (whatBoat == 4) {
        setUniBoatIcon("𓈉 ");
    }
    else if (whatBoat == 5) {
        setUniBoatIcon("ඞ ");
    }
    else if (whatBoat == 6) {
        setUniBoatIcon("Ω ");
    }
    else {
        setUniBoatIcon("⛵");
    }
}

void settings::cheatsON() {
    cheats = true;
}
void settings::cheatsOFF() {
    cheats = false;
}
bool settings::hasCheats() {
    return cheats;
}


