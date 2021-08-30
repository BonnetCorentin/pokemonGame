Liste des membres du groupe :

Fabien GOUBIN p1703553
Corentin BONNET p1703505
Lucas CHALOYARD p1704346
William BOUCHUT p1702669
Comment compiler :

Pour compiler et pouvoir jouer à notre jeu, il faut se trouver à la racine de l'archive et exécuter les commande suivantes :

Pour compiler : make SFMLMenu.out

Pour exécuter : bin/./SFMLMenu.out.

Cette commande permet donc de lancer le jeu et d'accéder à toutes les fonctionnalités une fois dedans.
Descriptif du jeu :

Le jeu PokePeip consiste en un jeu de stratégie au tour par tour, le joueur forme une équipe de 6 Pokemon à la création de son personnage, et peut par la suite lancer un combat contre une IA ou alors un joueur jouant sur le même ordinateur.

Comment utiliser le jeu :

Une fois le jeu lancé vous arrivez dans un menu avec trois options : combat, tuto ou quitter.
La première est la plus importante et la plus grosse, elle contient quasiment la moitié du code et vous permet de créer une sauvegarde, de choisir votre liste de Pokémon et de vous battre contre l'IA ou contre un autre joueur sur le même PC.
La deuxième option est un tutoriel vous expliquant comment jouer.
Et enfin la dernière vous permet de quitter le jeu, une fenêtre de vérification s'ouvrant quand vous cliquer dessus.
Il y a néanmoins trois autres options. Vous pouvez tout d'abord régler le volume du son via la touche "R" ou en cliquant sur l'engrenage en bas à gauche. Une fenêtre s'ouvrant alors vous permettant de régler le volume à la hauteur que vous le souhaitez. Vous pouvez autrement, et il s'agit de la deuxième option, cliquer sur le haut-parleur en haut à droite, ce qui coupera instantanément le son.
Enfin, et c'est la dernière option, il s'agit du Pokédex accessible par clic sur l'image ou via la touche "P". Une fois dedans vous pouvez naviguer avec les flèches ou même encore en cliquant avec la souris, et voir tous les Pokémons disponibles.

Détail de l'interface de combat :

Durant un combat, 4 menu correspondant à 4 actions seront présent, il y'aura :

Attaquer : Permet d'accéder à 4 attaques différents que le Pokemon peut infliger.
Utiliser un Objet : Permet d'accéder à 6 objets différents que le joueur peut utiliser.
Changer de Pokemon : Permet de voir l'équipe du joueur et de sélectionner un Pokémon pour le faire rentrer sur le terrain.
Fuir : Permet de quitter le Combat.
Il est possible de revenir au menu de sélection des actions en préssant la touche 'B' du clavier.
Détail de l'interface de chargement ou création d'un joueur :

Création d'un nouveau joueur : Lance une interface permettant de rentrer le nom d'un joueur, puis ouvre le Pokedex afin que le joueur puisse sélectionner les 6 Pokemons de son équipe.
Lancer le combat : Lance directement le combat si une sauvegarde est trouvée, sinon lance l'interface de création de joueur.
Détail de l'interface du Pokedex :

Permet de naviguer dans la liste des Pokemon, afin de voir leur type ainsi que leur nom, mais limité au niveau du joueur.
Presser le bouton 'A' ou cliquer sur la fléche de retour afin de quitter ce menu.
Composition de notre archive :

Notre archive est composée très classiquement. A la racine on retrouve bien évidemment ce readme.txt ainsi que le makefile permettant de compiler.
Nous avons ensuite sept autres dossiers.
Un dossier "SFML" contenant notre bibliothèque graphique, un dossier "data" contenant toutes nos images, musiques et tout autres fichiers nécéssaires au jeu.
Un dossier "bin" contenant les .out, un dossier "obj" contenant les .o, un dossier "ncursesw" contenant notre bibliothèque pour l'affichage texte.
Enfin nous avons un dossier "doc" contenant toute notre documentation (notamment Doxygen) et surtout notre dossier "src" contenant tous notre code.
