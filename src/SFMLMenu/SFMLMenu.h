/*! \file SFMLMenu.h
    \brief Documentation du module SFMLMenu.

    Le module SFMLMenu consiste en la gestion de l'affichage du menu principale
    qui va permettre l'accès à toutes les autres fonctions disponibles, il
    s'agit donc du coeur de l'affichage graphique
*/

#ifndef SFMLMENU_H
#define SFMLMENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../SFMLPokedex/SFMLPokedex.h"

/*! \class SFMLMenu SFMLMenu.h "src/SFMLMenu/SFMLMenu.h"
 *  \brief La classe gérant le principale affichage graphique.
 *
 */

class SFMLMenu {
private :
/*! \var sf::RenderWindow  menuWindow
*  \brief La fenêtre principale.
*
*  menuWindow est la fenêtre principale.
*/
  sf::RenderWindow menuWindow;

  /*! \var sf::RenderWindow  windowFermeture
  *  \brief La fenêtre de fermeture.
  *
  *  windowFermeture est la fenêtre de fermeture du jeu.
  */
  sf::RenderWindow windowFermeture;

  /*! \var sf::Text combat
  *  \brief Un texte.
  *
  *  combat est la variable texte contenant le texte du premier menu dans la
  *  fenêtre principale, lancant le combat.
  */
  sf::Text combat;
  /*! \var sf::Text tuto
  *  \brief Un texte.
  *
  *  tuto est la variable texte contenant le texte du deuxième menu dans la
  *  fenêtre principale, ouvrant le tutoriel.
  */
  sf::Text tuto;
  /*! \var sf::Text quitter
  *  \brief Un texte.
  *
  *  quitter est la variable texte contenant le texte du troisieme et dernier
  *  menu dans la fenêtre principale, permettant de quitter.
  */
  sf::Text quitter;
  /*! \var sf::Text textePokedex
  *  \brief Un texte.
  *
  *  textePokedex est la variable contenant le texte indiquant que faire pour
  *  acceder au Pokedex
  */
  sf::Text textePokedex;
  /*! \var sf::Text accueil
  *  \brief Un texte.
  *
  *  accueil est la variable contenant le titre de la page d'accueil
  */
  sf::Text accueil;
  /*! \var sf::Text message
  *  \brief Un texte.
  *
  *  message est la variable contenant le message de la page d'accueil
  */
  sf::Text message;
  /*! \var sf::Text parametre
  *  \brief Un texte.
  *  parametre est la variable contenant le message indiquant comment ouvrir
 titre fenêtre pour modifier le son
  *  parametre
  */
  sf::Text parametre;
  /*! \var sf::Text valeurVolume
  *  \brief Un texte.
  *
  *  valeurVolume est la variable contenant la valeur du son
  */
  sf::Text valeurVolume;
  /*! \var sf::Text corporation
  *  \brief Un texte.
  *
  *  corporation est la variable contenant le texte de corporation de l'accueil
  */
  sf::Text corporation;

  /*! \var sf::Music musiqueAccueil
  *  \brief Une musique.
  *
  *  musiqueAccueil est la variable contenant la musique de la page accueil
  */
  sf::Music musiqueAccueil;
  /*! \var sf::Music musiqueMenu
  *  \brief Une musique.
  *
  *  musiqueMenu est la variable contenant la musique du menu
  */
  sf::Music musiqueMenu;
  /*! \var sf::Music musiqueCombat
  *  \brief Une musique.
  *
  *  musiqueCombat est la variable contenant la musique du menu combat
  */
  sf::Music musiqueCombat;

  /*! \var sf::RectangleShape fondPrincipale
  *  \brief Un rectangle.
  *
  *  fondPrincipale correspond au rectangle de fond de la fenêtre principale
  */
  sf::RectangleShape fondPrincipale;
  /*! \var sf::RectangleShape rectangleCombat
  *  \brief Un rectangle.
  *
  *  rectangleCombat correspond au rectangle comprenant le combat
  */
  sf::RectangleShape rectangleCombat;
  /*! \var sf::RectangleShape rectangleTuto
  *  \brief Un rectangle.
  *
  *  rectangleTuto correspond au rectangle comprenant le tutoriel
  */
  sf::RectangleShape rectangleTuto;
  /*! \var sf::RectangleShape rectangleQuitter
  *  \brief Un rectangle.
  *
  *  rectangleQuitter correspond au rectangle comprenant l'option quitter
  */
  sf::RectangleShape rectangleQuitter;
  /*! \var sf::RectangleShape barreSon
  *  \brief Un rectangle.
  *
  *  barreSon est le rectangle aux dimensions proportionnel à la valeur du son
  */
  sf::RectangleShape barreSon;
  /*! \var sf::RectangleShape barrePlein
  *  \brief Un rectangle.
  *
  *  barrePlein est le rectangle quand le son est à 100, il permet de voir la
  *  diffèrence
  */
  sf::RectangleShape barrePlein;
  /*! \var sf::RectangleShape boutonPlus
  *  \brief Un rectangle.
  *
  *  boutonPlus contient l'image de "+"
  */
  sf::RectangleShape boutonPlus;
  /*! \var sf::RectangleShape boutonMoins
  *  \brief Un rectangle.
  *
  *  boutonMoins contient l'image de "-"
  */
  sf::RectangleShape boutonMoins;
  /*! \var sf::RectangleShape boutonCouperSon
  *  \brief Un rectangle.
  *
  *  boutonCouperSon contient l'une des deux images du haut parleur, si le son
  *  est coupé ou non
  */
  sf::RectangleShape boutonCouperSon;
  /*! \var sf::RectangleShape titre
  *  \brief Un rectangle.
  *
  * titre contient l'image de notre titre dans la page du menu
  */
  sf::RectangleShape titre;
  /*! \var sf::RectangleShape imagePokedex
  *  \brief Un rectangle.
  *
  *  imagePokedex contient l'image du Pokedex
  */
  sf::RectangleShape imagePokedex;
  /*! \var sf::RectangleShape fondAccueil
  *  \brief Un rectangle.
  *
  *  fondAccueil contient l'image de fond du menu accueil
  */
  sf::RectangleShape fondAccueil;
  /*! \var sf::RectangleShape imageParametre
  *  \brief Un rectangle.
  *
  *  imageParametre contient l'image de l'engrenage de parametre
  */
  sf::RectangleShape imageParametre;
  /*! \var sf::RectangleShape pokeball
  *  \brief Un rectangle.
  *
  *  pokebal contient l'image de la pokeball
  */
  sf::RectangleShape pokeball;
  /*! \var sf::RectangleShape copyright
  *  \brief Un rectangle.
  *
  *  copyright contient l'image du copyright
  */
  sf::RectangleShape copyright;

  /*! \var sf::Texture textureTitre
  *  \brief une texture.
  *
  *  textureTitre est la texture du titre
  */
  sf::Texture textureTitre;
  /*! \var sf::Texture pokedex
  *  \brief une texture.
  *
  *  pokedex est la texture du pokedex
  */
  sf::Texture pokedex;
  /*! \var sf::Texture fondEcran
  *  \brief une texture.
  *
  *  fondEcran est la texture contenant l'image de fond
  */
  sf::Texture fondEcran;
  /*! \var sf::Texture engrenage
  *  \brief une texture.
  *
  *  engrenage est la texture de l'engrenage pour ouvrir les parametres
  */
  sf::Texture engrenage;
  /*! \var sf::Texture Plus
  *  \brief une texture.
  *
  *  Plus est la texture du bouton moins
  */
  sf::Texture Plus;
  /*! \var sf::Texture Moins
  *  \brief une texture.
  *
  *  Moins est la texture du bouton moins
  */
  sf::Texture Moins;
  /*! \var sf::Texture sonCoupe
  *  \brief une texture.
  *
  * sonCoupe est la texture du son s'il est coupe ou non
  */
  sf::Texture sonCoupe;
  /*! \var sf::Texture textupokeball
  *  \brief une texture.
  *
  * textupokeball est la texture de la pokeball
  */
  sf::Texture textupokeball;
  /*! \var sf::Texture copyright1
  *  \brief une texture.
  *
  * copyright1 est la texture du copyright
  */
  sf::Texture copyright1;

  /*! \var sf::Font font
  *  \brief une police d'écriture.
  *
  *  font contient une des polices d'écritures
  */
  sf::Font font;
  /*! \var sf::Font font2
  *  \brief une police d'écriture.
  *
  *  font2 contient une des polices d'écritures
  */
  sf::Font font2;
  /*! \var sf::Font font3
  *  \brief une police d'écriture.
  *
  *  font3 contient une des polices d'écritures
  */
  sf::Font font3;

  /*! \var sf::Vector2i PositionSouris
  *  \brief les coordonnées d'un point sur l'image.
  *
  *  PositionSouris a les coordonnées de la souris pour un certain point sur une
  *  certaine fenêtre
  */
  sf::Vector2i PositionSouris;
  /*! \var sf::Vector2i PositionSouris2
  *  \brief les coordonnées d'un point sur l'image.
  *
  *  PositionSouris2 a les coordonnées de la souris pour un certain point sur une
  *  certaine fenêtre
  */
  sf::Vector2i PositionSouris2;
  /*! \var sf::Vector2i PositionSouris3
  *  \brief les coordonnées d'un point sur l'image.
  *
  *  PositionSouris3 a les coordonnées de la souris pour un certain point sur une
  *  certaine fenêtre
  */
  sf::Vector2i PositionSouris3;

  /*! \var unsigned int position
  *  \brief un entier signé
  *
  *  position represente la position actuelle ou l'on se situe dans le menu
  */
  unsigned int position;
  /*! \var unsigned int dimX
  *  \brief un entier signé
  *
  *  dimX represente la taille de la longueur de la fenêtre
  */
  unsigned int dimX;
  /*! \var unsigned int dimY
  *  \brief un entier signé
  *
  *  dimY represente la largeur de la longueur de la fenêtre
  */
  unsigned int dimY;
  /*! \var unsigned int valeurSon
  *  \brief un entier signé
  *
  *  valeurSon a pour valeur celle du son
  */
  unsigned int valeurSon;

  /*! \var bool fin
  *  \brief un boléen.
  *
  *  fin a pour but de savoir s'il faut arreter le jeu ou non
  */
  bool fin;
  /*! \var bool estCoupe
  *  \brief un boléen.
  *
  *  estCoupe permet de savoir si le son est coupe ou non
  */
  bool estCoupe;
  /*! \var bool estDansFerme
  *  \brief un boléen.
  *
  *  estDansFerme permet de savoir si l'on se trouve dans la fenêtre de
  *  fermeture ou non
  */
  bool estDansFerme;

public:
  /**
  * \brief       La boucle principale de Jeu
  * \details    boucleAffichage permet de lancer le menu et possede toutes
  *             les autres fonctions permettant de jouer
  *
  */
  void boucleAffichage ();

private:
  /**
  * \brief      Initialise l'accueil
  * \details    initialisationAccueil permet d'initialiser toutes les variables
  *             permettant l'affichage de l'accueil
  *
  */
  void initialisationAccueil();
  /**
  * \brief      Dessine
  * \details    dessinerWindow permet de dessiner ce qu'il faut dessiner
  *
  */
  void dessinerWindow ();
  /**
  * \brief      Initialise le menu
  * \details    initialisationMenu permet d'initialiser toutes les variables
  *             du menu
  *
  */
  void initialisationMenu ();
  /**
  * \brief      Initialise le fond
  * \details    initialisationMenu permet d'initialiser toutes les variables
  *             du fond
  *
  */
  void initialisationFond ();
  /**
  * \brief      Le choix de l'action
  * \details    action determine selon le choix, l'action à réaliser
  *
  */
  void action ();
  /**
  * \brief      Remet un rectangle a default
  * \details    dessinerDefault permet de dessiner les rectangles non
  *             selectionne à leurs couleurs de base
  *
  */
  void dessinerDefault ();
  /**
  * \brief      Met un rectangle d'une autre couleur
  * \details    dessinerSelection permet de changer la couleur du rectangle
  *             selectionné
  *
  */
  void dessinerSelection ();
  /**
  * \brief      Lance le tutoriel
  * \details    lireTuto permet d'afficher le fichier texte contenant le tutoriel
  *
  */
  void lireTuto ();
  /**
  * \brief      Ferme le jeu
  * \details    fermeJeu ouvre une fenetre permettant de quitter le jeu ou d'y
  *             rester
  *
  */
  void fermerJeu ();
  /**
  * \brief      Clic souris
  * \details    RecupSouris permet selon le clic de la souris de lancer l'action
  *             selectionne
  *
  */
  void RecupSouris();
  /**
  * \brief      Clic souris
  * \details    SourisFerme permet selon le clic de la souris dans le fenêtre
  *             fermer jeu, de lancer l'action selectionné
  *
  */
  void SourisFerme();
  /**
  * \brief      Augmente/diminue le son
  * \details    reglerSon permet via le clic sur le bouton plus ou moins de
  *             regler la valeur du son (en faisant des moins/plus 10)
  *
  */
  void reglerSon();
  /**
  * \brief      Coupe le son
  * \details    couperSon met le son à 0 lorsqu'on clique sur le haut parleur
  *
  */
  void couperSon();

};

#endif
