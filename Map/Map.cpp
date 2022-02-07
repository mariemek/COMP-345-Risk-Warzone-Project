
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

    for (const Territory* territory : territories) {
        // If a the name of a territory isn't in the set, then it is unreachable, thus the map wouldn't be a
        // connected map.
        if (nameset.find(territory->name) == nameset.end()) {
            return false;
        }
    }

    return true;

}

bool Map::continentsAreConnectedGraphs() {
    return true;
}

bool Map::countriesBelongOneContinent() {
    return true;
}

void Map::performDFS(const Territory* territory, unordered_set <string>& nameset) {
    // If the current territory already exists in the set, exit the function (to not get stuck in infinite loop)
    if (nameset.find(territory->name) != nameset.end()) return;

    // Insert to the set before to avoid infinite loop.
    nameset.insert(territory->name);

    for (const Territory* territory : territory->adjacentTerritories) {
        // Recursively visit the neighbors
        performDFS(territory, nameset);
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
}
