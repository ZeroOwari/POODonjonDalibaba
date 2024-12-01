#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <vector>
#include <iostream>

class Player {
protected:
	sf::Texture heroTexture;
	sf::Sprite heroSprite;
	sf::Clock heroAnimClock;

	const int SPRITE_SIZE = 32;
	const int WALK_SPEED = 5;

	sf::Vector2i heroAnim = sf::Vector2i(0, Player::Down);

public:
	enum Dir { Down, Left, Right, Up };
	bool heroIdle = true;

	void initTexture() {
		if (!heroTexture.loadFromFile("texture/soldat.png"))
			std::cout << "Erreur chargement texture heros" << std::endl;

	}
	void initSprite() {
		heroSprite.setTexture(heroTexture);
		heroSprite.scale(0.7f, 0.7f);
		initAnimation();
	}
	void initAnimation() {
		heroSprite.setTextureRect(sf::IntRect(heroAnim.x * SPRITE_SIZE, heroAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

		if (heroAnimClock.getElapsedTime().asSeconds() > 0.1f)
		{
			if (heroAnim.x * SPRITE_SIZE >= heroTexture.getSize().x - SPRITE_SIZE) {
				heroAnim.x = 0;
			}
			else
			{
				if (!heroIdle)
					heroAnim.x++;
			}
			heroAnimClock.restart();
		}
	}
	sf::Sprite& getShape() {
		return heroSprite;
	}

	int getSpriteSize() {
		return SPRITE_SIZE;
	}

	int getMoveSpeed() {
		return WALK_SPEED;
	}

	void setDirection(int direction) {
		heroAnim.y = direction;
		initAnimation();
	}

	Player() {

		initTexture();
		initSprite();
	}

	virtual ~Player() {

	}

	sf::Vector2f getPosition() const {
		return heroSprite.getPosition();
	}
	void setPosition(float x, float y) { // Ajoutez cette méthode
		heroSprite.setPosition(x, y);
	}

	int getDirection() const {
		return heroAnim.y;
	}

	void move(const float x, const float y) {
		heroSprite.move(WALK_SPEED * x, WALK_SPEED * y);
	}

	void render(sf::RenderTarget& target) {
		target.draw(heroSprite);
	}

};
