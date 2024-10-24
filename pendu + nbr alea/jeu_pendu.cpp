#include "jeu_pendu.h"

bool jeu_pendu::mode(char mode)
{
	
	if (mode == '3')
	{

		cout << endl << "------------------------------------------listing des mot------------------------------------------" << endl;
		ui->mot->afficher_mot();
		return 1;
	}
	else if (mode == '1')
	{
		cout << "3 regle importante" << endl
			<< "1. PAS D'ACCENT :)" << endl
			<< "2. une lettre n'est pas un mot :)" << endl
			<< "3. pas plus de 99 lettre (pas d'espace aussi)" << endl;

		int i = 0;
		float x = 0;
		int y = 0;
		string ajout;

		cout << "mot a ajouter :";

		cin >> ajout;
		size_t taille = strlen(ajout.c_str());
		for (y = 0; y < taille; y++)
		{
			for (i = 0; i < 26; i++)
			{
				if (toupper(ajout[y]) != lettre[i])
				{
					x++;
				}
			}
		}
		if (x / 25 > taille) // test par rapport a ce que je veut
		{
			cout << "pas d accent ou d'espace:( " << endl;
		}
		else if (taille == 1)
		{
			cout << "un mot pas une lettre" << endl;
		}
		else if (taille > 99)
		{
			cout << "\"-_-, vraiment + de " << taille << " lettre le mot" << endl;
		}
		else
		{
			ui->mot->Ecrire(ajout);
		}
		ui->mot->afficher_mot();
		return 1;
	}
	else if (mode == '2')
	{
		ui->mot->suppr();
		return 1;
	}
	else if (mode == '5')
	{
		return 0;
	}
	else if (mode == '4')
	{
		stop = jeu();
		while (stop == 0)
		{
			stop = jeu();
		}
		return 1;
	}
	return 0;
}




jeu_pendu::jeu_pendu()
{
	this->diff = ' ';
	this->nb_coups = 0;
	this->coup = 0;
	this->stop = ' ';
	this->coupR = 0;
	this->diffcoup = 0;
}

bool jeu_pendu::lancement()
{
	bool stop = false;
	cout << "------------------------------------------BIENVENUE SUR LE JEU DU PENDU------------------------------------------" <<
	endl << "regle a respecter" <<
	endl << "1 !!!les accents aisi que les chiffres sont interdit sinon ca va faire bugger le jeu!!!" <<
	endl << "2 il faut marquer une lettre (si vous en marquer plusieur la premiere sera la seul compter" <<
	endl << "3 quand vous ajoutez des mots il ne faut pas mettre des accent ou des espaces" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "------------------------------------------AMUSER VOUS BIEN------------------------------------------" <<
	endl << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << endl << "------------------------------------------listing des mot------------------------------------------" << endl;
	this_thread::sleep_for(chrono::milliseconds(100));
	ui->mot->afficher_mot();
	this_thread::sleep_for(chrono::milliseconds(1000));
	char mod = '1';//mode a selec
	cout << "------------------------------------------menu------------------------------------------" << endl;
	cout << "1 ecrire des nouveaux mots" << endl << endl;
	cout << "2 suprimer des mots" << endl << endl;
	cout << "3 reafficher les mots" << endl << endl;
	cout << "4 jouer" << endl << endl;
	cout << "5 fermer le jeu" << endl << endl;
			cin >> mod;
		while (mode(mod) == 1) // eteindre ou pas le programme
		{
			cout << "------------------------------------------menu------------------------------------------" << endl;
			cout << "1 ecrire des nouveaux mots" << endl << endl;
			cout << "2 suprimer des mots" << endl << endl;
			cout << "3 reafficher les mots" << endl << endl;
			cout << "4 jouer" << endl << endl;
			cout << "5 fermer le jeu" << endl << endl;
			cin >> mod;// entrer le mode
			this_thread::sleep_for(chrono::milliseconds(1000));

		}
		return 0;
}

			int jeu_pendu::difficulter(char diff)
			{
				
				if (diff == '1')
				{
					nb_coups = -1;//infinie
					return 2;
				}
				else if (diff == '2')
				{
					nb_coups = 16;
					return 1;
				}
				else if (diff == '3')
				{
					nb_coups = 8;
					return 1;
				}
				else if (diff == '4')
				{
					nb_coups = 4;
					return 1;
				}
				else if (diff == '5')
				{
					nb_coups = 2;
					return 1;
				}
				else
				{
					return 0;
				}
			}

			bool jeu_pendu::jeu()
			{
				this_thread::sleep_for(chrono::milliseconds(10));
				int u = 0;
				int g = 0;
				char su[100] = { 0 };
				char* su2 = new char[1];
				string result = "";
				string result2 = "                         ";
				bool tmp = false;
				bool tmp2 = false;
				int p = 0;
				int i = 0;
				int f = 0;
				char choix;
				
				cout << "choisie une difficulter:" << endl;
				cout << "1-INRATABLE(nombre de coups infini)" <<
					endl << "2-FACILE(nombre de coups = 16)" <<
					endl << "3-CLASSIQUE(nombre de coups = 8)" <<
					endl << "4-DIFFICILE(nombre de coups = 4)" <<
					endl << "5-IMPOSSIBLE(nombre de coups = 2)" <<
					endl;
				cin >> choix;
				
				while (difficulter(choix) == 1 || difficulter(choix) == 2)
				{
					coupR =nb_coups ;

					ui->set_motchoisie();
					cout << "mot a trouver" << endl;
					ui->transfo_txt_to_asterisk(su);
					cout << endl;
					while (f == 0)
					{
						string stp;
						g = 0;
						this_thread::sleep_for(chrono::milliseconds(10));

						if (difficulter(choix) == 2)
						{
							cout << "nombre de coups  " << coup << endl;
						}
						else
						{
							cout << "nombre de coups  " << coup << "   coups restant   " << coupR << "  coups max   " << diffcoup << endl;
						}
						if (coup >= 1)
						{
							ui->pendu(choix, coup);
						}

						cout << endl << "taper une lettre" << endl;

						while (g == 0)//test de si c'est autre chose que une lettre de notre alphabet
						{

							cin >> su[p];

							for (i = 0; i < 26; i++)
							{
								if (toupper(su[p]) == lettre[i])
								{
									g = 1;
								}
							}
						}
						*su2 = su[p];
						p = p++;
						tmp = ui->transfo_txt_to_asterisk(su);
						tmp2 = ui->lettre_t(su);

						if (tmp2 == true)
						{
							cout << endl << "lettre trouver " << endl;
						}
						else
						{
							coupR--;
							coup++;

							cout << endl << "pas encore" << endl;


						}

						result = (ui->lettre_utiliser(*su2));
						size_t pos = result.find_first_not_of(" ");
						stp = result[pos];

						result2.replace(pos, 1, stp);// ca permet de stocké les lettre utiliser et de toute les afficher en plus de remettre au meme endroit celle déjas utilisé

						cout << result2 << endl;

						if (tmp == true || coupR == 0)
						{

							if (coupR == 0)
							{
								ui->pendu(choix, coup);
								f = 1;

								cout << endl << "perdu vous avez utiliser vos " << coup << " coups" << endl;
								cout << "le mot était ";
								ui->get_motchoisie();
								cout << endl;
								coupR--;
								coup++;
							}
							else
							{
								if (coup >= 1)
								{
									ui->pendu(choix, coup);
								}


								f = 1;

								cout << endl << "GG, tu as win en" << coup << "coups" << endl;
							}
							while (u == 0)
							{
								this_thread::sleep_for(chrono::milliseconds(10));
								cout << "rejouer ?" << endl << "0 = non      1 = oui" << endl;

								cin >> stop;

								if (stop != '0' && stop != '1')
								{
									return 1;
								}
								else if (stop != '0')
								{
									return 0;
								}
								else return 1;
							}
						}
					}
				}
				return 0;
			}