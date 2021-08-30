#ifndef SFMLCHARGER_H
#define SFMLCHARGER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include "../Personnage/Personnage.h"
#include "../Combat/Combat.h"
#include "../SFMLCombat/SFML.h"
#include <string>

/**
* @brief Classe SFMLCharger qui gère l'affichage du chargement des joueurs
*/


class SFMLCharger {
private:

  /**
	* @var *fenetrePrincipale
	* @brief Pointeur vers un RenderWindow contenant la fenetre principale
	*/
  sf::RenderWindow *fenetrePrincipale;

  /**
	* @var fondchoixcombat
	* @brief Texture contenant le fond de la case combat
	*/
  sf::Texture fondchoixcombat;

  /**
	* @var rectangleFond
	* @brief RectangleShape contenant le rectangle de fond de la fenêtre principale
	*/
  sf::RectangleShape rectangleFond;

  /**
	* @var nouveauJoueur
	* @brief RectangleShape contenant le rectangle de la case nouveauJoueur
	*/
  sf::RectangleShape nouveauJoueur;

  /**
	* @var ancienJoueur
	* @brief RectangleShape contenant le rectangle de la case ancienJoueur
	*/
  sf::RectangleShape ancienJoueur;

  /**
	* @var jouer2V2
	* @brief RectangleShape contenant le rectangle pour lancer une partie en 2V2
	*/
  sf::RectangleShape jouer2V2;

  /**
	* @var ancien
	* @brief Text contenant le text de la case ancienJoueur
	*/
  sf::Text ancien;

  /**
	* @var nouveau
	* @brief Text contenant le text de la case nouveauJoueur
	*/
  sf::Text nouveau;

  /**
	* @var J2V2
	* @brief Text contenant le text de la case jouer2V2
	*/
  sf::Text J2V2;

  /**
	* @var affichage
	* @brief Text contenant le text de la case affichage
	*/
  sf::Text affichage;

  /**
	* @var font
	* @brief Text contenant la premier police d'écriture
	*/
  sf::Font font;

  /**
	* @var font2
	* @brief Text contenant la deuxieme police d'écriture
	*/
  sf::Font font2;

  /**
	* @var font3
	* @brief Text contenant la troisieme police d'écriture
	*/
  sf::Font font3;

  /**
	* @var dimX
	* @brief Entier positif contenant la dimension en X de l'écran
	*/
  unsigned int dimX;

  /**
	* @var dimY
	* @brief Entier positif contenant la dimension en Y de l'écran
	*/
  unsigned int dimY;

  /**
	* @var position
	* @brief Entier positif contenant la position du curseur
	*/
  unsigned int position;

  /**
	* @var fin
	* @brief Booleen contenant si le chargement est finit
	*/
  bool fin;

  /**
  * @var texteRentre
  * @brief Chaine de caractere contenant le prenom rentre par le joueur
  */
  std::string texteRentre;

public :
  /**
  * @brief Constructeur qui initialise toutes les variables de la classe et qui copie la fenetre passée en paramètre dans une nouvelle fenêtre
  * @param[in-out] Window RenderWindow contenant la fenêtre principale à copier
  */
  SFMLCharger (sf::RenderWindow& Window);

  /**
  * @brief       La boucle principale de Jeu et qui permet de démarrer le jeu et encapsuler toutes les
  *             autres boucles nécéssaire à l'affichage du combat
  */
  void boucleAffichage ();

private:

  /**
  * @brief En fonction de l'action du joueur, action va appeller de nouvelle fonction
  */
  void action ();

  /**
  * @brief Dessine avec le format defaut un rectangle en fonction de la postion
  */
  void dessinerDefault ();

  /**
  * @brief Dessine avec le format selection un rectangle en fonction de la postion
  */
  void dessinerSelection ();

  /**
  * @brief S'occupe d'initialiser un nouveau joueur puis de le sauvegarder dans un fichier
  * @param[in-out] joueur Joueur contenant le joueur à créer
  */
  void chargementNouveauJoueur (Joueur& joueur);

  /**
  * @brief S'occupe d'initialiser un nouveau joueur puis de le sauvegarder dans un fichier
  * @param[in-out] joueur Joueur contenant le joueur principal
  * @param[in-out] adversaire Adversaire contenant l'adversaire du joueur
  */
  void lancerCombat (Joueur& joueur,Adversaire& adversaire);

  /**
  * @brief S'occupe d'initialiser les pokémons du joueur
  * @param[in-out] joueur Joueur contenant le joueur principal
  */
  void ouvrirPokedex (Joueur& joueur);

};

#endif
