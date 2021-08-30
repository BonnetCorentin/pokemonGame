/**
* @file Sac.cpp
* @brief Fichier d'implémentation de la classe Sac
*/

#include "Sac.h"
#include <iostream>
#include <assert.h>


Sac::Sac() {
	std::string NomObjet[6]={"Potion", "Super potion", "Hyper potion", "Potion Max", "Elixir","Max Elixir"};
	for (unsigned int i(0);i<=5;i++) {
		setQuantiteObjetIeme(i, 5);
		setTypeObjetIeme(i, (TypeObjet)i);
		setNomObjetIeme(i, NomObjet[i]);
	}
}

void Sac::initSac() {
	for (unsigned int i(0);i<6;i++) {
		setQuantiteObjetIeme(i,5);
	}
}

void Sac::viderSac() {
	for (unsigned int i(0);i<6;i++) {
		setQuantiteObjetIeme(i,0);
	}
}

void Sac::augmenterQuantiteObjetIeme(unsigned int i , unsigned int nb) {
	assert (i>=0 && i<=5);
	setQuantiteObjetIeme(i, getQuantiteObjetIeme(i)+nb);
}

void Sac::diminuerQuantiteObjetIeme(unsigned int i , unsigned int nb){
	assert (i>=0 && i<=5);
	setQuantiteObjetIeme(i, getQuantiteObjetIeme(i)-nb);
}

unsigned int Sac::getTypeObjetIeme(unsigned int i) const {
	assert (i>=0 && i<=5);
	return SacADos[i].getTypeObjet();
}

std::string Sac::getNomObjetIeme (unsigned int i) const {
	assert (i>=0 && i<=5);
	return SacADos[i].getNomObjet();
}

Objet Sac::getIemeObjet (unsigned int i) const {
	assert (i>=0 && i<=5);
	return SacADos[i];
}

Objet * Sac::getIemeObjetRef (unsigned int i) {
	assert (i>=0 && i<=5);
	return &SacADos[i];
}

unsigned int Sac::getQuantiteObjetIeme (unsigned int i) const {
	assert (i>=0 && i<=5);
	return SacADos[i].getQuantite();
}

void Sac::setQuantiteObjetIeme (unsigned int i, unsigned int nb) {
	assert (i>=0 && i<=5);
	SacADos[i].setQuantite(nb);
}

void Sac::setNomObjetIeme (unsigned int i, const std::string & nom) {
	assert (i>=0 && i<=5);
	SacADos[i].setNomObjet(nom);
}

void Sac::setTypeObjetIeme(unsigned int i, const TypeObjet & type) {
	assert (i>=0 && i<=5);
	SacADos[i].setTypeObjet(type);
}


void Sac::testRegression() {
	initSac();
	for(unsigned int i(0);i<6;i++) {
		std::cout<<"Objet numéro "<<i+1<<":       ";
		std::cout<<getTypeObjetIeme(i)<<"||";
		std::cout<<getNomObjetIeme(i)<<"||";
		std::cout<<getQuantiteObjetIeme(i)<<"||";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	augmenterQuantiteObjetIeme(1, 10);
	std::cout<<getQuantiteObjetIeme(1)<<std::endl;
	diminuerQuantiteObjetIeme(1, 2);
	std::cout<<getQuantiteObjetIeme(1)<<std::endl;
	viderSac();
	for(unsigned int i(0);i<16;i++) {
		std::cout<<"Objet numéro "<<i+1<<":        ";
		std::cout<<getTypeObjetIeme(i)<<"||";
		std::cout<<getNomObjetIeme(i)<<"||";
		std::cout<<getQuantiteObjetIeme(i)<<"||";
		std::cout<<std::endl;
	}
}
