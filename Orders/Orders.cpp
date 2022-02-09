#include "Orders.hpp"


Order::Order() // Order Constructor
{
	*validity = false;
}

bool* Order::getValidity() // Accessor method
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

void Deploy::execute(int numOfArmies, Territory* location)
{
}

void Advance::execute(int numOfArmies, Territory* from, Territory* to)
{
}

void Bomb::execute(Territory* location)
{
}

void Blockade::execute(Territory* location)
{
}

void Airlift::execute(int numOfArmies, Territory* from, Territory* to)
{
}

void Negotiate::execute(string targetPlayer)
{
}
