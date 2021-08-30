/*! \file Combat.h
    \brief Documentation du module Combat.
    Le module Combat représente un combat entre deux joueurs, et chaque joueur
    combat avec une équipe de 6 Pokemon.
*/

#ifndef COMBAT_H
#define COMBAT_H

#include "../Personnage/Personnage.h"

/*! \class Combat Combat.h "src/Combat/Combat.h"
 *  \brief La classe gérant le combat.
 *
 * Le module Combat consiste en la gestion du combat et donc de chaque actions
 * possible durant un combat.
 */
class Combat {

private :

  /*! \var Joueur * joueur
  *  \brief Le joueur participant aux combats.
  *
  *  Joueur correspond au personnage qu'incarne l'utilisateur principale.
  */
  Joueur * joueur;
  /*! \var Adversaire * adverse
  *  \brief L'adversaire participant aux combats.
  *
  *  Adversaire peut correspondre à une IA ou bien à un 2eme Joueur jouant sur
  *  le même ordinateur.
  */
  Adversaire * adversaire;
  /*! \var int joueurGagnant
  *  \brief Indice du gagant.
  *
  *  Indice indiquant quel joueur a gagné.
  */
  int joueurGagnant;
  /*! \var unsigned int quiJoue
  *  \brief Indice du tour.
  *
  *  Indice indiquant quel joueur doit jouer.
  */
  unsigned int quiJoue;
  /*! \var Pokemon * PokePerso
  *  \brief Pokemon combattant du Joueur
  *
  *  Correspond au Pokemon du Joueur étant actuellement sur le terrain de combat.
  */
  Pokemon * PokePerso;
  /*! \var Pokemon * PokePerso
  *  \brief Pokemon combattant de l'Adversaire
  *
  *  Correspond au Pokemon de l'Adversaire étant actuellement sur le terrain de combat.
  */
  Pokemon * PokeAdversaire;

public :

  //Constructeur & Destructeur


  /**
  * \brief       Constructeur de Combat
  * \details    Construit un objet de type Combat
  */
  Combat ();

  /**
  * \brief       Constructeur de Combat
  * \details    Construit un objet de type Combat, en utilisant un Joueur et un
  *             Adversaire prédéfini
  */
  Combat (Joueur& perso, Adversaire &dress);

  /**
  * \brief       Destructeur de Combat
  * \details    Construit un objet de type Combat
  */
  ~Combat();

  //Accesseur

  /**
   * \brief Accesseur de PokePerso
   * \details Renvoie le Pokemon au combat de Joueur
   * \return Le Pokemon sur le terrain de Combat du Joueur
   */
  Pokemon getPokePerso () const;

  /**
   * \brief Accesseur de PokePerso
   * \details Renvoie le Pokemon au combat de Adversaire
   * \return Le Pokemon sur le terrain de Combat du Adversaire
   */
  Pokemon getPokeAdversaire () const;

  /**
   * \brief Accesseur/Mutateur de PokePerso
   * \details Renvoie un pointeur sur le Pokemon au combat de Joueur
   * \return Un pointeur sur le Pokemon sur le terrain de Combat du Joueur
   */
  Pokemon* getPokePersoRef ();

  /**
   * \brief Accesseur/Mutateur de PokeAdversaire
   * \details Renvoie un pointeur sur le Pokemon au combat de Adversaire
   * \return Un pointeur sur le Pokemon sur le terrain de Combat du Adversaire
   */
  Pokemon* getPokeAdversaireRef ();

  /**
   * \brief Accesseur de Joueur
   * \details Renvoie le Joueur de combat
   * \return La variable Joueur de Combat
   */
  Joueur getJoueur () const;

  /**
   * \brief Accesseur de Adversaire
   * \details Renvoie l'Adversaire de combat
   * \return La variable Adversaire de Combat
   */
  Adversaire getAdversaire () const;

  /**
   * \brief Accesseur/Mutateur de Joueur
   * \details Renvoie un pointeur sur le Joueur de combat
   * \return Un pointeur sur la variable Joueur de Combat
   */
  Joueur * getJoueurRef () ;

  /**
   * \brief Accesseur/Mutateur de Adversaire
   * \details Renvoie un pointeur sur l'Adversaire de combat
   * \return Un pointeur sur la variable Adversaire de Combat
   */
  Adversaire * getAdversaireRef () ;


  /**
  * \brief Accesseur de joueurGagnant
  * \details Renvoie l'indice du gagnant
  * \return L'indice du personnage gagnant
  */
  int getJoueurGagnant () const;


  /**
  * \brief Accesseur de quiJoue
  * \details Renvoie l'indice de celui qui joue
  * \return L'indice du personnage etant entrain de joueur
  */
  int getQuiJoue () const;

  //Mutateur

  /**
  * \brief Mutateur de quiJoue
  * \details Modifie l'indice de celui qui joue
  * \param[in] i Indice de celui qui joue
  */
  void setQuiJoue (unsigned int i);

  /**
  * \brief Mutateur de Joueur
  * \details Modifie le Joueur
  * \param[in] joueur Joueur par lequel on remplace l'actuel
  */
  void setJ1 (Joueur & joueur);

  /**
  * \brief Mutateur de Adversaire.
  * \details Modifie le Adversaire.
  * \param[in] adversaire Adversaire par lequel on remplace l'actuel.
  */
  void setJ2 (Adversaire & adversaire);

  //Autres fonctions

  /**
  * \brief Changer de Pokemon.
  * \details Permet de changer le Pokemon actuellemnt sur le terrain de Combat
  * par un autre de l'équipe du personnage, s'applique sur le personnage dont
  * l'indice quiJoue correspond.
  * \param[in] i Indice du Pokemon qu'on veut faire rentrer sur le terrain.
  */
  void changerDePokemon(unsigned int i);

  /**
  * \brief Changer le tour de Jeu.
  * \details Changer de tour de Jeu, donc du tour du J1 au J2, puis J2 au J1.
  */
  void changerQuiJoue ();

  /**
  * \brief Lance une attaque.
  * \details Lance une attaque du Pokemon du personnage correspondant à l'indice
  * quiJoue sur le Pokemon du personnage adversaire.
  * \param[in] i Indice de l'attaque utilisé.
  * \return Un indice permettant de savoir si l'attaque c'est bien effectué.
  */
  int lancerAttaque (unsigned int i);

  /**
  * \brief Utilise un Objet.
  * \details Utilise un objet du personnage correspondant à l'indice
  * quiJoue sur son Pokemon étant actuellement en combat.
  * \param[out] Pkmn Le Pokemon sur lequel l'objet est utilisé.
  * \param[in] i Indice de l'objet utilisé.
  * \return Un booléen permettant de savoir si l'objet a bien été appliqué.
  */
  bool utiliserObjet (Pokemon& Pkmn ,unsigned int i);

  /**
  * \brief Test si le combat est fini.
  * \details Renvoie un booléen dépendant de si le combat est terminé ou non.
  * \return Un booléen permettant de savoir si le combat est terminé.
  */
  bool finDeJeu ();

  /**
  * \brief Calcul de la priorité.
  * \details Si les deux personnages choissisent d'attaquer, le calcul de la
  * priorité en fonction de la vitesse de chaque Pokemon peut-être effectué.
  * \return L'indice du personnage ayant la priorité.
  */
  int calculPriorite();

  /**
  * \brief Test regression.
  */
  void testRegression();

private:
  /**
  * \brief Calcul du STAB.
  * \details Un multiplicateur est appliqué sur les dégats si l'élément de
  * l'attaque correspond à l'un des éléments du Pokemon.
  * \param[in] attackChoisi L'attaque lancé par le Pokemon.
  * \param[in] PkmnAttack Le Pokemon qui attaque.
  * \return Le multiplicateur de dégats.
  */
  float CalculSTAB (const Attaque & attackChoisi, const Pokemon & PkmnAttack);
  /**
  * \brief Calcul de l'éfficacité.
  * \details Un multiplicateur est appliqué sur les dégats en fonction de l'élément
  * de l'attaque et des éléments du Pokemon recevant l'attaque.
  * \param[in] attackChoisi L'attaque lancé par le Pokemon.
  * \param[in] PkmnDef Le Pokemon qui recoit l'attaque.
  * \return Le multiplicateur de dégats.
  */
  float CalculEfficaciteType (const Attaque & attackChoisi, const Pokemon & PkmnDef);


};

#endif
