#include <iostream>
#include "Bataille_Navalle.h"
#include "cadrillage.h"

int main() {
    const int lignes = 10;  // Nombre de lignes de la grille
    const int colonnes = 10; // Nombre de colonnes de la grille

    // Création de l'objet Cadrillage
    Cadrillage cadrillage(lignes, colonnes);

    // Création de l'objet BatailleNavale
    BatailleNavale batailleNavale(cadrillage);

    // Boucle principale pour entrer des points d'astérisques
    char continuer;
    do {
        // Affichage du cadrillage initial
        std::cout << "Cadrillage actuel:\n";
        std::cout << cadrillage.get_cad() << std::endl;

        // Entrée des astérisques
        batailleNavale.entrerAsterisques();

        // Demander à l'utilisateur s'il veut continuer
        std::cout << "Voulez-vous placer d'autres astérisques ? (o/n) : ";
        std::cin >> continuer;

    } while (continuer == 'o' || continuer == 'O');

    std::cout << "Fin du jeu.\n";
    return 0;
}
