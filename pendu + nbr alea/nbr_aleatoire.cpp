#include "nbr_aleatoire.h"
using namespace std;

int nbr_aleatoire::choix_nombre()
{
	if (i == 0)
	{
	srand(time(NULL));
	nbr_alea = (rand() % (this->max - this->min));
	i++;
	}
	return nbr_alea;
}

bool nbr_aleatoire::test()
{
	std::cin >> this->nbr_choisie;
	coup++;
	if (choix_nombre() > nbr_choisie)
	{
		std::cout << "plus haut" << std::endl;
		return false;
	}
	if (choix_nombre() < nbr_choisie)
	{
		std::cout << "plus bas" << std::endl;
		return false;
	}
	if (choix_nombre() == nbr_choisie)
	{
		return true;
	}
}

nbr_aleatoire::nbr_aleatoire(int m, int n)
{
	this->max = m;
	this->min = n;

}

void nbr_aleatoire::init_difficulter(int diff,int nbmin,int nbmax)
{
	this->difficulter = diff;
	if (this->difficulter == 1)
	{
		this->max = 10;
		this->min = 0;
	}
	if (this->difficulter == 2)
	{
		this->max = 100;
		this->min = 0;
	}
	if (this->difficulter == 3)
	{
		this->max = 1000;
		this->min = 0;
	}
	if (this->difficulter == 4)
	{
		this->max = 10000;
		this->min = 0;
	}
	if (this->difficulter == 5)
	{
		this->max = nbmax;
		this->min = nbmin;
	}
}

void nbr_aleatoire::lancement()
{
	bool result = false;
	cout << "------------------------------------------BIENVENUE SUR LE JEU DU JUSTE PRIX------------------------------------------" <<
		endl << "regle a respecter" <<
		endl << "1 !!!les accents aisi que les lettres sont interdit sinon ca va faire bugger le jeu!!!" << endl;
	cout << "choisie une difficulter:" << endl <<
		endl << "1-FACILE(chiffre de 0 a 10)" <<
		endl << "2-CLASSIQUE(chiffre de 0 a 100)" <<
		endl << "3-DIFFICILE(chiffre de 0 a 1000)" <<
		endl << "4-IMPOSSIBLE(chiffre de 0 a 10000)" <<
		endl << "5-choix (de quoi a quoi)" <<
		endl;
	cin >> difficulter;
	if (difficulter == 5)
	{
		cout << "entrer le minimum puis le maximum" << endl;
		cin >> min;
		cin >> max;
		init_difficulter(difficulter, min, max);

	}
	else
	{
		init_difficulter(difficulter);
	}
	choix_nombre();
	do
	{
		result = test();
	}
	while (result == false);
	cout << "GG tu as trouver le mot en " << coup << " de coups" << endl;
}

nbr_aleatoire::~nbr_aleatoire()
{
	
}
