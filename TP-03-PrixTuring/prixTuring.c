/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

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
	char nom[256];
	char description[256];
 } Winner;

int numberOfWinners(FILE *file){
	int count=0;
	char caractere=0;
	while ((caractere=fgetc(file))!=EOF){
		if(caractere =='\n'){
			count++;
		}
	}
	rewind(file);
	return count;
}

void readWinners(FILE *file, Winner *winners,int nombre_de_gagnant){
	for (int i = 0; i< nombre_de_gagnant;i++){
		fscanf( file,"%d;%255[^;];%255[^;\n]\n", &winners[i].annee,winners[i].nom,winners[i].description);

	}
}

void printWinners(FILE *file, Winner *winners,int nombre_de_gagnant){
	for (int i = 0; i< nombre_de_gagnant;i++){
		fprintf( file, "%d;%s;%s\n", winners[i].annee,winners[i].nom,winners[i].description);
		printf("%d;%s;%s\n \n", winners[i].annee,winners[i].nom,winners[i].description);
}
}


int main(int argc, char** argv){
	char *filename = "turingWinners.csv";
	char *outputFilename= "out.csv";

    // TODO
	FILE *inputFile = fopen(filename, "r");
	FILE *outputFile = fopen(outputFilename,"w");
	
	
	int nombre_de_gagnant=numberOfWinners(inputFile);
	Winner *winners = malloc(nombre_de_gagnant * sizeof(Winner));
	readWinners(inputFile, winners, nombre_de_gagnant);
	printWinners(outputFile,winners,nombre_de_gagnant);



	return EXIT_SUCCESS;
}


