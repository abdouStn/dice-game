/**
 *\file Joueur.cpp
 *\brief Implementation de la classe Joueur
 *\author Abdoulaye Diallo
 *\version 1.0
 *\date 2014-04-20
 */


#include <cstdlib>  // pour rand
#include"Joueur.h"
#include <sstream>

using namespace std;

int Joueur::compteur = 0;  // on initialise le compteur d'instance à 0

Joueur::Joueur(): nom("vide"),num_joueur(++compteur),nbDes(0),score(0),sensDuJeu(1),joueurReel(false){
						resultats = new int[6];
						for(size_t i=0;i<6;i++) resultats[i] = 0;	
						}

Joueur::Joueur(int nD): num_joueur(++compteur),nbDes(nD), score(0),sensDuJeu(1),joueurReel(true){       // pour un joueur réel;
				cout<< "\nUn joueur réel permet de jouer en mode debug\nsaisir le pseudo du joueur humain " << num_joueur << endl;
				cin >> nom;
								
				resultats = new int[6];
				for(size_t i=0;i<6;i++) resultats[i]=0;   								
				}
Joueur::Joueur(int des, bool b): num_joueur(++compteur),nbDes(des),score(0),sensDuJeu(1),joueurReel(b){
						string prefixe = "ordi";
						stringstream name;
						name << prefixe << num_joueur;
						nom = name.str();
						resultats = new int[6];
						for(size_t i=0;i<6;i++) resultats[i] = 0;
						cout<<"Création de l'instance du joueur virtuel "<<nom<<endl;	
						}
 Joueur::Joueur(const Joueur &j)
  {
  	cout << "Appel du constructeur par copie de Joueur"<< endl;
  }

Joueur::~Joueur(){
		delete[] resultats;
		--compteur;		
		cout<<"destruction de l'instance du joueur "<<nom<<endl ;}

string Joueur:: getNom() const {return nom;}
int Joueur::getNum() const {return num_joueur;}   
int Joueur::getNbDes() const {return nbDes;} 
int Joueur::getScore() const {return score;} 
int Joueur::getSens() const {return sensDuJeu;}		  
int* Joueur::getResultats() const{return resultats;} 
bool Joueur::getJoueurReel() const{return joueurReel; }

void Joueur::setNom(string n){nom = n;}
void Joueur::setNbDes(int d) {nbDes = d;} 
void Joueur::setScore(int s) {score = s;} 
void Joueur::setJoueurReel(bool j) { joueurReel = j; }
void Joueur::setSens(int s) {if(s==1 || s==0 ) sensDuJeu = s; else cout<<"Erreur de sens. valeur possible 1 ou 0"<<endl;}
void Joueur::setResultats(){ 
				int choix = 0, s = 0;
			
			cout<<"Entrer vos combinaison "<<nom<<" vous avez "<<nbDes<<" dés"<<endl;	
			do{
				s = 0;	
			for(size_t i = 1; i <= 6; i++)
				{
					
					cout<<"Entrez le nombre d'occurence de la face "<<i<<endl;
					cin>>choix;
					s+=choix;
					cout<<"reste : "<<nbDes - s<<" dés"<<endl;
					if(choix <= nbDes && choix >=0 ) resultats[i-1] = choix;
					else cout<<"Entrée invalide"<<endl;
				}
				if(s != nbDes) {viderTab(); cout<<"Vous n'avez pas respecté le nb de dés. vous devez reprendre"<<endl;}
			   }while(s != nbDes);
			}

void Joueur::retirerDes(int nbDesARetirer,ofstream& journal)
{
	nbDes -= nbDesARetirer; 
	cout<<"\n\t\t"<< nbDesARetirer<<" dés retirés pour "<<nom<<endl;
	if(journal) journal<<"\n\t\t"<< nbDesARetirer<<" dés retirés pour "<<nom<<endl;
}

void Joueur::ajouterDes(int nbDesAAjouter,ofstream& journal)
{
	nbDes += nbDesAAjouter; 
	cout<<"\n\t\t"<< nbDesAAjouter<<" dés ajoutés pour "<<nom<<endl;
	if(journal) journal<<"\n\t\t"<< nbDesAAjouter<<" dés ajoutés pour "<<nom<<endl;
}

void Joueur::retirerPts(int nbPts,ofstream& journal)
{
	score -= nbPts;
	cout<<"\n\t\t-"<<nbPts<<" pts pour "<<nom<< endl;
	if(journal) journal<<"\n\t\t-"<< nbPts<<" pts pour "<<nom<<endl;
}

void Joueur::ajouterPts(int nbPts,ofstream& journal)
{
	score += nbPts; 
	cout<<"\n\t\t+"<<nbPts<<" pts pour "<<nom<< endl;
	if(journal) journal<<"\n\t\t+"<<nbPts<<" pts pour "<<nom<< endl;
}

void Joueur::sePresenter()
{
	cout<<endl<<nom<<" : => num de joueur: "<<num_joueur<<" , des restants: "<<nbDes<<" , score : "<< score<<"sens : "<<sensDuJeu<<endl;
}


void Joueur::viderTab()
{
	for(size_t i=0;i<6;i++) resultats[i]=0;
}

void Joueur::lancerDes(ofstream& journal)
{	
	size_t j = 0;
	viderTab();
	int* tab = new int[nbDes];   // tableau de lancées aleatoires 
	
	if(!joueurReel)
	{
	for(size_t i=0;i<(size_t)nbDes;i++)
		{
			tab[i] = rand()%(7-1)+1;   //verdique
			score+=tab[i];
		}
			
	for(size_t i=0;i<(size_t)nbDes;i++)
		{
			j=tab[i]; 
	
			resultats[j-1]+=1;   // incremenetation des occurances
		 }
	}
	else setResultats();
		      
	
	cout<< endl << endl << nom <<" a lance ses "<< nbDes<<" des."<<"\t"<<" Resultats : ";
	if(journal) journal<< endl << endl << nom <<" a lance ses "<< nbDes<<" des."<<"\t"<<" Resultats : ";
	
	for(size_t i=0;i<6;i++) {
			 cout<<resultats[i]<<" ";
			 if(journal) journal<<resultats[i]<<" ";
			  }
	    // cout<<" Total: "<<score<<endl;
	  		
	  		
	delete[] tab;
}

/*Liste L;
		int nbJ = 0, nbJR = 0,nbD = 0;
		int k = 0;
		cout<<"Quelle est le nombre de joueur Total ?" <<endl;
		cin>> nbJ;
		cout<<"dont combien de joueur réel (humain) ?"<<endl;
		do{
		cin>> nbJR;
		} while(nbJR > nbJ);
		
		cout<<"nombre de Dés initial de cette partie ? "<<endl;
		cin>> nbD;
		stringstream name;
		string nom;
		for(k=1; k<= nbJR; k++)
		
		
		Joueur* joueur = NULL;
		 joueur = new Joueur[nbJR];
 
		for(int i=1; i<=nbJR; i++)
		{
		joueur[i-1] = new Joueur(nbD);// JOUEUR HUMAIN
		//L.ajoutFin(&j[i-1]);
		}
		
		//cout<< J[0].getNom()<<endl;
		if(nbJR < nbJ )
		{
			for(k=1; k<= (nbJ-nbJR); k++)
			{
		 	L.ajoutFin(new Joueur(nbD,false));  // joueur machine
			}
		}
		L.tousAfficher();
		
		
		cout<<"mode debug indisponible"<<L.tailleListe()<<endl;*/
