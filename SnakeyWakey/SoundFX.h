#pragma once
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include <string>


class Sound {
private:
	sf::Music musicPlayer;
	sf::Sound soundPlayer;
	sf::SoundBuffer buffer;
public:
	Sound() = default;
	void playSound(const std::string&);
	void playMusic(const std::string&);
};