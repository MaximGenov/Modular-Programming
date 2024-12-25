#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Global variables used to test parse
//int glob;
//int glob2;
void parse(char *str, int *coeff, int *expo){
	//Read numbers: convert string to integer

	//First Number in line
	*coeff = atoi(str);
	
	//Second parameter in line
	str++;
	while(*str != ' ') str++;
	str++;
	
	*expo = atoi(str);

}
int powi(int x, int expo){
	//Base case --> b^0 = 1
	int val = 1;
	for(int i = 0; i < expo; i++){
		val *= x;
		//printf("%d\n", val);
	}	
	return val;
}

//Main used to test two functions above
/*int main(int argc, char *argv[]){
	FILE *f = fopen(argv[1], "r");
	char data[60];
	fgets(data, 60, f);
	int *co = &glob;
	int *ex = &glob2;
	parse(data, co, ex);
	printf("coeff: %d\n", *co);
	printf("expo: %d\n", *ex);
}*/
