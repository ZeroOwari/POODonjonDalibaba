#include <iostream>
#include "SFML/Graphics.hpp"
#include "Barbare.hpp"
#include "Elfe.hpp"
#include "Humain.hpp"
#include "Nain.hpp"
#include "GobelinSarcastique.hpp"
#include "TrollRhetoricien.hpp"
#include "CanardExplosif.hpp"
#include "Game.hpp"
#include "ObserverMetier.hpp"

int main() {
	Game game;
	game.run();
	//std::cout << "Heros" << std::endl;
	//Heros monHeros(100, 50.0);
	//monHeros.JetDuHeros();
	//std::cout << "Monstre" << std::endl;
	//Monstre monMonstre(100,2);
	//monMonstre.JetDuMonstllre();

	//std::cout << "Fin du jeu" << std::endl;
	/*window fenetre(1920, 1080);
	fenetre.afficher();*/
	/*Barbare b(110, 50);
	Elfe e(150, 40);
	Humain h(100, 60);
	Nain n(120, 70);

	b.afficher();
	e.afficher();
	h.afficher();
	n.afficher();

	b.afficher();
	b.AfficherSpells();
	b.UpNiveau();
	b.UpNiveau();

	b.ajoutPoint("Force", 5);
	
	b.ajoutPoint("Intelligence", 5);
	b.AddInventaire("Epee");
	b.AddInventaire("Bouclier");
	b.afficher();

	b.AddSpells("Boule de feu");
	b.AddSpells("Eclair");
	b.AfficherSpells();*/


	////Affichage Monstre pour tester si ça fonctionne
	//vector<Monstre*> monstres;
	//monstres.push_back(new GobelinSarcastique());
	//monstres.push_back(new TrollRhetoricien());
	//monstres.push_back(new CanardExplosif());

	//for (Monstre* monstre : monstres)
	//{
	//	monstre->afficher();
	//}

	//for (Monstre* monstre : monstres)
	//{
	//	delete monstre;
	//}
/*	Heros heros(100, 50.0);
	Monstre monstre;
	monstre.set_pv(80);

	heros.set_force(10);
	heros.set_intelligence(8);
	heros.set_adresse(12);
	heros.set_charisme(6);
	heros.set_courage(10);
	monstre.set_force(12);
	monstre.set_intelligence(6);
	monstre.set_adresse(10);
	monstre.set_charisme(4);
	monstre.set_courage(8);

	Combat combat(heros, monstre);

	cout << "Le combat commence !" << endl;
	combat.demarrerCombat();

	if (heros.estVivant()) {
		cout << "Le héros a gagné !" << endl;
	}
	else {
		cout << "Le monstre a gagné !" << endl;
	}*/
	return 0;
}