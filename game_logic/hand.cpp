
#include "hand.h"
#include <vector>
#include "card_handler.h"
#include <optional>

Hand::Hand() {
    hand_value = 0;
    unused_ace_count = 0;
    is_splitable = false;
    busted = false;
}

Hand::Hand(std::vector<Card> cards) {
    hand_value = 0;
    unused_ace_count = 0;
    is_splitable = false;
    busted = false;
    for (Card card : cards) {
        this->add_card(card);
    }
}
// returns if the hand is busted
void Hand::draw_card(CardHandler *card_handler) {
    cards.emplace_back((*card_handler).draw_card());
    return this->recalculate_value();
}

void Hand::add_card(Card card) {
    cards.emplace_back(card);
    this->recalculate_value();
}

Card Hand::pop_last_card() {
    Card last_card = cards.back();
    cards.pop_back();
    return last_card;
}


void Hand::recalculate_value() {
    int last_card_value = cards[cards.size()-1].to_value();
    if (last_card_value == 11) {
        unused_ace_count += 1;
    }
    if (hand_value + last_card_value > 21 && unused_ace_count > 0) {
        unused_ace_count -= 1;
        hand_value -= 10;
    }
    if (cards.size() == 2 && cards[0].type == cards[1].type) {
        is_splitable = true;
    }
    this->hand_value += last_card_value;
    busted = hand_value > 21;
}


//returns if Hand is busted