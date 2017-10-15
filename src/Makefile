CXX=g++
CXXFLAGS=-Wall -ansi -pedantic -g
LDFLAGS=
EXEC=jeuD   # création de l'exécutable

all: $(EXEC)

jeuD: Joueur.o Cellule.o Liste.o main.o
	$(CXX) -o $@ $^ $(LDFLAGS)

Joueur.o: Joueur.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Cellule.o: Cellule.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Liste.o: Liste.cpp
	 $(CXX) -o $@ -c $< $(CXXFLAGS)	   

main.o: main.cpp Joueur.h Cellule.h Liste.h
	$(CXX) -o $@ -c $< $(CFLAGS)

install: 
	./$(EXEC)

# suppression des fichiers temporaires
clean:
	rm -rf *.o

# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf $(EXEC)
