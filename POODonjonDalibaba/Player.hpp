#pragma once
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/Config.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
public:

	void initTexture()
	{
		if (!texture.loadFromFile("texture/perso.png"))
		{
			std::cout << "Error init texture" << std::endl;
		}
	}

	void initSprite()
	{
		sprite.setTexture(texture);
		sprite.scale(0.1f, 0.1f);
	}

	Player()
	{
		movementSpeed = 5.f;
		initTexture();
		initSprite();
	}

	~Player()
	{
	}

	void updateWindowBoundsCollision(const sf::RenderTarget* target)
	{
		//left
		if (this->sprite.getGlobalBounds().left <= 0.f)
			this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);
		//right
		if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
			this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
		//top
		if (this->sprite.getGlobalBounds().top <= 0.f)
			this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);
		//Bottom
		if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
			this->sprite.setPosition(this->sprite.getGlobalBounds().left, target->getSize().y - this->sprite.getGlobalBounds().height);
	}

	void move(const float dirX, const float dirY)
	{
		sprite.move(movementSpeed * dirX, movementSpeed * dirY);
	}

	void update(const sf::RenderTarget* target)
	{
		updateWindowBoundsCollision(target);
	}

	void render(sf::RenderTarget& target)
	{
		target.draw(this->sprite);
	}
};