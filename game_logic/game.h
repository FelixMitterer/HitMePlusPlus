//
// Created by Phinneas on 03/03/2026.
//

#ifndef HITMEPLUSPLUS_GAME_H
#define HITMEPLUSPLUS_GAME_H


#include "player.h"
#include "dealer.h"

class Game {
public:
    CardHandler card_handler;
    std::vector<Player> players;
    Dealer dealer;
    int player_count;


    Game(int player_count);

    void play_round();

    void reset_round();

    bool check_all_done();

    void player_action_input(Player *player, int player_number);

    ActionType parse_action(std::string input);

    void evaluate();

};


#endif //HITMEPLUSPLUS_GAME_H