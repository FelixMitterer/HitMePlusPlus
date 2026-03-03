
#include "player.h"
#include <vector>
#include "card_handler.h"
#include <optional>
#include "hand.h"

    Player::Player() {
        hands[0] = Hand();
        hand_at_play = 0;
        is_split = false;
        done[0] = false;
        done[1] = true;
        cash = 100;
        bets = 0;
    }


void Player::reset_round() {
    for (int i = 0; i < 2; i++) {
        hands[i] = Hand();
    }
    done[0] = false;
    done[1] = true;
    hand_at_play = 0;
    is_split = false;
    bets = 0;
}

void Player::action(CardHandler *card_handler, ActionType action_type, std::optional<int> bet_optional) {
        switch (action_type) {
            case Hit:
                if (cash < bet_optional) {
                    std::cout << "Insufficient checkmate material";
                    break;
                }
                this->hit(card_handler, bet_optional);
                break;
            case Stand:
                done[hand_at_play] = true;
                break;
            case Split:
                if (hands[hand_at_play].is_splitable) {
                    this->split();
                }
                return;
        }
        if (is_split) {
            switch (hand_at_play) {
                case 0:
                    if (is_split) {
                        hand_at_play = 1;
                    }
                    break;
                case 1:
                    hand_at_play = 0;
                    break;
                default:
                    std::cerr << "Error: requested Hand out of bounds";
                    break;
            }
        }
    }


int Player::get_hand_value() {
        return this->hands[hand_at_play].hand_value;
    }

void Player::hit(CardHandler *card_handler, std::optional<int> bet_optional) {
        cash -= bet_optional.value_or(0);
        bets += bet_optional.value_or(0);
        hands[hand_at_play].draw_card(card_handler);
        done[hand_at_play] = hands[hand_at_play].busted;
    }

void Player::split() {

        Card second_card = hands[0].pop_last_card();
        hands[1] = Hand( {second_card});
        is_split = true;
        done[1] = false;
    }

bool Player::is_busted() {
    return hands[hand_at_play].busted;
}
