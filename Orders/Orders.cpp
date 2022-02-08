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


OrderList::OrderList()
{

}

void OrderList::move(int from, int to)
{
	Order* temp1 = list.at(from);
	if (from < to)
	{
		for (int i = from; i <= to; i++)
		{

		}
	}
	else if (from > to)
	{
		for (int i = from; i >= to; i--)
		{

		}
	}
	else if (from == to)
	{
		cout << "Invalid Move" << endl;
	}
	

}

void OrderList::remove(int position)
{
}

void Deploy::execute(int numOfArmies, string location)
{
}

void Advance::execute(int numOfArmies, string from, string to)
{
}

void Bomb::execute(string location)
{
}

void Blockade::execute(string location)
{
}

void Airlift::execute(int numOfArmies, string from, string to)
{
}

void Negotiate::execute(string targetPlayer)
{
}
