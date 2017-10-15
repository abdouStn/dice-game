
/**
 *\file Joueur.h
 *\brief Classe Joueur
 *\author Abdoulaye Diallo
 *\version 1.0
 *\date 2014-04-20
 *
 * Definition de la classe joueur 
 *
 */ 




#ifndef _JOUEUR
#define _JOUEUR

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

/**
 * \class Joueur
 * \brief La classe Joueur definit l'ensemble des attributs et des actions que peut faire un joueur de dés primés
 */
class Joueur{
 private:
  static int compteur;  // permet de mettre a jour le numero du joueur.
  std::string nom; 
  int num_joueur;
  int nbDes; 
  int score;
  int sensDuJeu;   /* !< 1 sens des aiguilles d'une montre; 0 sens contraire*/
  int* resultats;  /* !< tableau de 6 pour chaque face de dés possible, tableau des occurances d'un lancé*/
  bool joueurReel;
  
 public:
 
 Joueur();
 
 /**
 * \brief Constructeur par defaut
 * instancie le joueur en initialisant les attributs par defaut
 */
  Joueur(int);
 
 /**
 * \brief Constructeur
 *    instancie le joueur en initialisant les attributs par les valeurs des parametre
 * \param name - nom du joueur
 * \param num - numero du joueur
 * \param des - nombre de dés initial
 */
  Joueur(int des, bool h);
 
 /**
 * \brief Constructeur par copie
 * instancie le joueur par copie d'une autre instance de joueur
 */
  Joueur(const Joueur &j);
 
 /**
 * \brief Destructeur 
 * detruit l'instance du joueur 
 */
  ~Joueur(); 
  
 /**
 * \fn std::string getNom() const
 * \brief renvoie le nom de l'instance joueur
 * \return renvoie le nom de l'instance joueur
 */
  std::string getNom() const;
 
 /**
 * \fn int getNum() const
 * \brief renvoie le numero de l'instance joueur
 * \return renvoie le numero de l'instance joueur
 */
  int getNum() const;
 
  /**
 * \fn int getNbDes() const
 * \brief renvoie le nombre de des de l'instance joueur
 * \return renvoie le nombre de des de l'instance joueur
 */
  int getNbDes() const;
  
   /**
 * \fn int getScore() const
 * \brief renvoie le score de l'instance joueur
 * \return renvoie le score de l'instance joueur
 */
  int getScore() const;
  
   /**
 * \fn int getSens() const
 * \brief renvoie le sens de l'instance joueur
 * \return renvoie le sens de l'instance joueur
 */
  int getSens() const;
  
   /**
 * \fn int* getResultats() const
 * \brief renvoie le tableau de resultat de l'instance joueur
 * \return renvoie le tableau de resultat de l'instance joueur
 */
  int* getResultats() const;
  
   /**
 * \fn bool getJoueurReel() const
 * \brief permet de connaitre le statut du joueur de l'instance joueur (virtuel ou réel )
 * \return renvoie le statut du joueur de l'instance joueur (virtuel ou réel )
 */
  bool getJoueurReel() const;
 
   /**
 * \fn void setNom(std::string n)
 * \brief permet de modifier le nom de l'instance joueur
 * \param n - nom de subtitution
 */
  void setNom(std::string n);
    
  /**
 * \fn void setNbDes(int d)
 * \brief permet de modifier le nombre de dés de l'instance joueur
 * \param n - numero de subtitution
 */
  void setNbDes(int d);
  
 /**
 * \fn void setScore(int s)
 * \brief permet de modifier le score de l'instance joueur
 * \param n - nombre de subtitution
 */
  void setScore(int s);
  
 /**
 * \fn void setSens(int s)
 * \brief permet de modifier le sens de l'instance joueur
 * \param s - numero de subtitution
 */
  void setSens(int s);
  
 /**
 * \fn void setResultats(int place, int valeur)
 * \brief permet de modifier les occurences des resultats de l'instance joueur
 */
  void setResultats();
  
  /**
 * \fn void setJoueurReel(bool j)
 * \brief permet de changer le statut d'un joueur (humain à virtuel ou inversement )
 * \param j - true pour un joueur Réel (humain)
 */
  void setJoueurReel(bool j);

  /**
 * \fn void lancerDes()
 * \brief Cette fonction permet de lancer les dés, elle modifie ainsi le score et le tableau des occurences des faces de dés
 */
  void lancerDes(ofstream&);  
  
 /**
 * \fn void retirerDes(int nbDesARetirer)
 * \brief Cette fonction permet de diminuer de "nbDesARetirer" au nombre de dés de l'instance joueur
 * \param nbDesARetirer - nombre de dés à retirer
 */ 
  void retirerDes(int nbDesARetirer,ofstream& );
  
 /**
 * \fn void ajouterDes(int nbDesAAjouter)
 * \brief Cette fonction permet d' augmenter de "nbDesAjouter" au nombre de dés de l'instance joueur
 * \param nbDesAAjouter - nombre de dés à Ajouter
 */ 
  void ajouterDes(int nbDesAAjouter, ofstream&);
  
 /**
 * \fn void ajouterPts(int nbPts)
 * \brief Cette fonction permet d' incrémenter le score de l'instance joueur
 * \param nbPts - nombre de points à ajouter
 */ 
  void ajouterPts(int nbPts,ofstream& ); 
  
 /**
 * \fn void retirerPts(int nbPts)
 * \brief Cette fonction permet de decrémenter le score de l'instance joueur
 * \param nbPts - nombre de points à ajouter
 */ 
  void retirerPts(int nbPts, ofstream&);
  
 /**
 * \fn void sePresenter()
 * \brief Cette fonction presente le joueur en affichant sonn nom, son numero, son score, son nombre de dés, le sens du jeu.
 */
  void sePresenter();
  
 /**
 * \fn void viderTab()
 * \brief Cette fonction remet toutes  les occurences de tableau de resultats à zero.
 */
  void viderTab();



}; 


#endif
