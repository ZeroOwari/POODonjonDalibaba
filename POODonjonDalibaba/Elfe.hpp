#pragma once
#include <iostream>
#include "Heros.hpp"

class Elfe : public Heros {
public:
    Elfe(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 150;
        this->competences["Force"] = 4;
        this->competences["Intelligence"] = 5;
        this->competences["Adresse"] = 5;
        this->competences["Charisme"] = 4;
        this->competences["Courage"] = 3;
    }
    std::string get_origine() override {
        return "Elfe";
    }

};