
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
 class lirefichier
{
private:
	string NomFichier;
public:
	void Ecrire(string mot);// ecrit un mot saisie par l''utilisateur dans un fichier d�finie
	void suppr(); // supprime une ligne qui a �tait choisie par l'utilisateur dans un fichier d�finie
	void afficher_mot(); // affiche les ligne une a une
	string mothasard(); // chosie al�atoirement une ligne dans un fichier d�finie puis stock le premier mot
	lirefichier(string NomFichier);//constructeur
	~lirefichier();//destructeur
};

