// Create a finite state machine for the game engine 
//Create an enum that represents the different possible states
//For each state create a function with the name of the state that is being call when the user wants to transition to that state
//always set the currentstate after executing the function

//*****OR*****
//State are classes inherited from general State class
//a variable contains the current state(like an enum)
//When player calls a command, it will point to the right state class and execute the run method of  the class which will do the work in the state.
//When the run method is done, to do a transition, player needs to enter command prompt that will change the variable of the currentstate and point to the next one


enum currentStates{
    START,MAP_LOADED, MAP_VALIDATED,PLAYERS_ADDED,ASSIGN_REINFORCEMENT,ISSUE_ORDERS,EXECUTE_ORDERS,WIN
};


class State{

private:
    currentStates current;

public:
    State(currentStates currentState);
    State();
    ~State();

    void run();
    void setCurrentState(currentStates);
    currentStates getCurrentState();

};

class Start: public State{

};

class Map_Loaded: public State{

};

class Map_Validated: public State{

};

class Player_Added :  public State{

};

class Assign_Reinforcement: public State{

};

class Issue_Orders: public State{

};

class Execute_Orders: public State{

};

class Win: public State{

};