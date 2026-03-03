#include <iostream>
#include "game_logic/dealer.h"
#include <vector>
#include "game_logic/player.h"


bool check_all_done(std::vector<Player> players, Dealer dealer) {
    bool result = dealer.done;
    for (Player player: players) {
        result = result && player.done;
    }
    return result;
}

ActionType parse_action(std::string input) {
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
}

int main() {
    CardHandler card_handler;
    //card_handler.print();
    //std::cout << "i = " << i << std::endl;
    /*for (int i = 0; i < 52; i++) {
        std::cout << card_handler.draw_card().to_string() << '\n';
    }*/
    Dealer dealer;
    std::vector<Player> players;
    int player_count = 2;
    for (int i = 0; i < player_count; i++) {
        players.emplace_back(Player());
    }
    //TODO create interface for player and dealer
    int i = 0;
    while (!check_all_done(players, dealer)) {
        if (!dealer.done) {
            dealer.draw_card(&card_handler);
            std::cout << "dealer: new card: " << dealer.hand.cards[i].to_string() << '\n';
            std::cout << "dealer: hand value: " << dealer.get_hand_value() << '\n' << '\n';;
        }
        int j = 1;
        for (Player &player : players) {
            if (!player.done) {
                std::string input;
                std::cout << "Player " << j << ": Please choose move\n";
                std::cin >> input;
                ActionType action = parse_action(input);
                switch (action) {
                    case Stand:
                        player.action(&card_handler, action, std::nullopt);
                        break;
                    case Split:
                        player.action(&card_handler, action, std::nullopt);
                        j--;
                        break;
                    case Hit:
                        int bet = 0;
                        std::cout << "Please enter bet:\n";
                        std::cin >> bet;
                        player.action(&card_handler, action, bet);
                        if (player.is_split) {
                            std::cout << "Please enter second bet:\n";
                            std::cin >> bet;
                            player.action(&card_handler, action, bet);
                        }
                        std::cout << "Player " << j << ": new card: " << player.hands[player.hand_at_play].cards[i].to_string() << '\n';
                        std::cout << "Player " << j << ": hand value: " << player.get_hand_value() << '\n';
                        std::cout << '\n';
                        break;
                }
            }
            j++;
        }
        i++;
    }
    std::cout << "Dealer: " << dealer.get_hand_value() << '\n';
    int x = 1;
    for (Player player : players) {
        std::cout << "Player " << x << ": " << player.hands[0].hand_value << '\n';
        if (player.is_split) {
            std::cout << "Player " << x << ": second hand: " << player.hands[1].hand_value << '\n';
        }
    }
    return 0;
}