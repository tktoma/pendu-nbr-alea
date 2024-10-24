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
        int chiffre = lettre - 'A' + 1;
        return chiffre;
    }

    return -1; // Retourner -1 si la lettre est invalide
}

// M�thode pour placer un ast�risque dans le cadrillage � une position donn�e
bool BatailleNavale::placerAsterisque(char lettre, int chiffre) {
    // R�cup�rer la taille de la grille
    int colonnes = cadrillage.getColonnes();
    int lignes = cadrillage.getLignes();
    int ligneIndex = obtenirIndexLettre(lettre); // Obtenir l'index de la ligne � partir de la lettre

    if (ligneIndex == -1 || ligneIndex >= lignes || chiffre < 1 || chiffre > colonnes) {
        std::cerr << "Position invalide !" << std::endl;
        return false; // Retourner false si les coordonn�es sont invalides
    }

    int reglage_jsp_pk = 0;
    if (colonnes < 10) {
        reglage_jsp_pk = -1;
    }
    // Calculer l'index exact dans la cha�ne o� l'ast�risque doit �tre plac�
    int position = ((4 * (colonnes + 1) + 2)) + (4 * (colonnes + 1) + 2) * ((ligneIndex) * 2) + (4 * chiffre) + 3 + reglage_jsp_pk;

    // R�cup�rer la grille actuelle
    std::string& grille = cadrillage.get_cad(); // Utiliser la grille persistante

    // Remplacer l'espace vide par un ast�risque
    grille.replace(position, 1, "*");

    // Afficher la grille modifi�e
    std::cout << grille << std::endl;
    return true;
}

void BatailleNavale::entrerAsterisques() {
    // Tableau pour stocker les points des ast�risques
    char lettres[4];
    int chiffres[4];
    bool valid = false;

    while (!valid) {
        // R�initialiser les points
        for (int i = 0; i < 4; ++i) {
            lettres[i] = '\0';
            chiffres[i] = 0;
        }

        // Premier point
        std::cout << "Entrez le premier point (ex: A 1): ";
        std::cin >> lettres[0] >> chiffres[0];

        // Second point
        std::cout << "Entrez le second point (ex: A 2): ";
        std::cin >> lettres[1] >> chiffres[1];

        // Troisi�me point
        std::cout << "Entrez le troisi�me point (ex: A 3): ";
        std::cin >> lettres[2] >> chiffres[2];

        // Quatri�me point
        std::cout << "Entrez le quatri�me point (ex: A 4): ";
        std::cin >> lettres[3] >> chiffres[3];

        // V�rification de la validit� des points
        if (verifierPoints(lettres, chiffres)) {
            // Placer les ast�risques
            for (int i = 0; i < 4; ++i) {
                placerAsterisque(lettres[i], chiffres[i]);
            }
            valid = true; // Si tout est valide, sortir de la boucle
        }
        else {
            std::cout << "Les points ne forment pas une ligne valide. Veuillez r�essayer." << std::endl;
        }
    }
}

// V�rification de la validit� des points
bool BatailleNavale::verifierPoints(const char lettres[4], const int chiffres[4]) {
    // V�rifier que nous avons 4 points
    if (lettres[0] == '\0' || lettres[1] == '\0' || lettres[2] == '\0' || lettres[3] == '\0') {
        return false;
    }

    int ligneIndex0 = obtenirIndexLettre(lettres[0]);
    int ligneIndex1 = obtenirIndexLettre(lettres[1]);
    int ligneIndex2 = obtenirIndexLettre(lettres[2]);
    int ligneIndex3 = obtenirIndexLettre(lettres[3]);

    int colonne0 = chiffres[0];
    int colonne1 = chiffres[1];
    int colonne2 = chiffres[2];
    int colonne3 = chiffres[3];

    // V�rifier les lignes
    bool horizontal = (ligneIndex0 == ligneIndex1 && ligneIndex1 == ligneIndex2 && ligneIndex2 == ligneIndex3);
    bool vertical = (colonne0 == colonne1 && colonne1 == colonne2 && colonne2 == colonne3);
    bool diagonal = (abs(ligneIndex0 - ligneIndex1) == 1 && abs(colonne0 - colonne1) == 1 &&
        abs(ligneIndex1 - ligneIndex2) == 1 && abs(colonne1 - colonne2) == 1 &&
        abs(ligneIndex2 - ligneIndex3) == 1 && abs(colonne2 - colonne3) == 1);

    return horizontal || vertical || diagonal; // Retourner true si c'est une ligne valide
}