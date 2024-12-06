#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Personnages.hpp"
#include <map>
#include <vector>

class Heros : public Personnages, public Subject {
protected:
    double poidsmax;
    double poidsactuel;
    int points;
    std::string metier;
    std::vector<std::string> inventaire;
    std::vector<std::string> spells;
    std::map <std::string, int> competences_specifiques;

public:
    Heros(int pv, double poidsmax) : poidsmax(poidsmax), poidsactuel(0), points(0) {}

    virtual void set_poidsmax(double poidsmax) {
        this->poidsmax = poidsmax;
    }

    virtual void set_poidsactuel(double poidsactuel) {
        this->poidsactuel = poidsactuel;
    }

    virtual void set_niveau(int niveau) {
        this->niveau = niveau;
    }

    virtual void set_points(int points) {
        this->points = points;
    }

    virtual void set_metier(const std::string& metier) {
        this->metier = metier;
    }

    virtual double get_poidsmax() {
        return this->poidsmax;
    }

    virtual double get_poidsactuel() {
        return this->poidsactuel;
    }

    virtual int get_points() {
        return this->points;
    }

    virtual std::string get_metier() {
        return this->metier;
    }

    virtual void UpNiveau() {
        this->niveau++;
        this->points += 3;
        std::cout << "Vous etes passe au niveau superieur ! Vous avez maintenant " << this->points << " points a repartir." << std::endl;
    }

    virtual void ajoutPoint(std::string competence, int n) {
        if (this->points - n < 0) {
            std::cout << "Vous n'avez pas assez de points ! Vous etes actuellements a " << this->get_points() << " et il vous faut " << n << " points !" << std::endl;
            return;
        }
        std::cout << "Vous avez ajoute " << n << " points a la competence " << competence << std::endl;
        this->competences[competence] += n;
        this->points -= n;
    }

    virtual void AddSpells(std::string spell) {
        this->spells.push_back(spell);
    }

    virtual void AddCompetenceSpecifique(std::string competence, int n) {
        this->competences_specifiques[competence] = n;
    }

    virtual void AddInventaire(std::string objet) {
        this->inventaire.push_back(objet);
    }

    virtual void afficherInventaire() {
        std::cout << "" << std::endl;
        std::cout << "=Inventaire=" << std::endl;
        for (int i = 0; i < this->inventaire.size(); i++) {
            std::cout << this->inventaire[i] << std::endl;
        }
        std::cout << "============" << std::endl;
    }

    virtual void AfficherSpells() {
        std::cout << "" << std::endl;
        std::cout << "===Spells===" << std::endl;
        for (int i = 0; i < this->spells.size(); i++) {
            std::cout << this->spells[i] << std::endl;
        }
        std::cout << "============" << std::endl;
    }

    virtual std::string get_origine() override {
        return "Heros";
    }
    void changeOrigine(const std::string& nouvelleOrigine) {
        notifyObservers(nouvelleOrigine);
    }
    virtual void JetDuHeros() {
        std::cout << "Jet Courage : " << this->JetCOU() << std::endl;
        std::cout << "Jet Intelligence : " << this->JetINT() << std::endl;
        std::cout << "Jet Charisme : " << this->JetCHA() << std::endl;
        std::cout << "Jet Adresse : " << this->JetAD() << std::endl;
        std::cout << "Jet Force : " << this->JetFO() << std::endl;
    }

    virtual void afficher() {
        std::cout << "Origine : " << this->get_origine() << std::endl;
        std::cout << "PV : " << this->get_pv() << std::endl;
        std::cout << "Poids max : " << this->get_poidsmax() << std::endl;
        std::cout << "Poids actuel : " << this->get_poidsactuel() << std::endl;
        std::cout << "Force : " << this->get_force() << std::endl;
        std::cout << "Intelligence : " << this->get_intelligence() << std::endl;
        std::cout << "Adresse : " << this->get_adresse() << std::endl;
        std::cout << "Charisme : " << this->get_charisme() << std::endl;
        std::cout << "Courage : " << this->get_courage() << std::endl;
        std::cout << "Niveau : " << this->get_niveau() << std::endl;
        std::cout << "Points : " << this->get_points() << std::endl;
        this->afficherInventaire();
        std::cout << "" << std::endl;
    }
};
