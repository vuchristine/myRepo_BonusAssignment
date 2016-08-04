#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*******************************************************
	//1 mark
	//write a function "allocate10" that allocates space for 10 integer using the parameter list
	//in other words the function is of VOID type, takes a parameter and allocates and assigns memory to that parameter
	//call the function to allocate and assign memory to a
	//use a loop in the function to assign a[0] to a[9] to integers 0 to 9
	//print the values out one per line in the main program
	//To be clear - the memory is allocated and assigning values happens in the function
	//in the main function
 //free the memory in a
 //*******************************************************

 void allocate10(char **a) {
	 //variables
	 int i = 0;

	 //create memory for a
	 *a = malloc(10*sizeof(int));

	 //for as long as max number in array is not reached
	 for(i = 0; i < 10; i++) {
		 //create memory for each value of a
		 (*a)[i] = i;

		 //print out each value
		 fprint(stderr, "allocate10: a[%d]: %d\n", (*a)[i], i);
	 }
 }

 //*******************************************************
 //1 mark
 //Write a function "joinStrings" takes as parameters 3 strings. It joins the first 2 together and puts the result in the third string
 //The function allocates memory for the third string using malloc
 //apply the function to strings b,c, and d. After the function is done d should have memory allocated to it and contain "Hello World"
 //the function should not assume the sizes of b or c - it needs to be general enough for any string
 //after calling the function using b,c,d as parameters print out d from the main function
 //free the memory in d
 //*******************************************************

 void joinStrings(char *stringOne, char *stringTwo, char **stringThree) {
	 //create an array to fit two words and space
	 char words[strlen(stringOne) + strlen(stringTwo) + 1];

	 //join strings b and c
	 strcpy(words, stringOne);
	 strcat(words, stringTwo);

	 //create memory for third string
	 *stringThree = malloc(sizeof(words)*sizeof(char));

	 //copy the values of the word array into d
	 strcpy(*stringThree, words);

	 //print out d
	 fprint(stderr, "joinStrings: d: %s\n", *stringThree);
 }

 //*******************************************************
 //1 mark
 //write a function "arrayWrite" that takes as parameters an array of the same type as e, the size of the first dimension, and a string variables, binaryFilename
 //the function "arrayWrite" writes the values of the the array (starting from array[0][0] and ending at array[size-1][2]) to the binaryFilename
 //apply the function to array e and file1
 //*******************************************************

void arrayWrite(int array[][3], int row, char *binaryFile) {
	//variables
	int i = 0;
	int j = 0;
	FILE *fp;
	int buffer[100];

	//open binary file
	fp = fopen(binaryFile, "w");

	//if binary file is empty
	if(fp == NULL) {
		printf("Error: This file doesn't exist\n");
		printf("File is being created.\n");
	}

	//for as long as the max rows is not reached
	for(i = 0; i < (row - 1); i++) {
		//for as long as max columns is not reached
		for(j = 0; j < 3; j++) {
			//write the value of array[i][j] into file
			fwrite(array[i] + j, sizeof(char), 1, fp);
		}
	}

	//go back to the start of file
	fseek(binaryFile, 0, 0);

	//read
	fread(&buffer, sizeof(buffer), 4, binaryFile);

	//close file
	fclose(fp);
}

 //*******************************************************
 //1 mark
 //write a function "binaryIO" to take as a parameter two filenames
 //it opens the first file which is binary reads in sizeof(int) bytes at a time
 //it writes value and the value squared separated by a ',' one set of values per line i.e.
 //0,0
 //1,1
 //2,4
 //etc. to a the second file
 //
 //run the function with parameters e,file1, file2
 //so at the end of this there should be two new files
  //*******************************************************

void binaryIO(char *filename1, char *filename2) {
	//create int variables
	int row = 0;
	int column = 0;
	int buffer[100];
	int position = 1;
	int originalVal = 0;
	int squaredVal = 0;
	//int fpArray[row][column] = array[][];

	//open file1 for reading
	FILE *fpread = fopen(filename1, "r");

	//open file2 for writing
	FILE *fpwrite = fopen(filename2, "w");

	//close files
	fclose(fpread);
	fclose(fpwrite);
}

 //*******************************************************
 //2 marks
 //malloc and assign memory for	f as a pointer to pointers to integer style array of the same size as e
 //malloc and assign memory for g as a pointer to pointer to integer where you assign the pointers to a block of memory the size of e
	//write a function "arrayCopy" that that takes parameters of the same type as e, f, and g and a sizes array parameter
	//sizes is an array of the dimension sizes
	//use for loops to copy values of e to f and g inside the function
	//in main print out e, f and g
 //in main free the memory for f
 //in main free the memory for g
 //*******************************************************

void arrayCopy(int *e, int **f, int **g, int sizes[]) {
	//variables
	int i = 0;

	//create memory for f and g
	*f = malloc(4*sizeof(e));

	*g = malloc(4*sizeof(e));

	//copy values of e to f and g
	for(i = 0; i < 4; i++) {
		//get value of f and g equal value of e
		*f[i] = e[i];
		*g[i] = e[i];
		
		printf("arrayCopy: f: %d, g: %d\n", *f, *g);
	}
}

int main(){
	int *a;
	char *b="Hello ";
	char *c= "World";
	char *d;
	char *file1="e.bin";
	char *file2="e.txt";
	int size;
	int sizes[2];
	int e[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int **f;
 int **g;
	
	 //*******************************************************
	//1 mark
	//write a function "allocate10" that allocates space for 10 integer using the parameter list
	//in other words the function is of VOID type, takes a parameter and allocates and assigns memory to that parameter
	//call the function to allocate and assign memory to a
	//use a loop in the function to assign a[0] to a[9] to integers 0 to 9 
	//print the values out one per line in the main program
	//To be clear - the memory is allocated and assigning values happens in the function
	//in the main function
 //free the memory in a
 //*******************************************************

 allocate10(*a);

 free(*a);

 //*******************************************************
 //1 mark 
 //Write a function "joinStrings" takes as parameters 3 strings. It joins the first 2 together and puts the result in the third string
 //The function allocates memory for the third string using malloc
 //apply the function to strings b,c, and d. After the function is done d should have memory allocated to it and contain "Hello World"
 //the function should not assume the sizes of b or c - it needs to be general enough for any string
 //after calling the function using b,c,d as parameters print out d from the main function
 //free the memory in d
 //*******************************************************

 joinStrings(*b, *c, *d);

 free(*d);

 //*******************************************************
 //1 mark
 //write a function "arrayWrite" that takes as parameters an array of the same type as e, the size of the first dimension, and a string variables, binaryFilename
 //the function "arrayWrite" writes the values of the the array (starting from array[0][0] and ending at array[size-1][2]) to the binaryFilename
 //apply the function to array e and file1
 //*******************************************************

 arrayWrite(e, *file1);

 //******************************************************* 
 //1 mark
 //write a function "binaryIO" to take as a parameter two filenames
 //it opens the first file which is binary reads in sizeof(int) bytes at a time
 //it writes value and the value squared separated by a ',' one set of values per line i.e.
 //0,0
 //1,1
 //2,4 
 //etc. to a the second file
 //
 //run the function with parameters e,file1, file2
 //so at the end of this there should be two new files
  //*******************************************************

 	binaryIO(e, *file1, *file2);

 //******************************************************* 
 //2 marks
 //malloc and assign memory for	f as a pointer to pointers to integer style array of the same size as e
 //malloc and assign memory for g as a pointer to pointer to integer where you assign the pointers to a block of memory the size of e
	//write a function "arrayCopy" that that takes parameters of the same type as e, f, and g and a sizes array parameter
	//sizes is an array of the dimension sizes
	//use for loops to copy values of e to f and g inside the function
	//in main print out e, f and g
 //in main free the memory for f
 //in main free the memory for g
 //*******************************************************
 
 	arrayCopy(e, *f, *g, sizes[2]);

	free(*f);

	free(*g);
	
	return 1;
}
