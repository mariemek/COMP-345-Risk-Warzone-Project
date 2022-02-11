// Create a finite state machine for the game engine 
//Create an enum that represents the different possible states
//For each state create a function with the name of the state that is being call when the user wants to transition to that state
//always set the currentstate after executing the function

//*****OR*****
//State are classes inherited from general State class
//a variable contains the current state(like an enum)
//When player calls a command, it will point to the right state class and execute the run method of  the class which will do the work in the state.
//When the run method is done, to do a transition, player needs to enter command prompt that will change the variable of the currentstate and point to the next one


//create an enum variable to keep track of the current state in the switch statement





//create a function pointer to other functions which acts like states

//void (*state)();

#include<iostream>
using namespace std;

class GameEngine{

private:
    enum currentStates{
    START,MAP_LOADED, MAP_VALIDATED,PLAYERS_ADDED,ASSIGN_REINFORCEMENT,ISSUE_ORDERS,EXECUTE_ORDERS,WIN
};

public:

    GameEngine(const GameEngine &game1);
    GameEngine& operator =(const GameEngine&);
    ~GameEngine();

     friend ostream & operator << (ostream &out, const GameEngine &g);
    friend istream & operator >> (istream &in,  GameEngine &g);

    void start();
    void mapLoaded();
    void mapValidated();
    void playersAdded();
    void assignReinforcement();
    void issueOrders();
    void executeOrders();
    void win();
};



