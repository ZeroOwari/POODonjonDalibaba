#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "window.hpp"
#include "Item.h"
#include "Item_sous_classe.h"
#include "calcul_new_poids.hpp"
using namespace std;

class salles {
private:
    int longueur;
    int largeur;
    bool coffreOuvert;
public:
    salles(int longueur, int largeur) {
        this->longueur = longueur;
        this->largeur = largeur;
    }
    void set_longueur(int longueur) {
        this->longueur = longueur;
    }
    void set_largeur(int largeur) {
        this->largeur = largeur;
    }
    int get_longueur() {
        return this->longueur;
    }
    int get_largeur() {
        return this->largeur;
    }
    void afficherSalle(sf::RenderWindow& window) {

        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/quent/sfml/asset/sol.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
        }

        sf::Texture texture2;
        if (!texture2.loadFromFile("C:/Users/quent/sfml/asset/Coffre_final.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
        }
        sf::Texture texture3;
        if (!texture3.loadFromFile("C:/Users/quent/sfml/asset/Coffre_final_ouvert.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
        }

        const int caseSize = 48;

        // Calculer le nombre de cases en largeur et en longueur
        int nbCasesLargeur = this->largeur / caseSize;
        int nbCasesLongueur = this->longueur / caseSize;

        int salleWidth = nbCasesLargeur * caseSize;
        int salleHeight = nbCasesLongueur * caseSize;

        sf::Vector2u windowSize = window.getSize();

        float offsetX = (windowSize.x - salleWidth) / 2.0;
        float offsetY = (windowSize.y - salleHeight) / 2.0;

        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, caseSize, caseSize));

        sf::Sprite sprite2;
        sprite2.setTexture(texture2);
        sprite2.setTextureRect(sf::IntRect(0, 0, caseSize, caseSize));

        sf::Sprite sprite3;
        sprite3.setTexture(texture3);
        sprite3.setTextureRect(sf::IntRect(0, 0, caseSize, caseSize));

        int centerX = nbCasesLargeur / 2;
        int centerY = nbCasesLongueur / 2;

   
        int checkchestx = 0;
        int checkchesty = 0;
        for (int i = 0; i < nbCasesLongueur; i++) {
            checkchesty++;
            for (int j = 0; j < nbCasesLargeur; j++) {
                sprite.setPosition(offsetX + j * caseSize, offsetY + i * caseSize);
                window.draw(sprite);

            }
        }
        /*
        int verif = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
            verif=1;
        }

        if (verif==1){
            sprite3.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
            window.draw(sprite3);
                
           
           
        }
        else {
            sprite2.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
            window.draw(sprite2);
        }
        */


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
            coffreOuvert = !coffreOuvert; // Inverser l'état du coffre
            sf::sleep(sf::milliseconds(200)); // Pause pour éviter une répétition rapide
            newPOIDS(2, "Consommable", "Boison_de_papi");
            


            
            
            
            
            
            
            
            
            

                
                
            
            
            
        }

        if (coffreOuvert) {
            sprite2.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
            window.draw(sprite2);
            
            

        }
        else {
            sprite3.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
            window.draw(sprite3);
            
        }

       
        }

    /*
    void changer(); {
        sprite2.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
        window.draw(sprite3);
    }
    */

    

};

