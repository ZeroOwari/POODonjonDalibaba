#pragma once

using namespace std;
class item {
private:
    int poids;
public:
    item(int poids) : poids(poids) {}


    int poids_de_l_objet() const {
        return poids;
    }


    static int calculer_poids_total(const vector<item*>& inventaire, int taille) {
        int total = 0;
        int x = 0;
        for (int i = 1; i < taille; i++) {
            x++;
            total += inventaire[x]->poids_de_l_objet();
            cout << total << endl;
        }
        return total;
    }
};

