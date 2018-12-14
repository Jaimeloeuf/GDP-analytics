#include <stdlib.h> // Memory management Functions from Standard Library
#include <stdio.h> // Input and Output functions from Standard Library
#include <string.h> // String functions from Standard Library
#include <ctype.h> // Not sure if I need this

#include "graphics.h"
#include "fFunctions.h"
#include "functions.h"
#include "programSpecificFunc.h"
#include "strProcessing.h"
// #include <windows.h>

// #define productionCode
// #define TESTCODE_for_sizeof_and_pointers
// #define unused_word_processing_code

void Clear_screen(); // Clear screen function prototype

//Global Variables  // can I possibly add this to my header files
extern int sectorIndexTracker;
extern int numberOfSectors, earliestYr, latestYr;
extern int max_line_length;
//End of Global Variables


#ifdef productionCode
void strToInt(int number, int position, int numOfDigits)
{
    int power = numOfDigits - 1 - position;
    if(power == 0)
        input += 
    number = number * (10 * )
}
int main(int argc, char *argv[])
{
    int quit = 0;
    // cmdline_inputParser(argc, argv); // Parsing arguments passed via CLI
    
    /* Reading in Program Data from data files before usage */
    float *gdp = /*(float*)*/ dataReader(3.1); // Type casting is not needed in 'straight C'


    // size_t MAXINPUT = 100;
    #define MAXINPUT 100
    char charInput[MAXINPUT] = "";

    // input = 0;

    fgets(charInput, (MAXINPUT - 1), stdin); // Put this in string processing functions


    for (int i = 0; i < strlen(charInput); i++) // This loop is trying to loop through all the chars one by one to parse it
    {
        if(!isdigit(charInput[i]))
        {
            if(input != 0) // Meaning not the first word / character encountered
            {
                realloc some more space in the charInput char array anf put a . in between the words or use string array
            }
            start = i;
            while(isdigit[i])
            {
                i++;
            }
            end = i - 1;
            numOfDigits = end - start + 1;
            for(int i = 0; i<numOfDigits; i++)
            {
                strProcessing((charInput[start + i] - '0'), i, numOfDigits) //with i being the multiple, and starting with the highest multiple
            }
        }
        else if(isdigit[i])
        {
            if(charInput != 0) // Meaning not the first digit encountered
            {
                realloc some more space in the input int array
            }
            start = i;
            while(isdigit[i])
            {
                i++;
            }
            end = i - 1;
            numOfDigits = end - start + 1;
            for(int i = 0; i<numOfDigits; i++)
            {
                strToInt((charInput[start + i] atoi), i, numOfDigits) //with i being the multiple, and starting with the highest multiple
            }
        }
    }
    for (int i = 0; i < strlen(input); i++) // Something similiar to above loop
    {
        if(!isdigit(input[i]))
        {
            // printf ("Entered input is not a number\n");
            strProcessing();
        }
        else if(isdigit[i])
        {
            start = i;
            while(isdigit[i])
            {
                i++;
            }
            end = i - 1;
            numOfDigits = end - start + 1;
            for(int i = 0; i<numOfDigits; i++)
            {
                strToInt((input[start + i] atoi), i, numOfDigits) //with i being the multiple, and starting with the highest multiple
            }
        }
    }
    /* Have a char array, fgets values in with word limit failsafe
        sscanf to parse out any numbers then use my method in above function to read for any possibly words
    */

        case 1:
            do {
                menu(1); 
                fflush(stdin); // Clear input buffer before reading in new input
                scanf("%d", &input2);
                if(input2 < 1 || input2 > 5)
                    quit = errorHandler(1.0);
            }while(input2 < 1 || input2 > 5);
            if(quit == 2) // User choose to go back to MainMenu via errorHandler()
                break;
            sectioner(1);
            printf("\tAverage of selected sector over the four years is %.2f billion dollars.\n", AvrgOfSector(gdp, (input2-1), 2011, 2014));
            sectioner(2); getchar();
            break;
        case 2:
            do {
                menu(2); 
                fflush(stdin); // Clear input buffer before reading in new input
                scanf("%d", &input2);
                if(input2 < 1 || input2 > 4)
                    quit = errorHandler(1.0);
            }while(input2 < 1 || input2 > 4);
            if(quit == 2) // User choose to go back to MainMenu via errorHandler()
                break;
            input2--; // Since function lowesthighest takes in index form values
            sectioner(1);
            printf("\tThe lowest GDP data is %.2f and the corresponding sector is ", lowesthighest(gdp, (input2 + earliestYr), 0));
            sectorNamePrinter(sectorIndexTracker); printf(".\n");
            sectioner(2); getchar();
            break;
        case 3:
            do {
                menu(3); 
                fflush(stdin); // Clear input buffer before reading in new input
                scanf("%d", &input2);
                if(input2 < 1 || input2 > 4)
                    quit = errorHandler(1.0);
            }while(input2 < 1 || input2 > 4);
            if(quit == 2) // User choose to go back to MainMenu via errorHandler()
                break;
            sectioner(1);
            printf("\tThe GDP differences between yearly average and Manufacturing sector\n");
            printf("\tfor selected year is %.2f\n", AvrgOfYear(gdp, (input2 - 1 + earliestYr)) - *(gdp + input2 - 1));
            sectioner(2); getchar();
            break;
        case 4:
            menu(4);
            break;
        case 5:
            do {
                menu(5); 
                fflush(stdin); // Clear input buffer before reading in new input
                scanf("%d", &input2);
                if(input2 < 1 || input2 > 4)
                    quit = errorHandler(1.0);
            }while(input2 < 1 || input2 > 4);
            if(quit == 2) // User choose to go back to MainMenu via errorHandler()
                break;
            sectioner(1);
            float *arrangedData = (float*) XhighestGDP(gdp, (input2 + earliestYr - 1), numberOfSectors, 0);
            int *sectorNames = (int*) XhighestGDP(gdp, (input2 + earliestYr - 1), numberOfSectors, 1);
            printf("\tFor year %d\n", (input2 + earliestYr - 1));
            for(int i = 0; i<numberOfSectors; i++)
            {
                printf("\tThe value in position %d is %.2f\n", (i + 1), *(arrangedData + i));
                printf("\tThe corresponding sector is ");
                sectorNamePrinter(sectorNames[i]); newline(1);
            }

            free(arrangedData);
            arrangedData = NULL;
            if(arrangedData != NULL)
                errorHandler(0.3);

            free(sectorNames);
            sectorNames = NULL;
            if(sectorNames != NULL)
                errorHandler(0.3);
            break;
        case 6:
            menu(6);
            break;
        default:
            if(errorHandler(1.0))
                quit = 0;
            break;

    /* Freeing of all Dynamically allocated Heap Memory before exiting */
    free(gdp);
    gdp = NULL;
    if(gdp != NULL)
        errorHandler(0.3);
    clear_screen(0, 0);
}
#endif

float max, lowest;
int sectorIndexTracker;

#ifdef TESTCODE_for_sizeof_and_pointers
    /*printf("The sizeof int is %d, short is %d, unsigned short is %d\n", sizeof(int), sizeof(short), sizeof(unsigned short));
    printf("The sizeof float is %d, double is %d, long is %d,", sizeof(float), sizeof(double), sizeof(long));
    printf("The sizeof unsigned long is %d\nlong long is %d, unsigned int is %d\n", sizeof(unsigned long), sizeof(long long), sizeof(unsigned int));
    printf("The sizeof char is %d, unsigned char is %d\n", sizeof(char), sizeof(unsigned char));
    printf("Size of user defined ushort is %d\n", sizeof(ushort));
    clear_screen(1, 2);*/

#endif


#ifdef unused_word_processing_code

void Clear_screen()
{
    DWORD n;                         /* Number of characters written */
    DWORD size;                      /* number of visible characters */
    COORD coord = {0};               /* Top left screen position */
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    /* Get a handle to the console */
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

    GetConsoleScreenBufferInfo ( h, &csbi );

    /* Find the number of characters to overwrite */
    size = csbi.dwSize.X * csbi.dwSize.Y;

    /* Overwrite the screen buffer with whitespace */
    FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
    GetConsoleScreenBufferInfo ( h, &csbi );
    FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

    /* Reset the cursor to the top left position */
    SetConsoleCursorPosition ( h, coord );
}

// Clear screen method provided by MSDN

 /* Standard error macro for reporting API errors */ 
 // #define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s \ 
    // on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

 void cls( HANDLE hConsole )
 {
    COORD coordScreen = { 0, 0 };    /* here's where we'll home the
                                        cursor */ 
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
    DWORD dwConSize;                 /* number of character cells in
                                        the current buffer */ 

    /* get the number of character cells in the current buffer */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "GetConsoleScreenBufferInfo" );
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    /* fill the entire screen with blanks */ 

    bSuccess = FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputCharacter" );

    /* get the current text attribute */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "ConsoleScreenBufferInfo" );

    /* now set the buffer's attributes accordingly */ 

    bSuccess = FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputAttribute" );

    /* put the cursor at (0, 0) */ 

    bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
    PERR( bSuccess, "SetConsoleCursorPosition" );
    return;
 }

// clearing screen

/*void test()
{
    system("cls");
    printf("\e[1;1H\e[2J");
    //The \e[1;1H sets the screen to the 1st row and 1st column
    // the 2J overwrites all characters currently on the screen.
    write(0,"\e[1;1H\e[2J",12);
}*/

// End of clear screen functions

bool isNumber(char *input) {
    for (i = 0; input[i] != '\0'; i++)
        if (isalpha(input[i]))
            return false;
    return true;
}


int inputReader(int type)
{
	//Input variable will tell if input selection should be written to char or int
	// Type = 1 means write to int, Type = 2 means write to char (only when reading to exit or not)
	// return value not needed, unless returning an error
	printf("\n   INPUT:  ");
	fflush(stdin);	
	if(type==1)
		scanf("%d", &input);
	else if(type==2){
		// scanf();
	}
}

// isalpha() will test one character at a time. If the user input a number 
// like 23A4, then you want to test every letter. You can use this:
bool isNumber(char *input) {
    for (i = 0; input[i] != '\0'; i++)
        if (isalpha(input[i]))
            return false;
    return true;
}

scanf("%s", input);  // where input is a pointer to a char with memory allocated
if (isNumber(input)) {
    number = atoi(input);
    // rest of the code
}

// Checking using strlen()
{
    char input[MAXINPUT] = "";
    int length,i; 

    scanf ("%s", input);
    length = strlen (input);
    for (i=0;i<length; i++)
        if (!isdigit(input[i]))
        {
            printf ("Entered input is not a number\n");
            exit(1);
        }
    printf ("Given input is a number\n");
}


// A typical pattern is to read a string with fgets, then scan through the string
// and check that all the input was digits with isdigit. If it was all digits,
// then convert to an integer; otherwise, throw it away and get the input again.

//int string_is_name(char *s)
//{
//    int i;
//    int valid = 1;
//    for (i = 0; i < strlen(s); i++) {
//        if (!isalpha(s[i])) {
//            valid = 0;
//            break;
//        }
//    }
//    return valid;
//}

// checking for float
double value;
if (scanf("%lf", &value) == 1)
    printf("It's float: %f\n", value);
else
    printf("It's NOT float ... \n");



#endif