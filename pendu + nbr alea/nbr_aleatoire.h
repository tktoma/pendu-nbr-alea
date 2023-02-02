#pragma once
#include <iostream>
#include <thread>
#include <chrono>
class nbr_aleatoire
{
private:
	int max;
	int min;
	int nbr_choisie;
	int nbr_alea;
	int coup = 0;
	int i = 0;
	int difficulter;
public:
	int choix_nombre();
	bool test();
	nbr_aleatoire(int m = 0, int min = 0);
	void init_difficulter(int diff = 1, int nbmin=0 ,int nbmax=0);
	void lancement();
	~nbr_aleatoire();
};

