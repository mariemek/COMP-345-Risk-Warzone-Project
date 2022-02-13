
#include "Map.h"
using namespace std;
// Map implementation
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

bool Map::setContainsTerritories(unordered_set <string> nameset, vector<Territory*>& territories) {
    for (const Territory* territory : territories) {
        if (nameset.find(territory->name) == nameset.end()) {
            return false;
        }
    }
    return true;
}

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
// Continent implementation
Continent::Continent(string& name) {
    this->name = name;
}

// Territory implementation
Territory::Territory(string& name, Continent* continent) {
    this->name = name;
    this->continent = continent;
    this->nbOfArmy = 0;
}

Territory::~Territory() {
    //owner = NULL;
    delete (continent);
    continent = NULL;
}
