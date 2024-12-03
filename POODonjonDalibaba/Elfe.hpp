#pragma once
#include <iostream>
#include "Heros.hpp"

class Elfe : public Heros {
public:
    Elfe(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 25;
        this->competences["Force"] = 12;
        this->competences["Intelligence"] = 11;
        this->competences["Adresse"] = 12;
        this->competences["Charisme"] = 12;
        this->competences["Courage"] = 10;
		this->AddCompetenceSpecifique("Tir a l'arc");
		this->AddCompetenceSpecifique("Magie");
		this->AddCompetenceSpecifique("Tirer les oreilles");
    }
    std::string get_origine() override {
        return "Elfe";
    }

};