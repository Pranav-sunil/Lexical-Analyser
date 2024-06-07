#include<stdio.h>
#include "definitions.h"

/* Function to skip over single line comments in the file */
Status skip_single_line_comment( FILE *file_ptr )
{
	//Using a loop until reading newline character
	while( fgetc( file_ptr ) != '\n' );

	return e_success;
}

/* Function to skip over multi line comments */
Status skip_multi_line_comment( FILE *file_ptr )
{
	/* Character variable to store the previous character read */
	char prev_char;

	/* Character variable to store the previous character read */
   	char curr_char;

	/* Running a loop to read the characters from the file */
	while( ( curr_char = fgetc( file_ptr ) ) != EOF )
	{
		/* Check if the combination of current and previous character 
		   is for an end of multi line comment */
		if( prev_char == '*' && curr_char == '/' )
		{
			return e_success;
		}
		prev_char = curr_char;
	}

	/* If end was not detected, return failure */
	return e_fail;
}
