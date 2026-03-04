#include "game_logic/game.h"




int main() {
    Game game = Game(2);
    while (true) {
        game.play_round();
    }
    return 0;
}