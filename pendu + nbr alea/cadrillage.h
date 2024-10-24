#ifndef CADRILLAGE_H
#define CADRILLAGE_H

#include <string>
#include <iostream>

class Cadrillage {
public:
    Cadrillage(int lignes, int colonnes);
    void afficher() const;

    void ligne();
    int  getColonnes() const;
    int  getLignes() const;
    std::string& get_cad() ;
    void setGrille(const std::string& newGrille);

private:
    int lignes;
    int colonnes;
    std::string grille; // Utilisation d'une cha�ne de caract�res pour le cadrillage
    void construireGrille(); // M�thode pour construire la grille
};

#endif // CADRILLAGE_H
