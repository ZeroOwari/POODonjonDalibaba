#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Monstre.hpp"
#include "Personnages.hpp"
using namespace std;

class CanardExplosif : public Monstre, public Observer
{
public:
    CanardExplosif()
    {
        this->set_pv(1);
        this->set_force(20);
        this->set_intelligence(1);
        this->set_adresse(1);
        this->set_charisme(1);
        this->set_courage(1);
    }
    
    string get_origine() override
    {
        return "Canard Explosif";
    }

    void afficher() override
    {
        Monstre::afficher();
        cout << "Ceci est un Canard explosif." << endl;
    }
    void update(const std::string& origine) override {
        cout << "Gobelin Sarcastique a été notifié que " << origine << " a subi des dégâts." << endl;
    }
};