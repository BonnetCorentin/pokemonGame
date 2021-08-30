/*! \file SFMLPokedex.h
    \brief Documentation du module SFMLPokedex.

    Le module SFMLPokedex consiste en la gestion de l'affichage du Pokedex
    repertoriant tous les Pokemons
*/
#ifndef SFMLPOKEMON_H
#define  SFMLPOKEMON_H

#include "../Pokemon/Pokemon.h"
#include <string.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "../Personnage/Personnage.h"

/*! \class SFMLPokedex SFMLPokedex.h "src/SFMLPokedex/SFMLPokedex.h"
 *  \brief La classe gérant le principale affichage graphique.
 *
 */
class SFMLPokedex{
private:

  /*! \var sf::RenderWindow  * menuWindow
  *  \brief Un pointeur sur la fenêtre du menu.
  *
  *  windowFermeture est le pointeur permettant d'accéder et de modifier la
  *  fenêtre du menu.
  */
  sf::RenderWindow *menuWindow;

  /*! \var sf::Texture retour
  *  \brief une texture.
  *
  *  retour est la texture contenant la flèche retour
  */
  sf::Texture retour;
  /*! \var sf::Texture typePokemon
  *  \brief une texture.
  *
  *  typePokemon est la texture contenant l'image du premier type du Pokémon
  */
  sf::Texture typePokemon;
  /*! \var sf::Texture typePokemon2
  *  \brief une texture.
  *
  *  typePokemon2 est la texture contenant l'image du deuxieme type du Pokémon
  */
  sf::Texture typePokemon2;

  /*! \var sf::Music music
  *  \brief Une musique.
  *
  *  music est la variable contenant la musique du Pokedex
  */
  sf::Music music;

  /*! \var sf::RectangleShape fondPrincipale
  *  \brief Un rectangle.
  *
  *  fondPrincipale correspond au rectangle de fond de la fenêtre principale
  */
  sf::RectangleShape fondPrincipale;
  /*! \var sf::RectangleShape tabPokedex
  *  \brief Un rectangle.
  *
  *  tabPokedex correspond aux rectangles qui contiennent les différents
  *  Pokémons.
  */
  sf::RectangleShape tabPokedex [151];
  /*! \var sf::RectangleShape rectangleFlecheDroite
  *  \brief Un rectangle.
  *
  *  rectangleFlecheDroite correspond au rectangle contenant la flèche de droite
  */
  sf::RectangleShape rectangleFlecheDroite;
  /*! \var sf::RectangleShape rectangleFlecheGauche
  *  \brief Un rectangle.
  *
  *  rectangleFlecheGauche correspond au rectangle contenant la flèche de gauche
  */
  sf::RectangleShape rectangleFlecheGauche;
  /*! \var sf::RectangleShape back
  *  \brief Un rectangle.
  *
  *  back correspond au rectangle contenant la fleche retour
  */
  sf::RectangleShape back;
  /*! \var sf::RectangleShape carte
  *  \brief Un rectangle.
  *
  *  carte correspond au rectangle contenant toutes les informations par rapport
  *  à un Pokemon donné
  */
  sf::RectangleShape carte;
  /*! \var sf::RectangleShape pokemonBas
  *  \brief Un rectangle.
  *
  *  pokemonBas correpond au rectangle contenant l'image du Pokémon
  */
  sf::RectangleShape pokemonBas;
  /*! \var sf::RectangleShape elementPokemon
  *  \brief Un rectangle.
  *
  *  elementPokemon correspond au rectangle contenant l'image du premier type
  *  du Pokemon
  */
  sf::RectangleShape elementPokemon;
  /*! \var sf::RectangleShape elementPokemon2
  *  \brief Un rectangle.
  *
  *  elementPokemon2 correspond au rectangle contenant l'image du deuxième type
  *  du Pokemon
  */
  sf::RectangleShape elementPokemon2;

  /*! \var sf::Text basDePage
  *  \brief Un texte.
  *
  *  basDePage est la variable contenant le numéro de page
  */
  sf::Text basDePage;
  /*! \var sf::Text flechRetour
  *  \brief Un texte.
  *
  *  flechRetour est la variable contenant le texte qui informe comment revenir
  *  en arrière
  */
  sf::Text flechRetour;
  /*! \var sf::Text pokemonChoisis
  *  \brief Un texte.
  *
  *  pokemonChoisis est la variable contenant le texte informant des Pokémons
  *  que le joueur a choisit
  */
  sf::Text pokemonChoisis;
  /*! \var sf::Text niveauAvantDebloque
  *  \brief Un texte.
  *
  *  niveauAvantDebloque est la variable contenant le niveau qu'il faut pour
  *  débloquer tel ou tel Pokémon
  */
  sf::Text niveauAvantDebloque;

  /*! \var sf::Font font
  *  \brief une police d'écriture.
  *
  *  font contient une des polices d'écritures
  */
  sf::Font font;

  /*! \var unsigned int position
  *  \brief un entier signé
  *
  *  position represente la palce à laquelle le curseur se trouve
  */
  unsigned int position;
  /*! \var unsigned int curseurDroit
  *  \brief un entier signé
  *
  *  curseurDroit représente la valeur de la position du curseur droit
  */
  unsigned int curseurDroit;
  /*! \var unsigned int curseurGauche
  *  \brief un entier signé
  *
  *  curseurGauche représente la valeur de la position du curseur gauche
  */
  unsigned int curseurGauche;
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
  /*! \var unsigned int nbPokemonNiveau
  *  \brief un entier signé
  *
  *  nbPokemonNiveau représente le nombre de Pokémon par page
  */
  unsigned int nbPokemonNiveau;
  /*! \var unsigned int niveauJoueur
  *  \brief un entier signé
  *
  *  niveauJoueur contient le niveau du joueur actuel
  */
  unsigned int niveauJoueur;
  /*! \var unsigned int nbPage
  *  \brief un entier signé
  *
  *  nbPage contient le numéro de la page actuelle
  */
  unsigned int nbPage;
  /*! \var unsigned int rouge
  *  \brief un entier signé
  *
  *  rouge contient la valeur du pixel rouge
  */
  unsigned int rouge;
  /*! \var unsigned int vert
  *  \brief un entier signé
  *
  *  vert contient la valeur du pixel vert
  */
  unsigned int vert;
  /*! \var unsigned int bleu
  *  \brief un entier signé
  *
  *  bleu contient la valeur du pixel bleu
  */
  unsigned int bleu;

  /*! \var sf::string Pokedex [151]
  *  \brief Une chaîne de caractère.
  *
  *  Pokedex contient tous les noms des Pokémons
  */
  std::string Pokedex [151];

  /*! \var bool siFlecheGauche
  *  \brief un boléen.
  *
  *  siFlecheGauche permet de savoir si le curseur est sur la flèche gauche ou non
  */
  bool siFlecheGauche;
  /*! \var bool aDeuxType
  *  \brief un boléen.
  *
  *  aDeuxType permet de savoir si le Pokémon a deux types
  */
  bool aDeuxType;
  /*! \var bool fin
  *  \brief un boléen.
  *
  *  fin a pour but de savoir s'il faut sortir du Pokédex ou non
  */
  bool fin;



public:
  /**
  * \brief      Constructeur de SFMLPokedex
  * \details    Construit un objet de type SFMLCombat en utilisant une fenêtre
  *             déjà crée
  * \param[out] fenetre         correspond à la
  *           fenêtre que SFMLPokedex utilisera comme fenêtre de jeu.
  *
  */
  SFMLPokedex (sf::RenderWindow& fenetre);
  /**
  * \brief      La boucle principale du Pokedex
  * \details    boucleAffichage permet de lancer le Pokédex et possede toutes
  *             les autres fonctions permettant de se déplacer dedans
  *
  */
  void boucleAffichage ();
  /**
  * \brief      La boucle principale du Pokedex avec joueur
  * \details    boucleAffichageAvecJoueur permet au joueur de choisir 6 Pokémons
  * \param[out] joueur correspond au joueur selectionné
  * \param[in]  i correpond au i-ème Pokémon
  *
  */
  void boucleAffichageAvecJoueur (Joueur& joueur,unsigned int i);
  /**
  * \brief      La fonction de chargement
  * \details    chargerIemePokemon permet de charger les 6 Pokémons selectionnés
  * \param[out] joueur correspond au joueur selectionné
  * \param[in]  i correpond au i-ème Pokémon
  *
  */
  void chargerIemePokemon (Joueur& joueur,unsigned int i)const;

private:
  /**
  * \brief      Dessiner le Pokémon
  * \details    Permet de récuperer des informations sur un Pokémon, et de
  *             dessiner ses informations à l'écran
  *
  */
  void dessinerPokemon ();
  /**
  * \brief      Dessine l'espace du bas
  * \details    Permet de dessiner tout l'espace du bas et d'harmoniser le tout
  *
  */
  void dessinerBas ();
  /**
  * \brief      Remet un rectangle a default
  * \details    dessinerDefault permet de dessiner les rectangles non
  *             selectionne à leurs couleurs de base
  *
  */
  void dessinerDefault ();
  /**
  * \brief      Lance le tutoriel
  * \details    lireTuto permet d'afficher le fichier texte contenant le tutoriel
  *
  */
  void dessinerSelection ();
  /**
  * \brief      Recupere un Pokémon
  * \details    recupererNomPokemon permet des recuperer toutes les informations
  *             sur un Pokémon et de les stocker dans ses variables
  * \param[out] text correspond au nom du pokémon
  * \param[out] type1 correspond au premier type du Pokémon
  * \param[out] type2 correspond au deuxième type du Pokémon
  * \param[out] niveauAvantDebloque correspond au niveu qu'il faut avoir pour
  *             débloquer ce Pokémon
  * \param[out] nombrePv correspond au nombre de PV du Pokémon
  *
  */
  void recupererNomPokemon (sf::Text& text,sf::Text& type1,sf::Text& type2,sf::Text& niveauAvantDebloque,sf::Text& nombrePv);
  /**
  * \brief      Recupere type d'un Pokémon
  * \details    recupererTypeString recupere le type du Pokémon en version string
  *             il ajuste également les pixels selon le type du Pokémon, et charge
  *             la texture correspond au type
  * \param[oin] Type correspond au type du Pokémon en version int
  * \param[out] t correspond à la texture à charger
  *
  */
  std::string recupererTypeString (int Type, sf::Texture &t);
  /**
  * \brief      Change de page
  * \details    changerPage permet de changer de page quand la touche "Entrée"
  *             est enfoncée
  *
  */
  void changerPage ();
  /**
  * \brief      Change de page
  * \details    ChangerPageSouris permet de changer de page lorsque l'utilisateur
  *             clique sur l'une des deux flèches
  *
  */
  void ChangerPageSouris();

};

#endif
