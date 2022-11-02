#include <iostream>
#include "Snake.h"
#include "Apple.h"
#include "Menu.h"
#include "GameBoard.h"


int main() {

    std::srand(time(0));

    Menu playerMenu;
    if (playerMenu.openGameWindow) {
        if (playerMenu.singlePlayer)
            SnakeGameBoard SinglePlayerBoard;
        else
            SnakeGameBoard MultiplayerBoard;
    }

    return 0;
}