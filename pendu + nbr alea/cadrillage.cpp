#include "cadrillage.h"

// Constructeur
Cadrillage::Cadrillage(int lignes, int colonnes) : lignes(lignes), colonnes(colonnes) {
    // Limiter les dimensions � 26x26
    if (lignes > 26)  {
        this->lignes = 26;
    }
    if (colonnes > 26) {
        this->colonnes = 26;
    }
    construireGrille(); // Construire la grille vide
}
void Cadrillage::setGrille(const std::string& newGrille) {
    grille = newGrille; // Mettre � jour la grille
}

// M�thode pour construire la grille
void Cadrillage::construireGrille() {
    grille.clear(); // R�initialiser la cha�ne de la grille

    // Ajouter la premi�re ligne de s�paration
    ligne();
    grille += "|   |"; // Cellule vide pour le coin sup�rieur gauche

    // Ajouter les en-t�tes des colonnes
    for (int j = 1; j <= colonnes; ++j) {
        if (j < 10) {
            grille += " " + std::to_string(j) + " |"; // Un espace pour les chiffres � un chiffre
        }
        else if (j == 10)
        {
            grille += std::to_string(j) + " | "; // Pas d'espace pour les chiffres � deux chiffres
        }
        else {
            grille += std::to_string(j) + "| "; // Pas d'espace pour les chiffres � deux chiffres
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
        ligne(); // Ajouter la ligne de s�paration
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

// M�thode pour afficher le cadrillage
void Cadrillage::afficher() const {
    std::cout << grille; // Afficher la cha�ne qui contient tout le cadrillage
}
void Cadrillage::ligne()     // Ligne de s�paration apr�s les en-t�tes
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