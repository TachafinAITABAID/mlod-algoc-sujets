#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct {
    int annee;
    char *nom;
    char *description;
} Winner;

int numberOfWinners(FILE *file) {
    int count = 0;
    char caractere = 0;
    while ((caractere = fgetc(file)) != EOF) {
        if (caractere == '\n') {
            count++;
        }
    }
    rewind(file);
    return count;
}

void readWinners(FILE *file, Winner *winners, int nombre_de_gagnant) {
    for (int i = 0; i < nombre_de_gagnant; i++) {
        char buffer[256];
        int annee;
        if (fscanf(file, "%d;", &annee) != 1) {
            fprintf(stderr, "Erreur lors de la lecture de l'année.\n");
            exit(EXIT_FAILURE);
        }
        winners[i].annee = annee;
        if (fscanf(file, "%255[^;];", buffer) != 1) {
            fprintf(stderr, "Erreur lors de la lecture du nom.\n");
            exit(EXIT_FAILURE);
        }
        winners[i].nom = strdup(buffer); 
        if (winners[i].nom == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire pour le nom.\n");
            exit(EXIT_FAILURE);
        }
        if (fscanf(file, "%255[^;\n]\n", buffer) != 1) {
            fprintf(stderr, "Erreur lors de la lecture de la description.\n");
            exit(EXIT_FAILURE);
        }
        winners[i].description = strdup(buffer); 
        if (winners[i].description == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire pour la description.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printWinners(FILE *file, Winner *winners, int nombre_de_gagnant) {
    for (int i = 0; i < nombre_de_gagnant; i++) {
        fprintf(file, "%d;%s;%s\n", winners[i].annee, winners[i].nom, winners[i].description);
        //printf("%d;%s;%s\n \n", winners[i].annee, winners[i].nom, winners[i].description);
    }
}

void afficherGagnant(Winner *gagnant) {
    printf("L'année %d, le(s) gagnant(s) ont été : %s\n", gagnant->annee, gagnant->nom);
    printf("Nature des travaux : %s\n", gagnant->description);
}

void infosAnnee(int annee, Winner *gagnants, int nombre_de_gagnants) {
    int anneeTrouvee = 0; 

    for (int i = 0; i < nombre_de_gagnants; i++) {
        if (gagnants[i].annee == annee) {
            afficherGagnant(&gagnants[i]);
            anneeTrouvee = 1; 
        }
    }

    if (!anneeTrouvee) {
        printf("Aucun gagnant trouvé pour l'année %d.\n", annee);
    }
}

int comparerAnnee(const void *a, const void *b) {
    const Winner *winnerA = (const Winner *)a;
    const Winner *winnerB = (const Winner *)b;
    return winnerA->annee - winnerB->annee;
}

void sortTuringWinnersByYear(Winner *gagnants, int nombre_de_gagnants) {
    qsort(gagnants, nombre_de_gagnants, sizeof(Winner), comparerAnnee);
}

void writeSortedWinnersToFile(const char *filename, Winner *gagnants, int nombre_de_gagnants) {
    FILE *outputFile = fopen(filename, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier de sortie.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nombre_de_gagnants; i++) {
        fprintf(outputFile, "%d;%s;%s\n", gagnants[i].annee, gagnants[i].nom, gagnants[i].description);
    }

    fclose(outputFile);
}
int main(int argc, char **argv) {
    char *filename = "turingWinners.csv";
    char *outputFilename = "out.csv";
    int sortRequested = 1;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            outputFilename = argv[i + 1];
            i++; 
        } else {
            filename = argv[i];
        }
    }



    // TODO
    FILE *inputFile = fopen(filename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    int nombre_de_gagnant = numberOfWinners(inputFile);
    Winner *winners = malloc(nombre_de_gagnant * sizeof(Winner));
    readWinners(inputFile, winners, nombre_de_gagnant);
    printWinners(outputFile, winners, nombre_de_gagnant);
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--info") == 0 && i + 1 < argc) {
            int annee = atoi(argv[i + 1]); 
            infosAnnee(annee, winners, nombre_de_gagnant);
            return EXIT_SUCCESS;
        }
    }
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--sort") == 0) {
            sortRequested = 1;
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            outputFilename = argv[i + 1];
            i++; 
        }
    }
    if (sortRequested) {
        sortTuringWinnersByYear(winners, nombre_de_gagnant);
        writeSortedWinnersToFile(outputFilename, winners, nombre_de_gagnant);
    } else {
    
        FILE *outputFile = fopen(outputFilename, "w");
        if (outputFile == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier de sortie.\n");
            exit(EXIT_FAILURE);
        }
        printWinners(outputFile, winners, nombre_de_gagnant);
    }

    return EXIT_SUCCESS;
}


