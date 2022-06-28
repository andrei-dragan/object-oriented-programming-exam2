#pragma once
#include "Astronomer.h"
#include <vector>

class Astronomers {
private:
	std::vector<Astronomer>astronomers;
public:
	Astronomers();
	void read();
	std::vector<std::string> readAstronomer(std::string str, char delimiter);

	std::vector<Astronomer>getAstronomers() { return this->astronomers; }
};