#pragma once
#include <string>
#include <vector>
#include "Territory.h"

using std::string;
using std::vector;

class Continent;

class Territory { //declaration of the territory class
public:
	string name;
	Continent* continent; //name of the territory and continent
//	Player* owner; // pointer to the owner of this territory
	int nbOfArmy; // the number of army in the territory
	vector<Territory*> adjacentTerritories; // adjacentTerritories 

	Territory(string&, Continent*);
	~Territory();//destructor

};

