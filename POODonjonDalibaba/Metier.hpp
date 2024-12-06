#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Heros.hpp"
#include <vector>

class Metier : public virtual Heros {
protected:
    std::string metier;

public:

    Metier()
        : Heros(10, 50.0),
        metier("Inconnu") {}

    Metier(int pv, double poidsmax, const std::string& metier)
        : Heros(pv, poidsmax), metier(metier) {
        initialiserCompetencesSpecifiques();
    }

    void initialiserCompetencesSpecifiques() {
        if (metier == "Guerrier") {
            this->AddCompetenceSpecifique("Combat a l'epee", 1);
            this->AddCompetenceSpecifique("Parade", 1);
        }
        else if (metier == "Magicien") {
            this->AddCompetenceSpecifique("Magie", 1);
            this->AddCompetenceSpecifique("Concentration", 1);
        }
        else if (metier == "Voleur") {
            this->AddCompetenceSpecifique("Crochetage", 1);
            this->AddCompetenceSpecifique("Furtivite", 1);
        }
        else if (metier == "Ranger") {
            this->AddCompetenceSpecifique("Tir a l'arc", 1);
            this->AddCompetenceSpecifique("Survie dans les arbres", 1);
        }
    }

    virtual std::string get_metier() const {
        return metier;
    }

    void afficherCompetencesSpecifiques() {
        std::cout << "" << std::endl;
        std::cout << "===Competences specifiques===" << std::endl;
        for (const auto& pair : competences_specifiques) {
            std::cout << pair.first << " (Niveau " << pair.second << ")" << std::endl;
        }
        std::cout << "=============================" << std::endl;
    }
};