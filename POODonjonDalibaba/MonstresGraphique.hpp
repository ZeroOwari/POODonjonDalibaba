#pragma once
#include "Entity.hpp"

class Monstres : public Entity {
public:
    Monstres() {
        walkSpeed = 2.f;
        initTexture("res/slime.png");
        sprite.scale(0.5f, 0.5f);
        initSprite();
    }

    void initAnimation() override {
        sprite.move(walkSpeed, 0);

        if (sprite.getPosition().x > 600 || sprite.getPosition().x < 100)
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
