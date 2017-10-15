#include "Cellule.h"




Cell::Cell() : joueur(NULL),suiv(NULL),prec(NULL){}
Cell::Cell(Joueur* j) : joueur(j),suiv(NULL),prec(NULL){}

Joueur* Cell::getJoueur() const {return joueur;}
Cell* Cell::getPrec() const {return prec;}
Cell* Cell::getSuiv() const {return suiv;}

void Cell::setJoueur(Joueur* j ) { joueur=j;}
void Cell::setPrec(Cell* c) {prec=c;}
void Cell::setSuiv(Cell* c) {suiv=c;}

ostream& Cell::afficher(ostream& os) const { return os<<joueur->getNom()<<" "<<prec<<" "<<suiv<<endl; }
ostream& operator<<(ostream& os, const Cell& c){ return c.afficher(os);}

