
#ifndef HITMEPLUSPLUS_HAND_H
#define HITMEPLUSPLUS_HAND_H

#include "hand.h"
#include <vector>
#include "card_handler.h"
#include <optional>

class Hand {
public:
    std::vector<Card> cards;
    int hand_value;
    int unused_ace_count; // aces in hand using 11 instead of 1
    bool is_splitable; // is true when Player gets dealt two identical card types and enables split action
    bool busted;


    Hand();

    Hand(std::vector<Card> cards);

    void add_card(Card card);

    Card pop_last_card();

    void draw_card(CardHandler *card_handler);

    void recalculate_value();
};


#endif //HITMEPLUSPLUS_HAND_H