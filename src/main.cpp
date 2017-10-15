
#include"Liste.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

int main(int argc, char** argv)
{
	  srand(time(NULL)); 
	  int choixMode=0, round = 1, valWhile = 0, nbD = 0;
	  char rejouer = 'y';
	  char save = 'n'; 
	  string h = "--help";
	  string a = "--auteur";
	  ofstream journal("../fichiers/Journal", ios::out | ios::trunc);
	  
	  
	  if(argc > 1 && argv[1] == h )
	  {
	   system("cat ../fichiers/README");
	   return 0;
	  } 
	  else if(argc > 1 && argv[1] == a )
	  {
	   system("cat ../fichiers/Auteur");
	   return 0;
	  } 
	  
    do
    {
	  cout<<"\t (1) Jouer \n\t (2) quitter"<<endl;
	  
	  cin>>choixMode;
	  if (choixMode == 1)  // mode normal
	  {
	 	  cout<<"Voulez vous enregistrer la partie dans un journal? \n\t(o/n)"<<endl; 
	 	  cin >> save;
	 	  if(save == 'n' && journal) 
	 	  {
	 	  	
	 	  	journal.close();
	 	  	
	 	  } 
	 	  
	 	  cout<<"nombre de dés de la partie ?"<<endl;
	 	  cin>>nbD;
		  Joueur J1(nbD, false); // false pour dire qu'il s'agit pas d'un joueur réel.
		  Joueur J2(nbD, false);  
		  Joueur J3(nbD, false);
		 Joueur J7(nbD);
		  Joueur J4(nbD, false);
		  Joueur J5(nbD, false);
		  Joueur J6(nbD, false);
		  
		  Liste L;
		  L.ajoutDebut(&J1); L.ajoutFin(&J2);  L.ajoutFin(&J3); L.ajoutFin(&J4); L.ajoutFin(&J5); L.ajoutFin(&J6); L.ajoutFin(&J7);
		  
		  
		   cout<<"\x1B[2J"; /* cette ligne efface le terminal pour ne plus voir les ordres de compilation */ 
		    
		   Joueur *jCourant = L.tousLancer(journal);  // on cherche celui doit commencer
		   Joueur *jSuivant = NULL;// le joueur qui doit jouer apres
		   Joueur *jPrecedent = NULL;  // le joueur qui a joué avant 
		  
		   L.DefinirSensRotation(L.rechercheJoueur(*jCourant));   // on definit le sens du jeu;
		   
		   cout<<"\n\tC'est à "<<jCourant->getNom()<<" de commencer le jeu" <<endl;
		   if (journal) journal<<"\n\tC'est à "<<jCourant->getNom()<<" de commencer le jeu" <<endl;  // on ecrit dans le journal si possible

		   L.resetScore();  // remise a zero des scores

	
			cout<<"\n\n\t\t================ ATTENTION DEBUT DU JEU: ====================="<<endl;
			if(journal) journal<<"\n\n\t\t================ ATTENTION DEBUT DU JEU: ====================="<<endl;

		 while(!L.jeuFini() && valWhile != 1 )
		 {
			jCourant->lancerDes(journal);
	
	/* ===========================================================================================================  */

			if( (*(jCourant->getResultats()) != 0 ) && (jCourant->getNbDes() > 3) && (*(jCourant->getResultats())  == jCourant->getNbDes()) ) // s'il n'obtient que des 1
			{	
				cout<<"\n\tFace 1 obtenue: "<<*(jCourant->getResultats() )<<" fois"<<endl;
		
				jCourant->ajouterPts(3 * (*(jCourant->getResultats() ) ), journal );
				cout<<"\n\n\t\tJOLI COUP : JEU TERMINÉ "<<endl;
				if (journal) journal<<"\n\n\t\tJOLI COUP : JEU TERMINÉ "<<endl;
				
				valWhile = 1;
				break;
			}
			else if( (*(jCourant->getResultats()) != 0 ) ) 
			{
				cout<<"\n\tFace 1 obtenue: "<<*(jCourant->getResultats() )<<" fois"<<endl;
		
				cout<<"\t\tles 1 sont ignorés"<<endl;
				jCourant->retirerPts(*jCourant->getResultats(), journal);
			
			}
	

	/* ===========================================================================================================  */
	
	
			if(*(jCourant->getResultats() + 1) != 0)  // s'il obtient un 2
			{
				cout<<"\n\tFace 2 obtenue: "<<*(jCourant->getResultats() + 1)<<" fois"<<endl;		
				jCourant->ajouterPts(*(jCourant->getResultats() + 1), journal);
		
			}
	
	/* ===========================================================================================================  */
	
			if(*(jCourant->getResultats() + 2) != 0)   // s'il obtient un 3
			{
				cout<<"\n\tFace 3 obtenue: "<<*(jCourant->getResultats() + 2)<<" fois"<<endl;
		
				jCourant->ajouterPts(2*(*(jCourant->getResultats() + 2)), journal);
		
				if(!L.suivant(L.rechercheJoueur(*jCourant)) && L.precedent(L.rechercheJoueur(*jCourant)))  // s'il  est a la fin
				{
					L.leJoueur(L.premier())->ajouterPts(*(jCourant->getResultats() + 2), journal); // 1 point pour la tete 
					L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->ajouterPts(*(jCourant->getResultats() + 2), journal); // et un point pour le prec
						
				}
				else if(L.suivant(L.rechercheJoueur(*jCourant)) && !L.precedent(L.rechercheJoueur(*jCourant)))  // s'il  est au debut
				{
					L.leJoueur(L.dernier())->ajouterPts(*(jCourant->getResultats() + 2), journal);// 1 point pour la queue 
					L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->ajouterPts(*(jCourant->getResultats() + 2), journal); // et un point pour le suiv

				}
				else if(L.suivant(L.rechercheJoueur(*jCourant)) && L.precedent(L.rechercheJoueur(*jCourant))) // s'il a un prec et un suiv
				{
					L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->ajouterPts(*(jCourant->getResultats() + 2), journal); // 1 point pour le prec
					L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->ajouterPts(*(jCourant->getResultats() + 2), journal); // et un point pour le suiv
								//cout << "ok pour prec"<<endl;		
				}
				else
				{
								cout << "Erreur de position"<<endl;
								exit(1);
				}
			}
	

	/* ===========================================================================================================  */
			if(*(jCourant->getResultats() + 3) != 0)    // s'il obtient un 4
			{
				cout<<"\n\tFace 4 obtenue: "<<*(jCourant->getResultats() + 3)<<" fois"<<endl;
		
				if(*(jCourant->getResultats() + 3) % 2 == 1)  // si impair
				{
					cout<<"\t\tnb impair de la Face 4"<<endl;
					if(L.leJoueur(L.premier())->getSens() == 1) // on change le sens du Jeu.
					{
						L.modifSens(0);
					}
					else L.modifSens(1);
					cout<<"\t\t sens du jeu inversé"<<endl;
					if (journal) journal<<"\t\t sens du jeu inversé"<<endl;
			
				}
				
				jSuivant = L.leJoueurSuivant( L.rechercheJoueur(*jCourant),*(jCourant->getResultats() + 3) ); // cherche le k-ième joueur suivant
	
			}
			else // sinon definir quand le jSuivant
			{
				jSuivant = L.leJoueurSuivantNormal( L.rechercheJoueur(*jCourant));
			}

	/* ===========================================================================================================  */
	
			if(*(jCourant->getResultats() + 4) != 0)   // s'il obtient un 5
			{
				cout<<"\n\tFace 5 obtenue: "<<*(jCourant->getResultats() + 4)<<" fois"<<endl;
		
				if(!L.suivant(L.rechercheJoueur(*jCourant))) // s'il n'a pas de suivant
				{
					if(L.leJoueur(L.premier())->getScore() < L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->getScore() ) // alors si le premier est + petit que le precedent on lui donne les 5
					{
						L.leJoueur(L.premier())->ajouterPts( 5*(*(jCourant->getResultats() + 4)), journal ); 
					}
					else if ( L.leJoueur(L.premier())->getScore() > L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->getScore() )
					{
						L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->ajouterPts( 5*(*(jCourant->getResultats() + 4)) , journal); 	
					}
					else   // en cas d'egalite des 2 voisins 
					{
						if(jPrecedent)
						{
							 L.leJoueur(L.rechercheJoueur(*jPrecedent))->ajouterPts( 5*(*(jCourant->getResultats() + 4)), journal ); 	
						}
						else 
						{
							cout<<"\n\tPersonne n'a joué en dernier pour le moment"<<endl;
						}	 
					}
				}
		
				else if (!L.precedent(L.rechercheJoueur(*jCourant)))  // s'il n'a pas de precedent
				{
					if(L.leJoueur(L.dernier())->getScore() < L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->getScore() ) // alors si le dernier est + petit que le suivant on lui donne les 5
					{
						L.leJoueur(L.dernier())->ajouterPts( 5*(*(jCourant->getResultats() + 4)) , journal); 
					}
					else if ( L.leJoueur(L.dernier())->getScore() > L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->getScore() )
					{
						L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->ajouterPts( 5*(*(jCourant->getResultats() + 4)) , journal); 	
					}
					else   // en cas d'egalite des 2 voisins 
					{
						if(jPrecedent)
						{
							 L.leJoueur(L.rechercheJoueur(*jPrecedent))->ajouterPts( 5*(*(jCourant->getResultats() + 4)), journal ); 	
						}
						else 
						{
							cout<<"\n\tPersonne n'a joué en dernier pour le moment"<<endl;
						}	 
					}
				}
		
				else // s'il a un suivant et un precedent
				{
					if(L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->getScore() < L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->getScore() ) // alors si le precedent est + petit que le suivant on lui donne les 5
					{
						L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->ajouterPts( 5*(*(jCourant->getResultats() + 4)) , journal); 
					}
					else if ( L.leJoueur(L.precedent(L.rechercheJoueur(*jCourant)))->getScore() > L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->getScore() )
					{
						L.leJoueur(L.suivant(L.rechercheJoueur(*jCourant)))->ajouterPts( 5*(*(jCourant->getResultats() + 4)), journal ); 	
					}
					else   // en cas d'egalite des 2 voisins 
					{
						if(jPrecedent)
						{
							 L.leJoueur(L.rechercheJoueur(*jPrecedent))->ajouterPts( 5*(*(jCourant->getResultats() + 4)) , journal); 	
						}
						else 
						{
							cout<<"\n\tPersonne n'a joué en dernier pour le moment"<<endl;
						}	 
					}
				}
		
			}

	/* ===========================================================================================================  */
			if(*(jCourant->getResultats() + 5) != 0)   // s'il obtient un 6
			{
				cout<<"\n\tFace 6 obtenue: "<<*(jCourant->getResultats() + 5)<<" fois"<<endl;
				jCourant->retirerDes((*(jCourant->getResultats() + 5)),journal);   // les dés sont retirés du jeu
			}
	/* ===========================================================================================================  */
		
			jPrecedent = jCourant; 	// le courant devient le precedent 
			jCourant = jSuivant; // le suivant devient le courant

	
			cout<<"\n\t### score du round "<< round++<<endl; 
			L.tousAfficher();
			cout<<"\n\t### le joueur suivant sera "<<jCourant->getNom()<<endl;
			if(journal) journal<<"\n\t### le joueur suivant sera "<<jCourant->getNom()<<endl;
		
		
		}
		Joueur* gagnant = L.gagnant();
		cout<<"\n\n\tLe gagnant est "<< gagnant->getNom()<<" avec un Score de : "<<gagnant->getScore()<<endl;
		if(journal) journal<<"\n\n\tLe gagnant est "<< gagnant->getNom()<<" avec un Score de : "<<gagnant->getScore()<<endl;
		
		if(journal) journal.close();  // fermeture du fichier s'il est ouvert
	if( gagnant->getJoueurReel() ) L.topscore(gagnant->getNom(), gagnant->getScore()); // on save le gagnant dans le top 10 si c'est un humain.
	
		
	}

	else if(choixMode == 2)    // quitter le programme
	{ 
		cout<<"Merci d'avoir joué. A bientot"<<endl;
		return 0;//exit(0);
	}
	cout<<"\n\tVoulez vous rejouer ? (y/n)"<<endl;
		cin>>rejouer;
   }  while(rejouer != 'n')  ;

return 0;
}
