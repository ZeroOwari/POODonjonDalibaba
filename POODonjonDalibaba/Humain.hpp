#pragma once
#include <iostream>
#include "Heros.hpp"

class Humain : public Heros {
public:
    Humain(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 100;
        this->competences["Force"] = 3;
        this->competences["Intelligence"] = 3;
        this->competences["Adresse"] = 3;
        this->competences["Charisme"] = 3;
        this->competences["Courage"] = 3;
    }

    std::string get_origine() override {
        return "Humain";
    }
};