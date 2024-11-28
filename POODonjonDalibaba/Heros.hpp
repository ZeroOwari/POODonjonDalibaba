#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class Heros {
protected:
    int pv;
    int niveau;
    double poidsmax;
    double poidsactuel;
    int points;
    std::unordered_map<std::string, int> competences;

public:
    Heros(int pv, double poidsmax) : pv(pv), niveau(0), poidsmax(poidsmax), poidsactuel(0), points(0) {}

    virtual void set_pv(int pv) {
        this->pv = pv;
    }

    virtual void set_force(int niveau) {
        this->competences["Force"] = niveau;
    }

    virtual void set_intelligence(int niveau) {
        this->competences["Intelligence"] = niveau;
    }

    virtual void set_adresse(int niveau) {
        this->competences["Adresse"] = niveau;
    }

    virtual void set_charisme(int niveau) {
        this->competences["Charisme"] = niveau;
    }

    virtual void set_courage(int niveau) {
        this->competences["Courage"] = niveau;
    }

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

    virtual int get_pv() {
        return this->pv;
    }

    virtual double get_poidsmax() {
        return this->poidsmax;
    }

    virtual double get_poidsactuel() {
        return this->poidsactuel;
    }

    virtual std::string get_origine() = 0;

    virtual int get_force() {
        return this->competences["Force"];
    }

    virtual int get_intelligence() {
        return this->competences["Intelligence"];
    }

    virtual int get_adresse() {
        return this->competences["Adresse"];
    }

    virtual int get_charisme() {
        return this->competences["Charisme"];
    }

    virtual int get_courage() {
        return this->competences["Courage"];
    }

    virtual int get_niveau() {
        return this->niveau;
    }

    virtual int get_points() {
        return this->points;
    }

    virtual void UpNiveau() {
        this->niveau++;
        this->points += 3;
        std::cout << "Vous etes passe au niveau superieur ! Vous avez maintenant " << this->points << " points a repartir." << std::endl;
    }

    virtual void ajoutPoint(std::string competence, int n) {
        if (this->points - n < 0) {
            std::cout << "Vous n'avez pas assez de points ! Vous etes actuellements à " << this->get_points() << " et il vous faut " << n << " points !" << std::endl;
            return;
        }
        std::cout << "Vous avez ajoute " << n << " points a la competence. " << competence << std::endl;
        this->competences[competence] += n;
        this->points -= n;
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
        std::cout << "" << std::endl;
    }
};