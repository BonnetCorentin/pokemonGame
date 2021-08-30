/**
* @file Pokemon.cpp
* @brief Fichier d'implémentation de la classe Pokemon
*/


#include "Pokemon.h"
#include <iostream>
#include <fstream>

Pokemon :: Pokemon (){
	Attaque attaquePika("ATTACK", electrik, 99, 100, 100, speciale);
	nom="Pikachu";
	niveauAvantDebloque=0;
	type[0]=electrik;
	type[1]=pasType;
	for (unsigned int i(0);i<=3;i++) {
		setIemeAttaque(attaquePika, i);
	}
	defenseSpeciale=200;
	defensePhysique=200;
	attaqueSpeciale=200;
	attaquePhysique=200;
	vitesse=200;
	nbPV=200;
	nbPVMax=200;
}

Pokemon ::Pokemon (const std :: string& nomPokemon,unsigned int defenseSpe,unsigned int defensePhy,unsigned int attaqueSpe,unsigned int
attaquePhy, unsigned int vit,unsigned int PVPokemon, const int & type1, const int & type2){
	nom = nomPokemon;
	niveauAvantDebloque = 0;
	defenseSpeciale = defenseSpe;
	defensePhysique = defensePhy;
	attaqueSpeciale = attaqueSpe;
	attaquePhysique = attaquePhy;
	vitesse = vit;
	nbPV = PVPokemon;
	nbPVMax = PVPokemon;
	type[0] = (Type)type1;
	type[1] = (Type)type2;
}

void Pokemon :: gagneVie (unsigned int vie){
	nbPV += vie;
	if (nbPV > nbPVMax) {
		nbPV = nbPVMax;
	}
}

void Pokemon :: perdreVie (unsigned int vie) {
	nbPV = nbPV - vie;
	if (nbPV > 5000) {
		nbPV = 0;
	}
}

int Pokemon :: getTypeIeme (unsigned int i) const {
	return type[i];
}

unsigned int Pokemon :: getDefenseSpeciale ()const {
	return defenseSpeciale;
}

unsigned int Pokemon :: getDefensePhysique ()const {
	return defensePhysique;
}

unsigned int Pokemon :: getAttaqueSpeciale ()const {
	return attaqueSpeciale;
}

unsigned int Pokemon :: getAttaquePhysique ()const {
	return attaquePhysique;
}

unsigned int Pokemon :: getVitesse ()const {
	return vitesse;
}

unsigned int Pokemon :: getPV ()const {
	return nbPV;
}

unsigned int Pokemon :: getPVMax ()const {
	return nbPVMax;
}

unsigned int Pokemon :: getNiveauAvantDebloque ()const {
	return niveauAvantDebloque;
}

Attaque & Pokemon :: getIemeAttaque (unsigned int i){
	assert (i>=0 && i<=3);
	return tabAttaque[i];
}

Attaque * Pokemon :: getIemeAttaqueRef (unsigned int i){
	assert (i>=0 && i<=3);
	return &tabAttaque[i];
}

std :: string Pokemon :: getNom ()const {
	return nom;
}

void Pokemon :: setIemeAttaque (const Attaque& attaque,unsigned int i){
	assert (i>=0 && i<=3);
	tabAttaque [i] = attaque;
}

void Pokemon :: setPV (unsigned int i){
	nbPV = i;
}

void Pokemon :: setNom (const std::string & name) {
	nom=name;
}


void Pokemon :: chargerPokemon (const std::string& chemin){
	std :: ifstream monFichier (chemin);
	if (monFichier.is_open ()){
		int a,b;
		std::string vide;
		std::string typeAttaque;
		std::string nomAttaque;
		monFichier >> nom;
		monFichier >> niveauAvantDebloque;
		monFichier >> a;
		monFichier >> b;
		monFichier >> defenseSpeciale;
		monFichier >> defensePhysique;
		monFichier >> attaqueSpeciale;
		monFichier >> attaquePhysique;
		monFichier >> vitesse;
		monFichier >> nbPVMax;
		std::getline(monFichier,vide);
		nbPV = nbPVMax;
		type[0] = (Type)a;
		type[1] = (Type)b;
		for (unsigned int i(0);i<=3;i++) {
			std::getline(monFichier, typeAttaque, '/');
			std::getline(monFichier, nomAttaque, '.');
			tabAttaque[i].rentrerAttaqueFichier("data/Attaque/"+typeAttaque+".txt", nomAttaque);
			typeAttaque.clear();
			nomAttaque.clear();
			std::getline(monFichier, vide);
		}
		monFichier.close ();
	}
	else std::cout << "Erreur lors de l'ouverture du fichier pour charger pokemon, "+chemin+" introuvable" << '\n';
}

void Pokemon::sauvegarderPokemon (const std::string& cheminSauvegarde)const{
		std :: ofstream monFichier (cheminSauvegarde);
		if (!monFichier.is_open ()){
			std::cout << "erreur lors de l'ouverture du fichier de chargement pokemon" << '\n';
		}
		else{
			monFichier <<nom<<' '<<niveauAvantDebloque<<' '<<(int)type[0]<<' '<<(int)type [1]<<' '<<defenseSpeciale<<' '<<defensePhysique<<' '<<attaqueSpeciale<<' '<<attaquePhysique<<' '<<vitesse<<' '<<nbPVMax<<std::endl;
		}
}

Pokemon& Pokemon :: operator = (const Pokemon & Pkmn) {
	nom = Pkmn.nom;
	niveauAvantDebloque=Pkmn.niveauAvantDebloque;
	type[0]=Pkmn.type[0];
	type[1]=Pkmn.type[1];
	for (unsigned int i(0);i<=3;i++) {
		tabAttaque[i]=Pkmn.tabAttaque[i];
	}
	defenseSpeciale=Pkmn.defenseSpeciale;
	defensePhysique=Pkmn.defensePhysique;
	attaqueSpeciale=Pkmn.attaqueSpeciale;
	attaquePhysique=Pkmn.attaquePhysique;
	vitesse=Pkmn.vitesse;
	nbPV=Pkmn.nbPV;
	nbPVMax=Pkmn.nbPVMax;
	return *this;
}

void Pokemon :: testRegression() {
	std::string nom;

	unsigned int niveauAvantDebloque;
	unsigned int defenseSpeciale;
	unsigned int defensePhysique;
	unsigned int attaqueSpeciale;
	unsigned int attaquePhysique;
	unsigned int vitesse;
	unsigned int nbPVMax;

	int type[2];

	chargerPokemon("data/PokemonA/Bulbizarre.txt");
	defenseSpeciale = getDefenseSpeciale();
	attaqueSpeciale = getAttaqueSpeciale();
	defensePhysique = getDefensePhysique();
	attaquePhysique = getAttaquePhysique();
	niveauAvantDebloque = getNiveauAvantDebloque();
	nom = getNom();
	vitesse = getVitesse();
	nbPVMax = getPVMax();
	type[0]=getTypeIeme(0);
	type[1]=getTypeIeme(1);

	assert (defenseSpeciale >= 0 && defenseSpeciale <= 999);
	assert (attaqueSpeciale >= 0 && attaqueSpeciale <= 999);
	assert (defensePhysique >= 0 && defensePhysique <= 999);
	assert (defenseSpeciale >= 0 && defenseSpeciale <= 999);
	assert (attaquePhysique >= 0 && attaquePhysique <= 999);
	assert (niveauAvantDebloque >=0);
	assert (vitesse >= 0 && vitesse <= 999);
	assert (nbPVMax >= 0 && nbPVMax <= 999);
	assert (type[0]==getTypeIeme(0));
	assert (type[1]==getTypeIeme(1));
}
