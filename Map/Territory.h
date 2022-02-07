#pragma once
#include <vector>
#include "Continent.h"

using std::string;
using std::vector;

class Territory;

class Continent {
public:
	string name;
	vector<Territory*> territories;

	Continent(string&);
};
