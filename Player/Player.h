#pragma once
#include <unordered_set>
#include <vector>
#include "../Map/Map.h"
#include "../Cards/Card.h"
#include "../Cards/Hand.h"
#include "../Orders/Orders.hpp"

using namespace std;
class OrderList;
class Territory;

class Player {
public:
	unordered_set<Territory*> territories;
	Hand* hand;
	vector<Territory*>& toAttack();
	vector<Territory*>& toDefend();

	enum orderTypes{
		DEPLOY, ADVANCE, BOMB, BLOCKADE, AIRLIFT, NEGOTIATE
	} ;
	OrderList* orderList;
	Player();
	void issueOrder(orderTypes o);
};