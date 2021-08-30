/*! \file SFML.h
    \brief Documentation du module SFML.cpp

    Le module SFML consiste en la gestion de l'affichage du combat
    ainsi que la communication Homme-Machine nécéssaire durant le
    combat.
*/

#ifndef SFML_H
#define SFML_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include "../Combat/Combat.h"


/*! \class SFMLCombat SFML.h "src/SFMLCombat/SFML.h"
 *  \brief La classe gérant la partie IHM du combat.
 *
 * Le module SFML consiste en la gestion de l'affichage du combat
 * ainsi que la communication Homme-Machine nécéssaire durant le
 * combat..
 */

class SFMLCombat {

private:
  /*! \var sf::RenderWindow * mainWindow
  *  \brief Un pointeur sur la fenêtre de Jeu.
  *
  *  mainWindow est le pointeur permettant d'accéder et de modifier la
  *  fenêtre principale de jeu.
  */
  sf::RenderWindow * mainWindow;
  /*! \var sf::RectangleShape boiteAttaquer
  *  \brief Le rectangle définissant la boite "Attaquer".
  *
  *  boiteAttaquer représente les délimitations de la boite "Attaquer"
  *  dans la partie inférieure de l'affichage combat.
  */
  sf::RectangleShape boiteAttaquer;
  /*! \var sf::RectangleShape boiteObjet
  *  \brief Le rectangle définissant la boite "Utiliser objet".
  *
  *  boiteAttaquer représente les délimitations de la boite "Utiliser objet"
  *  dans la partie inférieure de l'affichage combat.
  */
  sf::RectangleShape boiteObjet;
  /*! \var sf::RectangleShape boitePokemon
  *  \brief Le rectangle définissant la boite "Changer de Pokemon".
  *
  *  boiteAttaquer représente les délimitations de la boite "Changer de Pokemon"
  *  dans la partie inférieure de l'affichage combat.
  */
  sf::RectangleShape boitePokemon;
  /*! \var sf::RectangleShape boiteFuir
  *  \brief Le rectangle définissant la boite "Fuir".
  *
  *  boiteAttaquer représente les délimitations de la boite "Fuir"
  *  dans la partie inférieure de l'affichage combat.
  */
  sf::RectangleShape boiteFuir;
  /*! \var sf::RectangleShape pkmnJ1
  *  \brief Le rectangle définissant le Pokemon du J1.
  *
  *  pkmnJ1 représente les délimitations du sprite du Pokemon du Joueur 1
  *  dans la partie supérieure de l'affichage combat.
  */
  sf::RectangleShape pkmnJ1;
  /*! \var sf::RectangleShape pkmnJ2
  *  \brief Le rectangle définissant la Pokemon du J2.
  *
  *  pkmnJ2 représente les délimitations du sprite du Pokemon du Joueur 2
  *  dans la partie supérieure de l'affichage combat.
  */
  sf::RectangleShape pkmnJ2;

  /*! \var sf::Font font
  \brief La police d'écriture utilisé pour l'affichage de texte.

    font est initialisé avec une police d'écriture fournis dans assets, qui
    est ensuite utilisé pour chaque affichage de texte.
  */
  sf::Font font;
  /*! \var unsigned int dimX
    \brief La largeur de la fenêtre de Jeu.

    dimX correspond à la taille en largeur de la fenêtre de Jeu, elle est
    adapté en fonction de la résolution de l'écran de l'Utilisateur.
  */
  unsigned int dimX;
  /*! \var unsigned int dimY
    \brief La hauteur de la fenêtre de Jeu.

    dimX correspond à la taille en largeur de la fenêtre de Jeu, elle est
    adapté en fonction de la résolution de l'écran de l'Utilisateur.
  */
  unsigned int dimY;
  /*! \var int position
    \brief La position du curseur dans les menus.

    position correspond à la position dans le menu principale ainsi que dans
    le menu de séléction d'une Attaque.
  */
  int position;
  /*! \var Combat * combat
    \brief Le combat étant actuellement géré par le module.

    combat correspond au combat ayant actuellement lieu, et qui est donc
    actuellement géré par la classe SFMLCombat.
  */
  Combat * combat;

  /*! \var int * ChoixMenu
    \brief Le pointeur sur le choix de Menu.

    ChoixMenu correspond à un pointeur nous permettant de gérer
    les choix des deux joueurs en utilisant qu'une seule et même variables.
  */
  int * ChoixMenu;
  /*! \var int * ChoixBis
    \brief Le pointeur sur le choix de Bis.

    ChoixBis correspond à un pointeur nous permettant de gérer
    les choix des deux joueurs en utilisant qu'une seule et même variables.
  */
  int * ChoixBis;

public:

  /**
  * \brief       Constructeur de SFMLCombat
  * \details    Construit un objet de type SFMLCombat en utilisant une fenêtre déjà
  *                  ouvertes et un combat déjà crée
  * \param[out]    menuWindow         correspond à la
  *           fenêtre que SFMLCombat utilisera comme fenêtre de jeu.
  * \param[out]    combatEnCours         correspond au combat
  *           que SFMLCombat doit gérér pour le jeu
  *
  */
  SFMLCombat (sf::RenderWindow & menuWindow, Combat & combatEnCours);

  /**
  * \brief       Constructeur de SFMLCombat
  * \details    Construit un objet de type SFMLCombat en utilisant un combat
  *           déjà crée
  * \param[out]    combatEnCours         correspond au combat
  *           que SFMLCombat doit gérér pour le jeu
  *
  */
  SFMLCombat (Combat & combatEnCours);

  /**
  * \brief       Constructeur de SFMLCombat
  * \details    Construit un objet de type SFMLCombat en utilisant une fenêtre déjà
  *                  ouvertes
  * \param[out]   menuWindow         correspond à la
  *           fenêtre que SFMLCombat utilisera comme fenêtre de jeu.
  *
  */
  SFMLCombat (sf::RenderWindow & menuWindow);

  /**
  * \brief       La boucle principale de Jeu
  * \details    affBoucle permet de démarrer le jeu et encapsulera toutes les
  *             autres boucles nécéssaire à l'affichage du combat
  *
  */
  void affBoucle();


    /**
    * \brief       La boucle principale de Jeu (version combat IA)
    * \details    affBoucleIA permet de démarrer le jeu et encapsulera toutes les
    *             autres boucles nécéssaire à l'affichage du combat (version combat IA)
    *
    */
  void affBoucleIA();

  private :

  /**
  * \brief       Permet de récupérer un pointeur sur combat
  * \details    Permet de récupérer un pointeur sur le combat étant actuellement
  *             géré par l'objet de classe SFMLCombat
  * \return     Un pointeur sur le combat étant actuellement géré
  */
  Combat* getCombatRef();

  /**
  * \brief       Test si une équipe Pokemon entière est KO
  * \details    Test si une équipe Pokemon entière est KO et lance l'affichage
  *             de fin de partie
  * \return     Un booléen permettant de savoir si oui ou non le combat est fini
  */
  bool testPokemonEnVie();
  /**
  * \brief       Test si un des Pokemon combattant est KO
  * \details    Test si un Pokemon est KO et enclenche le menu de changement
  *             de Pokemon
  * \return     Un booléen permettant de savoir si oui ou non un Pokemon était
  *             KO
  */
  int pokemonKO();

  /**
  * \brief       Boucle d'affichage de fin de partie
  * \details    Gére l'affichage de fin de partie
  */
  void affGagnant();
  /**
  * \brief       Dessine l'écran de fin de partie
  * \details    Dessine l'écran de fin de partie, est utilisé dans affGagnant
  */
  void dessinerGagnant();

  /**
  * \brief       Boucle d'affichage du menu attaque
  * \details    Permet de gérer le menu d'attaque, et de gérer la selection
  *             d'une attaque
  *
  */
  void affAttaque();

  /**
  * \brief       Boucle d'affichage du menu objet
  * \details    Permet de gérer le menu d'objet, et de gérer la selection
  *             d'un objet à utiliser
  *
  */
  void affObjet();
  /**
  * \brief       Dessine le curseur de sélection
  * \details    Dessine le curseur autour du cadre de l'objet étant actuellement
  *             pointé par le curseur
  * \param[in]  positionObjet Index de position de l'objet étant actuellement
  *             pointé par le curseur
  */
  void dessinerSelectionObjet (int positionObjet);
  /**
  * \brief       Calcul de la prochaine position objet
  * \details    Permet de calculer la prochaine position de l'objet en fonction
  *             de la touche directionelle préssé
  * \param[in]  positionObjet Index de position de l'objet étant actuellement
  *             pointé par le curseur
  * \param[in]  event Correspond à la touche qui est préssé par l'utilisateur
  * \return     Renvoie la future position du curseur sur objet, ou la même
  *             position que précédemment si le déplacement n'est pas autorisé
  */
  int calculProchainePositionObjet(sf::Event event, int positionObjet);
  /**
  * \brief       Modifie positionObjet
  * \details    Attribue à positionObjet la valeur retourné par
  *             calculProchainePositionObjet
  * \param[out]  positionObjet Index de position de l'objet étant actuellement
  *             pointé par le curseur
  * \param[in]  event Correspond à la touche qui est préssé par l'utilisateur
  */
  void seDeplacerObjet(sf::Event event, int & positionObjet);
  /**
  * \brief       Dessine les sprites des objets
  * \details    Desinne les sprites des objets dans leur rectangle attribué,
  *             et affiche le menu de sélection d'objet
  */
  void dessinerObjet();


  /**
  * \brief       Boucle d'affichage du menu Changer de Pokemon
  * \details    Permet de gérer le menu Pokemon, et de gérer la selection
  *             d'un Pokemon pour le changement
  *
  */
  void affChangerPokemon();
  /**
  * \brief       Dessine le curseur de sélection
  * \details    Dessine le curseur autour du cadre du Pokemon étant actuellement
  *             pointé par le curseur
  * \param[in]  positionPokemon Index de position du Pokemon étant actuellement
  *             pointé par le curseur
  */
  void dessinerSelectionPokemon (int positionPokemon);
  /**
  * \brief       Calcul de la prochaine position Pokemon
  * \details    Permet de calculer la prochaine position du cursueur sur
  *             Pokemon en fonction de la touche directionelle préssé
  * \param[in]  positionPokemon Index de position du Pokemon étant actuellement
  *             pointé par le curseur
  * \param[in]  event Correspond à la touche qui est préssé par l'utilisateur
  * \return     Renvoie la future position du curseur sur objet, ou la même
  *             position que précédemment si le déplacement n'est pas autorisé
  */
  int calculProchainePositionPokemon(sf::Event event, int positionPokemon);
  /**
  * \brief       Modifie positionPokemon
  * \details    Attribue à positionPokemon la valeur retourné par
  *             calculProchainePositionPokemon
  * \param[out]  positionPokemon Index de position du Pokemon étant actuellement
  *             pointé par le curseur
  * \param[in]  event Correspond à la touche qui est préssé par l'utilisateur
  */
  void seDeplacerPokemon(sf::Event event, int & positionPokemon);
  /**
  * \brief       Dessine les sprites des Pokemon
  * \details    Desinne les sprites des Pokemon dans leur rectangle attribué
  *             et le menu de sélection de Pokemon
  */
  void dessinerPokemon();

  /**
  * \brief       Boucle d'affichage des actions
  * \details    Permet d'afficher chaque action effectué par chaque joueur
  * \param[out] ChoixMenu1 Correspond au choix de menu du J1 (Attaquer, Changer
  *             de Pokemon ou Utiliser un Objet)
  * \param[out] ChoixBis1 Correspond au choix du J1 en fonction du menu, quelle
  * attaque, objet ou Pokemon
  * \param[out] ChoixMenu2 Correspond au choix de menu du J2 (Attaquer, Changer
  *             de Pokemon ou Utiliser un Objet)
  * \param[out] ChoixBis2 Correspond au choix du J2 en fonction du menu, quelle
  * attaque, objet ou Pokemon
  */
  void affCombat(int & ChoixMenu1,int & ChoixBis1,int & ChoixMenu2,int & ChoixBis2);
  /**
  * \brief       Affichage textuel des actions effectués
  * \details    Desinne le texte des actions effectués par chaque joueur
  */
  void afficherAction();
  /**
  * \brief       Calcul de la priorité des Joueurs
  * \details    Calcul quel joueur a la priorité sur l'autre en fonction des
  *             actions choisies ainsi que des statistiques de chaque Pokemon
  * \param[in] ChoixMenu1 Correspond au choix de menu du J1 (Attaquer, Changer
  *             de Pokemon ou Utiliser un Objet)
  * \param[in] ChoixBis1 Correspond au choix du J1 en fonction du menu, quelle
  * attaque, objet ou Pokemon
  * \param[in] ChoixMenu2 Correspond au choix de menu du J2 (Attaquer, Changer
  *             de Pokemon ou Utiliser un Objet)
  * \param[in] ChoixBis2 Correspond au choix du J2 en fonction du menu, quelle
  * attaque, objet ou Pokemon
  */
  void calculPriorite(int ChoixMenu1,int ChoixBis1,int ChoixMenu2,int ChoixBis2);

  /**
   * |brief    Initialise les paramètres de la fenêtre
   * \details Récupére la résolution de l'écran de l'utilisateur, créer la
   *          fenêtre en fonction, et stocke les valeurs de la taille de la
   *          fenêtre dans dimX et dimY
   */
  void initMainWindow();
  /**
   * |brief    Initialise la base de l'affichage du combar
   * \details  Desinne les fonds de chaque partie de l'affichage (menu et terrain
   *           de combat)
   */
  void initFightWindow();
  /**
   * |brief    Affichage des menus d'actions
   * \details Desinne le menu principale permettant la sélection des actions
   */
  void initMenuWindow();
  /**
   * |brief    Affichage des Pokemon actuellement en combat
   * \details Desinne les sprites des Pokemon de chaque Joueur étant actuellement
   *          en combat
   */
  void affPokemon();
  /**
   * |brief    Affichage du tour
   * \details Dessine un texte dans le coin supérieure droit permettant de
   *          savoir qui doit jouer
   */
  void affTour();
  /**
   * |brief    Affichage de la barre de vie
   * \details Dessine la barre de vie pour chaque Pokemon étant en combat,
   *          et gére l'évolution de la vie au cours du combat
   */
  void affBarreDeVie();
  /**
   * |brief    Affichage des noms des menus
   * \details Dessine le texte designant le nom de chaque menu des actions
   *          principale dans leur rectangle attribué
   */
  void ecrireMenu();
  /**
   * |brief    Affichage des noms des attaque
   * \details Dessine le texte designant le nom de chaque attaque
   *          possédé par le Pokemon
   */
  void ecrireAttaque();
  /**
   * |brief    Affichage du menu actuellement pointé
   * \details Dessine un curseur autour du menu étant actuellement selectionné
   *          par le joueur
   */
  void selectionMenu();
  /**
   * |brief    Gére le changement de menu
   * \details Sélectionne dans quel boucle de menu le programme doit rentrer
   *          en fonction du choix de l'utilisateur
   * \return Renvoie l'indice du menu sélectionné par le joueur
   */
  int changerMenu();
  /**
   * |brief    Changement de position du curseur
   * \details Attribue le résultat de calculProchainePosition dans position afin
   *          de déplacer le curseur en fonction de la touche directionelle
   *          préssé par l'utilisateur
   * \param[in] event Correspond à la touche directionelle préssé par l'utilisateur
   */
  void seDeplacer(sf::Event event);
  /**
   * |brief    Calcul de la prochaine position du curseur
   * \details Calcul de la prochaine position du curseur en foncton de la touche
   *          directionelle préssé par l'utilisateur ou renvoie la même position
   *          si le déplacement n'est pas autorisé
   * \param[in] event Correspond à la touche directionelle préssé par l'utilisateur
   */
  int calculProchainePosition(sf::Event event);

  //PARTIE IA

  /**
  * \brief       Test si un des Pokemon combattant est KO (version combat contre IA)
  * \details    Test si un Pokemon est KO et enclenche le menu de changement
  *             de Pokemon
  * \return     Un booléen permettant de savoir si oui ou non un Pokemon était
  *             KO
  */
  bool testPokemonEnVieIA();

  /**
  * \brief      Reflexion de l'IA sur l'action à effectuer
  * \details    Permet de calculer quel est l'action à effectuer et remplis ensuite
  *             ChoixMenu2 et ChoixBis2 des indices des actions à effectuer
  * \param[out] ChoixMenu2 Correspond au choix de menu de l'IA (Attaquer, Changer
  *             de Pokemon ou Utiliser un Objet)
  * \param[out] ChoixBis2 Correspond au choix de l'IA en fonction du menu, quelle
  * attaque, objet ou Pokemon
  */
  void choixMenu(int & ChoixMenu2, int & ChoixBis2);

  /**
  * \brief      Chance d'attaquer
  * \details    Effectue différent test afin de savoir si il faut attaquer
  * \return     Un booléen permettant de savoir si l'IA doit attaquer
  */
  bool chanceAttaquer();
  /**
  * \brief      Chance d'utiliser un objet
  * \details    Effectue différent test afin de savoir si il faut utiliser un objet
  * \return     Un booléen permettant de savoir si l'IA doit utiliser un objet
  */
  bool chanceObjet();
  /**
  * \brief      Chance de changer de Pokemon
  * \details    Effectue différent test afin de savoir si il faut utiliser un objet
  * \return     Un booléen permettant de savoir si l'IA doit utiliser un objet
  */
  bool chancePokemon();

  /**
  * \brief      Choix de l'attaque à lancer
  * \details    Effectuent différents test pour savoir quelle attaque doit-être lancer
  * \return     L'indice de l'attaque à lancer
  */
  int choixAttaque();
  /**
  * \brief      Choix de l'objet à utiliser
  * \details    Effectuent différents test pour savoir quel objet doit-être utiliser
  * \return     L'indice de l'attaque à utiliser
  */
  int choixObjet();
  /**
  * \brief      Choix du Pokemon à faire rentrer sur le terrain
  * \details    Effectuent différents test pour savoir quel pokemon doit rentrer sur le terrain
  * \return     L'indice du Pokemon à faire rentrer
  */
  int choixPokemon();

  /**
  * \brief      Calcul l'avantage d'un type par rapport aux types d'un Pokemon
  * \details    Calcul le multiplicateur de dégâts d'un type par rapport a (ou aux)
  *             type(s) d'un Pokemon en fonction de résistance et faiblesse
  *             du Pokemon
  * \return     Renvoie le multiplicateur de dégâts
  */
  float AvantageType(const Pokemon & PkmnIA, const Type & typeJoueur);
};

#endif
