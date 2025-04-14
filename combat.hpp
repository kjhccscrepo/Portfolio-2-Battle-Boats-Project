#pragma once

#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "player.hpp"

std::string cordValidAttackInput(Player attacker, Player Defender);
std::string damageCalc(Player &attacker, Player &defender);
std::string vsDisplayStart(Player p1, Player p2);
std::string eraseEndOfString(std::string stringInput);
std::string pveDisplay(Player p1, Player p2);
std::string pvpDisplay(Player p1, Player p2);
std::string publicDisplay(Player p1, Player p2);
std::string endOfGame(Player p1, Player p2);
std::string whichdisplay(Player pA, Player pB);
Player guessing(Player& pA, Player& pB, int turns);
Player combat(Player& pA, Player& pB);


