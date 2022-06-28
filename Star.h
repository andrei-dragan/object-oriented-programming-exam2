#pragma once
#include <string>

class Star {
private:
	std::string name, constellation;
	int RA, Dec;
	double diameter;
public:
	Star(std::string _name, std::string _constellation, int _RA, int _Dec, double _diameter) : name{ _name }, constellation{ _constellation }, RA{ _RA }, Dec{ _Dec }, diameter{ _diameter } {};
	std::string getName() { return this->name; }
	std::string getConstellation() { return this->constellation; }
	int getRA() { return this->RA; }
	int getDec() { return this->Dec; }
	int getDiameter() { return this->diameter; }
};