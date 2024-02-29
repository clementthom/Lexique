#ifndef LEXIQUE
#define LEXIQUE


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



#endif