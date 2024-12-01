#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <iostream>
#include <ctime>
#include "salles.hpp"
#include "coffre.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Config.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"

bool inventaireOuvert;
bool Objet_de_l_inventaire =false;

using namespace std;
using namespace sf;



class window {
private:
	int width;
	int height;
public:
	window(int width, int height) : width(1080), height(1920) {
		this->width = width;
		this->height = height;
	}

	void set_width(int width) {
		this->width = width;
	}

	void set_height(int height) {
		this->height = height;
	}

	int get_width() {
		return this->width;
	}

	int get_height() {
		return this->height;
	}

	void afficher() {	
		sf::VideoMode fullscreenMode = sf::VideoMode::getDesktopMode();
		sf::RenderWindow window(fullscreenMode, "Fenêtre en Plein Écran", sf::Style::Fullscreen);
		sf::RectangleShape player(sf::Vector2f(32, 32));
		player.setFillColor(sf::Color::White);
		player.setPosition(728, 308);
		sf::Vector2f position = player.getPosition();
		
		
		while (window.isOpen())
		{
			window.clear();
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();

					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Up) {

						}
						if (event.key.code == sf::Keyboard::Down) {

						}
					}
				}
			}
			sf::Texture background;
			if (!background.loadFromFile("C:/Users/quent/sfml/asset/background.png")) {
				std::cout << "Erreur lors du chargement de la texture" << std::endl;
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
				player.move(-3, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				player.move(3, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
				player.move(0.0, -3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				player.move(0.0, 3);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {
				for (int i=0; i < 2; i++) {
					for (int x = 0; x < 5; x++) {
						sf::RectangleShape Inventaire(sf::Vector2f(32, 32));
						Inventaire.setFillColor(sf::Color::White);
						Inventaire.setPosition(728, 308);
						

					}
				}
			}

			
			window.clear();
			sf::Sprite spritebackground;
			spritebackground.setTexture(background);
			window.draw(spritebackground);
			salles salle1(480, 480);
			salle1.afficherSalle(window);

			window.draw(player);
			sf::Font Police;
			if (!Police.loadFromFile("C:/Users/quent/source/repos/PROJET JEU/ressource/Police.ttf")) { // Remplacez par le chemin d'une police existante
				std::cout << "Erreur de chargement de la police!" << std::endl;
				return;
			}

			sf::Vector2f position = player.getPosition();
			if (position.x >= 800 && position.x <= 1100 && position.y >= 500 && position.y <= 700) {
				
				sf::RectangleShape TEXT(sf::Vector2f(500, 50));
				TEXT.setFillColor(sf::Color(255, 255, 255));
				TEXT.setPosition(720, 900);
				window.draw(TEXT);

				sf::Text PRESS_E;
				PRESS_E.setFont(Police);
				PRESS_E.setString("PRESS E");
				PRESS_E.setCharacterSize(50);
				PRESS_E.setFillColor(sf::Color::White);
				PRESS_E.setPosition(850, 890);
				window.draw(PRESS_E);
				

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
					Objet_de_l_inventaire = true;
					
				}


			}

			// asset pour l'inventaire : 
			sf::Texture Casque;
			if (!Casque.loadFromFile("C:/Users/quent/sfml/asset/Casque de base.png")) {
				std::cout << "Erreur lors du chargement de la texture" << std::endl;
				return;
			}
			sf::Sprite sprite_casque;
			sprite_casque.setTexture(Casque);

			sf::Texture Plastron;
			if (!Plastron.loadFromFile("C:/Users/quent/sfml/asset/Plastron.png")) {
				std::cout << "Erreur lors du chargement de la texture" << std::endl;
				return;
			}
			sf::Sprite sprite_Plastron;
			sprite_Plastron.setTexture(Plastron);

			sf::Texture Pantalon;
			if (!Pantalon.loadFromFile("C:/Users/quent/sfml/asset/Pantalon.png")) {
				std::cout << "Erreur lors du chargement de la texture" << std::endl;
				return;
			}
			sf::Sprite sprite_Pantalon;
			sprite_Pantalon.setTexture(Pantalon);

			sf::Texture Chaussure;
			if (!Chaussure.loadFromFile("C:/Users/quent/sfml/asset/chaussure.png")) {
				std::cout << "Erreur lors du chargement de la texture" << std::endl;
				return;
			}
			sf::Sprite sprite_Chaussure;
			sprite_Chaussure.setTexture(Chaussure);

			sf::Texture Boisson;
			if (!Boisson.loadFromFile("C:/Users/quent/sfml/asset/Boisson papi.png")) {
				std::cout << "Erreur lors du chargement de la texture" << std::endl;
				return;
			}
			sf::Sprite sprite_Boisson;
			sprite_Boisson.setTexture(Boisson);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {
				inventaireOuvert = !inventaireOuvert;  // Change l'état de l'inventaire
			}
				if (inventaireOuvert) {
					sf::sleep(sf::milliseconds(200));
					
					if (inventaireOuvert) {

						// impossible de comprendre ce truc bizarre : 
						/*
						sf::RectangleShape Inventaire(sf::Vector2f(1000, 300));
						Inventaire.setFillColor(sf::Color(255, 255, 255, 50));
						Inventaire.setPosition(450, 50);
						Inventaire.setOutlineThickness(7);
						Inventaire.setOutlineColor(sf::Color(255, 255, 255));
						window.draw(Inventaire);
						*/


						


						// Pour ecrire inventaire 
						sf::Text Inventaire_text;
						Inventaire_text.setFont(Police);
						Inventaire_text.setString("INVENTAIRE");
						Inventaire_text.setCharacterSize(30);
						Inventaire_text.setFillColor(sf::Color::White);
						Inventaire_text.setPosition(460, 50);
						window.draw(Inventaire_text);

						//et la ça marche jsp prq
						sf::RectangleShape Inventaire(sf::Vector2f(1000, 300));
						Inventaire.setFillColor(sf::Color(0, 0, 0, 50));
						Inventaire.setPosition(450, 50);
						Inventaire.setOutlineThickness(7);
						Inventaire.setOutlineColor(sf::Color(255, 255, 255));
						window.draw(Inventaire);

						// pour fermer la fenetre de l'inventaire 

						sf::Text PRESS_X;
						PRESS_X.setFont(Police);
						PRESS_X.setString("PRESS X TO LEAVE");
						PRESS_X.setCharacterSize(30);
						PRESS_X.setFillColor(sf::Color::White);
						PRESS_X.setPosition(460, 310);
						window.draw(PRESS_X);

						sf::RectangleShape Case_Personnage(sf::Vector2f(100, 250));
						Case_Personnage.setFillColor(sf::Color(255, 255, 255, 0));
						Case_Personnage.setPosition(1100, 80);
						Case_Personnage.setOutlineThickness(7);
						Case_Personnage.setOutlineColor(sf::Color(255, 255, 255));
						window.draw(Case_Personnage);

						int Position_en_y = 100;
						int MOOVE_DE_Y = 0;
						int Position_en_x = 450;

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
						int Position_y = 70;
						int MOOVE_Y = 0;
						for (int i = 0; i < 4; i++) {
							sf::RectangleShape Case_Inventaire_d_equipement(sf::Vector2f(50, 50));
							Case_Inventaire_d_equipement.setFillColor(sf::Color(255, 255, 255, 0));
							Case_Inventaire_d_equipement.setPosition(1300, Position_y + MOOVE_Y);
							Case_Inventaire_d_equipement.setOutlineThickness(7);
							Case_Inventaire_d_equipement.setOutlineColor(sf::Color(255, 255, 255));
							window.draw(Case_Inventaire_d_equipement);
							MOOVE_Y = MOOVE_Y + 70;
						}
						sprite_casque.setPosition(1300,70);
						window.draw(sprite_casque);

						sprite_Plastron.setPosition(1300, 140);
						window.draw(sprite_Plastron);
						
						sprite_Pantalon.setPosition(1300, 210);
						window.draw(sprite_Pantalon);

						sprite_Chaussure.setPosition(1300, 280);
						window.draw(sprite_Chaussure);

						if (Objet_de_l_inventaire == true) {

							sprite_Boisson.setPosition(200, 200);
							window.draw(sprite_Boisson);
						}



						// poids de l'inventaire : 

						sf::Text POIDS_INVENTAIRE;
						string Poids_de_l_inventaire = getPOIDS();
						POIDS_INVENTAIRE.setFont(Police);
						POIDS_INVENTAIRE.setString(Poids_de_l_inventaire);
						POIDS_INVENTAIRE.setCharacterSize(30);
						POIDS_INVENTAIRE.setFillColor(sf::Color::White);
						POIDS_INVENTAIRE.setPosition(1400, 310);
						window.draw(POIDS_INVENTAIRE);

						
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
						inventaireOuvert = !inventaireOuvert;
					}
				}
			

			window.display();
			
		}
	}
};