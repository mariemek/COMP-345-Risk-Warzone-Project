#pragma once

#include <vector>
#include "Hand.h"
#include "Card.h"

#define DECK_SIZE 50

class Deck {
    private:
        std::vector<Card*> deck;

    public:
        Deck();
        Deck(const Deck& c);
        ~Deck();
        void initialize();
        void draw(Hand* h);
        void addCard(Card* c);
};
