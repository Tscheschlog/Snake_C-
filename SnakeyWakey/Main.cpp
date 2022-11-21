#include <iostream>
#include <SFML/Audio/Music.hpp>
#include "Snake.h"
#include "Apple.h"
#include "Menu.h"
#include "GameBoard.h"





int main() {

    // Declare a new music
    sf::Music music;
    // Open it from an audio file
    if (!music.openFromFile("Music/music.ogg"))
    {
        // error...
        std::cout << "MUSIC FAILED!\n";
    }
    // Change some parameters
    music.setPosition(0, 1, 10); // change its 3D position
    music.setPitch(2);           // increase the pitch
    music.setVolume(50);         // reduce the volume
    music.setLoop(true);         // make it loop
    // Play it
    music.play();


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