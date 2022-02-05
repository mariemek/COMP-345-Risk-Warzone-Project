// Warzone.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <vector>
#include <list>
#include "Map.h"
using namespace std;

int main()
{
    Vertex v1;
    Vertex v2;
    Vertex v3;
    Territory t("Congo", "Africa", new Player(), 20);
    Territory t2("Mozambie", "Africa", new Player(), 12);
    Territory t3("Quebec", "North", new Player(), 4);
    v1.setTerritory(&t);
    v1.setId(1);
    v2.setTerritory(&t2);
    v2.setId(2);
    v3.setId(3);
    v3.setTerritory(&t3);

   // cout << "Edge test: " << endl;
   // Edge g1(3);
   // v1.edgeL.push_back(g1);
   // cout << v1.getEdgeList().begin()->getIdToNext();


    Map m;
    m.addVertex(v1);
    m.addVertex(v2);
    m.addVertex(v3);


    m.addEdge(v1.getId(), v2.getId());
    m.addEdge(v1.getId(), v3.getId());
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

//Checks if the vertex is already in the vector

bool Map::vertexAlreadyExist(int vertexId) {
    for (int i = 0; i < getVertices().size(); i++ ) {
        if (getVertices().at(i).getId() == vertexId) {
            return true;
        }
    }
    return false;
}
 
//Adds a new vertex to the map

void Map::addVertex(Vertex newVertex) {
    bool check = vertexAlreadyExist(newVertex.getId()); // checks if the vertex is already there
    if (check == true) {
        cout << "This territory already exists" << endl;
    }
    else { // push the vertex in the vector
        vertices.push_back(newVertex);
        cout << "Territory has been added to the map" << endl;
    }
}

//Checks if an edge from two vertex exists already

bool Map::edgeAlreadyExist(int idFromV, int idToV) {
    Vertex temp = getVertexById(idFromV); //get the vertex from its id
    list<Edge> aEdge;  //create an edge list
    aEdge = temp.getEdgeList(); // assign the vertex edgelist
    for (auto itEdge = aEdge.begin(); itEdge != aEdge.end(); itEdge++) { //iterate through the edge list to see if the id to the vertex is the same as in the edge list
        if (itEdge->getIdToNext() == idToV) {
            return true;
            break;
        }
    }
    return false;
}

// Add an edge between to vertices (adds automatically in both way because undirected graph)

void Map::addEdge(int idFromV, int idToV) {
   bool check_IdFromV = vertexAlreadyExist(idFromV);  // checks if both vertex already exists
   bool check_IdToV = vertexAlreadyExist(idToV);
   if (check_IdFromV && check_IdToV) {
    bool  checkEdge = edgeAlreadyExist(idFromV, idToV); //checks if an edge between the vertices already exists
    if (checkEdge) {
        cout << " EDGE already exist between " << getVertexById(idFromV).getTerritory()->getTerritoryN() << " and " << getVertexById(idToV).getTerritory()->getTerritoryN() << endl;
    }
    else {
        for (int i = 0; i < getVertices().size(); i++) {  // iterates through the vector until a vertex has the same id as the IdFrom
            if (getVertices().at(i).getId() == idFromV) {
                Edge e(idToV);
                vertices.at(i).edgeL.push_back(e);  //pushes the edge into its edgelist
               
            }
            else if (getVertices().at(i).getId() == idToV) { //iterates through the vector until a vertex has the same id as the IdTo
                Edge e(idFromV);
                vertices.at(i).edgeL.push_back(e); // pushes the edge into its edgelist
               
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

//Prints the graph as vertices with their edgelist (where they point to)

void Map::printGraph() {
    for (int i = 0; i < getVertices().size(); i++) {
        Vertex v1;
        v1 = getVertices().at(i);
        cout << v1.getTerritory()->getTerritoryN() << " (" << v1.getId() << ") --> " << endl;
        v1.printEdgeList();
    }
}

//Print all the edges where it points to connected vertices

void Vertex::printEdgeList() {
    cout << "[";
    for (auto it = edgeL.begin(); it != edgeL.end(); it++) {
        cout << it->getIdToNext() << "--> ";
    }
    cout << "]";
    cout << endl;
}
