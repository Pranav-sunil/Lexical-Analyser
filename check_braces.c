#include<stdio.h>
#include "definitions.h"

/* Function to check if the character is a brace */
Status check_for_brace( char character )
{
	/* Variable to iterate through the array */
	int iter;

	/* Running a loop to check if the character is a brace */
	for( iter = 0 ; iter < BRACES_COUNT ; iter++ )
	{
		if( character == open_brackets[iter] )
		{
			printf("Open Braces                 :     %c\n", character );
			return e_success;
		}
		else if( character == close_brackets[iter] )
		{
			printf("Close Braces                :     %c\n", character );
			return e_success;
		}
	}

	/* If the character was not a brace, return failure */
	return e_fail;
}
