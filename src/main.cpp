#include <iostream>
#include "etat.h"
#include "parametres.h"
#include "modele.h"
#include "solveur.h"

// main.cpp
// Programme principal : initialisation, choix du solveur et simulation.

int main() {
    Parametres p;
    Etat y;

    // Initialisation de l'état
    y.CA = 1.0;
    y.CS = 0.0;
    y.CT = 0.5;

    // Définition des paramètres du modèle
    p.alpha = 0.5;
    p.beta = 0.4;
    p.gamma = 0.1;
    p.delta = 0.2;
    p.epsilon = 0.3;
    p.zeta = 0.1;
    p.capacite_maximale = 1.0;

    double dt;
    int N;

    // Demande du pas de temps à l'utilisateur
    std::cout << "Donnez le pas de temps dt : ";
    std::cin >> dt;

    // Demande du nombre total de pas
    std::cout << "Donnez le nombre total de pas N : ";
    std::cin >> N;

    // Choix du solveur
    std::cout << "Choisissez le solveur (1 = explicite, 2 = implicite) : ";
    int choix;
    std::cin >> choix;

    SolveurEDO* solveur = nullptr;

    if (choix == 1) {
        // Solveur d'Euler explicite
        solveur = new SolveurEulerExplicite;
    }
    else if (choix == 2) {
        // Solveur implicite (itérations de Newton)
        solveur = new SolveurEulerImplicite;
    }
    else {
        std::cerr << "Choix invalide !" << std::endl;
        return 1;
    }

    // Instanciation du modèle EDO
    ModeleEDO modele(p);

    // Boucle d'intégration temporelle
    for (int i = 0; i < N; i++) {
        solveur->pas_de_temps(y, dt, modele);
    }

    // Affichage de l'état final
    std::cout << "Valeur finale de CA = " << y.CA << std::endl;
    std::cout << "Valeur finale de CS = " << y.CS << std::endl;
    std::cout << "Valeur finale de CT = " << y.CT << std::endl;

    // Libération mémoire du solveur
    delete solveur;

    return 0;
}
