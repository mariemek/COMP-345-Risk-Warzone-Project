#include <iostream>
#include <string>
#include "Orders.hpp"

using namespace std;

int main()
{
	OrderList* o = new OrderList;

	Deploy* d = new Deploy;

	o->list.push_back(d);

	string* temp = o->list.at(0)->getClassName();
	cout << *temp;

	o->remove(0);

	
	
	return 0;
} 