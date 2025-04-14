
#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "player.hpp"

int main() {
	settings defaultSettings;
	Player Computer("CPU", 4, true, 2, defaultSettings);
	Player Player1("Player 1", 4, false, 2, defaultSettings);
	Player Player2("Player 2", 4, false, 2, defaultSettings);

	assert(Computer.getVicEmote() == "┌(°...°)ノ");
	assert(Player1.getVicEmote() == "\\( ﾟヮﾟ)/");
	assert(Player2.getVicEmote() == "✌(-‿-)✌");

	//no boats so it will fails
	assert(!Computer.pIsBoat("A3"));
	assert(!Player1.pIsBoat("B1"));
	assert(!Player2.pIsBoat("C2"));

	assert(Computer.emptyspace("A3"));
	assert(Player1.emptyspace("B1"));
	assert(Player2.emptyspace("C2"));



	return 0;
}