/* ###################################### LEXICAL ANALYSER ######################################
Name : Pranav S
Regn. No. : 23029_009
*/

/* Main file : This file contains the main function and calls other functions to do the 
   			   Lexical analysis
*/

#include<stdio.h>
#include "definitions.h"
int main( int argc, char *argv[])
{
	File_details file_details;

	/* Validate if sufficient number of command line arguments was passed */
	if( argc == 1 )
	{
		printf("ERROR: Please pass the file through Command Line\n");
		printf("USAGE: ./a.out <filename.c>\n");
		return 0;
	}

	/* Start the analysis process */
	printf("########################### Lexical Analyser ###########################\n\n");
	if( check_and_validate_file( argv[1], &file_details ) == e_success )
	{
	   printf("Open       :   %s   :    Success\n", file_details.file_name);	   
	   printf("Parsing    :   %s   :    Success\n\n", file_details.file_name);
		
		if( do_lexical_analysis( &file_details ) == e_success )
		{
	   		printf("\nParsing    :   %s   :    Done\n", file_details.file_name);
		}
		else
		{
	   		printf("\nParsing    :   %s   :    Failure\n", file_details.file_name);
		}
   	}

	/* At the end, close the file */
	if( fclose( file_details.file_pointer ) != 0 )
	{
		printf("ERROR: Unable to close %s\n", file_details.file_name );
	}

	return 0;
}
