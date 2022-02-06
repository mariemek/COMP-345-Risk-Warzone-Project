#include "Map.h"

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
