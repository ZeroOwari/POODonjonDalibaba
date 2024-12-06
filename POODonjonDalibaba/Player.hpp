#pragma once
#include "Entity.hpp"

class Player : public Entity {
public:
	enum Dir { Down, Left, Right, Up };
	bool heroIdle = true;

	Player() {
		walkSpeed = 2.5f;
		initTexture("texture/soldat.png");
		sprite.scale(0.7f, 0.7f);
		initSprite();
		sprite.setPosition(7 * SPRITE_SIZE, 5 * SPRITE_SIZE);
	}

	void initAnimation() override {
		sprite.setTextureRect(sf::IntRect(anim.x * SPRITE_SIZE, anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

		if (animClock.getElapsedTime().asSeconds() > 0.1f) {
			if (anim.x * SPRITE_SIZE >= texture.getSize().x - SPRITE_SIZE) {
				anim.x = 0;
			}
			else {
				if (!heroIdle)
					anim.x++;
			}
			animClock.restart();
		}
	}

	void setDirection(int direction) {
		anim.y = direction;
		initAnimation();
	}

	int getDirection() const {
		return anim.y;
	}

};