#include <iostream>

#include "Card.h"
#include "Hand.h"

Hand::Hand() {}

Hand::Hand(const Hand& h) {
    for(Card* c : h.cardHand) 
        this->cardHand.push_back(c);    
}

Hand::~Hand() {
    for(Card* c : this->cardHand) 
        delete c;
    
    this->cardHand.clear();
}

/**
 * @brief Places a Card object at the end of the Hand
 * 
 * @param c 
 */
void Hand::addCard(Card* c) {
    cardHand.push_back(c);
}

void Hand::removeCard(Card* c) {
    // haven't found a usecase yet
    // this->cardHand.erase(std::remove(cardHand.begin(), cardHand.end(), c), cardHand.end());

}
/**
 * @brief Debug purposes
 * 
 */
void Hand::printHand() {
    for(Card* c : this->cardHand) 
        std::cout << *c << std::endl;
    
}
