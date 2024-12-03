#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

class PNJ : public Entity {
private:
    sf::Font font;
    sf::Text txt;
    sf::Texture dialTexture;
    sf::Sprite dial;
    bool recompenseOk = false;
    int po = 0;
    bool dialMerci = false;

public:
    PNJ() {
        initTexture("res/pnj.png");
        sprite.scale(0.7f, 0.7f);
        initSprite();
    }

    void initAnimation() override {
        sprite.setTextureRect(sf::IntRect(anim.x * SPRITE_SIZE, anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

    }
};
