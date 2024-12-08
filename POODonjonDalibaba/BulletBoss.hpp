#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class BulletBoss {
public:
    sf::Sprite bullet;
    sf::Vector2f direction;
    float speed;
    bool isActive;

    BulletBoss(const sf::Texture& texture, const sf::Vector2f& startPosition, const sf::Vector2f& targetPosition, float speed)
        : speed(speed), isActive(true) {
        bullet.setTexture(texture);
        bullet.setPosition(startPosition);

        // Calculer la direction du projectile
        direction = targetPosition - startPosition;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) {
            direction /= length; // Normaliser le vecteur de direction
        }
    }

    void update() {
        if (isActive) {
            bullet.move(direction * speed);
        }
    }
};