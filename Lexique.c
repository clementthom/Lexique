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
    printf("4 : Gerer les lexiques\n");
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
        case 2 :
            char *currentFileName = NULL;
            printf("Selectionner un lexique : \n");
            FILE *currentFile = NULL;
            currentFile = SelectionLexiqueDansDossier(&currentFileName);
            if(currentFile == NULL) {
                printf("Il n'y a pas de lexiques crees !\n\n");
                break;
            }
            //le & permet de changer la valeur du pointeur dans la fonction
            printf("Entrer votre saisie (200 caractères max) : \n");
            fprintf(currentFile, " - ");
            fprintf(currentFile, "%s", entrerMot(200));
            fclose(currentFile);
            break;
        case 3 :
            actionModifierlexique();
            break;
        case 4 :
            actionGererlexique();
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

FILE *SelectionLexiqueDansDossier(char *nomLexique) { //on va modifier nomLexique dans la fonction
    WIN32_FIND_DATA File; 
    HANDLE hSearch;
    HANDLE hSearch2; 
    //affiche les fichiers texte
    hSearch = FindFirstFile("*.txt*", &File);

    int fileIndex = 0; 
    if (hSearch != INVALID_HANDLE_VALUE) 
    { 
        do { 
            fileIndex ++;
            printf("%d : %s\n", fileIndex, File.cFileName); 
        } while (FindNextFile(hSearch, &File)); 
  
        FindClose(hSearch); 
    }
    //selectionner le fichier texte
    FILE *fichier = NULL;
    if(fileIndex==0) {
        return fichier;
    } 
    int choixLexique = choixMenu();//choixMenu sert ici à selectionner un entier
    while(choixLexique<=0 || choixLexique>fileIndex) {
        printf("\n\nHors champ. \n Reentrez un nombre.\n\n");
        choixLexique = choixMenu();
    }
    hSearch2 = FindFirstFile("*.txt*", &File);
    if (hSearch != INVALID_HANDLE_VALUE) { 
        for (int i = 1; i<choixLexique; i++) {
            FindNextFile(hSearch, &File);
        }
        for (int i = 0; i < 25; i++) {
            nomLexique[i] = File.cFileName[i];
        }
        //*(nomLexique) =  File.cFileName;//le nom du fichier est donné en RAM avec .txt
        fichier = fopen(nomLexique, "a+"); 
        FindClose(hSearch2);    
    }
    return fichier; 
}

char *entrerMot(int nbChar) { //permet de renvoyer des mots de nbChar caractères
    char *mot = NULL;
    mot = malloc(sizeof(char)*nbChar+5); //+5 par sécurité
    mot = fgets(mot, sizeof(char) * nbChar, stdin);
    /*while(*mot = EOF){
        printf("Saisie trop longue. Veuillez essayer avec moins de caractères.");
        mot = fgets(mot, sizeof(char) * 10, stdin);
    }*/
    return mot;
    
}

char *lireLigne(FILE *fichier, int numeroLigne) {//lit la ligne jusqu'au saut de ligne
    char *contenuLigne = NULL;
    contenuLigne = malloc(sizeof(fichier));
    int nbSautDeLigneCurseur = 0;
    fseek(fichier, 0, SEEK_SET);//on met le curseur au début du fichier
    char caractereLu;    
    do {
        caractereLu = fgetc(fichier);
        fseek(fichier, 1, SEEK_CUR); //on fait avancer le curseur de 1
    }while(caractereLu != '\n');
        nbSautDeLigneCurseur ++;
    fseek(fichier, 1, SEEK_CUR);//on est à la ligne souhaitée
    int tailleLigne = 1;
    caractereLu = fgetc(fichier);
    while(caractereLu != '\n') {
        *(&contenuLigne+1) = &caractereLu;
        caractereLu = fgetc(fichier);
    }
    printf("%s", &contenuLigne);
    printf("hoa");
    return contenuLigne;
}

void actionGererlexique() {
    afficherMenuGererlexique();
    int choix = choixMenu();
    switch(choix) {
        case 0 :
            printf("Pas un nombre");
            break;
        case 1 :
            printf("\nVoici la liste des fichiers : \n");
            scanDir();
            break;
        case 2 :
            char currentFileName[25];
            printf("Selectionner un lexique : \n");
            FILE *currentFile = NULL;
            currentFile = SelectionLexiqueDansDossier(currentFileName);
            if(currentFile == NULL) {
                printf("Il n'y a pas de lexiques crees !\n\n");
                break;
            }
            break;
        case 3 : // supprimer fichier
            printf("Selectionner un lexique : \n");
            currentFile = fopen(currentFileName, "a+");
            currentFile = SelectionLexiqueDansDossier(currentFileName);
            if(currentFile == NULL) {
                printf("Il n'y a pas de lexiques crees !\n\n");
                break;
            }
            int removeWorked = remove(currentFileName);
            fclose(currentFile);
            break;
        case 4 :
            break;
        default :
            printf("\nNombre hors champ.\n");
            break;
    }
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

void actionModifierlexique() {
    afficherMenuModifierLexique();
    int choix = choixMenu();
    switch(choix) {
        case 1 : // supprimer une entrée
            
        case 2 : //renommer un lexique
            char currentFileName[25];
            char *nouveauNom = NULL;
            nouveauNom = malloc(sizeof(char)*25);
            printf("Selectionner un lexique : \n");
            FILE *currentFile = SelectionLexiqueDansDossier(currentFileName);
            if(currentFile == NULL) {
                printf("Il n'y a pas de lexiques crees !\n\n");
                break;
            }//à ce stade on a obtenu le nom du fichier -> utilisé dans rename
            int test = 4;
            printf("test");
            printf("\nVeuillez entrer un nom.\n");
            nouveauNom = fgets(nouveauNom, sizeof(char)*25, stdin);
            //fclose(currentFile);//on doit fermer le fichier pour le renommer
            int renameSuccessful = rename(currentFileName, nouveauNom);
            if (renameSuccessful != 0) {
                perror("Error");//motre le type d'erreur
            }
            printf("\nFichier renommé avec succes.Nouveau nom : .\n");
        default :
    }
}