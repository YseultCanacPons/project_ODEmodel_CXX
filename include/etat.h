#ifndef ETAT_H
#define ETAT_H 

// etat.h
// Définit la structure Etat (CA, CS, CT) et la fonction nnNeg().

struct Etat
{
	double CA;
	double CT;
	double CS;
};

// Garantit la non-négativité des composantes de l'état y
inline void nnNeg(Etat& y) 
{
	if (y.CA < 0) y.CA = 0;
	if (y.CT < 0) y.CT = 0;
	if (y.CS < 0) y.CS = 0;
}


#endif
