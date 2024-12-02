#pragma once
#include "Metier.hpp"
#include <cstdlib>
#include <iostream>

class Magicien : public Metier {
public:
    Magicien(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 200;
        this->competences["Force"] = 2;
        this->competences["Intelligence"] = 3;
        this->competences["Adresse"] = 7;
        this->competences["Charisme"] = 1;
        this->competences["Courage"] = 3;
        this->competences["Resistance_Magique"] = 5;
    }

    std::string get_origine() override {
        return "Guerrier";
    }

    int attaque_simple(int resistance_cible) {
        int puissance = 30;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 5;

        int degats = std::max(0, (puissance + adresse) - resistance_cible + facteur_aleatoire);

        std::cout << "Le Magicien Lance une boule de feu!" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts." << std::endl;

        return degats;
    }

    int attaque_speciale(int resistance_cible) {
        int puissance = 60;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 10;

        int degats = std::max(0, (puissance + adresse * 2) - resistance_cible + facteur_aleatoire);

        std::cout << "Le Magicien libère une Puissance incroyable !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts." << std::endl;

        return degats;
    }

    int utiliser_competence_speciale(int resistance_cible) {
        int puissance = 100;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 15;

        int degats = std::max(0, (puissance + adresse * 3) - resistance_cible + facteur_aleatoire);

        std::cout << "Le Magicien entre en état de tanse,il frappe son ennemi avec une puissance folle !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts destructeurs." << std::endl;

        return degats;
    }
};