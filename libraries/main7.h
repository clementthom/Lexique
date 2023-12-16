#ifndef MAIN_7
#define MAIN_7



typedef struct Pile Pile;
typedef struct File File;



void empiler(Pile *pile, int nvNombre);
int depiler(Pile *pile);
void afficherPile(Pile *pile);
Pile *initialisationPile();
File *initialisationFile();
void enfiler(File *file, int nvNombre);
int defiler(File *file);
void afficherFile(File *file);


struct Pile {
    Element *premier;
};
struct File {
    Element *premier;
};




#endif