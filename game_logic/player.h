
#ifndef HITMEPLUSPLUS_PLAYER_H
#define HITMEPLUSPLUS_PLAYER_H

#include <vector>
#include "card_handler.h"
#include <optional>
#include "hand.h"

enum ActionType {
    Hit,
    Stand,
    Split, // ow Headaches incoming
};

class Player {
public:
    Hand hands[2]; //multiple in case of split
    bool done[2];
    int bets[2];
    int cash;
    int hand_at_play; // for split cards determines which of the 2 hands is currently at play hand1 = 0, hand2 = 1
    bool is_split;
    // Constructor
    Player();

    void reset_round();
    // Execute action for player
    void action(CardHandler *card_handler, ActionType action_type, std::optional<int> bet_optional);

    void hit(CardHandler *card_handler, std::optional<int> bet_optional);

    void split();

    void switch_hands();
    // Getter for hand value
    int get_hand_value();

    bool is_busted();
};


#endif //HITMEPLUSPLUS_PLAYER_H

