#include <iostream>
#include <SFML/Audio/Music.hpp>
#include "SoundFX.h"
#include "Snake.h"
#include "Apple.h"
#include "Menu.h"
#include "GameBoard.h"
#include "Options.h"



int main() {

    // Create the main menu
    Menu playerMenu(50);

    // Set the random time for apple spawns
    std::srand(time(0));

    
    if (playerMenu.openGameWindow) {
        Options optionsMenu;
        if (playerMenu.singlePlayer && playerMenu.openGameWindow)
            GameBoard SinglePlayerBoard(playerMenu.singlePlayer);
        else if(!playerMenu.singlePlayer && playerMenu.openGameWindow)
            GameBoard MultiplayerBoard(playerMenu.singlePlayer);
    }

    return 0;
}