#pragma once
#include <iostream>
#include "Heros.hpp"

class Nain : public Heros {
public:
    Nain(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 120;
        competences["Force"] = 5;
        competences["Intelligence"] = 3;
        competences["Adresse"] = 2;
        competences["Charisme"] = 2;
        competences["Courage"] = 5;
    }
    std::string get_origine() override {
        return "Nain";
    }
};