#include "Orders.hpp"





Order::Order() // Order Constructor
{	
	cout << "Making an Order\n";
	Order::className = new string("Order");
}
Order::~Order()
{
	cout << "Destroying an Order";
}

bool Order::getValidity() // Accessor method
{
	return validity;
}

string* Order::getClassName() // Accessor method
{
	return className;
}

ostream& operator<<(ostream& strm, Order& o)
{
	return strm << *o.className;
}

OrderList::OrderList()
{
	cout << "Making an OrderList\n";
}


void OrderList::move(int from, int to)
{
	Order* temp = list.at(from);
	if (from < to)
	{
		for (int i = from; i <= to; i++)
		{
			list.at(i) = list.at(i+1);
		}
		list.at(to) = temp;
	}
	else if (from > to)
	{
		for (int i = from; i >= to; i--)
		{
			list.at(i) = list.at(i-1);
		}
		list.at(to) = temp;
	}
	else if (from == to)
	{
		cout << "Invalid Move" << endl;
	}
	

}

void OrderList::remove(int position)
{
	Order* temp = list.at(position);
	delete (temp);
	temp = NULL;
	list.erase(list.begin() + position);
}

Deploy::Deploy()
{
	Deploy::className = new string("Deploy");
}

void Deploy::execute(int numOfArmies, Territory* location)
{
}

Advance::Advance()
{
	Advance::className = new string("Advance");
}

void Advance::execute(int numOfArmies, Territory* from, Territory* to)
{
}

Bomb::Bomb()
{
	Bomb::className = new string("Bomb");
}

void Bomb::execute(Territory* location)
{
}

Blockade::Blockade()
{
	Blockade::className = new string("Blockade");
}

void Blockade::execute(Territory* location)
{
}

Airlift::Airlift()
{
	Airlift::className = new string("Airlift");
}

void Airlift::execute(int numOfArmies, Territory* from, Territory* to)
{
}

Negotiate::Negotiate()
{
	Negotiate::className = new string("Negotiate");
}

void Negotiate::execute(string targetPlayer)
{
}
