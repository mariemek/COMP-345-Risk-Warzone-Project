#include "Player.h"

vector<Territory*>& Player::toAttack() {
	vector<Territory*>* territoriesToAttack = new vector<Territory*>;

	// Loops on every territory that the current player owns, and checks the adjacent territories to each of them,
	// if the two aren't owned by the same player that means it is not owned by the current player and a territory you could attack.
	for (Territory* territory : territories) {
		for (Territory* adjacentTerritory : territory->adjacentTerritories) {
			if (territory->owner != adjacentTerritory->owner) {
				territoriesToAttack->push_back(adjacentTerritory);
			}
		}
	}

	return *territoriesToAttack;
}

vector<Territory*>& Player::toDefend() {
	return *(new vector<Territory*>(territories.begin(), territories.end()));
}

void Player::issueOrder(orderTypes o)
{

	switch (o)
	{
	case DEPLOY:
		Deploy* d = new Deploy();
		orderList->list.push_back(d);
		break;
	case ADVANCE:
		Advance* a = new Advance();
		orderList->list.push_back(a);
		break;
	case BOMB:
		Bomb* b = new Bomb();
		orderList->list.push_back(b);
		break;
	case BLOCKADE:
		Blockade* b = new Blockade();
		orderList->list.push_back(b);
		break;
	case AIRLIFT:
		Airlift* a = new Airlift();
		orderList->list.push_back(a);
		break;
	case NEGOTIATE:
		Negotiate* n = new Negotiate();
		orderList->list.push_back(n);
		break;
	default:
		break;
	};
}