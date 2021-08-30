#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "Combat/Combat.h"

#define DEFAULT 1
#define SELECTION 2

using namespace std;

void init_programme (){
  keypad(stdscr, TRUE);
  initscr ();
  start_color ();
  init_pair (DEFAULT,COLOR_BLACK,COLOR_WHITE);
  init_pair (SELECTION,COLOR_WHITE,COLOR_BLACK);
  curs_set (0);
  noecho ();
  bkgd (COLOR_PAIR (DEFAULT));
}

void initWindow (WINDOW*& haut,WINDOW*& bas){
  haut = subwin (stdscr,LINES - 10,COLS,0,0);
  bas = subwin (stdscr,10,COLS, LINES - 10,0);
}

void initWindowBas (WINDOW* bas,WINDOW*& basHautGauche,WINDOW*& basHautDroit,WINDOW*& basGauche,WINDOW*& basDroit){
  basHautGauche = subwin (bas,4,COLS/2 -1,LINES-9,1);
  basHautDroit = subwin (bas,4,COLS/2 -1 ,LINES-9,COLS/2);
  basGauche = subwin (bas,4,COLS/2 -1 ,LINES-5,1);
  basDroit = subwin (bas,4,COLS/2 -1 ,LINES-5,COLS/2);
}


void initWindowHaut (WINDOW*haut,WINDOW*& hautGauche,WINDOW*& hautDroit,WINDOW*& hautMilieu) {
  hautGauche=subwin(haut, LINES-12, (COLS-2)/3, 1,1);
  hautMilieu=subwin(haut, LINES-12, (COLS-2)/3+2, 1,1+(COLS-2)/3);
  hautDroit=subwin(haut, LINES-12, (COLS-2)/3, 1,2+2*(COLS-2)/3);
}

void dessinerBox (WINDOW* bas,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit){
  wclear (basHautGauche);
  wclear (basHautDroit);
  wclear (basGauche);
  wclear (basDroit);

  box(bas, ACS_VLINE, ACS_HLINE);
  box(basHautGauche, ACS_VLINE, ACS_HLINE);
  box(basHautDroit, ACS_VLINE, ACS_HLINE);
  box(basGauche, ACS_VLINE, ACS_HLINE);
  box(basDroit, ACS_VLINE, ACS_HLINE);

  wrefresh (bas);
  wrefresh (basHautGauche);
  wrefresh (basHautDroit);
  wrefresh (basGauche);
  wrefresh (basDroit);
}

void dessinerBoxHaut (WINDOW* haut,WINDOW* hautGauche,WINDOW* hautDroit,WINDOW* hautMilieu){
  wclear (hautGauche);
  wclear (hautDroit);
  wclear (hautMilieu);

  box(haut, ACS_VLINE, ACS_HLINE);
  box(hautGauche, ACS_VLINE, ACS_HLINE);
  box(hautDroit, ACS_VLINE, ACS_HLINE);
  box(hautMilieu, ACS_VLINE, ACS_HLINE);

  wrefresh (haut);
  wrefresh (hautGauche);
  wrefresh (hautDroit);
  wrefresh (hautMilieu);
}

void clearBox(WINDOW* f) {
  wclear (f);

  box(f, ACS_VLINE, ACS_HLINE);

  wrefresh(f);
}

void ecrireWindowHaut (const Combat & combat,WINDOW*hautGauche, WINDOW*hautMilieu, WINDOW*hautDroit) {
  string NomPokeJoueur=combat.getPokePerso().getNom();
  string NomPokeAdversaire=combat.getPokeAdversaire().getNom();
  unsigned int PokeJoueurPV=combat.getPokePerso().getPV();
  unsigned int PokeAdversairePV=combat.getPokeAdversaire().getPV();
  unsigned int PokeJoueurAttck=combat.getPokePerso().getAttaquePhysique();
  unsigned int PokeAdversaireAttck=combat.getPokeAdversaire().getAttaquePhysique();
  unsigned int PokeJoueurDef=combat.getPokePerso().getDefensePhysique();
  unsigned int PokeAdversaireDef=combat.getPokeAdversaire().getDefensePhysique();
  unsigned int PokeJoueurAttckSpe=combat.getPokePerso().getAttaqueSpeciale();
  unsigned int PokeAdversaireAttckSpe=combat.getPokeAdversaire().getAttaqueSpeciale();
  unsigned int PokeJoueurDefSpe=combat.getPokePerso().getDefenseSpeciale();
  unsigned int PokeAdversaireDefSpe=combat.getPokeAdversaire().getDefenseSpeciale();
  unsigned int PokeJoueurSpeed=combat.getPokePerso().getVitesse();
  unsigned int PokeAdversaireSpeed=combat.getPokeAdversaire().getVitesse();
  mvwprintw (hautGauche,1,1,NomPokeJoueur.c_str());
  mvwprintw (hautDroit,1,1,NomPokeAdversaire.c_str());
  mvwprintw (hautGauche,2,1,("PV : " + to_string(PokeJoueurPV)).c_str());
  mvwprintw (hautDroit,2,1,("PV : " + to_string(PokeAdversairePV)).c_str());
  mvwprintw (hautGauche,3,1,("Attaque : " + to_string(PokeJoueurAttck)).c_str());
  mvwprintw (hautDroit,3,1,("Attaque : " + to_string(PokeAdversaireAttck)).c_str());
  mvwprintw (hautGauche,4,1,("Defense : " + to_string(PokeJoueurDef)).c_str());
  mvwprintw (hautDroit,4,1,("Defense : " + to_string(PokeAdversaireDef)).c_str());
  mvwprintw (hautGauche,5,1,("Attaque Special : " + to_string(PokeJoueurAttckSpe)).c_str());
  mvwprintw (hautDroit,5,1,("Attaque Special : " + to_string(PokeAdversaireAttckSpe)).c_str());
  mvwprintw (hautGauche,6,1,("Defense Special : " + to_string(PokeJoueurDefSpe)).c_str());
  mvwprintw (hautDroit,6,1,("Defense Special : " + to_string(PokeAdversaireDefSpe)).c_str());
  mvwprintw (hautGauche,7,1,("Vitesse : " + to_string(PokeJoueurSpeed)).c_str());
  mvwprintw (hautDroit,7,1,("Vitesse : " + to_string(PokeAdversaireSpeed)).c_str());
  wrefresh(hautGauche);
  wrefresh(hautMilieu);
  wrefresh(hautDroit);
}

void ecrireWindow (WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit,const string& a,const string& b,const string& c,const string& d){
  mvwprintw (basHautGauche,1,1,a.c_str());
  mvwprintw (basHautDroit,1,1,b.c_str());
  mvwprintw (basGauche,1,1,c.c_str());
  mvwprintw (basDroit,1,1,d.c_str());
  wrefresh (basHautGauche);
  wrefresh (basHautDroit);
  wrefresh (basGauche);
  wrefresh (basDroit);
}

void ecrireWindowMilieuTour (const Combat & combat, WINDOW* hautMilieu) {
  clearBox(hautMilieu);
  if (combat.getQuiJoue()==0) {
    mvwprintw (hautMilieu,1,1,("Au tour de " + combat.getJoueur().getNom()).c_str());
  }
  else if (combat.getQuiJoue()==1) {
    mvwprintw (hautMilieu,1,1,("Au tour de " + combat.getAdversaire().getNom()).c_str());
  }
  wrefresh (hautMilieu);
}

void ecrireWindowMilieuAction (const Combat & combat,int ChoixMenu, int ChoixBis, WINDOW* hautMilieu) {
  clearBox(hautMilieu);
  if (combat.getQuiJoue()==0) {
    switch (ChoixMenu) {
      case 2 :
      mvwprintw (hautMilieu,1,1,(combat.getPokeAdversaire().getNom() + " lance l'attaque : ").c_str());
      mvwprintw (hautMilieu,2,1,(combat.getPokeAdversaire().getIemeAttaque(ChoixBis).getNom()).c_str());
      break;

      case 1 :
      mvwprintw (hautMilieu,1,1,(combat.getAdversaire().getNom() + " utilise l'objet : ").c_str());
      mvwprintw (hautMilieu,2,1,(combat.getAdversaire().getObjetDansSac(ChoixBis).getNomObjet()).c_str());
      break;

      case 0 :
      mvwprintw (hautMilieu,1,1,(combat.getAdversaire().getNom() + " a changé de Pokemon ").c_str());
      mvwprintw (hautMilieu,2,1,(combat.getPokeAdversaire().getNom() + " rentre sur le terrain").c_str());
      break;
    }
  }
  else if (combat.getQuiJoue()==1) {
    switch (ChoixMenu) {
      case 2 :
      mvwprintw (hautMilieu,1,1,(combat.getPokePerso().getNom() + " lance l'attaque : ").c_str());
      mvwprintw (hautMilieu,2,1,(combat.getPokePerso().getIemeAttaque(ChoixBis).getNom()).c_str());
      break;

      case 1 :
      mvwprintw (hautMilieu,1,1,(combat.getJoueur().getNom() + " utilise l'objet : ").c_str());
      mvwprintw (hautMilieu,2,1,(combat.getJoueur().getObjetDansSac(ChoixBis).getNomObjet()).c_str());
      break;

      case 0 :
      mvwprintw (hautMilieu,1,1,(combat.getJoueur().getNom() + " a changé de Pokemon ").c_str());
      mvwprintw (hautMilieu,2,1,(combat.getPokePerso().getNom() + " rentre sur le terrain").c_str());
      break;
    }
  }
  wrefresh (hautMilieu);
  sleep(1);
}

void initFenetre (const Combat & combat,WINDOW*& haut,WINDOW*& hautGauche,WINDOW*& hautDroit,WINDOW*& hautMilieu,WINDOW*& bas,WINDOW*& basHautGauche,WINDOW*& basHautDroit,WINDOW*& basGauche,WINDOW*& basDroit){
  initWindow (haut,bas);
  initWindowBas (bas,basHautGauche,basHautDroit,basGauche,basDroit);
  initWindowHaut (haut,hautGauche,hautDroit,hautMilieu);
  dessinerBox (bas,basHautGauche,basHautDroit,basGauche,basDroit);
  dessinerBoxHaut (haut,hautGauche,hautDroit,hautMilieu);
  ecrireWindow (basHautGauche,basHautDroit,basGauche,basDroit,"Attaquer","Choisir Objet","Changer Pokemon","Fuite");
  ecrireWindowHaut(combat, hautGauche, hautMilieu, hautDroit);
}

void rebootFenetre (WINDOW* bas,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit){
  dessinerBox (bas,basHautGauche,basHautDroit,basGauche,basDroit);
  ecrireWindow (basHautGauche,basHautDroit,basGauche,basDroit,"Attaquer","Choisir Objet","Changer Pokemon","Fuite");
}

void remplirWindowDefault (WINDOW* fenetre){
  wbkgd (fenetre,COLOR_PAIR (DEFAULT));
  wrefresh (fenetre);
}

void remplirWindowSelection (WINDOW* fenetre){
  wbkgd(fenetre, COLOR_PAIR(SELECTION));
  wrefresh (fenetre);
}

void selectionWINDOW (WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit,int a){
  switch (a){
    case 2: remplirWindowDefault (basHautGauche);
    break;
    case 1: remplirWindowDefault (basHautDroit);
    break;
    case 0: remplirWindowDefault (basGauche);
    break;
    case -1 : remplirWindowDefault (basDroit);
    break;
    default : wprintw (basHautGauche,"Erreur");
    wrefresh (basHautGauche);
    break;
  }
}
void dessiner(WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit,int prochainePosition){
  switch (prochainePosition){
    case 2: remplirWindowSelection(basHautGauche);
    break;
    case 1: remplirWindowSelection(basHautDroit);
    break;
    case 0: remplirWindowSelection (basGauche);
    break;
    case -1 : remplirWindowSelection (basDroit);
    break;
    default : wprintw (basHautGauche,"Erreur");
    wrefresh (basHautGauche);
    break;
  }
}

int calculProchainePosition (int position,int key){
  int prochainePosition = position;
  switch (key){
    case 66: if (prochainePosition <= 0)position = 0;
    else position = -2;
    break;
    case 67: if ((prochainePosition%2) != 0)position = 0;
      else position = -1;
    break;
    case 65: if (prochainePosition >= 1 ) position = 0;
      else position = 2;
    break;
    case 68: if ((prochainePosition%2) == 0)position = 0;
      else position = 1;
    break;
    default: position = 0;
    break;
  }
  prochainePosition += position;
  return prochainePosition;
}

void seDeplacer (int &position,int key,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit){
  int prochainePosition = calculProchainePosition (position,key);
  selectionWINDOW (basHautGauche,basHautDroit,basGauche,basDroit,position);
  dessiner(basHautGauche,basHautDroit,basGauche,basDroit,prochainePosition);
  position=prochainePosition;
}

void attaquer (Pokemon pokemon,WINDOW* bas,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit){
  dessinerBox (bas,basHautGauche,basHautDroit,basGauche,basDroit);
  ecrireWindow (basHautGauche,basHautDroit,basGauche,basDroit,pokemon.getIemeAttaque(3).getNom(),pokemon.getIemeAttaque(2).getNom(),pokemon.getIemeAttaque(1).getNom(),pokemon.getIemeAttaque(0).getNom());
}


void changerPokemon (Personnage perso,WINDOW* bas,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit){
  dessinerBox (bas,basHautGauche,basHautDroit,basGauche,basDroit);
  ecrireWindow (basHautGauche,basHautDroit,basGauche,basDroit,perso.getIemePokemon(3).getNom(),perso.getIemePokemon(2).getNom(),perso.getIemePokemon(1).getNom(),perso.getIemePokemon(0).getNom());
}

void choisirObjet (Sac sac,WINDOW* bas,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit){
  dessinerBox (bas,basHautGauche,basHautDroit,basGauche,basDroit);
  ecrireWindow (basHautGauche,basHautDroit,basGauche,basDroit,sac.getNomObjetIeme (3),sac.getNomObjetIeme (2),sac.getNomObjetIeme (1),sac.getNomObjetIeme (0));
}

int action (int position,const Combat& combat,WINDOW* bas,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit,bool& finJeu){
  switch (position) {
    case 2:
    if (combat.getQuiJoue()==0) {
      attaquer (combat.getPokePerso (),bas,basHautGauche,basHautDroit,basGauche,basDroit);
    }
    else if (combat.getQuiJoue()==1) {
      attaquer (combat.getPokeAdversaire (),bas,basHautGauche,basHautDroit,basGauche,basDroit);
    }
    return 2;
    break;
    case 0:
    if (combat.getQuiJoue()==0) {
      changerPokemon (combat.getJoueur(),bas,basHautGauche,basHautDroit,basGauche,basDroit);
    }
    else if (combat.getQuiJoue()==1) {
      changerPokemon (combat.getAdversaire(),bas,basHautGauche,basHautDroit,basGauche,basDroit);
    }
    return 0;
    break;
    case 1:
    if (combat.getQuiJoue()==0) {
      choisirObjet (combat.getJoueur().getSac(),bas,basHautGauche,basHautDroit,basGauche,basDroit);
    }
    else if (combat.getQuiJoue()==1) {
      choisirObjet (combat.getAdversaire().getSac(),bas,basHautGauche,basHautDroit,basGauche,basDroit);
    }
    return 1;
    break;
    default : finJeu = true;
      return -1;
    break;
  }
}

void testPokemonEnVie (Combat & combat,WINDOW* hautMilieu,WINDOW * bas ,WINDOW* basHautGauche,WINDOW* basHautDroit,WINDOW* basGauche,WINDOW* basDroit, WINDOW * hautGauche, WINDOW * hautDroite) {
  bool finDeJeu=false;
  int position;
  int key;
  int actionActuelle;
  int ChoixPkmn=-1;
  while (combat.getPokePerso().getPV()==0 || combat.getPokeAdversaire().getPV()==0) {
    actionActuelle=-2;
    position=0;
    if (combat.getPokePerso().getPV()==0) {
      clearBox(hautMilieu);
      mvwprintw (hautMilieu,1,1,(combat.getPokePerso().getNom() + " est KO ").c_str());
      mvwprintw (hautMilieu,2,1,"Veuillez sélectionner un Pokemon");
      wrefresh(hautMilieu);
      combat.setQuiJoue(0);
      actionActuelle=action(position, combat, bas, basHautGauche, basHautDroit, basGauche, basDroit, finDeJeu);
      do {
        key = getch();
        seDeplacer (position,key,basHautGauche,basHautDroit,basGauche,basDroit);
        if (key == 10 && actionActuelle!=1){
          ChoixPkmn=position+1;
        }
      }
      while (ChoixPkmn==-1);
    }
    else if (combat.getPokeAdversaire().getPV()==0) {
      clearBox(hautMilieu);
      mvwprintw (hautMilieu,1,1,(combat.getPokeAdversaire().getNom() + " est KO ").c_str());
      mvwprintw (hautMilieu,2,1,"Veuillez sélectionner un Pokemon");
      wrefresh(hautMilieu);
      combat.setQuiJoue(1);
      actionActuelle=action(position, combat, bas, basHautGauche, basHautDroit, basGauche, basDroit, finDeJeu);
      do {
        key = getch();
        seDeplacer (position,key,basHautGauche,basHautDroit,basGauche,basDroit);
        if (key == 10 && actionActuelle!=5){
          ChoixPkmn=position+1;
        }
      }
      while (ChoixPkmn==-1);
    }
    combat.changerDePokemon(ChoixPkmn);
    if (combat.getQuiJoue()==0) {
      clearBox(hautMilieu);
      mvwprintw (hautMilieu,1,1,(combat.getPokeAdversaire().getNom() + " rentre sur le terrain ").c_str());
      wrefresh(hautMilieu);
    }
    else if (combat.getQuiJoue()==1) {
      clearBox(hautMilieu);
      mvwprintw (hautMilieu,1,1,(combat.getPokePerso().getNom() + " rentre sur le terrain ").c_str());
      wrefresh(hautMilieu);
    }
  rebootFenetre (bas,basHautGauche,basHautDroit,basGauche,basDroit);
  clearBox(hautGauche);
  clearBox(hautDroite);
  ecrireWindowHaut(combat,hautGauche,hautMilieu,hautDroite);
  }

}


int main(int argc, char const *argv[]) {
  srand(time(NULL));
  Joueur Corentin;
  Corentin.setNom("Corentin");
  Adversaire Lucas;
  Lucas.setNom("Lucas");
  Pokemon Salameche("Salameche", 200, 174, 218, 229, 306, 999, 0, -1);
  Attaque Flammeche("Flamméche", feu, 99, 120, 100, speciale);
  Salameche.setIemeAttaque(Flammeche,0);
  Pokemon Bulbizarre("Bulbizarre",  200, 174, 218, 229, 306, 999, 0, -1);
  Attaque FouetLiane("Fouet Liane", plante, 99, 120, 100, speciale);
  Bulbizarre.setIemeAttaque(FouetLiane,0);
  Corentin.setIemePokemon(Salameche,0);
  Lucas.setIemePokemon(Bulbizarre,0);
  bool finJeu (false);
  int actionActuelle=5;
  int ChoixMenuJoueur;
  int ChoixMenuAdversaire;
  int ChoixBisJoueur;
  int ChoixBisAdversaire;
  int *ChoixMenu;
  int *ChoixBis;
  int finTour=0;
  Pokemon * PkmnActuel;
  Combat combat(Corentin,Lucas);
  init_programme ();
  WINDOW *haut,*hautGauche,*hautDroite,*hautMilieu,*bas,*basHautGauche,*basHautDroit,*basGauche,*basDroit;
  initFenetre (combat,haut,hautGauche,hautDroite,hautMilieu,bas,basHautGauche,basHautDroit,basGauche,basDroit);
  int key,position (2);
  remplirWindowSelection (basHautGauche);
  wrefresh(basHautGauche);
  do {
      testPokemonEnVie(combat, hautMilieu, bas , basHautGauche, basHautDroit, basGauche, basDroit, hautGauche,haut);
      ecrireWindowMilieuTour(combat,hautMilieu);
      if (combat.getQuiJoue()==0) {
        ChoixBis=&ChoixBisJoueur;
        ChoixMenu=&ChoixMenuJoueur;
      }
      else if (combat.getQuiJoue()==1) {
        ChoixBis=&ChoixBisAdversaire;
        ChoixMenu=&ChoixMenuAdversaire;
      }
      key = getch();
      seDeplacer (position,key,basHautGauche,basHautDroit,basGauche,basDroit);
      if (key == 10 && actionActuelle==5){
        actionActuelle=action (position,combat,bas,basHautGauche,basHautDroit,basGauche,basDroit,finJeu);
        *ChoixMenu=actionActuelle;
      }
      else if (key == 10 && actionActuelle!=5){
        *ChoixBis=position+1;
        rebootFenetre (bas,basHautGauche,basHautDroit,basGauche,basDroit);
        actionActuelle=5;
        combat.changerQuiJoue();
        finTour++;
      }
      if (key == 98){
        rebootFenetre (bas,basHautGauche,basHautDroit,basGauche,basDroit);
        actionActuelle=5;
      }
      if (finTour==2) {
        finTour=0;
        rebootFenetre (bas,basHautGauche,basHautDroit,basGauche,basDroit);
        actionActuelle=5;
        if (ChoixMenuJoueur==0 || ChoixMenuJoueur==1) {
          combat.setQuiJoue(0);
          PkmnActuel=combat.getPokePersoRef();
          switch (ChoixMenuJoueur) {
            case 2: combat.lancerAttaque(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
          }
          PkmnActuel=combat.getPokeAdversaireRef();
          switch (ChoixMenuAdversaire) {
            case 2: combat.lancerAttaque(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
          }
        }
        else if (ChoixMenuAdversaire==0 || ChoixMenuAdversaire==1) {
          combat.setQuiJoue(1);
          PkmnActuel=combat.getPokeAdversaireRef();
          switch (ChoixMenuAdversaire) {
            case 2: combat.lancerAttaque(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
          }
          PkmnActuel=combat.getPokePersoRef();
          switch (ChoixMenuJoueur) {
            case 2: combat.lancerAttaque(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
          }
        }
        else if (combat.calculPriorite()==0){
          combat.setQuiJoue(0);
          PkmnActuel=combat.getPokePersoRef();
          switch (ChoixMenuJoueur) {
            case 2: combat.lancerAttaque(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
          }
          PkmnActuel=combat.getPokeAdversaireRef();
          switch (ChoixMenuAdversaire) {
            case 2: combat.lancerAttaque(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
          }
        }
        else if (combat.calculPriorite()==1) {
          combat.setQuiJoue(1);
          PkmnActuel=combat.getPokeAdversaireRef();
          switch (ChoixMenuAdversaire) {
            case 2: combat.lancerAttaque(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
          }
          PkmnActuel=combat.getPokePersoRef();
          switch (ChoixMenuJoueur) {
            case 2: combat.lancerAttaque(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
          }
        }
        else {
          combat.setQuiJoue(1);
          PkmnActuel=combat.getPokeAdversaireRef();
          switch (ChoixMenuAdversaire) {
            case 2: combat.lancerAttaque(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisAdversaire);
            ecrireWindowMilieuAction (combat, ChoixMenuAdversaire, ChoixBisAdversaire, hautMilieu);
            break;
          }
          PkmnActuel=combat.getPokePersoRef();
          switch (ChoixMenuJoueur) {
            case 2: combat.lancerAttaque(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 0: combat.changerDePokemon(ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
            case 1: combat.utiliserObjet(*PkmnActuel, ChoixBisJoueur);
            ecrireWindowMilieuAction (combat, ChoixMenuJoueur, ChoixBisJoueur, hautMilieu);
            break;
          }
        }
        finJeu=combat.finDeJeu();
        clearBox(hautGauche);
        clearBox(hautDroite);
        ecrireWindowHaut(combat,hautGauche,hautMilieu,hautDroite);
      }
    }while (key!=97 && finJeu == false);

  endwin ();


  return 0;
}
