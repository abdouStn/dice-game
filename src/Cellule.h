
/**
 *\file Cellule.h
 *\brief Classe Cellule
 *\author Abdoulaye Diallo
 *\version 1.0
 *\date 2014-04-20
 *
 * Definition de la classe Cellule necessaire pour la construction d'une Liste 
 *
 */ 

#ifndef _CELL
#define _CELL

#include"Joueur.h"
#include<iostream>
using namespace std;

/**
 * \class Cellule
 * \brief La classe Cellule contient un pointeur sur un joueur, un autre sur son suivant et un dernier sur son precedent.Elle permet l'implantation d'une Liste de Joueur.
 */
class Cell {
    private:
	Joueur* joueur;
	Cell* suiv;
	Cell* prec;
    public:
    	
    	/**
	 * \brief Constructeur par defaut . Tous les pointeurs à NULL
	 */
    	Cell();
    	
    	/**
	 * \brief Constructeur. Le joueur est initialisé
	 * \param j - le joueur à initialiser
	 */
    	Cell(Joueur*);
    	
    	/**
	 * \fn Joueur* getJoueur() const
	 * \brief renvoie un pointeur vers le joueur contenu dans la cellule
	 * \return renvoie un pointeur vers le joueur contenu dans la cellule
	 */
    	Joueur* getJoueur() const;
    	
    	/**
	 * \fn Cell* getSuiv() const
	 * \brief renvoie un pointeur vers le suivant du joueur contenu dans la cellule
	 * \return renvoie un pointeur vers le suivant du joueur contenu dans la cellule
	 */
    	Cell* getSuiv() const;
    	
    	/**
	 * \fn Cell* getPrec() const
	 * \brief renvoie un pointeur vers le precedent du joueur contenu dans la cellule
	 * \return renvoie un pointeur vers le precedent du joueur contenu dans la cellule
	 */
    	Cell* getPrec() const;
    	
    	
    	/**
	 * \fn void setJoueur(Joueur*)
	 * \brief permet de modifier le joueur contenu dans la cellule
	 * \param j - parametre à modifier
	 */
    	void setJoueur(Joueur*);
    	
    	/**
	 * \fn void setSuiv(Cell*)
	 * \brief permet de modifier le suivant du joueur contenu dans la cellule
	 * \param c - parametre à modifier
	 */
    	void setSuiv(Cell*);
    	
    	/**
	 * \fn void setPrec(Cell*)
	 * \brief permet de modifier le precedent du joueur contenu dans la cellule
	 * \param c - parametre à modifier
	 */
    	void setPrec(Cell*);
	ostream& afficher(ostream&) const;	
	};
	ostream& operator<<(ostream&, const Cell&);
#endif
