#include "solveur.h"
#include "modele.h"

// solveurEulerExplicite.cpp
// Implémente le schéma d’Euler explicite.

// Schéma explicite : y_{n+1} = y_n + dt * f(y_n)
void SolveurEulerExplicite::pas_de_temps(Etat& y, double dt, const ModeleEDO& modele)
{
	// Calcul des dérivées à l’état courant
	Etat dy = modele.f(y);

	y.CA += dt * dy.CA;
	y.CT += dt * dy.CT;
	y.CS += dt * dy.CS;

	// On impose les contraintes physiques
	nnNeg(y);
}
