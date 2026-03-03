#include <vector>
#include "card_handler.h"
#include "dealer.h"

    Dealer::Dealer() {
        hand_value = 0;
        unused_ace_count = 0;
        busted = false;
        done = false;
    }

    void Dealer::draw_card(CardHandler *card_handler) {
        hand.emplace_back((*card_handler).draw_card());
        this->recalculate_value();
    }

    void Dealer::recalculate_value() {
        int last_card_value = hand[hand.size()-1].to_value();
        if (last_card_value == 11) {
            unused_ace_count += 1;
        }
        if ((hand_value + last_card_value) > 21 && (unused_ace_count > 0)) {
            unused_ace_count -= 1;
            hand_value -= 10;
        }
        this->hand_value += last_card_value;
        busted = hand_value > 21;
        done = hand_value >= 17;
    }

    int Dealer::get_hand_value() {
        return this->hand_value;
    }
