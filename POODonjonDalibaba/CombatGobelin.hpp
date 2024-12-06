#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "CharacterGraphique.hpp"

class CombatGobelinWindow {
private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<sf::Text> textBoxes;
    std::vector<sf::RectangleShape> dialogueBoxes;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    //player
    Character player;
    Character enemy1;
    Character enemy2;
    sf::Sprite curseurSprite;
    sf::Texture curseurTexture;

    sf::Text playerHealthText;
    sf::Text enemyHealthText;
    sf::Text enemyHealthText2;

    bool selectingTarget = false;
    int selectedTarget = 0;

    int enemyHealth = 100;
    int enemyHealth2 = 100;

    const std::string defaultMessage = "Attack : A    Objet : O\nGarde : G      Fuir : F";
    bool playerTurn = true;
public:

    CombatGobelinWindow() :player("texture/chevalierIdle.png", font, 100, sf::Vector2f(200, 750), sf::Vector2f(5.f, 5.f)),
        enemy1("res/gobelinCombat.png", font, 100, sf::Vector2f(1350, 760), sf::Vector2f(5.f, 5.f)),
        enemy2("res/gobelinCombat.png", font, 100, sf::Vector2f(1550, 760), sf::Vector2f(5.f, 5.f)) {
        // Paramètres de l'anti-aliasing
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        // Initialisation de la fenêtre avec anti-aliasing
        window.create(sf::VideoMode(1920, 1080), "Combat Gobelin", sf::Style::Fullscreen, settings);

        // Charger les ressources
        font.loadFromFile("fonts/fontRpg.ttf");
        curseurTexture.loadFromFile("texture/curseur.png");

        // Configurer le curseur
        curseurSprite.setTexture(curseurTexture);
        curseurSprite.setPosition(1430, 700);
        curseurSprite.setScale(0.1f, 0.1f);

        // Configurer le fond
        backgroundTexture.loadFromFile("texture/donjon2.png");
        backgroundTexture.setSmooth(true); // Activer le filtre de texture lisse
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setScale(
            window.getSize().x / backgroundSprite.getLocalBounds().width,
            window.getSize().y / backgroundSprite.getLocalBounds().height
        );

        // Configurer les boîtes de dialogue et les textes
        configureDialogueBox(sf::Vector2f(245, 60), sf::Vector2f(0, 1000), defaultMessage);
        configureDialogueBox(sf::Vector2f(320, 60), sf::Vector2f(270, 1000), "Vie : 100/100  Mana : 100/100\nArmure : 20/20");
        configureDialogueBox(sf::Vector2f(320, 60), sf::Vector2f(1300, 1000), "Vie : 100/100  Mana : 100/100");
        configureDialogueBox(sf::Vector2f(600, 60), sf::Vector2f(660, 1000), "");

    }

    void configureHealthText(sf::Text& healthText, const sf::Sprite& sprite, int health) {
        healthText.setFont(font);
        healthText.setCharacterSize(24);
        healthText.setFillColor(sf::Color::Red);
        healthText.setPosition(sprite.getPosition().x, sprite.getPosition().y - 30);
        healthText.setString("HP: " + std::to_string(health));
    }

    void configureDialogueBox(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& message) {
        sf::RectangleShape dialogueBox;
        dialogueBox.setSize(size);
        dialogueBox.setPosition(position);
        dialogueBox.setFillColor(sf::Color(255, 255, 255, 200));
        dialogueBoxes.push_back(dialogueBox);

        sf::Text textBox;
        textBox.setFont(font);
        textBox.setCharacterSize(24);
        textBox.setFillColor(sf::Color::Black);
        textBox.setPosition(position.x + 1, position.y);
        textBox.setString(message);
        textBoxes.push_back(textBox);
    }

    void handleCombatLogic(sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            if (playerTurn) {
                if (selectingTarget) {
                    if (event.key.code == sf::Keyboard::Left) {
                        selectedTarget = (selectedTarget - 1 + 2) % 2; // Gérer deux ennemis
                    }
                    else if (event.key.code == sf::Keyboard::Right) {
                        selectedTarget = (selectedTarget + 1) % 2; // Gérer deux ennemis
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        textBoxes[3].setString("Vous attaquez l'ennemi " + std::to_string(selectedTarget + 1) + " !");
                        attackEnemy(selectedTarget);
                        selectingTarget = false;
                        textBoxes[0].setString(defaultMessage);
                        playerTurn = false;
                    }
                    else if (event.key.code == sf::Keyboard::X) {
                        selectingTarget = false;
                        textBoxes[0].setString(defaultMessage);
                    }

                    if (selectedTarget == 0) {
                        curseurSprite.setPosition(1430, 700);
                    }
                    else {
                        curseurSprite.setPosition(1630, 700);
                    }
                }
                else {
                    if (event.key.code == sf::Keyboard::A) {
                        textBoxes[0].setString("Choisissez une cible :");
                        selectingTarget = true;
                    }
                    else if (event.key.code == sf::Keyboard::O) {
                        textBoxes[3].setString("Vous utilisez un objet !");
                        playerTurn = false;
                    }
                    else if (event.key.code == sf::Keyboard::F) {
                        textBoxes[3].setString("Vous tentez de fuir !");
                        playerTurn = false;
                    }
                    else if (event.key.code == sf::Keyboard::G) {
                        textBoxes[3].setString("Vous mettez votre garde !");
                        playerTurn = false;
                    }
                }
            }
        }
    }

    void enemyTurn() {
        if (!playerTurn) {
            player.health -= 60;
            if (player.health < 0) player.health = 0;
            player.updateHealthText();

            if (player.health == 0) {
                textBoxes[3].setString("Vous avez été vaincu !");
            }
            else {
                playerTurn = true;
            }
        }
    }

    void attackEnemy(int target) {
        int damage = 10;
        if (target == 0) {
            enemy1.health -= damage;
            if (enemy1.health < 0) enemy1.health = 0;
            enemy1.updateHealthText();
            if (enemy1.health == 0) {
                textBoxes[3].setString("Vous avez vaincu l'ennemi 1 !");
                enemy1.sprite.setColor(sf::Color::Transparent); // Rendre l'ennemi invisible
                enemy1.healthText.setString(""); // Masquer les points de vie
                curseurSprite.setPosition(1630, 700);
            }
        }
        else if (target == 1) {
            enemy2.health -= damage;
            if (enemy2.health < 0) enemy2.health = 0;
            enemy2.updateHealthText();
            if (enemy2.health == 0) {
                textBoxes[3].setString("Vous avez vaincu l'ennemi 2 !");
                enemy2.sprite.setColor(sf::Color::Transparent);
                enemy2.healthText.setString("");
                curseurSprite.setPosition(1430, 700);
            }
        }
        // Vérifier la condition de victoire
        if (enemy1.health == 0 && enemy2.health == 0) {
            textBoxes[3].setString("Victoire ! Tous les ennemis sont vaincus !");
        }
    }

    bool isCombatOver() {
        return (player.health == 0 || (enemy1.health == 0 && enemy2.health == 0));
    }

    void runGobelinCombat() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                    window.close();

                handleCombatLogic(event);
            }

            if (!playerTurn) {
                enemyTurn();
            }
            if (isCombatOver()) {
                window.close();
            }

            window.clear();
            // Dessiner les éléments
            window.draw(backgroundSprite);
            window.draw(enemy1.sprite);
            window.draw(enemy2.sprite);
            window.draw(player.sprite);
            window.draw(curseurSprite);
            window.draw(player.healthText);
            window.draw(enemy1.healthText);
            window.draw(enemy2.healthText);
            for (const auto& dialogueBox : dialogueBoxes) {
                window.draw(dialogueBox);
            }
            for (const auto& textBox : textBoxes) {
                window.draw(textBox);
            }

            window.display();
        }
    }
};
