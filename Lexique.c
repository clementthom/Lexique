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
        afficherMenu();
        choix = choixMenu();
        actionMenu(choix);
        printf("%d", choix);
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
    fopen(nomFichier, "a+");
    fclose(lexique);
}

int scanAfficherDir() { 
    WIN32_FIND_DATA File; 
    HANDLE hSearch; 
  
    int nbFichier = 0;
    hSearch = FindFirstFile("*.*", &File); 
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
  
    hSearch = FindFirstFile("*.txt*", &File); 
    if (hSearch != INVALID_HANDLE_VALUE) 
    { 
        do { 
            printf("%s\n", File.cFileName); 
        } while (FindNextFile(hSearch, &File)); 
  
        FindClose(hSearch); 
    } 
    return 0; 
}


void initialisationLexique() {
    printf("Bienvenue sur votre gestionnaire de lexique !\n\n");
    printf("Voici votre liste de lexiques actuelle : \n\n");
    scanDir();
    
}


void afficherMenu() {
    printf("\nVeuillez choisir une instruction : \n\n");
    printf("1 : Creer un lexique\n");
    printf("2 : Ajouter une entree dans un lexique\n");
    printf("3 : Choisir un fichier a modifier\n");
    printf("4 : Afficher la liste des lexiques\n");
    printf("5 : Quitter le logiciel\n");

    
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


void actionMenu(int choix) {
    switch (choix) {
        case 0 :
            printf("Pas un nombre");
            break;
        case 1 :
            creerFichier();
            break;
        case 4 :
            printf("\nVoici la liste des fichiers : \n");
            scanDir();
            break;
        case 5 :
            printf("\nAu revoir\n");
            exit(EXIT_FAILURE);
            break;
        default :
            printf("\nNombre hors champ.\n");
            break;
    }
}