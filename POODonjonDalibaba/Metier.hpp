#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Heros.hpp"
#include <vector>

class Metier : public Heros {
protected:
    std::string metier;

public:
    Metier(int pv, double poidsmax, const std::string& metier)
        : Heros(pv, poidsmax), metier(metier) {
        initialiserCompetencesSpecifiques();
    }

    void initialiserCompetencesSpecifiques() {
        if (metier == "Guerrier") {
            this->AddCompetenceSpecifique("Combat a l'epee");
            this->AddCompetenceSpecifique("Parade");
        }
        else if (metier == "Magicien") {
            this->AddCompetenceSpecifique("Magie");
            this->AddCompetenceSpecifique("Concentration");
        }
        else if (metier == "Voleur") {
            this->AddCompetenceSpecifique("Crochetage");
            this->AddCompetenceSpecifique("Furtivite");
        }
        else if (metier == "Ranger") {
            this->AddCompetenceSpecifique("Tir a l'arc");
            this->AddCompetenceSpecifique("Survie dans les arbres");
        }
    }

    virtual std::string get_metier() const {
        return metier;
    }

    void afficherCompetencesSpecifiques() {
        std::cout << "" << std::endl;
        std::cout << "===Competences specifiques===" << std::endl;
        for (int i = 0; i < this->competences_specifiques.size(); i++) {
            std::cout << this->competences_specifiques[i] << std::endl;
        }
        std::cout << "=============================" << std::endl;
    }
};