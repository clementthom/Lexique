#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //permet de manipuler les directories


#include "libraries\main3.h"
#include "libraries\main4.h"
#include "libraries\main5.h"
#include "libraries\main6.h"
#include "libraries\main7.h"
#include "libraries\lexique.h"



int main(int args, char *argv[]) {
    int nombreElement = scanDir();
    int choix = 2;
    initialisationLexique();
    do {
        afficherMenuPrincipal();
        choix = choixMenu();
        actionMenuPrincipal(choix);
        //exit(EXIT_FAILURE);
    } while (choix!=5);
}



void creerFichier() {
    char *nomLexique = NULL;
    nomLexique = malloc(sizeof(char) * 10);
    printf("\n\nChoisissez un nom de fichier : \n");
    nomLexique = fgets(nomLexique, sizeof(char) * 10, stdin);
    FILE *lexique = NULL;
    char *nomFichier = NULL;
    nomFichier = malloc(sizeof(char) * 15); 
    nomLexique[strlen(nomLexique)-1] = '\0';
    nomFichier = strcat(nomLexique, ".txt");
    lexique = fopen(nomFichier, "a+");
    nomLexique[strlen(nomLexique)-4] = '\0';//on vire le .txt
    fprintf(lexique, "            %s\n\n", nomLexique);
    fclose(lexique);

}

int scanAfficherDir() { 
    WIN32_FIND_DATA File; 
    HANDLE hSearch; 
  
    int nbFichier = 0;
    hSearch = FindFirstFile("*.txt*", &File); 
    if (hSearch != INVALID_HANDLE_VALUE) 
    { 
        do { 
            printf("%s\n", File.cFileName);
            nbFichier ++; 
        } while (FindNextFile(hSearch, &File)); 
  
        FindClose(hSearch); 
    } 
    return nbFichier; 
}


int scanDir() { 
    WIN32_FIND_DATA File; 
    HANDLE hSearch;
    int totalFileNumber= 0; 
  
    hSearch = FindFirstFile("*.txt*", &File); 
    if (hSearch != INVALID_HANDLE_VALUE) 
    { 
        do { 
            printf("%s\n", File.cFileName);
            totalFileNumber ++;
        } while (FindNextFile(hSearch, &File)); 
  
        FindClose(hSearch); 
    } 
    return totalFileNumber; 
}


void initialisationLexique() {
    printf("Bienvenue sur votre gestionnaire de lexique !\n\n");
    printf("Voici votre liste de lexiques actuelle : \n\n");
    scanDir();
    
}

void afficherMenuPrincipal() {
    printf("\nVeuillez choisir une instruction : \n\n");
    printf("1 : Creer un lexique\n");
    printf("2 : Ajouter une entree dans un lexique\n");
    printf("3 : Choisir un fichier a modifier\n");
    printf("4 : Gerer les lexiques\n");
    printf("5 : Quitter le logiciel\n");
}

void afficherMenuGererlexique() {
    printf("\nVeuillez choisir une instruction : \n\n");
    printf("1 : Afficher la liste des lexiques\n");
    printf("2 : Afficher le contenu du lexique\n");
    printf("3 : Supprimer un lexique\n");
    printf("4 : Annuler\n");
}
void afficherMenuModifierLexique() {
    printf("\nVeuillez choisir une instruction : \n\n");
    printf("1 : Supprimer une entrée\n");
    printf("2 : Renommer un lexique\n");
    printf("3 : Annuler\n");
}

int choixMenu() {
    int choixMenu = 0;

    const int bufsize = 100;
    char buf[bufsize];

    int ret;
    // char word[bufsize];
    fgets(buf, bufsize, stdin);

    ret = sscanf(buf, "%d", &choixMenu);

    if (ret != 1) {
        fprintf(stderr, "J'ai dit un nombre abruti !!!\n");
        return 0;
    }

    printf("\n%d", choixMenu);
    return choixMenu;
}

void actionMenuPrincipal(int choix) {
    switch (choix) {
        case 0 : 
            printf("L'entree n'est pas un nombre.\n");
            break;
        case 1 : 
            creerFichier();
            break;
        case 2 :
            ajouterEntreeLexique();
            break;
    }

}

void ajouterEntreeLexique() {
    FILE *fichier = NULL;
    fichier = selectionnerFichierDansDossier();
    entrerDonneeDansLexique(fichier);
}

FILE *selectionnerFichierDansDossier() {
    WIN32_FIND_DATA File;
    HANDLE hSearch;
    FILE *fichier = NULL;

    //3 étapes dans cette fonction
    //1 : on affiche les fichiers
    int numberOfFiles = scanDir();
    //2 : on selectionne le fichier voulu
    printf("Veuillez choisir un nombre.\n");
    int choix = choixMenu();
    while(choix <1 || choix>numberOfFiles) {
        if (choix == 0) {
            printf("Saisie incorrecte. Veuillez entrer un nombre.\n");
        }
        if (choix > numberOfFiles || choix < 0) {
            printf("Nombre hors champ.\n");
        }
        printf("Veuillez saisir un nombre.\n");
        choix = choixMenu();
    }
    //3 : on selectionne le fichier (voir la fonction retournerFichier)
    fichier = retournerFichier(choix);
    return fichier;
}

FILE *retournerFichier(int indexFichier) {
    WIN32_FIND_DATA File;
    HANDLE hSearch;
    FILE *fichier = NULL;

    hSearch = FindFirstFile("*.txt", &File);
    char *nomFichier = NULL;
    if (hSearch != INVALID_HANDLE_VALUE) {
        for (int i = 0; i < indexFichier; i++) {
            FindNextFile(hSearch, &File);
            nomFichier = malloc(sizeof(char)*100);
            nomFichier = File.cFileName;
        }
        FindClose(hSearch); 
    }
    fichier = fopen(nomFichier, "r+");
    fclose(fichier);
    return fichier;
} 

void entrerDonneeDansLexique(FILE *fichier) {
    char *entree = NULL;
    entree = malloc(sizeof(char)*100);
    printf("Veuillez saisir l'entree a ajouter:\n");
    char *fgetsCheck = fgets(entree, sizeof(char) * 100, stdin);
    while (!fgetsCheck){
        printf("Entree trop longue ou incorrecte.\n");
        fgetsCheck = fgets(entree, sizeof(char) * 100, stdin);
    }


}

/**
 * permet de relever l'index d'un fichier en particulier dans son dossier
 * @param : fichier (FILE) dont on veut connaitre l'index
 * @return : la position (int) du fichier dans son dossier
*/
int trouverIndexFichier(FILE *fichier) {
    WIN32_FIND_DATA File;
    HANDLE hSearch;
    int index = 1;

    hSearch = FindFirstFile("*.txt", &File);
    if(hSearch != INVALID_HANDLE_VALUE) {
        do{
            if(fichier == fopen(File.cFileName, "a+")) {
                return index;
            }
            index++;
        }while(FindNextFile(hSearch, &File));
    }
    return 0; //erreur si 0 retourné
}
 char *retournerNomFichier(int indexFichier) {
    WIN32_FIND_DATA File;
    HANDLE hSearch;
    char *nomFichier;

    hSearch = FindFirstFile("*.txt", &File);
    if (hSearch != INVALID_HANDLE_VALUE) {
        for (int i =1; i<indexFichier; i++) {
            FindNextFile(hSearch, &File);
        }
        nomFichier = File.cFileName;
    }

    return nomFichier;
 }