
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
        bets[0] = 0;
        bets[1] = 0;
    }


void Player::reset_round() {
    for (int i = 0; i < 2; i++) {
        hands[i] = Hand();
    }
    done[0] = false;
    done[1] = true;
    hand_at_play = 0;
    is_split = false;
    bets[0] = 0;
    bets[1] = 0;
}

void Player::action(CardHandler *card_handler, ActionType action_type, std::optional<int> bet_optional) {
        switch (action_type) {
            case Hit:
                this->hit(card_handler, bet_optional);
                break;
            case Stand:
                done[hand_at_play] = true;
                break;
            case Split:
                if (hands[hand_at_play].is_splitable && cash >= bets[0]) {
                    this->split();
                }
               if (cash < bets[0]){
                   std::cout << "You're lacking the funds to split\n";
               }
                return;
        }
    }


int Player::get_hand_value() {
        return this->hands[hand_at_play].hand_value;
    }

void Player::hit(CardHandler *card_handler, std::optional<int> bet_optional) {
        cash -= bet_optional.value_or(0);
        bets[hand_at_play] += bet_optional.value_or(0);
        hands[hand_at_play].draw_card(card_handler);
        done[hand_at_play] = hands[hand_at_play].busted;
    }

void Player::split() {
        hands[0].is_splitable = false;
        Card second_card = hands[0].pop_last_card();
        hands[0].hand_value -= second_card.to_value();
        if (second_card.type == Ace) {
            hands[0].hand_value +=10;
        }
        hands[1] = Hand( {second_card});
        cash -= bets[0];
        bets[1] = bets[0];
        is_split = true;
        done[1] = false;
    }

void Player::switch_hands() {
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
bool Player::is_busted() {
    return hands[hand_at_play].busted;
}
