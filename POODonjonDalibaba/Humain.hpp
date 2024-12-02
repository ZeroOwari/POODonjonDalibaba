#pragma once
#include <iostream>
#include "Heros.hpp"

class Humain : public Heros {
public:
    Humain(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 30;
        this->competences["Force"] = 9;
        this->competences["Intelligence"] = 9;
        this->competences["Adresse"] = 9;
        this->competences["Charisme"] = 9;
        this->competences["Courage"] = 9;
    }

    std::string get_origine() override {
        return "Humain";
    }
};