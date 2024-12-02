#pragma once
#include "Metier.hpp"
#include <cstdlib> // Pour std::rand et std::srand
#include <iostream> // Pour afficher les messages d'attaque

class Ranger : public Metier {
public:
    Ranger(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 40;
        this->competences["Force"] = 4;
        this->competences["Intelligence"] = 4;
        this->competences["Adresse"] = 8;
        this->competences["Charisme"] = 5;
        this->competences["Courage"] = 5;
        this->competences["Resistance_Magique"] = 3;
    }

    std::string get_origine() override {
        return "Ranger";
    }

    int attaque_simple(int resistance_cible) {
        int puissance = 25;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 5;

        int degats = std::max(0, (puissance + adresse) - resistance_cible + facteur_aleatoire);

        std::cout << "Le ranger tire une Flèche rapide, transperçant son adversaire !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts." << std::endl;

        return degats;
    }

    int attaque_speciale(int resistance_cible) {
        int puissance = 45;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 10;

        int degats = std::max(0, (puissance + adresse * 2) - resistance_cible + facteur_aleatoire);

        std::cout << "Le ranger enchaîne un Tir en rafale, plusieurs flèches frappent l'ennemi !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts." << std::endl;

        return degats;
    }

    int utiliser_competence_speciale(int resistance_cible) {
        int puissance = 80;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 15;

        int degats = std::max(0, (puissance + adresse * 3) - resistance_cible + facteur_aleatoire);

        std::cout << "Le ranger concentre ses forces pour un Tir précis, visant un point vital !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts critiques." << std::endl;

        return degats;
    }
};
