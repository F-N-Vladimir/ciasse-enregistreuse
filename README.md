Date : 17 avril 2025
Projet : TP Caisse Enregistreuse
1. Introduction
Ce rapport décrit le fonctionnement du programme de caisse enregistreuse développé pour le TP "Caisse Enregistreuse". Le programme, écrit en langage C, simule une caisse qui rend la monnaie en roupies mauriciennes pour un montant donné, tout en gérant un stock limité de billets et pièces. Il répond aux exigences des points 1 à 10 du TD, incluant le calcul de la monnaie, l'affichage des billets/pièces rendus, la gestion du stock, la continuation des transactions, et les options pour remplir la caisse ou arrêter.
Le programme utilise les dénominations suivantes : billets de R$2000, R$1000, R$500, R$200, R$100, R$50, R$25, et pièces de R$20, R$10, R$5, R$1, R$0.25. Les sections suivantes expliquent comment compiler, exécuter et utiliser le programme.
2. Compilation du Programme
La compilation transforme le code source (caisse.c) en un exécutable. Le programme est compatible avec tout compilateur C standard, comme GCC ou un IDE tel qu'Embarcadero.
2.1. Compilation avec GCC
    1. Prérequis : Installez GCC.
        ◦ Sur Ubuntu : sudo apt update && sudo apt install build-essential. 
        ◦ Sur Windows : Installez MinGW et ajoutez gcc à votre PATH. 
        ◦ Sur macOS : Installez les outils en ligne de commande avec xcode-select --install. 
    2. Naviguez dans le dossier du projet :
        ◦ Ouvre un terminal (Git Bash sur Windows, Terminal sur Linux/macOS). 
        ◦ Accédez au dossier contenant caisse.c :
          cd chemin/vers/caisse
    3. Compilez :
        ◦ Exécutez :
          gcc caisse.c -o caisse
        ◦ Cela génère un exécutable nommé caisse (ou caisse.exe sur Windows). 
    4. Vérification : Si aucune erreur n’apparaît, l’exécutable est prêt. 
2.2. Compilation avec Embarcadero
    1. Prérequis : Embarcadero RAD Studio ou C++ Builder installé. 
    2. Créer un projet :
        ◦ Ouvre Embarcadero. 
        ◦ Sélectionne File > New > Console Application (configure pour C). 
    3. Ajouter le code :
        ◦ Ajoute caisse.c au projet via File > New > Unit ou en glissant le fichier. 
    4. Compiler :
        ◦ Appuie sur Ctrl+F9 ou sélectionne Build dans le menu. 
    5. Problème de console :
        ◦ Si la console se ferme immédiatement après exécution, modifie caisse.c :
          #include <conio.h> // Ajouter en haut
          // Dans main, avant return 0 :
          getch(); // Attend une touche
        ◦ Recompile après modification. 
2.3. Résolution des erreurs
    • Erreur "undefined reference" : Vérifiez que stdio.h et stdlib.h sont inclus. 
    • Erreur "command not found" (GCC) : Assurez-vous que GCC est installé et dans le PATH. 
3. Exécution du Programme
Une fois compilé, le programme peut être lancé via un terminal ou dans l’IDE.
3.1. Exécution avec GCC
    1. Naviguez dans le dossier :
       cd chemin/vers/caisse
    2. Exécutez :
        ◦ Sur Linux/macOS :
          ./caisse
        ◦ Sur Windows :
          caisse.exe
    3. Résultat : Le programme affiche :
       Programme de caisse enregistreuse
       Entrez le montant à rendre (en centimes, 0 pour quitter) :
3.2. Exécution avec Embarcadero
    1. Exécutez dans l’IDE :
        ◦ Après compilation, appuie sur F9 ou sélectionne Run. 
    2. Console : Une fenêtre s’ouvre avec le message ci-dessus. 
    3. Note : Si getch() est ajouté, la console reste ouverte jusqu’à une pression de touche. 
3.3. Exécution directe
    • Trouvez l’exécutable (caisse ou caisse.exe) dans le dossier du projet. 
    • Double-cliquez dessus (Windows) ou exécutez via terminal (Linux/macOS). 
    • Sur Windows, getch() est recommandé pour éviter une fermeture rapide. 
4. Utilisation du Programme
Le programme permet de rendre la monnaie pour un montant donné, gérer le stock, et continuer les transactions. Voici comment l’utiliser.
4.1. Étapes principales
    1. Démarrer :
        ◦ Lancez le programme (voir section 3). 
        ◦ Il affiche :
          Programme de caisse enregistreuse
          Entrez le montant à rendre (en centimes, 0 pour quitter) :
    2. Entrer un montant :
        ◦ Saisissez un montant en centimes (ex. 5675 pour R$56.75). 
        ◦ Le programme calcule la monnaie en utilisant les plus grandes dénominations possibles. 
        ◦ Exemple :
          Monnaie rendue :
          1 x R$50.00
          1 x R$5.00
          3 x R$0.25
    3. Vérifier le stock :
        ◦ Après chaque transaction, le stock est affiché :
          Stock actuel :
          R$2000.00 : 10
          R$1000.00 : 10
          R$500.00 : 10
          R$200.00 : 10
          R$100.00 : 10
          R$50.00 : 9
          R$25.00 : 10
          R$20.00 : 10
          R$10.00 : 10
          R$5.00 : 9
          R$1.00 : 10
          R$0.25 : 7
    4. Continuer ou quitter :
        ◦ Entrez un nouveau montant ou 0 pour arrêter :
          Programme terminé.
    5. Stock insuffisant :
        ◦ Si la monnaie ne peut être rendue :
          Pas assez de billets/pièces pour rendre la monnaie.
          Voulez-vous remplir la caisse (r) ou arrêter (a) ?
        ◦ Tapez r pour remplir (10 unités par dénomination) :
          Caisse remplie !
          [Monnaie rendue]
        ◦ Tapez a pour arrêter :
          Programme terminé.
        ◦ Autre entrée :
          Choix non valide, arrêt du programme.
    6. Entrées invalides :
        ◦ Montant non numérique (ex. abc) :
          Entrée non valide, essayez encore.
        ◦ Montant négatif (ex. -100) :
          Montant négatif non valide.
4.2. Exemple d’utilisation
Programme de caisse enregistreuse

Entrez le montant à rendre (en centimes, 0 pour quitter) : 5675
Monnaie rendue :
1 x R$50.00
1 x R$5.00
3 x R$0.25

Stock actuel :
R$2000.00 : 10
...
R$50.00 : 9
R$5.00 : 9
R$0.25 : 7

Entrez le montant à rendre (en centimes, 0 pour quitter) : abc
Entrée non valide, essayez encore.

Entrez le montant à rendre (en centimes, 0 pour quitter) : 5675
Pas assez de billets/pièces pour rendre la monnaie.
Voulez-vous remplir la caisse (r) ou arrêter (a) ? r
Caisse remplie !
Monnaie rendue :
1 x R$50.00
1 x R$5.00
3 x
