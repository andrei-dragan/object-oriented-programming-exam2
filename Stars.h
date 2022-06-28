#pragma once
#include "Star.h"
#include <vector>

class Stars {
private:
	std::vector<Star>stars;
public:
	Stars();
	void read();
	void write();
	std::vector<std::string> readStar(std::string str, char delimiter);
	std::vector<Star>getStars() { return this->stars; }
	bool checkStar(int row, std::string constellation);
	void addStar(Star s);
	void updateStar(std::string starName, Star s);
	std::string getStar(int idx) { return this->stars[idx].getName(); }
	std::string getConstellation(int idx) { return this->stars[idx].getConstellation(); }
};