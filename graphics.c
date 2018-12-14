#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "functions.h"

// Global Variables
int i;

void clear_screen(int pauseBool, int numOfnewlines)
{
	fflush(stdin);
    if(pauseBool)
        getchar();
    system("cls");
    newline(numOfnewlines);
}
void sP(int a){
	//sP short for spacePrint
	//Input defines number of spaces printed
	for(i=0;i<a;i++)
		printf(" ");
}
void pInput(){
	printf("\n\tInput: ");
}
void sectioner(int sectionType)
{
	/* Input defines type of section:
		0 for Menu Header section
		1 for generic Section Header
		2 for generic Section Footnote
		3 for Input Section Header
		4 for ERROR Section Header*/
	switch(sectionType)
	{
		case 0:
			clear_screen(0, 3);
			linePrint(0,5);
			printf(" MENU ");
			linePrint(0,4);
			break;
		case 1:
			clear_screen(0, 3);
			linePrint(0,0);
			printf(" Section START ");
			linePrint(0,0);
			break;
		case 2:
			newline(1);
			linePrint(0,1);
			printf(" Section END ");
			linePrint(0,1);
			break;
		case 3:
			newline(1);
			linePrint(0,0);
			printf(" INPUT SECTION ");
			linePrint(0,0);
			break;
		case 4:
			clear_screen(0, 3);
			linePrint(0,4);
			printf(" ERROR ");
			linePrint(0,4);
			break;
		default:
			errorHandler(0.1);
			break;
	}
	newline(2);
}
void linePrint(int a, int b)
{
	//Input a defines number of dash
	//Input b defines additional dash to be added to input a
	//B should only be used when input a == 0
	if(a==0)
		a=37+b;
	for(i = 0;i<a;i++)
		printf("=");
}
void newline(int a){
	for(i = 0;i<a;i++)
		printf("\n");
}
void exiter(){
	printf("Detected Exit Option from input.\nProgram Exitting now.");
	clear_screen(0, 0);
	exit(0); // Exit program
} // DONT FUCKING USE EXITER UNLESS ABSOULUTELY NECCESSARY AS THERE WILL BE MEMORY LEAKAGE