#include "Liste.h"
#include "Joueur.h"
#include<cstdlib>

typedef Cell* Place;

Liste::Liste(){
		tete = queue = NULL;
   		nbElement = 0;
   		}
   	


Liste::Liste(const Liste& L) // constructeur par copie;
{	
	cout << "appel de const par copie de liste"<< endl;
	nbElement = 0;
	tete = queue = NULL;
	Place p;
	
	for(L.premier();p!=NULL;p=L.suivant(p))
		ajoutFin(L.leJoueur(p));
}

Liste::~Liste()
{
		Place p = tete;
   		while(p!=NULL)
   		{
   		p = suivant(p);
   		//delete leJoueur(tete);
   		delete(tete);
   		tete = p;
   		}
   		cout<<"Liste detruite"<<endl;
}

Place Liste::premier() const {return tete;}
Place Liste::dernier() const {return queue;}

Place Liste::suivant(Place p) const { return p->getSuiv();}
Place Liste::precedent(Place p) const { return p->getPrec();}

void Liste::setSuivant(Place p, Place suiv) {p->setSuiv(suiv);}
void Liste::setPrecedent(Place p, Place prec) {p->setPrec(prec);} 

int Liste::tailleListe() const {return nbElement;}
Joueur* Liste::leJoueur(Place p) const{return p->getJoueur(); }
bool Liste::estVide() const { return tete == NULL;}

void Liste::ajoutApres(Place p,Joueur* j)
{
	Cell* elt = new Cell(j);
	if(p==NULL)
	   tete=queue=elt;
	else {
	   if(p==queue){
	   	setPrecedent(elt,p);
	   	setSuivant(p,elt);
	   	queue=elt;
	   }
	   else {
	   	setPrecedent(elt,p);
	   	setSuivant(elt,suivant(p));
	   	setPrecedent(suivant(p),elt);
	   	setSuivant(p,elt);
	   }
	} 
	nbElement++;
}

void Liste::ajoutAvant(Place p, Joueur* j)
{
	Cell* elt = new Cell(j);
	if(p==NULL)
		tete=queue=elt;
	else 
	    {
		if(p==tete)
		{
			setSuivant(elt,p);
			setPrecedent(p,elt);
			tete=elt;
		}
		else
		{
			setSuivant(elt,p);
			setPrecedent(elt,precedent(p));
			setSuivant(precedent(p),elt);
			setPrecedent(p,elt);
		}	
	      }
	nbElement++;
}

void Liste::ajoutDebut(Joueur* j)
{
	ajoutAvant(tete,j);
}

void Liste::ajoutFin(Joueur* j)
{
	ajoutApres(queue,j);
}

void Liste::vider()
{
	Place p = tete;
   		while(p!=NULL)
   		{
   		p = suivant(p);
   		delete(tete);
   		tete = p;
   		}
 	tete = queue = NULL;
 	nbElement = 0;  		
}

void Liste::enlever(Place p)
{
	if(nbElement == 1) {tete=queue=NULL; }
	else 
	  {
	  	if (p==tete) {
	  		tete=suivant(p);
	  		setPrecedent(tete,NULL);
	  	}
	  	else if (p==queue)
	  	{
	  		queue = precedent(p);
	  		setSuivant(queue,NULL);
	  	}
	  	else 
	  	{
	  		setSuivant(precedent(p),suivant(p));
	  		setPrecedent(suivant(p),precedent(p));
	  	}
	  }
	  nbElement--;
	  delete p;
}

bool Liste::jeuFini() const // false = 0; true = 1;
{	
	bool res = false;
	Place p= tete;
	while (p!= NULL && (leJoueur(p)->getNbDes() > 0))
	{
		p=suivant(p);
	}
	if(p!=NULL) res = true;
return res;
}

/*void Liste::afficher() const
{
	cout<<"\n(";
	Place p = premier();
	while(p!=NULL)
	{
		cout<<" ";
		cout<<leJoueur(p)->getNom()<<" :" <<leJoueur(p)->getNbDes()<<" dés";
		p=suivant(p);}
		cout<<")"<<endl;
	
}*/

Place Liste::rechercheJoueur(Joueur& j) const
{
	Place p = premier();
	while(p!=NULL && leJoueur(p)->getNom() != j.getNom() ) 		
	{
		p=suivant(p);
	}
return p;
}

void Liste::modifSens(int s)
{	
	Place p= tete;
	while(p!=NULL)
	{
		leJoueur(p)->setSens(s);
		p=suivant(p);
	}		
}

Joueur* Liste::leJoueurSuivant(Place j,int i) // si on a un 4
{
	Place p = j;
	while(i>0)
	{
		if(leJoueur(j)->getSens() == 1)
		{
			if(suivant(p) )
			{
				p=suivant(p);	
				i=i-1;
			}
			else 
			{
				p=tete;
				i=i-1;
			}
		}
		else
		{
			if(precedent(p) )
			{
				p=precedent(p);	
				i=i-1;
			}
			else 
			{
				p=queue;
				i=i-1;
			}
		}
	}	
return leJoueur(p);
}

Joueur* Liste::leJoueurSuivantNormal(Place j) // si on a pas de 4 comme resultat
{
	Place p = j;
	if(leJoueur(j)->getSens() == 1)
		{
			if(suivant(p) )
			{
				p=suivant(p);				
			}
			else 
			{
				p=tete;
			}
		}
		else
		{
			if(precedent(p) )
			{
				p=precedent(p);					
			}
			else 
			{
				p=queue;				
			}
		}
	return leJoueur(p);
}

Joueur* Liste::gagnant()
{
	Place p = tete;
	Place win = tete;
	int bestScore = leJoueur(tete)->getScore();
	while(p != NULL)
	{
		if(leJoueur(p)->getScore() > bestScore) 
		{
			bestScore = leJoueur(p)->getScore();
			win = p;
		}
		p = suivant(p);  
	}
	return leJoueur(win);
}
void Liste::DefinirSensRotation(Place j) // on definit le joueur suivant dans tous les cas si on n'a pas de 4 en resultat
{
	
	if(precedent(j) && suivant(j) ) // s'il y'a prec et suiv
	{
		if(leJoueur(precedent(j))->getScore() > leJoueur(suivant(j))->getScore())    
		{
			modifSens(0);
			cout<<"\n\tSens contraire des aiguilles d'une montre"<<endl;
						
		}
		else 
		{
			modifSens(1);
			cout<<"\n\tSens des aiguilles d'une montre"<<endl;
		}
	}
	else if(precedent(j) && !suivant(j) ) // si le j est a la fin
	{
		if(leJoueur(precedent(j))->getScore() > leJoueur(premier())->getScore())
		{
			modifSens(0);
			cout<<"\n\tSens contraire des aiguilles d'une montre"<<endl;			
		}
		else 
		{
			modifSens(1);
			cout<<"\n\tSens des aiguilles d'une montre"<<endl;			
		}
	}
	else if(!precedent(j) && suivant(j) ) // si le j est au debut
	{
		if(leJoueur(queue)->getScore() > leJoueur(suivant(j))->getScore())
		{
			modifSens(0);
			cout<<"\n\tSens contraire des aiguilles d'une montre"<<endl;					
		}
		else 
		{
			modifSens(1);
			cout<<"\n\tSens des aiguilles d'une montre"<<endl;					
		}
	}
	else
	{
		cout<<"Erreur de position"<<endl;
		exit(1);
	}
	
}

Joueur* Liste::tousLancer(ofstream& journal)
{
	Place jCourant;// = NULL;   // place du joueur courant
	Place p = tete;
	Liste l;
	
	while(p!=NULL)
	{
		leJoueur(p)->lancerDes(journal);
	
		p = suivant(p);
	}
					
  
	int k = occurence(jCourant, l);  
       	
	if(k > 1) // test si pas d'occurence du plus grand score 
       	
	{
			cout <<"\t y 'a occurance on relance entre les concernés"<< endl;
		
		l.tousLancer(journal);	 
		
	}
	
	if(tailleListe() > 0)  // definition ordre du commencement du jeu
	{
		if(jCourant == tete)
		{	
			if(leJoueur(suivant(jCourant))->getScore() >= leJoueur(dernier())->getScore() ) 
			{
				leJoueur(jCourant)->setSens(1);  // sens des aiguilles 
			}
			else
			{
				leJoueur(jCourant)->setSens(0);
			}
		}
		else if(jCourant == queue)
		{
			if(leJoueur(tete)->getScore() >= leJoueur(precedent(jCourant))->getScore()) 
			{
				leJoueur(jCourant)->setSens(1);  
			}
			else
			{
				leJoueur(jCourant)->setSens(0);
			}
		} 
		else
		{
			if(leJoueur(suivant(jCourant))->getScore() >= leJoueur(dernier())->getScore() ) 
				{
					leJoueur(jCourant)->setSens(1);  // sens des aiguilles 
				}
				else
				{
					leJoueur(jCourant)->setSens(0);
				}
		}
	}
	
return leJoueur(jCourant);
}



int Liste::occurence(Place& jCourant, Liste& l) // renvoie la liste des joueurs si egalite de score sinon null. //TODO plante parfois
{	
	int res=1;
	int n = leJoueur(tete)->getScore();
	Place p = suivant(tete);
	
	//Joueur* tableau = new Joueur[6];
	l.ajoutFin(leJoueur(tete));
	jCourant = tete;
	
	while(p!=NULL)
	{
		
		if (leJoueur(p)->getScore() > n)
		{
			n = leJoueur(p)->getScore();
			l.vider();
			l.ajoutFin(leJoueur(p));
			jCourant = p;
			res = 1;
						
		}
		else if(leJoueur(p)->getScore() == n)  // en cas d'egalité
		{
			l.ajoutFin(leJoueur(p));
			res++;
		}
		
		p = suivant(p);
	}
return res;	
}


void Liste::tousAfficher() const
{
	Place p = tete;
	while(p!=NULL)
	{
		cout <<leJoueur(p)->getNom()<<" ::  Score : "<< leJoueur(p)->getScore() <<"\tnb Des: "<<leJoueur(p)->getNbDes()<<" Sens: "<<leJoueur(p)->getSens() << endl;
		p = suivant(p);
	}
	
}

void Liste::resetScore()
{
	Place p = tete;
	while(p!=NULL)
	{
		leJoueur(p)->setScore(0);
		leJoueur(p)->setNbDes(leJoueur(p)->getNbDes());
		leJoueur(p)->viderTab();
		
		p= suivant(p);
	}
}



void Liste::topscore(string pseudo, int score)
{ 						 // Idée générale : parcourir le fichier existant(en le copiant dans un fichier
    ifstream lecture("../fichiers/top10.txt"); // temporaire jusqu'à tomber sur un score plus petit que le score donné en paramètre. On ecrit
    ofstream ecriture("../fichiers/temp.txt"); // alors ce score et on continue le parcours du fichier initial(qui était bien classé) jusqu'à l'avant
    size_t c=0; bool ecrit=0; 		     // derniere ligne, histoire de garder 10 scores uniquement. On finir par écraser le fichier initial.
    if(lecture && ecriture){
        int s; string psd, ligne;
        do {
            lecture >> s;
            if (score >= s && !ecrit){
                ecriture << score << " " << pseudo << endl;
                cout<<"\n\tBravo "<< pseudo <<" Vous êtes inscrit dans le top 10 des scores"<<endl;
                c++;
                ecrit=1;
            }
            lecture >> psd;
            if (s){
            ecriture << s << " " << psd << endl;
            c++;
            }
        } while (c<10 && getline(lecture,ligne));
 
 
        ifstream lecture2("../fichiers/temp.txt");
        ofstream ecriture2("../fichiers/top10.txt");
        if (lecture2 && ecriture2){
            string ligne;
            while (getline(lecture2, ligne)){
                ecriture2 << ligne << endl;
            }
        }
        else{
            cerr << "ERREUR: impossible d'ouvrir le ficher top10.txt ou espace disque insuffisant.(impossibilité de créer un fichier temporaire)" << endl;
            exit(1);
        }
    }
    else{
        cerr << "ERREUR: impossible d'ouvrir le fichier top10.txt ou le fichier temporaire." << endl;
        exit(1);
    }
    lecture.close();
    ecriture.close();
    if(remove("../fichiers/temp.txt")){
        cerr << "Echec de la destruction du fichier temp.txt" << endl;
    }
}
