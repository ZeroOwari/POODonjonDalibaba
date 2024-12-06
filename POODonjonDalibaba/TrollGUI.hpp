#pragma once
#include "Entity.hpp"

class Troll : public Entity {
public:
    Troll() {
        walkSpeed = 2.f;
        initTexture("res/trollCombat.png");
        initSprite();
        sprite.setScale(2.f, 2.f);
        sprite.setPosition(11 * SPRITE_SIZE, 32 * SPRITE_SIZE);
    }

    void initAnimation() override {
        sprite.setTextureRect(sf::IntRect(anim.x * SPRITE_SIZE, anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

    }
};
