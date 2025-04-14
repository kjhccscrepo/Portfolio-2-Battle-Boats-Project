#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "mainmenu.hpp"



int main(){
	std::string tempCompString = howToPlay();
	std::string testedString = "Guess cordinates to take down enemy ships! The player to lose all thier ships first loses!\nIf you are struggling to win, try playing on a lower difficuly!\n";
	assert(tempCompString == testedString);
	assert(tempCompString != " ");
	assert(" " != testedString);
	return 0;
}
