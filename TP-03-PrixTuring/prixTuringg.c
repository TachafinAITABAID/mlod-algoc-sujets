#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

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
        printf("%d;%s;%s\n \n", winners[i].annee, winners[i].nom, winners[i].description);
    }
}

int main(int argc, char **argv) {
    char *filename = "turingWinners.csv";
    char *outputFilename = "out.csv";

    // TODO
    FILE *inputFile = fopen(filename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    int nombre_de_gagnant = numberOfWinners(inputFile);
    Winner *winners = malloc(nombre_de_gagnant * sizeof(Winner));
    readWinners(inputFile, winners, nombre_de_gagnant);
    printWinners(outputFile, winners, nombre_de_gagnant);
    return EXIT_SUCCESS;
}