#include "Cards.h"
#include <algorithm>

Deck::Deck() { 
    for (int i = 0; i < DECK_SIZE; i++) {
        // Fill the deck with an equal amount of each card
        Card* c = new Card(static_cast<Card::CardType>(i % Card::CardType::LAST));
        addCard(c);
    }

}

Deck::Deck(const Deck& d) {
    for(Card* c : d.cards) 
        addCard(c); 
}

Deck::~Deck() {
    for(Card* c : cards)
        delete c;
    
    cards.clear();
}

/**
 * @brief Chooses a random Card from the Deck and moves it to the Hand
 * 
 * @param h - The Hand object in which the Card is moved to
 */
Card* Deck::draw() {
    int randIndex = rand() % cards.size();
    Card* c = cards.at(randIndex);
    cards.erase(cards.begin() + randIndex);
    return c;
}

/**
 * @brief Places a Card object at the end of the Deck
 * 
 * @param c - The Card object that is added to the end of the Deck
 */
void Deck::addCard(Card* c) {
    cards.push_back(c);
}

Deck& Deck:: operator=(const Deck& d) {
    cards = d.cards;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    out << "Deck Size: " << deck.cards.size() << std::endl;
    return out;
}


Hand::Hand() {}

Hand::Hand(const Hand& h) {
    for(Card* c : h.cards) 
        this->cards.push_back(c);   
    //! verify if 'new' needed 
}

Hand::~Hand() {
    for(Card* c : this->cards) 
        delete c;
    
    this->cards.clear();
}

/**
 * @brief Places a Card object at the end of the Hand
 * 
 * @param c 
 */
void Hand::addCard(Card* c) {
    cards.push_back(c);
}

Hand& Hand::operator=(const Hand& t) {
    this->cards = t.cards;
    return *this;
}
        
std::ostream& operator<<(std::ostream& out, const Hand& hand) {
    out << "Hand Size: " << hand.cards.size() << std::endl;
    return out;
}


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
Card::CardType Card::getCardType() const {
    return *type;
}

std::string Card::cardTypeToString() const {
    switch(this->getCardType()) { 
        case CardType::Airlift:         return "Airlift";
        case CardType::Blockade:        return "Blockade";
        case CardType::Bomb:            return "Bomb";
        case CardType::Diplomacy:       return "Diplomacy";
        case CardType::Reinforcement:   return "Reinforcement";
        default:                        return "Error reading card type.";
    }
}

/**
 * @brief Creates an Order from the Card
 * 
 */
void Card::play(std::vector<Card*> &ol, Deck* deck, Hand* hand) {

    // will add the card type to the order list later
    switch(this->getCardType()) { 
        case CardType::Airlift:
            std::cout << "Airlift order created" << std::endl;
            break;
        case CardType::Blockade:
            std::cout << "Blockade order created" << std::endl;
            break;
        case CardType::Bomb:
            std::cout << "Bomb order created" << std::endl;
            break;
        case CardType::Diplomacy:
            std::cout << "Diplomacy order created" << std::endl;
            break;
        case CardType::Reinforcement:
            std::cout << "Reinforcement order created" << std::endl;
            break;
        default:
            std::cout << "Card Type Error" << std::endl;
            break;
    }
    
    // Remove the card from the Hand and add it to the Deck
    auto index = std::find(hand->cards.begin(), hand->cards.end(), this);
    if (index != hand->cards.end()) {
        hand->cards.erase(index);
        deck->addCard(this);
        ol.push_back(this);
    }
}

Card& Card::operator=(const Card& t){
    this->type = t.type;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Card& card) {

    
    return out << card.cardTypeToString() << std::endl;
}