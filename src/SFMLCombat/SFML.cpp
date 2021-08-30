#include "SFML.h"

/**
* @file SFML.cpp
* @brief Fichier d'implémentation de la classe SFML.cpp
*/

SFMLCombat::SFMLCombat(sf::RenderWindow & menuWindow, Combat & combatEnCours) {
  mainWindow=&menuWindow;
  combat=&combatEnCours;
}

SFMLCombat::SFMLCombat(Combat & combatEnCours) {
  combat=&combatEnCours;
}

SFMLCombat::SFMLCombat(sf::RenderWindow & menuWindow) {
  mainWindow=&menuWindow;
}

void SFMLCombat::affBoucle () {
  int ChoixMenu1=-7;
  int ChoixMenu2=-7;
  int ChoixBis1=-7;
  int ChoixBis2=-7;
  srand(time(NULL));
  initMainWindow();
  position=2;
  bool fin(false);
  while (fin==false)
  {
    if (!testPokemonEnVie()) {
      fin=true;
    }
    sf::Event event;

    while (mainWindow->pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        fin=true;
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
          if (ChoixBis1==-7) {
            ChoixMenu=&ChoixMenu1;
            ChoixBis=&ChoixBis1;
          }
          else if (ChoixBis2==-7) {
            ChoixMenu=&ChoixMenu2;
            ChoixBis=&ChoixBis2;
          }
          if (ChoixBis1==-7 || ChoixBis2 ==-7) {
            *ChoixMenu=changerMenu();
            if (*ChoixMenu!=-7) {
              combat->changerQuiJoue();
            }
            if (*ChoixMenu==-8) {
              fin=true;
            }
          }
          if (ChoixBis1!=-7 && ChoixBis2 !=-7){
            affCombat(ChoixMenu1,ChoixBis1,ChoixMenu2,ChoixBis2);
            position=2;
          }
        }
        if (event.key.code == sf::Keyboard::Left) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Right) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Up) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Down) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::A) {
          fin=true;
        }
      }
    }
    mainWindow->clear();
    initFightWindow();
    initMenuWindow();
    selectionMenu();
    ecrireMenu();
    affPokemon();
    affBarreDeVie();
    affTour();
    mainWindow->display();
  }
}

//GERE L'AFFICHAGE DU MENU ATTAQUE

Combat * SFMLCombat::getCombatRef() {
  return combat;
}

bool SFMLCombat::testPokemonEnVie() {
  if (combat->getPokePersoRef()->getPV()==0) {
    if (!combat->finDeJeu()) {
    combat->setQuiJoue(0);
    affChangerPokemon();
    combat->setQuiJoue(0);
    return true;
    }
    else {
    affGagnant();
    return false;
    }
  }
  if (combat->getPokeAdversaireRef()->getPV()==0) {
    if (!combat->finDeJeu()) {
    combat->setQuiJoue(1);
    affChangerPokemon();
    combat->setQuiJoue(0);
    return true;
    }
    else {
    affGagnant();
    return false;
    }
  }
  return true;
}

int SFMLCombat::pokemonKO() {
  if (combat->getPokePersoRef()->getPV()==0) {
    return 0;
  }
  else if (combat->getPokeAdversaireRef()->getPV()==0) {
    return 1;
  }
  return -1;
}


void SFMLCombat::affGagnant() {

  bool fin=false;
  sf::Event event;
  while (fin==false) {
    while (mainWindow->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        mainWindow->close();
        fin=true;
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::B) {

        }
        if (event.key.code == sf::Keyboard::Return) {
          fin=true;
          mainWindow->close();
        }
        if (event.key.code == sf::Keyboard::Q) {
          fin=true;
        }
      }
    }
  mainWindow->clear();
  dessinerGagnant();
  mainWindow->display();

  }
}

void SFMLCombat::dessinerGagnant() {


  sf::RectangleShape fondNoir(sf::Vector2f(dimX,dimY));
  fondNoir.setFillColor(sf::Color::Black);
  fondNoir.setPosition(0,0);

  Personnage * joueurWin;

  sf::Text nomGagnant;
  nomGagnant.setFont(font);
  nomGagnant.setCharacterSize(dimY/30);
  nomGagnant.setFillColor(sf::Color(255,215,0));

  sf::Text textSorti;
  textSorti.setFont(font);
  textSorti.setCharacterSize(dimY/30);
  textSorti.setFillColor(sf::Color::White);
  textSorti.setPosition(dimX/2-(textSorti.getLocalBounds().width)/2, dimY-dimY/6-textSorti.getLocalBounds().height);
  textSorti.setString("Appuyez sur Q pour quitter");

  if (combat->getJoueurGagnant()==0) {
    nomGagnant.setString(combat->getJoueurRef()->getNom()+ " a WIN");
    joueurWin=combat->getJoueurRef();

  }
  else if (combat->getJoueurGagnant()==1) {
    nomGagnant.setString(combat->getAdversaireRef()->getNom()+ " a WIN");
    joueurWin=combat->getAdversaireRef();
  }
  nomGagnant.setPosition(dimX/2-(nomGagnant.getLocalBounds().width)/2, dimY/5);

  sf::Texture Pkmn;

  sf::RectangleShape PkmnRect(sf::Vector2f(dimX/6,dimY/7));
  PkmnRect.setOutlineThickness(dimY/300);
  PkmnRect.setOutlineColor(sf::Color(255,215,0));

  mainWindow->draw(fondNoir);

  for (unsigned int i(0);i<=5;i++) {
    Pkmn.loadFromFile("data/Sprite/Front/"+joueurWin->getIemePokemonRef(i)->getNom()+".png");
    PkmnRect.setTexture(&Pkmn);
    if (i<=2) {
    PkmnRect.setPosition((i+1)*dimX/8+i*dimX/6+1,nomGagnant.getPosition().y+nomGagnant.getLocalBounds().height+dimY/8 );
    }
    else {
    PkmnRect.setPosition((i-2)*dimX/8+(i-3)*dimX/6+1,nomGagnant.getPosition().y+nomGagnant.getLocalBounds().height+PkmnRect.getSize().y+2*dimY/8 );
    }
    mainWindow->draw(PkmnRect);
  }

  mainWindow->draw(textSorti);
  mainWindow->draw(nomGagnant);


}

void SFMLCombat::affAttaque() {
  bool fin(false);
  sf::Event event;
  while (fin==false) {
    while (mainWindow->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        mainWindow->close();
        fin=true;
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
          *ChoixBis=position+1;
          fin=true;
        }
        if (event.key.code == sf::Keyboard::B) {
          fin=true;
        }
        if (event.key.code == sf::Keyboard::Left) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Right) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Up) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Down) {
          seDeplacer(event);
        }
      }
    }
  mainWindow->clear();
  initFightWindow();
  initMenuWindow();
  selectionMenu();
  ecrireAttaque();
  affPokemon();
  affBarreDeVie ();
  mainWindow->display();

  }
}

//GERER AFFICHAGE OBJET

void SFMLCombat::affObjet () {
  bool fin(false);
  sf::Event event;
  sf::RectangleShape objetRectangle(sf::Vector2f(dimX,dimY-dimY/3));
  sf::RectangleShape basNoir(sf::Vector2f(dimX,dimY/3+2*dimY/30));
  int positionObjet=1;
  basNoir.setPosition(0,2*dimY/3-dimY/30);
  objetRectangle.setFillColor(sf::Color(0,0,0,200));
  basNoir.setFillColor(sf::Color::Black);
  while (fin==false) {
    while (mainWindow->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        mainWindow->close();
        fin=true;
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
          if (positionObjet>10) {
            positionObjet=positionObjet-8;
            *ChoixBis=positionObjet;
          }
          else {
            positionObjet=positionObjet-1;
            *ChoixBis=positionObjet;
          }
          fin=true;
        }
        if (event.key.code == sf::Keyboard::B) {
          fin=true;
        }
        if (event.key.code == sf::Keyboard::Left) {
          seDeplacerObjet(event, positionObjet);
        }
        if (event.key.code == sf::Keyboard::Right) {
          seDeplacerObjet(event, positionObjet);
        }
        if (event.key.code == sf::Keyboard::Up) {
          seDeplacerObjet(event, positionObjet);
        }
        if (event.key.code == sf::Keyboard::Down) {
          seDeplacerObjet(event, positionObjet);
        }
      }
    }
    mainWindow->clear();
    initFightWindow();
    initMenuWindow();
    selectionMenu();
    affPokemon();
    affBarreDeVie ();
    mainWindow->draw(objetRectangle);
    mainWindow->draw(basNoir);
    dessinerObjet();
    dessinerSelectionObjet(positionObjet);
    mainWindow->display();
  }
}

void SFMLCombat::dessinerSelectionObjet (int positionObjet) {
  sf::RectangleShape selection(sf::Vector2f(dimX/12, dimY/6));
  selection.setOutlineColor(sf::Color::Blue);
  selection.setOutlineThickness(8.f);
  selection.setFillColor(sf::Color::Transparent);
  int positionBis;
  if (positionObjet < 10) {
    selection.setPosition((positionObjet)*dimX/8+(positionObjet-1)*dimX/6, 1*dimY/9+1*dimY/12-dimY/15);
  }
  else if (positionObjet > 10 ){
    positionBis=positionObjet-8;
    selection.setPosition((positionBis-2)*dimX/8+(positionBis-3)*dimX/6, 2*dimY/9+2*dimY/12-dimY/15);
  }
  mainWindow->draw(selection);
}

int SFMLCombat::calculProchainePositionObjet (sf::Event event, int positionObjet){
  int prochainePosition = positionObjet;
  switch (event.key.code){
    case sf::Keyboard::Down : if (prochainePosition > 10) {}
    else prochainePosition =prochainePosition + 10;
    break;
    case sf::Keyboard::Right : if (prochainePosition == 3 || prochainePosition==13) {}
    else prochainePosition = prochainePosition + 1;
    break;
    case sf::Keyboard::Up : if (prochainePosition < 10 ) {}
    else prochainePosition = prochainePosition - 10;
    break;
    case sf::Keyboard::Left : if (prochainePosition == 1 || prochainePosition==11) {}
    else prochainePosition = prochainePosition - 1;
    break;
    default: prochainePosition=0;
    break;
  }
  return prochainePosition;
}

void SFMLCombat::seDeplacerObjet (sf::Event event, int & positionObjet) {
  int prochainePosition = calculProchainePositionObjet(event, positionObjet);
  if (prochainePosition!=positionObjet) {
    positionObjet=prochainePosition;
  }
}

void SFMLCombat::dessinerObjet() {
  sf::RectangleShape caseObjet(sf::Vector2f(dimX/12, dimY/6));
  sf::RectangleShape caseImage(sf::Vector2f(dimX/11, dimY/7));

  caseObjet.setFillColor(sf::Color::White);
  caseObjet.setOutlineColor(sf::Color::Red);
  caseObjet.setOutlineThickness(3.f);
  Sac * SacEnCours;

  sf::Texture spriteObjet;

  sf::Text text;
  sf::Text quantite;

  text.setFont(font);
  text.setCharacterSize(dimY/70);
  text.setFillColor(sf::Color::Black);

  quantite.setFont(font);
  quantite.setCharacterSize(dimY/70);
  quantite.setFillColor(sf::Color::Black);

  if (combat->getQuiJoue()==0) {
    SacEnCours=combat->getJoueurRef()->getSacRef();
  }
  else if (combat->getQuiJoue()==1) {
    SacEnCours=combat->getAdversaireRef()->getSacRef();
  }

  for (unsigned int j(0);j<=5;j++) {
  spriteObjet.loadFromFile("data/Sprite/Items/"+SacEnCours->getIemeObjetRef(j)->getNomObjet()+".png");
  if (j>=3) {
    caseObjet.setPosition((j-2)*dimX/8+(j-3)*dimX/6, 2*dimY/9+2*dimY/12-dimY/15);

    text.setPosition((j-2)*dimX/8+(j-3)*dimX/6+1, 2*dimY/9+2*dimY/12+dimY/60-dimY/15);
    text.setString(SacEnCours->getIemeObjetRef(j)->getNomObjet());

    quantite.setString("x"+std::to_string(SacEnCours->getIemeObjetRef(j)->getQuantite()));
    quantite.setPosition((j-2)*dimX/8+(j-3)*dimX/6+1, 2*dimY/9+2*dimY/12+dimY/60-dimY/15+text.getLocalBounds().height+dimY/60);

    caseImage.setTexture(&spriteObjet);

    caseImage.setPosition((j-2)*dimX/8+(j-3)*dimX/6, 2*dimY/9+2*dimY/12-dimY/15+dimY/60);
  }
  else {
    caseObjet.setPosition((j+1)*dimX/8+j*dimX/6, 1*dimY/9+1*dimY/12-dimY/15);

    text.setPosition((j+1)*dimX/8+j*dimX/6+1, 1*dimY/9+1*dimY/12-dimY/15+dimY/60);
    text.setString(SacEnCours->getIemeObjetRef(j)->getNomObjet());

    quantite.setString("x"+std::to_string(SacEnCours->getIemeObjetRef(j)->getQuantite()));
    quantite.setPosition((j+1)*dimX/8+j*dimX/6+1, 1*dimY/9+1*dimY/12-dimY/15+dimY/60+text.getLocalBounds().height+dimY/60);

    caseImage.setTexture(&spriteObjet);

    caseImage.setPosition((j+1)*dimX/8+j*dimX/6+1, 1*dimY/9+1*dimY/12-dimY/15+dimY/60);
  }
    text.setString(SacEnCours->getIemeObjetRef(j)->getNomObjet());
    mainWindow->draw(caseObjet);
    mainWindow->draw(caseImage);
    mainWindow->draw(text);
    mainWindow->draw(quantite);
  }
}

//GERER LE MENU CHANGEMENT DE POKEMON

void SFMLCombat::affChangerPokemon () {
  bool fin(false);
  sf::Event event;
  sf::RectangleShape PokemonRectangle(sf::Vector2f(dimX,dimY-dimY/3));
  sf::RectangleShape basNoir(sf::Vector2f(dimX,dimY/3+2*dimY/30));
  int positionPokemon=1;
  int quiJoue=combat->getQuiJoue();
  basNoir.setPosition(0,2*dimY/3-dimY/30);
  PokemonRectangle.setFillColor(sf::Color(0,0,0,200));
  basNoir.setFillColor(sf::Color::Black);
  while (fin==false) {
    while (mainWindow->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        mainWindow->close();
        fin=true;
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
          if (pokemonKO()!=-1) {
            if (quiJoue==0 && pokemonKO()==0 && combat->getJoueurRef()->getIemePokemonRef((positionPokemon<10)? positionPokemon-1 : positionPokemon-8)->getPV()==0) {
              *ChoixBis=positionPokemon;
            }
            else if (quiJoue==1 && pokemonKO()==1 && combat->getAdversaireRef()->getIemePokemonRef((positionPokemon<10)? positionPokemon-1 : positionPokemon-8)->getPV()==0) {
              *ChoixBis=positionPokemon;
            }
            else if (quiJoue==pokemonKO()) {
              *ChoixBis=positionPokemon;
              *ChoixBis=*ChoixBis-1;
              if (*ChoixBis < 10) {
                combat->changerDePokemon(*ChoixBis);
              }
              else if (*ChoixBis >= 10 ) {
                *ChoixBis=*ChoixBis-7;
                combat->changerDePokemon(*ChoixBis);
              }
              *ChoixBis=-7;
              fin=true;
            }
          }
          else {
            if (quiJoue==0 && combat->getJoueurRef()->getIemePokemonRef((positionPokemon<10)? positionPokemon-1 : positionPokemon-8)->getPV()==0) {
              *ChoixBis=positionPokemon;
            }
            else if (quiJoue==1 && combat->getAdversaireRef()->getIemePokemonRef((positionPokemon<10)? positionPokemon-1 : positionPokemon-8)->getPV()==0) {
              *ChoixBis=positionPokemon;
            }
            else {
            *ChoixBis=positionPokemon;
            if (*ChoixBis>10) {
              *ChoixBis=*ChoixBis-8;
            }
            else {
              *ChoixBis=*ChoixBis-1;
            }
            fin=true;
            }
          }
        }
        if (event.key.code == sf::Keyboard::B) {
          if (quiJoue==1 && pokemonKO()==1) {
            fin=false;
          }
          else if (quiJoue==0 && pokemonKO()==0) {
            fin=false;
          }
          else {
            fin=true;
          }
        }
        if (event.key.code == sf::Keyboard::Left) {
          seDeplacerPokemon(event, positionPokemon);
        }
        if (event.key.code == sf::Keyboard::Right) {
          seDeplacerPokemon(event, positionPokemon);
        }
        if (event.key.code == sf::Keyboard::Up) {
          seDeplacerPokemon(event, positionPokemon);
        }
        if (event.key.code == sf::Keyboard::Down) {
          seDeplacerPokemon(event, positionPokemon);
        }
      }
    }
    if (fin!=true) {
    mainWindow->clear();
    initFightWindow();
    initMenuWindow();
    selectionMenu();
    affPokemon();
    affBarreDeVie ();
    mainWindow->draw(PokemonRectangle);
    mainWindow->draw(basNoir);
    dessinerPokemon();
    dessinerSelectionPokemon(positionPokemon);
    mainWindow->display();
    }
  }
}

void SFMLCombat::dessinerSelectionPokemon (int positionPokemon) {
  sf::RectangleShape selection(sf::Vector2f(dimX/6, dimY/6));
  selection.setOutlineColor(sf::Color::Blue);
  selection.setOutlineThickness(8.f);
  selection.setFillColor(sf::Color::Transparent);
  int positionBis;
  if (positionPokemon < 10) {
    selection.setPosition((positionPokemon)*dimX/8+(positionPokemon-1)*dimX/6, 1*dimY/9+1*dimY/12-dimY/15);
  }
  else if (positionPokemon > 10 ){
    positionBis=positionPokemon-8;
    selection.setPosition((positionBis-2)*dimX/8+(positionBis-3)*dimX/6, 2*dimY/9+2*dimY/12-dimY/15);
  }
  mainWindow->draw(selection);
}

int SFMLCombat::calculProchainePositionPokemon (sf::Event event, int positionPokemon){
  int prochainePosition = positionPokemon;
  switch (event.key.code){
    case sf::Keyboard::Down : if (prochainePosition > 10) {}
    else prochainePosition =prochainePosition + 10;
    break;
    case sf::Keyboard::Right : if (prochainePosition == 3 || prochainePosition==13) {}
    else prochainePosition = prochainePosition + 1;
    break;
    case sf::Keyboard::Up : if (prochainePosition < 10 ) {}
    else prochainePosition = prochainePosition - 10;
    break;
    case sf::Keyboard::Left : if (prochainePosition == 1 || prochainePosition==11) {}
    else prochainePosition = prochainePosition - 1;
    break;
    default: prochainePosition=0;
    break;
  }
  return prochainePosition;
}

void SFMLCombat::seDeplacerPokemon (sf::Event event, int & positionPokemon) {
  int prochainePosition = calculProchainePositionPokemon(event, positionPokemon);
  if (prochainePosition!=positionPokemon) {
    positionPokemon=prochainePosition;
  }
}

void SFMLCombat::dessinerPokemon() {
  sf::RectangleShape casePokemon(sf::Vector2f(dimX/6, dimY/6));
  sf::RectangleShape caseImage(sf::Vector2f(dimX/6, dimY/7));

  casePokemon.setFillColor(sf::Color::White);
  casePokemon.setOutlineColor(sf::Color::Red);
  casePokemon.setOutlineThickness(3.f);

  Personnage * PersoEnCours;

  sf::Texture spritePokemon;
  sf::Text text;
  sf::Text hp;

  hp.setFont(font);
  hp.setCharacterSize(dimY/70);
  hp.setFillColor(sf::Color::Black);

  text.setFont(font);
  text.setCharacterSize(dimY/70);
  text.setFillColor(sf::Color::Black);

  if (combat->getQuiJoue()==0) {
    PersoEnCours=combat->getJoueurRef();
  }
  else if (combat->getQuiJoue()==1) {
    PersoEnCours=combat->getAdversaireRef();
  }

  for (unsigned int j(0);j<=5;j++) {

  spritePokemon.loadFromFile("data/Sprite/Front/"+PersoEnCours->getIemePokemonRef(j)->getNom()+".png");

  if (j>=3) {
    casePokemon.setPosition((j-2)*dimX/8+(j-3)*dimX/6, 2*dimY/9+2*dimY/12-dimY/15);

    text.setPosition((j-2)*dimX/8+(j-3)*dimX/6+1, 2*dimY/9+2*dimY/12+dimY/60-dimY/15);
    text.setString(PersoEnCours->getIemePokemonRef(j)->getNom());

    hp.setPosition((j-2)*dimX/8+(j-3)*dimX/6+1, 2*dimY/9+2*dimY/12+dimY/60-dimY/15+text.getLocalBounds().height+dimY/60);
    hp.setString(std::to_string(PersoEnCours->getIemePokemonRef(j)->getPV())+"/"+std::to_string(PersoEnCours->getIemePokemonRef(j)->getPVMax()));

    caseImage.setTexture(&spritePokemon);
    caseImage.setPosition((j-2)*dimX/8+(j-3)*dimX/6, 2*dimY/9+2*dimY/12-dimY/15+dimY/60);
  }
  else {
    casePokemon.setPosition((j+1)*dimX/8+j*dimX/6, 1*dimY/9+1*dimY/12-dimY/15);

    text.setPosition((j+1)*dimX/8+j*dimX/6+1, 1*dimY/9+1*dimY/12-dimY/15+dimY/60);
    text.setString(PersoEnCours->getIemePokemonRef(j)->getNom());

    hp.setString(std::to_string(PersoEnCours->getIemePokemonRef(j)->getPV())+"/"+std::to_string(PersoEnCours->getIemePokemonRef(j)->getPVMax()));
    hp.setPosition((j+1)*dimX/8+j*dimX/6+1, 1*dimY/9+1*dimY/12-dimY/15+dimY/60+text.getLocalBounds().height+dimY/60);

    caseImage.setTexture(&spritePokemon);
    caseImage.setPosition((j+1)*dimX/8+j*dimX/6+1, 1*dimY/9+1*dimY/12-dimY/15+dimY/60);
  }
    text.setString(PersoEnCours->getIemePokemonRef(j)->getNom());
    mainWindow->draw(casePokemon);
    mainWindow->draw(caseImage);
    mainWindow->draw(text);
    mainWindow->draw(hp);
  }
}

//GERER L'AFFICHAGE DES ACTIONS SUIVI APRES LES CHOIX

void SFMLCombat::affCombat(int & ChoixMenu1,int & ChoixBis1,int & ChoixMenu2,int & ChoixBis2) {
  sf::Time time;
  time.asSeconds();

  calculPriorite(ChoixMenu1, ChoixBis1, ChoixMenu2, ChoixBis2);
  bool fin(false);
  while (fin==false)
  {
    if (combat->getQuiJoue()==0) {
      if (combat->getPokePersoRef()->getPV()==0) {
        ChoixMenu1=-7;
        ChoixBis1=-7;
      }
      else {
      ChoixMenu=&ChoixMenu1;
      ChoixBis=&ChoixBis1;
      }
    }
    else if (combat->getQuiJoue()==1) {
      if (combat->getPokeAdversaireRef()->getPV()==0) {
        ChoixMenu2=-7;
        ChoixBis2=-7;
      }
      else {
      ChoixMenu=&ChoixMenu2;
      ChoixBis=&ChoixBis2;
      }
    }
    mainWindow->clear();
    initFightWindow();
    initMenuWindow();
    afficherAction();
    affPokemon();
    affBarreDeVie();
    mainWindow->display();
    sf::sleep(sf::seconds(1));
    if (ChoixBis1==-7 && ChoixBis2==-7) {
      fin=true;
      combat->setQuiJoue(0);
    }
  }
}

void SFMLCombat::afficherAction() {
  sf::RectangleShape boiteText(sf::Vector2f(dimX,dimY/3+2*dimY/30));

  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(dimY/27);
  text.setFillColor(sf::Color::Black);
  text.setPosition(1+text.getLocalBounds().width,2*dimY/3-dimY/30+1);

  boiteText.setFillColor(sf::Color::White);
  boiteText.setOutlineThickness(dimY/200);
  boiteText.setOutlineColor(sf::Color::Black);
  boiteText.setPosition(0,2*dimY/3-dimY/30);

  Pokemon * pkmn=nullptr;
  Personnage * joueur;
  std::string nomJ;
  sf::String texte;
  int echecMsg=99;

  if (combat->getQuiJoue()==0) {
    pkmn=combat->getPokePersoRef();
    joueur=combat->getJoueurRef();
    nomJ=joueur->getNom();
    boiteText.setOutlineColor(sf::Color::Blue);
  }
  else if (combat->getQuiJoue()==1) {
    pkmn=combat->getPokeAdversaireRef();
    joueur=combat->getAdversaireRef();
    nomJ=joueur->getNom();
    boiteText.setOutlineColor(sf::Color::Red);
  }

  switch ((pkmn->getPV()==0) ? -99 : *ChoixMenu) {
    case -99:
    text.setString(pkmn->getNom()+" n'a pas pu attaquer il est KO");
    break;

    case 2:
    echecMsg=combat->lancerAttaque(*ChoixBis);
    if (echecMsg==1) {
      text.setString(pkmn->getNom()+" attaque avec "+pkmn->getIemeAttaqueRef(*ChoixBis)->getNom());
    }
    else if (echecMsg==-1) {
      text.setString(pkmn->getNom()+" attaque avec "+pkmn->getIemeAttaqueRef(*ChoixBis)->getNom()+" mais l'attaque rate");
    }
    break;

    case 1:

    if (*ChoixBis < 10) {
      combat->utiliserObjet(*pkmn, *ChoixBis);
    }
    text.setString(nomJ+" utilise "+joueur->getSacRef()->getIemeObjetRef(*ChoixBis)->getNomObjet());
    break;

    case 0:
    if (*ChoixBis < 10) {
      combat->changerDePokemon(*ChoixBis);
    }
    else if (*ChoixBis >= 10 ) {
      combat->changerDePokemon(*ChoixBis);
    }
    text.setString(joueur->getIemePokemonRef(*ChoixBis)->getNom()+ " rentre sur le terrain");
    break;
    default :
    break;
  }
  mainWindow->draw(boiteText);
  mainWindow->draw(text);
  *ChoixMenu=-7;
  *ChoixBis=-7;
}

void SFMLCombat::calculPriorite (int ChoixMenu1,int ChoixBis1,int ChoixMenu2,int ChoixBis2) {
  switch (ChoixMenu1) {
    case 2:
      if (ChoixMenu2==1 || ChoixMenu2==0) {
        combat->setQuiJoue(1);
      }
      else {
        if (combat->getPokePersoRef()->getVitesse()>combat->getPokeAdversaire().getVitesse()) {
          combat->setQuiJoue(0);
        }
        else if (combat->getPokePersoRef()->getVitesse()<combat->getPokeAdversaire().getVitesse()){
          combat->setQuiJoue(1);
        }
        else {
          if (rand()%50+1<50) {
            combat->setQuiJoue(1);
          }
          else {
            combat->setQuiJoue(0);
          }
        }
      }
    break;
    case 1:
      if (ChoixMenu2==2) {
        combat->setQuiJoue(0);
      }
      else {
        if (rand()%50+1<50) {
          combat->setQuiJoue(1);
        }
        else {
          combat->setQuiJoue(0);
        }
      }
    break;
    case 0:
      if (ChoixMenu2==2) {
      combat->setQuiJoue(0);
    }
    else {
      if (rand()%50+1<50) {
        combat->setQuiJoue(1);
      }
      else {
        combat->setQuiJoue(0);
      }
    }
    default :
    break;
  }
}

// GESTION DE L'AFFICHAGE DE BASE DU COMBAT

void SFMLCombat::initMainWindow () {
  dimX=sf::VideoMode::getDesktopMode().width;
  dimY=sf::VideoMode::getDesktopMode().height;
  mainWindow->close ();
  mainWindow->create (sf::VideoMode (dimX,dimY),"PokePeip");
  dimX=mainWindow->getSize().x;
  dimY=mainWindow->getSize().y;
  mainWindow->clear(sf::Color::White);
  mainWindow->setVerticalSyncEnabled(true);
  font.loadFromFile("data/Fonts/roboto/Roboto-Regular.ttf");
  sf::Image icon;
  if (!icon.loadFromFile("data/IconApp/Pokeball.PNG")) {
    std::cout<< "Erreur de chargement de l'image";
  }
  mainWindow->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
}

void SFMLCombat::initFightWindow () {
  sf::RectangleShape fondMenu(sf::Vector2f(dimX,dimY/3+2*dimY/30));
  sf::RectangleShape fondCombat(sf::Vector2f(dimX,dimY-dimY/3+2*dimY/30));

  sf::Texture fondCombatIMG;
  if (!fondCombatIMG.loadFromFile("data/Combat/Combat.png")) {
    std::cout <<"Erreur de chargement de l'image";
  }
  fondCombat.setTexture(&fondCombatIMG);

  fondMenu.setPosition(0,2*dimY/3-dimY/30);
  fondCombat.setPosition(0,0);

  fondMenu.setOutlineColor(sf::Color(30, 144, 255));

  fondMenu.setOutlineThickness(5.f);

  fondMenu.setFillColor(sf::Color(176,196,222));

  mainWindow->draw(fondCombat);
  mainWindow->draw(fondMenu);

}

void SFMLCombat::initMenuWindow() {
  boiteAttaquer.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));
  boiteObjet.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));
  boitePokemon.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));
  boiteFuir.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));

  boiteAttaquer.setPosition(dimX/30,dimY-2*dimY/6);
  boiteObjet.setPosition(dimX/2+dimX/30,dimY-2*dimY/6);
  boitePokemon.setPosition(dimX/30,dimY-dimY/6);
  boiteFuir.setPosition(dimX/2+dimX/30,dimY-dimY/6);

  boiteAttaquer.setOutlineColor(sf::Color(30, 144, 255));
  boiteObjet.setOutlineColor(sf::Color(30, 144, 255));
  boitePokemon.setOutlineColor(sf::Color(30, 144, 255));
  boiteFuir.setOutlineColor(sf::Color(30, 144, 255));

  boiteAttaquer.setOutlineThickness(5.f);
  boiteObjet.setOutlineThickness(5.f);
  boitePokemon.setOutlineThickness(5.f);
  boiteFuir.setOutlineThickness(5.f);

  mainWindow->draw(boiteAttaquer);
  mainWindow->draw(boiteObjet);
  mainWindow->draw(boitePokemon);
  mainWindow->draw(boiteFuir);
}

void SFMLCombat::affPokemon () {
  int dimXPkmnJ2=dimX/7+dimX/28;
  int dimYPkmnJ2=dimY/4;
  int dimXPkmnJ1=dimXPkmnJ2*1.2;
  int dimYPkmnJ1=dimYPkmnJ2*1.2;
  int posXJ1=dimX/5-dimX/28;
  int posXJ2=3*dimX/5+dimX/28;
  int posYJ1=dimY/3-dimY/300;
  int posYJ2=dimY/12;

  sf::Texture spriteJ1;
  if(!spriteJ1.loadFromFile("data/Sprite/Back/"+combat->getPokePersoRef()->getNom()+".png")) {
    std::cout<<"ça a pas chargé"<<std::endl;
  };
  pkmnJ1.setTexture(&spriteJ1);

  sf::Texture spriteJ2;
  if(!spriteJ2.loadFromFile("data/Sprite/Front/"+combat->getPokeAdversaireRef()->getNom()+".png")) {
    std::cout<<"ça a pas chargé"<<std::endl;
  };
  pkmnJ2.setTexture(&spriteJ2);

  pkmnJ1.setSize(sf::Vector2f(dimXPkmnJ1,dimYPkmnJ1));
  pkmnJ2.setSize(sf::Vector2f(dimXPkmnJ2,dimYPkmnJ2));

  pkmnJ1.setPosition(posXJ1,posYJ1);
  pkmnJ2.setPosition(posXJ2,posYJ2);

  mainWindow->draw(pkmnJ1);
  mainWindow->draw(pkmnJ2);
}

void SFMLCombat::affTour() {
  sf::Text text;

  text.setFont(font);
  text.setCharacterSize(dimY/25);
  text.setFillColor(sf::Color::Black);

  if (combat->getQuiJoue()==0) {
    text.setFillColor(sf::Color::Blue);
    text.setString("Au tour du J1");
  }
  else if (combat->getQuiJoue()==1) {
    text.setFillColor(sf::Color::Red);
    text.setString("Au tour du J2");
  }
  text.setPosition(dimX-text.getLocalBounds().width-dimX/60,1);

  mainWindow->draw(text);
}

void SFMLCombat::affBarreDeVie () {
  sf::RectangleShape boiteHP(sf::Vector2f(dimX/3,dimY/14));
  sf::RectangleShape barreDeVie(sf::Vector2f(dimX/6,dimY/30));
  sf::RectangleShape fondDeVie(sf::Vector2f(dimX/6,dimY/30));

  sf::Text nomPkmn;
  sf::Text pv;

  nomPkmn.setFont(font);
  pv.setFont(font);

  fondDeVie.setFillColor(sf::Color(35,82,66));
  barreDeVie.setFillColor(sf::Color(1,193,53));

  sf::Texture spriteBoiteHP;
  spriteBoiteHP.loadFromFile("data/Combat/HP.png");
  boiteHP.setTexture(&spriteBoiteHP);

  Pokemon * PokeJ1=combat->getPokePersoRef();
  Pokemon * PokeJ2=combat->getPokeAdversaireRef();


  //POKEMON DU HAUT
  boiteHP.setPosition(dimX/40,dimY/40);
  fondDeVie.setPosition(dimX/40+fondDeVie.getSize().x-boiteHP.getSize().x/40, dimY/40+fondDeVie.getSize().y);
  barreDeVie.setPosition(dimX/40+fondDeVie.getSize().x-boiteHP.getSize().x/40, dimY/40+fondDeVie.getSize().y);

  barreDeVie.setSize(sf::Vector2f(barreDeVie.getSize().x*PokeJ2->getPV()/PokeJ2->getPVMax()-dimX/160,barreDeVie.getSize().y));

  nomPkmn.setString(PokeJ2->getNom());
  pv.setString("PV : "+std::to_string(PokeJ2->getPV())+"/"+std::to_string(PokeJ2->getPVMax()));

  nomPkmn.setCharacterSize(dimY/40);
  pv.setCharacterSize(dimY/60);

  nomPkmn.setPosition(dimX/40+dimX/60,boiteHP.getPosition().y+boiteHP.getSize().y/8);
  pv.setPosition(dimX/40+dimX/60,boiteHP.getPosition().y+boiteHP.getSize().y/2+dimY/160);

  nomPkmn.setFillColor(sf::Color::Black);
  pv.setFillColor(sf::Color::Black);

  mainWindow->draw(fondDeVie);
  mainWindow->draw(barreDeVie);
  mainWindow->draw(boiteHP);
  mainWindow->draw(pv);
  mainWindow->draw(nomPkmn);

  //POKEMON DU bas
  barreDeVie.setSize(sf::Vector2f(dimX/6,dimY/30));

  boiteHP.setPosition(dimX-dimX/40-boiteHP.getSize().x,2*dimY/3-dimY/30-dimY/40-boiteHP.getSize().y);
  fondDeVie.setPosition(dimX-dimX/40-boiteHP.getSize().x+fondDeVie.getSize().x-boiteHP.getSize().x/40, 2*dimY/3-dimY/30-dimY/40-boiteHP.getSize().y+fondDeVie.getSize().y);
  barreDeVie.setPosition(dimX-dimX/40-boiteHP.getSize().x+fondDeVie.getSize().x-boiteHP.getSize().x/40, 2*dimY/3-dimY/30-dimY/40-boiteHP.getSize().y+fondDeVie.getSize().y);

  barreDeVie.setSize(sf::Vector2f(barreDeVie.getSize().x*PokeJ1->getPV()/PokeJ1->getPVMax()-dimX/160,barreDeVie.getSize().y));

  nomPkmn.setString(PokeJ1->getNom());
  pv.setString("PV : "+std::to_string(PokeJ1->getPV())+"/"+std::to_string(PokeJ1->getPVMax()));

  nomPkmn.setCharacterSize(dimY/40);
  pv.setCharacterSize(dimY/60);

  nomPkmn.setPosition(dimX-dimX/40-boiteHP.getSize().x+dimX/60,boiteHP.getPosition().y+boiteHP.getSize().y/8);
  pv.setPosition(dimX-dimX/40-boiteHP.getSize().x+dimX/60,boiteHP.getPosition().y+boiteHP.getSize().y/2+dimY/160);

  nomPkmn.setFillColor(sf::Color::Black);
  pv.setFillColor(sf::Color::Black);

  mainWindow->draw(fondDeVie);
  mainWindow->draw(barreDeVie);
  mainWindow->draw(boiteHP);
  mainWindow->draw(pv);
  mainWindow->draw(nomPkmn);

}

void SFMLCombat::ecrireMenu () {
  boiteAttaquer.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));
  boiteObjet.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));
  boitePokemon.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));
  boiteFuir.setSize(sf::Vector2f(dimX/2-dimX/15,dimY/6-dimY/20));

  boiteAttaquer.setPosition(dimX/30,dimY-2*dimY/6);
  boiteObjet.setPosition(dimX/2+dimX/30,dimY-2*dimY/6);
  boitePokemon.setPosition(dimX/30,dimY-dimY/6);
  boiteFuir.setPosition(dimX/2+dimX/30,dimY-dimY/6);

  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(dimY/25);
  text.setFillColor(sf::Color(30, 144, 255));

  text.setString("Attaquer");
  text.setPosition(boiteAttaquer.getPosition().x+boiteAttaquer.getSize().x/2-text.getLocalBounds().width/2,boiteAttaquer.getPosition().y+boiteAttaquer.getSize().y/2-text.getLocalBounds().height/2 );
  mainWindow->draw(text);

  text.setString("Utiliser objet");
  text.setPosition(boiteObjet.getPosition().x+boiteObjet.getSize().x/2-text.getLocalBounds().width/2,boiteObjet.getPosition().y+boiteObjet.getSize().y/2-text.getLocalBounds().height/2 );
  mainWindow->draw(text);

  text.setString("Changer de Pokemon");
  text.setPosition(boitePokemon.getPosition().x+boitePokemon.getSize().x/2-text.getLocalBounds().width/2,boitePokemon.getPosition().y+boitePokemon.getSize().y/2-text.getLocalBounds().height/2 );
  mainWindow->draw(text);

  text.setString("Fuir");
  text.setPosition(boiteFuir.getPosition().x+boiteFuir.getSize().x/2-text.getLocalBounds().width/2,boiteFuir.getPosition().y+boiteFuir.getSize().y/2-text.getLocalBounds().height/2 );
  mainWindow->draw(text);

}

void SFMLCombat::ecrireAttaque () {
  sf::Text text;
  sf::Text nbPP;
  sf::Text puissance;
  sf::Text precision;

  sf::RectangleShape typeRect;
  sf::Texture typeText;

  Pokemon * Poke=nullptr;
  if (combat->getQuiJoue()==0) {
    Poke=combat->getPokePersoRef();
  }
  else if (combat->getQuiJoue()==1) {
    Poke=combat->getPokeAdversaireRef();
  }
  text.setFont(font);
  text.setCharacterSize(dimY/25);
  text.setFillColor(sf::Color(30, 144, 255));

  nbPP.setFont(font);
  nbPP.setCharacterSize(dimY/38);
  nbPP.setFillColor(sf::Color(30, 144, 255));

  puissance.setFont(font);
  puissance.setCharacterSize(dimY/38);
  puissance.setFillColor(sf::Color(30, 144, 255));

  precision.setFont(font);
  precision.setCharacterSize(dimY/38);
  precision.setFillColor(sf::Color(30, 144, 255));

  text.setString(Poke->getIemeAttaqueRef(3)->getNom());
  text.setPosition(boiteAttaquer.getPosition().x,boiteAttaquer.getPosition().y+text.getLocalBounds().height);
  mainWindow->draw(text);

  nbPP.setString(std::to_string(Poke->getIemeAttaqueRef(3)->getNbPP())+"/"+std::to_string(Poke->getIemeAttaqueRef(3)->getNbPPMax()));
  nbPP.setPosition(boiteAttaquer.getPosition().x,boiteAttaquer.getPosition().y+boiteAttaquer.getSize().y-text.getLocalBounds().height);
  mainWindow->draw(nbPP);

  puissance.setString("Puissance : "+std::to_string(Poke->getIemeAttaqueRef(3)->getPuissance()));
  puissance.setPosition(boiteAttaquer.getPosition().x+boiteAttaquer.getSize().x-puissance.getLocalBounds().width-8.f,boiteAttaquer.getPosition().y-10.f+boiteAttaquer.getSize().y-puissance.getLocalBounds().height);
  mainWindow->draw(puissance);

  precision.setString("Precision : "+std::to_string(Poke->getIemeAttaqueRef(3)->getPrecision()));
  precision.setPosition(boiteAttaquer.getPosition().x+boiteAttaquer.getSize().x-precision.getLocalBounds().width-8.f,puissance.getPosition().y-precision.getLocalBounds().height*3/2);
  mainWindow->draw(precision);

  if (Poke->getIemeAttaqueRef(3)->getType()!=-1) {
    typeText.loadFromFile("data/MiniatureType/"+std::to_string(Poke->getIemeAttaqueRef(3)->getType())+".png");
  }
  else {
    typeText.loadFromFile("data/MiniatureType/Nani.png");
  }
  typeRect.setTexture(&typeText);
  typeRect.setSize(sf::Vector2f((dimX/2-dimX/15)/10,(dimY/6-dimY/20)/7));
  typeRect.setPosition(precision.getPosition().x+precision.getLocalBounds().width/2-typeRect.getLocalBounds().width/2, precision.getPosition().y-typeRect.getSize().y*3/2);
  mainWindow->draw(typeRect);

  text.setString(Poke->getIemeAttaqueRef(2)->getNom());
  text.setPosition(boiteObjet.getPosition().x,boiteObjet.getPosition().y+text.getLocalBounds().height);
  mainWindow->draw(text);

  nbPP.setString(std::to_string(Poke->getIemeAttaqueRef(2)->getNbPP())+"/"+std::to_string(Poke->getIemeAttaqueRef(2)->getNbPPMax()));
  nbPP.setPosition(boiteObjet.getPosition().x,boiteObjet.getPosition().y+boiteObjet.getSize().y-text.getLocalBounds().height);
  mainWindow->draw(nbPP);

  puissance.setString("Puissance : "+std::to_string(Poke->getIemeAttaqueRef(2)->getPuissance()));
  puissance.setPosition(boiteObjet.getPosition().x+boiteObjet.getSize().x-puissance.getLocalBounds().width-8.f,boiteObjet.getPosition().y-10.f+boiteObjet.getSize().y-puissance.getLocalBounds().height);
  mainWindow->draw(puissance);

  precision.setString("Precision : "+std::to_string(Poke->getIemeAttaqueRef(2)->getPrecision()));
  precision.setPosition(boiteObjet.getPosition().x+boiteObjet.getSize().x-precision.getLocalBounds().width-8.f,puissance.getPosition().y-precision.getLocalBounds().height*3/2);
  mainWindow->draw(precision);

  if (Poke->getIemeAttaqueRef(2)->getType()!=-1) {
    typeText.loadFromFile("data/MiniatureType/"+std::to_string(Poke->getIemeAttaqueRef(2)->getType())+".png");
  }
  else {
    typeText.loadFromFile("data/MiniatureType/Nani.png");
  }
  typeRect.setTexture(&typeText);
  typeRect.setSize(sf::Vector2f((dimX/2-dimX/15)/10,(dimY/6-dimY/20)/7));
  typeRect.setPosition(precision.getPosition().x+precision.getLocalBounds().width/2-typeRect.getLocalBounds().width/2, precision.getPosition().y-typeRect.getSize().y*3/2);
  mainWindow->draw(typeRect);


  text.setString(Poke->getIemeAttaqueRef(1)->getNom());
  text.setPosition(boitePokemon.getPosition().x,boitePokemon.getPosition().y+text.getLocalBounds().height);
  mainWindow->draw(text);

  nbPP.setString(std::to_string(Poke->getIemeAttaqueRef(1)->getNbPP())+"/"+std::to_string(Poke->getIemeAttaqueRef(1)->getNbPPMax()));
  nbPP.setPosition(boitePokemon.getPosition().x,boitePokemon.getPosition().y+boitePokemon.getSize().y-text.getLocalBounds().height);
  mainWindow->draw(nbPP);

  puissance.setString("Puissance : "+std::to_string(Poke->getIemeAttaqueRef(1)->getPuissance()));
  puissance.setPosition(boitePokemon.getPosition().x+boitePokemon.getSize().x-puissance.getLocalBounds().width-8.f,boitePokemon.getPosition().y-10.f+boitePokemon.getSize().y-puissance.getLocalBounds().height);
  mainWindow->draw(puissance);

  precision.setString("Precision : "+std::to_string(Poke->getIemeAttaqueRef(1)->getPrecision()));
  precision.setPosition(boitePokemon.getPosition().x+boitePokemon.getSize().x-precision.getLocalBounds().width-8.f,puissance.getPosition().y-precision.getLocalBounds().height*3/2);
  mainWindow->draw(precision);

  if (Poke->getIemeAttaqueRef(1)->getType()!=-1) {
    typeText.loadFromFile("data/MiniatureType/"+std::to_string(Poke->getIemeAttaqueRef(1)->getType())+".png");
  }
  else {
    typeText.loadFromFile("data/MiniatureType/Nani.png");
  }
  typeRect.setTexture(&typeText);
  typeRect.setSize(sf::Vector2f((dimX/2-dimX/15)/10,(dimY/6-dimY/20)/7));
  typeRect.setPosition(precision.getPosition().x+precision.getLocalBounds().width/2-typeRect.getLocalBounds().width/2, precision.getPosition().y-typeRect.getSize().y*3/2);
  mainWindow->draw(typeRect);


  text.setString(Poke->getIemeAttaqueRef(0)->getNom());
  text.setPosition(boiteFuir.getPosition().x,boiteFuir.getPosition().y+text.getLocalBounds().height);
  mainWindow->draw(text);

  nbPP.setString(std::to_string(Poke->getIemeAttaqueRef(0)->getNbPP())+"/"+std::to_string(Poke->getIemeAttaqueRef(0)->getNbPPMax()));
  nbPP.setPosition(boiteFuir.getPosition().x,boiteFuir.getPosition().y+boiteFuir.getSize().y-text.getLocalBounds().height);
  mainWindow->draw(nbPP);

  puissance.setString("Puissance : "+std::to_string(Poke->getIemeAttaqueRef(0)->getPuissance()));
  puissance.setPosition(boiteFuir.getPosition().x+boiteFuir.getSize().x-puissance.getLocalBounds().width-8.f,boiteFuir.getPosition().y-10.f+boiteFuir.getSize().y-puissance.getLocalBounds().height);
  mainWindow->draw(puissance);

  precision.setString("Precision : "+std::to_string(Poke->getIemeAttaqueRef(0)->getPrecision()));
  precision.setPosition(boiteFuir.getPosition().x+boiteFuir.getSize().x-precision.getLocalBounds().width-8.f,puissance.getPosition().y-precision.getLocalBounds().height*3/2);
  mainWindow->draw(precision);

  if (Poke->getIemeAttaqueRef(0)->getType()!=-1) {
    typeText.loadFromFile("data/MiniatureType/"+std::to_string(Poke->getIemeAttaqueRef(0)->getType())+".png");
  }
  else {
    typeText.loadFromFile("data/MiniatureType/Nani.png");
  }
  typeRect.setTexture(&typeText);
  typeRect.setSize(sf::Vector2f((dimX/2-dimX/15)/10,(dimY/6-dimY/20)/7));
  typeRect.setPosition(precision.getPosition().x+precision.getLocalBounds().width/2-typeRect.getLocalBounds().width/2, precision.getPosition().y-typeRect.getSize().y*3/2);
  mainWindow->draw(typeRect);


}

void SFMLCombat::selectionMenu() {
  switch (position){
    case 2:
      boiteAttaquer.setOutlineColor(sf::Color(25, 25, 112));
      boiteAttaquer.setOutlineThickness(8.f);
      mainWindow->draw(boiteAttaquer);
    break;
    case 1:
      boiteObjet.setOutlineColor(sf::Color(25, 25, 112));
      boiteObjet.setOutlineThickness(8.f);
      mainWindow->draw(boiteObjet);
    break;
    case 0:
      boitePokemon.setOutlineColor(sf::Color(25, 25, 112));
      boitePokemon.setOutlineThickness(8.f);
      mainWindow->draw(boitePokemon);
    break;
    case -1 :
      boiteFuir.setOutlineColor(sf::Color(25, 25, 112));
      boiteFuir.setOutlineThickness(8.f);
      mainWindow->draw(boiteFuir);
    break;
    default :
    break;
  }
}

void SFMLCombat::seDeplacer (sf::Event event){
  int prochainePosition = calculProchainePosition(event);
  if (prochainePosition!=position) {
    position=prochainePosition;
  }
}

int SFMLCombat::changerMenu () {
  switch (position){
    case 2:
      affAttaque();
      if (!mainWindow->isOpen()) {
        return -8;
      }
      if (*ChoixBis!=-7) {
        return 2;
      }
      else {
        return -7;
      }
    break;
    case 1:
      affObjet();
      if (!mainWindow->isOpen()) {
        return -8;
      }
      if (*ChoixBis!=-7) {
        return 1;
      }
      else {
        return -7;
      }
    break;
    case 0:
      affChangerPokemon();
      if (!mainWindow->isOpen()) {
        return -8;
      }
      if (*ChoixBis!=-7) {
        return 0;
      }
      else {
        return -7;
      }
    break;
    case -1 :
      return -8;
    break;
    default :
      return -7;
    break;
  }
}

int SFMLCombat::calculProchainePosition (sf::Event event){
  int prochainePosition = position;
  switch (event.key.code){
    case sf::Keyboard::Down : if (prochainePosition <= 0) position = 0;
    else prochainePosition += -2;
    break;
    case sf::Keyboard::Right : if ((prochainePosition%2) != 0) position = 0;
    else prochainePosition += -1;
    break;
    case sf::Keyboard::Up : if (prochainePosition >= 1 ) position = 0;
    else prochainePosition += 2;
    break;
    case sf::Keyboard::Left : if ((prochainePosition%2) == 0) position = 0;
    else prochainePosition += 1;
    break;
    default: prochainePosition=0;
    break;
  }
  return prochainePosition;
}

//PARTIE IA

bool SFMLCombat::testPokemonEnVieIA() {
  if (combat->getPokePersoRef()->getPV()==0) {
    if (!combat->finDeJeu()) {
    combat->setQuiJoue(0);
    affChangerPokemon();
    combat->setQuiJoue(0);
    return true;
    }
    else {
    affGagnant();
    return false;
    }
  }
  if (combat->getPokeAdversaireRef()->getPV()==0) {
    if (!combat->finDeJeu()) {
    combat->setQuiJoue(1);
    combat->changerDePokemon(choixPokemon());
    combat->setQuiJoue(0);
    return true;
    }
    else {
    affGagnant();
    return false;
    }
  }
  return true;
}

void SFMLCombat::affBoucleIA () {
  int ChoixMenu1=-7;
  int ChoixMenu2=-7;
  int ChoixBis1=-7;
  int ChoixBis2=-7;
  srand(time(NULL));
  initMainWindow();
  position=2;
  bool fin(false);
  while (fin==false)
  {
    if (!testPokemonEnVieIA()) {
      fin=true;
    }
    sf::Event event;

    while (mainWindow->pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        fin=true;
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
          if (ChoixBis1==-7) {
            ChoixMenu=&ChoixMenu1;
            ChoixBis=&ChoixBis1;

          }
          if (ChoixBis1==-7 || ChoixBis2 ==-7) {
            *ChoixMenu=changerMenu();
            if (*ChoixMenu!=-7) {
              combat->changerQuiJoue();
              choixMenu(ChoixMenu2, ChoixBis2);
            }
            if (*ChoixMenu==-8) {
              fin=true;
            }
          }
          if (ChoixBis1!=-7 && ChoixBis2 !=-7){
            affCombat(ChoixMenu1,ChoixBis1,ChoixMenu2,ChoixBis2);
            position=2;
          }
        }
        if (event.key.code == sf::Keyboard::Left) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Right) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Up) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::Down) {
          seDeplacer(event);
        }
        if (event.key.code == sf::Keyboard::A) {
          fin=true;
        }
      }
    }
    mainWindow->clear();
    initFightWindow();
    initMenuWindow();
    selectionMenu();
    ecrireMenu();
    affPokemon();
    affBarreDeVie();
    affTour();
    mainWindow->display();
  }
}

void SFMLCombat::choixMenu(int & ChoixMenu2, int & ChoixBis2) {
  bool Attaque=chanceAttaquer();
  bool Objet=chanceObjet();
  bool Pokemon=chancePokemon();
  if (Objet==true) {
    ChoixMenu2=1;
    ChoixBis2=choixObjet();
    if (ChoixBis2==-7) {
      ChoixMenu2=2;
      ChoixBis2=choixAttaque();
    }
    else {
      combat->changerQuiJoue();
    }
  }
  else if (Pokemon==true) {
    combat->changerQuiJoue();
    ChoixMenu2=0;
    ChoixBis2=choixPokemon();
  }
  else if (Attaque==true) {
    combat->changerQuiJoue();
    ChoixMenu2=2;
    ChoixBis2=choixAttaque();
  }
  else {
    combat->changerQuiJoue();
    ChoixMenu2=2;
    ChoixBis2=choixAttaque();
  }
}

bool SFMLCombat::chanceAttaquer() {
  Pokemon IAPkmn=combat->getPokeAdversaire();
  Pokemon JoueurPKMN=combat->getPokePerso();
  Attaque ListeAttaque[4];
  float avantageMax=0;
  float chance=0;
  if (IAPkmn.getPV()>IAPkmn.getPVMax()*0.75) {
    return true;
  }
  if (IAPkmn.getPV()<IAPkmn.getPVMax()*0.25) {
    return false;
  }
  for (unsigned int i(0);i<=3;i++) {
    chance=AvantageType(JoueurPKMN,(Type)IAPkmn.getIemeAttaque(i).getType());
    chance = 1-chance/4;
    if (chance>avantageMax) {
      avantageMax=chance;
    }
  }
  if ((rand()%100+1)/100<(chance+2/100)) {
    return true;
  }
  else {
    return false;
  }
}

bool SFMLCombat::chanceObjet() {
  Pokemon IAPkmn=combat->getPokeAdversaire();
  if ((float)IAPkmn.getPV()/(float)IAPkmn.getPVMax()<=0.25) {
    return true;
  }
  if ((float)IAPkmn.getPV()/(float)IAPkmn.getPVMax()>=0.75) {
    return false;
  }
  for (unsigned int i(0);i<=3;i++) {
    if ((float)IAPkmn.getIemeAttaque(i).getNbPP()/IAPkmn.getIemeAttaque(i).getNbPPMax()<=0.5) {
    return true;
    }
  }
  float chance=1-(float)IAPkmn.getPV()/(float)IAPkmn.getPVMax()-0.2;
  if ((float)(rand()%100+1)/100<=chance) {
    return true;
  }
  else {
    return false;
  }
}

bool SFMLCombat::chancePokemon() {
  Pokemon IAPkmn=combat->getPokeAdversaire();
  Pokemon JoueurPKMN=combat->getPokePerso();
  float chance=0;
  if (JoueurPKMN.getTypeIeme(1)!=-1) {
    chance=AvantageType(IAPkmn,(Type)JoueurPKMN.getTypeIeme(0));
    chance=chance+AvantageType(IAPkmn,(Type)JoueurPKMN.getTypeIeme(1));
    chance = 1-chance/8;
  }
  else {
    chance=AvantageType(IAPkmn,(Type)JoueurPKMN.getTypeIeme(0));
    chance = 1-chance/4;
  }
  chance = 1-chance/4;
  if ((float)(rand()%100+1)/100>(chance+2/100)) {
    return true;
  }
  else {
    return false;
  }
}

int SFMLCombat::choixAttaque() {
  Pokemon * IAPkmn=combat->getPokeAdversaireRef();
  Attaque ListeAttaque[4];
  Pokemon * JoueurPkmn=combat->getPokePersoRef();
  int indiceMax=-1;
  float avantageMax=-1;
  Type typeAttaque;
  for (unsigned i(0);i<=3;i++) {
    ListeAttaque[i]=*(IAPkmn->getIemeAttaqueRef(i));
    typeAttaque=ListeAttaque[i].getType();
    if (AvantageType(*(JoueurPkmn), typeAttaque)>avantageMax) {
      avantageMax=AvantageType(*(JoueurPkmn), typeAttaque);
      indiceMax=i;
    }
  }
  return indiceMax;
}

int SFMLCombat::choixObjet() {
  Sac sacIA;
  Pokemon PokeIA=*combat->getPokeAdversaireRef();
  sacIA=combat->getAdversaireRef()->getSac();
  if ((float)PokeIA.getPV()/(float)PokeIA.getPVMax()>=0.80 && sacIA.getIemeObjet(0).getQuantite()!=0) {
    return 0;
  }
  if ((float)PokeIA.getPV()/(float)PokeIA.getPVMax()>=0.30 && sacIA.getIemeObjet(1).getQuantite()!=0) {
    return 1;
  }
  if ((float)PokeIA.getPV()/(float)PokeIA.getPVMax()>=0.05 && sacIA.getIemeObjet(2).getQuantite()!=0) {
    return 2;
  }
  if ((float)PokeIA.getPV()/(float)PokeIA.getPVMax()<0.05 && sacIA.getIemeObjet(3).getQuantite()!=0) {
    return 3;
  }
  int sommePPManquant=0;
  for (unsigned int i(0);i<=3;i++) {
    sommePPManquant+=PokeIA.getIemeAttaque(i).getNbPPMax()-PokeIA.getIemeAttaque(i).getNbPP();
  }
  if (sommePPManquant<=20 && sommePPManquant>10 && sacIA.getIemeObjet(4).getQuantite()!=0) {
    return 4;
  }
  if (sommePPManquant>20 && sacIA.getIemeObjet(5).getQuantite()!=0) {
    return 5;
  }
  return -7;
 }

int SFMLCombat::choixPokemon() {
  Pokemon IAPkmn;
  Pokemon JoueurPKMN=combat->getPokePerso();
  Personnage IAPerso=*combat->getAdversaireRef();
  float chance=0;
  float chanceMax=0;
  int indiceMax=-1;

  for (unsigned int i(0);i<=5;i++) {
    chance=0;
    IAPkmn=*IAPerso.getIemePokemonRef(i);
    if (combat->getAdversaireRef()->getIemePokemonRef(i)!=combat->getPokeAdversaireRef() && IAPkmn.getPV()!=0) {
      if (indiceMax==-1) {
        indiceMax=i;
      }
      if (JoueurPKMN.getTypeIeme(1)!=-1) {
        chance=AvantageType(IAPkmn,(Type)JoueurPKMN.getTypeIeme(0));
        chance=chance+AvantageType(IAPkmn,(Type)JoueurPKMN.getTypeIeme(1));
        chance = 1-chance/8;
      }
      else {
        chance=AvantageType(IAPkmn,(Type)JoueurPKMN.getTypeIeme(0));
        chance = 1-chance/4;
      }
      if (chanceMax<chance) {
        chanceMax=chance;
        indiceMax=i;
      }
    }
  }
  return indiceMax;
}

float SFMLCombat::AvantageType (const Pokemon & IAPkmn, const Type & typeJoueur) {
  float multiplicateur=1;
  Type attack=typeJoueur;
  for (int i(0);i<=1;i++) {
    switch ((IAPkmn.getTypeIeme(i))) {
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

      case 16:
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
