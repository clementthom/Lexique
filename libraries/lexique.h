#ifndef LEXIQUE
#define LEXIQUE

typedef struct EntreeLexique EntreeLexique; 



void creerFichier();
int scanAfficheDir();
int scanDir();
void initialisationLexique();
void afficherMenuPrincipal();
int choixMenu();
void actionMenuPrincipal(int choix);
void ajouterEntreeLexique();
FILE *selectionnerFichierDansDossier();
FILE *retournerFichier(int indexFichier);
void entrerDonneeDansLexique(FILE *fichier);
int trouverIndexFichier(FILE *fichier);
char *retournerNomFichier(int indexFichier); //ln227
void actionModifierLexique();
void supprimerEntree();
void renommerLexique();
void actionGererLexique();
void afficherContenuLexique();
void supprimerLexique();
EntreeLexique *initialiserTableauEntree(FILE *lexique);
void scannerFichier (FILE *lexique);
void afficherContenu (EntreeLexique *tableauEntree);




struct EntreeLexique {
    int ligne;
    char *contenu; //on ne peut pas faire de malloc dans la déclaration de structure
};


#endif