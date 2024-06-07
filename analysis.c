/* File contains the definitions of functions to do the Lexical analysis operation */

#include<stdio.h>
#include<string.h>
#include "definitions.h"

/* Function to do the lexical analysis of the file */
Status do_lexical_analysis( File_details *file_details )
{
	/* Char array to store word to compare for keyword or identifier */
	char word[MAX_WORD_SIZE];

	/* Char variables to store the character read from the file */
	char character, next_char;

	/* Variable to move through the index of the array */
	int iteration = 0;

	/* Running a loop to read each word */
	while( fscanf( file_details->file_pointer, "%c", &character ) != EOF )
	{
restart:
		// Check for preprocessor directive
		if( character == '#' )
		{
			if( handle_pre_processor( file_details->file_pointer ) == e_success )
			{
				continue;
			}
		}

		/* Check if the character is part of line comment */
		if( character == '/' )
		{
			//Read the next character and check if it is a single line or multi-line comment
			next_char = fgetc( file_details->file_pointer );

			if( next_char == '/' )
			{
				//Skip over the single line comment
				if( skip_single_line_comment( file_details->file_pointer ) == e_success )
				{
					continue;
				}
			}
			else if( next_char == '*' )
			{
				//Skip over the multi line comment
				if( skip_multi_line_comment( file_details->file_pointer ) == e_success )
				{
					continue;
				}
			}
			else
			{
				//If the character was not part of a line comment continue to check for other cases

				/* Reset back the file pointer to read and check the next character */
				fseek( file_details->file_pointer, -1, SEEK_SET );
			}
		}

		//Check for beginning of a charcater literal
		if( character == '\'' )
		{
			//Calling function to read character literal and print it
			if( check_for_character_literal( character, file_details->file_pointer ) == e_success )
			{
				continue;
			}
		}

		//Check for beginning of a string literal
		if( character == '"' )
		{
			//Calling the function to read string literal and print it
			if( check_for_string_literal( character, file_details->file_pointer ) == e_success )
			{
				continue;
			}
		}

		// Check if the character read is an alphabet or underscore
		if( ( character >= 65 && character <= 90 ) || ( character >= 97 && character <= 122 ) || character == '_' ) 
		{
			//Store the character to word array
			word[iteration++] = character;
		}

		if( !(( character >= 65 && character <= 90 ) || ( character >= 97 && character <= 122 ) || character == '_' ) && iteration != 0 ) 
		{
			/* Terminate the char array with null character and reset index variable to zero */
			word[iteration] = '\0';
			iteration = 0;

			//Check what the word is
			if( check_for_keyword_or_identifier( word ) == e_success )
			{
				//Check if the delimiting character was a space or new line character
				if( character == ' ' || character == '\n' )
				{
					// If yes, then skip and read the next character
					continue;
				}
				else
				{
					//Else going back to the beginning and checking for the character read
					goto restart;
				}
			}
		}
		else if( character == ' ' )
		{
			/* If there is nothing stored in the array word and the 
			   character read is a space, skip it */
			continue;
		}

		/* Check if the character is part of a number */
		if( character >= 48 && character <= 57 )
		{
			//Search and print if it is an integer or a float constant
			if( check_for_numeric_literal( character, file_details->file_pointer ) == e_success )
			{
				continue;
			}
		}

		/* Check if the charcater read is any brace */
		if( check_for_brace( character ) == e_success )
		{
			continue;
		}

		/* Check if the character read is an operator */
		if( check_for_operator( character ) == e_success )
		{
			continue;
		}
	}
	/* After all tokens have been printed and file offset reaches end of file, return success */
	return e_success;
}
