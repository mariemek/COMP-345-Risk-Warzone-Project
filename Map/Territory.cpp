#include "Territory.h"

Territory::Territory(string& name, Continent* continent) {
    this->name = name;
    this->continent = continent;
    this->nbOfArmy = 0;
}

Territory::~Territory() {
    //owner = NULL;
}
