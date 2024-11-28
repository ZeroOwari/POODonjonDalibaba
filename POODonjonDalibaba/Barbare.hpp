#pragma once
#include <iostream>
#include "Heros.hpp"

class Barbare : public Heros {
public:
    Barbare(int pv, double poidsmax) : Heros(pv, poidsmax) {
        this->pv = 110;
        this->competences["Force"] = 5;
        this->competences["Intelligence"] = 2;
        this->competences["Adresse"] = 2;
        this->competences["Charisme"] = 4;
        this->competences["Courage"] = 5;
    }

    std::string get_origine() override {
        return "Barbare";
    }

};