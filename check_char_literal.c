#include<stdio.h>
#include "definitions.h"

/* Function to read character literal from the file and print it */
Status check_for_character_literal( char temp_char, FILE *file_ptr )
{
	/* Declaring a char array to store the character literal */
	char char_lit[CHAR_LITERAL_LEN];

	/* Variable to move through the array */
	int index = 0;

	/* Storing the first character read and sent through function call */
	char_lit[index++] = temp_char;

	/* Running a loop to read the character literal from the file */
	while( ( temp_char = fgetc( file_ptr ) ) != '\'' )
	{
		char_lit[index++] = temp_char; //Storing the character read to the array
	}

	char_lit[index++] = temp_char; //Storing the last single quote read to the array

	char_lit[index] = '\0'; //Terminating the char array with null character

	/* Printing the literal */
	printf("Character literal           :     %s\n", char_lit );

	return e_success;
}
