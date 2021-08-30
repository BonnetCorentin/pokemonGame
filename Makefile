G++ = g++ -std=c++11 -ggdb -Wall
LIBS_SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


#Partie du Makefile sur les .out 'éxecutables'#
SFMLCharger.out : SFMLCharger.o SFML.o Combat.o Personnage.o Pokemon.o Attaque.o Sac.o Objet.o
	$(G++) -o bin/$@ obj/SFMLCharger.o obj/SFML.o obj/Combat.o obj/Personnage.o obj/Pokemon.o obj/Objet.o obj/Attaque.o obj/Sac.o $(LIBS_SFML)

SFML.out : SFML.o Combat.o Personnage.o Pokemon.o Attaque.o Sac.o Objet.o
	$(G++) -o bin/$@ obj/SFML.o obj/Combat.o obj/Personnage.o obj/Pokemon.o obj/Objet.o obj/Attaque.o obj/Sac.o $(LIBS_SFML)

SFMLPokedex.out : SFMLPokedex.o SFML.o Combat.o Personnage.o Pokemon.o Attaque.o Sac.o Objet.o
	$(G++) -o bin/$@ obj/SFMLPokedex.o obj/SFML.o obj/Combat.o obj/Personnage.o obj/Pokemon.o obj/Objet.o obj/Attaque.o obj/Sac.o $(LIBS_SFML)

SFMLMenu.out : SFMLMenu.o SFMLCharger.o SFMLPokedex.o SFML.o Combat.o Personnage.o Pokemon.o Attaque.o Sac.o Objet.o
	$(G++) -o bin/$@ obj/SFMLMenu.o obj/SFMLCharger.o obj/SFMLPokedex.o obj/SFML.o obj/Combat.o obj/Personnage.o obj/Pokemon.o obj/Objet.o obj/Attaque.o obj/Sac.o $(LIBS_SFML)

Demo.out : Demo.o Combat.o Personnage.o Pokemon.o Attaque.o Sac.o Objet.o
	$(G++) -o bin/$@ obj/Demo.o obj/Combat.o obj/Personnage.o obj/Pokemon.o obj/Objet.o obj/Attaque.o obj/Sac.o -lncurses

Combat.out : Combat.o Personnage.o Pokemon.o Attaque.o Sac.o Objet.o
	$(G++) -o bin/$@ obj/Combat.o obj/Personnage.o obj/Pokemon.o obj/Objet.o obj/Attaque.o obj/Sac.o

Personnage.out : Personnage.o Pokemon.o Attaque.o Sac.o Objet.o
	$(G++) -o bin/$@ obj/Personnage.o obj/Pokemon.o obj/Sac.o obj/Objet.o obj/Attaque.o

Pokemon.out : Pokemon.o Objet.o Attaque.o
	$(G++) -o bin/$@ obj/Pokemon.o obj/Objet.o obj/Attaque.o

Sac.out : Sac.o Objet.o
	$(G++) -o bin/$@ obj/Sac.o obj/Objet.o

Attaque.out : Attaque.o
	$(G++) -o bin/$@ obj/Attaque.o

Objet.out : Objet.o
	$(G++) -o bin/$@ obj/Objet.o


#Partie du Makefile sur les .o
SFML.o : src/SFMLCombat/SFML.cpp
	$(G++) -c src/SFMLCombat/SFML.cpp -o obj/$@

SFMLCharger.o : src/SFMLCharger/SFMLCharger.cpp
	$(G++) -c src/SFMLCharger/SFMLCharger.cpp -o obj/$@

SFMLPokedex.o : src/SFMLPokedex/SFMLPokedex.cpp
	$(G++) -c src/SFMLPokedex/SFMLPokedex.cpp -o obj/$@

SFMLMenu.o : src/SFMLMenu/SFMLMenu.cpp src/SFMLPokedex/SFMLPokedex.h
	$(G++) -c src/SFMLMenu/SFMLMenu.cpp -o obj/$@

Demo.o : src/Demo.cpp
	$(G++) -c src/Demo.cpp -o obj/$@

Test.o : src/test.cpp src/Combat/Combat.cpp
	g++ -ggdb -Wall -c src/test.cpp -o obj/Test.o

main.o : src/main.cpp src/Combat/Combat.cpp
	g++ -ggdb -Wall -c src/main.cpp -o obj/main.o

Combat.o : src/Combat/Combat.cpp src/Combat/Combat.h
	$(G++) -c src/Combat/Combat.cpp -o obj/$@

Personnage.o : src/Personnage/Personnage.cpp src/Personnage/Personnage.h
	$(G++) -c src/Personnage/Personnage.cpp -o obj/$@

Pokemon.o : src/Pokemon/Pokemon.cpp src/Pokemon/Pokemon.h
	$(G++) -c src/Pokemon/Pokemon.cpp -o obj/$@

Sac.o : src/Sac/Sac.cpp src/Sac/Sac.h
	$(G++) -c src/Sac/Sac.cpp -o obj/$@

Attaque.o : src/Attaque/Attaque.cpp src/Attaque/Attaque.h
	$(G++) -c src/Attaque/Attaque.cpp -o obj/$@

Objet.o : src/Objet/Objet.cpp src/Objet/Objet.h
	$(G++) -c src/Objet/Objet.cpp -o obj/$@

clean :
	rm obj/*.o

veryclean : clean
	rm bin/*.out
