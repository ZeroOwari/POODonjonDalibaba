#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Character {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text healthText;
    int health;

    Character(const std::string& textureFile, const sf::Font& font, int initialHealth, const sf::Vector2f& position, const sf::Vector2f& scale) {
        texture.loadFromFile(textureFile);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(scale);

        health = initialHealth;
        healthText.setFont(font);
        healthText.setCharacterSize(24);
        healthText.setFillColor(sf::Color::Red);
        healthText.setPosition(sprite.getPosition().x, sprite.getPosition().y - 30);
        healthText.setString("HP: " + std::to_string(health));
    }

    void updateHealthText() {
        healthText.setString("HP: " + std::to_string(health));
    }
};
