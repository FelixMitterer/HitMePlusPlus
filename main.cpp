#include <iostream>
#include "game_logic/card_handler.cpp"

int main() {
    CardHandler card_handler;
    //card_handler.print();
    //std::cout << "i = " << i << std::endl;
    for (int i = 0; i < 52; i++) {
        std::cout << card_handler.draw_card().to_string() << '\n';
    }
    return 0;
}