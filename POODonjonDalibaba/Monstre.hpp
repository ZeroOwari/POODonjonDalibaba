#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Monstre
{
protected:
    int pv;
    int niveau;
    unordered_map<string, int> competences;

public:
    Monstre() : pv(0), niveau(0) {}
    Monstre(int pv) : pv(pv), niveau(0) {}

    virtual void set_pv(int pv)
    {
        this->pv = pv;
    }

    virtual void set_force(int niveau)
    {
        this->competences["Force"] = niveau;
    }

    virtual void set_intelligence(int niveau)
    {
        this->competences["Intelligence"] = niveau;
    }

    virtual void set_adresse(int niveau)
    {
        this->competences["Adresse"] = niveau;
    }

    virtual void set_charisme(int niveau)
    {
        this->competences["Charisme"] = niveau;
    }

    virtual void set_courage(int niveau)
    {
        this->competences["Courage"] = niveau;
    }

    virtual int get_pv() const
    {
        return this->pv;
    }

    virtual int get_force() const
    {
        return this->competences.at("Force");
    }

    virtual int get_intelligence() const
    {
        return this->competences.at("Intelligence");
    }

    virtual int get_adresse() const
    {
        return this->competences.at("Adresse");
    }

    virtual int get_charisme() const
    {
        return this->competences.at("Charisme");
    }

    virtual int get_courage() const
    {
        return this->competences.at("Courage");
    }

    virtual int get_niveau() const
    {
        return this->niveau;
    }

    virtual string get_origine() const = 0;

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
};