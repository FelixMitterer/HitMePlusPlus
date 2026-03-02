#include <iostream>
#include <string>

enum CardColour {
    Heart,
    Spade,
    Diamond,
    Club,
};

enum CardType {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

class Card {
    public:
    CardColour colour;
    CardType type;

    Card(const CardColour card_colour, const CardType type) {
        this->colour = card_colour;
        this->type = type;
    }

    std::string to_string() {
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

};

