#include "SFMLCharger.h"
#include "../SFMLPokedex/SFMLPokedex.h"

/**
* @file SFMLCharger.cpp
* @brief Fichier d'implémentation de la classe SFMLCharger.cpp
*/

SFMLCharger::SFMLCharger (sf::RenderWindow& window){

  font.loadFromFile("data/Fonts/Splatch.ttf");

  fenetrePrincipale = &window;
  dimX=sf::VideoMode::getDesktopMode().width;
  dimY=sf::VideoMode::getDesktopMode().height;

  fenetrePrincipale->close ();
  fenetrePrincipale->create (sf::VideoMode (dimX,dimY),"PokePeip");
  dimX=fenetrePrincipale->getSize().x;
  dimY=fenetrePrincipale->getSize().y;

  rectangleFond.setSize (sf::Vector2f (dimX,dimY));
  fondchoixcombat.loadFromFile("data/Graphique/Fondchoixmodecombat1.png");
  rectangleFond.setTexture(&fondchoixcombat);
  rectangleFond.setPosition (0,0);

  ancienJoueur.setSize (sf::Vector2f (dimX/2,dimY/10));
  ancienJoueur.setOutlineColor (sf::Color (255, 255, 255));
  ancienJoueur.setFillColor(sf::Color(255, 255, 255,0));
  ancienJoueur.setOutlineThickness (5.f);
  ancienJoueur.setPosition (dimX/2 - ancienJoueur.getLocalBounds().width/2, dimY/3 - ancienJoueur.getLocalBounds().height/2 );

  jouer2V2.setSize (sf::Vector2f (dimX/2,dimY/10));
  jouer2V2.setOutlineColor (sf::Color (255, 255, 255));
  jouer2V2.setFillColor(sf::Color(255, 255, 255,0));
  jouer2V2.setOutlineThickness (5.f);
  jouer2V2.setPosition (dimX/2 - jouer2V2.getLocalBounds().width/2, 2*dimY/3 - dimY/10 - jouer2V2.getLocalBounds().height/2 );

  nouveauJoueur.setSize (sf::Vector2f (dimX/2,dimY/10));
  nouveauJoueur.setOutlineColor (sf::Color (255 , 255, 255));
  nouveauJoueur.setFillColor(sf::Color(255, 255, 255,0));
  nouveauJoueur.setOutlineThickness (5.f);
  nouveauJoueur.setPosition (dimX/2 - nouveauJoueur.getLocalBounds().width/2,2*dimY/3 + dimY/7 - nouveauJoueur.getLocalBounds().height/2);

  ancien.setPosition(dimX/2 - nouveauJoueur.getLocalBounds().width/2,dimY/3 - ancien.getLocalBounds().height/2);
  J2V2.setPosition(dimX/2 - nouveauJoueur.getLocalBounds().width/2,2*dimY/3 -dimY/10 - J2V2.getLocalBounds().height/2);
  nouveau.setPosition(dimX/2 - nouveauJoueur.getLocalBounds().width/2,2*dimY/3 + dimY/7 - nouveau.getLocalBounds().height/2);

  ancien.setString("JOUEUR CONTRE IA");
  J2V2.setString ("JOUEUR CONTRE JOUEUR");
  nouveau.setString("NOUVELLE PARTIE");

  ancien.setFont(font);
  J2V2.setFont (font);
  nouveau.setFont(font);

  ancien.setCharacterSize(dimY/40);
  J2V2.setCharacterSize(dimY/40);
  nouveau.setCharacterSize(dimY/40);

  ancien.setFillColor(sf::Color::White);
  J2V2.setFillColor(sf::Color::White);
  nouveau.setFillColor(sf::Color::White);

  position = 0;
  fin = false;
}
void SFMLCharger::lancerCombat (Joueur& joueur,Adversaire& adversaire){
  Combat combat (joueur,adversaire);
  SFMLCombat jeu(*fenetrePrincipale, combat);
  if (position == 0)jeu.affBoucleIA ();
  else jeu.affBoucle ();
  fin = true;
}
void SFMLCharger::ouvrirPokedex (Joueur& joueur){
  SFMLPokedex pokedex (*fenetrePrincipale);
  for (unsigned int i (0);i<6;i++){
    pokedex.boucleAffichageAvecJoueur (joueur,i);
  }
}

void SFMLCharger::chargementNouveauJoueur (Joueur &joueur){

  font3.loadFromFile("data/Fonts/roboto/Roboto-Regular.ttf");

  sf::RectangleShape rectangleNom;
  rectangleNom.setSize (sf::Vector2f (dimX/2,dimY/10));
  rectangleNom.setFillColor (sf::Color::White);
  rectangleNom.setPosition (dimX/4,dimY/2);

  bool finChargement (false);
  std::string nom;


  affichage.setCharacterSize (dimY/20);
  affichage.setFillColor (sf::Color::Black);
  affichage.setFont (font3);
  affichage.setPosition (dimX/4,dimY/2);

  sf::Text text;
  text.setFont (font);
  text.setString ("NOUVELLE SAUVEGARDE");
  text.setFillColor (sf::Color::Black);
  text.setPosition (dimX/2 - text.getLocalBounds().width/2,dimY/3);

  sf::Text rentrerNom;
  rentrerNom.setFont (font3);
  rentrerNom.setString ("Veuillez rentrer le nom de votre dresseur");
  rentrerNom.setCharacterSize(dimX/60);
  rentrerNom.setFillColor (sf::Color(0,0,0,10));
  rentrerNom.setPosition (dimX/4,dimY/2 - dimY/10);

	while (finChargement == false){
		sf::Event event;
		while (fenetrePrincipale->pollEvent (event)){
			if (event.type == sf::Event::Closed){
				finChargement = true;
			}
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::BackSpace && nom.length ()>0){
					nom = nom.substr(0, nom.size()-1);
          affichage.setString (nom);
				}
        if (event.key.code == sf::Keyboard::Return){
          joueur.setNom (nom);
          ouvrirPokedex (joueur);
          finChargement = true;
        }
			}
			if (event.type == sf::Event::TextEntered){
        if (event.text.unicode !=8){
          nom += event.text.unicode;
  				affichage.setString (nom);
        }
			}
		}
		fenetrePrincipale->clear (sf::Color::White);
    fenetrePrincipale->draw (rectangleFond);
    fenetrePrincipale->draw (rectangleNom);
    fenetrePrincipale->draw (text);
    fenetrePrincipale->draw (rentrerNom);
    fenetrePrincipale->draw (affichage);
		fenetrePrincipale->display ();
	}
  joueur.sauvegarderJoueur ();
}
void SFMLCharger::action (){
  unsigned int niveauInter;
  Joueur Corentin;
  Adversaire adversaire;
  adversaire.chargerAdversaire (Corentin.getNiveau ());
  bool finChargement (false);
  while (finChargement == false){
    sf::Event event;
    switch (position) {
      case 0:{
        if (!Corentin.chargerJoueur ()){
          chargementNouveauJoueur (Corentin);
          lancerCombat (Corentin,adversaire);
          finChargement = true;
        }
        else {
          ouvrirPokedex (Corentin);
          lancerCombat (Corentin,adversaire);
          finChargement = true;
          position = 0;
        }
      }
      break;
      case 1:
      niveauInter = Corentin.getNiveau ();
      Corentin.setNiveau (9);
      if (!Corentin.chargerJoueur ()){
        chargementNouveauJoueur (Corentin);
        lancerCombat (Corentin,adversaire);
        finChargement = true;
      }
      else {
        lancerCombat (Corentin,adversaire);
        finChargement = true;
        position = 0;
      }
      Corentin.setNiveau (niveauInter);
      break;
      case 2:
        chargementNouveauJoueur (Corentin);
        lancerCombat (Corentin,adversaire);
        finChargement = true;
      break;
      default:
      break;
    }
    while (fenetrePrincipale->pollEvent (event)){
      if (event.type == sf::Event::Closed){
        finChargement = true;
      }
      if (event.type == sf::Event::KeyPressed){
        switch (event.key.code) {
          case sf::Keyboard::Escape: finChargement = true;
          break;
          default:
          break;
        }
      }
    }
    fenetrePrincipale->clear (sf::Color::White);
    fenetrePrincipale->draw (rectangleFond);
    fenetrePrincipale->display ();
  }
}
void SFMLCharger::dessinerDefault (){
  switch (position) {
    case 0:
    ancienJoueur.setOutlineColor (sf::Color(255,255,255));
    ancienJoueur.setFillColor(sf::Color(255,255,255,0));
    ancien.setFillColor(sf::Color(255,255,255));
    break;

    case 1:
    jouer2V2.setOutlineColor (sf::Color(255,255,255));
    jouer2V2.setFillColor(sf::Color(255,255,255,0));
    J2V2.setFillColor(sf::Color(255,255,255));
    break;

    case 2:
    nouveauJoueur.setOutlineColor (sf::Color(255,255,255));
    nouveauJoueur.setFillColor(sf::Color(255,255,255,0));
    nouveau.setFillColor(sf::Color(255,255,255));
    break;

    default:
    break;
  }
}
void SFMLCharger::dessinerSelection (){
  switch (position) {
    case 0:
    ancienJoueur.setOutlineColor (sf::Color(255,255,255));
    ancienJoueur.setFillColor(sf::Color(255,255,255));
    ancien.setFillColor(sf::Color::Black);
    break;

    case 1:
    jouer2V2.setOutlineColor (sf::Color(255,255,255));
    jouer2V2.setFillColor(sf::Color(255,255,255));
    J2V2.setFillColor(sf::Color::Black);

    break;
    case 2:
    nouveauJoueur.setOutlineColor (sf::Color(255,255,255));
    nouveauJoueur.setFillColor(sf::Color(255,255,255));
    nouveau.setFillColor(sf::Color::Black);
    break;
    default:
    break;
  }
}
void SFMLCharger::boucleAffichage (){
  dessinerSelection();
  while (fin == false){
    sf::Event event;
    while (fenetrePrincipale->pollEvent (event)){
      if (event.type == sf::Event::Closed){
        fenetrePrincipale->close ();
      }
      if (event.type == sf::Event::KeyPressed){
        switch (event.key.code) {
          case sf::Keyboard::Escape: fin = true;
          break;
          case sf::Keyboard::Return:
            action ();
          break;
          case sf::Keyboard::Down: if (position == 2)position = 2;
            else {
              dessinerDefault ();
              position++;
              dessinerSelection ();
            }
          break;
          case sf::Keyboard::Up: if (position == 0)position=0;
            else {
              dessinerDefault ();
              position --;
              dessinerSelection ();
            }
          break;
          default:
          break;
        }
      }
    }
    fenetrePrincipale->clear (sf::Color::White);
    fenetrePrincipale->draw (rectangleFond);
    fenetrePrincipale->draw (nouveauJoueur);
    fenetrePrincipale->draw (jouer2V2);
    fenetrePrincipale->draw (J2V2);
    fenetrePrincipale->draw (ancienJoueur);
    fenetrePrincipale->draw (ancien);
    fenetrePrincipale->draw (nouveau);
    fenetrePrincipale->display ();
  }
}
