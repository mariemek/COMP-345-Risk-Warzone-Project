#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Game Engine/GameEngine.h"
#include <string>

int main() {
	LogObserver* logger = new LogObserver();

	// show Command, CommandProcessor logging later

	// ----- Order/OrderList test -----
	string* na = new string("North America");
	string* ca = new string("Canada");
	string* us = new string("United States");
	Player* p1 = new Player("Michael");
	p1->orderList->attach(logger);
	Player* p2 = new Player("William");
	Continent* northAmerica = new Continent(*na);
	Territory* canada = new Territory(*ca, northAmerica);
	Territory* unitedStates = new Territory(*us, northAmerica);

	Deploy* deploy = new Deploy(p1, 1, canada);
	deploy->attach(logger);

	Advance* advance = new Advance(p1, 1, canada, unitedStates);
	advance->attach(logger);

	Bomb* bomb = new Bomb(p1, canada);
	bomb->attach(logger);

	Blockade* blockade = new Blockade(p1, canada);
	blockade->attach(logger);

	Airlift* airlift = new Airlift(p1, 1, canada, unitedStates);
	airlift->attach(logger);

	Negotiate* negotiate = new Negotiate(p1, p2);
	negotiate->attach(logger);

	p1->orderList->add(deploy);
	deploy = NULL;
	p1->orderList->add(advance);
	advance = NULL;
	p1->orderList->add(bomb);
	bomb = NULL;
	p1->orderList->add(blockade);
	blockade = NULL;
	p1->orderList->add(airlift);
	airlift = NULL;
	p1->orderList->add(negotiate);
	negotiate = NULL;
	p1->orderList->list.front()->execute();

	// ----- GameEngine Test -----
	GameEngine* g = new GameEngine();
	g->attach(logger);
	g->start();
}
