#include<stdio.h>
#include<string.h>
#include "definitions.h"

/* Function to handle pre-processor directives */
Status handle_pre_processor( FILE *file_ptr )
{
	/* Declaring a character array to store the pre-processor directive */
	char directive[MAX_WORD_SIZE];

	/* Declaring a temporary character to read and store the character */
	char temp_char;

	/* Declaring a variable to iterate the index of the array */
	int index = 0;

	/* Storing '#' as the first character */
	directive[index++] = '#';

	/* Running a loop till new line character to read the pre-processor */
	//while( fscanf( file_ptr, "%c", &temp_char ) != '\n' )
	while( ( temp_char = fgetc( file_ptr ) ) != '\n' )
	{
		//printf("Scanning\n");
		directive[index++] = temp_char;
	}

	/* After the whole pre-processor has been read, printing it */
	printf("Pre-Processor Directive     :     %s\n", directive );

	return e_success;
}
