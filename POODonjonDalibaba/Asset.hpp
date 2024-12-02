#pragma once 

#include "SFML/Graphics.hpp"
#include <iostream>
#include <iostream>
#include <ctime>
#include "salles.hpp"

#include "SFML/Audio.hpp"
#include "SFML/Config.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "string"
#include "Game.hpp"
#include "calcul_new_poids.hpp"
#include "Player.hpp"
//class item {
//public : 
//	//void asset(std::string objet) {
//	
//	
//};



void Inventaire(sf::RenderWindow& window, const Player& player) {
	sf::Vector2f playerPosition = player.getPosition();

	const float inventoryWidth = 1000;
	const float inventoryHeight = 300;

	sf::Vector2f inventoryPosition(playerPosition.x - inventoryWidth / 2, playerPosition.y - inventoryHeight / 2);
	// police d'écriture : 
	sf::Font Police;
	if (!Police.loadFromFile("fonts/Police.ttf")) {
		std::cout << "Erreur de chargement de la police!" << std::endl;
		return;
	}

	// definition casque
	//if (objet == "Casque") {
	sf::Texture Casque;
	if (!Casque.loadFromFile("texture/Casque de base.png")) {
		std::cout << "Erreur lors du chargement de la texture" << std::endl;
		return;
	}

	sf::Sprite sprite_casque;
	sprite_casque.setTexture(Casque);
	//}


	//if (objet == "Plastron") {
	sf::Texture Plastron;
	if (!Plastron.loadFromFile("texture/Plastron.png")) {
		std::cout << "Erreur lors du chargement de la texture" << std::endl;
		return;
	}
	sf::Sprite sprite_Plastron;
	sprite_Plastron.setTexture(Plastron);
	//}

	//if (objet == "Pantalon") {

	sf::Texture Pantalon;
	if (!Pantalon.loadFromFile("texture/Pantalon.png")) {
		std::cout << "Erreur lors du chargement de la texture" << std::endl;
		return;
	}
	sf::Sprite sprite_Pantalon;
	sprite_Pantalon.setTexture(Pantalon);

	//}


	//if (objet == "Chaussure") {

	sf::Texture Chaussure;
	if (!Chaussure.loadFromFile("texture/chaussure.png")) {
		std::cout << "Erreur lors du chargement de la texture" << std::endl;
		return;
	}
	sf::Sprite sprite_Chaussure;
	sprite_Chaussure.setTexture(Chaussure);
	//}

	//if (objet == "Boisson") {

	sf::Texture Boisson;
	if (!Boisson.loadFromFile("texture/Boisson papi.png")) {
		std::cout << "Erreur lors du chargement de la texture" << std::endl;
		return;
	}
	sf::Sprite sprite_Boisson;
	sprite_Boisson.setTexture(Boisson);

	sf::Text Inventaire_text;
	Inventaire_text.setFont(Police);
	Inventaire_text.setString("INVENTAIRE");
	Inventaire_text.setCharacterSize(30);
	Inventaire_text.setFillColor(sf::Color::White);
	Inventaire_text.setPosition(inventoryPosition.x + 10, inventoryPosition.y + 10);
	window.draw(Inventaire_text);


	sf::RectangleShape Case_Personnage(sf::Vector2f(100, 250));
	Case_Personnage.setFillColor(sf::Color(255, 255, 255, 0));
	Case_Personnage.setPosition(inventoryPosition.x + 650, inventoryPosition.y + 30);
	Case_Personnage.setOutlineThickness(7);
	Case_Personnage.setOutlineColor(sf::Color(255, 255, 255));
	window.draw(Case_Personnage);

	sf::RectangleShape Inventaire(sf::Vector2f(inventoryWidth, inventoryHeight));
	Inventaire.setFillColor(sf::Color(0, 0, 0, 50));
	Inventaire.setPosition(inventoryPosition);
	Inventaire.setOutlineThickness(7);
	Inventaire.setOutlineColor(sf::Color(255, 255, 255));
	window.draw(Inventaire);

	// pour fermer la fenetre de l'inventaire 

	sf::Text PRESS_X;
	PRESS_X.setFont(Police);
	PRESS_X.setString("PRESS X TO LEAVE");
	PRESS_X.setCharacterSize(30);
	PRESS_X.setFillColor(sf::Color::White);
	PRESS_X.setPosition(inventoryPosition.x + 10, inventoryPosition.y + 210);
	window.draw(PRESS_X);

	int Position_en_y = inventoryPosition.y + 50;
	int MOOVE_DE_Y = 0;
	int Position_en_x = inventoryPosition.x;

	for (int i = 0; i < 2; i++) {
		int MOOVE_DE_X = 0;

		for (int x = 0; x < 5; x++) {
			MOOVE_DE_X = MOOVE_DE_X + 100;
			sf::RectangleShape Case_inventaire_Item(sf::Vector2f(50, 50));
			Case_inventaire_Item.setFillColor(sf::Color(255, 255, 255, 0));
			Case_inventaire_Item.setPosition(Position_en_x + MOOVE_DE_X, Position_en_y + MOOVE_DE_Y);
			Case_inventaire_Item.setOutlineThickness(7);
			Case_inventaire_Item.setOutlineColor(sf::Color(255, 255, 255));
			window.draw(Case_inventaire_Item);
		}
		MOOVE_DE_Y = MOOVE_DE_Y + 150;
	}
	int Position_y = playerPosition.y + 20;
	int MOOVE_Y = 0;
	for (int i = 0; i < 4; i++) {
		sf::RectangleShape Case_Inventaire_d_equipement(sf::Vector2f(50, 50));
		Case_Inventaire_d_equipement.setFillColor(sf::Color(255, 255, 255, 0));
		Case_Inventaire_d_equipement.setPosition(inventoryPosition.x + 850, Position_y + MOOVE_Y);
		Case_Inventaire_d_equipement.setOutlineThickness(7);
		Case_Inventaire_d_equipement.setOutlineColor(sf::Color(255, 255, 255));
		window.draw(Case_Inventaire_d_equipement);
		MOOVE_Y = MOOVE_Y + 70;
	}
	sprite_casque.setPosition(inventoryPosition.x + 850, inventoryPosition.y + 20);
	window.draw(sprite_casque);

	sprite_Plastron.setPosition(inventoryPosition.x + 850, inventoryPosition.y + 90);
	window.draw(sprite_Plastron);

	sprite_Pantalon.setPosition(inventoryPosition.x + 850, inventoryPosition.y + 160);
	window.draw(sprite_Pantalon);

	sprite_Chaussure.setPosition(inventoryPosition.x + 850, inventoryPosition.y + 230);
	window.draw(sprite_Chaussure);
	/*
	if (Objet_de_l_inventaire == true) {

		sprite_Boisson.setPosition(200, 200);
		window.draw(sprite_Boisson);
	}
	 
	*/

	// poids de l'inventaire : +

	sf::Text POIDS_INVENTAIRE;
	std::string Poids_de_l_inventaire = getPOIDS();
	POIDS_INVENTAIRE.setFont(Police);
	POIDS_INVENTAIRE.setString(Poids_de_l_inventaire);
	POIDS_INVENTAIRE.setCharacterSize(30);
	POIDS_INVENTAIRE.setFillColor(sf::Color::White);
	POIDS_INVENTAIRE.setPosition(inventoryPosition.x + 1000, inventoryPosition.y + 210);
	window.draw(POIDS_INVENTAIRE);


}


