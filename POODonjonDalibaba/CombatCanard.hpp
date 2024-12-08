#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "CharacterGraphique.hpp"

class CombatCanardWindow {
private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<sf::Text> textBoxes;
    std::vector<sf::RectangleShape> dialogueBoxes;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    //player
    Character player;
    Character canard;
    sf::Sprite curseurSprite;
    sf::Texture curseurTexture;

    sf::Text playerHealthText;
    sf::Text canardHealthText;

    bool selectingTarget = false;
    int selectedTarget = 0;

    const std::string defaultMessage = "Attack : A    Objet : O\nGarde : G      Fuir : F";
    bool playerTurn = true;

    int canardForce = 7;
    int playerForce = 12;

public:
    CombatCanardWindow() : player("texture/chevalierIdle.png", font, 100, sf::Vector2f(200, 750), sf::Vector2f(5.f, 5.f)),
        canard("res/canardIdle.png", font, 20, sf::Vector2f(1350, 780), sf::Vector2f(3.f, 3.f)) {

        // Paramètres de l'anti-aliasing
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        // Initialisation de la fenêtre avec anti-aliasing
        window.create(sf::VideoMode(1920, 1080), "Combat canard", sf::Style::Fullscreen, settings);

        // Charger les ressources
        font.loadFromFile("fonts/fontRpg.ttf");
        curseurTexture.loadFromFile("texture/curseur.png");

        // Configurer le curseur
        curseurSprite.setTexture(curseurTexture);
        curseurSprite.setScale(0.1f, 0.1f);
        updateCurseurPosition();


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

        // Initialiser les points de vie
        configureHealthText(playerHealthText, player.sprite, player.health);
        configureHealthText(canardHealthText, canard.sprite, canard.health);
    }

    void updateCurseurPosition() {
        curseurSprite.setPosition(canard.sprite.getPosition().x + 60, canard.sprite.getPosition().y + 50 - curseurSprite.getGlobalBounds().height - 10);
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


    int lancerDe() {
        return std::rand() % 20 + 1;
    }
    void handleCombatLogic(sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            if (playerTurn) {
                if (selectingTarget) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        textBoxes[3].setString("Vous attaquez l'ennemi !");
                        attackEnemy(0);
                        selectingTarget = false;
                        textBoxes[0].setString(defaultMessage);
                        playerTurn = false;
                    }
                    else if (event.key.code == sf::Keyboard::X) {
                        selectingTarget = false;
                        textBoxes[0].setString(defaultMessage);
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
            int de = lancerDe();
            if (de > canardForce) {
                player.health -= 2;
                if (player.health < 0) player.health = 0;
                configureHealthText(playerHealthText, player.sprite, player.health); // Mettre à jour le texte de santé

                if (player.health == 0) {
                    textBoxes[3].setString("Vous avez ete vaincu !");
                }
                else {
                    textBoxes[2].setString("L'ennemi vous attaque !");
                }
            }
            else {
                textBoxes[2].setString("L'ennemi a rate son attaque !");
            }
            playerTurn = true;
        }
    }

    void attackEnemy(int target) {
        int de = lancerDe();
        if (de > playerForce) {
            int damage = 10;
            if (target == 0) {
                canard.health -= damage;
                if (canard.health < 0) canard.health = 0;
                configureHealthText(canardHealthText, canard.sprite, canard.health); // Mettre à jour le texte de santé
                if (canard.health == 0) {
                    textBoxes[3].setString("Vous avez vaincu le canard !");
                    canard.sprite.setColor(sf::Color::Transparent); // Rendre l'ennemi invisible
                    canard.healthText.setString(""); // Masquer les points de vie
                    curseurSprite.setPosition(1630, 700);
                }
            }
            // Vérifier la condition de victoire
            if (canard.health == 0) {
                textBoxes[3].setString("Victoire ! Tous les ennemis sont vaincus !");
            }
        }
        else {
            textBoxes[3].setString("Vous avez rate votre attaque !");
        }
    }

    bool isCombatOver() {
        return (player.health == 0 || canard.health == 0);
    }

    void runCanardCombat() {
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
            window.draw(canard.sprite);
            window.draw(player.sprite);
            window.draw(curseurSprite);
            window.draw(playerHealthText);
            window.draw(canardHealthText);
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