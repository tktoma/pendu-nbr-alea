#include "jeu_pendu.h"
#include "nbr_aleatoire.h"
#include "cadrillage.h"
int main()
{
	cadrillage vui(10,'e');
	cadrillage vui2(10, 'e');
	cadrillage vui3(10, 'e');
	string * cadre = vui.crea_cadre();
	string * cadre2 = vui2.crea_cadre();
	int i = 0;
	while (i != 10)
	{
		int x, y;
		cin >> x >> y;
		vui2.replace(x, y);
		i++;
	}
	vui2.cadreaffiche(*cadre2);
	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 10; y++)
		{
			this_thread::sleep_for(chrono::milliseconds(10));
			vui.replace(i + 1,y + 1); 
			vui.cadreaffiche(*cadre);
		}
	}

}