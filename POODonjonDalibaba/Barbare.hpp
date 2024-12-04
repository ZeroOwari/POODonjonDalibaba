#pragma once
#include <iostream>
#include "Heros.hpp"

class Barbare : public Heros, public Observer {
public:
    Barbare(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 35;
        this->competences["Force"] = 13;
        this->competences["Intelligence"] = 8;
        this->competences["Adresse"] = 8;
        this->competences["Charisme"] = 10;
        this->competences["Courage"] = 12;
		this->AddCompetenceSpecifique("Chercher des noises",5);
		this->AddCompetenceSpecifique("Boire de la biere",7);
		this->AddCompetenceSpecifique("Casser des choses",9);
    }

    std::string get_origine() override {
        return "Barbare";
    }
    void update(const std::string& origine) override {
        std::cout << "La race du héros a changé en : " << origine << std::endl;
    }

};