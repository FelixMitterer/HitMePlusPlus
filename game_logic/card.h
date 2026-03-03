
#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>
#include <string>

enum CardColour {
    Heart,
    Spade,
    Diamond,
    Club,
};

enum CardType {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

class Card {
public:
    CardColour colour;
    CardType type;

    Card(CardColour card_colour, CardType card_type);

    std::string to_string();

    int to_value();
};



#endif //BLACKJACK_CARD_H