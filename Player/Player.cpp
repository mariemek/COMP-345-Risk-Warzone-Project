#include "Player.h"

Player::Player()
{
	orderList = new OrderList();
}

Player::~Player()
{
	delete (orderList);
	orderList = NULL;
	cout << "Destroying a Player" << endl;
}

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

void Player::issueOrder(orderTypes o, Player* issuingPlayer, Territory* location)
{
	switch (o)
	{
	case BOMB: {
		Bomb* bomb = new Bomb(issuingPlayer, location);
		orderList->list.push_back(bomb);
	}
			 break;
	case BLOCKADE: {
		Blockade* blockade = new Blockade(issuingPlayer, location);
		orderList->list.push_back(blockade);
	}
				 break;
	default: cout << "Invalid Order issued";
		break;
	}
}

void Player::issueOrder(orderTypes o, Player* issuingPlayer, int numOfArmies, Territory* location)
{
	switch (o)
	{
	case DEPLOY: {
		Deploy* deploy = new Deploy(issuingPlayer, numOfArmies, location);
		orderList->list.push_back(deploy);
	}
			   break;
	default: cout << "Invalid Order issued";
		break;
	}
}

void Player::issueOrder(orderTypes o, Player* issuingPlayer, int numOfArmies, Territory* to, Territory* from)
{

	switch (o)
	{
	case ADVANCE: {
		Advance* advance = new Advance(issuingPlayer, numOfArmies, to, from);
		orderList->list.push_back(advance);
	}
				break;
	case AIRLIFT: {
		Airlift* airlift = new Airlift(issuingPlayer, numOfArmies, to, from);
		orderList->list.push_back(airlift);
	}
				break;
	default: cout << "Invalid Order issued";
		break;
	};
}

void Player::issueOrder(orderTypes o, Player* issuingPlayer, Player* targetPlayer)
{
	switch (o)
	{
	case NEGOTIATE: {
		Negotiate* negotiate = new Negotiate(issuingPlayer, targetPlayer);
		orderList->list.push_back(negotiate);
	}
				  break;
	default: cout << "Invalid Order issued";
		break;
	}
}
