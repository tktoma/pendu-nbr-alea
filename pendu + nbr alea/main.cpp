#include <iostream>
#include "verif_cadrillage.h"
#include "cadrillage.h"

int main() {
    const int lignes = 10;  // Nombre de lignes de la grille
    const int colonnes = 10; // Nombre de colonnes de la grille

    // Création de l'objet Cadrillage
    Cadrillage cadrillage(lignes, colonnes);

    // Création de l'objet BatailleNavale
    Verif_cadrillage verif_cadrillage(cadrillage);

    // Boucle principale pour entrer des points d'astérisques
    char continuer;
    do {
        // Affichage du cadrillage initial
        std::cout << "Cadrillage actuel:\n";
        std::cout << cadrillage.get_cad() << std::endl;

        // Entrée des astérisques
        verif_cadrillage.entrerAsterisques(4);
        verif_cadrillage.entrerAsterisques(4);
        verif_cadrillage.entrerAsterisques(3);
        verif_cadrillage.entrerAsterisques(3);
        verif_cadrillage.entrerAsterisques(3);
        verif_cadrillage.entrerAsterisques(2);
        verif_cadrillage.entrerAsterisques(2);
        verif_cadrillage.entrerAsterisques(2);
        verif_cadrillage.entrerAsterisques(2);

        // Demander à l'utilisateur s'il veut continuer
        std::cout << "Voulez-vous placer d'autres astérisques ? (o/n) : ";
        std::cin >> continuer;

    } while (continuer == 'o' || continuer == 'O');

    std::cout << "Fin du jeu.\n";
    return 0;
}
