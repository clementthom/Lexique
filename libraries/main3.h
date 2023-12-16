#ifndef MAIN_3    //nom du fichier .h
#define MAIN_3


size_t strlen(const char* chaine);
int nbChar(char* tableau);
char* strcpy(char* copieDeLaChaine, const char* chaineACopier); //stringcopy
char* strcat(char* chaine1, const char* chaine2); //concatener
int strcmp(const char* chaine1, const char* chaine2); //comparer
char* strchr(const char* chaine, int caractereARechercher); // le caractère est un int      
char* strpbrk(const char* chaine, const char* lettresARechercher);//même qu'avant mais pour plusieurs lettres
char* strstr(const char* chaine1, const char* chaine2);//cherche toute la chaine2 dans chaine1


#endif