#ifndef BATAILLE_NAVALE_H
#define BATAILLE_NAVALE_H

#include <string>
#include "cadrillage.h"

class BatailleNavale {
public:
    BatailleNavale(Cadrillage& cadrillage);

    bool placerAsterisque(char lettre, int chiffre); // Placer un astérisque à une position donnée

    void entrerAsterisques();

    bool verifierPoints(const char lettres[4], const int chiffres[4]);

private:
    Cadrillage& cadrillage; // Référence au cadrillage
    int obtenirIndexLettre(char lettre); // Convertir la lettre en index de ligne (A = 1, B = 2, ...)
};

#endif // BATAILLE_NAVALE_H
