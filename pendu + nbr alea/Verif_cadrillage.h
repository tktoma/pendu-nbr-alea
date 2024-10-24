#ifndef VERIF_CADRILLAGE_H
#define VERIF_CADRILLAGE_H

#include <string>
#include "cadrillage.h"

class Verif_cadrillage {
public:
    Verif_cadrillage(Cadrillage& cadrillage);

    bool placerAsterisque(char lettre, int chiffre); // Placer un astérisque à une position donnée

    void entrerAsterisques(int nombrePoints);

    void annulerAsterisque(char lettre, int chiffre);

    bool verifierPoints(const char lettres[], const int chiffres[], const int nombrePoints);

private:
    Cadrillage& cadrillage; // Référence au cadrillage
    int obtenirIndexLettre(char lettre); // Convertir la lettre en index de ligne (A = 1, B = 2, ...)
   int nombrePoints;
};

#endif // BATAILLE_NAVALE_H
