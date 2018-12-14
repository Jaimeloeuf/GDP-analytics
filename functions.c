#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include "graphics.h"
#include "programSpecificFunc.h"
#include "fFunctions.h"

int inputParser();
int inputReader(int type);

// Global Variables and External Variables
int i; /*Variable i will be reserved as loop control variable, to optimize
for efficiency since no new allocation of memory space for each use*/

void menu(int menuSelector)
{
	/* The Menu Function takes in a parameter defining the 
	specific menu to be displayed.
	menuSelector == 0, Display MainMenu
	menuSelector == 1, Display SubMenu1 of Option 1 in MainMenu
	menuSelector == 2, Display SubMenu2 of Option 2 in MainMenu
	menuSelector == 3, Display SubMenu3 of Option 3 in MainMenu
	menuSelector == 4, Display SubMenu4 of Option 4 in MainMenu
	menuSelector == 5, Display SubMenu5 of Option 5 in MainMenu
	menuSelector == 6, Display SubMenu6 of Option 6 in MainMenu */
	sectioner(0);
	switch(menuSelector)
	{
		case 0: //Main Menu
			dataReader(1.0);
	  		break;
		case 1: // Option (1) sub menu from MainMenu
			dataReader(1.1);
	    	break;
	    case 2: // Option (2) sub menu from MainMenu
			dataReader(1.2);
		    break;
		case 3: // Option (3) sub menu from MainMenu
			dataReader(1.3);
			break;
		case 4: // Option (4) sub menu from MainMenu
			dataReader(1.4);
			break;
		case 5: // Option (5) sub menu from MainMenu
			dataReader(1.5);
			break;
		case 6: // Option (6) sub menu from MainMenu
			dataReader(1.6);
			break;
	    default:
	    	errorHandler(0.1);
	    	break;
	} // End of switch(menuSelector)
	newline(2);
	printf("\t Enter corresponding number on the menu as input\n");
	printf("\t or '0' or 'Q ' or 'exit' to exit this program.\n");
	sectioner(2);
	sectioner(3); pInput();
	// inputParser();
}

void myPrinter(char * toPrint, int print_location)
{
	/* 'char * toPrint' is the string to be printed
		'print_location' is the place to be printed to
	
		print_location = 0, print to stdout
		print_location = 1, print to stderr
		print_location = 2, print to a log file
	*/
	switch(print_location)
	{
		case 1:
			fprintf(stderr, "%s", toPrint);
			break;

		case 2:
			FILE *file;
			file = fopen(error_log_file, "a");

		
	}
}

int errorHandler(float input)
{
	/*	Input parameter format is: errorType.Index

		errorType:
		(0) for internal errors, examples like unexpected internal excecution,
		or passing of wrong values between functions.
		(1) for input errors, where wrong input type / format is being read.
		(2) for file errors, anything to do with file I/O

		errorIndex = errorType.Index * 10
		errorIndex:
		(0.0) unexpected internal excecution
		(0.1) passing of wrong values between functions
		(0.2) unable to allocate memory from heap for whatever reasons
		(0.3) unable to free memory from heap or dangling pointer detected
		(0.4) 
		
		(1.0) Wrong input / Invalid input (General Error) Let user try again
		(1.1) Wrong input type
		(1.2) Wrong input format

		(2.0) when FILE pointer is of NULL value, missing file, file unable to be read
		(2.1) File stored in wrong format / edited wrongly
	*/
	int errorType = (int) input; // type casting values from float to int to use with switch case
	float tmp = input * 10; // Multiplying by 10 to get the fileIndex for switching
	int errorIndex = (int) tmp;

	int errorHandlerInput, repeatErrorCount = 0;
	switch(errorType)
	{
		case 0: // Internal errors
			do
			{
				if((!(repeatErrorCount % 2) && repeatErrorCount) || !repeatErrorCount)
				{
					if(!(repeatErrorCount % 2) && repeatErrorCount)
						clear_screen(1, 3);
					else
						clear_screen(0, 3);
					sectioner(4);
					switch(errorIndex)
					{
						case 0:
							printf("\tError! Unexpected internal excecution.\n\tPlease inform developer if error persists.\n");
							sectioner(2); getchar(); sectioner(3);
							printf("\tEnter:\n\t(1) To try excecution again\n");
							break;
						case 1:
							printf("\tError! Internal error encountered -> wrong values passed in program.\n");
							printf("\tPlease notice developer on issue.\n"); sectioner(2); getchar(); sectioner(3);
							printf("\tEnter:\n\t(1) To try excecution again\n");
							break;
						case 2:
							printf("\tError! Unable to allocate memory to perform operations!\n");
							printf("\tError might be due to insufficient RAM.\n");
							sectioner(2); getchar(); sectioner(3);
							printf("\tEnter:\n\t(1) Try allocation again. (Try closing apps to free up ram before trying again)\n");
							break;
						case 3:
							printf("\tError! Unable to free memory from heap(RAM).\n\tPlease notice developer on issue.\n");
							sectioner(2); getchar(); sectioner(3);
							printf("\tEnter:\n\t(1) Try excecution again.\n");
							break;
					} // End of switch(errorIndex)
					sectioner(2);
				}
				sectioner(3);
				printf("\t(2) To go back to MainMenu\n");
				printf("\t(0) To exit program.\n");
				pInput(); fflush(stdin);
				scanf("%d", &errorHandlerInput);
				if(errorHandlerInput < 0 || errorHandlerInput > 2){
					repeatErrorCount++;
					printf("\tOption entered is still invalid please try again.\n");
				}
				else
					break;
			}while(repeatErrorCount);
			return errorHandlerInput;
			break;
		case 1: // input errors
			do
			{
				if((!(repeatErrorCount % 2) && repeatErrorCount) || !repeatErrorCount)
				{
					if(!(repeatErrorCount % 2) && repeatErrorCount)
						clear_screen(1, 3);
					else
						clear_screen(0, 3);
					sectioner(4);
					switch(errorIndex)
					{
						case 10:
							printf("\tError! Invalid input detected.\n");
							break;
						case 11:
							printf("\tError! Invalid input type detected.\n");
							break;
						case 12:
							printf("\tError! Invalid input format detected.\n");
							break;
					} // End of switch(errorIndex)
					sectioner(2);
				}
				sectioner(3);
				printf("\tEnter:\n\t(1) To try again\n");
				printf("\t(2) To go back to MainMenu\n");
				printf("\t(0) To exit program.\n");
				pInput(); fflush(stdin);
				scanf("%d", &errorHandlerInput);
				if(errorHandlerInput < 0 || errorHandlerInput > 2){
					repeatErrorCount++;
					printf("\tOption entered is still invalid please try again.\n");
				}
				else
					break;
			}while(repeatErrorCount);
			return errorHandlerInput;
			break;
		case 2: // All errors regarding file I/O
			do
			{
				if((!(repeatErrorCount % 2) && repeatErrorCount) || !repeatErrorCount)
				{
					if(!(repeatErrorCount % 2) && repeatErrorCount)
						clear_screen(1, 3);
					else
						clear_screen(0, 3);
					sectioner(4);
					switch(errorIndex)
					{
						case 20:
							printf("\tError! File specified does not exist in the specified location!\n");
							printf("\tCheck if file has been deleted before accessing file or running app again.\n");
							break;
						case 21:
							printf("\tError! File specified is written in the wrong format, or has been edited wrongly!\n");
							printf("\tCheck file format before accessing file or running app again.\n");
							break;
					} // End of switch(errorIndex)
					sectioner(2);
				}
				sectioner(3);
				printf("\tEnter:\n\t(1) Try excecution again. (Check file first)\n");
				printf("\t(0) Exit program.\n");
				pInput(); fflush(stdin);
				scanf("%d", &errorHandlerInput);
				if(errorHandlerInput < 0 || errorHandlerInput > 1){
					repeatErrorCount++;
					printf("\tOption entered is still invalid please try again.\n");
				}
				else
					break;
			}while(repeatErrorCount);
			return errorHandlerInput;
		default:
			break;
	} // End of switch(errorType)
}