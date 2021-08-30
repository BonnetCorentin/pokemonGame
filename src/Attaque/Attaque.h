/*! \file Attaque.h
    \brief Documentation du module Attaque.
    Le module Attaque représente les attaques qui seront utilisés par les
		Pokemon durant leur combat.
*/

#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>


/*! \enum TypeAttaque
 * Le type d'une attaque, elle peut-être Physique ou Spécial.
 */
enum TypeAttaque {
	physique = 0,
	speciale = 1,
	pasTypeAttaque = -1
};

/*! \enum Type
 * L'élément associé à l'attaque.
 */
enum Type {
	feu = 0,
	eau = 1,
	insecte = 2,
	acier = 3,
	dragon = 4,
	electrik = 5,
	normal = 6,
	vol = 7,
	glace = 8,
	psy = 9,
	roche = 10,
	tenebre = 11,
	spectre = 12,
	poison = 13,
	sol = 14,
	plante = 15,
	combat = 16,
	pasType = -1
};


/*! \class Attaque Attaque.h "src/Attaque/Attaque.h"
 *  \brief La classe représentant les Attaques des Pokemon.
 *
 * Le module Attaque représente les attaques utilisés par les Pokemon durant,
 * plusieurs statistiques différents sont associés à chaque attaque.
 */
class Attaque {

private :

	/*! \var std::strign nom
	*  \brief Nom de l'Attaque.
	*
	*  nom correspond au nom associé a l'Attaque.
	*/
	std :: string nom;
	/*! \var Type type
	*  \brief Element de l'attaque.
	*
	*  type correspond à l'élément associé à l'attaque (feu, eau, plante, etc...).
	*/
	Type type;
	/*! \var unsigned int nbPP
	*  \brief nbPP de l'attaque.
	*
	*  nbPP correspond au nombre de fois que l'attaque peut-être utilisé avant de
	*  devoir la recharger, nbPP baisse d'un à chaque utilisation de l'attaque.
	*/
	unsigned int nbPP;
	/*! \var unsigned int nbPPMax
	*  \brief nbPPMax de l'attaque.
	*
	*  nbPPMax correspond à nbPP au moment de la création de l'attaque.
	*/
	unsigned int nbPPMax;
	/*! \var unsigned int puissance
	*  \brief Puissance de l'attaque.
	*
	*  Puissance correspond à la puissance de l'attaque, cela servira durant le
	*  calcul des dégâts d'une attaque.
	*/
	unsigned int puissance;
	/*! \var unsigned int precision
	*  \brief Précision de l'attaque.
	*
	*  Précision correspond à la précision de l'attaque, ce qui est équivalent
	*  au chance que l'attaque touche son adversaires.
	*/
	unsigned int precision;

	/*! \var TypeAttaque typeAttaque
	*  \brief Type de l'attaque
	*
	*  typeAttaque correspond à la manière dont l'attaque est infligé, sur un coup
	*  physique ou plutôt spéciale.
	*/
	TypeAttaque typeAttaque;

public :

	/**
	* \brief       Constructeur de Attaque
	* \details    Construit un objet de type Attaque
	*
	*/
	Attaque ();

	/**
	* \brief       Constructeur de Attaque
	* \details    Construit un objet de type Attaque avec toutes les statistiques
	* \param[in] nomAttaque Nom de l'attaque
	* \param[in] t Élément de l'attaque
	* \param[in] pp Nombre de PP de l'attaque
	* \param[in] Puissance Puissance de l'attaque
	* \param[in] Precision Précision de l'attaque
	* \param[in] eA Effet de l'attaque
	* \param[in] desc Description de l'attaque
	* \param[in] tA Type de l'attaque
	*/
	Attaque (const std::string & nomAttaque, const Type & t, unsigned int pp,unsigned int Puissance,unsigned int Precision,const TypeAttaque & tA);

	//Mutateurs

	/**
	* \brief       Mutateur de nbPP
	* \details    Modifie nbPP
	* \param[in] nb Nombre de pp
	*/
	void setNbPP (unsigned int nb);

	/**
	* \brief       Mutateur de nom
	* \details    Modifie nom
	* \param[in] nom Nom de l'attaque
	*/
	void setNom(std::string nom);

	//Accesseurs

	/**
	* \brief       Accesseur de Puissance
	* \details    Renvoie la puissance de l'attaque
	* \return Le paramètre Puissance de l'attaque
	*/
	unsigned int getPuissance ()const;

	/**
	* \brief       Accesseur de Précision
	* \details    Renvoie la précision de l'attaque
	* \return Le paramètre précision de l'attaque
	*/
	unsigned int getPrecision ()const;

	/**
	* \brief       Accesseur de nbPP
	* \details    Renvoie le nombre de PP de l'attaque
	* \return Le paramètre nbPP de l'attaque
	*/
	unsigned int getNbPP () const;

	/**
	* \brief       Accesseur de nbPPMax
	* \details    Renvoie le nombre de PP Max de l'attaque
	* \return Le paramètre nbPPMax de l'attaque
	*/
	unsigned int getNbPPMax ()const;

	/**
	* \brief       Accesseur de typeAttaque
	* \details    Renvoie le type de l'attaque
	* \return Le paramètre typeAttaque de l'attaque
	*/
	TypeAttaque getTypeAttaque () const;

	/**
	* \brief       Accesseur de nom
	* \details    Renvoie le nom de l'attaque
	* \return Le paramètre nom de l'attaque
	*/
	std :: string getNom ()const;

	/**
	* \brief       Accesseur de type
	* \details    Renvoie l'élément de l'attaque
	* \return Le paramètre type de l'attaque
	*/
	Type getType ()const;

	/**
	* \brief    Charge une attaque à partir d'un fichier
	* \details    Permet de charger une attaque à partir d'un fichier
	* \param[in] fichier Chemin d'accès vers le fichier
	*/
	void rentrerAttaqueFichier (const std :: string& fichier, const std::string& attack);


	//Autres fonctions

	/**
	* \brief    Charge une attaque à partir d'un fichier
	* \details    Permet de charger une attaque à partir d'un fichier
	*/
	void testRegression ();

	/**
	* \brief    Baisse le nombre de PP de l'attaque de 1 unité
	* \details    Diminue d'1 le nombre de PP de l'attaque sur laquel on l'applique
	*/
	void baisserNbPP ();


	//Opérateurs
	/**
	* \brief    Opérateur égale de Attaque
	* \details  Effectue une copie compléte des données d'Attaque
	* \param[in] attaque L'attaque qui est utilisé pour effectuer la copie
	*/
	Attaque& operator = (const Attaque & attaque);

};

#endif
