#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "MapLoader.h"

Map& MapLoader::createMap(string& filename) {
	const string continentsflag = "[continents]";
	Map* gamemap = new Map();

	ifstream mapstream;
	string line;
	cout << "Reading from " << filename << endl;
	mapstream.open(filename);

	// This will get the next line until it hits "[continents]" which will indicate the start of the continents.
	while (getline(mapstream, line) && line != continentsflag);

	unordered_map<int, Continent> continents;
	int continentnumber = 1;

	// This will process every continent until there isn't any continent left.
	while (getline(mapstream, line) && line != "") {
		Continent& continent = createContinent(line, *gamemap);

		pair<int, Continent> currentpair(continentnumber, continent);
		continents.insert(currentpair);

		cout << "Processing continent #" << continentnumber << " " << continent.name << endl;

		continentnumber++;
	}

	mapstream.close();

	return *gamemap;
}

Continent& MapLoader::createContinent(string& line, Map& gamemap) {
	vector<string>& split = splitInput(line, ' ');

	string name = split[0];

	Continent* continent = new Continent(name);

	return *continent;
}

vector<string>& MapLoader::splitInput(const string& line, const char delimiter) {
	vector<string>* destination = new vector<string>;

	for (size_t i = 0, j = 0; i < line.size(); i++) {
		if (line[i] == ' ') {
			destination->push_back(line.substr(j, i - j));
			j = i + 1;
		}
	}

	return *destination;
}

