#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <stdlib.h>
#include "Player.hpp"
#include "SlimeGUI.hpp"
#include "Map.hpp"
#include "Asset.hpp"
#include "pnj.hpp"
#include "CombatSlime.hpp"
#include "CombatGobelin.hpp"
#include "CombatTroll.hpp"
#include "GobelinGUI.hpp"
#include "TrollGUI.hpp"

using namespace sf;

class Game {

private:
    bool coffreFerme=true;
    bool inventaireOuvert = false;
    bool PrintInventaire = false;
	bool pause = false;
	bool pKeyReleased = true;
    bool proche_du_coffre = false;
	bool IsStarting = true;
    bool dialogueRecompense = false;
    bool recompense = false;
    sf::Music music;
    PNJ* pnj;


protected:
    RenderWindow* window;
    VideoMode videoMode;
    Player* player;
    Slime* slime;
    Gobelin* gobelin;
    Troll* troll;
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
    sf::Texture StartButtonTexture;
	sf::Sprite startButton;
	sf::Texture StartBackgroundTexture;
	sf::Sprite startBackground;

    const int WIN_WIDTH = 800;
    const int WIN_HEIGHT = 576;

    int levelLoaded[2500];
    int levelColision[2500];
    sf::RectangleShape rects[2500];
    bool canShowCollisionDebug = false;
    bool slimeDestroyed = false;
    bool gobelinDestroyed = false;
    bool trollDestroyed = false;

    bool bulletActive = false;
    const int Bullet_Speed = 5;
    enum BulletDirection { Down, Left, Right, Up };
    bool inCombat;
public:

    Game() {
        initWindow();
        initPlayer();
        initSlime();
        initGobelin();
        initTroll();
        initMap();
        initMapColision();
        view.setSize(static_cast<float>(WIN_WIDTH), static_cast<float>(WIN_HEIGHT)); // Conversion explicite en float
        initMusic();
        initPNJ();
        initFont();
        initBullet();
        slimeDestroyed = false;
        gobelinDestroyed = false;
        trollDestroyed = false;
        initcoffre();
        initButtons();
        initStartMenu(); // Initialiser le menu de démarrage
    }


    ~Game() {
        delete window;
        delete player;
        delete slime;
        delete pnj;
        delete gobelin;
        delete troll;
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

		if (!StartButtonTexture.loadFromFile("res/startbutton.png")) {
			std::cerr << "Erreur lors du chargement de la texture du bouton Start" << std::endl;
			return;
		}
    }

    void initStartMenu() {
        if (!StartBackgroundTexture.loadFromFile("res/startbackground.png")) {
            std::cerr << "Erreur lors du chargement de la texture du fond" << std::endl;
            return;
        }
        startBackground.setTexture(StartBackgroundTexture);
        startBackground.setScale(
            static_cast<float>(WIN_WIDTH) / StartBackgroundTexture.getSize().x,
            static_cast<float>(WIN_HEIGHT) / StartBackgroundTexture.getSize().y
        );
        startBackground.setPosition(100, 220);

        if (!StartButtonTexture.loadFromFile("res/startbutton.png")) {
            std::cerr << "Erreur lors du chargement de la texture du bouton Start" << std::endl;
            return;
        }
        startButton.setTexture(StartButtonTexture);
        startButton.setPosition(675, 675);
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

        sprite2.setPosition(288, 160);
        sprite3.setPosition(288, 160);

    }

    void initMap() {
        if (!map.loadFromFile("res/map1.txt", levelLoaded, 2500)) {
            std::cerr << "Erreur lors du chargement de la carte" << std::endl;
            return;
        }

        if (!map.load("res/tileset.png", sf::Vector2u(player->getSpriteSize(), player->getSpriteSize()), levelLoaded, map.COL_COUNT, map.ROW_COUNT)) {
            std::cerr << "Erreur lors du chargement de la carte" << std::endl;
        }
    }

    void initMapColision() {
        if (!map.loadFromFile("res/map1_colision.txt", levelColision, 2500)) {
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
        slime = new Slime();
    }

    void initGobelin() {
        gobelin = new Gobelin();
    }

    void initPNJ() {
        pnj = new PNJ();
    }

    void initTroll() {
        troll = new Troll();
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

        if (positionPlayer.x >= 256 && positionPlayer.x <= 320 &&
            positionPlayer.y >= 192 && positionPlayer.y <= 256) {


            if (coffreFerme == true) {
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
    }


    void update() {
        updatePollEvent();
        if (IsStarting) {
            // Vérifier si le bouton Start est cliqué
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

                if (startButton.getGlobalBounds().contains(worldPos)) {
                    IsStarting = false;
                    music.play();
                }
            }
            return;
        }

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
        slimeMovement();
        gobelinMovement();
        trollMovement();
        view.setCenter(player->getPosition());
    }
    void trollMovement() {
        troll->initAnimation();
        sf::FloatRect herrohitbox = player->getGlobalBounds(); // Initialiser bulletHitbox
        sf::FloatRect trollHitbox = troll->getGlobalBounds();
        if (herrohitbox.intersects(trollHitbox))
        {
            // On masque la flèche et le monstre !
            trollDestroyed = true;
            bulletActive = false;
            handleCombatTroll();
            troll->setPosition(100000, 10000);
        }
    }

    void gobelinMovement() {
        gobelin->initAnimation();
        sf::FloatRect herrohitbox = player->getGlobalBounds(); // Initialiser bulletHitbox
        sf::FloatRect gobelinHitbox = gobelin->getGlobalBounds();
        if (herrohitbox.intersects(gobelinHitbox))
        {
            // On masque la flèche et le monstre !
            gobelinDestroyed = true;
            bulletActive = false;
            handleCombatGobelin();
            gobelin->setPosition(100000, 10000);
        }
    }

    void slimeMovement() {
        slime->initAnimation();
        sf::FloatRect herrohitbox = player->getGlobalBounds(); // Initialiser bulletHitbox
        sf::FloatRect slimeHitbox = slime->getGlobalBounds();
        if (herrohitbox.intersects(slimeHitbox))
        {
            // On masque la flèche et le monstre !
            slimeDestroyed = true;
            bulletActive = false;
            handleCombatSlime();
            slime->setPosition(100000, 10000);
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
        sf::FloatRect gobelinHitbox = gobelin->getGlobalBounds();
        sf::FloatRect trollHitbox = troll->getGlobalBounds();
        if (bulletHitbox.intersects(slimeHitbox))
        {
            // On masque la flèche et le monstre !
            slimeDestroyed = true;
            bulletActive = false;
            handleCombatSlime();
            slime->setPosition(100000, 10000);
        }

        if (bulletHitbox.intersects(gobelinHitbox))
        {
            // On masque la flèche et le monstre !
            gobelinDestroyed = true;
            bulletActive = false;
            handleCombatGobelin();
            gobelin->setPosition(100000, 10000);
        }

        if (bulletHitbox.intersects(trollHitbox))
        {
            // On masque la flèche et le monstre !
            trollDestroyed = true;
            bulletActive = false;
            handleCombatTroll();
            troll->setPosition(100000, 10000);
        }

    }
    void renderColisison() {
        for (unsigned int j = 0; j < 50; ++j) {
            for (unsigned int i = 0; i < 50; ++i) {
                if (levelColision[(i + j * 50)] == 1) {
                    sf::Vector2f pos = sf::Vector2f(static_cast<float>(i * player->getSpriteSize()), static_cast<float>(j * player->getSpriteSize())); // Conversion explicite en float
                    rects[(i + j * 50)].setPosition(pos);
                    rects[(i + j * 50)].setSize(sf::Vector2f(static_cast<float>(player->getSpriteSize()), static_cast<float>(player->getSpriteSize()))); // Conversion explicite en float
                    rects[(i + j * 50)].setFillColor(Color(250, 0, 0, 100));
                    if (canShowCollisionDebug)
                        window->draw(rects[(i + j * 50)]);
                }
            }
        }
    }

    void checkCollision() {
        sf::FloatRect playerBounds = player->getShape().getGlobalBounds();
        for (unsigned int j = 0; j < 50; ++j) {
            for (unsigned int i = 0; i < 50; ++i) {
                if (levelColision[(i + j * 50)] == 1) {
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

    void setText(Text& txt, String str) {
        //le texte
        text.setFont(font);
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        text.setPosition(view.getCenter().x - WIN_WIDTH / 2 + 55, view.getCenter().y + WIN_HEIGHT / 2 - 106);
        text.setString(str);

        //la box de dialogue
        dialTexture.loadFromFile("res/dialbox.png");
        dial.setTexture(dialTexture);
        dial.setPosition(view.getCenter().x - WIN_WIDTH / 2 + 20, view.getCenter().y + WIN_HEIGHT / 2 - 126);
        dial.setScale(1.9f, 0.75f);
        if (str != "") {
            window->draw(dial);
            window->draw(txt);
        }
    }
    void DialoguePnj() {    
        sf::Vector2f positionPlayer = player->getPosition();
        sf::Vector2f positionPnj = pnj->getPosition();
        
        if  (positionPlayer.x >= 96 && positionPlayer.x <= 160 && 
            positionPlayer.y >= 160 && positionPlayer.y <= 192) {
            
            if (!slimeDestroyed)
                setText(text, "He toi la, aide moi, va tuer l'ennemi juste en dessous !");
            else {
                if (!dialogueRecompense) {
                    setText(text, "Merci aventurier, voila une cle pour ce coffre !");
                    recompense = true;
                }
                else {
                    setText(text, "Fait attention au ennemi et au piege, il y en a beaucoup !");
                }
            }
        }
        else {
            setText(text, "");
            if (recompense)
                dialogueRecompense = true;
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

    void renderStartMenu() {
        window->clear();
        window->draw(startBackground);
        window->draw(startButton);
        window->display();
    }

    void handleCombatSlime() {
        CombatSlimeWindow combatWindow;
        combatWindow.runSlimeCombat();
        inCombat = false;
    }

    void handleCombatGobelin() {
        CombatGobelinWindow combatGobelinWindow;
        combatGobelinWindow.runGobelinCombat();
        inCombat = false;
    }

    void handleCombatTroll() {
        CombatTrollWindow combatTrollWindow;
        combatTrollWindow.runTrollCombat();
        inCombat = false;
    }

    void render() {
        window->setView(view);
        window->clear();

        if (IsStarting) {
            renderStartMenu();
            return;
        }

        window->draw(map);
        player->render(*window);
        if (!slimeDestroyed)
            slime->render(*window);
        if (!gobelinDestroyed)
            gobelin->render(*window);
        if (!trollDestroyed)
            troll->render(*window);
        pnj->render(*window);
        if (coffreFerme) {
            window->draw(sprite2); // Affiche le coffre ouvert
        }
        else {
            window->draw(sprite3); // Affiche le coffre fermé
        }

        DialoguePnj();
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