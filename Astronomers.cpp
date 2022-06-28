#include "Astronomers.h"
#include <sstream>
#include <fstream>

using namespace std;

Astronomers::Astronomers() {
	this->read();
}

void Astronomers::read() {
	ifstream f("astronomers.txt");
	string line;
	while (getline(f, line)) {
		vector<string>tokens = this->readAstronomer(line, ',');
		Astronomer a{ tokens[0], tokens[1] };
		this->astronomers.push_back(a);
	}
	f.close();
}

vector<string> Astronomers::readAstronomer(string str, char delimiter) {
	vector<string>tokens;
	string token;
	stringstream ss(str);
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}