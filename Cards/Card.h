#pragma once

#include <iostream>

class Card {
    public:
        // fields
        enum CardType {
            airlift = 0,
            blockade,
            bomb,
            diplomacy,
            reinforcement
        };        

        // constructors / destructors
        Card();
        Card(CardType c);
        Card(const Card& c);
        ~Card();

        // get/set
        const CardType getCardType() const;

        // functions
        void play();

        // overrides
        friend std::ostream& operator<<(std::ostream& Out, const Card& card);
    
    private:
        CardType* type;
};
