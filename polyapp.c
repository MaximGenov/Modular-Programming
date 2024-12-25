#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poly.h"
#include "utils.h"

//Main file

int main(int argc, char *argv[]){
	FILE *f = fopen(argv[1], "r");
	
	//Global variables to allocate memory to pointers --> otherwise segmentation error
	int glob1;
	int glob2;
	
	//Case 0: File cannot open ==> error code 1
	if(f == NULL){
		puts("File could not open.");
		return 1;
	}
	//Extract polynomial parameters from file
	int errc; //error code for addPolyTerm
	
	//Allocate memory to two pointers
	char line[60];
	int *coeff = malloc(sizeof(int));//&glob1;
	int *expo = malloc(sizeof(int));//&glob2;
	 fgets(line, 60, f);
	
	while(!feof(f)){
		//Get input line
		//char line[60];

		//Allocate memory to two pointers
		//int *coeff = malloc(sizeof(int));//&glob1;
		//int *expo = malloc(sizeof(int));//&glob2;
		
		//fgets(line, 60, f);
		
		parse(line, coeff, expo);
		
		//Get error code for addPolyTerm
		errc = addPolyTerm(*coeff, *expo);
		if(errc != 0){
			//Polynomial node could not be created
			puts("Could not create polynomial out of input\n");
			exit(1);
		}
		fgets(line, 60, f);
		//free(coeff);
		//free(expo);
		
	}
	
	free(coeff);
        free(expo);

	displayPolynomial();
	//Evaluation of polynomial for values hereby
	for(int x = -2; x <= 2; x++){
		int val = evaluatePolynomial(x);
		printf("for x = %d, y = %d\n", x, val);
	}
	freePolynomial();	
	fclose(f);
	return 0;
}
