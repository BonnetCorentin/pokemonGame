/**
* \brief Module gérant un objet dans le jeu PokePEIP
* @file Objet.h
*/


#ifndef OBJET_H
#define OBJET_H

#include <string>


enum TypeObjet {
	Default=-1, // Par défaut
	Potion=0, // Soigne 20 PV
	Super_Potion=1, // Soigne 60 PV
	Hyper_Potion=2, // Soigne 120 PV
	Potion_Max=3, // Soigne tout les PV
	Elixir=4, // Restaure 10 PP de toutes les capacités
	Max_Elixir=5, // Restaure tout les PP de toutes les capacités
};

/**
* @brief Classe Objet qui gère un objet et qui contient son type d'objet,son nom,sa description et sa quantité
*/
class Objet {
    private :

		/**
		* @var typeObjet
		* @brief enum TypeObjet contenant le type de l'objet (entre -1 et 15)
		*/
		TypeObjet typeObjet;

		/**
		* @var nomObjet
		* @brief chaîne de caractère contenant le nom de l'objet
		*/
    std::string nomObjet;

		/**
		* @var quantite
		* @brief entier positif contenant la quantité de l'objet
		*/
	  unsigned int quantite;

    public :

	//Constructeur et destructeur

		/**
		* @brief Constructeur par défaut qui initialise le type d'objet à Default,
		* le nomObjet à "NULL", la description à "Aucune description" et la quantite à 0
		*/
    Objet ();

	//Accesseur

		/**
		* @brief Accesseur de la variable TypeObjet
		* @return retourne en entier contenant le type de l'objet
		*/
    int getTypeObjet () const;

		/**
		* @brief Accesseur de la variable nomObjet
		* @return retourne une chaîne de caractère contenant le nom de l'objet
		*/
  	std::string getNomObjet() const;

		/**
		* @brief Accesseur de la variable quantite
		* @return retourne un entier positif contenant la quantité de l'objet
		*/
	  unsigned int getQuantite() const;

	//Mutateur

		/**
		* @brief Mutateur de la variable typeObjet
		* @param[in] type type de l'objet à copier
		*/
    void setTypeObjet (const TypeObjet & type);

		/**
		* @brief Mutateur de la variable nomObjet
		* @param[in] nom chaîne de caractère contenant le nom de l'objet à copier
		*/
		void setNomObjet(const std::string & nom);

		/**
		* @brief Mutateur de la variable quantite
		* @param[in] nombre entier positif contenant la quantité de l'objet à copier
		*/
		void setQuantite (unsigned int nombre);

	//Operateur

		/**
		* @brief surcharge de l'opérateur égal
		* @param[in] objet Objet contenant l'objet à copier
		* @return retourne une réference sur l'instance objet
		*/
		Objet& operator = (const Objet& objet);

	//Autres fonctions

		/**
		* @brief baisse la quantité de l'objet de un
		*/
		void baisserQuantite();

		/**
		* @brief test toutes les fonctions de la classe
		*/
		void testRegression();

};

#endif
