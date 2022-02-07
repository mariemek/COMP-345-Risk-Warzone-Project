#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Map.h"

using std::unordered_map;

class MapLoader {
public:
	static Map& createMap(string& filename);
	static Continent& createContinent(string&);
	static Territory& createTerritory(string&, unordered_map<int, Continent*>, int&);
	static void processBorders(string& line, unordered_map<int, Territory*> countries);
	static vector<string>& splitInput(const string&, const char);
};

#endif