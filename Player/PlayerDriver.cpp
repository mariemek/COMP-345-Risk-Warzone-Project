#include "../Map/MapLoader.h"
#include "Player.h"

int main() {
	Map& map = MapLoader::createMap("solar.map");

	Continent* continent = map.continents[0];

	Player player("Michael");

	// Insert all of the territories of the first continent into the player's set.
	for (Territory* territory : continent->territories) {
		player.territories.insert(territory);
		territory->owner = &player;
	}
		

	cout << "All of the player's territories are:\n";

	for (Territory* territory : player.territories)
		cout << "\t" << territory->name << endl;

	cout << endl << "All of the player's territories to attack are:\n";

	vector<Territory*>& toattack = player.toAttack();

	for (Territory* territory : toattack)
		cout << "\t" << territory->name << endl;

	cout << endl << "All of the player's territories to defend are:\n";

	vector<Territory*>& todefend = player.toDefend();

	for (Territory* territory : todefend)
		cout << "\t" << territory->name << endl;


	cin.get();
}