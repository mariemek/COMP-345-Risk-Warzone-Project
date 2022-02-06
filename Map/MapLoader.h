#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Map.h"

class MapLoader {
public:
	static Map& createMap(string& filename);
	static Continent& createContinent(string&, Map&);
	static vector<string>& splitInput(const string&, const char);
};

#endif