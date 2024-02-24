#ifndef LEXIQUE
#define LEXIQUE


void creerFichier();
int scanAfficheDir();
int scanDir();
void initialisationLexique();
void afficherMenu();
int choixMenu();
void actionMenu(int choix);
FILE *selectionLexiqueDansDossier(char *nomLexique);
int selectionnerFichierDansDossier();
char *changerTitreFichier(int choixLexique, char *nomLexique);
char *donnerNomFichier(FILE *fichier);
FILE *renvoyerFichier(char *nomLexique);
char *entrerMot(int nbChar);
char *lireLigne(FILE *fichier, int numeroLigne);
void actionGererlexique();
void afficherMenuGererlexique();
void afficherMenuModifierLexique();
void actionModifierlexique();



#endif