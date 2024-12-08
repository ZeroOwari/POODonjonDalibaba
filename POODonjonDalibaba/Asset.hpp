#pragma once 

#include "SFML/Graphics.hpp"
#include <iostream>
#include <ctime>
#include "SFML/Audio.hpp"
#include "SFML/Config.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "string"
#include "Game.hpp"
#include "calcul_new_poids.hpp"
#include "Player.hpp"



int position_associer_x;
int position_associer_y;


bool checkcase1 = false;
bool checkcase2 = false;
bool checkcase3 = false;
bool checkcase4 = false;
bool checkcase5 = false;
bool checkcase6 = false;
bool checkcase7 = false;
bool checkcase8 = false;
bool checkcase9 = false;
bool checkcase10 = false;





bool boisson_de_papi = false;
bool calcul_de_position_boisson_de_papi =false;
int position_boisson_de_papi[2];


bool bierre = false;
bool calcul_de_position_bierre = false;
int position_bierre[2];

bool potion_humoristique = false;
bool calcul_de_position_potion_humoristique = false;
int position_potion_humoristique[2];

bool clef_rouillee = false;
bool calcul_de_position_clef_rouillee = false;
int position_clef_rouillee[2];

bool Potion_d_intelligence_discutable = false;
bool calcul_de_position_Potion_d_intelligence_discutable = false;
int position_Potion_d_intelligence_discutable[2];

bool Chaussures_de_discrétion_bruyante = false;
bool calcul_de_position_Chaussures_de_discrétion_bruyante = false;
int position_Chaussures_de_discrétion_bruyante[2];

bool Épée_émoussée = false;
bool calcul_de_position_Épée_émoussée = false;
int position_Épée_émoussée[2];

bool Potion_de_soin_majeur = false;
bool calcul_de_position_Potion_de_soin_majeur = false;
int position_Potion_de_soin_majeur[2]; 

bool Sceptre_de_la_Supériorité_Syntaxique = false;
bool calcul_de_position_Sceptre_de_la_Supériorité_Syntaxique = false;
int position_Sceptre_de_la_Supériorité_Syntaxique[2];


bool Livre_des_règles_perdues = false;
bool calcul_de_position_Livre_des_règles_perdues = false;
int position_Livre_des_règles_perdues[2];





void Inventaire(sf::RenderWindow& window, const Player& player, string nom_de_l_item) {

    sf::Vector2f playerPosition = player.getPosition();

    const float inventoryWidth = 1000;
    const float inventoryHeight = 700;

    // Position initiale de l'inventaire par rapport à la position du joueur
    sf::Vector2f inventoryPosition(playerPosition.x - inventoryWidth / 2, playerPosition.y - inventoryHeight / 2);

    // Chargement de la police
    sf::Font Police;
    if (!Police.loadFromFile("fonts/Police.ttf")) {
        std::cout << "Erreur de chargement de la police!" << std::endl;
        return;
    }

    // Chargement des textures
    sf::Texture Casque;
    if (!Casque.loadFromFile("res/Casque de base.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Plastron;
    if (!Plastron.loadFromFile("res/Plastron.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Pantalon;
    if (!Pantalon.loadFromFile("res/Pantalon.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Chaussure;
    if (!Chaussure.loadFromFile("res/chaussure.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Boisson_de_papi;
    if (!Boisson_de_papi.loadFromFile("res/Boisson papi.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Bierre;
    if (!Bierre.loadFromFile("res/potion_de_bierre.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Personnage;
    if (!Personnage.loadFromFile("res/Personnage2.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Epee;
    if (!Epee.loadFromFile("res/épée.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Bouclier;
    if (!Bouclier.loadFromFile("res/Bouclier.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Potion;
    if (!Potion.loadFromFile("res/Potion.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Dragon;
    if (!Dragon.loadFromFile("res/Dragon.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }
    sf::Texture Clef_rouille;
    if (!Clef_rouille.loadFromFile("res/clef rouillé.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }
    sf::Texture tex_potion_humoristique;
    if (!tex_potion_humoristique.loadFromFile("res/potion_humoristique.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }
    sf::Texture tex_potion_dintelligence_discutable;
    if (!tex_potion_dintelligence_discutable.loadFromFile("res/potion_dintelligence_discutable.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Chaussures_de_discretion_bruyante;
    if (!Chaussures_de_discretion_bruyante.loadFromFile("res/Chaussures_de_discretion_bruyante.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture tex_Potion_de_soin_majeur;
    if (!tex_Potion_de_soin_majeur.loadFromFile("res/Potion_de_soin_majeur.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture epee_emousee;
    if (!epee_emousee.loadFromFile("res/epee_emousee.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }
    sf::Texture Livre_des_regles_perdues;
    if (!Livre_des_regles_perdues.loadFromFile("res/Livre_des_regles_perdues.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }

    sf::Texture Sceptre_de_la_Superiorite_Syntaxique;
    if (!Sceptre_de_la_Superiorite_Syntaxique.loadFromFile("res/Sceptre_de_la_Superiorite_Syntaxique.png")) {
        std::cout << "Erreur lors du chargement de la texture" << std::endl;
        return;
    }



    // Création des sprites
    sf::Sprite sprite_casque;
    sprite_casque.setTexture(Casque);

    sf::Sprite sprite_Plastron;
    sprite_Plastron.setTexture(Plastron);

    sf::Sprite sprite_Pantalon;
    sprite_Pantalon.setTexture(Pantalon);

    sf::Sprite sprite_Chaussure;
    sprite_Chaussure.setTexture(Chaussure);

    sf::Sprite sprite_Boisson;
    sprite_Boisson.setTexture(Boisson_de_papi);

    sf::Sprite sprite_Bierre;
    sprite_Bierre.setTexture(Bierre);

    sf::Sprite sprite_Personnage;
    sprite_Personnage.setTexture(Personnage);

    sf::Sprite sprite_Epee;
    sprite_Epee.setTexture(Epee);

    sf::Sprite sprite_Bouclier;
    sprite_Bouclier.setTexture(Bouclier);

    sf::Sprite sprite_Potion;
    sprite_Potion.setTexture(Potion);

    sf::Sprite sprite_Dragon;
    sprite_Dragon.setTexture(Dragon);

    /////////////////////////////////////////////////////////////

    sf::Sprite sprite_Clef_rouille;
    sprite_Clef_rouille.setTexture(Clef_rouille);


    sf::Sprite sprite_potion_humoristique;
    sprite_potion_humoristique.setTexture(tex_potion_humoristique);

    sf::Sprite sprite_potion_dintelligence_discutable;
    sprite_potion_dintelligence_discutable.setTexture(tex_potion_dintelligence_discutable);

    sf::Sprite sprite_Chaussures_de_discretion_bruyante;
    sprite_Chaussures_de_discretion_bruyante.setTexture(Chaussures_de_discretion_bruyante);

    sf::Sprite sprite_Potion_de_soin_majeur;
    sprite_Potion_de_soin_majeur.setTexture(tex_Potion_de_soin_majeur);

    sf::Sprite sprite_epee_emousee;
    sprite_epee_emousee.setTexture(epee_emousee);

    sf::Sprite sprite_Livre_des_regles_perdues;
    sprite_Livre_des_regles_perdues.setTexture(Livre_des_regles_perdues);

    sf::Sprite sprite_Sceptre_de_la_Superiorite_Syntaxique;
    sprite_Sceptre_de_la_Superiorite_Syntaxique.setTexture(Sceptre_de_la_Superiorite_Syntaxique);



    // Interface Inventaire


    // logo 

    sprite_Dragon.setPosition(inventoryPosition.x + 520, inventoryPosition.y + 270);
    window.draw(sprite_Dragon);

    sf::RectangleShape Case_Inventaire_text(sf::Vector2f(480, 29));
    Case_Inventaire_text.setFillColor(sf::Color(0, 0, 0, 200));
    Case_Inventaire_text.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 132);
    Case_Inventaire_text.setOutlineThickness(3);
    Case_Inventaire_text.setOutlineColor(sf::Color(255, 255, 255));
    window.draw(Case_Inventaire_text);

    sf::Text Inventaire_text;
    Inventaire_text.setFont(Police);
    Inventaire_text.setString("INVENTAIRE");
    Inventaire_text.setCharacterSize(19.2);
    Inventaire_text.setFillColor(sf::Color::White);
    Inventaire_text.setPosition(inventoryPosition.x + 430, inventoryPosition.y + 132);
    window.draw(Inventaire_text);

    sf::RectangleShape Inventaire(sf::Vector2f(480, 336));
    Inventaire.setFillColor(sf::Color(34, 34, 34, 200));
    Inventaire.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 200);
    Inventaire.setOutlineThickness(3);
    Inventaire.setOutlineColor(sf::Color(255, 255, 255));
    window.draw(Inventaire);

    // Affichage des catégories et sections
    sf::Text Personnage_inventaire;
    Personnage_inventaire.setFont(Police);
    Personnage_inventaire.setString("Personnage");
    Personnage_inventaire.setCharacterSize(19.2);
    Personnage_inventaire.setFillColor(sf::Color::White);
    Personnage_inventaire.setPosition(inventoryPosition.x + 320, inventoryPosition.y + 165);

    sf::RectangleShape Case_text_Personnage(sf::Vector2f(240, 29));
    Case_text_Personnage.setFillColor(sf::Color(0, 0, 50, 200)); //0, 0, 50, 200
    Case_text_Personnage.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 165);
    Case_text_Personnage.setOutlineThickness(3);
    Case_text_Personnage.setOutlineColor(sf::Color(255, 255, 255));
    window.draw(Case_text_Personnage);

    sf::RectangleShape Case_Personnage(sf::Vector2f(240, 252));
    Case_Personnage.setFillColor(sf::Color(255, 255, 255, 0));
    Case_Personnage.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 200);
    Case_Personnage.setOutlineThickness(2);
    Case_Personnage.setOutlineColor(sf::Color(255, 255, 255));
    window.draw(Case_Personnage);

    ////////////////////////////////////////////////////////////////////////////////////



    //// Texte pour Sac à dos
    sf::Text Sac_a_dos_text;
    Sac_a_dos_text.setFont(Police);
    Sac_a_dos_text.setString("Sac à dos");
    Sac_a_dos_text.setCharacterSize(19.2);
    Sac_a_dos_text.setFillColor(sf::Color::White);
    Sac_a_dos_text.setPosition(inventoryPosition.x + 575, inventoryPosition.y + 165);

    sf::RectangleShape Case_sac_a_dos(sf::Vector2f(238, 29));
    Case_sac_a_dos.setFillColor(sf::Color(0, 0, 50, 200));
    Case_sac_a_dos.setPosition(inventoryPosition.x + 502, inventoryPosition.y + 165);
    Case_sac_a_dos.setOutlineThickness(3);
    Case_sac_a_dos.setOutlineColor(sf::Color(255, 255, 255));
    window.draw(Case_sac_a_dos);

    // Bouton pour quitter
    sf::Text PRESS_X;
    PRESS_X.setFont(Police);
    PRESS_X.setString("PRESS X TO LEAVE");
    PRESS_X.setCharacterSize(15);
    PRESS_X.setFillColor(sf::Color::White);
    PRESS_X.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 545);
    window.draw(PRESS_X);


    int Position_en_y = 285;
    int MOOVE_DE_Y = 0;
    int Position_de_x = 483;
    for (int i = 0; i < 10; i++) {
        int MOOVE_DE_X = 0;
        for (int x = 0; x < 9; x++) {
            MOOVE_DE_X += 25;
            sf::RectangleShape Case_inventaire_Item(sf::Vector2f(25, 25));
            Case_inventaire_Item.setFillColor(sf::Color(255, 255, 255, 0));
            Case_inventaire_Item.setPosition(inventoryPosition.x + Position_de_x + MOOVE_DE_X, inventoryPosition.y + Position_en_y + MOOVE_DE_Y);
            Case_inventaire_Item.setOutlineThickness(1);
            Case_inventaire_Item.setOutlineColor(sf::Color(255, 255, 255));
            window.draw(Case_inventaire_Item);
        }

        MOOVE_DE_Y += 25;
    }

    // Affichage des sprites en utilisant inventoryPosition
    sprite_casque.setPosition(inventoryPosition.x + 277, inventoryPosition.y + 210);
    window.draw(sprite_casque);

    sprite_Plastron.setPosition(inventoryPosition.x + 277, inventoryPosition.y + 270);
    window.draw(sprite_Plastron);

    sprite_Pantalon.setPosition(inventoryPosition.x + 277, inventoryPosition.y + 330);
    window.draw(sprite_Pantalon);

    sprite_Chaussure.setPosition(inventoryPosition.x + 277, inventoryPosition.y + 390);
    window.draw(sprite_Chaussure);

    sprite_Epee.setPosition(inventoryPosition.x + 457, inventoryPosition.y + 210);
    window.draw(sprite_Epee);

    sprite_Bouclier.setPosition(inventoryPosition.x + 457, inventoryPosition.y + 270);
    window.draw(sprite_Bouclier);

    sprite_Potion.setPosition(inventoryPosition.x + 457, inventoryPosition.y + 330);
    window.draw(sprite_Potion);

    sprite_Potion.setPosition(inventoryPosition.x + 457, inventoryPosition.y + 390);
    window.draw(sprite_Potion);
    int MOOVE_DE_X = 0;
    for (int y = 0; y < 2; y++) {
        int MOOVE_DE_Y = 0;
        for (int x = 0; x < 4; x++) {


            sf::RectangleShape Case_inventaire_Item(sf::Vector2f(25, 25));
            Case_inventaire_Item.setFillColor(sf::Color(255, 255, 255, 0));
            Case_inventaire_Item.setPosition(inventoryPosition.x + 277 + MOOVE_DE_X, inventoryPosition.y + 210 + MOOVE_DE_Y);
            Case_inventaire_Item.setOutlineThickness(3);
            Case_inventaire_Item.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(Case_inventaire_Item);
            MOOVE_DE_Y = MOOVE_DE_Y + 60;
        }
        MOOVE_DE_X = 180;
    }

    // Poids de l'inventaire
    sf::Text Poids_personnage;
    std::string Poids_de_l_inventaire = "Poids de votre inventaire : " + getPOIDS() + "/100";
    Poids_personnage.setFont(Police);
    Poids_personnage.setString(Poids_de_l_inventaire);
    Poids_personnage.setCharacterSize(10);
    Poids_personnage.setFillColor(sf::Color::White);
    Poids_personnage.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 520);

    // Case Poids
    sf::RectangleShape Case_Poids_inventaire(sf::Vector2f(239, 80));
    Case_Poids_inventaire.setFillColor(sf::Color(34, 34, 34, 200));
    Case_Poids_inventaire.setPosition(inventoryPosition.x + 260, inventoryPosition.y + 455);
    Case_Poids_inventaire.setOutlineThickness(3);
    Case_Poids_inventaire.setOutlineColor(sf::Color(255, 255, 255));
    window.draw(Case_Poids_inventaire);

    // Affichage final
    sprite_Personnage.setPosition(inventoryPosition.x + 290, inventoryPosition.y + 200);
    window.draw(sprite_Personnage);

    window.draw(Personnage_inventaire);
    window.draw(Sac_a_dos_text);
    window.draw(Poids_personnage);


    

        if (nom_de_l_item!="") {
            // Gestion des cases disponibles
            if (!checkcase1) {
                position_associer_x = 508;  // Mise à jour de la position de la première case
                position_associer_y = 283;
                checkcase1 = true;
            }
            else if (checkcase2 == false && checkcase1 == true) {
                position_associer_x = 533;  // Mise à jour de la position de la deuxième case
                position_associer_y = 283;
                checkcase2 = true;
            }
            else if (checkcase3 == false && checkcase2 == true) {
                position_associer_x = 558;
                position_associer_y = 283;
                checkcase3 = true;
                cout << position_associer_x << endl;
         
            }

            else if (checkcase4 == false && checkcase3 == true) {
                position_associer_x = 583;
                position_associer_y = 283;
                checkcase4 = true;
            }

            else if (checkcase5 == false && checkcase4 == true) {
                position_associer_x = 608;
                position_associer_y = 283;
                checkcase5 = true;
            }

            else if (checkcase6 == false && checkcase5 == true) {
                position_associer_x = 633;
                position_associer_y = 283;
                checkcase6 = true;
            }

            else if (checkcase7 == false && checkcase6 == true) {
                position_associer_x = 658;
                position_associer_y = 283;
                checkcase7 = true;
            }

            else if (checkcase8 == false && checkcase7 == true) {
                position_associer_x = 683;
                position_associer_y = 283;
                checkcase8 = true;
            }

            else if (checkcase9 == false && checkcase8 == true) {
                position_associer_x = 708;
                position_associer_y = 283;
                checkcase9 = true;
            }
            else if (checkcase10 == false && checkcase9 == true) {
                position_associer_x = 508;
                position_associer_y = 283;
                checkcase10 = true;
                
            }

        // Gestion des items spécifiques


        if (nom_de_l_item == "Boisson_de_papi") {
            boisson_de_papi = true;
        }

        if (nom_de_l_item == "potion_humoristique") {
            potion_humoristique = true;
        }



        if (nom_de_l_item == "clef_rouillee") {
            clef_rouillee = true;
        }

        if (nom_de_l_item == "Potion_d_intelligence_discutable") {
            Potion_d_intelligence_discutable = true;
        }

        if (nom_de_l_item == "Chaussures_de_discrétion_bruyante") {
            Chaussures_de_discrétion_bruyante = true;
        }

        if (nom_de_l_item == "Épée_émoussée") {
            Épée_émoussée = true;
        }

        if (nom_de_l_item == "Potion_de_soin_majeur") {
            Potion_de_soin_majeur = true;
        }

        if (nom_de_l_item == "Sceptre_de_la_Supériorité_Syntaxique") {
            Sceptre_de_la_Supériorité_Syntaxique = true;
        }

        if (nom_de_l_item == "Livre_des_règles_perdues") {
            Livre_des_règles_perdues = true;
        }
        if (nom_de_l_item == "Bierre") {
            bierre = true;
        }

    }

    if (potion_humoristique) {
        if (calcul_de_position_potion_humoristique == false) {
            sprite_potion_humoristique.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
            window.draw(sprite_potion_humoristique);

            position_potion_humoristique[0] = position_associer_x;
            position_potion_humoristique[1] = position_associer_y;
            calcul_de_position_potion_humoristique = true;

        }
        else {
            sprite_potion_humoristique.setPosition(inventoryPosition.x + position_potion_humoristique[0], inventoryPosition.y + position_potion_humoristique[1]);
            window.draw(sprite_potion_humoristique);
        }
    }



        if (Livre_des_règles_perdues) {
            if (calcul_de_position_Livre_des_règles_perdues == false) {
                sprite_Livre_des_regles_perdues.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_Livre_des_regles_perdues);

                position_Livre_des_règles_perdues[0] = position_associer_x;
                position_Livre_des_règles_perdues[1] = position_associer_y;
                calcul_de_position_Livre_des_règles_perdues = true;

            }
            else {
                sprite_Livre_des_regles_perdues.setPosition(inventoryPosition.x + position_Livre_des_règles_perdues[0], inventoryPosition.y + position_Livre_des_règles_perdues[1]);
                window.draw(sprite_Livre_des_regles_perdues);
            }

        }





   
        if (Sceptre_de_la_Supériorité_Syntaxique) {
            if (calcul_de_position_Sceptre_de_la_Supériorité_Syntaxique == false) {
                sprite_Sceptre_de_la_Superiorite_Syntaxique.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_Sceptre_de_la_Superiorite_Syntaxique);

                position_Sceptre_de_la_Supériorité_Syntaxique[0] = position_associer_x;
                position_Sceptre_de_la_Supériorité_Syntaxique[1] = position_associer_y;
                calcul_de_position_Sceptre_de_la_Supériorité_Syntaxique = true;

            }
            else {
                sprite_Sceptre_de_la_Superiorite_Syntaxique.setPosition(inventoryPosition.x + position_Sceptre_de_la_Supériorité_Syntaxique[0], inventoryPosition.y + position_Sceptre_de_la_Supériorité_Syntaxique[1]);
                window.draw(sprite_Sceptre_de_la_Superiorite_Syntaxique);
            }

        }




        if (Potion_de_soin_majeur) {
            if (calcul_de_position_Potion_de_soin_majeur == false) {
                sprite_Potion_de_soin_majeur.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_Potion_de_soin_majeur);

                position_Potion_de_soin_majeur[0] = position_associer_x;
                position_Potion_de_soin_majeur[1] = position_associer_y;
                calcul_de_position_Potion_de_soin_majeur = true;

            }
            else {
                sprite_Potion_de_soin_majeur.setPosition(inventoryPosition.x + position_Potion_de_soin_majeur[0], inventoryPosition.y + position_Potion_de_soin_majeur[1]);
                window.draw(sprite_Potion_de_soin_majeur);
            }

        }

        if (Épée_émoussée) {
            if (calcul_de_position_Épée_émoussée == false) {
                sprite_epee_emousee.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_epee_emousee);

                position_Épée_émoussée[0] = position_associer_x;
                position_Épée_émoussée[1] = position_associer_y;
                calcul_de_position_Épée_émoussée = true;

            }
            else {
                sprite_epee_emousee.setPosition(inventoryPosition.x + position_Épée_émoussée[0], inventoryPosition.y + position_Épée_émoussée[1]);
                window.draw(sprite_epee_emousee);
            }

        }





        if (Potion_d_intelligence_discutable) {
            if (calcul_de_position_Potion_d_intelligence_discutable == false) {
                sprite_potion_dintelligence_discutable.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_potion_dintelligence_discutable);

                position_Potion_d_intelligence_discutable[0] = position_associer_x;
                position_Potion_d_intelligence_discutable[1] = position_associer_y;
                calcul_de_position_Potion_d_intelligence_discutable = true;

            }
            else {
                sprite_potion_dintelligence_discutable.setPosition(inventoryPosition.x + position_Potion_d_intelligence_discutable[0], inventoryPosition.y + position_Potion_d_intelligence_discutable[1]);
                window.draw(sprite_potion_dintelligence_discutable);
            }

        }



        if (Chaussures_de_discrétion_bruyante) {
            if (calcul_de_position_Chaussures_de_discrétion_bruyante == false) {
                sprite_Chaussures_de_discretion_bruyante.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_Chaussures_de_discretion_bruyante);

                position_Chaussures_de_discrétion_bruyante[0] = position_associer_x;
                position_Chaussures_de_discrétion_bruyante[1] = position_associer_y;
                calcul_de_position_Chaussures_de_discrétion_bruyante = true;

            }
            else {
                sprite_Chaussures_de_discretion_bruyante.setPosition(inventoryPosition.x + position_Chaussures_de_discrétion_bruyante[0], inventoryPosition.y + position_Chaussures_de_discrétion_bruyante[1]);
                window.draw(sprite_Chaussures_de_discretion_bruyante);
            }

        }


        if (clef_rouillee) {
            if (calcul_de_position_clef_rouillee == false) {
                sprite_Clef_rouille.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_Clef_rouille);

                position_clef_rouillee[0] = position_associer_x;
                position_clef_rouillee[1] = position_associer_y;
                calcul_de_position_clef_rouillee = true;

            }
            else {
                sprite_Clef_rouille.setPosition(inventoryPosition.x + position_clef_rouillee[0], inventoryPosition.y + position_clef_rouillee[1]);
                window.draw(sprite_Clef_rouille);
            }

        }

        if (boisson_de_papi) {
            if (calcul_de_position_boisson_de_papi == false) {
                sprite_Boisson.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_Boisson);


                position_boisson_de_papi[0] = position_associer_x;
                position_boisson_de_papi[1] = position_associer_y;
                calcul_de_position_boisson_de_papi = true;

            }
            else {
                sprite_Boisson.setPosition(inventoryPosition.x + position_boisson_de_papi[0], inventoryPosition.y + position_boisson_de_papi[1]);
                window.draw(sprite_Boisson);
                
            }
        }

        if (bierre) {
            if (calcul_de_position_bierre == false) {
                sprite_Bierre.setPosition(inventoryPosition.x + position_associer_x, inventoryPosition.y + position_associer_y);
                window.draw(sprite_Bierre);

                position_bierre[0] = position_associer_x;
                position_bierre[1] = position_associer_y;
                calcul_de_position_bierre = true;

            }
            else {
                sprite_Bierre.setPosition(inventoryPosition.x + position_bierre[0], inventoryPosition.y + position_bierre[1]);
                window.draw(sprite_Bierre);
                cout << position_bierre[0] << endl;
            }
        }
}