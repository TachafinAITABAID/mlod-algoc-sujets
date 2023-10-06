#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";
bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

// =============
void statistics(const char *sequence, double *tableau) {
    int longueur = strlen(sequence);
    int countA = 0, countT = 0, countC = 0, countG = 0;

    for (int i = 0; i < longueur; i++) {
        char nucleotide = sequence[i];
        switch (nucleotide) {
            case 'A':
                countA++;
                break;
            case 'T':
                countT++;
                break;
            case 'C':
                countC++;
                break;
            case 'G':
                countG++;
                break;
        }
    }

  
    tableau[0] = (double) (countA * (100 / longueur));
    tableau[1] = (double) (countT * (100 / longueur));
    tableau[2] = (double) (countC * (100 / longueur));
    tableau[3] = (double) (countG * (100 / longueur));
}

typedef struct {
    int index;     
    int distance;  
} Difference;

Difference* computeDifferenceBetween(const char *sequence1, const char *sequence2) {
    int len = strlen(sequence1);
    Difference *differences = NULL;
    int diffIndice = 0;
    for (int i = 0; i < len; i++) {
        char nucleotide1 = sequence1[i];
        char nucleotide2 = sequence2[i];
        if (nucleotide1 != nucleotide2) {
            differences = (Difference *)realloc(differences, (diffIndice + 1) * sizeof(Difference));
            differences[diffIndice].index = i;
            differences[diffIndice].distance = distanceBetweenNucleotides(nucleotide1, nucleotide2);
            diffIndice++;
        }
    }

    return differences;
}

void printDifferences( Difference* difference ){
	for (int i = 0; difference[i].index > 0; i++) {
        printf("<%d,%d> ", difference[i].index, difference[i].distance);
		printf("\n");
    }
}

// =============





// ========
// = Main =
// ========

int main(void){
	const char *sequence = "AAGCTTTACA";
    double result[4];

    statistics(sequence, result);


	printf("<%.2f,%.2f,%.2f,%.2f>",result[0],result[1],result[2],result[3]);
	printf("\n");
	//const char *sequence1="ATGCAAAT";
	//const char *sequence2 ="ATCGAAAG";
	const char *sequence1 = code_proteine_spike_pfizer;
    const char *sequence2 = code_proteine_spike_moderna;

    Difference *differences = computeDifferenceBetween(sequence1, sequence2);
	printDifferences(differences);
	//printf("<%d,%d> ", differences[358].index, differences[358].distance);
    free(differences);

	//char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

    //printf("%s\n",code_proteine_spike_moderna);

	return EXIT_SUCCESS;
}

