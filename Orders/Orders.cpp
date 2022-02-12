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

Deploy::Deploy(int numOfArmies, Territory& location) : Order(), numOfArmies(numOfArmies), location(location)
{
	cout << "Making a Deploy" << endl;
	delete (className);
	className = NULL;
	Deploy::className = new string("Deploy");
}

void Deploy::execute(int numOfArmies, Territory& location)
{

}

Deploy::~Deploy()
{
	cout << "Destroying a Deploy" << endl;
	delete (className);
	delete (validity);
	className = NULL;
	validity = NULL;
}

Deploy::Deploy(const Deploy& d) : Order(d), numOfArmies(d.numOfArmies), location(d.location)
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
	this->numOfArmies = d.numOfArmies;
	this->location = d.location;
	return *this;
}

Advance::Advance(int numOfArmies, Territory& to, Territory& from) : Order(), numOfArmies(numOfArmies), to(to), from(from)
{
	cout << "Making an Advance" << endl;
	delete (className);
	className = NULL;
	Advance::className = new string("Advance");
}

void Advance::execute(int numOfArmies, Territory& from, Territory& to)
{
}

Advance::~Advance()
{
	cout << "Destroying an Advance" << endl;
}

Advance::Advance(const Advance& a) : Order(a), numOfArmies(a.numOfArmies), to(a.to), from(a.from)
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
	this->numOfArmies = a.numOfArmies;
	this->to = a.to;
	this->from = a.from;
	return *this;
}

Bomb::Bomb(Territory& location) : Order(), location(location)
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

Bomb::Bomb(const Bomb& b) : Order(b), location(b.location)
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
	this->location = b.location;
	return *this;
}

void Bomb::execute(Territory& location)
{
}

Blockade::Blockade(Territory& location) : Order(), location(location)
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

void Blockade::execute(Territory* location)
{
}

Blockade::Blockade(const Blockade& b) : Order(b), location(b.location)
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
	this->location = b.location;
	return *this;
}

void Blockade::execute(Territory& location)
{
}

Airlift::Airlift(int numOfArmies, Territory& from, Territory& to) : Order(), numOfArmies(numOfArmies), to(to), from(from)
{
	cout << "Making an Airlift" << endl;
	delete (className);
	className = NULL;
	Airlift::className = new string("Airlift");
}

void Airlift::execute(int numOfArmies, Territory& from, Territory& to)
{
}

Airlift::~Airlift()
{
	cout << "Destroying an Airlift" << endl;
}

Airlift::Airlift(const Airlift& a) : Order(a), numOfArmies(a.numOfArmies), to(a.to), from(a.from)
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
	this->numOfArmies = a.numOfArmies;
	this->to = a.to;
	this->from = a.from;
	return *this;
}

Negotiate::Negotiate(Player& targetPlayer) : Order(), targetPlayer(targetPlayer)
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

Negotiate::Negotiate(const Negotiate& n) : Order(n), targetPlayer(n.targetPlayer)
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
	this->targetPlayer = n.targetPlayer;
	return *this;
}

void Negotiate::execute(Player& targetPlayer)
{
}
