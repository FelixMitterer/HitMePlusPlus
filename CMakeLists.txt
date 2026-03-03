cmake_minimum_required(VERSION 4.1)
project(HitMePlusPlus)

set(CMAKE_CXX_STANDARD 20)

add_executable(HitMePlusPlus
    main.cpp
        game_logic/card_handler.cpp
        game_logic/card.cpp
        game_logic/dealer.cpp
        game_logic/player.cpp
        game_logic/hand.cpp
)
