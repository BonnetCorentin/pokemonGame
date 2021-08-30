/**
* @file Objet.cpp
* @brief Fichier d'implémentation de la classe Objet
*/

#include "Objet.h"
#include <iostream>
#include <assert.h>

//Constructeur et destructeur

Objet::Objet() {
	typeObjet=Default;
	nomObjet="NULL";
	quantite=0;
}

//Accesseur

int Objet::getTypeObjet () const {
	return typeObjet;
}

std::string Objet::getNomObjet () const {
	return nomObjet;
}

unsigned int Objet::getQuantite () const {
	return quantite;
}

//Mutateur

void Objet::setTypeObjet (const TypeObjet & type) {
	typeObjet=type;
}

void Objet::setNomObjet (const std::string & nom) {
	nomObjet=nom;
}

void Objet::setQuantite (unsigned int nombre) {
	assert(nombre<=99);
	quantite=nombre;
}

//Operateur

Objet& Objet :: operator = (const Objet& objet){
	typeObjet = objet.typeObjet;
	nomObjet = objet.nomObjet;
	quantite = objet.quantite;
	return *this;
}

//Autres fonctions

void Objet::baisserQuantite() {
	quantite=quantite-1;
}

void Objet::testRegression() {
	std::cout<<getQuantite()<<std::endl;
	std::cout<<getTypeObjet()<<std::endl;
	std::cout<<getNomObjet()<<std::endl;
	setTypeObjet(Potion);
	setNomObjet("Potion");
	setQuantite(7);
	std::cout<<getQuantite()<<std::endl;
	std::cout<<getTypeObjet()<<std::endl;
	std::cout<<getNomObjet()<<std::endl;
}
