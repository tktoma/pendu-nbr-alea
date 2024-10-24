#include "Bataille_Navalle.h"
#include <cctype>
#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>

// Constructeur
BatailleNavale::BatailleNavale(Cadrillage& cadrillage) : cadrillage(cadrillage) {}

// M�thode pour obtenir l'index correspondant � une lettre (ex. 'A' = 0, 'B' = 1, ...)
int BatailleNavale::obtenirIndexLettre(char lettre) {
    lettre = toupper(lettre); // Convertir en majuscule pour �viter les erreurs

    if (lettre >= 'A' && lettre <= 'Z') {
        return lettre - 'A'; // Retourne un index de 0 pour 'A', 1 pour 'B', etc.
    }

    return -1; // Retourner -1 si la lettre est invalide
}

// M�thode pour placer un ast�risque dans le cadrillage � une position donn�e
bool BatailleNavale::placerAsterisque(char lettre, int chiffre) {
    int colonnes = cadrillage.getColonnes();
    int lignes = cadrillage.getLignes();
    int ligneIndex = obtenirIndexLettre(lettre); // Obtenir l'index de la ligne � partir de la lettre

    if (ligneIndex < 0 || ligneIndex >= lignes || chiffre < 1 || chiffre > colonnes) {
        std::cerr << "Position invalide !" << std::endl;
        return false; // Retourner false si les coordonn�es sont invalides
    }

    int reglage_jsp_pk = (colonnes < 10) ? -1 : 0;

    // Calculer l'index exact dans la cha�ne
    int position = ((4 * (colonnes + 1) + 2)) + (4 * (colonnes + 1) + 2) * ((ligneIndex+1) * 2) + (4 * chiffre) + 3 + reglage_jsp_pk;

    std::string& grille = cadrillage.get_cad(); // Utiliser la grille persistante

    if (grille[position] == '*') {
        std::cerr << "Erreur : un ast�risque est d�j� pr�sent � cette position !" << std::endl;
        return false; // Ne pas placer l'ast�risque si l'emplacement est occup�
    }

    // Remplacer l'espace vide par un ast�risque
    grille.replace(position, 1, "*");
    return true;
}

// M�thode pour entrer les ast�risques avec un nombre modulable de points
void BatailleNavale::entrerAsterisques(int nombrePoints) {
    char* lettres = new char[nombrePoints]; 
    int* chiffres = new int[nombrePoints];   
    bool valid = false;

    while (!valid) {
        // R�initialiser les points
        for (int i = 0; i < nombrePoints; ++i) {
            lettres[i] = '\0';
            chiffres[i] = 0;
        }

        // Entr�e des points
        for (int i = 0; i < nombrePoints; ++i) {
            std::cout << "Entrez le point " << (i + 1) << " (ex: A 1): ";
            std::cin >> lettres[i] >> chiffres[i];
        }

        // V�rification de la validit� des points
        if (verifierPoints(lettres, chiffres, nombrePoints)) {
            bool asterisquePlace = true; // Pour v�rifier si tous les ast�risques ont �t� plac�s correctement
            for (int i = 0; i < nombrePoints; ++i) {
                if (!placerAsterisque(lettres[i], chiffres[i])) {
                    asterisquePlace = false; // Si un ast�risque ne peut pas �tre plac�, annuler l'op�ration
                    std::cerr << "Erreur lors du placement du point. Annulation des points plac�s." << std::endl;
                    
                    // Annuler tous les ast�risques plac�s avant cette erreur
                    for (int j = 0; j < i; ++j) {
                        annulerAsterisque(lettres[j], chiffres[j]);
                    }
                    break; // Sortir de la boucle si une erreur est rencontr�e
                }
            }

            if (asterisquePlace) {
                valid = true; // Si tout a r�ussi, sortir de la boucle
            }
        } else {
            // Si les points ne sont pas valides, annuler les ast�risques d�j� plac�s
            for (int i = 0; i < nombrePoints; ++i) {
                if (lettres[i] != '\0' && chiffres[i] != 0) {
                    // Remplacer l'ast�risque par un espace
                    annulerAsterisque(lettres[i], chiffres[i]);
                }
            }
            std::cout << "Les points ne forment pas une ligne valide. Veuillez r�essayer." << std::endl;
        }
    }

    delete[] lettres;   // Lib�rer la m�moire
    delete[] chiffres;  // Lib�rer la m�moire

    std::cout << "Grille finale:" << std::endl;
    std::cout << cadrillage.get_cad() << std::endl; // Affichage final de la grille
}

// M�thode pour annuler un ast�risque
void BatailleNavale::annulerAsterisque(char lettre, int chiffre) {
    std::string& grille = cadrillage.get_cad();
    int ligneIndex = obtenirIndexLettre(lettre);
    int reglage_jsp_pk = (cadrillage.getColonnes() < 10) ? -1 : 0;
    int position = ((4 * (cadrillage.getColonnes() + 1) + 2)) + (4 * (cadrillage.getColonnes() + 1) + 2) * ((ligneIndex + 1) * 2) + (4 * chiffre) + 3 + reglage_jsp_pk;

    // Remplacer l'ast�risque par un espace
    if (grille[position] == '*') {
        grille.replace(position, 1, " ");
    }
}

// V�rification de la validit� des points
bool BatailleNavale::verifierPoints(const char lettres[], const int chiffres[], int nombrePoints) {
    if (nombrePoints < 2) {
        return false; // Doit avoir au moins 2 points
    }

    int ligneIndex[10];
    for (int i = 0; i < nombrePoints; ++i) {
        ligneIndex[i] = obtenirIndexLettre(lettres[i]);
    }

    // V�rifier si tous les points sont sur la m�me ligne
    bool horizontal = true;
    for (int i = 1; i < nombrePoints; ++i) {
        if (ligneIndex[i] != ligneIndex[0]) {
            horizontal = false;
            break;
        }
    }

    // V�rifier si tous les points sont sur la m�me colonne
    bool vertical = true;
    for (int i = 1; i < nombrePoints; ++i) {
        if (chiffres[i] != chiffres[0]) {
            vertical = false;
            break;
        }
    }

    // V�rifier si tous les points forment une diagonale
    bool diagonal = true;
    int deltaLigne = ligneIndex[1] - ligneIndex[0];
    int deltaColonne = chiffres[1] - chiffres[0];

    for (int i = 1; i < nombrePoints; ++i) {
        if (ligneIndex[i] - ligneIndex[i - 1] != deltaLigne || chiffres[i] - chiffres[i - 1] != deltaColonne) {
            diagonal = false;
            break;
        }
    }

    // S'assurer que les points sont cons�cutifs (pas de sauts)
    for (int i = 1; i < nombrePoints; ++i) {
        if (abs(ligneIndex[i] - ligneIndex[i - 1]) > 1 || abs(chiffres[i] - chiffres[i - 1]) > 1) {
            return false; // Si les points ne sont pas cons�cutifs, retourner faux
        }
    }

    // Retourner vrai si au moins une des conditions est remplie
    return horizontal || vertical || diagonal;
}
