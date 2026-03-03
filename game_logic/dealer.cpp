#include <vector>
#include "card_handler.h"
#include "dealer.h"

    Dealer::Dealer() {
        hand = Hand();
        done = false;
    }

    void Dealer::draw_card(CardHandler *card_handler) {
        hand.draw_card(card_handler);
        done = hand.hand_value>=17;
    }

    int Dealer::get_hand_value() {
        return this->hand.hand_value;
    }

    bool Dealer::is_busted() {
        return hand.busted;
    }
