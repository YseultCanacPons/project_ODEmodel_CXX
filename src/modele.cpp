#include "modele.h"

// Modele.cpp
// Implémente la dynamique du modèle d’équations différentielles.


// Constructeur prenant les paramètres physiques
ModeleEDO::ModeleEDO(const Parametres& params) : _p(params) {}

// Calcul des dérivées d'état (système d'équations différentielles)
Etat ModeleEDO::f(const Etat& y) const {

    Etat dy;

    // Équations définies selon le modèle fourni
    dy.CA = -_p.alpha * y.CA + _p.beta * y.CS;
    dy.CS = _p.alpha * y.CA - (_p.beta + _p.gamma) * y.CS + _p.delta * y.CT;
    dy.CT = _p.gamma * y.CS - _p.delta * y.CT;

    return dy;
}
