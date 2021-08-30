/**
* @file Personnage.cpp
* @brief Fichier d'implémentation de la classe Personnage
*/

#include <iostream>
#include "Personnage.h"


Personnage::Personnage (){
	nom = "Default";
}

Personnage::Personnage (const std::string& n){
  nom = n;
}

std::string Personnage::getNom ()const{
  return nom;
}

Sac * Personnage::getSacRef() {
	return &sac;
}

Pokemon Personnage :: getIemePokemon (unsigned int i)const{
	assert (i>=0 && i<=5);
	return equipePokemon[i];
}

Pokemon * Personnage :: getIemePokemonRef (unsigned int i) {
	assert (i>=0 && i<=5);
	return &equipePokemon[i];
}

Pokemon* Personnage::getEquipePokemon (){
  return equipePokemon;
}

Objet Personnage::getObjetDansSac (unsigned int i) const {
	assert (i>=0 && i<=15);
	return sac.getIemeObjet (i);
}

Objet* Personnage::getObjetDansSacRef (unsigned int i) {
	assert (i>=0 && i<=15);
	return sac.getIemeObjetRef (i);
}

Sac Personnage::getSac ()const{
	return sac;
}

void Personnage::setNom (const std::string & n){
	nom = n;
}

void Personnage::recevoirObjet (const Objet & objet) {
	unsigned int i;
	i = objet.getTypeObjet();
	sac.augmenterQuantiteObjetIeme(i, objet.getQuantite());
}

void Personnage::setIemePokemon (const Pokemon & pokemon,unsigned int i){
	assert (i>=0 && i<=5);
	equipePokemon [i] = pokemon;
}

Personnage& Personnage :: operator = (const Personnage & Perso) {
	nom = Perso.nom;
	for (unsigned int i(0);i<=5;i++) {
		setIemePokemon(Perso.getIemePokemon(i), i);
	}
	sac=Perso.getSac();
	return *this;
}


Joueur::Joueur (): Personnage () {
  nbDefaites = 0;
  nbVictoires = 0;
  niveau = 0;
  argent = 0;
}

Joueur::Joueur (const std::string& n):Personnage (n){
  nbDefaites = 0;
  nbVictoires = 0;
  niveau = 0;
  argent = 0;
}

unsigned int Joueur::getArgent ()const{
  return argent;
}

unsigned int Joueur::getNbVictoires ()const{
  return nbVictoires;
}

unsigned int Joueur::getNbDefaites ()const{
  return nbDefaites;
}

unsigned int Joueur::getNiveau ()const{
	return niveau;
}

void Joueur::recevoirArgent (unsigned int i){
  argent += i;
}

void Joueur::depenserArgent (unsigned int i){
  argent -= i;
  if (argent > 5000)argent = 0;
}

void Joueur::augmenterNiveau (){
  niveau++;
}

void Joueur::augmenterNbDefaites (){
  nbDefaites++;
}

void Joueur::augmenterNbVictoires (){
  nbVictoires++;
}

void Joueur::setNiveau (unsigned int i){
	niveau = i;
}

bool Joueur:: chargerJoueur (){
	  std::ifstream fichierSauvegarde ("data/Sauvegarde/SauvegardePerso/sauvegarde.txt");
		if (!fichierSauvegarde.is_open ()){
			std::cout << "Impossible d'ouvir le fichier de chargement du joueur" << '\n';
			return false;
		}
		else {
			std::string name;
			std::string nomPokemon;
			int niveauAvantDebloque;

			fichierSauvegarde>>name;

			setNom (name);

			for (unsigned int i (0);i<6;i++){
				fichierSauvegarde>>nomPokemon;
				fichierSauvegarde>>niveauAvantDebloque;
				Pokemon pokemon;
				pokemon.chargerPokemon ("data/Pokemon/pokemon"+std::to_string(niveauAvantDebloque)+"/"+nomPokemon+".txt");
				setIemePokemon (pokemon,i);
			}
			return true;
		}
}

bool Joueur::sauvegarderJoueur ()const{
	std::ofstream fichierSauvegarde ("data/Sauvegarde/SauvegardePerso/sauvegarde.txt");
	if (!fichierSauvegarde.is_open ()){
		return false;
	}
	else {
		fichierSauvegarde<<getNom ()<<' ';
		for (unsigned int i (0);i<6;i++){
			fichierSauvegarde<<getIemePokemon (i).getNom ()<<' '<<getIemePokemon(i).getNiveauAvantDebloque()<<" ";
			getIemePokemon (i).sauvegarderPokemon ("data/Sauvegarde/SauvegardePokemon/sauvegardePokemon"+std::to_string (i)+".txt");
		}
		fichierSauvegarde<<nbDefaites<<' '<<nbVictoires<<' '<<' '<<niveau<<' '<<argent;
		return true;
	}
}

Adversaire::Adversaire (): Personnage () {
  objetDonnee = NULL;
  argentDonnee = 0;
}

Adversaire::Adversaire (const std::string& n): Personnage (n){
  objetDonnee = NULL;
  argentDonnee = 0;
}

Adversaire::~Adversaire (){
  detruireObjet ();
}

void Adversaire::detruireObjet (){
  delete objetDonnee;
  objetDonnee = NULL;
}

unsigned int Adversaire::getArgentDonnee ()const{
  return argentDonnee;
}

Objet* Adversaire::getObjetDonne ()const{
  return objetDonnee;
}

void Adversaire::setArgentDonnee (unsigned int i){
  argentDonnee = i;
}

void Adversaire::setObjetDonne (const Objet & o){
  objetDonnee = new Objet;
  *objetDonnee = o;
}

void Adversaire::chargerAdversaire (unsigned int niveau){
	std::ifstream fichier("data/Sauvegarde/SauvegardeAdversaire/adversaire"+std::to_string (niveau)+".txt");
	if (!fichier.is_open ()){
		std::cout << "erreur lors de l'ouverture de l'adversaire" << '\n';
	}
	std::string nomJoueur;
	fichier>>nomJoueur;
	setNom (nomJoueur);
	Pokemon pokemon;
	std::string nomPokemon;
	for (unsigned int i (0);i<6;i++){
		fichier>>nomPokemon;
		pokemon.chargerPokemon ("data/Pokemon/pokemon"+std::to_string (niveau)+"/"+nomPokemon+".txt");
		setIemePokemon (pokemon,i);
	}

}

void Personnage::testRegression (){
  std::cout << "Nom joueur : " <<getNom ()<<'\n';
  std::cout << "Nom 4ème Pokémon : " <<getIemePokemon (4).getNom ()<<'\n';
  std::cout << "Objet 4 :" <<getObjetDansSac (4).getNomObjet ()<< '\n';
}
