#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "window.hpp"
#include "salles.hpp"
#include "coffre.hpp"
#include "sfml/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

#include "string"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "window.hpp"
#include "Item.h"
#include "Item_sous_classe.h"



#include <iostream>
#include "SFML/Graphics.hpp"
#include "window.hpp"
#include <vector>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>


#include "SFML/Graphics.hpp"
#include <iostream>
#include "window.hpp"
#include "Item.h"
#include "Item_sous_classe.h"
#include "calcul_new_poids.hpp"





#include <iostream>
#include <vector>
using namespace std;

vector<item*> inventaire;

int taille;
int poidstotal;
Consommable potion_de_biere(2);
Equipement chaussure_de_discretion_bruyante(15);
Armement epee_emoussee(10);

void origine() {
    
    inventaire.push_back(&potion_de_biere);
    inventaire.push_back(&chaussure_de_discretion_bruyante);
    inventaire.push_back(&epee_emoussee);

    int taille = 0;
    

    for (int i = 0; i < inventaire.size(); i++) {
        taille++;
        cout << inventaire[i] << endl;
    }
    cout << taille << endl;

    

    int poidsTotal = item::calculer_poids_total(inventaire, taille);
    cout << "Poids total de l'item : " << poidsTotal << " unites." << endl;
}



int poidsTotal = 25;


void newPOIDS(int newpoids, string type,string nom_de_l_obejet) {
    cout << "vous venez de trouver un objet de type :" << type << "qui est : " << nom_de_l_obejet << endl;
    cout << poidsTotal << endl;
    poidsTotal = poidsTotal + newpoids;
    cout << "voici le nouveau poids de votre inventaire : " << poidsTotal << endl;
   
    

}

string getPOIDS() {
    std::string Poids_inventaire = std::to_string(poidsTotal);
    return Poids_inventaire;
}


