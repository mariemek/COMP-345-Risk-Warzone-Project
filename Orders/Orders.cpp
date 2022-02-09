#include "Orders.hpp"

string* Order::className = new string("Order");

Order::Order() // Order Constructor
{	
}

bool Order::getValidity() // Accessor method
{
	return validity;
}

string* Order::getClassName() // Accessor method
{
	return className;
}


// OrderList::OrderList()
// {
	
// }

OrderList::OrderList()
{
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
	list.erase(list.begin() + position);
	delete temp;
	temp = NULL;
}

Deploy::Deploy()
{
}

void Deploy::execute(int numOfArmies, Territory* location)
{
}

Advance::Advance()
{
}

void Advance::execute(int numOfArmies, Territory* from, Territory* to)
{
}

Bomb::Bomb()
{
}

void Bomb::execute(Territory* location)
{
}

Blockade::Blockade()
{
}

void Blockade::execute(Territory* location)
{
}

Airlift::Airlift()
{
}

void Airlift::execute(int numOfArmies, Territory* from, Territory* to)
{
}

Negotiate::Negotiate()
{
}

void Negotiate::execute(string targetPlayer)
{
}
