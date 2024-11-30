#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include "Heros.hpp"
#include "Monstre.hpp"
using namespace std;
/*
class Combat {
private:
    Heros& heros;
    Monstre& monstre;

    bool determinerInitiative();
    //bool attaque(Heros& attaquant, Monstre& defenseur);
    //bool parade(Monstre& defenseur);
    //int calculerDegats(Heros& attaquant);

public:
    Combat(Heros& heros, Monstre& monstre);

    void demarrerCombat();
};

void Combat::demarrerCombat() {
    bool tourHeros = determinerInitiative();
    while (heros.estVivant() && monstre.estVivant()) {
        if (tourHeros) {
            if (attaque(heros, monstre)) {
                int degats = calculerDegats(heros);
                monstre.recevoirDegats(degats);
            }
        }
        else {
            if (parade(monstre)) {
                int degats = 0;
            }
            else {
                int degats = calculerDegats(monstre);
                heros.subitDegats(degats);
            }
        }
        tourHeros = !tourHeros;
    }
}

bool Combat::determinerInitiative() {
    int initiativeHeros = heros.get_adresse() + heros.get_courage();
    int initiativeMonstre = monstre.get_adresse() + monstre.get_courage();
    return initiativeHeros >= initiativeMonstre;
}
/*
bool Combat::attaque(Heros& attaquant, Monstre& defenseur) {
    int jetAttaque = rand() % 20 + 1;
    return jetAttaque + attaquant.getCompetenceAttaque() > defenseur.getCompetenceParade();
}

bool Combat::parade(Monstre& defenseur) {
    int jetParade = rand() % 20 + 1;
    return jetParade + defenseur.getCompetenceParade() > 15;
}

int Combat::calculerDegats(Heros& attaquant) {
    return attaquant.get_force() + attaquant.get_arme().getDegats();
}
*/