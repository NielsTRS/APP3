#include <stdio.h>
#include <string.h>
#include "arbres.h"

void dot_generation_rec(arbre a, FILE *f) {

    if (a->gauche != NULL) {
        fprintf(f, "%s -> %s [label = \"non\"]", a->valeur, a->gauche->valeur);
        fprintf(f, "\n");
        dot_generation_rec(a->gauche, f);
    }

    if (a->droit != NULL) {
        fprintf(f, "%s", a->valeur);
        fprintf(f, " -> ");
        fprintf(f, "%s", a->droit->valeur);
        fprintf(f, " [label = \"oui\"]\n");
        fprintf(f, "\n");
        dot_generation_rec(a->droit, f);
    }

}

void dot_generation(arbre a, FILE *f) {
    fprintf(f, "digraph arbre{\n");

    if (a->gauche == NULL && a->droit == NULL) {
        fprintf(f, "%s", a->valeur);
        fprintf(f, "}");
        return;
    }

    dot_generation_rec(a, f);

    if (a == NULL) {
        fprintf(f, "}");
        return;
    }

    fprintf(f, "}");
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Nombre d'arguments souhaités : 2 \n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier d'entrée \n");
        return 1;
    }

    if (out == NULL) {
        printf("Impossible d'ouvrir le fichier de sortie \n");
        return 1;
    }

    arbre a = lire_arbre(f);
    fclose(f);

    dot_generation(a, out);
    fclose(out);

    return 0;
}