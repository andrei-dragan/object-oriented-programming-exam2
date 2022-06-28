#include "Service.h"
#include <algorithm>

using namespace std;

vector<Star> Service::getSortedStars() {
	vector<Star>sortedStars = this->getStars();
	sort(sortedStars.begin(), sortedStars.end(), [](Star A, Star B) {
		return (A.getConstellation() < B.getConstellation());
	});
	return sortedStars;
}

void Service::addStar(std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter) {
	if (name == "") {
		throw exception{ "The name should not be empty! Try again!" };
	}

	int RA = 0, Dec = 0;
	double diameter = 0;

	try {
		RA = stoi(sRA);
	}
	catch (std::exception& e) {
		throw exception{ "The Right Ascension should be an integer number!" };
	}

	try {
		Dec = stoi(sDec);
	}
	catch (std::exception& e) {
		throw exception{ "The declination should be an integer number!" };
	}

	try {
		diameter = stod(sDiameter);
	}
	catch (std::exception& e) {
		throw exception{ "The diameter should be a real number!" };
	}

	Star s{ name, constellation, RA, Dec, diameter };
	
	try {
		this->stars.addStar(s);
	}
	catch (exception& e) {
		throw exception{ "There is already a star with this name!" };
	}
}


void Service::updateStar(std::string starName, std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter) {
	if (name == "") {
		throw exception{ "The name should not be empty! Try again!" };
	}

	int RA = 0, Dec = 0;
	double diameter = 0;

	try {
		RA = stoi(sRA);
	}
	catch (std::exception& e) {
		throw exception{ "The Right Ascension should be an integer number!" };
	}

	try {
		Dec = stoi(sDec);
	}
	catch (std::exception& e) {
		throw exception{ "The declination should be an integer number!" };
	}

	try {
		diameter = stod(sDiameter);
		if (diameter <= 10) {
			throw exception{ "The diameter should be a real number greater than 10!" };
		}
	}
	catch (std::exception& e) {
		throw exception{ "The diameter should be a real number greater than 10!" };
	}

	Star s{ name, constellation, RA, Dec, diameter };
	this->stars.updateStar(starName, s);
}