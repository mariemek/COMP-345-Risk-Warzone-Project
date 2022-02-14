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
	Player* issuingPlayer;
	int numOfArmies;
	Territory* location;
public:
	Deploy(Player*, int, Territory*);
	virtual ~Deploy();
	Deploy(const Deploy& d);
	Deploy& operator=(const Deploy& d);
	void validate();
	void execute(Player*, int numOfArmies, Territory* location);
};

class Advance : public Order {
	Player* issuingPlayer;
	int numOfArmies;
	Territory* to;
	Territory* from;
public:
	Advance(Player*, int, Territory*, Territory*);
	virtual ~Advance();
	Advance(const Advance& a);
	Advance& operator=(const Advance& a);
	void validate();
	void execute(Player*, int numOfArmies, Territory* to, Territory* from);
};

class Bomb : public Order {
	Player* issuingPlayer;
	Territory* location;
public:
	Bomb(Player*, Territory*);
	virtual ~Bomb();
	Bomb(const Bomb& b);
	Bomb& operator=(const Bomb b);
	void validate();
	void execute(Player*, Territory* location);
};

class Blockade : public Order {
	Player* issuingPlayer;
	Territory* location;
public:
	Blockade();
	Blockade(Player*, Territory*);
	virtual ~Blockade();
	Blockade(const Blockade& b);
	Blockade& operator=(const Blockade& b);
	void validate();
	void execute(Player*, Territory* location);
};

class Airlift : public Order {
	Player* issuingPlayer;
	int numOfArmies;
	Territory* to;
	Territory* from;
public:
	Airlift();
	Airlift(Player*, int, Territory*, Territory*);
	virtual ~Airlift();
	Airlift(const Airlift& a);
	Airlift& operator=(const Airlift& a);
	void validate();
	void execute(Player*, int numOfArmies, Territory* from, Territory* to);
};

class Negotiate : public Order {
	Player* issuingPlayer;
	Player* targetPlayer;
public:
	Negotiate();
	Negotiate(Player*, Player*);
	virtual ~Negotiate();
	Negotiate(const Negotiate& n);
	Negotiate& operator=(const Negotiate& n);
	void validate();
	void execute(Player*, Player* targetPlayer);
};