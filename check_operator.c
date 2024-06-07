#include<stdio.h>
#include "definitions.h"

/* Function to check if the character recieved is an operator */
Status check_for_operator( char character )
{
	/* Declaring a variable to iterate through the array of operators */
	int iter;

	/* Running a loop to check if the character is an operator */
	for( iter = 0 ; iter < OPERATOR_COUNT ; iter++ )
	{
		if( character == operators[iter] )
		{
			printf("Operator                    :     %c\n", character );
			return e_success;
		}
	}

	/* If the character was not an operator return failure */
	return e_fail;
}
