#include "Deck.h"
#include "Hand.h"
#include "Card.h"

Deck::Deck() { }

Deck::Deck(const Deck& d) {
    for(Card* c : d.deck) 
        addCard(c); 
}

Deck::~Deck() {
    for(Card* c : deck)
        delete c;
    
    deck.clear();
}

/**
 * @brief Initializes the Deck with DECK_SIZE random Cards
 * 
 */
void Deck::initialize() {    
    for (int i = 0; i < DECK_SIZE; i++) {
        Card* c = new Card(static_cast<Card::CardType>(rand() % Card::CardType::reinforcement));
        addCard(c);
    }
}

/**
 * @brief Chooses a random Card from the Deck and moves it to the Hand
 * 
 * @param h - The Hand object in which the Card is moved to
 */
void Deck::draw(Hand* h) {
    int randIndex = rand() % deck.size();
    Card* c = deck.at(randIndex);
    deck.erase(deck.begin() + randIndex);
    h->addCard(c);
}

/**
 * @brief Places a Card object at the end of the Deck
 * 
 * @param c - The Card object that is added to the end of the Deck
 */
void Deck::addCard(Card* c) {
    deck.push_back(c);
}
