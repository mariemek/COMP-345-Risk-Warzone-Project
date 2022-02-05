// Warzone.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include "Map.h"
using namespace std;

int main()
{
    Vertex v1;
    Territory t("Congo", "Africa", new Player(), 20);
    v1.setTerritory(&t);
    v1.setId(1);
    Map m;
    m.addVertex(v1);
}



Player::Player() {
    name = "No name";
}

Player::Player(string Tname) {
    name = Tname;
}

Player::~Player() {

}




Territory::Territory() {
    territoryN = "Default Territory";
    continent = "Default Continent";
    owner = new Player();
    nbOfArmy = 0;
}

Territory::Territory(string name, string cName, Player* tOwner, int army) {
    territoryN = name;
    continent = cName;
    owner = tOwner;
    nbOfArmy = army;
}

Territory::~Territory() {
    owner = NULL;
}

Edge::Edge() {
    idToNext = 0;
}

Edge::Edge(int id) {
    idToNext = id;
}

Edge::~Edge() {

}

Vertex::Vertex() {
    id = 0;
    territory = new Territory();
}

Vertex::Vertex(int tId, Territory* terr) {
    id = tId;
    territory = terr;
}

Vertex::~Vertex() {
    territory = NULL;
}


bool Map::vertexAlreadyExist(int vertexId) {
    for (int i = 0; i < getVertices().size(); ) {
        if (getVertices().at(i).getId() == vertexId) {
            return true;
        }
    }
    return false;
}
 

void Map::addVertex(Vertex newVertex) {
    bool check = vertexAlreadyExist(newVertex.getId());
    if (check == true) {
        cout << "This territory already exists" << endl;
    }
    else {
        vertices.push_back(newVertex);
        cout << "Territory has been added to the map" << endl;
    }
}