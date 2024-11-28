#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Monstre.hpp"
using namespace std;

class TrollRhetoricien : public Monstre
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

    string get_origine() const override
    {
        return "Troll Rhetoricien";
    }

    void afficher() override
    {
        Monstre::afficher();
        cout << "Ceci est un Troll rhetoricien." << endl;
    }
};