#include "Combat.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/**
* @file Combat.cpp
* @brief Fichier d'implémentation de la classe Combat.cpp
*/

Combat :: Combat (){
  joueurGagnant = 0;
  quiJoue = 0;
}

Combat :: Combat (Joueur & perso,Adversaire & dress) {
  joueur = &perso;
  adversaire = &dress;
  joueurGagnant = 0;
  quiJoue = 0; // 0 = PokerPerso, 1 = PokeAdversaire
  PokePerso=perso.getIemePokemonRef(0);
  PokeAdversaire=dress.getIemePokemonRef(0);

}

Combat :: ~Combat () {
  if (getJoueurGagnant () == 0 && joueur->getNiveau()!=9){
    joueur->augmenterNiveau ();
  }
}

Pokemon Combat::getPokePerso () const {
  return *PokePerso;
}

Pokemon Combat::getPokeAdversaire () const {
  return *PokeAdversaire;
}

Pokemon * Combat::getPokePersoRef () {
  return PokePerso;
}

Pokemon * Combat::getPokeAdversaireRef () {
  return PokeAdversaire;
}

int Combat::getQuiJoue () const {
  return quiJoue;
}

Joueur Combat::getJoueur() const {
  return *joueur;
}

Adversaire Combat::getAdversaire () const {
  return *adversaire;
}

Joueur * Combat::getJoueurRef() {
  return joueur;
}

Adversaire * Combat::getAdversaireRef () {
  return adversaire;
}

int Combat::getJoueurGagnant() const {
  return joueurGagnant;
}

void Combat::setQuiJoue (unsigned int i) {
  quiJoue=i;
}

void Combat::setJ1 (Joueur & Joueur1) {
  joueur=&Joueur1;
}

void Combat::setJ2 (Adversaire & Joueur2) {
  adversaire=&Joueur2;
}

int Combat::calculPriorite() {
  int priorite=-1;
  if (PokePerso->getVitesse()>PokeAdversaire->getVitesse()) {
    priorite=0;
  } else if (PokePerso->getVitesse()<PokeAdversaire->getVitesse()) {
    priorite=1;
  }
  return priorite;
}

bool Combat:: finDeJeu() {
  bool finDeJeu=1;
  for (unsigned int i(0);i<=5;i++) {
    if (!(joueur->getIemePokemon(i).getPV()==0)) {
       finDeJeu=0;
    }
  }
  if (finDeJeu==1) {
    joueurGagnant=1;
    return finDeJeu;
  }
  finDeJeu=1;
  for (unsigned int i(0);i<=5;i++) {
    if (!(adversaire->getIemePokemon(i).getPV()==0)) {
      finDeJeu=0;
    }
  }
  if (finDeJeu==1) {
    joueurGagnant=0;
    return finDeJeu;
  }
  return finDeJeu;
}

void Combat::changerDePokemon(unsigned int i) {
  Pokemon PokeTampon;
  if (quiJoue==0) {
    PokePerso=joueur->getIemePokemonRef(i);
  }
  else if (quiJoue==1) {
    PokeAdversaire=adversaire->getIemePokemonRef(i);
  }
  changerQuiJoue();
}

bool Combat::utiliserObjet(Pokemon & Pkmn,unsigned int i) {
  Objet * objUtilise;
  int TypeObjetUtilise = 0;
  if (quiJoue==0) {
    if (joueur->getObjetDansSac(i).getQuantite()==0) {
      return false;
    }
      objUtilise=joueur->getObjetDansSacRef(i);
      TypeObjetUtilise=objUtilise->getTypeObjet();
  }
  else {
    if (adversaire->getObjetDansSac(i).getQuantite()==0) {
      return false;
    }
      objUtilise=adversaire->getObjetDansSacRef(i);
      TypeObjetUtilise=objUtilise->getTypeObjet();
  }
  switch (TypeObjetUtilise) {
      case 0:
        if (Pkmn.getPV () == Pkmn.getPVMax ()){
          changerQuiJoue();
          objUtilise->baisserQuantite();
          return false;
		    }
        else Pkmn.gagneVie(20);
      break;
      case 1:
        if (Pkmn.getPV () == Pkmn.getPVMax ()){
          changerQuiJoue();
          objUtilise->baisserQuantite();
          return false;
		    }
        else Pkmn.gagneVie(60);
      break;
      case 2:
        if (Pkmn.getPV () == Pkmn.getPVMax ()){
          changerQuiJoue();
          objUtilise->baisserQuantite();
          return false;
		    }
        else Pkmn.gagneVie(120);
      break;
      case 3:
        if (Pkmn.getPV () == Pkmn.getPVMax ()){
          changerQuiJoue();
          objUtilise->baisserQuantite();
          return false;
        }
        else Pkmn.gagneVie(Pkmn.getPVMax());
      break;
      case 4:
        for (unsigned int i (0);i<3;i++){
          Pkmn.getIemeAttaque (i).setNbPP (10);
        }
      break;
      case 5:
        for (unsigned int i (0);i<=3;i++) {
          Pkmn.getIemeAttaque (i).setNbPP (Pkmn.getIemeAttaque (i).getNbPPMax ());
        }
      break;
  }
  objUtilise->baisserQuantite();
  changerQuiJoue();
  return true;
}

int Combat :: lancerAttaque(unsigned int i) {
  Attaque * attackChoisi;
  Pokemon * PkmnAttack = nullptr;
  Pokemon * PkmnDef = nullptr;
  if (quiJoue==0) {
    PkmnAttack=PokePerso;
    PkmnDef=PokeAdversaire;
  }
  else if (quiJoue==1) {
    PkmnAttack=PokeAdversaire;
    PkmnDef=PokePerso;
  }
  attackChoisi=&PkmnAttack->getIemeAttaque(i);
  if (attackChoisi->getNbPP()==0) {
    return 0;
  }
  else {
    float degats;
    float critique=1;
    float stab=CalculSTAB(*attackChoisi,*PkmnAttack);
    float efficacite=CalculEfficaciteType(*attackChoisi,*PkmnDef);
    float random=((rand()%16)+85)/100.0;
    int Attck=0;
    int Def = 0;
    float coeffMulti;
    if (attackChoisi->getPrecision()>(unsigned int)rand()%101) {
     if ((rand() % 101)<7) {
      critique=1.5;
      }
    if (attackChoisi->getTypeAttaque()==0) {
      Attck=PkmnAttack->getAttaquePhysique();
      Def=PkmnDef->getDefensePhysique();
      }
    else if (attackChoisi->getTypeAttaque()==1) {
      Attck=PkmnAttack->getAttaqueSpeciale();
      Def=PkmnDef->getDefenseSpeciale();
      }
    coeffMulti=stab*critique*efficacite*random;
    degats=((((100*0.4+2)*Attck*attackChoisi->getPuissance())/(Def*50))+2)*coeffMulti;
    unsigned int degat=(unsigned int)degats;
    PkmnDef->perdreVie(degat);
    attackChoisi->baisserNbPP();
    changerQuiJoue();
    return 1;
    }
    else {
      changerQuiJoue();
      return -1;
    }
  }
}

void Combat:: changerQuiJoue() {
  if (quiJoue==0) {
    quiJoue=1;
  }
  else if (quiJoue==1) {
    quiJoue=0;
  }
}

float Combat::CalculSTAB (const Attaque & attackChoisi, const Pokemon & PkmnAttack) {
  if (attackChoisi.getType()==(PkmnAttack.getTypeIeme(0)) || attackChoisi.getType()==(PkmnAttack.getTypeIeme(1))) {
    return 1.5;
  }
  else return 1;
}


float Combat::CalculEfficaciteType (const Attaque & attackChoisi, const Pokemon & PkmnDef) {
  float multiplicateur=1;
  Type attack=attackChoisi.getType();
  for (int i(0);i<=1;i++) {
    switch ((PkmnDef.getTypeIeme(i))) {
      case feu :
        if (attack==15 || attack==3 || attack==2 || attack==8 || attack==0) // résistant contre le feu, l'insecte, l'acier, la glace et la  plante
        {
          multiplicateur*=0.5;
        }
        else if (attack==1 || attack==14 || attack==10) // faible contre l'eau, le sol et la roche
        {
          multiplicateur*=2;
        }
        break;

      case eau:
        if (attack==0 || attack==3 || attack==8 || attack==1) // résistant contre le feu, l'eau, l'acier et la glace
        {
          multiplicateur*=0.5;
        }
        else if (attack==5 || attack==15) // faible contre l'electrik et la plante
        {
          multiplicateur*=2;
        }
        break;

      case insecte:
        if (attack==16 || attack==15 || attack==14) // résistant contre la plante, le combat et le sol
        {
          multiplicateur*=0.5;
        }
        else if (attack==0 || attack==13 || attack==10 || attack==7) // faible contre le feu, le vol, la roche et le poison
        {
          multiplicateur*=2;
        }
        break;

      case acier:
        if (attack==6 || attack==3 || attack==15 || attack==4 || attack==8 || attack==7 || attack==10 || attack==9 || attack==11 || attack==12 || attack==2) //résistant au normal, acier, plante, dragon, vol, glace, psy, roche, tenebre, insecte, et spectre
        {
          multiplicateur*=0.5;
        }
        else if (attack==16 || attack==14 || attack==0) // faible contre le feu, le sol et le combat
        {
          multiplicateur*=2;
        }
        else if (attack==13) // immunisé contre poison
         {
          multiplicateur*=0;
        }
        break;

      case dragon:
        if (attack==0 || attack==1 || attack==15 || attack==5) {
          multiplicateur*=0.5;
        }
        else if (attack==8 || attack==4) {
          multiplicateur*=2;
        }
        break;

      case electrik:
        if (attack==7 || attack==3 || attack==5) {
          multiplicateur*=0.5;
        }
        else if (attack==14) {
          multiplicateur*=2;
        }
        break;

      case normal:
        if (attack==12) {
          multiplicateur*=0;
        }
        else if (attack==16) {
          multiplicateur*=2;
        }
        break;

      case vol:
        if (attack==16 || attack==2 || attack==15) {
          multiplicateur*=0.5;
        }
        else if (attack==8 || attack==5 || attack==10) {
          multiplicateur*=2;
        }
        else if (attack==14) {
          multiplicateur*=0;
        }
        break;

      case glace:
        if (attack==8) {
          multiplicateur*=0.5;
        }
        else if (attack==0 || attack==3 || attack==10 || attack==16) {
          multiplicateur*=2;
        }
        break;

      case psy:
        if (attack==16 || attack==9) {
          multiplicateur*=0.5;
        }
        else if (attack==2) {
          multiplicateur*=2;
        }
        else if (attack==12) {
          multiplicateur*=0;
        }
        break;

      case roche:
        if (attack==6 || attack==0 || attack==13 || attack==7) {
          multiplicateur*=0.5;
        }
        else if (attack==1 || attack==15 || attack==14 || attack==16 || attack==3) {
          multiplicateur*=2;
        }
        break;

      case tenebre:
        if (attack==11 || attack==12) {
          multiplicateur*=0.5;
        }
        else if (attack==16 || attack==2) {
          multiplicateur*=2;
        }
        else if (attack==9) {
          multiplicateur*=0;
        }
        break;

      case spectre:
        if (attack==13 || attack==2) {
          multiplicateur*=0.5;
        }
        else if (attack==12) {
          multiplicateur*=2;
        }
        else if (attack==16 || attack==6) {
          multiplicateur*=0;
        }
        break;

      case poison:
        if (attack==13 || attack==15 || attack==16) {
          multiplicateur*=0.5;
        }
        else if (attack==14 || attack==9 || attack==2) {
          multiplicateur*=2;
        }
        break;

      case sol:
        if (attack==13 || attack==10) {
          multiplicateur*=0.5;
        }
        else if (attack==1 || attack==15 || attack==8) {
          multiplicateur*=2;
        }
        else if (attack==5) {
          multiplicateur*=0;
        }
        break;

      case plante:
        if (attack==1 || attack==14 || attack==15 || attack==5) {
          multiplicateur*=0.5;
        }
        else if (attack==8 || attack==0 || attack==7 || attack==2 || attack==13) {
          multiplicateur*=2;
        }
        break;

      case combat:
        if (attack==11 || attack==2 || attack==10) {
          multiplicateur*=0.5;
        }
        else if (attack==9 || attack==7) {
          multiplicateur*=2;
        }
        break;

      case pasType:
        break;
      }
   }
   return multiplicateur;
}

void Combat::testRegression() {
  /*Objet Potion25;
  Potion25.setQuantite(5);
  Potion25.setTypeObjet(Potion);
  Pokemon Corentin;
  Corentin.setNom("Pikachu");
  adversaire->setIemePokemon(Corentin,1);
  joueur->setIemePokemon(Corentin, 1);
  joueur->recevoirObjet(Potion25);
  std::cout<<"10";
  std::cout<<"------- Avant Modification -------"<<std::endl;
  std::cout<<"Stat Joueur :"<<std::endl;
  std::cout<<PokePerso->getNom()<<std::endl;
  std::cout<<PokePerso->getPV()<<std::endl;
  std::cout<<PokePerso->getIemeAttaque(0).getNbPP()<<std::endl;
  std::cout<<"Stat adversaire :"<<std::endl;
  std::cout<<PokeAdversaire->getNom()<<std::endl;
  std::cout<<PokeAdversaire->getPV()<<std::endl;
  std::cout<<PokeAdversaire->getIemeAttaque(0).getNbPP()<<std::endl;
  lancerAttaque(0);
  lancerAttaque(1);
  std::cout<<"------- Aprés 1ere Modification -------"<<std::endl;
  std::cout<<"Stat Joueur :"<<std::endl;
  std::cout<<PokePerso->getNom()<<std::endl;
  std::cout<<PokePerso->getPV()<<std::endl;
  std::cout<<PokePerso->getIemeAttaque(0).getNbPP()<<std::endl;
  std::cout<<"Stat adversaire :"<<std::endl;
  std::cout<<PokeAdversaire->getNom()<<std::endl;
  std::cout<<PokeAdversaire->getPV()<<std::endl;
  std::cout<<PokeAdversaire->getIemeAttaque(1).getNbPP()<<std::endl;
  utiliserObjet(*PokePerso, 0);
  std::cout<<"------- Aprés 2eme Modification -------"<<std::endl;
  std::cout<<"Stat Joueur :"<<std::endl;
  std::cout<<PokePerso->getNom()<<std::endl;
  std::cout<<PokePerso->getPV()<<std::endl;
  std::cout<<PokePerso->getIemeAttaque(0).getNbPP()<<std::endl;
  std::cout<<"Stat adversaire :"<<std::endl;
  std::cout<<PokeAdversaire->getNom()<<std::endl;
  std::cout<<PokeAdversaire->getPV()<<std::endl;
  std::cout<<PokeAdversaire->getIemeAttaque(1).getNbPP()<<std::endl;
  changerDePokemon(1);
  changerDePokemon(1);
  std::cout<<"------- Aprés 3eme Modification -------"<<std::endl;
  std::cout<<"Stat Joueur :"<<std::endl;
  std::cout<<PokePerso->getNom()<<std::endl;
  std::cout<<PokePerso->getPV()<<std::endl;
  std::cout<<PokePerso->getIemeAttaque(0).getNbPP()<<std::endl;
  std::cout<<"Stat adversaire :"<<std::endl;
  std::cout<<PokeAdversaire->getNom()<<std::endl;
  std::cout<<PokeAdversaire->getPV()<<std::endl;
  std::cout<<PokeAdversaire->getIemeAttaque(1).getNbPP()<<std::endl;*/
}
