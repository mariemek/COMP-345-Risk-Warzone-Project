#pragma once

#include <vector>

#include "Card.h"

// unclear if needed
#define HAND_SIZE 5

class Hand {
    private:        

    public:

        std::vector<Card*> cardHand;

        // constructors/destructors
        Hand();
        Hand(const Hand& h);
        ~Hand();

        // get/set
        int getHandSize();

        // methods
        void removeCard(Card* c);
        void addCard(Card* c);
        void printHand();
};
