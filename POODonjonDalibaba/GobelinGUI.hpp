#pragma once
#include "Entity.hpp"

class Gobelin : public Entity {
private:
    bool movingRight = true;
public:
    Gobelin() {
        walkSpeed = 2.f;
        initTexture("res/gobelin.png");
        sprite.scale(1.f, 1.f);
        initSprite();
        sprite.setPosition(8 * SPRITE_SIZE, 19 * SPRITE_SIZE);
    }

    void initAnimation() override {
        sprite.move(walkSpeed, 0);

        if (sprite.getPosition().x > 300 || sprite.getPosition().x < 150) {
            walkSpeed *= -1;
            movingRight = !movingRight;
            sprite.setScale(movingRight ? 1.f : -1.f, 1.f);
        }

        sprite.setTextureRect(sf::IntRect(anim.x* SPRITE_SIZE, anim.y* SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
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
