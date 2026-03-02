#include "card.cpp"
#include<vector>
#include<iostream>
#include<random>

class CardHandler {
    public:
    std::vector<Card> cards;

    CardHandler() {
        cards = {};
        for (int colour_int = Heart; colour_int <= Club; colour_int++) {
            CardColour card_colour = static_cast<CardColour>(colour_int);
            for (int type_int = Ace; type_int <= King; type_int++) {
                CardType card_type = static_cast<CardType>(type_int);
                cards.emplace_back(Card(card_colour, card_type));
            }
        }
    }

    void print() {
        for (Card& card : cards) {
            std::cout << card.to_string() << '\n';
            //std::cout << card.colour << " " << card.type << '\n';
        }
    }

    Card draw_card() {
        std::cout << (int) this->cards.size();
        std::random_device rd;
        std::uniform_int_distribution dist(0, (int) this->cards.size()-1);
        int random_num = dist(rd);
        Card card = this->cards[random_num];
        //this->cards.erase(cards.begin() + random_num, cards.begin() + random_num+1);
        this->cards[random_num] = this->cards.back();
        this->cards.pop_back();
        return card;
    }

};