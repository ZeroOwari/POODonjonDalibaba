#pragma once
#include "Metier.hpp"
#include <cstdlib>
#include <iostream>

class Voleur : public Metier {
public:
    Voleur(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 50;
        this->competences["Force"] = 5;
        this->competences["Intelligence"] = 4;
        this->competences["Adresse"] = 9;
        this->competences["Charisme"] = 6;
        this->competences["Courage"] = 4;
        this->competences["Resistance_Magique"] = 2;
    }

    std::string get_origine() override {
        return "Voleur";
    }

    int attaque_simple(int resistance_cible) {
        int puissance = 20;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 5;

        int degats = std::max(0, (puissance + adresse) - resistance_cible + facteur_aleatoire);

        std::cout << "Le voleur effectue une Entaille rapide sur son adversaire !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts." << std::endl;

        return degats;
    }

    int attaque_speciale(int resistance_cible) {
        int puissance = 40;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 10;

        int degats = std::max(0, (puissance + adresse * 2) - resistance_cible + facteur_aleatoire);

        std::cout << "Le voleur exécute une Attaque sournoise, frappant dans l'ombre !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts." << std::endl;

        return degats;
    }

    int utiliser_competence_speciale(int resistance_cible) {
        int puissance = 70;
        int adresse = this->competences["Adresse"];
        int facteur_aleatoire = std::rand() % 15;

        int degats = std::max(0, (puissance + adresse * 3) - resistance_cible + facteur_aleatoire);

        std::cout << "Le voleur effectue un Assassinat précis, touchant une zone vitale !" << std::endl;
        std::cout << "Il inflige " << degats << " points de dégâts mortels." << std::endl;

        return degats;
    }
};
