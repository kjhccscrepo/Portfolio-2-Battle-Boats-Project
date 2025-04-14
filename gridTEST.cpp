#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "grid.hpp"

int main(){
	Grid testGrid;
	Grid testGrid9L(9);

	assert(testGrid.getSize() == 4);
	testGrid.setGridLength(testGrid.getSize());
	assert(testGrid9L.getSize() == 9);

	assert(testGrid.getBoatIcon() == "⛵");
	assert(testGrid.getFireIcon() == "🔥");
	assert(testGrid.getMissIcon() == "❎");
	assert(testGrid9L.getBoatIcon() == "⛵");
	assert(testGrid9L.getFireIcon() == "🔥");
	assert(testGrid9L.getMissIcon() == "❎");

	assert(testGrid.getRemainingBoatsINT() == 0);
	assert(testGrid9L.getRemainingBoatsINT() == 0);
	assert(testGrid.getRemainingBoats() == "0");
	assert(testGrid9L.getRemainingBoats() == "0");

	assert(testGrid.getRow(1) == "B  〰 〰 〰 〰 \n");
	assert(testGrid9L.getRow(2) == "C  〰 〰 〰 〰 〰 〰 〰 〰 〰 \n");

	testGrid.addBoat("A3");
	assert(testGrid.getRow(0) == "A  〰 〰 ⛵ 〰 \n");
	testGrid9L.addBoat("F5");
	testGrid9L.addBoat("F6");
	testGrid9L.addBoat("F7");
	testGrid9L.addBoat("F8");
	assert(testGrid9L.getRow(5) == "F  〰 〰 〰 〰 ⛵ ⛵ ⛵ ⛵ 〰 \n");

	assert(!testGrid.winCheck());
	assert(!testGrid9L.winCheck());

	assert(testGrid.getRemainingBoatsINT() == 1);
	assert(testGrid9L.getRemainingBoatsINT() == 4);
	assert(testGrid.getRemainingBoats() == "1");
	assert(testGrid9L.getRemainingBoats() == "4");

	testGrid.hardCodeFire(1, 0);
	assert(testGrid.getRow(0) == "A  〰 🔥 ⛵ 〰 \n");


	testGrid9L.hardCodeFire(1, 5);
	testGrid9L.hardCodeMiss(6, 5);

	assert(testGrid9L.getRow(5) == "F  〰 🔥 〰 〰 ⛵ ⛵ ❎ ⛵ 〰 \n");


	return 0;

}