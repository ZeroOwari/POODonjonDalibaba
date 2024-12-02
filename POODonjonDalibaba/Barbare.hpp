#pragma once
#include <iostream>
#include "Heros.hpp"

class Barbare : public Heros {
public:
    Barbare(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 35;
        this->competences["Force"] = 13;
        this->competences["Intelligence"] = 8;
        this->competences["Adresse"] = 8;
        this->competences["Charisme"] = 10;
        this->competences["Courage"] = 12;
    }

    std::string get_origine() override {
        return "Barbare";
    }

};