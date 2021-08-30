/**
* @file Personnage.h
* \brief Module gérant un Personnage dans PokePEIP
*
*/


#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include "../Pokemon/Pokemon.h"
#include "../Sac/Sac.h"
#include <assert.h>
#include <fstream>


/**
* @brief Classe Personnage qui gère un personnage et qui contient son nom, son équipe pokémon et son sac
*/
class Personnage {
private :

    /**
    * @var nom
    * @brief chaine de caractère contenant le nom du personnage
    */
  	std::string nom;
    /**
    * @var equipePokemon
    * @brief tableau de six pokémons contenant tous les pokémons du personnage
    */
  	Pokemon equipePokemon [6];
    /**
    * @var sac
    * @brief sac contenant tous les objets du personnage
    */
    Sac sac;

public :

  /**
  * @brief Constructeur par défaut qui initialise le nom du personnage à "Default"
  */
  Personnage ();

  /**
  * @brief Constructeur qui initialise le nom du personnage avec la chaîne de paramètre passé en paramètre
  * @param[in] n chaîne de caractère contenant le nom du personnage à copier
  */
  Personnage (const std::string& n);

  //accesseur
  /**
  * @brief Accesseur de la variable nom
  * @return retourne une chaîne de caractère contenant le nom du personnage
  */
  std::string getNom ()const;

  /**
  * @brief Accesseur d'un pokémon du tableau de pokémon
  * @param[in] i entier positif contenant l'index du tableau à accéder
  * @return retourne un pokémon contenu dans le tableau de pokémon
  */
  Pokemon getIemePokemon (unsigned int i)const;

  /**
  * @brief Accesseur d'un pokémon du tableau de pokémon par référence
  * @param[in] i entier positif contenant l'index du tableau à accéder
  * @return retourne un pointeur sur un pokémon contenu dans le tableau de pokémon
  */
  Pokemon* getIemePokemonRef (unsigned int i) ;

  /**
  * @brief Accesseur du tableau de pokémon par référence
  * @return retourne un pointeur sur le tableau de pokémon
  */
  Pokemon* getEquipePokemon ();

  /**
  * @brief Accesseur d'un objet dans le sac
  * @param[i] i entier positif contenant l'index de l'objet à accéder
  * @return retourne un objet contenue dans le sac
  */
  Objet getObjetDansSac (unsigned int i)const;

  /**
  * @brief Accesseur d'un objet dans le sac par référence
  * @param[i] i entier positif contenant l'index de l'objet à accéder
  * @return retourne un pointeur sur un objet contenue dans le sac
  */
  Objet* getObjetDansSacRef (unsigned int i);

  /**
  * @brief Accesseur du sac
  * @return retourne le sac
  */
  Sac getSac ()const;

  /**
  * @brief Accesseur du sac par référence
  * @return retourne un pointeur sur le sac
  */
  Sac * getSacRef();

  //mutateur

  /**
  * @brief Mutateur de la variable nom
  * @param[in] n chaîne de caractère contenant le nom du personnage à copier
  */
  void setNom (const std::string & n);

  /**
  * @brief Mutateur d'un pokémon du tableu de pokémon
  * @param[in] pokemon Pokemon contenant le pokémon à copier
  * @param[in] i entier positif contenant l'index du pokemon à changer
  */
  void setIemePokemon (const Pokemon & pokemon,unsigned int i);

  /**
  * @brief Mutateur d'un objet du sac
  * @param[in] objet Objet contenant l'objet à copier
  */
  void recevoirObjet (const Objet & objet);

  /**
  * @brief test toutes les fonctions de la classe
  */
  void testRegression ();

  /**
  * @brief surcharge de l'opérateur égal
  * @param[in] Perso Personnage contenant le personnage à copier
  * @return retourne une réference sur l'instance Personnage
  */
  Personnage& operator = (const Personnage & Perso);

};


/**
* @brief Classe Joueur hérité de la classe Personnage qui gère un joueur et qui contient son nombre de défaites,de victoires,son niveau et son argent
*/
class Joueur : public Personnage {
private:

  /**
  * @var nbDefaites
  * @brief entier positif contenant le nombre de défaites du joueur
  */
	unsigned int nbDefaites;

  /**
  * @var nbVictoires
  * @brief entier positif contenant le nombre de victoires du joueur
  */
	unsigned int nbVictoires;

  /**
  * @var niveau
  * @brief entier positif contenant le niveau du joueur
  */
	unsigned int niveau;

  /**
  * @var argent
  * @brief entier positif contenant l'argent du joueur
  */
	unsigned int argent;

public :

  /**
  * @brief Constructeur par défaut qui appel le constructeur par défaut de Personnage et qui initialise nbDefaites à 0,nbVictoires à 0,niveau à 0 et l'argent à 0
  */
  Joueur ();

  /**
  * @brief Constructeur qui appelle le constructeur de Personnage avec un paramètre et qui initialise nbDefaites à 0,nbVictoires à 0,niveau à 0 et l'argent à 0
  * @param[in] n nom du personnage à copier
  */
  Joueur (const std::string& n);
  //accesseur

  /**
  * @brief Accesseur de la variable argent
  * @return retourne un entier positif contenant l'argent du joueur
  */
  unsigned int getArgent ()const;

  /**
  * @brief Accesseur de la variable nbVictoires
  * @return retourne un entier positif contenant le nombre de victoires du joueur
  */
  unsigned int getNbVictoires ()const;

  /**
  * @brief Accesseur de la variable nbDefaites
  * @return retourne un entier positif contenant le nombre de défaites du joueur
  */
  unsigned int getNbDefaites ()const;

  /**
  * @brief Accesseur de la variable niveau
  * @return retourne un entier positif contenant le niveau du joueur
  */
  unsigned int getNiveau ()const;

  //mutateur

  /**
  * @brief Augmente la variable argent
  * @param[in] n entier postif contenant l'argent à ajouter
  */
  void recevoirArgent (unsigned int n);

  /**
  * @brief Diminue la variable argent
  * @param[in] n entier postif contenant l'argent à enlever
  */
  void depenserArgent (unsigned int n);

  /**
  * @brief Augmente la variable nbDefaites de 1
  */
  void augmenterNbDefaites ();

  void setNiveau (unsigned int i);

  /**
  * @brief Augemente la variable nbVictoires de 1
  */
  void augmenterNbVictoires ();

  /**
  * @brief Augmente la variable niveau de 1
  */
  void augmenterNiveau ();

  /**
  * @brief charge dans le joueur tous les informations contenues dans un fichier
  * @return retourne un booléen contenant 1 si le chargement c'est bien passée sinon 0
  */
  bool chargerJoueur ();

  /**
  * @brief charge dans un fichier tout le contenu du joueur
  * @return retourne un booléen contenant 1 si la sauvergarde c'est bien passée sinon 0
  */
  bool sauvegarderJoueur  ()const;

};

/**
* @brief Classe Adversaire hérité de la classe Personnage qui gère un adversaire et qui contient son nombre de défaites,de victoires,son niveau et son argent
*/
class Adversaire : public Personnage {
private:

  /**
  * @var argentDonnee
  * @brief entier postif contenant l'argent donné par l'adversaire
  */
  unsigned int argentDonnee;
  /**
  * @var objetDonnee
  * @brief pointeur vers Objet contenant l'objet donné par l'adversaire
  */
	Objet * objetDonnee;

public:

  /**
  * @brief Constructeur par défaut qui appel le constructeur par défaut de Personnage et qui initialise objetDonnee à NULL et argentDonnee à 0
  */
  Adversaire ();

  /**
  * @brief Constructeur qui appelle le constructeur de Personnage avec un paramètre et qui initialise objetDonnee à NULL et argentDonnee à 0
  * @param[in] n nom du personnage à copier
  */
  Adversaire (const std::string& n);

  /**
  * @brief Destructeur qui appelle la fonction detruireObjet
  */
  ~Adversaire ();
  //accesseur

  /**
  * @brief Accesseur de la variable argentDonnee
  * @return retourne un entier positif contenant l'argent donné par l'adversaire
  */
  unsigned int getArgentDonnee ()const;

  /**
  * @brief Accesseur de la variable objetDonné
  * @return retourne un pointeur vers l'objet donné par l'adversaire
  */
  Objet* getObjetDonne ()const;

  //mutateur

  /**
  * @brief Mutateur de la variable argentDonnee
  * @param[in] i entier positif contenant l'argent à donné à copier
  */
  void setArgentDonnee (unsigned int i);

  /**
  * @brief Mutateur de la variable argentDonnee
  * @param[in] o Objet contenant l'objet à donné à copier
  */
  void setObjetDonne (const Objet & o);

  /**
  * @brief Delete l'objet et qui le fait pointer sur NULL
  */
  void detruireObjet ();

  /**
  * @brief charge dans un fichier tout le contenu de l'adversaire
  */
  void chargerAdversaire (unsigned int niveau);

};

#endif
