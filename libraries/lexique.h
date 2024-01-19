#ifndef LEXIQUE
#define LEXIQUE


void creerFichier();
int scanAfficheDir();
int scanDir();
void initialisationLexique();
void afficherMenu();
int choixMenu();
void actionMenu(int choix);
FILE *SelectionLexiqueDansDossier(char **nomLexique);
char *entrerMot(int nbChar);
char *lireLigne(FILE *fichier, int numeroLigne);


#endif