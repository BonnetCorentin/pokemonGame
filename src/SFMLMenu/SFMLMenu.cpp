#include "SFMLMenu.h"
#include "../SFMLCombat/SFML.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../SFMLCharger/SFMLCharger.h"

/**
* @file SFMLMenu.cpp
* @brief Fichier d'implémentation de la classe SFMLMenu.cpp
*/

void SFMLMenu::initialisationMenu (){
  sf::Image icon;
  valeurSon = 100;
  dimX = sf::VideoMode::getDesktopMode().width;
  dimY = sf::VideoMode::getDesktopMode().height;
  menuWindow.close ();
  menuWindow.create (sf::VideoMode (dimX,dimY),"PokePeip");
  menuWindow.setVerticalSyncEnabled(true);
  if (!icon.loadFromFile("data/IconApp/Pokeball.PNG")) {
    std::cout<< "Erreur de chargement de l'image";
  }
  menuWindow.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

  dimX = menuWindow.getSize().x;
  dimY = menuWindow.getSize().y;

  if (!textureTitre.loadFromFile ("data/Titre/PokePeip.png")){
    std::cout << "erreur" << '\n';
  }
  if (!pokedex.loadFromFile("data/Graphique/Pokedex.png")){
    std::cout << "erreur" << '\n';
  }
  if (!engrenage.loadFromFile("data/Graphique/parametre.png")){
    std::cout << "erreur" << '\n';
  }

  fin = false;
  font.loadFromFile("data/Fonts/Splatch.ttf");
  font3.loadFromFile("data/Fonts/lemon_milk/LemonMilk.otf");
  position = 1;

  rectangleCombat.setSize (sf::Vector2f (dimX/2,dimY/10));
  rectangleTuto.setSize (sf::Vector2f (dimX/2,dimY/10));
  rectangleQuitter.setSize (sf::Vector2f (dimX/2,dimY/10));

  rectangleCombat.setFillColor(sf::Color(255, 255, 255));
  rectangleTuto.setFillColor (sf::Color(254 , 43, 24,0));
  rectangleQuitter.setFillColor (sf::Color(238, 43, 24,0));

  rectangleCombat.setOutlineColor(sf::Color(255, 255, 255));
  rectangleTuto.setOutlineColor(sf::Color(255, 255, 255));
  rectangleQuitter.setOutlineColor(sf::Color(255, 255, 255));

  rectangleCombat.setOutlineThickness(8.f);
  rectangleTuto.setOutlineThickness(5.f);
  rectangleQuitter.setOutlineThickness(5.f);

  rectangleCombat.setPosition (dimX/2-dimX/4,dimY/2 -dimY/4+dimY/12);
  rectangleTuto.setPosition (dimX/2-dimX/4,dimY/2 -dimY/4 + dimY/6+dimY/12);
  rectangleQuitter.setPosition (dimX/2-dimX/4,dimY/2 -dimY/4 + dimY/6 + dimY/6+dimY/12);

  combat.setString("COMBAT");
  tuto.setString("TUTO");
  quitter.setString("QUITTER");
  textePokedex.setString("APPUYER SUR P POUR OUVRIR LE POKEDEX");
  parametre.setString ("APPUYER SUR R OU CLIQUER POUR PARAMETRER LE SON");

  combat.setFont(font);
  tuto.setFont(font);
  quitter.setFont(font);
  textePokedex.setFont(font);
  parametre.setFont(font);

  combat.setCharacterSize(dimY/40);
  tuto.setCharacterSize(dimY/40);
  quitter.setCharacterSize(dimY/40);
  textePokedex.setCharacterSize(dimY/40);
  parametre.setCharacterSize(dimY/40);

  combat.setFillColor(sf::Color(176,196,222));
  tuto.setFillColor(sf::Color::Black);
  quitter.setFillColor(sf::Color::Black);
  textePokedex.setFillColor(sf::Color::Black);
  parametre.setFillColor(sf::Color::Black);

  combat.setPosition(dimX/2-combat.getLocalBounds().width/2, rectangleCombat.getPosition().y+rectangleCombat.getSize().y/2-combat.getLocalBounds().height/2);
  tuto.setPosition(dimX/2-tuto.getLocalBounds().width/2, rectangleTuto.getPosition().y+rectangleTuto.getSize().y/2-tuto.getLocalBounds().height/2);
  quitter.setPosition(dimX/2-quitter.getLocalBounds().width/2, rectangleQuitter.getPosition().y+rectangleQuitter.getSize().y/2-quitter.getLocalBounds().height/2);
  textePokedex.setPosition(dimX-textePokedex.getLocalBounds().width,dimY-textePokedex.getLocalBounds().height);
  parametre.setPosition(1,dimY-parametre.getLocalBounds().height);


  titre.setTexture(&textureTitre);
  titre.setSize(sf::Vector2f(dimX/5,dimY/6));
  titre.setPosition(dimX/2-titre.getSize().x/2,dimY/40);

  imagePokedex.setTexture(&pokedex);
  imagePokedex.setSize(sf::Vector2f(dimX/20,dimY/10));
  imagePokedex.setPosition(dimX-imagePokedex.getSize().x,dimY-imagePokedex.getSize().y-textePokedex.getLocalBounds().height);

  imageParametre.setTexture(&engrenage);
  imageParametre.setSize(sf::Vector2f(dimX/20,dimY/10));
  imageParametre.setPosition(1,dimY-imageParametre.getSize().y-parametre.getLocalBounds().height);

  if (!sonCoupe.loadFromFile ("data/Graphique/SonActive.png")){
    std::cout << "Probleme d'imagePokedex" << '\n';
  }

  boutonCouperSon.setTexture(&sonCoupe);
  boutonCouperSon.setPosition(dimX - dimX/30,1);
  boutonCouperSon.setSize(sf::Vector2f(dimX/30,dimX/30));
}

void SFMLMenu::couperSon (){
  if (!estCoupe){
    if (!sonCoupe.loadFromFile ("data/Graphique/SonCoupe.png")){
      std::cout << "erreur" << '\n';
    }
    boutonCouperSon.setTexture(&sonCoupe);
    boutonCouperSon.setPosition(dimX - boutonCouperSon.getLocalBounds().width,1);
    boutonCouperSon.setSize(sf::Vector2f(dimX/30,dimX/30));

    estCoupe=true;
    musiqueMenu.setVolume(0);
  }
  else {
    if (!sonCoupe.loadFromFile ("data/Graphique/SonActive.png")){
      std::cout << "erreur" << '\n';
    }

    boutonCouperSon.setTexture(&sonCoupe);
    boutonCouperSon.setPosition(dimX - boutonCouperSon.getLocalBounds().width,1);
    boutonCouperSon.setSize(sf::Vector2f(dimX/30,dimX/30));

    estCoupe=false;
    musiqueMenu.setVolume(valeurSon);
}
}

void SFMLMenu::reglerSon(){
  unsigned int x,y;
  font.loadFromFile("data/Fonts/Splatch.ttf");
  if (!Plus.loadFromFile ("data/Graphique/Plus.png")){
    std::cout << "erreur" << '\n';
  }
  if (!Moins.loadFromFile ("data/Graphique/Moins.png")){
    std::cout << "erreur" << '\n';
  }
  x=dimX/2;
  y=dimY/3;
  sf::RenderWindow windowSound (sf::VideoMode (x,y),"Reglage son");
  x = windowSound.getSize().x;
  y = windowSound.getSize().y;

  boutonMoins.setTexture(&Moins);
  boutonMoins.setSize(sf::Vector2f(x/15,y/10));
  boutonMoins.setPosition(x/12,y/2);

  boutonPlus.setTexture(&Plus);
  boutonPlus.setSize(sf::Vector2f(x/15,y/10));
  boutonPlus.setPosition(x/2 + x/6 + x/5 ,y/2);

  barreSon.setSize(sf::Vector2f((x/6 +x/2) * valeurSon/100 ,y/10));
  barrePlein.setSize(sf::Vector2f(x/2 +x/6,y/10));

  sf::RectangleShape rectangleSon (sf::Vector2f (x,y));
  rectangleSon.setFillColor(sf::Color(78,71,99));

  windowSound.setVerticalSyncEnabled(true);

  barreSon.setFillColor(sf::Color::Green);
  barrePlein.setFillColor(sf::Color::Red);
  barreSon.setPosition(x/6,y/2);
  barrePlein.setPosition(x/6,y/2);

  valeurVolume.setString(std::to_string(valeurSon));
  valeurVolume.setFont(font);
  valeurVolume.setFillColor(sf::Color::Black);
  valeurVolume.setCharacterSize(x/40);
  valeurVolume.setPosition(x/2-valeurVolume.getLocalBounds().width/2,y/2-valeurVolume.getLocalBounds().height/2 +y/16);

  if (estCoupe){
    valeurSon=0;
  }

  while (windowSound.isOpen())
  {
    sf::Event event;
    while (windowSound.pollEvent (event)){
      if (event.type == sf::Event::Closed){
        windowSound.close ();
      }
      PositionSouris3 = sf::Mouse::getPosition(windowSound);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if ((unsigned int) PositionSouris3.x >= x/12 && (unsigned int) PositionSouris3.y >= y/2 && (unsigned int) PositionSouris3.x <= x/12 + x/15 && (unsigned int) PositionSouris3.y <= y/2 +y/10){
          if (valeurSon == 0)
          {
            valeurSon = 0;
            estCoupe=false;
            couperSon();
          }
          else {
            valeurSon = valeurSon - 10;
            if (valeurSon == 0){
              valeurSon = 0;
              estCoupe=false;
              couperSon();
            }
            valeurVolume.setString(std::to_string(valeurSon));
            barreSon.setSize(sf::Vector2f((x/6 +x/2) * valeurSon/100 ,y/10));
            musiqueMenu.setVolume(valeurSon);
          }
        }
        else if ((unsigned int) PositionSouris3.x >= x/2 + x/6 + x/5 && (unsigned int) PositionSouris3.x <= x/2 + x/6 + x/5 + x/15 && (unsigned int) PositionSouris3.y >= y/2 && (unsigned int) PositionSouris3.y <= y/2 + y/10){
          estCoupe=true;
          couperSon();
          if (valeurSon ==100){
            valeurSon=100;
          }
          else {
            valeurSon = valeurSon +10;
            valeurVolume.setString(std::to_string(valeurSon));
            barreSon.setSize(sf::Vector2f((x/6 +x/2) * valeurSon/100 ,y/10));
           musiqueMenu.setVolume(valeurSon);
          }
        }
        else if ((unsigned int) PositionSouris3.x >= x || (unsigned int) PositionSouris3.y >= y)
        {
          windowSound.close();
        }
      }
    }
    windowSound.clear (sf::Color::Black);
    windowSound.draw(rectangleSon);
    windowSound.draw(barrePlein);
    windowSound.draw(barreSon);
    windowSound.draw(boutonMoins);
    windowSound.draw(boutonPlus);
    windowSound.draw(valeurVolume);
    windowSound.display();
  }
}

void SFMLMenu::initialisationAccueil(){
  dimX = sf::VideoMode::getDesktopMode().width;
  dimY = sf::VideoMode::getDesktopMode().height;

  menuWindow.create (sf::VideoMode (dimX,dimY),"PokePeip");
  menuWindow.setVerticalSyncEnabled(true);

  dimX = menuWindow.getSize().x;
  dimY = menuWindow.getSize().y;

  font.loadFromFile("data/Fonts/PokemonSolid.ttf");
  font2.loadFromFile("data/Fonts/Splatch.ttf");
  font3.loadFromFile("data/Fonts/lemon_milk/LemonMilk.otf");

  accueil.setString("BIENVENUE DANS NOTRE JEU POKEPEIP !");
  corporation.setString("Pokepeip inc.");
  message.setString("APPUYER SUR UNE TOUCHE POUR CONTINUER");

  accueil.setFont(font);
  message.setFont(font2);
  corporation.setFont(font3);

  accueil.setCharacterSize(dimX/25);
  message.setCharacterSize(dimX/100);
  corporation.setCharacterSize(dimX/160);

  accueil.setFillColor(sf::Color(20,105,194));
  message.setFillColor(sf::Color(1,1,1));
  corporation.setFillColor(sf::Color(250,250,250));

  accueil.setPosition(dimX/2 - accueil.getLocalBounds().width/2,2*dimY/5 - accueil.getLocalBounds().height/2);
  message.setPosition(dimX -message.getLocalBounds().width,dimY - message.getLocalBounds().height);
  corporation.setPosition(1,1);

  if (!fondEcran.loadFromFile ("data/Graphique/Fond2.png")){
    std::cout << "erreur" << '\n';
  }

  fondAccueil.setTexture(&fondEcran);
  fondAccueil.setSize(sf::Vector2f(dimX,dimY));
  fondAccueil.setPosition(1,1);
}

void SFMLMenu::initialisationFond (){
  fondPrincipale.setSize (sf::Vector2f (dimX,dimY));
  fondPrincipale.setFillColor (sf::Color(176,196,222));
  fondPrincipale.setPosition (0,0);
}

void SFMLMenu::dessinerDefault (){
  switch (position) {
    case 1: rectangleCombat.setOutlineColor(sf::Color(255, 255, 255));
    rectangleCombat.setFillColor(sf::Color(255, 255, 255,0));
    rectangleCombat.setOutlineThickness(5.f);
    break;

    case 2: rectangleTuto.setOutlineColor(sf::Color(255 , 255, 255));
    rectangleTuto.setFillColor(sf::Color(255, 255, 255,0));
    rectangleTuto.setOutlineThickness(5.f);
    break;

    case 3: rectangleQuitter.setOutlineColor(sf::Color(255, 255, 255));
    rectangleQuitter.setFillColor(sf::Color(255, 255, 255,0));
    rectangleQuitter.setOutlineThickness(5.f);
    break;

    default:
    break;
  }
}

void SFMLMenu::dessinerSelection (){
  switch (position) {
    case 1: rectangleCombat.setOutlineColor(sf::Color(255, 255, 255));
    rectangleCombat.setFillColor(sf::Color(255, 255, 255));
    rectangleCombat.setOutlineThickness(8.f);
    combat.setFillColor(sf::Color(176,196,222));
    tuto.setFillColor(sf::Color::Black);
    quitter.setFillColor(sf::Color::Black);
    break;

    case 2: rectangleTuto.setOutlineColor(sf::Color(255, 255, 255));
    rectangleTuto.setFillColor(sf::Color(255, 255, 255));
    rectangleTuto.setOutlineThickness(8.f);
    tuto.setFillColor(sf::Color(176,196,222));
    quitter.setFillColor(sf::Color::Black);
    combat.setFillColor(sf::Color::Black);
    break;

    case 3: rectangleQuitter.setOutlineColor(sf::Color(255, 255, 255));
    quitter.setFillColor(sf::Color(255,255,255));
    rectangleQuitter.setFillColor(sf::Color(255,255,255));
    rectangleQuitter.setOutlineThickness(8.f);
    quitter.setFillColor(sf::Color(176,196,222));
    tuto.setFillColor(sf::Color::Black);
    combat.setFillColor(sf::Color::Black);
    break;

    default:
    break;
  }
}

void SFMLMenu::action (){
  switch (position) {
    case 1: {
      if (!musiqueCombat.openFromFile("data/Musique/rencontre01.ogg"))
        {
        std::cout<<"Erreur lors de l'ouverture de la music";
      }
      musiqueCombat.play();
      musiqueCombat.setLoop(true);
      SFMLCharger charger (menuWindow);
      charger.boucleAffichage ();
      musiqueCombat.stop();
      musiqueMenu.play();
    }
    break;
    case 2: lireTuto ();
    break;
	    case 3: fermerJeu ();
    break;
  }
}

void SFMLMenu::dessinerWindow (){
  menuWindow.clear (sf::Color::White);
  menuWindow.draw (fondPrincipale);
  menuWindow.draw (titre);
  menuWindow.draw (rectangleCombat);
  menuWindow.draw (rectangleTuto);
  menuWindow.draw (rectangleQuitter);
  menuWindow.draw(combat);
  menuWindow.draw(tuto);
  menuWindow.draw(quitter);
  menuWindow.draw(imagePokedex);
  menuWindow.draw(textePokedex);
  menuWindow.draw(parametre);
  menuWindow.draw(imageParametre);
  menuWindow.draw(boutonCouperSon);
  menuWindow.display ();
}

void SFMLMenu::lireTuto (){
  std::ifstream fichier ("data/tuto.txt");
  sf::Event event;
  if (!fichier.is_open ()){
    std::cout << "erreur" << '\n';
  }
  bool fin (false);
  std::string a;
  sf::Texture texture;
  sf::Sprite sprite;
  texture.loadFromFile ("data/ImageFondTuto.png");
  sprite.setTexture (texture);
  while (fin == false){
    while (menuWindow.pollEvent (event)){
      if (event.type == sf::Event::Closed){
        fin=true;
        menuWindow.close ();
      }
      if (event.key.code == sf::Keyboard::A) fin = true;
    }
    menuWindow.clear (sf::Color::White);
    menuWindow.draw (sprite);
    menuWindow.display ();
  }
  fichier.close ();
}

void SFMLMenu::fermerJeu (){
  sf::Text texte;
  sf::Text gauche;
  sf::Text droit;

  gauche.setFont(font);
  texte.setFont (font);
  droit.setFont(font);

  texte.setString("VOULEZ VRAIMENT FERMER POKEPEIP ?");
  gauche.setString("ANNULER");
  droit.setString("QUITTER");

  gauche.setCharacterSize(10);
  texte.setCharacterSize(10);
  droit.setCharacterSize(10);

  texte.setFillColor (sf::Color::Black);
  gauche.setFillColor(sf::Color::Black);
  droit.setFillColor(sf::Color::Black);

  unsigned int x,y;
  unsigned int fermerPosition (0);
  x = dimX -dimX/4;
  y = dimY -dimY/4 + dimY/12;

  texte.setPosition (x/2-texte.getLocalBounds().width/2,y/2 - y/7+y/8);
  gauche.setPosition(x/4-gauche.getLocalBounds().width/2 , y/2 + y/3 +y/10);
  droit.setPosition(x/4-droit.getLocalBounds().width/2 + x/2, y/2 + y/3 +y/10);
  sf::RenderWindow windowFermeture (sf::VideoMode (x,y),"Fermeture");
  x = windowFermeture.getSize().x;
  y = windowFermeture.getSize().y;

  sf::RectangleShape fondPrincipaleFermeture (sf::Vector2f (x,y));
  sf::RectangleShape rectangleGauche (sf::Vector2f (x/2 -4,y/8));
  sf::RectangleShape rectangleDroite (sf::Vector2f (x/2 -4,y/8));

  rectangleGauche.setFillColor (sf::Color(211,211,211));
  rectangleGauche.setOutlineColor (sf::Color(128,128,128));
  rectangleGauche.setOutlineThickness (5.f);
  rectangleGauche.setPosition (1,y - y/4 +y/8);

  rectangleDroite.setFillColor (sf::Color(211,211,211));
  rectangleDroite.setOutlineColor (sf::Color(128,128,128));
  rectangleDroite.setOutlineThickness (2.f);
  rectangleDroite.setPosition (x/2,y - y/4+y/8);

  fondPrincipaleFermeture.setFillColor (sf::Color (61,99,140));
  while (windowFermeture.isOpen ()){
    sf::Event event;
    while (windowFermeture.pollEvent (event)){
      if (event.type == sf::Event::Closed){
        windowFermeture.close ();
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        PositionSouris2 = sf::Mouse::getPosition(windowFermeture);
        if ((unsigned int) PositionSouris2.x >= 1 && (unsigned int) PositionSouris2.y >= y-y/4 +y/8 && (unsigned int) PositionSouris2.x <= 1 + x/2 -4){
          windowFermeture.close();
          estDansFerme=false;
        }
        else if ((unsigned int) PositionSouris2.x >= x/2 && (unsigned int) PositionSouris2.y >= y - y/4+y/8 && (unsigned int) PositionSouris2.x <= x/2 + x/2 -4){
          windowFermeture.close();
          estDansFerme=false;
          fin=true;
        }
      }
        if (event.type == sf::Event::KeyPressed){
          switch (event.key.code) {
            case sf::Keyboard::Left: fermerPosition = 0;
              rectangleGauche.setOutlineThickness (5.f);
              rectangleDroite.setOutlineThickness (2.f);
              break;
          case sf::Keyboard::Right: fermerPosition = 1;
            rectangleGauche.setOutlineThickness (2.f);
            rectangleDroite.setOutlineThickness (5.f);
            break;
          case sf::Keyboard::Return:
            switch (fermerPosition) {
              case 0: windowFermeture.close ();
              break;
              case 1 :
                windowFermeture.close ();
                fin = true;
              break;
              default:
              break;
            }
          default :
          break;
        }
      }
    }
    windowFermeture.clear (sf::Color::Black);
    windowFermeture.draw (fondPrincipaleFermeture);
    windowFermeture.draw (rectangleGauche);
    windowFermeture.draw (rectangleDroite);
    windowFermeture.draw (texte);
    windowFermeture.draw(gauche);
    windowFermeture.draw(droit);
    windowFermeture.display ();
  }
}

void SFMLMenu::boucleAffichage (){
  estCoupe =false;
  estDansFerme = false;
  if (!musiqueAccueil.openFromFile("data/Musique/pokemon.ogg"))
  {
    std::cout<<"Erreur";
  }
  musiqueAccueil.play();
  musiqueAccueil.setLoop(true);
  initialisationAccueil();
  sf:: Event event;
  while (menuWindow.isOpen()) {
    while (menuWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed){
        musiqueAccueil.stop();
        menuWindow.close();
      }
      if (event.type == sf::Event::KeyPressed){
        if (event.key.code==sf::Keyboard::B) {
          musiqueAccueil.stop();
          if (!musiqueAccueil.openFromFile("data/Musique/benoit.ogg"))
          {
            std::cout<<"Erreur";
          }
          musiqueAccueil.play();
        }
        else {
          musiqueAccueil.stop();
          menuWindow.close();
        }
      }
    }
    menuWindow.clear (sf::Color::White);
    menuWindow.draw(fondAccueil);
    menuWindow.draw(accueil);
    menuWindow.draw(message);
    menuWindow.draw(corporation);
    menuWindow.display();
  }
if (!musiqueMenu.openFromFile("data/Musique/titre.ogg"))
{
  std::cout<<"Erreur";
}
 musiqueMenu.play();
 musiqueMenu.setLoop(true);
  initialisationMenu ();
  initialisationFond ();
  while (menuWindow.isOpen ()){
    while (menuWindow.pollEvent (event)){
      if (event.type == sf::Event::Closed){
        estDansFerme=true;
        fermerJeu();
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
          RecupSouris();
      }
      if (event.type == sf::Event::KeyPressed){
        switch (event.key.code) {
          case sf::Keyboard::Down:
            if (position == 3)position = 3;
            else {
              dessinerDefault ();
              position ++;
              dessinerSelection ();
            }
          break;
          case sf::Keyboard::Up:
            if (position == 1) position = 1;
            else {
              dessinerDefault ();
              position --;
              dessinerSelection ();
              }
          break;
          case sf::Keyboard::Return:
           musiqueMenu.stop();
            action ();
          break;
          case sf::Keyboard::P:{
           musiqueMenu.stop();
            SFMLPokedex a (menuWindow);
            a.boucleAffichage ();
            musiqueMenu.play();
          }
          break;
          case sf::Keyboard::R:{
            reglerSon();
          }
          break;
          case sf::Keyboard::Escape :
            fermerJeu ();
          break;
          default:
          break;
        }
      }
    }
    dessinerWindow ();
    if  (fin == true){
		menuWindow.close ();
    }
  }
}

void SFMLMenu::RecupSouris(){
  if (!estDansFerme){
    PositionSouris = sf::Mouse::getPosition(menuWindow);
    if ((unsigned int) PositionSouris.x >=dimX/2-dimX/4 && (unsigned int) PositionSouris.y >=dimY/2 -dimY/4+dimY/12 && (unsigned int) PositionSouris.x <= dimX/2-dimX/4 + dimX/2 && (unsigned int) PositionSouris.y <= dimY/2 -dimY/4+dimY/12 + dimY/10 )
    {
      musiqueCombat.play();
      musiqueCombat.setLoop(true);
      SFMLCharger charger (menuWindow);
      charger.boucleAffichage ();
      musiqueCombat.stop();
    }
    else if ((unsigned int) PositionSouris.x >=dimX/2-dimX/4 && (unsigned int) PositionSouris.y >= dimY/2 -dimY/4 + dimY/6+dimY/12 && (unsigned int) PositionSouris.x <= dimX/2 -dimX/4 + dimX/2 && (unsigned int) PositionSouris.y <= dimY/2 -dimY/4 + dimY/6+dimY/12 +dimY/10){
      lireTuto();
    }
    else if ((unsigned int) PositionSouris.x >=dimX/2 -dimX/4 && (unsigned int) PositionSouris.y >= dimY/2-dimY/4 +dimY/6 +dimY/12 +dimY/6 && (unsigned int) PositionSouris.x <= dimX/2 - dimX/4 +dimX/2 && (unsigned int) PositionSouris.y <= dimY/2-dimY/4 +dimY/6 +dimY/12 +dimY/6  + dimY/10){
      estDansFerme=true;
      fermerJeu();
    }
    else if ((unsigned int) PositionSouris.x >=dimX-imagePokedex.getSize().x && (unsigned int) PositionSouris.y >=dimY-imagePokedex.getSize().y-textePokedex.getLocalBounds().height && (unsigned int) PositionSouris.y <= dimY-imagePokedex.getSize().y-textePokedex.getLocalBounds().height + dimY/10 && (unsigned int) PositionSouris.x <= dimX-imagePokedex.getSize().x + dimX/20)
    {
     musiqueMenu.stop();
      SFMLPokedex a (menuWindow);
      a.boucleAffichage ();
     musiqueMenu.play();
    }
    else if ((unsigned int) PositionSouris.x >= 1 && (unsigned int) PositionSouris.y >=dimY-imageParametre.getSize().y-parametre.getLocalBounds().height && (unsigned int) PositionSouris.y <= dimY-imageParametre.getSize().y-parametre.getLocalBounds().height + dimY/10 && (unsigned int) PositionSouris.x <= 1 + dimY/10 ){
      reglerSon();
    }
    else if ((unsigned int) PositionSouris.x >= dimX -dimX/30 && (unsigned int) PositionSouris.y >= 1 && (unsigned int) PositionSouris.y <= 1 + dimX/30){
      couperSon();
    }
  }
    else if (estDansFerme){
      PositionSouris=sf::Mouse::getPosition(windowFermeture);
      fermerJeu();
    }
}

int main (){
  SFMLMenu Menu;
  Menu.boucleAffichage ();
}
