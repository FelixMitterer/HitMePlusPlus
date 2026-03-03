
#include "player.h"
#include <vector>
#include "card_handler.h"
#include <optional>
#include "hand.h"

    Player::Player() {
        hands[0] = Hand();
        hand_at_play = 0;
        is_split = false;
        done = false;
        cash = 100;
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
                done = true;
                break;
            case Split:
                if (hands[hand_at_play].is_splitable) {
                    this->split();
                }
                break;
        }
    }


int Player::get_hand_value() {
        return this->hands[hand_at_play].hand_value;
    }

void Player::hit(CardHandler *card_handler, std::optional<int> bet_optional) {
        cash -= bet_optional.value_or(0);
        hands[hand_at_play].draw_card(card_handler);
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

void Player::split() {
        Card second_card = hands[0].pop_last_card();
        hands[1] = Hand( {second_card});
        is_split = true;
    }

bool Player::is_busted() {
    return hands[hand_at_play].busted;
}
