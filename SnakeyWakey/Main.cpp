#include <iostream>
#include <SFML/Audio/Music.hpp>
#include "SoundFX.h"
#include "Snake.h"
#include "Apple.h"
#include "Menu.h"
#include "GameBoard.h"
#include "Options.h"



int main() {

    bool continueGame = true; // is true unless you close window with ESC or hit Quit Button

     // Set the random time for apple spawns
    std::srand(time(0));

    do {
        Menu playerMenu(continueGame);

        if (continueGame) {
            Options optionsMenu(continueGame);
            if (playerMenu.singlePlayer && continueGame)
                GameBoard SinglePlayerBoard(playerMenu.singlePlayer, continueGame);
            else if (!playerMenu.singlePlayer && continueGame)
                GameBoard MultiplayerBoard(playerMenu.singlePlayer, continueGame);
        }

    } while (continueGame);

    return 0;
}