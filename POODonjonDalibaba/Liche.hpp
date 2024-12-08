#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include <vector>
#include "BulletBoss.hpp"

class Liche : public Entity {
private:
    sf::Font font;
    sf::Text txt;
    sf::Texture dialTexture;
    sf::Sprite dial;
    int sprite_size = 57;
    sf::FloatRect salleLiche;
    sf::Texture BulletBossTexture;
    std::vector<BulletBoss> bulletBoss;
    sf::Clock shootClock;
    float shootInterval = 2.0f;
public:
    Liche() {
        initTexture("res/liche.png");
        sprite.scale(2.f,2.f);
        initSprite();
        sprite.setPosition(34 * 32, 23 * 32);
        salleLiche = sf::FloatRect(24 * 32, 10 * 32, 20 * 32, 20 * 32); // x, y, width, height

        if (!BulletBossTexture.loadFromFile("res/sphereliche.png")) {
            std::cerr << "Erreur lors du chargement de la texture du projectile" << std::endl;
        }
    }

    void initAnimation() override {
        sprite.setTextureRect(sf::IntRect(anim.x * sprite_size, anim.y * sprite_size, sprite_size, sprite_size));

    }

    void moveToPlayer(const sf::Vector2f& playerPosition) {
        sf::Vector2f lichePosition = sprite.getPosition();
        sf::Vector2f direction = playerPosition - lichePosition;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (length != 0) {
            direction /= length;
        }

        sprite.move(direction * walkSpeed);
    }

    bool isPlayerInSalle(const sf::Vector2f& playerPosition) {
        return salleLiche.contains(playerPosition);
    }

    void shootAtPlayer(const sf::Vector2f& playerPosition) {
        if (shootClock.getElapsedTime().asSeconds() >= shootInterval) {
            bulletBoss.emplace_back(BulletBossTexture, sprite.getPosition(), playerPosition, 5.0f);
            shootClock.restart();
        }
    }

    void updateBossBullet() {
        for (auto& projectile : bulletBoss) {
            projectile.update();
        }
    }

    void drawProjectiles(sf::RenderWindow& window) {
        for (const auto& bullet : bulletBoss) {
            if (bullet.isActive) {
                window.draw(bullet.bullet);
            }
        }
    }
    std::vector<BulletBoss>& getProjectiles() {
        return bulletBoss;
    }
};
