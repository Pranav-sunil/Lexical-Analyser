#include<stdio.h>
#include<string.h>
#include "definitions.h"

/* Function to check if the word is a keyword or an identifier */
Status check_for_keyword_or_identifier( char *word )
{
	//Declaring a variable to iterate through the array of keywords
	int iteration;

	/* Running a loop to check for reserved keywords related to data */
	for( iteration = 0 ; iteration < RESERVED_KEYWORD_DATA_COUNT ; iteration++ )
	{
		if( strcmp( word, reserved_keywords_data[iteration]) == 0 )
		{
			printf("Reserved Keyword( Data )    :     %s\n", word );
			return e_success;
		}
	}

	/* Running a loop to check for reserved keywords related to data */
	for( iteration = 0 ; iteration < RESERVED_KEYWORD_NON_DATA_COUNT ; iteration++ )
	{
		if( strcmp( word, reserved_keywords_non_data[iteration]) == 0 )
		{
			printf("Reserved Keyword( Non-data) :     %s\n", word );
			return e_success;
		}
	}

	/* If the word was not a keyword, then it is an identifier */
	printf("Identifier                  :     %s\n", word);

	return e_success;
}
