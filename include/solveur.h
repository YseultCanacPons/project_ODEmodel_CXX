#ifndef SOLVEUR_H
#define SOLVEUR_H

#include "etat.h"
#include "parametres.h"

// solveur.h
// Déclare l’interface SolveurODE ainsi que les solveurs.
// Euler explicite et Euler implicite.

class ModeleEDO;

class SolveurEDO
{
public : 
	virtual ~SolveurEDO() = default;
	
	// Méthode virtuelle : un pas de temps
	virtual void pas_de_temps(Etat& y, double dt, const ModeleEDO& modele) = 0;
};

class SolveurEulerExplicite : public SolveurEDO
{
public :
	// Implémentation du schéma explicite
	void pas_de_temps(Etat& y, double dt, const ModeleEDO& modele);
};

class SolveurEulerImplicite : public SolveurEDO
{
public :
	// Implémentation du schéma implicite via Newton
	void pas_de_temps(Etat& y, double dt, const ModeleEDO& modele);
};

#endif
