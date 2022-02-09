#include <iostream>
#include <string>
#include "Orders.hpp"

using namespace std;

int main()
{

	OrderList* o = new OrderList;
	while (true) {
		Deploy* d = new Deploy;
		Advance* a = new Advance;

		o->list.push_back(d);
		o->list.push_back(a);

		//string* temp = o->list.at(0)->getClassName();
		//cout << *temp << temp << endl;
		cout << *d << endl << *a << endl;

		o->remove(0);
		o->remove(0);

		//cout << endl << *o->list.at(0) << endl;
		//cout << *temp << temp << endl;
	}
	return 0;
} 