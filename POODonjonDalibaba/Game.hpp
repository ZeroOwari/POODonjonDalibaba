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
#include "Asset.hpp"
#include "pnj.hpp"

using namespace sf;

class Game {

private:
    bool coffreFerme=true;
    bool inventaireOuvert = false;
    bool PrintInventaire = false;
	bool pause = false;
	bool pKeyReleased = true;
    bool proche_du_coffre = false;
    sf::Music music;
    PNJ* pnj;


protected:
    RenderWindow* window;
    VideoMode videoMode;
    Player* player;
    Monstres* slime;
    Map map;
    View view;
    sf::Font font;
    sf::Text text;
    sf::Texture dialTexture;
    sf::Sprite dial;
    std::string string;
    sf::Texture bTexture;
    sf::Sprite bullet;
    sf::Clock bulletClock;
    int bulletDirection;
    sf::Texture texture3;
    sf::Texture texture2;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
	sf::Texture resumeButtonTexture;
	sf::Sprite resumeButton;
    sf::Texture leaveButtonTexture;
	sf::Sprite leaveButton;

    const int WIN_WIDTH = 800;
    const int WIN_HEIGHT = 576;

    int levelLoaded[450];
    int levelColision[450];
    sf::RectangleShape rects[450];
    bool canShowCollisionDebug = false;
    bool mobDestroyed = false;

    bool bulletActive = false;
    const int Bullet_Speed = 5;
    enum BulletDirection { Down, Left, Right, Up };
public:

    Game() {
        initWindow();
        initPlayer();
        initSlime();
        initMap();
        initMapColision();
        view.setSize(static_cast<float>(WIN_WIDTH), static_cast<float>(WIN_HEIGHT)); // Conversion explicite en float
		initMusic();
        initPNJ();
        initFont();
        initBullet();
        mobDestroyed = false;
        initcoffre();
        initButtons();
    }

    ~Game() {
        delete window;
        delete player;
        delete slime;
        delete pnj;
    }

    void run() {
        while (window->isOpen()) {
            update();
            render();
        }
    }

    void initButtons() {
        if (!resumeButtonTexture.loadFromFile("res/resumebutton.png")) {
            std::cerr << "Erreur lors du chargement de la texture du bouton Resume" << std::endl;
            return;
        }
        resumeButton.setTexture(resumeButtonTexture);

        if (!leaveButtonTexture.loadFromFile("res/leavebutton.png")) {
            std::cerr << "Erreur lors du chargement de la texture du bouton Leave" << std::endl;
            return;
        }
        leaveButton.setTexture(leaveButtonTexture);
    }



    void initFont() {
        if (!font.loadFromFile("fonts/poppins.ttf")) {
            std::cout << "Erreur chargement fonte" << std::endl;
        }
    }

    void initMusic() {
		if (!music.openFromFile("dungeonsound.wav")) {
			std::cerr << "Erreur lors du chargement de la musique" << std::endl;
			return;
		}
		music.setVolume(12);
		music.setLoop(true);
        music.play();
    }

    void initBullet() {
        if (!bTexture.loadFromFile("texture/arrow.png")) {
            std::cerr << "Erreur lors du chargement de l'arrow" << std::endl;
            return;
        }

        bullet.setTexture(bTexture);
    }



    void initcoffre() {

        if (!texture2.loadFromFile("texture/Coffre_final.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
        }
        if (!texture3.loadFromFile("texture/Coffre_final_ouvert.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
        }

        sprite2.setTexture(texture2);



        sprite3.setTexture(texture3);


        sprite2.setPosition(448, 288);
        sprite3.setPosition(448, 288);
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
        this->window = new RenderWindow(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Mon jeu SFML", sf::Style::Fullscreen);
        this->window->setFramerateLimit(60);
        this->window->setVerticalSyncEnabled(false);
    }

    void initPlayer() {
        player = new Player();
    }

    void initSlime() {
        slime = new Monstres();
    }

    void initPNJ() {
        pnj = new PNJ();
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {
            inventaireOuvert = !inventaireOuvert;  // Change l'état de l'inventaire
        }
        if (inventaireOuvert) {
            sf::sleep(sf::milliseconds(200));
            PrintInventaire = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
            PrintInventaire = false;
            inventaireOuvert = false;
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (!bulletActive) {
                bulletActive = true;
                bullet.setPosition(player->getPosition().x + 16, player->getPosition().y + 16);
                bullet.setScale(0.75f, 0.75f);
                bullet.setOrigin(16, 16);
                bulletDirection = player->getDirection();
                bulletClock.restart();
            }
        }
    
  

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            if (pKeyReleased) {
                pause = !pause;
                pKeyReleased = false;
            }
        }
        else {
            pKeyReleased = true;
        }
        player->heroIdle = !isMoving;
        if (isMoving) {
            player->initAnimation();
        }

        canShowCollisionDebug = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    }

    void check_coffre() {
        sf::Vector2f positionPlayer = player->getPosition();
        sf::Vector2f positionPnj = pnj->getPosition();

        if (positionPlayer.x >= 416 && positionPlayer.x <= 480 &&
            positionPlayer.y >= 256 && positionPlayer.y <= 320) {



            const std::string texte1 = "PRESS E ";
            text.setFont(font);
            text.setCharacterSize(18);
            text.setFillColor(sf::Color::White);
            text.setStyle(sf::Text::Bold);
            text.setPosition(view.getCenter().x - WIN_WIDTH / 2 + 55, view.getCenter().y + WIN_HEIGHT / 2 - 106);
            text.setString(texte1);

            //la box de dialogue
            dialTexture.loadFromFile("res/dialbox.png");
            dial.setTexture(dialTexture);
            dial.setPosition(view.getCenter().x - WIN_WIDTH / 2 + 20, view.getCenter().y + WIN_HEIGHT / 2 - 126);
            dial.setScale(1.9f, 0.75f);

            window->draw(dial);
            window->draw(text);
            if (coffreFerme == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
                    coffreFerme = !coffreFerme; // Inverser l'état du coffre
                    sf::sleep(sf::milliseconds(200)); // Pause pour éviter une répétition rapide
                    newPOIDS(2, "Consommable", "Boison_de_papi");



                }
            }
        }
    }


    void update() {
        updatePollEvent();
        if (pause) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                if (pKeyReleased) {
                    pause = !pause;
                    music.play();
                    pKeyReleased = false;
                }
            }
            else {
                pKeyReleased = true;
            }

            // Vérifier si les boutons sont cliqués
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

                if (resumeButton.getGlobalBounds().contains(worldPos)) {
                    pause = false;
                    music.play();
                }
                else if (leaveButton.getGlobalBounds().contains(worldPos)) {
                    window->close();
                }
            }
            return;
        }
        updateInput();
        checkCollision();
        mob();
        view.setCenter(player->getPosition());
    }




    void mob() {
        slime->initAnimation();
        sf::FloatRect herrohITBOX = player->getGlobalBounds(); // Initialiser bulletHitbox
        sf::FloatRect slimeHitbox = slime->getGlobalBounds();
        if (herrohITBOX.intersects(slimeHitbox))
        {
            // On masque la flèche et le monstre !
            mobDestroyed = true;
            bulletActive = false;
        }
    }

    void HandleBullet() {
        if (bulletActive) {
            switch (bulletDirection) {
            case Down:
                bullet.setRotation(270);
                bullet.move(0, Bullet_Speed);
                break;
            case Up:
                bullet.setRotation(90);
                bullet.move(0, -Bullet_Speed);
                break;
            case Left:
                bullet.setRotation(0);
                bullet.move(-Bullet_Speed, 0);
                break;
            case Right:
                bullet.setRotation(180);
                bullet.move(Bullet_Speed, 0);
                break;
            }
            window->draw(bullet);
        }

        if (bulletClock.getElapsedTime().asSeconds() > 1.5f)
        {
            bulletActive = false;
        }

        sf::FloatRect bulletHitbox = bullet.getGlobalBounds(); // Initialiser bulletHitbox
        sf::FloatRect slimeHitbox = slime->getGlobalBounds();
        if (bulletHitbox.intersects(slimeHitbox))
        {
            // On masque la flèche et le monstre !
            mobDestroyed = true;
            bulletActive = false;
            slime->setPosition(10000, 10000);
        }

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

    void renderDialogue() {
        sf::Vector2f positionPlayer = player->getPosition();
        sf::Vector2f positionPnj = pnj->getPosition();
        
        if  (positionPlayer.x >= 278 && positionPlayer.x <= 310 &&
            positionPlayer.y >= 300 && positionPlayer.y <= 374) {
            //le texte 
            const std::string texte1 = "Fait attention aux ennemis";
            text.setFont(font);
            text.setCharacterSize(18);
            text.setFillColor(sf::Color::White);
            text.setStyle(sf::Text::Bold);
            text.setPosition(view.getCenter().x - WIN_WIDTH / 2 + 55, view.getCenter().y + WIN_HEIGHT / 2 - 106);
            text.setString(texte1);

            //la box de dialogue
            dialTexture.loadFromFile("res/dialbox.png");
            dial.setTexture(dialTexture);
            dial.setPosition(view.getCenter().x - WIN_WIDTH / 2 + 20, view.getCenter().y + WIN_HEIGHT / 2 - 126);
            dial.setScale(1.9f, 0.75f);
            
            window->draw(dial);
            window->draw(text);
        }
    }
    
    
    void renderPauseMessage() {
        sf::Text pauseText;
        pauseText.setFont(font);
        pauseText.setCharacterSize(50);
        pauseText.setFillColor(sf::Color::White);
        pauseText.setStyle(sf::Text::Bold);
        pauseText.setString("Pause");
        pauseText.setPosition(view.getCenter().x - pauseText.getGlobalBounds().width / 2, view.getCenter().y - pauseText.getGlobalBounds().height / 2 - 100);
        window->draw(pauseText);

        // Mettre à jour la position des boutons
        resumeButton.setPosition(view.getCenter().x - resumeButton.getGlobalBounds().width / 2, view.getCenter().y - resumeButton.getGlobalBounds().height / 2);
        leaveButton.setPosition(view.getCenter().x - leaveButton.getGlobalBounds().width / 2, view.getCenter().y - leaveButton.getGlobalBounds().height / 2 + 100);

        // Dessiner les boutons
        window->draw(resumeButton);
        window->draw(leaveButton);
    }

    

    void render() {
        window->setView(view);
        window->clear();

        window->draw(map);
        player->render(*window);
        if (!mobDestroyed)
            slime->render(*window);
        pnj->render(*window);
        if (coffreFerme) {
            window->draw(sprite2); // Affiche le coffre ouvert
        }
        else {
            window->draw(sprite3); // Affiche le coffre fermé
        }

        renderDialogue();
        renderColisison();
        if (PrintInventaire == true) {
            Inventaire(*window, *player);
        }
        HandleBullet();
        if (pause == true) {
            renderPauseMessage();
            music.pause();
        }

        check_coffre();
        window->display();
    }
};