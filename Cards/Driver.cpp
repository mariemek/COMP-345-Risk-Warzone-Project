#include <iostream>
#include <vector>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"

void print(Card* c);
int main() {
    srand(time(NULL));
    Deck* d = new Deck();
    d->initialize();
    
    Hand* h = new Hand();
    for (int i = 0; i < HAND_SIZE; i++) {
        d->draw(h);
    }

    for (Card* c : h->cardHand) {
        c->play();
    }
}
