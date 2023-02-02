#pragma once
#include <iostream>
#include "verif.h"
#include<windows.h>

class jeu_pendu
{
private:
	char lettre[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char diff;
	int nb_coups;
	int coup = 0;
	char stop;
	int coupR;
	int diffcoup;
	verif* ui = new verif();//alouage dynamique de l'objet ui
public:
	bool mode(char mod);
	bool lancement();
	int difficulter(char diff);
	bool jeu();
	jeu_pendu();
};

