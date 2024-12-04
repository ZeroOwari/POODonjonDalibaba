//#pragma once 
//
//#include "SFML/Graphics.hpp"
//#include <iostream>
//#include <ctime>
//#include "salles.hpp"
//#include "SFML/Audio.hpp"
//#include "SFML/Config.hpp"
//#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
//#include "string"
//#include "Game.hpp"
//#include "calcul_new_poids.hpp"
//#include "Player.hpp"
//
//void Inventaire(sf::RenderWindow& window, const Player& player) {
//    sf::Vector2f playerPosition = player.getPosition();
//
//    const float inventoryWidth = 1000;
//    const float inventoryHeight = 700;
//
//    // Position initiale de l'inventaire par rapport à la position du joueur
//    sf::Vector2f inventoryPosition(playerPosition.x - inventoryWidth / 2, playerPosition.y - inventoryHeight / 2);
//
//    // Chargement de la police
//    sf::Font Police;
//    if (!Police.loadFromFile("fonts/Police.ttf")) {
//        std::cout << "Erreur de chargement de la police!" << std::endl;
//        return;
//    }
//
//    // Chargement des textures
//    sf::Texture Casque;
//    if (!Casque.loadFromFile("C:/Users/quent/sfml/asset/Casque de base.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Plastron;
//    if (!Plastron.loadFromFile("C:/Users/quent/sfml/asset/Plastron.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Pantalon;
//    if (!Pantalon.loadFromFile("C:/Users/quent/sfml/asset/Pantalon.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Chaussure;
//    if (!Chaussure.loadFromFile("C:/Users/quent/sfml/asset/chaussure.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Boisson;
//    if (!Boisson.loadFromFile("C:/Users/quent/sfml/asset/Boisson papi.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Personnage;
//    if (!Personnage.loadFromFile("C:/Users/quent/sfml/asset/Personnage2.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Epee;
//    if (!Epee.loadFromFile("C:/Users/quent/sfml/asset/épée.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Bouclier;
//    if (!Bouclier.loadFromFile("C:/Users/quent/sfml/asset/Bouclier.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    sf::Texture Potion;
//    if (!Potion.loadFromFile("C:/Users/quent/sfml/asset/Potion.png")) {
//        std::cout << "Erreur lors du chargement de la texture" << std::endl;
//        return;
//    }
//
//    // Création des sprites
//    sf::Sprite sprite_casque;
//    sprite_casque.setTexture(Casque);
//
//    sf::Sprite sprite_Plastron;
//    sprite_Plastron.setTexture(Plastron);
//
//    sf::Sprite sprite_Pantalon;
//    sprite_Pantalon.setTexture(Pantalon);
//
//    sf::Sprite sprite_Chaussure;
//    sprite_Chaussure.setTexture(Chaussure);
//
//    sf::Sprite sprite_Boisson;
//    sprite_Boisson.setTexture(Boisson);
//
//    sf::Sprite sprite_Personnage;
//    sprite_Personnage.setTexture(Personnage);
//
//    sf::Sprite sprite_Epee;
//    sprite_Epee.setTexture(Epee);
//
//    sf::Sprite sprite_Bouclier;
//    sprite_Bouclier.setTexture(Bouclier);
//
//    sf::Sprite sprite_Potion;
//    sprite_Potion.setTexture(Potion);
//
//    // Interface Inventaire
//    sf::RectangleShape Case_Inventaire_text(sf::Vector2f(480, 29));
//    Case_Inventaire_text.setFillColor(sf::Color(255, 255, 255, 0));
//    Case_Inventaire_text.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 132);
//    Case_Inventaire_text.setOutlineThickness(3);
//    Case_Inventaire_text.setOutlineColor(sf::Color(255, 255, 255));
//    window.draw(Case_Inventaire_text);
//
//    sf::Text Inventaire_text;
//    Inventaire_text.setFont(Police);
//    Inventaire_text.setString("INVENTAIRE");
//    Inventaire_text.setCharacterSize(19.2);
//    Inventaire_text.setFillColor(sf::Color::White);
//    Inventaire_text.setPosition(inventoryPosition.x + 430, inventoryPosition.y + 132);
//    window.draw(Inventaire_text);
//
//    sf::RectangleShape Inventaire(sf::Vector2f(480, 336));
//    Inventaire.setFillColor(sf::Color(34, 34, 34, 200));
//    Inventaire.setPosition(inventoryPosition.x +260, inventoryPosition.y +200);
//    Inventaire.setOutlineThickness(3);
//    Inventaire.setOutlineColor(sf::Color(255, 255, 255));
//    window.draw(Inventaire);
//
//    // Affichage des catégories et sections
//    sf::Text Personnage_inventaire;
//    Personnage_inventaire.setFont(Police);
//    Personnage_inventaire.setString("Personnage");
//    Personnage_inventaire.setCharacterSize(19.2);
//    Personnage_inventaire.setFillColor(sf::Color::White);
//    Personnage_inventaire.setPosition(inventoryPosition.x + 320, inventoryPosition.y + 165);
//
//    sf::RectangleShape Case_text_Personnage(sf::Vector2f(240, 29));
//    Case_text_Personnage.setFillColor(sf::Color(0, 0, 50, 200)); //0, 0, 50, 200
//    Case_text_Personnage.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 165);
//    Case_text_Personnage.setOutlineThickness(3);
//    Case_text_Personnage.setOutlineColor(sf::Color(255, 255, 255));
//    window.draw(Case_text_Personnage);
//
//    sf::RectangleShape Case_Personnage(sf::Vector2f(240, 252));
//    Case_Personnage.setFillColor(sf::Color(255, 255, 255, 0));
//    Case_Personnage.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 200);
//    Case_Personnage.setOutlineThickness(2);
//    Case_Personnage.setOutlineColor(sf::Color(255, 255, 255));
//    window.draw(Case_Personnage);
//
//    ////////////////////////////////////////////////////////////////////////////////////
//
//
//
//    //// Texte pour Sac à dos
//    sf::Text Sac_a_dos_text;
//    Sac_a_dos_text.setFont(Police);
//    Sac_a_dos_text.setString("Sac à dos");
//    Sac_a_dos_text.setCharacterSize(19.2);
//    Sac_a_dos_text.setFillColor(sf::Color::White);
//    Sac_a_dos_text.setPosition(inventoryPosition.x + 575, inventoryPosition.y + 165);
//
//    sf::RectangleShape Case_sac_a_dos(sf::Vector2f(238, 29));
//    Case_sac_a_dos.setFillColor(sf::Color(0, 0, 50, 200));
//    Case_sac_a_dos.setPosition(inventoryPosition.x + 502, inventoryPosition.y + 165);
//    Case_sac_a_dos.setOutlineThickness(3);
//    Case_sac_a_dos.setOutlineColor(sf::Color(255, 255, 255));
//    window.draw(Case_sac_a_dos);
//
//    // Bouton pour quitter
//    sf::Text PRESS_X;
//    PRESS_X.setFont(Police);
//    PRESS_X.setString("PRESS X TO LEAVE");
//    PRESS_X.setCharacterSize(15);
//    PRESS_X.setFillColor(sf::Color::White);
//    PRESS_X.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 545);
//    window.draw(PRESS_X);
//
//    // Génération des cases de l'inventaire
//    /*int Position_en_y = 440;
//    int MOOVE_DE_Y = 0;
//    int Position_de_x = 260;
//    for (int i = 0; i < 10; i++) {
//        int MOOVE_DE_X = 0;
//        for (int x = 0; x < 9; x++) {
//            MOOVE_DE_X += 55;
//            sf::RectangleShape Case_inventaire_Item(sf::Vector2f(50, 50));
//            Case_inventaire_Item.setFillColor(sf::Color(255, 255, 255, 0));
//            Case_inventaire_Item.setPosition(inventoryPosition.x + Position_de_x + MOOVE_DE_X, inventoryPosition.y + Position_en_y + MOOVE_DE_Y);
//            Case_inventaire_Item.setOutlineThickness(5);
//            Case_inventaire_Item.setOutlineColor(sf::Color(255, 255, 255));
//            window.draw(Case_inventaire_Item);
//        }
//        Position_en_y += 75;
//        MOOVE_DE_Y += 75;
//    }*/
//
//    // Affichage des sprites en utilisant inventoryPosition
//    sprite_casque.setPosition(inventoryPosition.x + 500, inventoryPosition.y + 325);
//    window.draw(sprite_casque);
//
//    sprite_Plastron.setPosition(inventoryPosition.x + 500, inventoryPosition.y + 450);
//    window.draw(sprite_Plastron);
//
//    sprite_Pantalon.setPosition(inventoryPosition.x + 500, inventoryPosition.y + 575);
//    window.draw(sprite_Pantalon);
//
//    sprite_Chaussure.setPosition(inventoryPosition.x + 500, inventoryPosition.y + 700);
//    window.draw(sprite_Chaussure);
//
//    sprite_Epee.setPosition(inventoryPosition.x + 900, inventoryPosition.y + 450);
//    window.draw(sprite_Epee);
//
//    sprite_Bouclier.setPosition(inventoryPosition.x + 900, inventoryPosition.y + 575);
//    window.draw(sprite_Bouclier);
//
//    sprite_Potion.setPosition(inventoryPosition.x + 900, inventoryPosition.y + 325);
//    window.draw(sprite_Potion);
//
//    sprite_Potion.setPosition(inventoryPosition.x + 900, inventoryPosition.y + 700);
//    window.draw(sprite_Potion);
//    int MOOVE_DE_X = 0;
//    for (int y = 0; y < 2; y++) {
//        int MOOVE_DE_Y = 0;
//        for (int x = 0; x < 4; x++) {
//
//
//            sf::RectangleShape Case_inventaire_Item(sf::Vector2f(50, 50));
//            Case_inventaire_Item.setFillColor(sf::Color(255, 255, 255, 0));
//            Case_inventaire_Item.setPosition(inventoryPosition.x + 200 + MOOVE_DE_X, inventoryPosition.y + 200 + MOOVE_DE_Y);
//            Case_inventaire_Item.setOutlineThickness(5);
//            Case_inventaire_Item.setOutlineColor(sf::Color(255, 255, 255));
//            window.draw(Case_inventaire_Item);
//            MOOVE_DE_Y = MOOVE_DE_Y + 25;
//        }
//        MOOVE_DE_X = 500;
//    }
//
//    // Poids de l'inventaire
//    sf::Text Poids_personnage;
//    std::string Poids_de_l_inventaire = "Poids de votre inventaire : " + getPOIDS() + "/100";
//    Poids_personnage.setFont(Police);
//    Poids_personnage.setString(Poids_de_l_inventaire);
//    Poids_personnage.setCharacterSize(20);
//    Poids_personnage.setFillColor(sf::Color::White);
//    Poids_personnage.setPosition(inventoryPosition.x + 480, inventoryPosition.y + 935);
//
//    // Case Poids
//    sf::RectangleShape Case_Poids_inventaire(sf::Vector2f(500, 190));
//    Case_Poids_inventaire.setFillColor(sf::Color(34, 34, 34, 200));
//    Case_Poids_inventaire.setPosition(inventoryPosition.x + 480, inventoryPosition.y + 780);
//    Case_Poids_inventaire.setOutlineThickness(7);
//    Case_Poids_inventaire.setOutlineColor(sf::Color(255, 255, 255));
//    window.draw(Case_Poids_inventaire);
//
//    // Affichage final
//    sprite_Personnage.setPosition(inventoryPosition.x + 330, inventoryPosition.y + 200);
//    window.draw(sprite_Personnage);
//
//    window.draw(Personnage_inventaire);
//    window.draw(Sac_a_dos_text);
//    //window.draw(Poids_personnage);
//}
