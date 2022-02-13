#pragma once
#include <unordered_set>
#include <vector>
#include "../Map/Map.h"
#include "../Cards/Card.h"
#include "../Cards/Hand.h"
#include "../Orders/Orders.hpp"

using namespace std;

class Territory;
class OrderList;

class Player {
public:
	unordered_set<Territory*> territories;
	Hand* hand;
	OrderList* orderList;

	vector<Territory*>& toAttack();
	vector<Territory*>& toDefend();

	enum orderTypes {
		DEPLOY = 0, ADVANCE, BOMB, BLOCKADE, AIRLIFT, NEGOTIATE
	};
	Player();
	void issueOrder(orderTypes, Player&, Territory&);
	void issueOrder(orderTypes, Player&, int, Territory&);
	void issueOrder(orderTypes, Player&, int, Territory&, Territory&);
	void issueOrder(orderTypes, Player&, Player&);
};