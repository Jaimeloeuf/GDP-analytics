#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "fFunctions.h"
#include "graphics.h"
#include "programSpecificFunc.h"
#include "functions.h"

extern char *menus[];
extern char settings[];
extern char dataFile[];
extern char names[];
extern char manual[];

extern int numberOfSectors, earliestYr, latestYr;
int max_line_length;

// Function Prototype Declarations
int inputParser();
int inputReader(int type);
// End of Func Declare

void * dataReader(float input)
{
	/*  
		Input parameter format = typeSelector.fileIndex

		typeSelector:
		(1) Menu
		(2) Help n Usage Manual  (Including Readme files)
		(3) Settings n Data files

		The file index will be the particular file of selected type

		Return type is a generic pointer to be casted by the function caller
	*/

	// Code below type casts values from float to int since switch case don't switch floats
	int typeSelector = (int) input;
	float tmp = input * 10; // Multiplying by 10 to get the 'fileIndex' for switching
	int fileIndex = (int) tmp; // Casting 'tmp' to obtain 'fileIndex'

	FILE *file; // Declaring a file pointer variable before assigning a pointer based on the case value
	int numOflines, error = 0;
	// Implement a file format checker before reading in the data
	do
	{
		if(error == 1) // If error opening any file and user chooses to go to Main Menu in error handler
			typeSelector = 1, fileIndex = 10;
		switch(typeSelector)
		{
			case 1:
				switch(fileIndex)
				{
					case 10: // Main Menu
						file = fopen(menus[0], "r"); break;
					case 11: // Option (1) sub menu from MainMenu
						file = fopen(menus[1], "r"); break;
					case 12: // Option (2) sub menu from MainMenu
						file = fopen(menus[2], "r"); break;
					case 13: // Option (3) sub menu from MainMenu
						file = fopen(menus[3], "r"); break;
					case 14: // Option (4) sub menu from MainMenu
						file = fopen(menus[4], "r"); break;
					case 15: // Option (5) sub menu from MainMenu
						file = fopen(menus[5], "r"); break;
					case 16: // Option (6) sub menu from MainMenu
						file = fopen(menus[6], "r"); break;
					default:
						error = errorHandler(0.1); break;
				} // End of switch(fileindex)
				break; // End of case 1
			case 2:
				switch(fileIndex)
				{
					file = fopen()
				} // End of switch(fileindex)
				break; // End of case 2
			case 3:
				switch(fileIndex)
				{
					case 30:
						file = fopen(settings, "r"); break;
					case 31:
						file = fopen(dataFile, "r"); break;
					case 32:
						file = fopen(names, "r"); break;
					default:
						error = errorHandler(0.1); break;
				} // End of switch(fileindex)
				break; // End of case 3
			default:
				error = errorHandler(0.1); break;
		} // End of switch(typeSelector)
		error = fileErrorChecker(file);
	}while(error);

	if(typeSelector == 1 || typeSelector == 2)
		fscanf(file, "%d%d", &numOflines, &max_line_length); // only for text to be printed
	char printingBuffer[max_line_length];
	memset(printingBuffer, '\0', max_line_length);
	if(typeSelector == 1 || typeSelector == 2) // Checking if file type needs printing
		for(int i = 0; i < numOflines; i++) // Printing loop
		{
			// fgets till line_length limit or till End of line read
			fgets(printingBuffer, max_line_length, (FILE*)file);
			// Each line is scanned into the char array buffer before being displayed
		   	printf("%s", printingBuffer);
		}
	else if(fileIndex == 30) // Settings file
	{
		// read in settings
		// 1. GDP in millions, billions, or trillions
	}
	else if(fileIndex == 31) // Reading from Data file to save into variables for program usage
	{
		fscanf(file, "%d", &numberOfSectors);
		fscanf(file, "%d", &earliestYr);
		fscanf(file, "%d", &latestYr);
		// Implement something to prevent datasets too huge that would hog all the memory and process threads
		float *gdp = /*(float*)*/ calloc((numberOfSectors * (latestYr - earliestYr + 1)), sizeof(float));
		// Type caster for above calloc is not needed in 'straight C'
    	if(gdp == NULL)
	        errorHandler(0.2);
        for(int i = 0; i<(numberOfSectors * (latestYr - earliestYr + 1)); i++)
    		fscanf(file, "%f", &gdp[i]); // Setting the gdp array with data from file
    	return gdp; // Returning pointer to gdp array
	}
	else if(fileIndex == 32)
	{
		fscanf(file, "%d", &max_line_length);
		// The number of sector names corresponds to numberOfSectors
		char** sectornames = calloc(numberOfSectors, sizeof(char*));
		if(sectornames == NULL)
			errorHandler(0.2);
	    for(int i = 0; i<numberOfSectors; i++)
	    {
			// allocating 'max_line_length' number of characters to each pointer in the array
			sectornames[i] = calloc(max_line_length, sizeof(char));
			if(sectornames[i] == NULL)
	        	errorHandler(0.2);
	    } // End of character sorting loop
 	   	for(int i = 0; i<numberOfSectors; i++) // assigning strings to each pointer in the array
			fgets(sectornames[i], max_line_length, (FILE*)file);
 	  	return sectornames;
 	}
	fclose(file);
}

int fileErrorChecker(FILE *fileptr)
{
	// Takes in a file pointer and checks if it is null
	if(fileptr == NULL)
		if(errorHandler(2.0)) // File missing error
			return 1;
	return 0; // Return 0 for no errors
}


// void dataWriter(int dataType, int dataIndex)
// {
// 	// dataType == 1, means settings
// 	// dataType == 2, means program data

// 	FILE *file;
// 	char buff[1000]; // All editing should be done into the buffer before saving data
// 	switch(dataType)
// 	{
// 		case 1: // Settings editing requested
// 			file = fopen(settings, "w");
// 			errorHandler(1);
// 			switch(dataIndex)
// 			{
// 				case 0: // reverse program back to first use state
// 					strcpy(buff, "settings: 1");
// 					/*Setting first use variable setting to true 
// 				 	before writing data back to file*/
// 				 	fprintf(file, "%s", buff);
// 				 	printf("Program state changed to first use state.\n");
// 				 	fclose(file);
// 				 	exit(0);
// 					break;
// 				case 1: // First time use, request user for all settings
// 					strcpy(buff, "settings: 0");	 	
// 				 	/*Setting first use variable setting to false 
// 				 	before writing data back to file*/
// 					fprintf(file, "%s", buff);
// 				break;

// 			} // switch(dataIndex)
// 			fclose(file);
// 			break;
// 		case 2:
// 			switch(dataIndex)
// 			{
// 				case 1:
// 				break;
// 			} // switch(dataIndex)
// 			break;

// 		default:
// 		break;
// 	} // switch(dataType)
// }