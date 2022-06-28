#pragma once
#include <string>

class Astronomer {
private:
	std::string name, constellation;
public:
	Astronomer(std::string _name, std::string _constellation) : name{ _name }, constellation{ _constellation } {};
	std::string getName() { return this->name; }
	std::string getConstellation() { return this->constellation; }
};