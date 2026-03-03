
#ifndef HITMEPLUSPLUS_DEALER_H
#define HITMEPLUSPLUS_DEALER_H

#include "card_handler.h" // include the header, NOT the .cpp
#include "hand.h"

class Dealer {
public:
    Hand hand;
    bool done;

    // Constructor
    Dealer();

    // Draw a card from a CardHandler
    void draw_card(CardHandler *card_handler);

    void reset_round();

    // Recalculate hand_value
    void recalculate_value();

    // Getter for hand value
    int get_hand_value();

    bool is_busted();
};


#endif //HITMEPLUSPLUS_DEALER_H