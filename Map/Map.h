#ifndef MAP_H
#define MAP_H
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


class Continent;
class Territory;

class Continent {
public:
	string name;
	vector<Territory*> territories;

	Continent(string&);
};

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

class Map { //declaration of the map
private:
	bool mapIsConnectedGraph();
	bool continentsAreConnectedGraphs();
	bool countriesBelongOneContinent();
	void performDFS(const Territory*, unordered_set <string>&);
	void performContinentDFS(const Territory*, unordered_set <string>&);
	bool setContainsTerritories(unordered_set <string>, vector<Territory*>&);

public:
	vector<Territory*> territories;
	vector<Continent*> continents;

	bool validate();


};
#endif