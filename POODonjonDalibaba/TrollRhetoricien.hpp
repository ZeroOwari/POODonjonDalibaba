#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Monstre.hpp"
#include "Observer.hpp"
using namespace std;

class TrollRhetoricien : public Monstre, public Observer
{
public:
    TrollRhetoricien()
    {
        this->set_pv(200);
        this->set_force(7);
        this->set_intelligence(1);
        this->set_adresse(1);
        this->set_charisme(3);
        this->set_courage(5);
    }

    string get_origine() override
    {
        return "Troll Rhetoricien";
    }

    void afficher() override
    {
        Monstre::afficher();
        cout << "Ceci est un Troll rhetoricien." << endl;
    }
    void update(Monstre* monstre) override {
        cout << "Troll rhetoricien a été notifié que " << monstre->get_origine() << " a subi des dégâts." << endl;
    }
};