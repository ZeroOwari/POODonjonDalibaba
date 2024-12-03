#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock animClock;
    const int SPRITE_SIZE = 32;
    float walkSpeed = 1.f;

    int hPosX = round(sprite.getPosition().x / SPRITE_SIZE);
    int hPosY = round(sprite.getPosition().y / SPRITE_SIZE);
    sf::Vector2i anim = sf::Vector2i(0, 0);

public:
    virtual void initTexture(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath))
            std::cout << "Erreur chargement texture" << std::endl;
    }

    virtual void initSprite() {
        sprite.setTexture(texture);
        sprite.setPosition(5 * SPRITE_SIZE, 5 * SPRITE_SIZE);
        initAnimation();
    }

    virtual void initAnimation() = 0;

    sf::Sprite& getShape() {
        return sprite;
    }

    int getSpriteSize() const {
        return SPRITE_SIZE;
    }

    void move(const float x, const float y) {
        sprite.move(walkSpeed * x, walkSpeed * y);
    }

    void render(sf::RenderTarget& target) {
        target.draw(sprite);
    }

    sf::Vector2f getPosition() const {
        return sprite.getPosition();
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }
};