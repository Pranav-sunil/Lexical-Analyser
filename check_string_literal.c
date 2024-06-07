#include<stdio.h>
#include "definitions.h"

/* Function to read and print string literal from the file stream */
Status check_for_string_literal( char temp_char, FILE *file_ptr )
{
	/* Char array to store the characters of the string literal */
	char string[STR_LITERAL_LEN];

	/* Variable to move through the index of the array */
	int index = 0;

	/* Storing '"' obtained from argument passed during function call */
	string[index++] = temp_char;

	/* Running a loop to read the string literal from the file */
	while( ( temp_char = fgetc( file_ptr ) ) != '"' )
	{
		string[index++] = temp_char; //Storing the character read to the array
	}

	string[index++] = temp_char; //Storing the end '"' to the array
	string[index] = '\0'; //Terminating the array with null character

	/* Printing the string literal */
	printf("String Literal              :     %s\n", string );

	return 0;
}
