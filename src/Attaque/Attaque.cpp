#include "Attaque.h"

/**
* @file Attaque.cpp
* @brief Fichier d'implémentation de la classe Attaque.cpp
*/

//Constructeur & Destructeur
Attaque :: Attaque (){
	nom = "Nom";
	type = pasType;
	nbPP = 0;
	nbPPMax=0;
	puissance = 0;
	precision = 0;
	typeAttaque = pasTypeAttaque;
}

Attaque :: Attaque (const std :: string & nomAttaque, const Type & t,
unsigned int pp,unsigned int pui,unsigned int prec, const TypeAttaque & tA) {

	assert (t >= -1 && t<=16);
	assert (pp<= 99);
	assert (pui< 1000);
	assert (prec <=100);
	assert (tA >= -1 && tA <= 1);

	nom = nomAttaque;
	type = t;
	nbPP = pp;
	nbPPMax= pp;
	puissance = pui;
	precision = prec;
	typeAttaque = tA;
}

void Attaque :: setNbPP (unsigned int nb) {

	assert (nb<=99);

	nbPP += nb;
	if (nbPP > nbPPMax) {
		nbPP = nbPPMax;
	}
}

std :: string Attaque :: getNom ()const  {
	if (!nom.empty()) {
	return nom;
	}
	return "pas de nom";
}

Type Attaque :: getType ()const {
	return type;
}

unsigned int Attaque :: getNbPP ()const {
	return nbPP;
}

unsigned int Attaque :: getNbPPMax ()const {
	return nbPPMax;
}

unsigned int Attaque :: getPuissance ()const {
	return puissance;
}

unsigned int Attaque :: getPrecision ()const {
	return precision;
}

TypeAttaque Attaque :: getTypeAttaque() const {
	return typeAttaque;
}

void Attaque :: baisserNbPP (){
	nbPP --;
}

void Attaque :: rentrerAttaqueFichier (const std :: string& fichier, const std::string& attack) {
	std :: ifstream monFichier (fichier);
	int a,c;
	std::string vide;
	if (!monFichier.is_open ()) {
		std::cout << "Erreur lors de l'ouverture du fichier, "+fichier+" introuvable" << '\n';
	}
	else {
	do {
		nom.clear();
		std::getline(monFichier, vide);
		std::getline (monFichier, nom, '.');
	}
	while (nom.compare(attack)!=0);
	monFichier >> a >> precision >> puissance >> nbPP >> c;
	nbPPMax=nbPP;
	type = (Type)a;
	typeAttaque = (TypeAttaque)c;
	monFichier.close ();
  }
}

Attaque& Attaque :: operator = (const Attaque & attaque){
	nom = attaque.getNom();
	type = attaque.getType();
	nbPP = attaque.getNbPP();
	nbPPMax = attaque.getNbPPMax();
	puissance = attaque.getPuissance();
	precision = attaque.getPrecision();
	typeAttaque = attaque.getTypeAttaque();

	return *this;
}

void Attaque:: testRegression()
{
	std::string nom;
	std::cout << "Nom du type au début :" << nom <<'\n';
	//rentrerAttaqueFichier("data/Plante.txt");
	nom=getNom();
	Type type = getType();
	unsigned int puissance = getPuissance();
	unsigned int precision = getPrecision();
	unsigned int Pp = getNbPP();
	TypeAttaque typeA = getTypeAttaque();
	std::cout << "Apres fichier : "<< nom <<" " << type << " " << puissance << " " << precision << " " << Pp << " " << typeA <<'\n';
}
