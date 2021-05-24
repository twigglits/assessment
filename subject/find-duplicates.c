#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHZIZE 101  //size of our hashtable(dictionary)
#define MAXCHAR 10000

typedef struct Dict
{ 
	//struct Dict * next;   //only have pointer that points to next line in the text file
	unsigned int key; //key digit that goes from 0 to 4294967294
	char value[MAXCHAR];	   //char value that contains alpha numeric characters
} Dict;

int main(int argc, char **argv)
{
	struct Dict *next;
	FILE *input_file;
	FILE *output_file; 

	char str[MAXCHAR];	
	int count_lines = 0;

	char c;

	char *filename_in = argv[1];
	char *filename_out = argv[2];

	if (argc != 3)
	{
		fprintf(stderr, "usage: %s in1.txt out.txt\n", argv[0]);
		(exit(0));
	}
	else if (argv[1] == NULL)
	{
		fprintf(stderr, "usage: There is no input file!\n");
		exit(0);
	}
	else if (argv[2] == NULL)
	{
		fprintf(stderr, "usage: There is no output file!\n");
		exit(0);
	}

	input_file = fopen(filename_in, "r");
	output_file = fopen(filename_out, "w"); //this creates a file with our duplicates in it

	char delimit[]=":\n";  //whitespace delimiters!!!
	unsigned int toknum = 0;  //values can only be positive

	char pairs[HASHZIZE];  //size of 101

	//method that reads text and displays it.
	while (fgets(str, MAXCHAR, input_file) != NULL)   // see if we can read and do split operation on : and put them into a struct.
	{
		char * token = strtok(str, delimit);
		while (token != NULL)
		{
			printf("%d: %s\n", ++toknum, token);  //toknum gives us our index number
			token = strtok(NULL, delimit);

			pairs[toknum] = token; //want to increment my array

			//or put it into an array
			//here insert it into our Dict Data structure
		}
		count_lines += 1;  //counts lines
	}
	printf("The file has %d lines\n", count_lines);  //imported string library
	
	// use arrays to put the lines of text into!
	//ReadKeyVal(input_file, count_lines); //method to read keyval pair
							   //find duplicates, for each duplicate, increment amount
	fclose(input_file);
	
	return 0;
}


