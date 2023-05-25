#include <stdio.h>
#include <string.h>

// Définition des constantes pour le nombre maximal de formules et la longueur du nom / de la description
#define MAX_FORMULES 100
#define MAX_LONGUEUR_NOM 50
#define MAX_LONGUEUR_DESCRIPTION 500

// Définition des types de formules mathématiques
typedef enum {
    ALGEBRE,
    CALCUL_INTEGRAL,
    GEOMETRIE,
    STATISTIQUES,
    TRIGONOMETRIE,
    TYPE_MATH_COUNT
} TypeMath;

// Définition de la structure pour une formule mathématique
typedef struct {
    char nom[MAX_LONGUEUR_NOM];
    char description[MAX_LONGUEUR_DESCRIPTION];
    TypeMath type;
} FormuleMath;

// Déclaration du tableau global de formules et du compteur de formules
FormuleMath formules[MAX_FORMULES];
int nombreFormules = 0;

// Tableau des noms des types de mathématiques pour l'affichage
const char* nomsTypeMath[TYPE_MATH_COUNT] = {
    "Algèbre",
    "Calcul intégral",
    "Géométrie",
    "Statistiques",
    "Trigonométrie"
};

// Fonction pour obtenir le type de mathématiques de l'utilisateur
TypeMath entrerTypeMath() {
    int choix;

    // Boucle jusqu'à ce que l'utilisateur entre un choix valide
    do {
        printf("Entrez le type de la formule:\n");

        for (int i = 0; i < TYPE_MATH_COUNT; i++) {
            printf("%d. %s\n", i + 1, nomsTypeMath[i]);
        }

        scanf("%d", &choix);
        // Vide le tampon d'entrée
        while (getchar() != '\n');
    } while (choix < 1 || choix > TYPE_MATH_COUNT);

    return choix - 1;
}

// Fonction pour obtenir une chaîne de l'utilisateur
void entrerChaine(char* tampon, int longueur) {
    fgets(tampon, longueur, stdin);

    // Supprime le caractère de nouvelle ligne si présent
    size_t len = strlen(tampon);
    if (len > 0 && tampon[len - 1] == '\n') {
        tampon[len - 1] = '\0';
    }
}

// Fonction pour ajouter une nouvelle formule
void ajouterFormule() {
    if (nombreFormules >= MAX_FORMULES) {
        printf("Désolé, nous ne pouvons pas ajouter plus de formules.\n");
        return;
    }

    char nom[MAX_LONGUEUR_NOM];
    char description[MAX_LONGUEUR_DESCRIPTION];
    TypeMath type;

    printf("Entrez le nom de la formule:\n");
    entrerChaine(nom, MAX_LONGUEUR_NOM);

    printf("Entrez la description de la formule:\n");
    entrerChaine(description,
