#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "window.hpp"
#include "calcul_new_poids.hpp"


using namespace std;


#pragma once
#include <iostream>
using namespace std;
/*qz
class Coffre {
private:
    bool coffreOuvert;
    int longueur;
    int largeur;

public:
    Coffre(int longueur, int largeur) {
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
    
    void changerdecoffre(sf::RenderWindow& window) {
        
        sf::Texture texture2;
        if (!texture2.loadFromFile("C:/Users/quent/sfml/asset/Coffre_final.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
            

        sf::Texture texture3;
        if (!texture3.loadFromFile("C:/Users/quent/sfml/asset/Coffre_final_ouvert.png")) {
            std::cout << "Erreur lors du chargement de la texture" << std::endl;
            return;
        }
        const int caseSize = 48;
        
        sf::Sprite sprite2;
        sprite2.setTexture(texture2);
        sprite2.setTextureRect(sf::IntRect(0, 0, caseSize, caseSize));
        
        sf::Sprite sprite3;
        sprite3.setTexture(texture3);
        sprite3.setTextureRect(sf::IntRect(0, 0, caseSize, caseSize));

        int nbCasesLargeur = this->largeur / caseSize;
        int nbCasesLongueur = this->longueur / caseSize;

        int salleWidth = nbCasesLargeur * caseSize;
        int salleHeight = nbCasesLongueur * caseSize;

        sf::Vector2u windowSize = window.getSize();

        float offsetX = (windowSize.x - salleWidth) / 2.0;
        float offsetY = (windowSize.y - salleHeight) / 2.0;
        sprite3.setPosition(offsetX -0.5 * caseSize, offsetY - 0.5* caseSize);
        window.draw(sprite3);

        

        void Changement_coffre(); {
            coffreOuvert = !coffreOuvert; 
            sf::sleep(sf::milliseconds(200)); 
            newPOIDS(2, "Consommable", "Boison_de_papi");















        

        if (coffreOuvert) {
            sprite2.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
            window.draw(sprite2);



        }
        else {
            sprite3.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
            window.draw(sprite3);
        }

        }
        }
    }
};

/*
bool coffreOuvert;

void Changement_coffre(); {
    coffreOuvert = !coffreOuvert;
    sf::sleep(sf::milliseconds(200));
    newPOIDS(2, "Consommable", "Boison_de_papi");

















    if (coffreOuvert) {
        sprite2.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
        window.draw(sprite2);



    }
    else {
        sprite3.setPosition(offsetX + 4.5 * caseSize, offsetY + 4.5 * caseSize);
        window.draw(sprite3);
    }

}
*/












