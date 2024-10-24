#include "Bataille_Navalle.h"
#include <cctype>
#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>

// Constructeur
BatailleNavale::BatailleNavale(Cadrillage& cadrillage) : cadrillage(cadrillage) {}

// Méthode pour obtenir l'index correspondant à une lettre (ex. 'A' = 0, 'B' = 1, ...)
int BatailleNavale::obtenirIndexLettre(char lettre) {
    lettre = toupper(lettre); // Convertir en majuscule pour éviter les erreurs

    if (lettre >= 'A' && lettre <= 'Z') {
        return lettre - 'A'; // Retourne un index de 0 pour 'A', 1 pour 'B', etc.
    }

    return -1; // Retourner -1 si la lettre est invalide
}

// Méthode pour placer un astérisque dans le cadrillage à une position donnée
bool BatailleNavale::placerAsterisque(char lettre, int chiffre) {
    int colonnes = cadrillage.getColonnes();
    int lignes = cadrillage.getLignes();
    int ligneIndex = obtenirIndexLettre(lettre); // Obtenir l'index de la ligne à partir de la lettre

    if (ligneIndex < 0 || ligneIndex >= lignes || chiffre < 1 || chiffre > colonnes) {
        std::cerr << "Position invalide !" << std::endl;
        return false; // Retourner false si les coordonnées sont invalides
    }

    int reglage_jsp_pk = (colonnes < 10) ? -1 : 0;

    // Calculer l'index exact dans la chaîne
    int position = ((4 * (colonnes + 1) + 2)) + (4 * (colonnes + 1) + 2) * ((ligneIndex+1) * 2) + (4 * chiffre) + 3 + reglage_jsp_pk;

    std::string& grille = cadrillage.get_cad(); // Utiliser la grille persistante

    if (grille[position] == '*') {
        std::cerr << "Erreur : un astérisque est déjà présent à cette position !" << std::endl;
        return false; // Ne pas placer l'astérisque si l'emplacement est occupé
    }

    // Remplacer l'espace vide par un astérisque
    grille.replace(position, 1, "*");
    return true;
}

// Méthode pour entrer les astérisques avec un nombre modulable de points
void BatailleNavale::entrerAsterisques(int nombrePoints) {
    char* lettres = new char[nombrePoints]; 
    int* chiffres = new int[nombrePoints];   
    bool valid = false;

    while (!valid) {
        // Réinitialiser les points
        for (int i = 0; i < nombrePoints; ++i) {
            lettres[i] = '\0';
            chiffres[i] = 0;
        }

        // Entrée des points
        for (int i = 0; i < nombrePoints; ++i) {
            std::cout << "Entrez le point " << (i + 1) << " (ex: A 1): ";
            std::cin >> lettres[i] >> chiffres[i];
        }

        // Vérification de la validité des points
        if (verifierPoints(lettres, chiffres, nombrePoints)) {
            bool asterisquePlace = true; // Pour vérifier si tous les astérisques ont été placés correctement
            for (int i = 0; i < nombrePoints; ++i) {
                if (!placerAsterisque(lettres[i], chiffres[i])) {
                    asterisquePlace = false; // Si un astérisque ne peut pas être placé, annuler l'opération
                    std::cerr << "Erreur lors du placement du point. Annulation des points placés." << std::endl;
                    
                    // Annuler tous les astérisques placés avant cette erreur
                    for (int j = 0; j < i; ++j) {
                        annulerAsterisque(lettres[j], chiffres[j]);
                    }
                    break; // Sortir de la boucle si une erreur est rencontrée
                }
            }

            if (asterisquePlace) {
                valid = true; // Si tout a réussi, sortir de la boucle
            }
        } else {
            // Si les points ne sont pas valides, annuler les astérisques déjà placés
            for (int i = 0; i < nombrePoints; ++i) {
                if (lettres[i] != '\0' && chiffres[i] != 0) {
                    // Remplacer l'astérisque par un espace
                    annulerAsterisque(lettres[i], chiffres[i]);
                }
            }
            std::cout << "Les points ne forment pas une ligne valide. Veuillez réessayer." << std::endl;
        }
    }

    delete[] lettres;   // Libérer la mémoire
    delete[] chiffres;  // Libérer la mémoire

    std::cout << "Grille finale:" << std::endl;
    std::cout << cadrillage.get_cad() << std::endl; // Affichage final de la grille
}

// Méthode pour annuler un astérisque
void BatailleNavale::annulerAsterisque(char lettre, int chiffre) {
    std::string& grille = cadrillage.get_cad();
    int ligneIndex = obtenirIndexLettre(lettre);
    int reglage_jsp_pk = (cadrillage.getColonnes() < 10) ? -1 : 0;
    int position = ((4 * (cadrillage.getColonnes() + 1) + 2)) + (4 * (cadrillage.getColonnes() + 1) + 2) * ((ligneIndex + 1) * 2) + (4 * chiffre) + 3 + reglage_jsp_pk;

    // Remplacer l'astérisque par un espace
    if (grille[position] == '*') {
        grille.replace(position, 1, " ");
    }
}

// Vérification de la validité des points
bool BatailleNavale::verifierPoints(const char lettres[], const int chiffres[], int nombrePoints) {
    if (nombrePoints < 2) {
        return false; // Doit avoir au moins 2 points
    }

    int ligneIndex[10];
    for (int i = 0; i < nombrePoints; ++i) {
        ligneIndex[i] = obtenirIndexLettre(lettres[i]);
    }

    // Vérifier si tous les points sont sur la même ligne
    bool horizontal = true;
    for (int i = 1; i < nombrePoints; ++i) {
        if (ligneIndex[i] != ligneIndex[0]) {
            horizontal = false;
            break;
        }
    }

    // Vérifier si tous les points sont sur la même colonne
    bool vertical = true;
    for (int i = 1; i < nombrePoints; ++i) {
        if (chiffres[i] != chiffres[0]) {
            vertical = false;
            break;
        }
    }

    // Vérifier si tous les points forment une diagonale
    bool diagonal = true;
    int deltaLigne = ligneIndex[1] - ligneIndex[0];
    int deltaColonne = chiffres[1] - chiffres[0];

    for (int i = 1; i < nombrePoints; ++i) {
        if (ligneIndex[i] - ligneIndex[i - 1] != deltaLigne || chiffres[i] - chiffres[i - 1] != deltaColonne) {
            diagonal = false;
            break;
        }
    }

    // S'assurer que les points sont consécutifs (pas de sauts)
    for (int i = 1; i < nombrePoints; ++i) {
        if (abs(ligneIndex[i] - ligneIndex[i - 1]) > 1 || abs(chiffres[i] - chiffres[i - 1]) > 1) {
            return false; // Si les points ne sont pas consécutifs, retourner faux
        }
    }

    // Retourner vrai si au moins une des conditions est remplie
    return horizontal || vertical || diagonal;
}
