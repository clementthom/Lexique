#ifndef MAIN_4 
#define MAIN_4  


typedef struct Coordonnees Coordonnees; //le premier est pour la structure, le deuxième pour l'equivalent
typedef struct Personne Pers;

void initialiserCoordonnees(Coordonnees *point);
FILE* fopen(const char* nomDuFichier, const char* modeOuverture); //renvoie FILE*
int fclose(FILE* pointeurSurFichier); //renvoie 0 si le fichier a été fermé, EOF sinon --> erreur   
int fputc(int caractere, FILE* pointeurSurFichier); //met un caractère dans le fichier, renvoie EOF si erreur, un int sinon
int fputs(const char* chaine, FILE* pointeurSurFichier);//pareil mais pour une chaine
int fgetc(FILE* pointeurDeFichier);//retourne le caractère lu, sinon EOF
char* fgets(char* chaine, int NbDeCaracteresALire, FILE* pointeurSurFichier);//pareil mais pour une ligne
long ftell(FILE* pointeurSurFichier); //renvoie le nombre de la position du curseur (long)
int fseek(FILE* pointeurSurFichier, long deplacement, int origine); // on commence à "origine" et on avance de "déplacement"
void rewind(FILE* pointeurSurFichier);
int rename(const char* ancienNom, const char* nouveauNom); //renvoie 0 si renommé, sinon autre chose
int remove(const char* fichierASupprimer);// supprime


typedef enum Volume Volume; //on déclare une énumération
enum Volume{ 
    FAIBLE=10, MOYEN, FORT=100 //les différentes valeurs que peut prendre Volume
}; // si volume = 10, il est déclaré comme faible; par défaut, le compil rajoute 1 pour chaque nouvel élément
// ici, MOYEN = 11 par défaut


struct Coordonnees{
    int x; // abscisses
    int y; //ordonnees
};

struct Personne{

    char nom[100];
    char prenom[100];
    char adresse[1000];

    int age;
    int etudiants; // 1=etudiant, 0=non étudiant

};





#endif