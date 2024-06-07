#include<stdio.h>
#include "definitions.h"

/* Function to check if the numeric character read is an integer constant or a float constant */
Status check_for_numeric_literal( char temp_char, FILE *file_ptr )
{
	/* Declaring an array to store the number*/
	char number[MAX_NUM_SIZE];

	/* Variable to move through the index of the array */
	int index = 0;

	/* Flag variables for detecting integer, float and hexa-decimal values 
	   Initially the number is assumed as integer constant                */
	int int_flag = 1, float_flag = 0, hex_flag = 0;

	/* Storing the obtained character to the array */
	number[index++] = temp_char;

	/* Using a loop to scan the characters from the file */
	while( ( temp_char = fgetc( file_ptr ) ) != '\n' )
	{
		/* Checking if the character obtained is a decimal saperator and 
		   if the '.' was not previously encountered */
		if( temp_char == '.' && float_flag == 0 )
		{
			float_flag++; //Setting the float constant flag
			number[index++] = temp_char; //Storing the character to the array
			int_flag = 0; //Resetting integer flag
			//Write logic forwhat to do if more than one dot comes
		}

		/* Checking if the character received is x for a hexa decimal number and 
		   the first character in the number is 0 */
		if( ( temp_char == 'x' || temp_char == 'X' ) && number[0] == '0' && float_flag == 0 )
		{
			hex_flag++; //Setting the hex flag
			number[index++] = temp_char; //Storing the number to the array
			int_flag = 0; //Resetting integer flag
		}

		/* Checking if the character obtained was a hexadecimal character and if the flag has been
		   set for hexa deximal numbers */
		if( ( (temp_char >= 'A' && temp_char <= 'F' ) || ( temp_char >= 'a' && temp_char <= 'f' ) ) && hex_flag == 1 )
		{
			number[index++] = temp_char;
		}

		/* Checking if the numeric constant is suffixed with type f for float */
		if( ( temp_char == 'f' || temp_char == 'F' ) && hex_flag == 0 )
		{
			number[index++] = temp_char;
			int_flag = 0; //Resetting int flag incase it is set
			float_flag = 1; //Setting the float flag
		}

		/* Checking if the numeric constant is suffixed with type u for unsigned
		   or l for long */
		if( ( temp_char == 'l' || temp_char == 'L' ) || (temp_char == 'u' ||temp_char == 'U' ) )
		{
			number[index++] = temp_char;
		}

		/* Checking if the character obtained was a digit charcater */
		if( temp_char >= '0' && temp_char <= '9' )
		{
			number[index++] = temp_char; //Storing it to the array
		}
		
	}

	number[index] = '\0'; //Storing null character to the end of the char array

	/* When the loop breaks, check the flag and print the numeric constant */
	if( int_flag != 0 || hex_flag != 0 )
	{
		/* If integer flag or hexadecimal flag is set, printing it as integer constant */
		printf("Integer Constant            :     %s\n", number );
		return e_success;
	}
	else if( float_flag != 0 )
	{
		/* If float flag is set, printing the number as float constant */
		printf("Float Constant              :     %s\n", number );
		return e_success;
	}
}
