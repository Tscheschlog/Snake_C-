#include <iostream>
#include <SFML/Audio/Music.hpp>
#include "SoundFX.h"
#include "Snake.h"
#include "Apple.h"
#include "Menu.h"
#include "GameBoard.h"



int main() {

    // Create the main menu
    Menu playerMenu;

    // Set the random time for apple spawns
    std::srand(time(0));

    if (playerMenu.openGameWindow) {
        if (playerMenu.singlePlayer)
            GameBoard SinglePlayerBoard;
        else
            GameBoard MultiplayerBoard;
    }

    return 0;
}