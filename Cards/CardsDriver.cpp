#include <iostream>
#include <vector>
#include "Cards.h"

using namespace std;

void print(Card* c);
int main() {

    Deck* deck = new Deck();    
    Hand* hand = new Hand();
    vector<Card*> ol;
    cout << "- Deck and Hand created." << endl;
    cout << *deck;
    cout << *hand;
    cout << "Order List Size: " << ol.size() << endl;

    cout << endl << "- Filling the Hand." << endl;
    for (int i = 0; i < HAND_SIZE; i++) {
        Card* c = deck->draw();
        cout << "Card Drawn: " << c->cardTypeToString() << endl;
        hand->addCard(c);
    }

    cout << endl << "- Hand is filled." << endl;
    cout << *deck;
    cout << *hand;

    cout << endl << "- Playing each Card" << endl;
    vector<Card*>::iterator iter = hand->cards.begin();
    while (iter != hand->cards.end()) {
        (*iter)->play(ol, deck, hand);
    }

    cout << endl << "- All Cards in Hand have been played." << endl;
    cout << *deck;
    cout << *hand;
    cout << "Order List Size: " << ol.size() << endl;

    delete deck;
    delete hand;
}