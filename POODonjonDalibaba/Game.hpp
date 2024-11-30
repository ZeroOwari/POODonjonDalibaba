#pragma once
#include <iostream>
#include <ctime>
#include <vector>

#include "Player.hpp"
#include "salles.hpp"

class Game
{
private:
	sf::RenderWindow* window;
	Player* player;

	sf::Texture worldTexture;
	sf::Sprite Background;

public:

	Game() {
		initWindow();
		initWorld();
		initPlayer();

	}

	// initialison fond ecran
	void initWorld() {
		if (!worldTexture.loadFromFile("texture/fond1.png")) {
			std::cout << "Erreur lors du chargement de la texture" << std::endl;
		}
		Background.setTexture(worldTexture);
	}

	~Game() {
		delete window;
	}

	void initBackGround() {

	}

	void initWindow() {
		window = new sf::RenderWindow(sf::VideoMode(640, 320), "Game 2", sf::Style::Close | sf::Style::Titlebar);
		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(false);
	}

	void initPlayer()
	{
		player = new Player();
	}

	void run()
	{
		while (window->isOpen())
		{
			update();
			render();
		}

	}

	void updateInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			player->move(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player->move(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			player->move(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player->move(0.f, 1.f);
		}
	}

	void updatePollEvent()
	{
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.Event::type == sf::Event::Closed)
				window->close();
			if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
				window->close();
		}
	}

	void renderBackground() {
		window->draw(Background);
	}

	void update()
	{
		updatePollEvent();
		updateInput();
		player->updateWindowBoundsCollision(window);

	}

	void render()
	{
		window->clear();

		salles salle1(320, 320);
		salle1.afficherSalle(*window);
		//renderBackground();

		this->player->render(*this->window);

		window->display();
	}
};