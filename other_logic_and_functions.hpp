
#pragma once

#include <iostream>

void closeGame();

//this clears the buffer and allows for the user to input again after wrong input
void Buffer_Clear();
//overloaded function that allows for two ints or two strings to be called for the message.
std::string invalidMessage(int a, int b);
std::string invalidMessage(std::string a, std::string b);
//converts an integer to a string based off its ASCI value
std::string intToAsciiString(int number);

//returns the ASCI num value of the cordinate so it can be checked modularly
int getX(std::string getString);
int getY(std::string getString);

bool boundValidation(int boundmax, int isValid, int boundmin = 0);
int numValidInput(int boundmax, const std::string inputmessage, int boundmin = 1);
//bool that returns t/f if a cord inputted is in bounds
bool validateCords(std::string cords, int bounds);


class settings {
private:
	std::string uniBoat;
	std::string p1win;
	std::string p2win;
	std::string cpuwin;
	bool cheats;

public:

settings();

void setUniBoatIcon(std::string icon);

std::string p1WinMessage();
std::string p2WinMessage();
std::string CPUWinMessage();

std::string getBoat();

int newBoatM();
void newBoat();

void cheatsON();
void cheatsOFF();

bool hasCheats();

};


