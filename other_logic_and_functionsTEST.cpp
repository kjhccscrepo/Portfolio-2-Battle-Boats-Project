
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cassert>
#include "other_logic_and_functions.hpp"


int main() {

	assert(getX("D1") == 3);
	assert(getY("D1") == 0);

	assert(getX("I4") == 8);
	assert(getY("I4") == 3);

	assert(boundValidation(10, 9, 0));
	assert(boundValidation(10, 1, 0));
	assert(boundValidation(10, 10, 0));
	assert(boundValidation(10, 0, 0));
	assert(!boundValidation(10, 11, 0));
	assert(!boundValidation(10, -1, 0));

	assert(validateCords("D4", 4));
	assert(validateCords("A1", 4));

	assert(validateCords("A1", 9));
	assert(validateCords("I9", 9));

	settings defaultSettings;

	assert(defaultSettings.p1WinMessage() == "\\( ﾟヮﾟ)/");
	assert(defaultSettings.p2WinMessage() == "✌(-‿-)✌");
	assert(defaultSettings.CPUWinMessage() == "┌(°...°)ノ");
	assert(defaultSettings.getBoat() == "⛵");


	return 0;
}