#pragma once
#include <unordered_set>
#include <vector>
#include "../Map/Map.h"
#include "../Cards/Card.h"
#include "../Cards/Hand.h"
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

	enum orderTypes{
		DEPLOY, ADVANCE, BOMB, BLOCKADE, AIRLIFT, NEGOTIATE
	} ;

	void issueOrder(const char* orderType);
};