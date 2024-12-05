#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Personnages.hpp"
#include "Combat.hpp"
using namespace std;

class Monstre : public Personnages {
public:
    Monstre() : Personnages() {}
    Monstre(int pv, int niveau) : Personnages(pv, niveau) {}

    virtual std::string get_origine() override {
        return "Monstre";
    }
    virtual void JetDuMonstre() {
        std::cout << "Jet Courage : " << this->JetCOU() << std::endl;
        std::cout << "Jet Adresse : " << this->JetAD() << std::endl;
        std::cout << "Jet Force : " << this->JetFO() << std::endl;
    }
    virtual void afficher()
    {
        cout << "Origine : " << this->get_origine() << endl;
        cout << "PV : " << this->get_pv() << endl;
        cout << "Force : " << this->get_force() << endl;
        cout << "Intelligence : " << this->get_intelligence() << endl;
        cout << "Adresse : " << this->get_adresse() << endl;
        cout << "Charisme : " << this->get_charisme() << endl;
        cout << "Courage : " << this->get_courage() << endl;
        cout << "Niveau : " << this->get_niveau() << endl;
        cout << "" << endl;
    }

    void subitDegats(int degats)
    {
        this->pv -= degats;
        cout << "MONSTRE subit" << degats << "degats" << endl;
    }
    bool estVivant()
    {
        return this->pv > 0;
    }
};