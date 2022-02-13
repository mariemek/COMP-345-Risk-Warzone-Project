#include "Orders.hpp"

// Method, Constructor, and Operator implementation

	class Continent;
	class Territory;

Order::Order()										// Order Method Implementations
{	
	cout << "Making an Order\n";
	Order::className = new string("Order");
	Order::validity = new bool(false);
}
Order::~Order()
{
	cout << "Destroying an Order" << endl;
	delete (className);
	delete (validity);
	className = NULL;
	validity = NULL;
}

Order::Order(const Order& o) 
{
	cout << "Copying an Order" << endl;
	this->validity = new bool(*(o.validity));
	this->className = new string(*(o.className));
}

Order& Order::operator =(const Order& o) 
{
	this->validity = new bool(*(o.validity));
	this->className = new string(*(o.className));
	return *this;
}

bool& Order::getValidity()							
{
	return *validity;
}

string& Order::getClassName()						
{
	return *className;
}

ostream& operator<<(ostream& strm, Order& o)			// Free stream insertion implementation
{
	return strm << "Order Type: " << *o.className;
}

OrderList::OrderList()							// OrderList Method Implementations
{
	cout << "Making an OrderList\n";
}


void OrderList::move(int from, int to)
{
	if (from < list.size() && from >= 0 && to < list.size() && to >= 0) {
		Order* temp = list.at(from);
		if (from < to)
		{
			for (int i = from; i <= to; i++)
			{
				list.at(i) = list.at(i + 1);
			}
			list.at(to) = temp;
			temp = NULL;
		}
		else if (from > to)
		{
			for (int i = from; i >= to; i--)
			{
				list.at(i) = list.at(i - 1);
			}
			list.at(to) = temp;
		}
		else
		{
			cout << "Invalid Move" << endl;
		}
	}
}

void OrderList::remove(int position)
{
	if (position < list.size() && position >= 0) {
		Order* temp = list.at(position);
		delete (temp);
		temp = NULL;
		list.erase(list.begin() + position);
	}
	else
	{
		cout << "Invalid Move" << endl;
	}
}

OrderList::~OrderList()
{
	cout << "Destroying an OrderList" << endl;
	if (!list.empty())
	{
		for (int i = 0; i < list.size(); i++)
		{
			Order* temp = list.at(0);
			delete (temp);
			temp = NULL;
			list.erase(list.begin());
		}
	}
}

OrderList::OrderList(const OrderList& o)
{
	cout << "Copying an OrderList" << endl;
	this->list = o.list;
}

OrderList& OrderList::operator=(const OrderList& o)
{
	this->list = o.list;
	return *this;
}

Deploy::Deploy(Player& issuingPlayer, int numOfArmies, Territory& location) : Order(), issuingPlayer(issuingPlayer), numOfArmies(numOfArmies), location(location)
{
	cout << "Making a Deploy" << endl;
	delete (className);
	className = NULL;
	Deploy::className = new string("Deploy");
}

void Deploy::validate()
{
	cout << "Validating Deploy Order..." << endl;
}

void Deploy::execute(Player& issuingPlayer, int numOfArmies, Territory& location)
{
	Deploy::validate();
	cout << "Executing Deploy..." << endl;
}

Deploy::~Deploy()
{
	cout << "Destroying a Deploy" << endl;
	delete (className);
	delete (validity);
	className = NULL;
	validity = NULL;
}

Deploy::Deploy(const Deploy& d) : Order(d), issuingPlayer(d.issuingPlayer), numOfArmies(d.numOfArmies), location(d.location)
{
	cout << "Copying a Deploy" << endl;
	delete (className);
	className = NULL;
	this->className = new string(*(d.className));
}

Deploy& Deploy::operator=(const Deploy& d)
{
	Order::operator =(d);
	delete (className);
	className = NULL;
	this->className = new string(*(d.className));
	this->issuingPlayer = d.issuingPlayer;
	this->numOfArmies = d.numOfArmies;
	this->location = d.location;
	return *this;
}

Advance::Advance(Player& issuingPlayer, int numOfArmies, Territory& to, Territory& from) : Order(), issuingPlayer(issuingPlayer), numOfArmies(numOfArmies), to(to), from(from)
{
	cout << "Making an Advance" << endl;
	delete (className);
	className = NULL;
	Advance::className = new string("Advance");
}

void Advance::validate()
{
	cout << "Validating Advance Order..." << endl;
}

void Advance::execute(Player& issuingPlayer, int numOfArmies, Territory& from, Territory& to)
{
	Advance::validate();
	cout << "Executing Advance..." << endl;
}

Advance::~Advance()
{
	cout << "Destroying an Advance" << endl;
}

Advance::Advance(const Advance& a) : Order(a), issuingPlayer(a.issuingPlayer), numOfArmies(a.numOfArmies), to(a.to), from(a.from)
{
	cout << "Copying an Advance" << endl;
	delete (className);
	className = NULL;
	this->className = new string(*(a.className));
}

Advance& Advance::operator=(const Advance& a)
{
	Order::operator =(a);
	delete (className);
	className = NULL;
	this->className = new string(*(a.className));
	this->issuingPlayer = a.issuingPlayer;
	this->numOfArmies = a.numOfArmies;
	this->to = a.to;
	this->from = a.from;
	return *this;
}

Bomb::Bomb(Player& issuingPlayer, Territory& location) : Order(), issuingPlayer(issuingPlayer), location(location)
{
	cout << "Making a Bomb" << endl;
	delete (className);
	className = NULL;
	Bomb::className = new string("Bomb");
}

Bomb::~Bomb()
{
	cout << "Destroying a Bomb" << endl;
}

Bomb::Bomb(const Bomb& b) : Order(b), issuingPlayer(b.issuingPlayer), location(b.location)
{
	cout << "Copying an Bomb" << endl;
	delete (className);
	className = NULL;
	this->className = new string(*(b.className));
}

Bomb& Bomb::operator=(const Bomb b)
{
	Order::operator =(b);
	delete (className);
	className = NULL;
	this->className = new string(*(b.className));
	this->issuingPlayer = b.issuingPlayer;
	this->location = b.location;
	return *this;
}

void Bomb::validate()
{
	cout << "Validating Deploy Order..." << endl;
}

void Bomb::execute(Player& issuingPlayer, Territory& location)
{
	Bomb::validate();
	cout << "Executing Bomb..." << endl;
}

Blockade::Blockade(Player& issuingPlayer, Territory& location) : Order(), issuingPlayer(issuingPlayer), location(location)
{
	cout << "Making a Blockade" << endl;
	delete (className);
	className = NULL;
	Blockade::className = new string("Blockade");
}

Blockade::~Blockade()
{
	cout << "Destroying a Blockade" << endl;
}

void Blockade::validate()
{
	cout << "Validating Blockade Order..." << endl;
}

void Blockade::execute(Player& issuingPlayer, Territory& location)
{
	Blockade::validate();
	cout << "Executing Blockade..." << endl;
}

Blockade::Blockade(const Blockade& b) : Order(b), issuingPlayer(b.issuingPlayer), location(b.location)
{
	cout << "Copying a Blockade" << endl;
	delete (className);
	className = NULL;
	this->className = new string(*(b.className));
}

Blockade& Blockade::operator=(const Blockade& b)
{
	Order::operator =(b);
	delete (className);
	className = NULL;
	this->className = new string(*(b.className));
	this->issuingPlayer = b.issuingPlayer;
	this->location = b.location;
	return *this;
}

Airlift::Airlift(Player& issuingPlayer, int numOfArmies, Territory& from, Territory& to) : Order(), issuingPlayer(issuingPlayer), numOfArmies(numOfArmies), to(to), from(from)
{
	cout << "Making an Airlift" << endl;
	delete (className);
	className = NULL;
	Airlift::className = new string("Airlift");
}

void Airlift::validate()
{
	cout << "Validating Airlift Order..." << endl;
}

void Airlift::execute(Player& issuingPlayer, int numOfArmies, Territory& from, Territory& to)
{
	Airlift::validate();
	cout << "Executing Airlift..." << endl;
}

Airlift::~Airlift()
{
	cout << "Destroying an Airlift" << endl;
}

Airlift::Airlift(const Airlift& a) : Order(a), issuingPlayer(a.issuingPlayer), numOfArmies(a.numOfArmies), to(a.to), from(a.from)
{
	cout << "Copying an Airlift" << endl;
	delete (className);
	className = NULL;
	this->className = new string(*(a.className));
}

Airlift& Airlift::operator=(const Airlift& a)
{
	Order::operator =(a);
	delete (className);
	className = NULL;
	this->className = new string(*(a.className));
	this->issuingPlayer = a.issuingPlayer;
	this->numOfArmies = a.numOfArmies;
	this->to = a.to;
	this->from = a.from;
	return *this;
}

Negotiate::Negotiate(Player& issuingPlayer, Player& targetPlayer) : Order(), issuingPlayer(issuingPlayer), targetPlayer(targetPlayer)
{
	cout << "Making a Negotiate" << endl;
	delete (className);
	className = NULL;
	Negotiate::className = new string("Negotiate");
}

Negotiate::~Negotiate()
{
	cout << "Destroying a Negotiate" << endl;
}

Negotiate::Negotiate(const Negotiate& n) : Order(n), issuingPlayer(n.issuingPlayer), targetPlayer(n.targetPlayer)
{
	cout << "Copying a Negotiate" << endl;
	delete (className);
	className = NULL;
	this->className = new string(*(n.className));
}

Negotiate& Negotiate::operator=(const Negotiate& n)
{
	Order::operator =(n);
	delete (className);
	className = NULL;
	this->className = new string(*(n.className));
	this->issuingPlayer = n.issuingPlayer;
	this->targetPlayer = n.targetPlayer;
	return *this;
}

void Negotiate::validate()
{
	cout << "Validating Negotiate Order..." << endl;
}

void Negotiate::execute(Player& issuingPlayer, Player& targetPlayer)
{
	Negotiate::validate();
	cout << "Executing Negotiate..." << endl;
}
