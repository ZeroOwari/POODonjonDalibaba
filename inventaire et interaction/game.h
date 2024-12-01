/*
#pragma once
#include <vector>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

class Game {
private:
    RenderWindow* window;
    VideoMode videoMode;
    Event event;

    Vector2i mousePosWindow;
    Vector2f mousePosView;

    bool endGame = false;
    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;

    //Game object
    std::vector<RectangleShape> enemies;
    RectangleShape enemy;

    void initVariable();
    void initWindow();
    void initEnemies();
public:
    Game();
    virtual ~Game();

    const bool running() const;

    void spawnEnemy();
    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void renderEnemies();
    void update();
    void render();
};          
*/