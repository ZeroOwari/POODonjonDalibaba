#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "salles.hpp"

class window {
private:
	int width;
	int height;
public:
	window(int width, int height) : width(1080), height(1920) {
		this->width = width;
		this->height = height;
	}

	void set_width(int width) {
		this->width = width;
	}

	void set_height(int height) {
		this->height = height;
	}

	int get_width() {
		return this->width;
	}

	int get_height() {
		return this->height;
	}

	void afficher() {

		// INITIALISATION DE LA FENETRE
		sf::VideoMode fullscreenMode = sf::VideoMode::getDesktopMode();
		sf::RenderWindow window(fullscreenMode, "Le Donjon d'Alibaba", sf::Style::Fullscreen);
		// FIN INITIAL

		salles salle1(480, 480);

		// LOAD PLAYER
		sf::Texture playerTexture;
		sf::Sprite PlayerSprite;
		PlayerSprite.setPosition(720, 288);
		if (!playerTexture.loadFromFile("C:/Users/lukpr/Desktop/DonjonAliababa/texture/perso.png")) {
			std::cout << "Erreur lors du chargement de la texture" << std::endl;
			return;
		}
		PlayerSprite.setTexture(playerTexture);
		// FIN LOAD PLAYER

		while (window.isOpen())
		{
			window.clear();
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
			}
			sf::Texture background;
			if (!background.loadFromFile("C:/Users/lukpr/Desktop/DonjonAliababa/texture/fond1.png")) {
				std::cout << "Erreur lors du chargement de la texture" << std::endl;
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
				sf::Vector2f position = PlayerSprite.getPosition();
				PlayerSprite.setPosition(position + sf::Vector2f(-3, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				sf::Vector2f position = PlayerSprite.getPosition();
				PlayerSprite.setPosition(position + sf::Vector2f(3, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
				sf::Vector2f position = PlayerSprite.getPosition();
				PlayerSprite.setPosition(position + sf::Vector2f(0, -3));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				sf::Vector2f position = PlayerSprite.getPosition();
				PlayerSprite.setPosition(position + sf::Vector2f(0, 3));
			}

			sf::Sprite spritebackground;
			spritebackground.setTexture(background);
			window.draw(spritebackground);
			salle1.afficherSalle(window);
			window.draw(PlayerSprite);
			window.display();
		}
	}
};