#ifndef MAIN_6
#define MAIN_6


typedef struct Element Element; 
typedef struct Liste Liste; //l'ensemble de la liste chaînée


Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
void insertionCiblee(Liste *liste, int nvNombre, int position);
void suppressionCible(Liste *liste, int position);
int tailleListe(Liste *liste);
void destructionListe(Liste *liste);


struct Element {
    int nombre; //on peut faire de manière générique *void au lieu de int, pour tous les types
    Element *suivant; //correspond à l'élement suivant : un lien est crée (ils ne sont pas côte à côte en mémoire)
}; //il n'y a qu'un pointeur : c'est une liste simplement chaînée (on ne connait pas l'élement précédent)

struct Liste {
    Element *premier; //le premier élement de la liste
};


#endif