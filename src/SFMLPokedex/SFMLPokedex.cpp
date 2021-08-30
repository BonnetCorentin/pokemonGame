#include "SFMLPokedex.h"

/**
* @file SFMLPokedex.cpp
* @brief Fichier d'implémentation de la classe SFMLPokedex.cpp
*/

SFMLPokedex::SFMLPokedex (sf::RenderWindow& fenetre){
  sf::Vector2u tailleFenetre;
  menuWindow = &fenetre;
  std::ifstream monfichier;
  tailleFenetre = menuWindow->getSize ();
  dimX = tailleFenetre.x;
  dimY = tailleFenetre.y;
  position = 0;
  curseurGauche = 0;
  nbPokemonNiveau = 20;
  curseurDroit = nbPokemonNiveau;
  monfichier.open("data/Nom.txt");
  for (unsigned int i=0;i<152;i++)
  monfichier >> Pokedex[i];
  font.loadFromFile("data/Fonts/roboto/Roboto-Regular.ttf");
  siFlecheGauche = false;
  tabPokedex [0].setOutlineColor (sf::Color::Black);
  tabPokedex [0].setOutlineThickness (5.f);
}

void SFMLPokedex::dessinerDefault (){
  if (position == curseurDroit){
    rectangleFlecheDroite.setOutlineThickness (0.f);
  }
  else if (position == curseurGauche){
    if (siFlecheGauche == true){
      rectangleFlecheGauche.setOutlineThickness (0.f);
    }
    else {
      tabPokedex [curseurGauche].setOutlineThickness (0.f);
    }
  }
  else {
    tabPokedex [position].setOutlineThickness (0.f);
  }
}

void SFMLPokedex::dessinerSelection (){
  if (position == curseurDroit){
    rectangleFlecheDroite.setOutlineColor (sf::Color::Black);
    rectangleFlecheDroite.setOutlineThickness (5.f);
  }
  else if (position == curseurGauche){
    if (siFlecheGauche == true){
      rectangleFlecheGauche.setOutlineColor (sf::Color::Black);
      rectangleFlecheGauche.setOutlineThickness (5.f);
    }
    else {
      tabPokedex [curseurGauche].setOutlineColor (sf::Color::Black);
      tabPokedex [curseurGauche].setOutlineThickness (5.f);
    }
  }
  else {
    tabPokedex [position].setOutlineColor (sf::Color::Black);
    tabPokedex [position].setOutlineThickness (5.f);
  }
}

void SFMLPokedex::dessinerPokemon (){
  unsigned int dimension = dimX/18;
  unsigned int ligne = 1;
  unsigned int colone = 1;
  sf::Texture pokemon;
  sf::Texture flecheDroite,flecheGauche;

  rectangleFlecheDroite.setSize (sf::Vector2f (dimension,dimension));
  rectangleFlecheDroite.setPosition (dimX - dimension ,(dimY - dimY/3) - dimension);

  rectangleFlecheGauche.setSize (sf::Vector2f (dimension,dimension));
  rectangleFlecheGauche.setPosition (0,(dimY - dimY/3) - dimension);

  if (!flecheDroite.loadFromFile ("data/Graphique/FlecheDroite.png")){
    std::cout << "erreur lors de l'ouverture de flecheDoite" << '\n';
  }
  if (!flecheGauche.loadFromFile ("data/Graphique/FlecheGauche.png")){
    std::cout << "erreur lors de l'ouverture de fleche gauche" << '\n';
  }

  rectangleFlecheDroite.setTexture(&flecheDroite);
  rectangleFlecheGauche.setTexture (&flecheGauche);

  for (unsigned int i (curseurGauche);i<curseurDroit;++i){
    if(!pokemon.loadFromFile ("data/Sprite/Front/"+Pokedex[i]+".png")){
      std::cout<<"erreur lors de l'ouverture du sprite pokemon";
    };
    if (ligne > dimX - dimension){
      colone+=dimension + dimension/4;
      ligne=0;
    }
    tabPokedex [i].setTexture (&pokemon);
    tabPokedex [i].setPosition (ligne,colone);
    tabPokedex [i].setSize (sf::Vector2f (dimension,dimension));
    ligne += dimension + dimension/4;
    menuWindow->draw (tabPokedex[i]);
  }
  menuWindow->draw (rectangleFlecheDroite);
  menuWindow->draw (rectangleFlecheGauche);
  menuWindow->draw(back);
  menuWindow->draw (flechRetour);
  menuWindow->draw (niveauAvantDebloque);

}

std::string SFMLPokedex::recupererTypeString (int Type, sf::Texture &t) {
  switch (Type) {
    case 0 : t.loadFromFile ("data/TypePokémon/Feu.png");
    rouge = 227;
    vert = 85;
    bleu =40;
    return "Feu";
    break;

    case 1 :t.loadFromFile ("data/TypePokémon/Eau.png");
    rouge=40;
    vert=168;
    bleu=227;
    return "Eau";
    break;

    case 2 : t.loadFromFile ("data/TypePokémon/Insecte.png");
    rouge=37;
    vert=237;
    bleu=61;
    return "Insecte";
    break;

    case 3 : t.loadFromFile ("data/TypePokémon/Acier.png");
    rouge=175;
    vert=183;
    bleu=276;
    return "Acier";
    break;

    case 4 : t.loadFromFile ("data/TypePokémon/Dragon.png");
    rouge=17;
    vert=50;
    bleu=72;
    return "Dragon";
  	break;

    case 5 :t.loadFromFile ("data/TypePokémon/Elektrik.png");
    rouge=227;
    vert=216;
    bleu=55;
    return "Electrik";
    break;

    case 6 :t.loadFromFile ("data/TypePokémon/Normal.png");
    rouge=140;
    vert=140;
    bleu=140;
    return "Normal";
    break;

    case 7 : t.loadFromFile ("data/TypePokémon/Vol.png");
    rouge=200;
    vert=156;
    bleu=234;
    return "Vol";
    break;

    case 8 :t.loadFromFile ("data/TypePokémon/Glace.png");
    rouge=56;
    vert=214;
    bleu=242;
    return "Glace";
    break;

    case 9 : t.loadFromFile ("data/TypePokémon/Psy.png");
    rouge=236;
    vert=97;
    bleu=196;
    return "Psy";
    break;

    case 10 :t.loadFromFile ("data/TypePokémon/Roche.png");
    rouge=142;
    vert=53;
    bleu=39;
    return "Roche";
    break;

    case 11 : t.loadFromFile ("data/TypePokémon/Tenebre.png");
    rouge=39;
    vert=27;
    bleu=25;
    return "Tenebre";
    break;

    case 12 :t.loadFromFile ("data/TypePokémon/Spectre.png");
    rouge=141;
    vert=28;
    bleu=154;
    return "Spectre";
    break;

    case 13 :t.loadFromFile ("data/TypePokémon/Poison.png");
    rouge=141;
    vert=15;
    bleu=124;
    return "Poison";
    break;

    case 14 :t.loadFromFile ("data/TypePokémon/Sol.png");
    rouge=151;
    vert=106;
    bleu=63;
    return "Sol";
    break;

    case 15 : t.loadFromFile ("data/TypePokémon/Plante.png");
    rouge=76;
    vert=225;
    bleu=43;
    return "Plante";
    break;

    case 16 :t.loadFromFile ("data/TypePokémon/Combat.png");
    rouge=231;
    vert=46;
    bleu=20;
    return "Combat";
    break;

    case -1 :
    rouge =0;
    vert=0;
    bleu=0;
    return "Pas de Type";
    break;

    default : return "Pas de Type";
    break;
  };
}

void SFMLPokedex::recupererNomPokemon (sf::Text& nom,sf::Text& type1,sf::Text& type2,sf::Text& niveauAvantDebloque,sf::Text& nombrePv){
  std::string nomPokemon,niveau;
  int type1String,type2String;
  std::string nbPv;
  std::string cheminPokemon;

  cheminPokemon = Pokedex [position];
  cheminPokemon = "data/PokemonA/"+cheminPokemon+".txt";

  std::ifstream fichierPokemon (cheminPokemon);

  fichierPokemon>>nomPokemon;
  fichierPokemon>>niveau;
  fichierPokemon>>type2String;
  fichierPokemon>>type1String;
  fichierPokemon>>nbPv;

  if (type1String!= -1)
  {
    aDeuxType = false;
  }

  nom.setFont (font);
  nom.setCharacterSize (dimX/70);
  nom.setPosition (dimX/2 - carte.getLocalBounds().width /2 + dimX/15 ,(152*dimY)/240);
  nom.setFillColor (sf::Color::White);
  nom.setString (nomPokemon);

  type1.setFont (font);
  type1.setCharacterSize (dimX/81);
  type2.setPosition (dimX/2 - carte.getLocalBounds().width/2,(1608*dimY)/2160);
  type1.setFillColor (sf::Color::White);
  type1.setString ("2eme type du Pokemon : "+recupererTypeString(type1String,typePokemon2));
  carte.setOutlineColor(sf::Color(rouge,vert,bleu));

  type2.setFont (font);
  type2.setCharacterSize (dimX/81);
  type1.setPosition (dimX/2 - carte.getLocalBounds().width/2,dimY/3 + dimY/4 + dimY/9 + dimY/12 + dimY/20);
  type2.setFillColor (sf::Color::White);
  type2.setString ("1er type du Pokemon : "+recupererTypeString(type2String, typePokemon));

  niveauAvantDebloque.setFont (font);
  niveauAvantDebloque.setCharacterSize (dimX/81);
  niveauAvantDebloque.setPosition(dimX/2 - carte.getLocalBounds().width/2, dimY/3 + dimY/4 + dimY/9 + dimY/6 + dimY/20);
  niveauAvantDebloque.setFillColor (sf::Color::White);
  niveauAvantDebloque.setString ("Niveau avant de debloquer : "+niveau);
  niveauAvantDebloque.setCharacterSize (dimX/81);

  nombrePv.setFont(font);
  nombrePv.setCharacterSize(dimX/100);
  nombrePv.setFillColor(sf::Color::Black);
  nombrePv.setString(nbPv + "PV");
  nombrePv.setPosition(dimX/2 - carte.getLocalBounds().width/2 ,dimY/3);

  fichierPokemon.close ();
}

void SFMLPokedex::dessinerBas (){
  unsigned int dimension = dimX/16;
  sf::Text nomPokemon,type1,type2,nombrePv;
  sf::Texture texture;
  font.loadFromFile("data/Fonts/roboto/Roboto-Regular.ttf");

  if (!retour.loadFromFile ("data/Graphique/retour.png")){
    std::cout << "erreur lors de l'ouverture de la fleche retour" << '\n';
  }

  if (position < curseurDroit){
    if(!texture.loadFromFile ("data/Sprite/Front/"+Pokedex[position]+".png")){
      std::cout << "erreur lors de l'ouverture du sprite de bas" << '\n';
    }
      recupererNomPokemon (nomPokemon,type1,type2,niveauAvantDebloque,nombrePv);
      pokemonBas.setTexture (&texture);
      pokemonBas.setPosition (dimX/2 - carte.getLocalBounds().width/2 +pokemonBas.getLocalBounds().width/2 - dimX/80,dimY/2 -dimY/10);
      pokemonBas.setSize (sf::Vector2f (2*dimension - dimension/5,2*dimension- dimension/5));

      flechRetour.setString("APPUYER SUR A POUR REVENIR OU CLIQUER SUR LA FLECHE");
      flechRetour.setFont(font);
      flechRetour.setCharacterSize(dimX/80);
      flechRetour.setFillColor(sf::Color::Black);
      flechRetour.setPosition(dimX-flechRetour.getLocalBounds().width,dimY-flechRetour.getLocalBounds().height -dimY/50);

      back.setTexture(&retour);
      back.setFillColor(sf::Color(176,196,222));
      back.setPosition(dimX-back.getSize().x,dimY-back.getSize().y-flechRetour.getLocalBounds().height);
      back.setSize(sf::Vector2f(dimension,dimension));

      carte.setSize(sf::Vector2f(dimX/4 - dimX/24,dimY/2 + dimY/10));
      carte.setFillColor(sf::Color(rouge,vert,bleu));
      carte.setPosition(dimX/2 - carte.getLocalBounds().width/2,dimY/3);

      elementPokemon.setTexture(&typePokemon);
      elementPokemon.setPosition(dimX/2 - carte.getLocalBounds().width/2 + dimX/4 - elementPokemon.getLocalBounds().width - dimX/20 + dimX/130 ,dimY/3);
      elementPokemon.setSize(sf::Vector2f(dimX/20,dimX/20));

      menuWindow->draw(carte);
      menuWindow->draw (nomPokemon);
      menuWindow->draw(type1);
      menuWindow->draw (type2);
      menuWindow->draw(back);
      menuWindow->draw(flechRetour);
      menuWindow->draw (pokemonBas);
      menuWindow->draw (elementPokemon);
      menuWindow->draw(nombrePv);
      if (!aDeuxType){
        elementPokemon2.setTexture(&typePokemon2);
        elementPokemon2.setPosition(dimX/2 - carte.getLocalBounds().width/2 + dimX/4 - elementPokemon.getLocalBounds().width - dimX/20 + dimX/130 ,dimY/3 + dimY/9);
        elementPokemon2.setSize(sf::Vector2f(dimX/20,dimX/20));
        carte.setOutlineThickness(10);
        menuWindow->draw (elementPokemon2);
        aDeuxType = true;
    }
  }
    if (position == curseurDroit){
      if(!texture.loadFromFile ("data/Sprite/Front/"+Pokedex[position-1]+".png")){
        std::cout << "erreur lors de l'ouverture du sprite de bas" << '\n';
      }
      position= position-1;
      recupererNomPokemon (nomPokemon,type1,type2,niveauAvantDebloque,nombrePv);
      position=curseurDroit;
      pokemonBas.setTexture (&texture);
      pokemonBas.setPosition (dimX/2 - carte.getLocalBounds().width/2 +pokemonBas.getLocalBounds().width/2 - dimX/80,dimY/2 -dimY/10);
      pokemonBas.setSize (sf::Vector2f (2*dimension - dimension/5,2*dimension- dimension/5));

      flechRetour.setString("APPUYER SUR A POUR REVENIR OU CLIQUER SUR LA FLECHE");
      flechRetour.setFont(font);
      flechRetour.setCharacterSize(dimX/80);
      flechRetour.setFillColor(sf::Color::Black);
      flechRetour.setPosition(dimX-flechRetour.getLocalBounds().width,dimY-flechRetour.getLocalBounds().height -dimY/50);

      back.setTexture(&retour);
      back.setFillColor(sf::Color(176,196,222));
      back.setPosition(dimX-back.getSize().x,dimY-back.getSize().y-flechRetour.getLocalBounds().height);
      back.setSize(sf::Vector2f(dimension,dimension));

      carte.setSize(sf::Vector2f(dimX/4 - dimX/24,dimY/2 + dimY/10));
      carte.setFillColor(sf::Color(rouge,vert,bleu));
      carte.setPosition(dimX/2 - carte.getLocalBounds().width/2,dimY/3);

      elementPokemon.setTexture(&typePokemon);
      elementPokemon.setPosition(dimX/2 - carte.getLocalBounds().width/2 + dimX/4 - elementPokemon.getLocalBounds().width - dimX/20 + dimX/130 ,dimY/3);
      elementPokemon.setSize(sf::Vector2f(dimX/20,dimX/20));

      menuWindow->draw(carte);
      menuWindow->draw (nomPokemon);
      menuWindow->draw(type1);
      menuWindow->draw (type2);
      menuWindow->draw(back);
      menuWindow->draw(flechRetour);
      menuWindow->draw (pokemonBas);
      menuWindow->draw (elementPokemon);
      menuWindow->draw(nombrePv);
      if (!aDeuxType){
        elementPokemon2.setTexture(&typePokemon2);
        elementPokemon2.setPosition(dimX/2 - carte.getLocalBounds().width/2 + dimX/4 - elementPokemon.getLocalBounds().width - dimX/20 + dimX/130 ,dimY/3 + dimY/9);
        elementPokemon2.setSize(sf::Vector2f(dimX/20,dimX/20));
        carte.setOutlineThickness(10);
        menuWindow->draw (elementPokemon2);
        aDeuxType = true;
    }
  }
}

void SFMLPokedex::changerPage (){
  if (!music.openFromFile("data/Musique/pokedex.ogg"))
  {
    std::cout<<"Erreur lors de l'ouverture de la music";
  }
  music.play();
  if (position == curseurDroit && niveauJoueur != 0){
    curseurGauche = position;
    curseurDroit += nbPokemonNiveau;
    rectangleFlecheDroite.setOutlineThickness (0.f);
    tabPokedex [curseurGauche].setOutlineColor (sf::Color::Black);
    tabPokedex [curseurGauche].setOutlineThickness (5.f);
    niveauJoueur --;
  }
  else if (siFlecheGauche == true && curseurGauche != 0){
    curseurDroit -= nbPokemonNiveau;
    curseurGauche -= nbPokemonNiveau;
    position = curseurGauche;
    rectangleFlecheGauche.setOutlineThickness (0.f);
    rectangleFlecheGauche.setOutlineColor (sf::Color::Black);
    rectangleFlecheGauche.setOutlineThickness (5.f);
    niveauJoueur ++;
  }
  if (curseurDroit >150){
    curseurGauche -= nbPokemonNiveau;
    curseurDroit -= nbPokemonNiveau;
    position = curseurDroit;
    rectangleFlecheDroite.setOutlineColor (sf::Color::Black);
    rectangleFlecheDroite.setOutlineThickness (5.f);
    niveauJoueur ++;
  }
}

void SFMLPokedex::boucleAffichage (){
  fondPrincipale.setSize (sf::Vector2f (dimX,dimY));
  fondPrincipale.setFillColor (sf::Color(176,196,222));
  fondPrincipale.setPosition (0,0);
  font.loadFromFile("data/Fonts/roboto/Roboto-Regular.ttf");

  niveauJoueur = 10;

  sf::Event event;
  fin = false;
  if (!music.openFromFile("data/Musique/pokedex.ogg"))
    {
    std::cout<<"Erreur lors de l'ouverture de la music";
  }
  music.play();
  while (fin == false){
    while (menuWindow->pollEvent (event)){
      if (event.type == sf::Event::Closed){
        fin = true;
      }
      nbPage = curseurDroit/20;
      basDePage.setString(std::to_string(nbPage));
      basDePage.setPosition(1, dimY - dimY/8 + dimY/50);
      basDePage.setCharacterSize(100);
      basDePage.setFont(font);
      basDePage.setFillColor(sf::Color::Black);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        dessinerDefault();
        ChangerPageSouris();
        dessinerBas();
        dessinerSelection();
      }
      if (event.type == sf::Event::KeyPressed){
      switch (event.key.code) {
        case  sf::Keyboard::A: fin = true;
        break;
        case sf::Keyboard::Escape: fin = true;
        break;
        case sf::Keyboard::Left: if (position == curseurGauche){
          if (siFlecheGauche == false){
            dessinerDefault ();
            siFlecheGauche = true;
            dessinerSelection ();
          }
        }
        else {
          dessinerDefault ();
          position --;
          dessinerSelection ();
        }
        break;
        case sf::Keyboard::Right: if (position == curseurDroit){
          position = curseurDroit;
        }
        else if (position == curseurGauche){
          if (siFlecheGauche == true){
            dessinerDefault ();
            siFlecheGauche = false;
            dessinerSelection ();
          }
          else {
            dessinerDefault ();
            position ++;
            dessinerSelection ();
          }
        }
        else {
          dessinerDefault ();
          position ++;
          dessinerSelection ();
        }
        break;
        case sf::Keyboard::Return:
          changerPage ();
        default:
        break;
      }
    }
  }
    menuWindow->clear (sf::Color::White);
    menuWindow->draw (fondPrincipale);
    dessinerBas ();
    dessinerPokemon ();
    menuWindow->draw(basDePage);

    menuWindow->display ();
  }
}

void SFMLPokedex::boucleAffichageAvecJoueur (Joueur& joueur,unsigned int i){

  sf::Text choixPokemon;
  choixPokemon.setFont (font);
  choixPokemon.setPosition (1,dimY/2);
  choixPokemon.setCharacterSize (dimX/50);
  choixPokemon.setString ("Selectionnez votre pokemon numero : " + std::to_string (i+1));
  choixPokemon.setFillColor (sf::Color::Black);

  niveauJoueur = joueur.getNiveau ();

  fondPrincipale.setSize (sf::Vector2f (dimX,dimY));
  fondPrincipale.setFillColor (sf::Color(176,196,222));
  fondPrincipale.setPosition (0,0);

  sf::Event event;
  if (!music.openFromFile("data/Musique/pokedex.ogg"))
    {
    std::cout<<"Erreur lors de l'ouverture de la music";
  }
  music.play();
  fin =false;
  while (fin == false){
    while (menuWindow->pollEvent (event)){
      if (event.type == sf::Event::Closed){
        menuWindow->close();
        fin = true;
      }
      nbPage = curseurDroit/20;
      basDePage.setString(std::to_string(nbPage));
      basDePage.setPosition(1, dimY - dimY/8 + dimY/50);
      basDePage.setCharacterSize(100);
      basDePage.setFont(font);
      basDePage.setFillColor(sf::Color::Black);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        dessinerDefault();
        ChangerPageSouris();
        dessinerBas();
        dessinerSelection();
      }
      if (event.type == sf::Event::KeyPressed){
      switch (event.key.code) {
        case  sf::Keyboard::A: fin = true;
        break;
        case sf::Keyboard::Escape: fin = true;
        break;
        case sf::Keyboard::Left: if (position == curseurGauche){
          if (siFlecheGauche == false){
            dessinerDefault ();
            siFlecheGauche = true;
            dessinerSelection ();
          }
        }
        else {
          dessinerDefault ();
          position --;
          dessinerSelection ();
        }
        break;
        case sf::Keyboard::Right: if (position == curseurDroit){
          position = curseurDroit;
        }
        else if (position == curseurGauche){
          if (siFlecheGauche == true){
            dessinerDefault ();
            siFlecheGauche = false;
            dessinerSelection ();
          }
          else {
            dessinerDefault ();
            position ++;
            dessinerSelection ();
          }
        }
        else {
          dessinerDefault ();
          position ++;
          dessinerSelection ();
        }
        break;
        case sf::Keyboard::Return:
          if (siFlecheGauche == true || position == curseurDroit){
            changerPage ();
        }
          else {
            chargerIemePokemon (joueur,i);



            fin = true;
          }
        default:
        break;
      }
    }
  }

    menuWindow->clear (sf::Color::White);
    menuWindow->draw (fondPrincipale);
    dessinerBas ();
    menuWindow->draw(choixPokemon);
    dessinerPokemon ();
    menuWindow->draw(basDePage);
    for (unsigned int j =0;j<i;j++){
      pokemonChoisis.setFont(font);
      pokemonChoisis.setPosition(1,dimY/2 + (j+1)*dimX/50 + dimY/8);
      pokemonChoisis.setCharacterSize(dimX/50);
      pokemonChoisis.setString("Pokemon " + std::to_string(j+1) + joueur.getIemePokemon(j).getNom());
      pokemonChoisis.setFillColor(sf::Color::Black);
      menuWindow->draw(pokemonChoisis);
  }
    menuWindow->display ();
  }
}

void SFMLPokedex::ChangerPageSouris(){
  sf::Vector2i PositionSouris;
  PositionSouris = sf::Mouse::getPosition(*menuWindow);
  unsigned int dimension = dimX/16;
  if ((unsigned int) PositionSouris.x >= dimX-dimension && (unsigned int) PositionSouris.y >= (dimY-dimY/3)-dimension && (unsigned int) PositionSouris.x <=dimX && (unsigned int) PositionSouris.y <=dimY-dimY/3){
    position = curseurDroit;
    changerPage();
    if (position > 149)
    {
      rectangleFlecheDroite.setOutlineThickness(0.f);
      position=curseurGauche;
    }
  }
  else if ((unsigned int) PositionSouris.x >=1 && (unsigned int) PositionSouris.y >= (dimY-dimY/3)-dimension && (unsigned int) PositionSouris.x <= 1 + dimension && (unsigned int) PositionSouris.y <= dimY-dimY/3){
    if (position !=0){
    position=curseurGauche;
    siFlecheGauche=true;
    changerPage();
    siFlecheGauche=false;
    rectangleFlecheGauche.setOutlineThickness(0.f);
    }
  }
  else if ((unsigned int) PositionSouris.x >=dimX-back.getSize().x && (unsigned int) PositionSouris.y >=dimY-back.getSize().y-flechRetour.getLocalBounds().height -dimY/50 && (unsigned int) PositionSouris.y <= dimY-back.getSize().y-flechRetour.getLocalBounds().height + dimY/10 && (unsigned int) PositionSouris.x <= dimX-back.getSize().x + dimX/20){
   fin=true;;
  }
  else if ((unsigned int) PositionSouris.y <= dimX/18)
  {
    for (unsigned int i=3;i<17;i++)
    {
      if ((unsigned int)PositionSouris.x <= (i-2)*(dimX/14) && (unsigned int)PositionSouris.x >= (i-3)*(dimX/14))
      {
        position = (i-3)+((nbPage-1)*20);
      }
    }
  }
  else if ((unsigned int) PositionSouris.y >= dimX/18 && (unsigned int)PositionSouris.y <= dimX/9){
    for (unsigned int j=3;j<17;j++)
    {
      if ((unsigned int)PositionSouris.x <= (j-2)*(dimX/14) && (unsigned int)PositionSouris.x >= (j-3)*(dimX/14) && (unsigned int)PositionSouris.x <= 6*(dimX/14))
      {
        position = (j+11)+((nbPage-1)*20);
      }
    }
  }
}

void SFMLPokedex::chargerIemePokemon (Joueur& joueur,unsigned int i)const{
  std::string cheminPokemon ("data/PokemonA/"+Pokedex [position]+".txt");
  Pokemon pokemon;
  pokemon.chargerPokemon (cheminPokemon);
  joueur.setIemePokemon (pokemon,i);
}
