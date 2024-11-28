#include <iostream>
#include "Barbare.hpp"
#include "Elfe.hpp"
#include "Humain.hpp"
#include "Nain.hpp"

int main()
{
    Barbare b(110, 50);
    Elfe e(150, 40);
    Humain h(100, 60);
    Nain n(120, 70);

    b.afficher();
    //e.afficher();
    //h.afficher();
    //n.afficher();

    b.set_pv(120);
    b.set_force(6);
    b.set_intelligence(3);
    b.set_adresse(3);
    b.set_charisme(4);
    b.set_courage(4);
    b.set_poidsmax(60);
    b.set_poidsactuel(30);

    b.afficher();

    b.ajoutPoint("Force", 5);

    b.afficher();

    return 0;
}