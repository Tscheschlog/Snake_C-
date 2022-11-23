#include "SoundFX.h"




void Sound::playMusic(const std::string& musicFilePath) {

    // Open it from an audio file
    if (!musicPlayer.openFromFile(musicFilePath))
    {
        // error...
        std::cout << "AUDIO: " + musicFilePath + " FAILED!\n";
    }
    std::cout << "AUDIO: " + musicFilePath + " \n";
    
    // Change some parameters
    musicPlayer.setPosition(0, 1, 10);  // change its 3D position
    musicPlayer.setPitch(2);            // increase the pitch
    musicPlayer.setVolume(15);          // reduce the volume
    musicPlayer.setLoop(true);          // music should loop
    // Play it
    musicPlayer.play();
}

void Sound::playSound(const std::string& audioFilePath) {

    // Open it from an audio file
    if (!buffer.loadFromFile(audioFilePath))
    {
        // error...
        std::cout << "AUDIO: " + audioFilePath + " FAILED!\n";
    }
    // Change some parameters
    soundPlayer.setPosition(0, 1, 10);  // change its 3D position
    soundPlayer.setPitch(2);            // increase the pitch
    soundPlayer.setVolume(15);          // reduce the volume
    soundPlayer.setLoop(false);         // Sounds do not loop

    soundPlayer.setBuffer(buffer);
    // Play it
    soundPlayer.play();
}
