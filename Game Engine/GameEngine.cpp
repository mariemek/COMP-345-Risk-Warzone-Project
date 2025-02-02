#include <iostream>
#include "GameEngine.h"
using namespace std;

GameEngine::GameEngine() {
    state = new currentStates(START);
}

GameEngine::GameEngine(const GameEngine &game1){
    
}

GameEngine& GameEngine::operator= (const GameEngine& game1){
    return *this;
}

GameEngine::~GameEngine(){
    delete state;
}

ostream & operator << (ostream &out, const GameEngine &g){
    return out;
}

istream & operator >> (istream &in, GameEngine &g){
    return in;
}

// Method to start the GameEngine 
void GameEngine::start(){
   
    bool gameRunning = true; //boolean to end the loop when the game ends
    cout << "Welcome to Warzone. " << endl;

    //possible commands for the users
    string choice = "\n1. Load the map\n2.Validate the map\n3.Add a player in the game\n4.Assign a country\n5.Issue an order\n6End the issues of order\n7.Execute an order\n8.End the execution of orders\n9.Win the Game\n10.Play again\n11.End the game\n";
    while (gameRunning)
    {
        // switch statement where each case represent a state where it will execute the code and ask a command from the user which determine if it stays in the same state or transition to another
        switch (*state)
        {
        case START:
            cout << "Starting the startup phase" << endl;
            cout << "Please choose from the option below.\n"
                 << endl;
            
            cout << choice;
            int option;
            cout << "Enter your choice: ";
            cin >> option;

            switch (option)
            {
            case 1:
                // go to the MapLoaded state
                *state = MAP_LOADED;
                notify(this);
                break;

            default:
                cout << "\nThis is not a valid command\n" << endl;
                break;
            }
            break;

        case MAP_LOADED:
            cout << "\nYou are in the map loaded phase\n"
                 << endl;
            // load the map
            //  game->mapLoadedPhase();
            cout << "Map has been loaded" << endl;
            // ask for the options
            cout << choice;
            cout << "Enter your choice: ";
            cin >> option;
            switch (option)
            {
            case 1:
                // load another map
                //    game->mapLoadedPhase();
                cout << "Map has been loaded" << endl;
                break;
            case 2:
                // go to validate the map
                *state = MAP_VALIDATED;
                notify(this);
                break;
            default:
                cout << "\nThis is not a valid command\n" << endl;
                break;
            }
            break;
        case MAP_VALIDATED:
            cout << "\nYou are in the map validated phase\n"
                 << endl;
            //    game->mapValidatedPhase();
            cout << "The map has been validated" << endl;
            cout << choice;
            cout << "Enter an option: ";
            cin >> option;
            switch (option)
            {
            case 3:
            //go to add player
                *state = PLAYERS_ADDED;
                notify(this);
                break;

            default:
             cout << "\nThis is not a valid command\n" << endl;
                break;
            }
            break;
        case PLAYERS_ADDED:
            cout << "\nYou are in the player added phase\n"
                 << endl;
            //    game->playersAddedPhase();
            cout << choice;
            cout << "Enter your choice: ";
            cin >> option;
            switch (option)
            {
            case 3:
            //loop in same state to add another player
                //        game->playersAddedPhase();
                break;
            case 4:
            //go to next state
                *state = ASSIGN_REINFORCEMENT;
                notify(this);
                break;
            default:
            cout << "\nThis is not a valid command\n" << endl;
                break;
            }
            break;
        case ASSIGN_REINFORCEMENT:
            cout << "\nYou are in the assignment reinforcement phase\n"
                 << endl;
            // game->assignReinforcementPhase();
            cout << "\nThe countries have been assigned to the players\n";
            cout << choice;
            cin >> option;
            switch (option)
            {
            case 5: //go to the next state
                *state = ISSUE_ORDERS;
                notify(this);
                break;
            default:
            cout << "\nThis is not a valid command\n" << endl;
                break;
            }
            break;
        case ISSUE_ORDERS:
            cout << "\nYou are in the issue order phase\n"
                 << endl;
            // game->issueOrdersPhase();
            cout << "\nAn order has been issued\n";
            cout << choice;
            cout << "Enter a choice: ";
            cin >> option;

            switch (option)
            {
            case 5:  //loop in the same state, issue another order
                // game->issueOrdersPhase();
                break;
            case 6:  //move to the next state
                *state = EXECUTE_ORDERS;
                notify(this);
                break;
            default:
            cout << "\nThis is not a valid command\n" << endl;
                break;
            }
            break;
        case EXECUTE_ORDERS:
            cout << "\nYou are in the execute order phase\n";
            cout << choice;
            cout << "Enter your choice: ";
            cin >> option;
            switch (option)
            {
            case 7:  //loop in the same state
                // game->executeOrdersPhase();
                cout << "\nAn order has been executed\n";
                break;
            case 8:  //move back to previous state
                cout << "Ending execution orders";
                *state = ASSIGN_REINFORCEMENT;
                notify(this);
                break;
            case 9:  //move to next state
                *state = WIN;
                notify(this);
                break;
            default:
            cout << "\nThis is not a valid command\n" << endl;
                break;
            }
            break;
        case WIN:
            cout << "\nYou are in the win phase\n";
            cout << "Congratulation you have won";
            cout << choice;
            cout << "Enter your choice: ";
            cin >> option;
            switch (option)
            {
            case 10:  //move back to start state
                cout << "Restarting a new game...";
                *state = START;
                notify(this);
                break;
            case 11: //move out of the loop and end the game
                cout << "End of the game...";
                gameRunning = false;
                break;
            }
            break;
        default:
            cout << "This is not a valid state" << endl;
                break;
        }
    }
}

std::string GameEngine::stateToString() {
    switch (*state) {
        case currentStates::START:                  return "START";
        case currentStates::MAP_LOADED:             return "MAP_LOADED";
        case currentStates::MAP_VALIDATED:          return "MAP_VALIDATED";
        case currentStates::PLAYERS_ADDED:          return "PLAYERS_ADDED";
        case currentStates::ASSIGN_REINFORCEMENT:   return "ASSIGN_REINFORCEMENT";
        case currentStates::ISSUE_ORDERS:           return "ISSUE_ORDERS";
        case currentStates::EXECUTE_ORDERS:         return "EXECUTE_ORDERS";
        case currentStates::WIN:                    return "WIN";    
        default:                                    return "Error reading state.";
    }
}

std::string GameEngine::stringToLog() {
    return "GameEngine: Current state: " + stateToString();
}