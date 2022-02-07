#pragma once
#include <unordered_set>
#include <vector>
#include "../Map/Map.h"
#include "../Cards/Cards.h"

using namespace std;

class Territory;

class Player {
public:
	unordered_set<Territory*> territories;
	Hand* hand;

	vector<Territory*>& toAttack();
	vector<Territory*>& toDefend();
};