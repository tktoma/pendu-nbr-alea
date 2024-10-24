#include "cadrillage.h"

// Constructeur
Cadrillage::Cadrillage(int lignes, int colonnes) : lignes(lignes), colonnes(colonnes) {
    // Limiter les dimensions à 26x26
    if (lignes > 26)  {
        this->lignes = 26;
    }
    if (colonnes > 26) {
        this->colonnes = 26;
    }
    construireGrille(); // Construire la grille vide
}
void Cadrillage::setGrille(const std::string& newGrille) {
    grille = newGrille; // Mettre à jour la grille
}

// Méthode pour construire la grille
void Cadrillage::construireGrille() {
    grille.clear(); // Réinitialiser la chaîne de la grille

    // Ajouter la première ligne de séparation
    ligne();
    grille += "|   |"; // Cellule vide pour le coin supérieur gauche

    // Ajouter les en-têtes des colonnes
    for (int j = 1; j <= colonnes; ++j) {
        if (j < 10) {
            grille += " " + std::to_string(j) + " |"; // Un espace pour les chiffres à un chiffre
        }
        else if (j == 10)
        {
            grille += std::to_string(j) + " | "; // Pas d'espace pour les chiffres à deux chiffres
        }
        else {
            grille += std::to_string(j) + "| "; // Pas d'espace pour les chiffres à deux chiffres
        }
    }
    grille += "\n";
    ligne();


    // Ajouter les lignes avec les lettres A, B, C, ...
    for (int i = 0; i < lignes; ++i) {
        grille += "| " + std::string(1, 'A' + i) + " "; // Ajouter les lettres A, B, C, ...

        for (int j = 0; j < colonnes; ++j) {
            grille += "|   "; // Ajouter les cellules vides
        }
        grille += "|\n"; // Fermer la ligne
        ligne(); // Ajouter la ligne de séparation
    }
}

int Cadrillage::getColonnes() const
{
    return this->colonnes;
}

int Cadrillage::getLignes() const
{
    return this->lignes;
}

// Méthode pour afficher le cadrillage
void Cadrillage::afficher() const {
    std::cout << grille; // Afficher la chaîne qui contient tout le cadrillage
}
void Cadrillage::ligne()     // Ligne de séparation après les en-têtes
{
    for (int i = 0; i < ((colonnes + 1) * 4) + 1; ++i) {
        grille += "-";
    }
    grille += "\n";
}

std::string& Cadrillage::get_cad() 
{
    return grille;
}