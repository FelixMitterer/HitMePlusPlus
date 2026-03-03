//
// Created by felix on 02.03.2026.
//

#ifndef BLACKJACK_CARD_HANDLER_H
#define BLACKJACK_CARD_HANDLER_H

#include "card.h"
#include <vector>
#include <iostream>


class CardHandler {
public:
    std::vector<Card> cards;

    CardHandler();

    CardHandler(int number_of_decks);

    void print();

    Card draw_card();


};


#endif //BLACKJACK_CARD_HANDLER_H