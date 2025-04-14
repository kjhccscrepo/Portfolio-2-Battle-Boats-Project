#pragma once

#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "combat.hpp"

void playerVersusAI(settings iniFile);
void playerVersusPlayer(settings iniFile);
std::string howToPlay();
int mainMenu();
