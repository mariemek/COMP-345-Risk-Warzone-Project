#pragma once
#include <unordered_set>
#include <vector>
#include "../Map/Map.h"
#include "../Cards/Cards.h"
#include "../Orders/Orders.hpp"

using namespace std;

class Territory;
class OrderList;
class Hand;

class Player {
public:
	string name;
	unordered_set<Territory*> territories;
	Hand* hand;
	OrderList* orderList;

	vector<Territory*>& toAttack();
	vector<Territory*>& toDefend();

	enum orderTypes {
		DEPLOY = 0, ADVANCE, BOMB, BLOCKADE, AIRLIFT, NEGOTIATE
	};
	Player(string);
	Player(const Player*);
	~Player();

	void issueOrder(orderTypes, Territory*);
	void issueOrder(orderTypes, int, Territory*);
	void issueOrder(orderTypes, int, Territory*, Territory*);
	void issueOrder(orderTypes, Player*);
};