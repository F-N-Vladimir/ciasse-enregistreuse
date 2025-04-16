#include <stdio.h>
#include <stdlib.h>

// Liste des billets et pièces (en centimes pour éviter les décimales)
int billets_pieces[] = {200000, 100000, 50000, 20000, 10000, 5000, 2500, 2000, 1000, 500, 100, 25};
int stock[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; // Stock initial
int nombre_types = 12; // Nombre de billets/pièces

// Fonction pour calculer la monnaie à rendre (point 6)
int calculate_monnaie(int montant, int monnaie_rendue[], int stock[]) {
    // Copier le stock pour tester sans modifier
    int stock_temporaire[nombre_types];
    for (int i = 0; i < nombre_types; i++) {
        stock_temporaire[i] = stock[i];
        monnaie_rendue[i] = 0; // Initialiser à zéro
    }

    int reste = montant; // Montant restant à rendre
    for (int i = 0; i < nombre_types; i++) {
        // Utiliser le plus grand billet/pièce possible
        while (reste >= billets_pieces[i] && stock_temporaire[i] > 0) {
            reste -= billets_pieces[i]; // Réduire le montant
            monnaie_rendue[i]++; // Ajouter un billet/pièce
            stock_temporaire[i]--; // Réduire le stock temporaire
        }
    }

    // Si tout le montant est rendu (reste = 0)
    if (reste == 0) {
        // Mettre à jour le stock réel
        for (int i = 0; i < nombre_types; i++) {
            stock[i] = stock_temporaire[i];
        }
        return 1; // Succès
    }
    return 0; // Échec
}

// Fonction pour afficher la monnaie rendue (point 7)
void afficher_monnaie(int monnaie_rendue[]) {
    printf("Monnaie rendue :\n");
    for (int i = 0; i < nombre_types; i++) {
        if (monnaie_rendue[i] > 0) {
            printf("%d x R$%.2f\n", monnaie_rendue[i], billets_pieces[i] / 100.0);
        }
    }
}

// Fonction pour afficher l'état du stock (point 8)
void afficher_stock() {
    printf("\nStock actuel :\n");
    for (int i = 0; i < nombre_types; i++) {
        printf("R$%.2f : %d\n", billets_pieces[i] / 100.0, stock[i]);
    }
}

// Fonction pour remplir la caisse (point 10)
void remplir_caisse() {
    for (int i = 0; i < nombre_types; i++) {
        stock[i] = 10; // Remettre 10 pour chaque billet/pièce
    }
    printf("Caisse remplie !\n");
}

int main() {
    int montant; // Montant à rendre (en centimes)
    int monnaie_rendue[nombre_types]; // Tableau pour la monnaie rendue
    char choix; // Choix de l'utilisateur (r ou a)

    printf("Programme de caisse enregistreuse\n");

    // Boucle pour gérer les transactions (point 9)
    while (1) {
        printf("\nEntrez le montant à rendre (en centimes, 0 pour quitter) : ");
        if (scanf("%d", &montant) != 1) { // Vérifier l'entrée
            while (getchar() != '\n'); // Vider le buffer
            printf("Entrée non valide, essayez encore.\n");
            continue;
        }

        if (montant == 0) { // Quitter si montant = 0
            printf("Programme terminé.\n");
            break;
        }

        if (montant < 0) { // Vérifier montant négatif
            printf("Montant négatif non valide.\n");
            continue;
        }

        // Tenter de rendre la monnaie (points 6-7)
        if (calculate_monnaie(montant, monnaie_rendue, stock)) {
            afficher_monnaie(monnaie_rendue); // Afficher monnaie rendue
            afficher_stock(); // Afficher stock (point 8)
        } else {
            // Si impossible de rendre la monnaie (point 10)
            printf("Pas assez de billets/pièces pour rendre la monnaie.\n");
            printf("Voulez-vous remplir la caisse (r) ou arrêter (a) ? ");
            scanf(" %c", &choix); // Espace avant %c pour ignorer les espaces
            if (choix == 'r') {
                remplir_caisse(); // Remplir la caisse
                if (calculate_monnaie(montant, monnaie_rendue, stock)) {
                    afficher_monnaie(monnaie_rendue);
                    afficher_stock();
                } else {
                    printf("Erreur : Toujours impossible de rendre la monnaie.\n");
                    break;
                }
            } else if (choix == 'a') {
                printf("Programme terminé.\n");
                break;
            } else {
                printf("Choix non valide, arrêt du programme.\n");
                break;
            }
        }
    }

    return 0;
}

