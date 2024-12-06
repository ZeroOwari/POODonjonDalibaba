#pragma once
#include "Entity.hpp"

class Troll : public Entity {
public:
    Troll() {
        walkSpeed = 2.f;
        initTexture("res/troll.png");
        initSprite();
        sprite.setPosition(8 * SPRITE_SIZE, 12 * SPRITE_SIZE);
    }

    void initAnimation() override {
        sprite.move(walkSpeed, 0);

        if (sprite.getPosition().x > 400 || sprite.getPosition().x < 150)
            walkSpeed *= -1;

        sprite.setTextureRect(sf::IntRect(anim.x * SPRITE_SIZE, anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
        if (animClock.getElapsedTime().asSeconds() > 0.1f) {
            if (anim.x * SPRITE_SIZE >= texture.getSize().x - SPRITE_SIZE) {
                anim.x = 0;
            }
            else {
                anim.x++;
            }
            animClock.restart();
        }
    }
};
