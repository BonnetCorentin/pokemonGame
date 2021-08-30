#ifndef SAC_H
#define SAC_H

#include "../Objet/Objet.h"

/**
* @file Sac.h
* @brief Classe Sac qui gère un sac et qui contient un tableau d'objet
*/

class Sac {
	private :

	/**
	* @var SacADos
	* @brief tableau de 16 objets contenus dans le sac
	*/
	Objet SacADos[16];

	public :

	//constructeur

	/**
  * @brief Constructeur par défaut qui initialise le sac avec des objets et met leur quantité à 5
  */
	Sac();

	//accesseur

	/**
  * @brief Accesseur du type d'un objet du sac
  * @param[in] i entier postif contenant l'index de l'objet
	* @return retourne un entier positif contenant le type de l'objet
  */
	unsigned int getTypeObjetIeme (unsigned int i) const ;

	/**
  * @brief Accesseur du nom d'un objet du sac
  * @param[in] i entier postif contenant l'index de l'objet
	* @return retourne une chaîne de caractère contenant le nom de l'objet
  */
	std::string getNomObjetIeme (unsigned int i) const ;

	/**
  * @brief Accesseur d'un objet du sac
  * @param[in] i entier postif contenant l'index de l'objet
	* @return retourne un Objet contenant l'objet
  */
	Objet getIemeObjet (unsigned int i)const;

	/**
  * @brief Accesseur d'un objet du sac par référence
  * @param[in] i entier postif contenant l'index de l'objet
	* @return retourne un pointeur vers un objet du sac
  */
	Objet* getIemeObjetRef (unsigned int i);

	/**
  * @brief Accesseur d'un objet du sac
  * @param[in] i entier postif contenant l'index de l'objet
	* @return retourne un entier postif contenant la quantité de l'objet
  */
	unsigned int getQuantiteObjetIeme (unsigned int i) const ;

	//mutateur

	/**
  * @brief Mutateur de la quantité d'un objet du sac
	* @param[in] i entier postif contenant l'index de l'objet
	* @param[in] nombre entier postif contenant la quantité de l'objet à copier
  */
	void setQuantiteObjetIeme (unsigned int i, unsigned int nombre);

	/**
  * @brief Mutateur du nom d'un objet du sac
	* @param[in] i entier postif contenant l'index de l'objet
	* @param[in] nom chaîne de caractère contenant le nom de l'objet à copier
  */
	void setNomObjetIeme (unsigned int i, const std::string & nom);

	/**
  * @brief Mutateur du type d'un objet du sac
	* @param[in] i entier postif contenant l'index de l'objet
	* @param[in] type TypeObjet contenant le type de l'objet à copier
  */
	void setTypeObjetIeme (unsigned int i, const TypeObjet & type);

  //autres fonctions

	/**
	* @brief Met toutes les quantités des objets du sac à 5
	*/
	void initSac ();

	/**
	* @brief Met toutes les quantités des objets du sac à 0
	*/
	void viderSac ();

	/**
  * @brief Augmente la quantité d'un objet du sac
	* @param[in] i entier postif contenant l'index de l'objet
	* @param[in] nb entier postif contenant la quantité à augmenter
  */
	void augmenterQuantiteObjetIeme(unsigned int i, unsigned int nb);

	/**
  * @brief Diminue la quantité d'un objet du sac
	* @param[in] i entier postif contenant l'index de l'objet
	* @param[in] nb entier postif contenant la quantité à diminuer
  */
	void diminuerQuantiteObjetIeme(unsigned int i, unsigned int nb);

	/**
	* @brief test toutes les fonctions de la classe
	*/
	void testRegression();
};

#endif
