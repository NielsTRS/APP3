#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listes.h"

/* fichier à compléter au besoin */

cellule_t *nouvelleCellule() {
    cellule_t *c = malloc(sizeof(cellule_t));
    c->suivant = NULL;
    return c;
}

void init_liste_vide(liste_t *L) {
    L->tete = NULL;
}

void detruireCellule(cellule_t *cell) {
    free(cell);
}

void liberer_liste(liste_t *L) {
    cellule_t *c = L->tete;
    cellule_t *tmp;
    while (c != NULL) {
        tmp = c;
        c = c->suivant;
        detruireCellule(tmp);
    }
}

int ajouter_tete(liste_t *L, string c) { /* retourne 0 si OK, 1 sinon  */
    cellule_t *cell = nouvelleCellule();
    cell->val = c;
    if (L->tete != NULL) {
        cell->suivant = L->tete;
    }
    L->tete = cell;
    return 0;
}

