#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class salles {
private:
    int longueur;
    int largeur;
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
        if (!texture.loadFromFile("texture/fond1.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
        }

        const int caseSize = 32;

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

        for (int i = 0; i < nbCasesLongueur; i++) {
            for (int j = 0; j < nbCasesLargeur; j++) {
                sprite.setPosition(offsetX + j * caseSize, offsetY + i * caseSize);

                window.draw(sprite);
            }
        }
    }
};