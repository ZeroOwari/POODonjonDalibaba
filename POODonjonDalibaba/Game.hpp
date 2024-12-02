#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <stdlib.h>
#include "Player.hpp"
#include "MonstresGraphique.hpp"
#include "Map.hpp"

using namespace sf;

class Game {
protected:
    RenderWindow* window;
    VideoMode videoMode;
    Player* player;
    Monstres* slime;
    Map map;
    View view;

    const int WIN_WIDTH = 800;
    const int WIN_HEIGHT = 576;

    int levelLoaded[450];
    int levelColision[450];
    sf::RectangleShape rects[450];
    bool canShowCollisionDebug = false;

public:
    Game() {
        initWindow();
        initPlayer();
        initSlime();
        initMap();
        initMapColision();
        view.setSize(static_cast<float>(WIN_WIDTH), static_cast<float>(WIN_HEIGHT)); // Conversion explicite en float
    }

    ~Game() {
        delete window;
        delete player;
        delete slime;
    }

    void run() {
        while (window->isOpen()) {
            update();
            render();
        }
    }

    void initMap() {
        if (!map.loadFromFile("res/map1.txt", levelLoaded, 450)) {
            std::cerr << "Erreur lors du chargement de la carte" << std::endl;
            return;
        }

        if (!map.load("res/tileset.png", sf::Vector2u(player->getSpriteSize(), player->getSpriteSize()), levelLoaded, map.COL_COUNT, map.ROW_COUNT)) {
            std::cerr << "Erreur lors du chargement de la carte" << std::endl;
        }
    }

    void initMapColision() {
        if (!map.loadFromFile("res/map1_colision.txt", levelColision, 450)) {
            std::cerr << "Erreur lors du chargement de la carte de collision" << std::endl;
            return;
        }
    }

    void initWindow() {
        this->window = new RenderWindow(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Mon jeu SFML", Style::Default);
        this->window->setFramerateLimit(60);
        this->window->setVerticalSyncEnabled(false);
    }

    void initPlayer() {
        player = new Player();
    }

    void initSlime() {
        slime = new Monstres();
    }

    void updatePollEvent() {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
                window->close();
        }
    }

    void updateInput() {
        bool isMoving = false;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            player->setDirection(Player::Left);
            player->move(-1.f, 0.f);
            isMoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player->setDirection(Player::Right);
            player->move(1.f, 0.f);
            isMoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            player->setDirection(Player::Up);
            player->move(0.f, -1.f);
            isMoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player->setDirection(Player::Down);
            player->move(0.f, 1.f);
            isMoving = true;
        }

        player->heroIdle = !isMoving;
        if (isMoving) {
            player->initAnimation();
        }

        canShowCollisionDebug = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    }

    void update() {
        updatePollEvent();
        updateInput();
        checkCollision();
        slime->initAnimation();
        view.setCenter(player->getPosition());
    }

    void renderColisison() {
        for (unsigned int j = 0; j < 18; ++j) {
            for (unsigned int i = 0; i < 25; ++i) {
                if (levelColision[(i + j * 25)] == 1) {
                    sf::Vector2f pos = sf::Vector2f(static_cast<float>(i * player->getSpriteSize()), static_cast<float>(j * player->getSpriteSize())); // Conversion explicite en float
                    rects[(i + j * 25)].setPosition(pos);
                    rects[(i + j * 25)].setSize(sf::Vector2f(static_cast<float>(player->getSpriteSize()), static_cast<float>(player->getSpriteSize()))); // Conversion explicite en float
                    rects[(i + j * 25)].setFillColor(Color(250, 0, 0, 100));
                    if (canShowCollisionDebug)
                        window->draw(rects[(i + j * 25)]);
                }
            }
        }
    }

    void checkCollision() {
        sf::FloatRect playerBounds = player->getShape().getGlobalBounds();
        for (unsigned int j = 0; j < 18; ++j) {
            for (unsigned int i = 0; i < 25; ++i) {
                if (levelColision[(i + j * 25)] == 1) {
                    sf::FloatRect tileBounds(static_cast<float>(i * player->getSpriteSize()), static_cast<float>(j * player->getSpriteSize()), static_cast<float>(player->getSpriteSize()), static_cast<float>(player->getSpriteSize())); // Conversion explicite en float
                    if (playerBounds.intersects(tileBounds)) {
                        // Ajuster la position du joueur en fonction de la collision
                        if (player->getDirection() == Player::Left) {
                            player->setPosition(tileBounds.left + tileBounds.width, player->getPosition().y);
                        }
                        else if (player->getDirection() == Player::Right) {
                            player->setPosition(tileBounds.left - playerBounds.width, player->getPosition().y);
                        }
                        else if (player->getDirection() == Player::Up) {
                            player->setPosition(player->getPosition().x, tileBounds.top + tileBounds.height);
                        }
                        else if (player->getDirection() == Player::Down) {
                            player->setPosition(player->getPosition().x, tileBounds.top - playerBounds.height);
                        }
                    }
                }
            }
        }

        // Empêcher le joueur de sortir de la carte
        sf::Vector2f playerPos = player->getPosition();
        if (playerPos.x < 0) {
            player->setPosition(0, playerPos.y);
        }
        if (playerPos.y < 0) {
            player->setPosition(playerPos.x, 0);
        }
        if (playerPos.x + playerBounds.width > map.COL_COUNT * player->getSpriteSize()) {
            player->setPosition(map.COL_COUNT * player->getSpriteSize() - playerBounds.width, playerPos.y);
        }
        if (playerPos.y + playerBounds.height > map.ROW_COUNT * player->getSpriteSize()) {
            player->setPosition(playerPos.x, map.ROW_COUNT * player->getSpriteSize() - playerBounds.height);
        }
    }

    void render() {
        window->setView(view);
        window->clear();

        window->draw(map);
        player->render(*window);
        slime->render(*window);
        renderColisison();

        window->display();
    }
};
