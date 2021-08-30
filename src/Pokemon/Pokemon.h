#ifndef POKEMON_H
#define POKEMON_H

#include "../Objet/Objet.h"
#include "../Attaque/Attaque.h"
#include <string>
#include <assert.h>

/**
* @file Pokemon.h
* @brief Classe Pokemon qui gère un pokémon et qui contient son type d'objet,son nom,sa description et sa quantité
*/
class Pokemon {

private :

	/**
	* @var nom
	* @brief chaîne de caractère contenant le nom du pokémon
	*/
	std :: string nom;

	/**
	* @var niveauAvantDebloque
	* @brief entier positif contenant le niveau avant de pouvoir débloquer le pokémon
	*/
	unsigned int niveauAvantDebloque;

	/**
	* @var type
	* @brief tableau de deux Type contenant tous les types du pokémon
	*/
	Type type[2];

	/**
	* @var tabAttaque
	* @brief tableau de quatre Attaque contenant toutes les attaques du pokémon
	*/
	Attaque tabAttaque [4];

	/**
	* @var defenseSpeciale
	* @brief entier positif contenant la défense spéciale du pokémon
	*/
	unsigned int defenseSpeciale;

	/**
	* @var defensePhysique
	* @brief entier positif contenant la défense physique du pokémon
	*/
	unsigned int defensePhysique;

	/**
	* @var attaqueSpeciale
	* @brief entier positif contenant l'attaque spéciale du pokémon
	*/
	unsigned int attaqueSpeciale;

	/**
	* @var attaquePhysique
	* @brief entier positif contenant l'attaque physique du pokémon
	*/
	unsigned int attaquePhysique;

	/**
	* @var vitesse
	* @brief entier positif contenant la vitesse du pokémon
	*/
	unsigned int vitesse;

	/**
	* @var nbPV
	* @brief entier positif contenant le nombre de PV du pokémon
	*/
	unsigned int nbPV;

	/**
	* @var nbPVMax
	* @brief entier positif contenant le nombre de PV max du pokémon
	*/
	unsigned int nbPVMax;

public :

	//constructeur

	/**
  * @brief Constructeur par défaut qui initialise son nom à "Pikachu",son niveau avant d'être débloqué à 0, son premier type à electrik,son deuxième type à pasType, ses attaques à des attaques par défaut et toutes ses statistiques à 200
  */
	Pokemon ();

	/**
  * @brief Constructeur qui initialise le pokémon avec des paramètres
	* @param[in] nomPokemon chaîne de caractère contenant le nom du pokémon à copier
	* @param[in] defenseSpe entier positif contenant la défense spéciale du pokémon à copier
	* @param[in] defensePhy entier positif contenant la défense physique du pokémon à copier
	* @param[in] attaqueSpe entier positif contenant l'attaque spéciale du pokémon à copier
	* @param[in] attaquePhy entier positif contenant l'attaque physique du pokémon à copier
	* @param[in] vit entier positif contenant la vitesse du pokémon à copier
	* @param[in] PVPokemon entier positif contenant les PV du pokémon à copier
	* @param[in] type1 entier positif contenant le premier type du pokémon à copier
	* @param[in] type2 entier positif contenant le deuxième type du pokémon à copier
	*/
	Pokemon (const std :: string& nomPokemon,unsigned int defenseSpe,unsigned int defensePhy,unsigned int attaqueSpe, unsigned int attaquePhy, unsigned int vit,unsigned int PVPokemon, const int & type1, const int & type2);

	//accesseur
	/**
  * @brief Accesseur d'un type du tableau
  * @param[in] i entier postif contenant l'index du type à retourner
	* @return retourne un entier contenant le type du pokemon
  */
	int getTypeIeme (unsigned int i) const ;

	/**
  * @brief Accesseur de la variable defenseSpeciale
  * @return retourne un entier postif contenant la défense spéciale du pokemon
  */
	unsigned int getDefenseSpeciale ()const;

	/**
  * @brief Accesseur de la variable defensePhysique
  * @return retourne un entier postif contenant la défense physique du pokemon
  */
	unsigned int getDefensePhysique ()const;

	/**
  * @brief Accesseur de la variable attaquePhysique
  * @return retourne un entier postif contenant l'attaque physique du pokemon
  */
	unsigned int getAttaquePhysique () const;

	/**
  * @brief Accesseur de la variable attaqueSpeciale
  * @return retourne un entier postif contenant l'attaque spéciale du pokemon
  */
	unsigned int getAttaqueSpeciale () const;

	/**
  * @brief Accesseur de la variable vitesse
  * @return retourne un entier postif contenant la vitesse du pokemon
  */
	unsigned int getVitesse ()const;

	/**
  * @brief Accesseur de la variable NbPV
  * @return retourne un entier postif contenant les PV du pokemon
  */
	unsigned int getPV ()const;

	/**
  * @brief Accesseur de la variable NbPVMax
  * @return retourne un entier postif contenant les PV max du pokemon
  */
	unsigned int getPVMax ()const;

	/**
  * @brief Accesseur de la variable niveauAvantDebloque
  * @return retourne un entier postif contenant le niveau avant de débloquer le pokemon
  */
	unsigned int getNiveauAvantDebloque ()const;

	/**
	* @brief Accesseur d'une attaque du tableau d'attaque par référence
	* @param[in] i entier postif contenant l'index de l'attaque à retourner
	* @return retourne une référence vers une attaque du tableau d'attaque
	*/
	Attaque& getIemeAttaque (unsigned int i);

	/**
	* @brief Accesseur d'une attaque du tableau d'attaque par pointeur
	* @param[in] i entier postif contenant l'index de l'attaque à retourner
	* @return retourne un pointeur vers une attaque du tableau d'attaque
	*/
	Attaque * getIemeAttaqueRef (unsigned int i);

	/**
	* @brief Accesseur de la variable nom
	* @return retourne une chaîne de caractère contenant le nom du pokemon
	*/
	std :: string getNom ()const;

	//mutateur

	/**
  * @brief Augmente NbPV du nombre de la variable passé en paramètre
  * @param[in] vie entier postif contenant le nombre de PV à restaurer au pokemon
  */
	void gagneVie (unsigned int vie);

	/**
  * @brief Baisse NbPV du nombre de la variable passé en paramètre
  * @param[in] vie entier postif contenant le nombre de PV à enlever au pokemon
  */
	void perdreVie (unsigned int vie);

	/**
  * @brief Mutateur d'une attaque du tableau d'attaque
	* @param[in] attaque Attaque contenant l'attaque du pokemon à copier
  * @param[in] i entier postif contenant l'index du tableau d'attaque à changer
  */
	void setIemeAttaque (const Attaque& attaque,unsigned int i);

	/**
  * @brief Mutateur de la variable NbPV
  * @param[in] i entier postif contenant le nombre de PV du pokemon à copier
  */
	void setPV (unsigned int i);

	/**
  * @brief Mutateur de la variable nom
	* @param[in] name chaîne de caractère contenant le nom du pokemon à copier
  */
	void setNom (const std::string & name);

	//Operateur

	/**
  * @brief surcharge de l'opérateur égal
  * @param[in] Pkmn Pokemon contenant le pokemon à copier
  * @return retourne une réference sur l'instance Pokemon
  */
	Pokemon& operator = (const Pokemon & Pkmn);

  //Autres fonctions

	/**
  * @brief charge dans un fichier tout le contenu du pokemon
	* @param [in]
  */
	void sauvegarderPokemon (const std::string& cheminSauvegarde)const;

	/**
  * @brief charge dans le pokemon tous les informations contenues dans un fichier
	* @param[in] cheminSauvegarde chaîne de caractère contenant le chemin vers le fichier
	*/
	void chargerPokemon (const std::string& chemin);

	/**
	* @brief test toutes les fonctions de la classe
	*/
	void testRegression();

};


#endif
