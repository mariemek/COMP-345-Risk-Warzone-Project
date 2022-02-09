#include <iostream>

#include "Card.h"
#include "Hand.h"

Card::Card() {}

Card::Card(CardType c) {
    type = new CardType(c);
}

Card::Card(const Card& c) {
    type = new CardType(c.getCardType());
}

Card::~Card() {
    delete type;
    type = NULL;
};

/**
 * @brief CardType Value Getter
 * 
 * @return const Card::CardType 
 */
const Card::CardType Card::getCardType() const {
    return *type;
}
/**
 * @brief Creates an Order from the Card
 * 
 */
void Card::play() {
    // will add the card type to the order list later
    switch(this->getCardType()) { 
        case CardType::airlift:
            std::cout << "Airlift card played" << std::endl;
            break;
        case CardType::blockade:
            std::cout << "Blockade card played" << std::endl;
            break;
        case CardType::bomb:
            std::cout << "Bomb card played" << std::endl;
            break;
        case CardType::diplomacy:
            std::cout << "Diplomacy card played" << std::endl;
            break;
        case CardType::reinforcement:
            std::cout << "Reinforcement card played" << std::endl;
            break;
        default:
            std::cout << "Card Type Error" << std::endl;
            break;
    }
    // remove the card from the players hand
    // add the card to the deck
}

std::ostream &operator<<(std::ostream &out, const Card& card) {

    switch(card.getCardType()) {
        case Card::CardType::airlift:
            out << "Airlift";
            break;
        case Card::CardType::blockade:
            out << "Blockade";
            break;
        case Card::CardType::bomb:
            out << "Bomb";
            break;
        case Card::CardType::diplomacy:
            out << "Diplomacy";
            break;
        case Card::CardType::reinforcement:
            out << "Reinforcement";
            break;
        default:
            out << "Card Type Error";
            break;
    }
    return out;
}
