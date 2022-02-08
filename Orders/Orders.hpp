#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// ------------------------------------------------------------
// Declaration of OrdersList, Order and all subclasses of Order
// ------------------------------------------------------------

class Order {
	bool* validity;
	static string* className;
public:
	Order();
	bool* getValidity();
	string* getClassName();
	//void execute();
};

class OrderList {
	// List as a vector for dynamic resizing of List
	// List of Order objects

	vector<Order*> list;

public:
	OrderList();
	void move(int from, int to);
	void remove(int position);
};

class Deploy : public Order {
public:
	Deploy();
	void execute(int numOfArmies, string location);
};

class Advance : public Order {
public:
	Advance();
	void execute(int numOfArmies, string from, string to);
};

class Bomb : public Order {
public:
	Bomb();
	void execute(string location);
};

class Blockade : public Order {
public:
	Blockade();
	void execute(string location);
};

class Airlift : public Order {
public:
	Airlift();
	void execute(int numOfArmies, string from, string to);
};

class Negotiate : public Order {
public:
	Negotiate();
	void execute(string targetPlayer);
};