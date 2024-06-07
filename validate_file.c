/* File containes the function to validate the file passed by user to command line */

#include<stdio.h>
#include<string.h>
#include "definitions.h"

/* Function will check if the file passed by the user is a .c file and then 
   opens it and checks if it is empty or not */
Status check_and_validate_file( const char *filename, File_details *file_details )
{
	/* Checking if the file is a .c file or not */
	if( strstr( filename, ".c") == NULL )
	{
		printf("ERROR: File passed should be a .c file\n");
		return e_fail;
	}

	/* Storing the file name to the structure variable */
	strcpy( file_details->file_name,filename );

	/* Opening the file in read mode */
	file_details->file_pointer = fopen( file_details->file_name, "r" );
	
	/* Checking if the file has been opened correctly */
	if( file_details->file_pointer == NULL )
	{
		printf("ERROR: Unable to open %s\n", file_details->file_name );
		return e_fail;
	}

	/* Checking if the file is empty */
	fseek( file_details->file_pointer, 0, SEEK_END );//Setting the file pointer to the end of the file

	if( ftell( file_details->file_pointer ) == 0 )
	{
		printf("ERROR: File %s is empty\n", file_details->file_name );
		return e_fail;
	}

	/* Reset the file pointer to the beginning of the file */
	rewind( file_details->file_pointer ); 

	/* After all valdations have been completed, returing back to main */
	return e_success;
}
