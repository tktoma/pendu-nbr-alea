#include "cadrillage.h"

cadrillage::cadrillage(int x2, char y2)
{
	this->x = x2;
	this->y = x2;
}

void cadrillage::set(int x2, char y2)
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

int cadrillage::choix(char ver)
{
    char lettre[10] = { 'A','B','C','D','E','F','G','H','I','J'}; // alphabet pour les verification
    int i = 0;
    size_t taille = strlen(&lettre[10]) - 8;//taille des lettres
    char jenaimar = 0;
    jenaimar = toupper(ver);// tout en majuscule
    for (i = 0; i < taille; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(10));

        if (strchr(&jenaimar, lettre[i]) && lettre[i] != 0)// si il trouve une lettre de l'alphabet
        {
            return i + 1;
        }
    }
    return 0;
}
void cadrillage::replace(int x, int y)
{
    string sx, sy;
    sx = x;
    sy = y;
    this->cadre.replace(46+2+ (46*(y*2)) + (4*x), 1, "*");
}


