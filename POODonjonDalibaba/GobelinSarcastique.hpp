#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Monstre.hpp"
#include "ObserverPersonnages.hpp"
using namespace std;

class GobelinSarcastique : public Monstre, public Observer
{
public:
    GobelinSarcastique(int pv, int niveau) : Monstre(pv, niveau) {}

    GobelinSarcastique()
    {
        this->set_pv(25);
        this->set_force(2);
        this->set_intelligence(0);
        this->set_adresse(4);
        this->set_charisme(1);
        this->set_courage(1);
    }

    string get_origine() override
    {
        return "Gobelin Sarcastique";
    }

    void afficher() override
    {
        Monstre::afficher();
        cout << "Ceci est un gobelin sarcastique." << endl;
    }
    void update(Monstre* monstre) override {
        cout << "Gobelin Sarcastique a été notifié que " << monstre->get_origine() << " a subi des dégâts." << endl;
    }
};