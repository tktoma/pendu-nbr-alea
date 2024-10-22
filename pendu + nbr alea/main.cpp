#include "jeu_pendu.h"
#include "nbr_aleatoire.h"
#include "cadrillage.h"
int main()
{
	cadrillage vui(10,'e');
	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 10; y++)
		{
			this_thread::sleep_for(chrono::milliseconds(10));
			vui.replace(i + 1,y + 1); 
			vui.cadreaffiche();
		}
	}

}