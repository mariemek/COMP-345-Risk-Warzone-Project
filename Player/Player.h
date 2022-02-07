#pragma once
#include "../Map/Map.h"
#include "../Cards/Cards.h"

class Territory;

class Player {
public:
	unordered_set<Territory*> territories;
	Hand* hand;

	vector<Territory*>& toAttack();
	vector<Territory*>& toDefend();
};