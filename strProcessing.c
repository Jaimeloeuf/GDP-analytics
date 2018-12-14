#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "graphics.h"
#include "fFunctions.h"

extern int max_line_length;

char *cmdline_keywords[] = {
	"help",
	"manual",
	"version",
	"print",
	"data",
	"settings"
};

char *specialWord[] = {
	"exit", "quit",	"set", "gdp", "menu", "average", "highest", "lowest",
	"sector", "year", "data", "print", "settings", "manual",
};

int strProcessor(char *string, int processType)
{
	/* Input

		max_line_length must be set before using function
	*/
	char buffer[max_line_length]; // Tmp char array for sorting
	memset(buffer, '\0', max_line_length); 
	switch(processType)
	{
		case 0:
		    break;
		case 1:
			break;

		default:
			break;
	}
}

int cmdline_inputParser(int argc, char *argv[])
{
	int cmdline_keyword_tracker[sizeof(cmdline_keywords) / sizeof(char*)];
	for(int i = 0; i<sizeof(cmdline_keywords) / sizeof(char*); i++)
		cmdline_keyword_tracker[i] = 0;

	for(int i = 1; i<argc; i++)
		printf("%s \n", argv[i]);

	for(int i = 1; i<argc; i++)
		for(int j = 0; j< ; j++)
			if(strcmp(argv[i], cmdline_keywords[j]) == 0)
				cmdline_keyword_tracker[j] = 1;

	if(cmdline_keyword_tracker[0] || cmdline_keyword_tracker[1])
		// print help manual // check manual for what
	if(cmdline_keyword_tracker[2])
		//Print version of app
	if(cmdline_keyword_tracker[3]) // Print stuff out depending on whats specified
	if(cmdline_keyword_tracker[4]) // data smth
	if(cmdline_keyword_tracker[4]) // settings smth
}

int charReplacer(char *string, char replace, char replaceWith)
{
	// max_line_length must be set before using function
	char buffer[max_line_length]; // Tmp char array for sorting
	memset(buffer, '\0', max_line_length);
    strcpy(buffer, string);
    for(int j = 0; j<max_line_length; j++){
        // Loop through all characters to replace '\n' with '\0'
        if(buffer[j] == replace)
            buffer[j] = replaceWith;
        else if(buffer[j] == '\0')
            break;
    }
    strcpy(string, buffer);
}