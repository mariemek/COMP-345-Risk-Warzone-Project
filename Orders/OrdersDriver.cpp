#include <iostream>
#include <string>
#include "Orders.hpp"
#include "../Map/Map.h"

using namespace std;

int main()
{
	string* na = new string("North America");
	string* ca = new string("Canada");
	string* us = new string("United States");
	Player* p1 = new Player();
	Player* p2 = new Player();
	Continent* northAmerica = new Continent(*na);
	Territory* canada = new Territory(*ca, northAmerica);
	Territory* unitedStates = new Territory(*us, northAmerica);


	OrderList* o = new OrderList();

	Deploy* deploy = new Deploy(*p1, 1, *canada);
	Advance* advance = new Advance(*p1, 1, *canada, *unitedStates);
	


	return 0;
} 