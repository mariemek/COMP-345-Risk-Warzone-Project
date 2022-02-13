#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "MapLoader.h"

Map& MapLoader::createMap(string filename) {
	const string continentsflag = "[continents]";
	Map* gamemap = new Map();

	ifstream mapstream;
	string line;
	cout << "Reading from " << filename << endl;
	mapstream.open(filename);

	// This will get the next line until it hits "[continents]" which will indicate the start of the continents.
	while (getline(mapstream, line) && line != continentsflag);

	unordered_map<int, Continent*> continents;
	int continentnumber = 1;

	cout << endl << "Processing continents" << endl;
	// This will process every continent until there isn't any continent left.
	while (getline(mapstream, line) && line != "") {
		Continent& continent = createContinent(line);
		gamemap->continents.push_back(&continent);

		pair<int, Continent*> currentpair(continentnumber, &continent);
		continents.insert(currentpair);

		cout << "\tProcessing continent #" << continentnumber << " " << continent.name << endl;

		continentnumber++;
	}

	// Skip [countries] line
	getline(mapstream, line);

	unordered_map<int, Territory*> countries;

	cout << endl << "Processing countries" << endl;
	// This will process every countries until there isn't any left.
	while (getline(mapstream, line) && line != "") {
		int countrynumber;

		Territory& territory = createTerritory(line, continents, countrynumber);
		gamemap->territories.push_back(&territory);

		pair<int, Territory*> currentpair(countrynumber, &territory);
		countries.insert(currentpair);

		cout << "\tProcessing country #" << countrynumber << " " << territory.name << " that is part of " << territory.continent->name << endl;
	}

	// Skip [borders] line
	getline(mapstream, line);

	cout << endl << "Processing borders" << endl;
	// This will process every borders until there isn't any left.
	while (getline(mapstream, line) && line != "") {

		processBorders(line, countries);

	}

	mapstream.close();

	return *gamemap;
}

void MapLoader::processBorders(string& line, unordered_map<int, Territory*> countries) {
	vector<string>& split = splitInput(line, ' ');

	int countrynumber = stoi(split[0]);

	Territory* origincountry = countries.at(countrynumber);

	cout << "\tProcessing the borders of " << origincountry->name << ". Added borders to the following countries: ";

	for (size_t i = 1, N = split.size(); i < N; i++) {
		int bordercountrynumber = stoi(split[i]);
		Territory* bordercountry = countries.at(bordercountrynumber);

		origincountry->adjacentTerritories.push_back(bordercountry);

		cout << bordercountry->name << " ";
	}

	cout << endl;
}

Continent& MapLoader::createContinent(string& line) {
	vector<string>& split = splitInput(line, ' ');

	string name = split[0];

	Continent* continent = new Continent(name);

	return *continent;
}

Territory& MapLoader::createTerritory(string& line, unordered_map<int, Continent*> continents, int& countrynumber) {
	vector<string>& split = splitInput(line, ' ');

	countrynumber = stoi(split[0]);
	string name = split[1];
	int continentid = stoi(split[2]);

	// Retrieve the continent from the map and add the new territory to the list of territories of that continent
	Continent* continent = continents.at(continentid);

	Territory* territory = new Territory(name, continent);

	continent->territories.push_back(territory);

	return *territory;
}

vector<string>& MapLoader::splitInput(const string& line, const char delimiter) {
	vector<string>* destination = new vector<string>;

	size_t i = 0, j = 0;

	for (; i < line.size(); i++) {
		if (line[i] == ' ') {
			// Check first if j is already equal to i. (This happens when theres two consecutive spaces, we do not want to save "").
			if(i != j) destination->push_back(line.substr(j, i - j));
			j = i + 1;
		}
	}

	// save the last part when i goes out of bounds if previous character was not an empty space.
	if (i != j) destination->push_back(line.substr(j, i - j));

	return *destination;
}

