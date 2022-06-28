#include "Stars.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Stars::Stars() {
	this->read();
}

void Stars::read() {
	ifstream f("stars.txt");
	string line;
	while (getline(f, line)) {
		vector<string>tokens = this->readStar(line, ',');
		Star s{ tokens[0], tokens[1], stoi(tokens[2]), stoi(tokens[3]), stod(tokens[4]) };
		this->stars.push_back(s);
	}
	f.close();
}

void Stars::write() {
	ofstream g("stars.txt");
	vector<Star>stars = this->stars;
	sort(stars.begin(), stars.end(), [](Star A, Star B) {
		if (A.getConstellation() == B.getConstellation()) {
			return A.getDiameter() < B.getDiameter();
		}
		return A.getConstellation() < B.getConstellation();
	});

	for (auto star : stars) {
		g << star.getName() + "," + star.getConstellation() + "," + to_string(star.getRA()) + "," + to_string(star.getDec()) + "," + to_string(star.getDiameter()) << '\n';
	}
	g.close();
}

vector<string> Stars::readStar(string str, char delimiter) {
	vector<string>tokens;
	string token;
	stringstream ss(str);
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

bool Stars::checkStar(int row, string constellation) {
	vector<Star>sortedStars = this->getStars();
	sort(sortedStars.begin(), sortedStars.end(), [](Star A, Star B) {
		return (A.getConstellation() < B.getConstellation());
	});
	return (sortedStars[row].getConstellation() == constellation);
}

void Stars::addStar(Star s) {
	for (auto star : this->stars) {
		if (star.getName() == s.getName()) {
			throw exception{""};
		}
	}
	this->stars.push_back(s);
	this->write();
}

void Stars::updateStar(string starName, Star s) {
	for (int i = 0; i < this->stars.size(); i++) {
		if (this->stars[i].getName() == starName) {
			this->stars[i] = s;
			return;
		}
	}
}