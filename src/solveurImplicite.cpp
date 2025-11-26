#include "solveur.h"
#include "modele.h"
#include <cmath>
#include <iostream>

// solveurEulerImplicite.cpp
// Implémente le schéma d’Euler implicite en utilisant Newton.

// Méthode de Newton pour résoudre : y_{n+1} = y_n + dt * f(y_{n+1})
void SolveurEulerImplicite::pas_de_temps(Etat& y, double dt, const ModeleEDO& modele)
{
	// On part de l'état actuel comme estimation initiale
    Etat y_new = y;
    
    const Parametres& p = modele.getParams();

    // Paramètres du Newton
    const int maxIter = 50;
    const double tol = 1e-8;

    for (int iter = 0; iter < maxIter; ++iter) {

        // f(y_new)
        Etat fy = modele.f(y_new);

        // Fonction F(y_new) = y_new - y - dt*f(y_new)
        Etat F;
        F.CA = y_new.CA - y.CA - dt * fy.CA;
        F.CS = y_new.CS - y.CS - dt * fy.CS;
        F.CT = y_new.CT - y.CT - dt * fy.CT;

        // Vérification convergence (norme simple)
        double norme = std::fabs(F.CA) + std::fabs(F.CS) + std::fabs(F.CT);
        if (norme < tol) break;

        // Jacobienne analytique du système
        double J11 = 1 - dt * (-p.alpha);
        double J12 = -dt * (p.beta);
        double J13 = 0;

        double J21 = -dt * (p.alpha);
        double J22 = 1 - dt * ( -(p.beta + p.gamma) );
        double J23 = -dt * (p.delta);

        double J31 = 0;
        double J32 = -dt * (p.gamma);
        double J33 = 1 - dt * ( -(p.delta) );

        // Système linéaire 3x3 à résoudre : J * delta = -F
        double det =
            J11*(J22*J33 - J23*J32) -
            J12*(J21*J33 - J23*J31) +
            J13*(J21*J32 - J22*J31);

        if (std::fabs(det) < 1e-14) {
            std::cerr << "Jacobian is singular, Newton failed." << std::endl;
            break;
        }

        Etat delta;

        delta.CA =
            (-(F.CA)*(J22*J33 - J23*J32)
             + (-(F.CS))*(J12*J33 - J13*J32)
             + (-(F.CT))*(J12*J23 - J13*J22)) / det;

        delta.CS =
            (-(F.CA)*(J21*J33 - J23*J31)
             + (-(F.CS))*(J11*J33 - J13*J31)
             + (-(F.CT))*(J11*J23 - J13*J21)) / det;

        delta.CT =
            (-(F.CA)*(J21*J32 - J22*J31)
             + (-(F.CS))*(J11*J32 - J12*J31)
             + (-(F.CT))*(J11*J22 - J12*J21)) / det;

        // Mise à jour Newton
        y_new.CA += delta.CA;
        y_new.CS += delta.CS;
        y_new.CT += delta.CT;
    }

    // Mise à jour finale
    y = y_new;

    // Contraintes physiques
    nnNeg(y);
}
