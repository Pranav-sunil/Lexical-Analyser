/* File contains the enum definitions, function prototypes required for Lexical Analysis */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define FILE_NAME_SIZE							40
#define MAX_WORD_SIZE							50
#define MAX_NUM_SIZE							10
#define STR_LITERAL_LEN							80
#define CHAR_LITERAL_LEN						 5

#define RESERVED_KEYWORD_DATA_COUNT				19
#define RESERVED_KEYWORD_NON_DATA_COUNT			13
#define OPERATOR_COUNT							17
#define BRACES_COUNT							 3

static char *reserved_keywords_data[RESERVED_KEYWORD_DATA_COUNT] = { "const", "volatile", "extern", "auto", "register", "static", "signed", "unsigned", "short", "long", "double", "char", "int", "float", "struct", "union", "enum", "void", "typedef"};

static char *reserved_keywords_non_data[RESERVED_KEYWORD_NON_DATA_COUNT] = { "goto", "return", "continue", "break", "if", "else", "for", "while", "do", "switch", "case", "default", "sizeof" };

static char operators[OPERATOR_COUNT] = { '/', '+', '-', '*', '%', '=', '<', '>', ',', '~', '!', '?', '|', '&', '^', ':', ';'};

static char open_brackets[BRACES_COUNT] = {'(', '{', '[', };

static char close_brackets[BRACES_COUNT] = {')', '}', ']'};

/* Enum to return status of function */
typedef enum
{
	e_fail,
	e_success,
}Status;

/* Structure to store the details of file */
typedef struct
{
	char file_name[FILE_NAME_SIZE];
	FILE *file_pointer;
}File_details;

/* Function to validate the file passed through command line argument */
Status check_and_validate_file( const char *filename, File_details *file_details );

/* Function to do the analysis process */
Status do_lexical_analysis( File_details *file_details );

/* Function to handle pre-processor directives */
Status handle_pre_processor( FILE *file_ptr );

/* Function to check if the character is a brace */
Status check_for_brace( char character );

/* Function to check if the character is an operator */
Status check_for_operator( char character );

/* Function to check for key words */
Status check_for_keyword_or_identifier( char *word );

/* Function to skip over the single line comments */
Status skip_single_line_comment( FILE *file_ptr );

/* Function to skip over the multi line comments */
Status skip_multi_line_comment( FILE *file_ptr );

/* Function to check and print numeric literal */
Status check_for_numeric_literal( char temp_char, FILE *file_ptr );

/* Function to check and print character literal */
Status check_for_character_literal( char temp_char, FILE *file_ptr );

/* Function to check and print stirng literal */
Status check_for_string_literal( char temp_char, FILE *file_ptr );
#endif
