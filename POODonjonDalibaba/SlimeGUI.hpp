#pragma once
#include "Entity.hpp"

class Slime : public Entity {
public:
    Slime() {
        walkSpeed = 2.f;
        initTexture("res/slime.png");
        sprite.scale(0.5f, 0.5f);
        initSprite();
        sprite.setPosition(8 * SPRITE_SIZE, 12 * SPRITE_SIZE);
    }

    void initAnimation() override {
        sprite.move(walkSpeed, 0);

        if (sprite.getPosition().x > 300 || sprite.getPosition().x < 150)
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
