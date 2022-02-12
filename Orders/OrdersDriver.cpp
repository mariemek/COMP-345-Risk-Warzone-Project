#include <iostream>
#include <string>
#include "Orders.hpp"

using namespace std;

int main()
{

	
	//while (true) {
	Player* player = new Player;
	player->issueOrder(player->DEPLOY, 0, NULL, NULL, NULL);

		OrderList* o = new OrderList;
		//Order* o = new Order;
		Deploy* d = new Deploy;
		Advance* a = new Advance;

		Deploy* d2 = new Deploy(*d);
		
		o->list.push_back(d);
		o->list.push_back(a);
		o->list.push_back(d2);

		////string* temp = o->list.at(0)->getClassName();
		////cout << *temp << temp << endl;
		cout << *d << endl << *a << endl;

		o->remove(0);
		o->remove(0);


		cout << typeid(*o->list.at(0)).name() << endl;
		cout << *o->list.at(0) << endl;
		o->remove(0);
		delete (o);
		o = NULL;
	//}


	return 0;
} 