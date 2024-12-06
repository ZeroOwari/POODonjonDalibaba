#include <iostream>
#include <string>
#include <vector>
#include "Heros.hpp"
class ObserverMetier {
private:
    const std::vector<std::string> metiersDisponibles = { "Guerrier", "Magicien", "Voleur", "Ranger" };
    const std::string metierCache = "Archimage";

public:
    void proposerChoixMetier(std::shared_ptr<Heros> heros) {
        std::cout << "Votre héros est au niveau " << heros->get_niveau()
            << ". Vous pouvez choisir un métier parmi ceux disponibles." << std::endl;

        for (size_t i = 0; i < metiersDisponibles.size(); ++i) {
            std::cout << i + 1 << ". " << metiersDisponibles[i] << std::endl;
        }
        std::cout << "0. Ne pas choisir de métier maintenant" << std::endl;

        int choix = -1;
        do {
            std::cout << "Entrez le numéro de votre choix : ";
            std::cin >> choix;
        } while (choix < 0 || choix > static_cast<int>(metiersDisponibles.size()));

        if (choix == 0) {
            std::cout << "Vous avez décidé de ne pas choisir de métier pour l'instant." << std::endl;
        }
        else {
            std::string metierChoisi = metiersDisponibles[choix - 1];
            heros->set_metier(metierChoisi);
            std::cout << "Le héros " << heros->get_origine() << " a choisi le métier : "
                << metierChoisi << std::endl;
        }
    }

    void verifierEtAssignerMetier(std::shared_ptr<Heros> heros) {
        if (heros->get_niveau() >= 5 && heros->get_metier().empty()) {
            proposerChoixMetier(heros);
        }
        if (heros->get_niveau() >= 12 && heros->get_metier().empty()) {
            std::cout << "Votre héros a atteint le niveau 12 sans métier. Le métier caché "
                << metierCache << " est maintenant disponible !" << std::endl;
            heros->set_metier(metierCache);
        }
    }
};