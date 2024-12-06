#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Monstre.hpp"
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
    void update(const std::string& origine) override {
        cout << "Canard Explosif a été notifié que " << origine << " a subi des dégâts." << endl;
    }
};