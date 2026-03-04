#include "card.h"
#include "card_handler.h"
#include<vector>
#include<iostream>
#include<random>


    CardHandler::CardHandler() {
        CardHandler(1);
    }

    CardHandler::CardHandler(int number_of_decks) {
        cards = {};
        for (int i = 0; i < number_of_decks; i++) {
            for (int colour_int = Heart; colour_int <= Club; colour_int++) {
                CardColour card_colour = static_cast<CardColour>(colour_int);
                for (int type_int = Ace; type_int <= King; type_int++) {
                    CardType card_type = static_cast<CardType>(type_int);
                    //CardType card_type = Eight;  //DEBUG TOOL
                    cards.emplace_back(Card(card_colour, card_type));
                }
            }
        }
    }

    void CardHandler::print() {
        for (Card& card : cards) {
            std::cout << card.to_string() << '\n';
            //std::cout << card.colour << " " << card.type << '\n';
        }
    }

    Card CardHandler::draw_card() {

        std::random_device rd;
        std::uniform_int_distribution dist(0, (int) this->cards.size()-1);
        int random_num = dist(rd);
        Card card = this->cards[random_num];
        //this->cards.erase(cards.begin() + random_num, cards.begin() + random_num+1);
        this->cards[random_num] = this->cards.back();
        this->cards.pop_back();
        return card;
    }