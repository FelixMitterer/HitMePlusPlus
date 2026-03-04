//
// Created by Phinneas on 03/03/2026.
//

#include "game.h"
#include "player.h"
#include "dealer.h"
#include <iostream>


Game::Game(int player_count) {
    this->player_count = player_count;
    card_handler = CardHandler(1);
    dealer = Dealer();
    for (int i = 0; i < player_count; i++) {
        players.emplace_back(Player());
    }
}

void Game::play_round() {
    reset_round();
    card_handler = CardHandler(1);
    int i = 0;
    while (!this->check_all_done()) {
        if (!dealer.done) {
            dealer.draw_card(&card_handler);
            std::cout << "Dealer: new card: " << dealer.hand.cards[i].to_string() << '\n';
            std::cout << "Dealer: hand value: " << dealer.get_hand_value() << '\n' << '\n';
        }


        int j = 1;
        for (Player &player : players) {
            if (!player.is_split) {
                if (!player.done[player.hand_at_play]) {
                    player_action_input(&player, j);
                }
            } else {
                for (int x = 0; x < 2; x++) {
                    if (!player.done[player.hand_at_play]) {
                        player_action_input(&player, j);
                    }
                }
            }
            j++;
        }
        i++;
    }
    std::cout << "Dealer: " << dealer.get_hand_value() << '\n';
    int x = 0;
    for (Player &player : players) {
        x++;
        if (player.is_split) {
            std::cout << "Player " << x << ": first hand:" << player.hands[0].hand_value << '\n';
            std::cout << "Player " << x << ": second hand: " << player.hands[1].hand_value << '\n';
        }
        else {
            std::cout << "Player " << x << ": " << player.hands[0].hand_value << '\n';
        }
    }
    evaluate();
}




void Game::reset_round() {
    card_handler = CardHandler(1);
    dealer.reset_round();
    for (Player &player: players) {
        player.reset_round();
    }
}

bool Game::check_all_done() {
    bool result = dealer.done;
    for (Player &player: players) {
        for (bool i : player.done) {
            result = result && i;
        }
    }
    return result;
}

void Game::player_action_input(Player *player, int player_number) {
    std::string hand_number_maybe;
    if (player->is_split) {
        switch (player->hand_at_play) {
            case 0:
                hand_number_maybe = " for the first hand";
                break;
            case 1:
                hand_number_maybe = " for the second hand";
                break;
            default:
                break;
        }
    }
    std::string input;
    std::cout << "Player " << player_number << ": Please choose move" << hand_number_maybe << '\n';
    std::cin >> input;
    ActionType action = this->parse_action(input);
    switch (action) {
        case Stand:
            (*player).action(&card_handler, action, std::nullopt);
            if ((*player).is_split) {
                (*player).switch_hands();
            }
            break;
        case Split:
            (*player).action(&card_handler, action, std::nullopt);
            player_action_input(player, player_number);
            break;
        case Hit:
            int bet = 0;
            std::cout << "Please enter bet:\n";
            std::cin >> bet;
            while (bet>(*player).cash) {
                std::cout << "You're lacking the funds\nYou have " << (*player).cash << " cash\nPlease valid bet enter bet:\n";
                std::cin >> bet;
            }

            (*player).action(&card_handler, action, bet);
            //int last_card_index = (*player).hands[(*player).hand_at_play].cards.size();
            std::cout << "Player " << player_number << ": new card: " << (*player).hands[(*player).hand_at_play].cards[(*player).hands[(*player).hand_at_play].cards.size()-1].to_string() << '\n';
            std::cout << "Player " << player_number << ": hand value: "<< (*player).get_hand_value() << '\n' << '\n';
            if ((*player).is_split) {
                (*player).switch_hands();
            }
            break;
    }
}

ActionType Game::parse_action(std::string input) {
    if (input == "Hit") {
        return Hit;
    }
    if (input == "Stand") {
        return Stand;
    }
    if (input == "Split") {
        return Split;
    }

    std::cerr << "Parse failed";
    return Stand;
}

void Game::evaluate() {
    int i = 1;
    for ( Player &player : players) {
        for (int j = 0; j<2; j++) {
            player.hand_at_play = j;
            if (!player.is_busted() && player.get_hand_value() > dealer.get_hand_value() or !player.is_busted() && dealer.is_busted()) {
                player.cash += player.bets[j] *2;
            }
        }
        std::cout << "Player " << i << " now has " << player.cash << " cash\n";
        i++;
    }
    std::cout << '\n' << '\n' << '\n';
}