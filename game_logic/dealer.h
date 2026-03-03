//
// Created by felix on 02.03.2026.
//

#ifndef HITMEPLUSPLUS_DEALER_H
#define HITMEPLUSPLUS_DEALER_H

#include <vector>
#include <iostream>       // for std::cout in get_hand_value()
#include "card_handler.h" // include the header, NOT the .cpp

class Dealer {
public:
    std::vector<Card> hand;
    int hand_value;
    int unused_ace_count; // aces in hand using 11 instead of 1
    bool busted;
    bool done;

    // Constructor
    Dealer();

    // Draw a card from a CardHandler
    void draw_card(CardHandler *card_handler);

    // Recalculate hand_value
    void recalculate_value();

    // Getter for hand value
    int get_hand_value();
};


#endif //HITMEPLUSPLUS_DEALER_H