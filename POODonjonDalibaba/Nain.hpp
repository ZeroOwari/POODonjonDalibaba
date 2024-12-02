#pragma once
#include <iostream>
#include "Heros.hpp"

class Nain : public Heros {
public:
    Nain(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 35;
        competences["Force"] = 12;
        competences["Intelligence"] = 9;
        competences["Adresse"] = 7;
        competences["Charisme"] = 7;
        competences["Courage"] = 11;
    }
    std::string get_origine() override {
        return "Nain";
    }
};