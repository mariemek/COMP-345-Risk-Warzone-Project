#pragma once
#include <unordered_set>
#include <vector>
#include "../Map/Map.h"
#include "../Cards/Cards.h"
#include "../Orders/Orders.hpp"

using namespace std;

class Territory;

class Player {
public:
	unordered_set<Territory*> territories;
	Hand* hand;
	OrderList* orderlist;

	vector<Territory*>& toAttack();
	vector<Territory*>& toDefend();
};