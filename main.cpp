#include <iostream>
#include "game_logic/dealer.h"

int main() {
    CardHandler card_handler;
    //card_handler.print();
    //std::cout << "i = " << i << std::endl;
    /*for (int i = 0; i < 52; i++) {
        std::cout << card_handler.draw_card().to_string() << '\n';
    }*/
    Dealer dealer;
    while (!dealer.done) {
        dealer.draw_card(&card_handler);
        std::cout << dealer.get_hand_value() << '\n';
    }
    return 0;
}