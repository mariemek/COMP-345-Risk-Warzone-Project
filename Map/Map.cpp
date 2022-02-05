// Warzone.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include "Map.h"
using namespace std;

int main()
{
    Vertex v1;
    Vertex v2;
    Territory t("Congo", "Africa", new Player(), 20);
    Territory t2("Mozambie", "Africa", new Player(), 12);
    v1.setTerritory(&t);
    v1.setId(1);
    v2.setTerritory(&t2);
    v2.setId(2);
    Map m;
    m.addVertex(v1);
    m.addVertex(v2);
    m.addEdge(v1.getId(), v2.getId());
    m.printGraph();
    
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
    for (int i = 0; i < getVertices().size(); i++ ) {
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

bool Map::edgeAlreadyExist(int idFromV, int idToV) {
    Vertex temp = getVertexById(idFromV);
    list<Edge> aEdge;
    aEdge = temp.getEdgeList();
    for (auto itEdge = aEdge.begin(); itEdge != aEdge.end(); itEdge++) {
        if (itEdge->getIdToNext() == idToV) {
            return true;
            break;
        }
    }
    return false;
}

void Map::addEdge(int idFromV, int idToV) {
   bool check_IdFromV = vertexAlreadyExist(idFromV);
   bool check_IdToV = vertexAlreadyExist(idToV);
   if (check_IdFromV && check_IdToV) {
    bool  checkEdge = edgeAlreadyExist(idFromV, idToV);
    if (checkEdge) {
        cout << " EDGE already exist between " << getVertexById(idFromV).getTerritory()->getTerritoryN() << " and " << getVertexById(idToV).getTerritory()->getTerritoryN() << endl;
    }
    else {
        for (int i = 0; i < getVertices().size(); i++) {
            if (getVertices().at(i).getId() == idFromV) {
                Edge e(idToV);
                getVertices().at(i).getEdgeList().push_back(e);
               
            }
            else if (getVertices().at(i).getId() == idToV) {
                Edge e(idFromV);
                getVertices().at(i).getEdgeList().push_back(e);
               
            }
        }
        cout << "Edge added successfully between " << getVertexById(idFromV).getTerritory()->getTerritoryN() << " and " << getVertexById(idToV).getTerritory()->getTerritoryN() << endl;
    }
   }
   else {
       cout << "Invalid Vertex ID entered" << endl;
   }
}

Vertex Map::getVertexById(int vertexId) {
    for (int i = 0; i < getVertices().size(); i++) {
        if (getVertices().at(i).getId() == vertexId) {
            return getVertices().at(i);
        }
    }
}

void Map::printGraph() {
    for (int i = 0; i < getVertices().size(); i++) {
        Vertex v1;
        v1 = getVertices().at(i);
        cout << v1.getTerritory()->getTerritoryN() << " (" << v1.getId() << ") --> " << endl;
        v1.printEdgeList();
    }
}
