using namespace std;
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
class Player { //temporary declaration
private:
	string name;
public:
	Player();
	Player(string);
	~Player(); //destructor


	string inline getName() {
		return name;
	} 
	//get the name 
	void inline setName(string tName) {
		name = tName;
	} //mutator
};


class Territory { //declaration of the territory class
private:
	string territoryN, continent; //name of the territory and continent
	Player* owner; // pointer to the owner of this territory
	int nbOfArmy; // the number of army in the territory

public:
	Territory();
	Territory(string, string, Player*, int); 
	~Territory();//destructor

	//Accessor method
	string inline getTerritoryN() {
		return territoryN;
	}
	string inline getContinent() {
		return continent;
	}
	inline Player* getOwner() {
		return owner;
	}
	int inline getArmy() {
		return nbOfArmy;
	}

	//Mutator Method
	void inline setTerritoryN(string tName) {
		territoryN = tName;
	}
	void inline setContinent(string cName) {
		continent = cName;
	}
	void inline setOwner(Player* player) {
		owner = player;
	}
	void inline setArmy(int armies) {
		nbOfArmy = armies;
	}
};

//For the graph we are doing an adjency list structure
// It will be a vector of vertices
//We will create a vertex class which contains a pointer to the territory that represents it as well as an id and a list of edges that connects to other vertices
// Then we will create an edge class which will link two vertices together, it will contain only the id of the territory it points to
//The Map class represents the graph class that will add vertices and edges together 


class Edge { //declaration of the edge class

private:
	int idToNext;
public:

	Edge();
	Edge(int);
	~Edge(); // destructor

	int inline getIdToNext() {
		return idToNext;
	} //accessor

	void inline setIdToNext(int tId) {
		idToNext = tId;
	} // mutator


};

class Vertex { //declaration of the vertex class
private:
	int id;
	Territory* territory;
	list<Edge> edgeL;


public: 
	Vertex();
	Vertex(int, Territory*);
	~Vertex(); //destructor

	//Accessor
	int inline getId() {
		return id;
	}

	inline Territory* getTerritory() {
		return territory;
	}

	inline list<Edge> getEdgeList() {
		return edgeL;
	}

	//Mutator

	void inline setId(int id) {
		this->id = id;
	}
	void inline setTerritory(Territory* t) {
		territory = t;
	}
	
	void printEdgeList() {
		cout << "[";
		for (auto it = edgeL.begin(); it != edgeL.end(); it++) {
			cout << it->getIdToNext() << "--> ";
		}
		cout << "]";
		cout << endl;
	}
	


};
class Map { //declaration of the map
private:
	 
	vector<Vertex> vertices;

public:
	vector<Vertex> getVertices() {
		return vertices;
	}

	void addVertex(Vertex);
	bool vertexAlreadyExist(int vertexId);
	void addEdge(int idFromV, int idToV);
	bool edgeAlreadyExist(int, int);
	Vertex getVertexById(int);
	void printGraph();
	
	
};