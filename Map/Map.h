#ifndef MAP_H
#define MAP_H
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "Territory.h";
#include "Continent.h";

using std::string;
using std::vector;
using std::unordered_set;

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