#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class Personnages {
protected:
    int pv;
    int niveau;
    std::unordered_map<std::string, int> competences;

public:

    Personnages() : pv(0), niveau(0) {}
    Personnages(int pv) : pv(pv), niveau(0) {}

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

    virtual void set_niveau(int niveau) {
        this->niveau = niveau;
    }

    virtual int get_pv() {
        return this->pv;
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
};