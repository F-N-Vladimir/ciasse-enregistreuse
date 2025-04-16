#include <stdio.h>
#include <stdlib.h>

// Liste des billets et pièces disponibles (en centimes pour éviter les décimales)
int billets_pieces[] = {200000, 100000, 50000, 20000, 10000, 5000, 2500, 2000, 1000, 500, 100, 25};
int stock[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; // Stock initial : 10 de chaque
int nombre_types = 12; // Nombre total de billets/pièces différents

// Fonction pour afficher les dénominations et le stock (pour vérifier la configuration)
void afficher_config() {
    printf("Dénominations disponibles et stock initial :\n");
    for (int i = 0; i < nombre_types; i++) {
        printf("R$%.2f : %d en stock\n", billets_pieces[i] / 100.0, stock[i]);
    }
}

int main() {
    printf("Programme de caisse enregistreuse - Configuration initiale\n");
    afficher_config(); // Afficher les dénominations et le stock
    printf("Projet prêt pour calculer la monnaie (à implémenter).\n");
    return 0;
}
