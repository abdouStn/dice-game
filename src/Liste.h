
/**
 *\file Liste.h
 *\brief Classe Liste
 *\author Abdoulaye Diallo
 *\version 1.0
 *\date 2014-04-20
 *
 * Definition de la classe Liste 
 *
 */ 

#ifndef _LISTE
#define _LISTE

#include"Cellule.h"
#include <vector>

using namespace std;

/**
 * \class Liste
 * \brief La classe Liste (doublement chainée) regroupe un certain nombre de cellule de Joueur (qu' on appelera Place).</br>
 * Elle contient les attributs tete, queue et nbElement puis les operations ensemblistes
 */
class Liste{
     
     public:   	
   	
   	typedef Cell* Place;  /* !< on encapsule *Cell. Comme ça on cache la manipulation "affreuse" des pointeurs */
   	
   	/**
	 * \brief Constructeur par defaut
	 * instancie la liste de joueurs en initialisant la tete et la queue de liste à NULL et le nombre d'elements à 0
	 */
   	Liste();
   	
   	Liste(int nbJoueur);
   	
   	/**
	 * \brief Constructeur par copie
	 * instancie la liste de joueurs par copie d'une autre
	 */
   	Liste(const Liste& L); 
   	
   	/**
	 * \brief Destructeur 
	 * detruit l'instance de la liste de joueurs tout en liberant toute allocation dynamique 
	 */
   	~Liste();
   	
   	   	/*===============================getters  ===========================***/
   	
   	/**
	 * \fn Place premier()const
	 * \brief Tete de la liste de joueur
 	 *  C'est une methohe constante puisqu'elle ne modifie pas l'instance courante
	 * \return renvoie la Tete de la liste de joueur
	 */
   	Place premier()const;
	
	/**
	 * \fn Place dernier()const
	 * \brief Queue de la liste de joueur
	 *  C'est une methohe constante puisqu'elle ne modifie pas l'instance courante
	 * \return renvoie la queue de la liste de joueur
	 */
	Place dernier()const ;
	
	/**
	 * \fn int tailleListe()const
	 * \brief ta taille la liste de joueur
	 *  C'est une methohe constante puisqu'elle ne modifie pas l'instance courante
	 * \return renvoie la taille de la liste de joueur
	 */
	int tailleListe()const ;
	
	/**
	 * \fn Place suivant(Place p)const
	 * \brief suivant de la cellule p dans la liste de joueur
	 *  C'est une methohe constante puisqu'elle ne modifie pas l'instance courante
	 * \return renvoie la Place du suivant de la cellule p dans la liste de joueur
	 */
	Place suivant(Place p)const;
	
	/**
	 * \fn Place suivant(Place p)const
	 * \brief suivant de la cellule p dans la liste de joueur
	 *  C'est une methohe constante puisqu'elle ne modifie pas l'instance courante
	 * \return renvoie la Place du suivant de la cellule p dans la liste de joueur
	 */
  	Place precedent(Place p)const;
  	
  	/**
	 * \fn Joueur* leJoueur(Place p)const
	 * \brief le Joueur à la cellule p dans la liste de joueur
	 *  C'est une methohe constante puisqu'elle ne modifie pas l'instance courante
	 * \return renvoie un pointeur vers le joueur situé à la cellule p dans la liste de joueur
	 */
  	Joueur* leJoueur(Place p)const;
  	
  	/**
	 * \fn bool estVide() const
	 * \brief La liste est elle vide?
	 *  C'est une methohe constante puisqu'elle ne modifie pas l'instance courante
	 * \return true si la liste est vide et false sinon
	 */
  	bool estVide() const;
  	
  	/**
	 * \fn void ajoutApres(Place,Joueur* )
	 * \brief Ajouter un joueur dans la liste apres celui situé a la Place p 
	 * \param p - Cellule de reference
	 * \param j - joueur à ajouter
	 */
  	void ajoutApres(Place,Joueur* );
	
	/**
	 * \fn void ajoutAvant(Place, Joueur*)
	 * \brief Ajouter un joueur dans la liste avant celui situé a la Place p 
	 * \param p - Cellule de reference
	 * \param j - joueur à ajouter
	 */
	void ajoutAvant(Place, Joueur*);
	
	/**
	 * \fn void ajoutDebut(Joueur*)
	 * \brief Ajouter un joueur au debut de la liste 
	 * \param j - joueur à ajouter
	 */
	void ajoutDebut(Joueur*);
	
	/**
	 * \fn void ajoutFin(Joueur*)
	 * \brief Ajouter un joueur a la fin de la liste 
	 * \param j - joueur à ajouter
	 */
	void ajoutFin(Joueur*);
  	
  	/**
	 * \fn void vider()
	 * \brief vide la liste et libère les allocations de memoire 
	 */
  	void vider();
  	
  	/**
	 * \fn void enlever(Place p)
	 * \brief Retire un joueur de la liste 
	 * \param p - Place du joueur à enlever
	 */
  	void enlever(Place p);
  	
  	/**
	 * \fn bool jeuFini() const
	 * \brief Verifie qu'aucun des joueur n'a un nombre de dés inferieur ou égal a 0. sinon le jeu est fini 
	 * \return renvoie true si le jeu est fini sinon false
	 */
  	bool jeuFini() const;
  	
  	/**
	 * \fn Place rechercheJoueur(Joueur&) const
	 * \brief Recherche un joueur et renvoie sa Place dans la liste 
	 * \param j - le joueur a rechercher
	 * \return renvoie sa Place dans la liste 
	 */
  	Place rechercheJoueur(Joueur&) const;
  	
  	/**
	 * \fn void modifSens(int s)
	 * \brief modifie le sens du jeu en fonction de l'etat d'avancement du jeu
	 * \param s - le sens a definir (1 - sens des aiguilles d'une montre  2 - sens contraire )
	 */
  	void modifSens(int s);
 	
 	/**
	 * \fn void DefinirSensRotation(Place j)
	 * \brief Elle definie au debut du jeu le sens du jeu en fonction des scores des 2 voisins du joueur courant à l'issu du premier lancé de dés
	 * \param j - Le joueur courant
	 */
 	void DefinirSensRotation(Place j); 
  	
  	/**
	 * \fn Joueur* leJoueurSuivantNormal(Place j)
	 * \brief permet de definir celui qui doit jouer juste apres le joueur courant au debut de jeu 
	 * \param j - le joueur courant
	 * \return Renvoie un pointeur vers le joueur suivant 
	 */
  	Joueur* leJoueurSuivantNormal(Place j); // si on a pas de 4 comme resultat
  	
  	/**
	 * \fn Joueur* leJoueurSuivant(Place j,int i)
	 * \brief permet de definir celui qui doit jouer en fonction du nombre de face 4 obtenu par le joueur courant 
	 * \param j - le joueur courant
	 * \param i - nombre de face 4 obtenue et donc nombre de fois qu'il faut faire suivre le joueur suivant
	 * \return Renvoie un pointeur vers le joueur suivant correspondant
	 */
  	Joueur* leJoueurSuivant(Place j,int i);
  	
  	/**TODO
	 * \fn int occurence(Place&, Liste& l)
	 * \brief Determine le nombre d'occurence de score les plus élévés au premier round 
	 * \param p - le joueur courant
	 * \param i - nombre de face 4 obtenue et donc nombre de fois qu'il faut faire suivre le joueur suivant
	 * \return le nombre d'occurence
	 */
  	int occurence(Place&, Liste& l);
    	
    	/**
	 * \fn Joueur* tousLancer()
	 * \brief fait lancer à chaque joueur ses dés. Elle appelle la methode lancerDes() de la classe Joueur
	 * \return Renvoie en meme temps le joueur qui doit jouer c.a.d le lauréat
	 */
    	Joueur* tousLancer(ofstream& );
  	
  	/**
	 * \fn void tousAfficher() const
	 * \brief Affiche le profil de chacun des joueurs
	 */
  	void tousAfficher() const;
  	
  	/**
	 * \fn void resetScore()
	 * \brief Remet les scores des joueur a zero
	 */
  	void resetScore();
  	
  	/**
	 * \fn void topscore(string pseudo, int score)
	 * \brief Permet d'inscrire le gagnant de la partie dans le fichier des top 10 si son score le permet et si c'est un humain
	 */
  	void topscore(string pseudo, int score);
  	
  	/**
	 * \fn Joueur* gagnant()
	 * \brief permet de returner le joueur gagant de la partie
	 * \return Renvoie le joueur ayant le score le plus élévé.
	 */
  	Joueur* gagnant();
  	
  private:
	Place tete;
	Place queue;
	int nbElement;

	void setSuivant(Place p, Place suiv); 
	void setPrecedent(Place p, Place prec);
};
#endif
