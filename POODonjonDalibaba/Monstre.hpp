#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Personnages.hpp"
#include "Combat.hpp"

using namespace std;

class Monstre : public Personnages
{
public:
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