#include <iostream>
#include "GameEngine.h"
using namespace std;



GameEngine::GameEngine(const GameEngine &game1){
    
}

GameEngine& GameEngine::operator= (const GameEngine& game1){
    return *this;
}

GameEngine::~GameEngine(){

}

ostream & operator << (ostream &out, const GameEngine &g){
    return out;
}

istream & operator >> (istream &in, GameEngine &g){
    return in;
}


void GameEngine::start(){
    currentStates current = START;
   
    bool gameRunning = true;
    cout << "Welcome to Warzone. " << endl;

    //possible commands for the users
    string choice = "\n1. Load the map\n2.Validate the map\n3.Add a player in the game\n4.Assign a country\n5.Issue an order\n6End the issues of order\n7.Execute an order\n8.End the execution of orders\n9.Win the Game\n10.Play again\n11.End the game\n";
    while (gameRunning)
    {
        // switch statement where each case represent a state where it will execute the code and ask a command from the user which determine if it stays in the same state or transition to another
        switch (current)
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
                current = MAP_LOADED;
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
                current = MAP_VALIDATED;
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
                current = PLAYERS_ADDED;
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
            //loop in same state
                //        game->playersAddedPhase();
                break;
            case 4:
            //go to next state
                current = ASSIGN_REINFORCEMENT;
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
            case 5:
                current = ISSUE_ORDERS;
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
            case 5:
                // game->issueOrdersPhase();
                break;
            case 6:
                current = EXECUTE_ORDERS;
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
            case 7:
                // game->executeOrdersPhase();
                cout << "\nAn order has been executed\n";
                break;
            case 8:
                cout << "Ending execution orders";
                current = ASSIGN_REINFORCEMENT;
                break;
            case 9:
                current = WIN;
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
            case 10:
                cout << "Restarting a new game...";
                current = START;
                break;
            case 11:
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
