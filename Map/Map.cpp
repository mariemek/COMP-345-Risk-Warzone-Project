
#include "Map.h"
using namespace std;
// Map implementation
Map::Map() {}

Map::Map(const Map& map) {
    territories = map.territories;
    continents = map.continents;
}

Map& Map::operator=(const Map& map) {
    territories = map.territories;
    continents = map.continents;
    return *this;
}

bool Map::validate() {
    if (!mapIsConnectedGraph()) return false;
    if (!continentsAreConnectedGraphs()) return false;
    if (!countriesBelongOneContinent()) return false;
    return true;
}

bool Map::mapIsConnectedGraph() {
    // If the map is a connected graph, we should be able to start from any node, perform Depth-First Search,
    // and end up with a set that contains every node in the map.
    unordered_set <string> nameset;

    const Territory* firstTerritory = territories[0];
    performDFS(firstTerritory, nameset);

    if (!setContainsTerritories(nameset, territories)) return false;

    return true;

}
/*
* Similar approach to mapIsConnectedGraph, but adding an end condition for the DFS is that if the current Territory's continent is not the same
* as the next, then don't add it to the set.
*/
bool Map::continentsAreConnectedGraphs() {
    for (Continent* continent : continents) {
        unordered_set <string> nameset;
        vector<Territory*>& continentTerritories = continent->territories;

        const Territory* firstTerritory = continentTerritories[0];

        performContinentDFS(firstTerritory, nameset);

        if(!setContainsTerritories(nameset, continentTerritories)) return false;
    }
    return true;
}


// Checks if the set contains all of the territories in the vectors
bool Map::setContainsTerritories(unordered_set <string> nameset, vector<Territory*>& territories) {
    for (const Territory* territory : territories) {
        if (nameset.find(territory->name) == nameset.end()) {
            return false;
        }
    }
    return true;
}

/*
* For every continent, every one of its territories should be pointing to it.
*/
bool Map::countriesBelongOneContinent() {
    for (Continent* continent : continents) {
        for (const Territory* territory : continent->territories) {
            if (continent != territory->continent) return false;
        }
    }
    return true;
}

void Map::performContinentDFS(const Territory* territory, unordered_set <string>& nameset) {
    if (nameset.find(territory->name) != nameset.end()) return;

    nameset.insert(territory->name);

    for (const Territory* adjacentTerritory : territory->adjacentTerritories) {
        // If both territories have the same continent, then you can explore the next territory.
        if(territory->continent == adjacentTerritory->continent) 
            performDFS(adjacentTerritory, nameset);
    }
}

void Map::performDFS(const Territory* territory, unordered_set <string>& nameset) {
    // If the current territory already exists in the set, exit the function (to not get stuck in infinite loop)
    if (nameset.find(territory->name) != nameset.end()) return;

    // Insert to the set before to avoid infinite loop.
    nameset.insert(territory->name);

    for (const Territory* adjacentTerritory : territory->adjacentTerritories) {
        // Recursively visit the neighbors
        performDFS(adjacentTerritory, nameset);
    }
}

std::ostream& operator<<(std::ostream& out, const Map& continent) {
    return out;
}

// The map's destructor is the one that handles destroying the territories & continents
Map::~Map() {
    for (Territory* territory : territories)
        delete territory;

    territories.clear();

    for (Continent* continent : continents)
        delete continent;

    continents.clear();
}
// Continent implementation
Continent::Continent(string& name) {
    this->name = name;
}

// Shallow copy because otherwise it would require copying the entire map? Seems quite useless considering the scope of this project.
Continent::Continent(const Continent& continent) {
    this->name = name;
    this->territories = territories;
}

// No need to do anything in here, the destructor of vector is called by default and frees the pointers but not what they're pointing to which will be handled
// by the map
Continent::~Continent() {
    cout << "Destroyed Continent: " << this->name << endl;
}

// Print the Territory type as a string
std::ostream& operator<<(std::ostream& out, const Continent& continent) {
    return out << continent.name;
}

// Territory implementation
Territory::Territory(const string& name, Continent* continent) {
    this->name = name;
    this->continent = continent;
    this->nbOfArmy = 0;
}

// Shallow copy because otherwise it would require copying the entire map? Seems quite useless considering the scope of this project.
Territory::Territory(const Territory& territory) {
    this->name = territory.name;
    this->continent = territory.continent;
    this->nbOfArmy = territory.nbOfArmy;
}

Territory& Territory::operator=(const Territory& territory) {
    this->name = territory.name;
    this->continent = territory.continent;
    this->nbOfArmy = territory.nbOfArmy;

    return *this;
}

/*
* Only set pointers to null, the Map object will handle deleting continents and the Game Engine will handle deleting the players
*/
Territory::~Territory() {
    continent = NULL;
    owner = NULL;
}

// Print the Territory type as a string
std::ostream& operator<<(std::ostream& out, const Territory& territory) {
    return out << territory.name;
}