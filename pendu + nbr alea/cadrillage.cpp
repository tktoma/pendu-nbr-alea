#include "cadrillage.h"

cadrillage::cadrillage(int x2, int y2)
{
	this->x = x2;
	this->y = x2;
}

void cadrillage::set(int x2, int y2)
{
	this->x = x2;
	this->y = x2;
}

void cadrillage::cadreaffiche()
{
	int inf = cadre.size() ;
	cout << cadre;
	cout << inf;
}

/*void cadrillage::test()
{
	vector<char> lettre;
	int nbr_alea1;
	int nbr_alea2;
	srand(time(NULL));
	nbr_alea1 = (rand() % (10));
	nbr_alea2 = (rand() % (10));
	char.reserve(nbr_alea2.size());
	nbr_alea2 += 45;
	lettre = 
	cout << nbr_alea1 << lettre;
}*/
