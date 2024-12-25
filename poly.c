#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct PolyTerm
{
	int coeff;
	int expo;
	struct PolyTerm *next;
};

struct PolyTerm *head = NULL;

int addPolyTerm(int coeff, int expo){
	
	//first case: polynomial is empty, set new term to head
	if(head == NULL){
		struct PolyTerm *newTerm;
		newTerm = malloc(sizeof(struct PolyTerm));
		if (newTerm == NULL) return (-1);
		
		//Set data
		newTerm->coeff = coeff;
		newTerm->expo = expo;
		
		//Base case: Next node of 1st term points to null
		newTerm->next = head;
		head = newTerm;
		//printf("head expo: %d\n", head->expo);
		return 0;

	}
	//printf("head expo: %d\n\n\n", head->expo);
	//search for exponent in polynomial, and add to coefficient if found
	struct PolyTerm *current = head;
	//printf("current coeff: %d\nNew term coeff: %d\n", current->coeff, coeff);
	//printf("current expo: %d\nNew term expo: %d\n", current->expo, expo);
	while(current != NULL){
		if(current->expo == expo){
			current->coeff += coeff;
			return 0;
		}
		;
		current = current->next;
	}
	
	//can now assume the exponent is not in the polynomial
	//create new term
	struct PolyTerm *newTerm;
	newTerm = malloc(sizeof(struct PolyTerm));
	if (newTerm == NULL) return -1;

	//defines newterm values
	newTerm->coeff = coeff;
	newTerm->expo = expo;

	//now find where it should be in linked list
	//check head first
	current = head;
	if (newTerm->expo < current->expo){
		newTerm->next = head;
		head = newTerm;
		return 0;
	}

	//now check for the rest of list
	while(current->next != NULL){
		//puts("Enters while");
		if(newTerm->expo < current->next->expo){
			//insert newTerm after current
			newTerm->next = current->next;
			current->next = newTerm;
			//head = newTerm;
			
			//newTerm->next = current->next;
			//current->next = newTerm;
			//puts("Enters if");
			return 0;
		}
		current = current->next;
	}
	//add to end of list
	newTerm->next = current->next;

	current->next = newTerm;
	
	//head = newTerm;
	//newTerm -> next = head;
	//head = newTerm;
	return 0;
}

void displayPolynomial(){
	//create a pointer to iterate through the list
	struct PolyTerm *cur = head;
	
	//now loop through list and print each term
	//note that this is reliant on list being sorted in addPolyTerm
	while(cur != NULL){
		//checks for if cur is the first term and sign of coeff	
		if(cur == head){
			printf("%dx%d", cur->coeff, cur->expo);
		} else if(cur->coeff < 0){
			printf("%dx%d", cur->coeff, cur->expo);
		} else {
			printf("+%dx%d", cur->coeff, cur->expo);
		}
		cur = cur->next;
	}
	//now print newline
	printf("\n");
	
}

int evaluatePolynomial(int x){
	//traverse linked list, get values for coefficient and exponent from each node
	int runningtotal = 0;
	int coeff;
	int exp;
	struct PolyTerm *current = head;
	//traverses the list
	while (current != NULL) {
		coeff = current->coeff;
		exp = current->expo;
		runningtotal += (powi(x, exp))*coeff;
		current = current->next;
	}
	return runningtotal;
}

//helper funtion to free the linked list since nodes use malloc
void freePolynomial(){
	struct PolyTerm *cur = head;
	struct PolyTerm *tmp;

	while(cur != NULL){
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

//temporary main for testing
/*
int main(){
	addPolyTerm(1,3);
	displayPolynomial();
	printf("%d\n", evaluatePolynomial(3));

	addPolyTerm(1,4);
	displayPolynomial();

	addPolyTerm(1,3);
	displayPolynomial();

	addPolyTerm(3,2);
	displayPolynomial();	
	printf("%d\n", evaluatePolynomial(3));
}
*/
