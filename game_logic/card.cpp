#include <iostream>
#include <string>
#include "card.h"


    Card::Card(const CardColour card_colour, const CardType type) {
        this->colour = card_colour;
        this->type = type;
    }

    std::string Card::to_string() {
       std::string string = "";
        switch (this->colour) {
            case Heart:
                string = string + "Heart";
                break;
            case Spade:
                string = string + "Spade";
                break;
            case Diamond:
                string = string + "Diamond";
                break;
            case Club:
                string = string + "Club";
                break;
        }
        string = string + ": ";
        switch (this->type) {
            case Ace:
                string = string + "Ace";
                break;
            case Two:
                string = string + "Two";
                break;
            case Three:
                string = string + "Three";
                break;
            case Four:
                string = string + "Four";
                break;
            case Five:
                string = string + "Five";
                break;
            case Six:
                string = string + "Six";
                break;
            case Seven:
                string = string + "Seven";
                break;
            case Eight:
                string = string + "Eight";
                break;
            case Nine:
                string = string + "Nine";
                break;
            case Ten:
                string = string + "Ten";
                break;
            case Jack:
                string = string + "Jack";
                break;
            case Queen:
                string = string + "Queen";
                break;
            case King:
                string = string + "King";
                break;
        }
        return string;
    }

    int Card::to_value() {
        switch (this->type) {
            case Ace:
                return 11;
            case Two:
                return 2;
            case Three:
                return 3;
            case Four:
                return 4;
            case Five:
                return 5;
            case Six:
                return 6;
            case Seven:
                return 7;
            case Eight:
                return 8;
            case Nine:
                return 9;
            case Ten:
                return 10;
            case Jack:
                return 10;
            case Queen:
                return 10;
            case King:
                return 10;
        }
    }

