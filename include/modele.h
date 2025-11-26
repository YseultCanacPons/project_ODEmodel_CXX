#ifndef MODELE_H
#define MODELE_H

#include "etat.h"
#include "parametres.h"

// modele.h
// Déclare le modèle d’équations différentielles et la fonction f(y).


class ModeleEDO
{
private :
	Parametres _p; // paramètres physiques du modèle

public :
	ModeleEDO(const Parametres& params);
	Etat f(const Etat& y) const;
	
	// Retourne la structure des paramètres physiques du modèle.
	const Parametres& getParams() const { return _p; }
};

#endif
