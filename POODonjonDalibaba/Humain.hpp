#pragma once
#include <iostream>
#include "Heros.hpp"

class Humain : public Heros, public Observer {
public:
    Humain(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 30;
        this->competences["Force"] = 9;
        this->competences["Intelligence"] = 9;
        this->competences["Adresse"] = 9;
        this->competences["Charisme"] = 9;
        this->competences["Courage"] = 9;
		this->AddCompetenceSpecifique("Diplomatie",5);
        this->AddCompetenceSpecifique("Commerce", 7);
		this->AddCompetenceSpecifique("Coup de retournée acrobatique",9);
    }

    std::string get_origine() override {
        return "Humain";
    }
    void update(const std::string& origine) override {
        std::cout << "La race du héros a changé en : " << origine << std::endl;
    }
};