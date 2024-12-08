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
#include "tests.hpp"

int main() {
	Game game;
	game.run();

	// Tests unitaires :

	// Création d'un héros de chaque classe

	Barbare barbare(100, 100);
	Elfe elfe(100, 100);
	Humain humain(100, 100);
	Nain nain(100, 100);

	// Tests :

	tests test;
	test.run();


	return 0;
}