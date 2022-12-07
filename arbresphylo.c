#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"

void analyse_arbre(arbre racine, int *nb_esp, int *nb_carac) {
    int espece_d = 0;
    int caractere_d = 0;

    int espece_g = 0;
    int caractere_g = 0;

    if (racine == NULL) {
        *nb_esp = 0;
        *nb_carac = 0;
        return;
    }

    if (racine->droit == NULL && racine->gauche == NULL) { // si racine est une feuille
        *nb_esp = 1;
        *nb_carac = 0;
        return;
    }

    analyse_arbre(racine->gauche, &espece_g, &caractere_g);
    analyse_arbre(racine->droit, &espece_d, &caractere_d);

    *nb_esp = espece_g + espece_d;
    *nb_carac = 1 + caractere_g + caractere_d;
}


/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y mettre les
 * caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 */
int rechercher_espece(arbre racine, char *espece, liste_t *seq) {
    /* à compléter */
    if (racine == NULL) {
        return 1;
    }
    if (strcmp(racine->valeur, espece) == 0) {
        return 0;
    }
    if (rechercher_espece(racine->gauche, espece, seq) == 0) {
        return 0;
    }
    if (rechercher_espece(racine->droit, espece, seq) == 0) {
        ajouter_tete(seq, racine->valeur);
        return 0;
    }
    return 1;
}


/* Doit renvoyer 0 si l'espece a bien ete ajoutee, 1 sinon, et ecrire un
 * message d'erreur.
 */
int ajouter_espece(arbre *a, char *espece, cellule_t *seq) {
    if (seq != NULL) { // si seq n'est pas vide
        if (*a == NULL) { // si l'arbre est null, on crée un noeud
            *a = nouveau_noeud();
            (*a)->valeur = seq->val;
            seq = seq->suivant;
            ajouter_espece(&(*a)->droit, espece, seq);
        } else if (strcmp((*a)->valeur, seq->val) == 0) { // s'il y a une correspondance des caractéristiques
            seq = seq->suivant;
            ajouter_espece(&(*a)->droit, espece, seq);
        } else if ((*a)->gauche == NULL && (*a)->droit == NULL) { // si a est une feuille
            arbre b = nouveau_noeud();
            b->valeur = (*a)->valeur;

            *a = nouveau_noeud();
            (*a)->valeur = seq->val;

            seq = seq->suivant;
            ajouter_espece(&(*a)->droit, espece, seq);

            (*a)->gauche = b;
        } else { // s'il n'y a pas de correspondance des caractéristiques
            ajouter_espece(&(*a)->gauche, espece, seq);
        }
    } else { // seq est vide
        if (*a == NULL) { // si l'arbre est null, on crée un noeud
            *a = nouveau_noeud();
            (*a)->valeur = espece;
        } else {
            printf("Ne peut ajouter <%s>: possède les mêmes caractères que <%s>.\n", espece, (*a)->valeur);
            return 1;
        }
    }
    return 0;
}

/* Doit afficher la liste des caractéristiques niveau par niveau, de gauche
 * à droite, dans le fichier fout.
 * Appeler la fonction avec fout=stdin pour afficher sur la sortie standard.
 */
void afficher_par_niveau(arbre racine, FILE *fout) {
    printf("<<<<< À faire: fonction afficher_par_niveau fichier " __FILE__ "\n >>>>>");
}

// Acte 4


int ajouter_carac(arbre *a, char *carac, cellule_t *seq) {
    printf("<<<<< À faire: fonction ajouter_carac fichier " __FILE__ "\n >>>>>");
    return 0;
}
