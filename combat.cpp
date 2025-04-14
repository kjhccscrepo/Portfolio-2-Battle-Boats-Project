#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "combat.hpp"


std::string cordValidAttackInput(Player attacker, Player Defender) {
    if (attacker.isBot()) {
        //bot attack
        std::string botcord;
        botcord = attacker.botAttack(Defender);
        return botcord;
    }
    else {
        std::string input;
        std::string msgQcord;
        std::string a;
        std::string b;
        a = "A1";
        b = intToAsciiString(attacker.getMax() - 1) + std::to_string(attacker.getMax());
        msgQcord = "\n" + attacker.getName() + ", where would you to attack?\n";
        std::cout << msgQcord;
        input = attacker.cordValidInput(attacker.getMax(), 0);
        if (validateCords(input, attacker.getMax())) {
            if (Defender.guessableCord(input)) {
                //success!?
                return input;
            }
            else {
                //number is not guessable
                std::cout << "You have entered in a number that was already guessed...\n";
                return cordValidAttackInput(attacker, Defender);
            }
        }
        else {
            std::cout << invalidMessage(a, b);
            return cordValidAttackInput(attacker, Defender);
        }
    }
    std::cerr << "ERROR IN ATTACK INPUT";
    closeGame();
    return "XX";
}

std::string damageCalc(Player &attacker, Player &defender) {
    std::string input = cordValidAttackInput(attacker, defender);
    std::string combo = attacker.getName() + " guesses " + input + "!\n";
    combo += defender.fireBall(input) + "\n";
    combo += defender.getName() + " has " + defender.pGetRemainingBoats() + " remaining boat(s)!";
    return combo;
}

std::string vsDisplayStart(Player p1, Player p2) {
    std::string tempContainer;
    tempContainer.push_back('\n');
    tempContainer.append(p1.getName());
    tempContainer.append(":");
    for (int i = 0; i < p1.getMax(); i++) {
        tempContainer.append("   ");
    }
    tempContainer.append(p2.getName());
    tempContainer.append(":");
    tempContainer.push_back('\n');
    tempContainer.append(eraseEndOfString(p1.pGetHeader()));
    tempContainer.append("     ");
    tempContainer.append(eraseEndOfString(p2.pGetHeader()));
    tempContainer.push_back('\n');
    return tempContainer;
}

std::string eraseEndOfString(std::string stringInput) {
    stringInput.erase((stringInput.size() - 1), 2);
    return stringInput;
}

std::string pveDisplay(Player p1, Player p2) {
    std::string tempContainer = vsDisplayStart(p1, p2);
    for (int i = 0; i < p1.getMax(); i++) {
        tempContainer.append(eraseEndOfString(p1.pGetRow(i)));
        tempContainer.append("   ");
        tempContainer.append(eraseEndOfString(p2.pGetHiddenRow(i)));
        tempContainer.push_back('\n');
    }
    return tempContainer;
}

std::string pvpDisplay(Player p1, Player p2) {
    std::string tempContainer = vsDisplayStart(p1, p2);
    for (int i = 0; i < p1.getMax(); i++) {
        tempContainer.append(eraseEndOfString(p1.pGetHiddenRow(i)));
        tempContainer.append("   ");
        tempContainer.append(eraseEndOfString(p2.pGetHiddenRow(i)));
        tempContainer.push_back('\n');
    }
    return tempContainer;
}

std::string publicDisplay(Player p1, Player p2) {
    std::string tempContainer = vsDisplayStart(p1, p2);
    for (int i = 0; i < p1.getMax(); i++) {
        tempContainer.append(eraseEndOfString(p1.pGetRow(i)));
        tempContainer.append("   ");
        tempContainer.append(eraseEndOfString(p2.pGetRow(i)));
        tempContainer.push_back('\n');
    }
    return tempContainer;
}

std::string endOfGame(Player p1, Player p2) {
    std::string tempString = "Final board:\n";
    tempString.append(publicDisplay(p1, p2));
    return tempString;
}


std::string whichdisplay(Player pA, Player pB) {
    if (pB.isBot() || pA.isBot()) {
        return pveDisplay(pA, pB);
    }
    else {
        return pvpDisplay(pA, pB);
    }
}

Player guessing(Player& pA, Player& pB, int turns) {
    if (turns % 2 == 0) {
        //player A turn 
        std::cout << damageCalc(pA, pB);
        std::cout << whichdisplay(pA, pB);
    }
    else {
        //player B turn
        std::cout << damageCalc(pB, pA);
        std::cout << whichdisplay(pA, pB);
    }
    if (pA.pGetRemainingBoatsINT() == 0) {
        std::cout << endOfGame(pA, pB);
        std::cout << "\n    " << pB.getVicEmote() << "        " << pB.getVicEmote() << "\n";
        return pB;
    }
    if (pB.pGetRemainingBoatsINT() == 0) {
        std::cout << endOfGame(pA, pB);
        std::cout << "\n    " << pA.getVicEmote() << "        " << pA.getVicEmote() << "\n";
        return pA;
    }
    turns++;
    return guessing(pA, pB, turns);
}
Player combat(Player& pA, Player& pB) {
    int turns = 0;

    //determines coinflip, has a higher chance to lose the higher the difficulty.
    std::cout << std::endl << "Flipping a coin to determining if " << pA.getName() << " or " << pB.getName() << " goes first.";
    std::cout << std::endl << "💿" << std::endl;
    //generates a value between 100 and 1
    int coinFlip = (rand() % 99) + 1;
    //checks if the flip is greater then the bots weighted coin flip value
    if (coinFlip >= (50 + (pB.getDiff() * 4))) {
        //player A wins flip
        std::cout << pA.getName() << " has won the coin flip!" << std::endl;
    }
    else {
        //player B wins flip
        std::cout << pB.getName() << " has won the coin flip!" << std::endl;
        turns++;
    }
    return guessing(pA, pB, turns);
}

