#ifndef MAIN_5
#define MAIN_5







void* malloc(size_t nombreOctetsNecessaire); //on alloue nombreOctetsNecessaire en mémoire
//void* -> renvoie le pointeur de la zone réservée ; //renvoie NULL si échec
//size_t permet de rendre le pointeur universel (n'importe quel type).
void free(void* pointeur); //libère la mémoire pointée par le pointeur
char *fgets(char *str, int num, FILE *stream);//str : tableau cible pour être écris
//num : taille du tableau str (n + 1 car \0); stream : pointeur du fichier à lire
int lire(char *chaine, int longueur);
void viderBuffer();
long strtol(const char *start, char **end, int base); //start est la chaine de caractère lue
//conversion en long selon la base indiquée par base (ex base 10) et retourne le nombre lu
int lireLong();
double strtod(const char *start, char**end); //pareil que strtol mais pour un double
//ici pas de int base, et on peut lire des décimaux













#endif