#pragma once

#include "Astronomers.h"
#include "Stars.h"

class Service {
private:
	Stars stars;
	Astronomers astronomers;
public:
	Service(Astronomers _astronomers, Stars _stars) : stars{ _stars }, astronomers{ _astronomers } {};
	std::vector<Astronomer>getAstronomers() { return this->astronomers.getAstronomers(); }
	std::vector<Star>getStars() { return this->stars.getStars(); }
	std::vector<Star>getSortedStars();
	bool checkStar(int row, std::string constellation) { return this->stars.checkStar(row, constellation); }
	void addStar(std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter);
	void updateStar(std::string starName, std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter);
	std::string getStar(int idx) { return this->stars.getStar(idx); }
	std::string getConstellation(int idx) { return this->stars.getConstellation(idx); }
};