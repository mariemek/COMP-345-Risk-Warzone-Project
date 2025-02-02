#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "../Player/Player.h"
using namespace std;

class Player;
class Continent;
class Territory;

class Continent {
public:
	string name;
	vector<Territory*> territories;

	friend std::ostream& operator<<(std::ostream&, const Continent&);

	Continent(string&);
	Continent(const Continent&);
	Continent& operator=(const Continent&);
	~Continent();
};

class Territory { //declaration of the territory class
public:
	string name;
	Continent* continent; //name of the territory and continent
	Player* owner; // pointer to the owner of this territory
	int nbOfArmy; // the number of army in the territory
	vector<Territory*> adjacentTerritories; // adjacentTerritories 

	friend std::ostream& operator<<(std::ostream&, const Territory&);

	Territory(const string&, Continent*);
	Territory(const Territory&);
	Territory& operator=(const Territory&);
	~Territory();//destructor

};

class Map { //declaration of the map
private:
	bool mapIsConnectedGraph();
	bool continentsAreConnectedGraphs();
	bool countriesBelongOneContinent();
	void performDFS(const Territory*, unordered_set <string>&);
	void performContinentDFS(const Territory*, unordered_set <string>&);
	bool setContainsTerritories(unordered_set <string>, vector<Territory*>&);

public:
	friend std::ostream& operator<<(std::ostream&, const Map&);
	vector<Territory*> territories;
	vector<Continent*> continents;

	bool validate();

	Map();
	Map(const Map&);
	Map& operator=(const Map&);
	~Map();

};
