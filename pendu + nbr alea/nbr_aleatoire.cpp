#include "nbr_aleatoire.h"

int nbr_aleatoire::choix_nombre()
{
	srand(time(NULL));
	int nbr_alea = (rand() % (this->max - this->min));
	return nbr_alea;
}

bool nbr_aleatoire::test()
{
	std::cin >> this->nbr_choisie;
	if (choix_nombre() < nbr_choisie)
	{
		std::cout << "plus haut" << std::endl;
		return false;
	}
	if (choix_nombre() > nbr_choisie)
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

void nbr_aleatoire::init_difficulter(int diff)
{
	this->difficulter = diff;
	if (this->difficulter == 1)
	{
		this->max = 10;
		this->min = 0;
	}
	if (this->difficulter == 2)
	{

	}
	if (this->difficulter == 3)
	{

	}
	if (this->difficulter == 4)
	{

	}
	if (this->difficulter == 5)
	{

	}
}

nbr_aleatoire::~nbr_aleatoire()
{

}
