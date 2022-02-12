#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include "../Map/Map.h"

using namespace std;
class Territory;
class Continent;

// ------------------------------------------------------------
// Declaration of OrderList, Order and all subclasses of Order
// ------------------------------------------------------------

class Order {
protected:
	bool* validity;
	string* className;
	static string* EMPTYSTRING;
	static Continent* EMPTYCONT;
	static Territory* EMPTYTERR;
	static Player* EMPTYPLAYER;
	friend ostream& operator<<(ostream&, Order&);
public:
	Order();
	virtual ~Order();
	Order(const Order& o);
	Order& operator =(const Order& o);
	bool& getValidity();
	string& getClassName();
	void validate();
	void execute();
};

class OrderList {
								// List as a vector for dynamic resizing of List
								// List of Order objects
public:
	vector<Order*> list;
	OrderList();
	~OrderList();
	OrderList(const OrderList& o);
	OrderList& operator=(const OrderList& o);
	void move(int from, int to);
	void remove(int position);
};

class Deploy : public Order {
	int numOfArmies;
	Territory& location;
public:
	Deploy();
	Deploy(int, Territory&);
	virtual ~Deploy();
	Deploy(const Deploy& d);
	Deploy& operator=(const Deploy& d);
	void validate();
	void execute(int numOfArmies, Territory& location);
};

class Advance : public Order {
	int numOfArmies;
	Territory& to;
	Territory& from;
public:
	Advance();
	Advance(int, Territory&, Territory&);
	virtual ~Advance();
	Advance(const Advance& a);
	Advance& operator=(const Advance& a);
	void validate();
	void execute(int numOfArmies, Territory& to, Territory& from);
};

class Bomb : public Order {
	Territory& location;
public:
	Bomb();
	Bomb(Territory&);
	virtual ~Bomb();
	Bomb(const Bomb& b);
	Bomb& operator=(const Bomb b);
	void validate();
	void execute(Territory& location);
};

class Blockade : public Order {
	Territory& location;
public:
	Blockade();
	Blockade(Territory&);
	virtual ~Blockade();
	Blockade(const Blockade& b);
	Blockade& operator=(const Blockade& b);
	void validate();
	void execute(Territory& location);
};

class Airlift : public Order {
	int numOfArmies;
	Territory& to;
	Territory& from;
public:
	Airlift();
	Airlift(int, Territory&, Territory&);
	virtual ~Airlift();
	Airlift(const Airlift& a);
	Airlift& operator=(const Airlift& a);
	void validate();
	void execute(int numOfArmies, Territory& from, Territory& to);
};

class Negotiate : public Order {
	Player& targetPlayer;
public:
	Negotiate();
	Negotiate(Player&);
	virtual ~Negotiate();
	Negotiate(const Negotiate& n);
	Negotiate& operator=(const Negotiate& n);
	void validate();
	void execute(Player& targetPlayer);
};