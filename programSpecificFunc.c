#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "programSpecificFunc.h"
#include "functions.h"
#include "graphics.h"
#include "fFunctions.h"
#include "strProcessing.h"

// Global Variables n External Variables
extern int numberOfSectors, earliestYr, latestYr;
extern int max_line_length; // Global Variable from fFunctions.c
float total, max, lowest;
int sectorIndexTracker;
float gdp[5][4]; // Delete please
// End Globlal Variables n External Variables

float AvrgOfSector(float * gdp, int sectorIndex, int startYr, int endYr)
{
    // Computes the average GDP of selected sector over a span of specified timeframe
    total = 0.0;
    for(int i = 0; i<(endYr - startYr + 1); i++)
        total += *(gdp + ((sectorIndex * (latestYr - earliestYr + 1)) + (startYr - earliestYr + i)));
    return total / (endYr - startYr + 1);
}

float AvrgOfYear(float * gdp, int year)
{
    // Computes the average GDP of all sectors of the selected year
    total = 0.0;
    year -= earliestYr;
    for(int i = 0; i<numberOfSectors; i++)
        total += *(gdp + (i * (latestYr - earliestYr + 1)) + year);
    return total / numberOfSectors;
}

float growthRate(int growthType)
{
	/* Input growth type defines
	(0) the total GDP growth
	(1) the rate of growth of a sector
	*/
	// if(endYr - startYr == 0)
		// Error Handler (internal error)

	/*float tmp;
	max = 0.0;
	for(int i = 0; i<numberOfSectors; i++)
	{
		tmp = gdp[i][startYr - earliestYr + 1] - gdp[i][startYr - earliestYr];
		// By using tmp variable above, the calculation would only need to be done once
		if(max < tmp)
			max = tmp;
    }*/
}

void highestGrowth(float * gdp, int rawOrPercentage) // create a function similiar to highest growth but one that calculates most decay / lost
{
    /* Input rawOrPercentage determines if the highest growth of the year is based on
    highest growth on raw data or highest percentage growth from previous year
    with raw being 0 and percentage growth being 1*/
    // loop constant is (number of years - 1) since lastest year will have no consecutive increase.
    for(int i = 0; i<(latestYr - earliestYr); i++)
    {
        max = 0.0; // Max has to be resetted to 0 for every year
        for(int j = 0; j<numberOfSectors; j++)
        {
            if(max < consecutiveGrowth(j, (earliestYr + i), rawOrPercentage))
            {
                max = consecutiveGrowth(j, (earliestYr + i), rawOrPercentage);
                sectorIndexTracker = j;
            }
        }
        printf("The highest increase in GDP from %d to %d is %.2f ", (i + earliestYr), (i + earliestYr + 1), max); // add code that can change the format specifier to allow %.3f or higher precision
        printf("and the corresponding sector is "); sectorNamePrinter(sectorIndexTracker); newline(1);
    }
}

float consecutiveGrowth(int sectorIndex, int startYr, int growthType)
{
    /*
    Only the startYr is required as input parameter since the endYr would always be
    (startYr + 1) as this function only calculates growth between consecutive years.
    Input startYr should be passed in human readable format, code below already includes
    conversion for the format to array Index format.

    Growth Type input can define return value to be,
    (0) in terms of raw GDP growth OR increase between consecutive years.
    (1) in terms of percentage increase over the pervious year
    */
    switch(growthType)
    {
        case 0:
            return gdp[sectorIndex][startYr - earliestYr + 1] - gdp[sectorIndex][startYr - earliestYr];
            break;
        case 1:
            return (gdp[sectorIndex][startYr - earliestYr + 1] / gdp[sectorIndex][startYr - earliestYr] * 100.0) - 100.0;
            break;
        default:
            // Error Handler (internal Error)
            break;
    } // End of switch(growthType)
}

// Create a function to calculate consecutive decay? so if the growth is less than 0,
// then use bitshift to remove the sign but set a bool variable to keep track of either decay or growth

// Function to calculate average growth over the years

void sectorNamePrinter(int sectorIndex)
{
    // if(sectorNamesPassed == NULL)
        // printf("NULL value received\n");
    char **sectorNames = dataReader(3.2);
    if(sectorNames == NULL)
        errorHandler(0.1);
    
    charReplacer(sectorNames[sectorIndex], '\n', '\0');
    printf("'%s'", sectorNames[sectorIndex]);
    // printf("%s\n", *(sectorNames + i));
    // Alternate printing method using pointer dereferencing

    /*iterate again, freeing memory in each index*/
    for(int i = 0; i<numberOfSectors; i++){
        free(sectorNames[i]);
        sectorNames[i] = NULL;
        if(sectorNames[i] != NULL)
            errorHandler(0.3);
    }
    /*free the pointer to the array of pointers*/
    free(sectorNames);
    sectorNames = NULL;
    if(sectorNames != NULL)
        errorHandler(0.3);
}

void * sort_data(void * data, int algorithm_choice, int position, int returnType)
{
    /* Additional input parameters to consider:
        1) data type to specifer pointer type
        3) Miscancellous data to do program specific tasks, such as selectedYr from XhighestGDP()
            maybe add it as the floating point average of a input to save parameter
    */

    /* Function Description:
        Given a set of data, sort it to an order specified by the sort_type
        *Special Cases of recurring data, will be dealt differently based on the different type of sorting
        algorithm used. In some cases, only one instance of it will be recorded, but there might be data
        appended at the end of the return value to store additional information about the recurring data
        *Only certain algorithms are able to sought negative numbers
    */


    switch(algorithm_choice)
    {
        case 0: // Generic Sorting with some optimization
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

void * NminusOneAlgorithm(void * data, int algorithm_choice, int datatype, int returnType, int dataSize)
{
    switch(datatype)
    {
        case 0: // Integers
            (int*) data;
            break;
    }
    memcpy(arrangedDataHeap, arrangedDataStack, sizeof(float) * position);
    sortedData[dataSize];
    for(int i = 0; i<dataSize; i++)
        sortedData[i] = 0;
    int VariableDataSize = dataSize, tracker;
    for(int i = 0; i<dataSize; i++)
    {
        for(int j = 0; j<VariableDataSize; j++)
        {
            if(!*(data + j))
                continue;
            if(*(data + j) > sortedData[i])
            {
                sortedData[i] = *(data + j);
                tracker = j;
            }
        }
        *(data + j) = 0;
    }

}

void * XhighestGDP(float * gdp, int selectedYr, int position, int returnType) // Change name to DAta arranger?
{
    /* Add option to use the selectedYr input to select a sector instead to sort the data in the sector instead of a yr.
    */

    /* Input:
    (2) selectedYr defines the year for sorting
    (3) Position defines the data as xxx position from highest value to be returned.
        E.g. input '4' means the 4th highest GDP data. It also defines if the array for
        sorting should be created with 'position' or 'numberOfSectors' number of elements.
        If position is 1, lowesthighest can do the job, but XhighestGDP function
        should still be used during implementation for consistency.
        Position cannot be at 0, since the input should be of human readable format.
    (4) returnType is a boolean value (using int instead since C does not support bool type)
        that determines if the whole array is returned for further processing or just a single
        float value corresponding with the position value.
        
        *** 3 possible return types can be specified by the inputs (position, returnType)
        (position is !0, 0) return sorted data array with 'specified position' as number of elements
        (position is !0, 1) return list of sector index corresponding to sorted (position is !0, 0)
        (position is !0, 2) return a pointer to a value of 'position' and will set 'sectorIndexTracker'
        * The 3 return types will be commented as condition(1, 2, 3)
        * To sought the whole array and return the data or sector index, call either condition 1 or 2,
            and pass 'numberOfSectors' as 'position', with 'position' acting as loop control constant

        *** REGARDLESS of returnType, the data will be stored and returned via pointer to a heap memory
        locataion with values copied from stack memory after calculation, function caller is advised
        to free() memory via pointer IMMEDIATELY after using or moving data into its own data container
        (preferably of stack memory) to prevent memory leakage.
    */
    float arrangedDataStack[position];
    int arrangedSectorIndexStack[position];
    memset(arrangedDataStack, 0, sizeof(float) * position);
    /*for(int i = 0; i<position; i++)
        arrangedDataStack[i] = 0.0f;*/ // Loop alternative to memset

    arrangedDataStack[0] = lowesthighest(gdp, selectedYr, 1); // Setting highestvalue first
    arrangedSectorIndexStack[0] = sectorIndexTracker; // Setting sector index of highestvalue
    selectedYr -= earliestYr; // setting after lowesthighest() since it takes input in human format too
    int sectorJumper = latestYr - earliestYr + 1; // Used for 'jumping' through years in a 1D array to simulate a 2D one
    for(int i = 1; i<position; i++) // 'i' starts at 1 since index 0 has been set to the highest value already
        for(int j = 0; j<numberOfSectors; j++) // 'J' stands for sector number
            if((*(gdp + (j * sectorJumper) + selectedYr) > arrangedDataStack[i]) && (*(gdp + (j * sectorJumper) + selectedYr) < arrangedDataStack[i-1]))
            {
                arrangedDataStack[i] = *(gdp + (j * sectorJumper) + selectedYr);
                arrangedSectorIndexStack[i] = j;
            }
            
    if(!returnType) // Condition 1, where returnType is 0
    {
        float *arrangedDataHeap = (float*) calloc(position, sizeof(float));
        memcpy(arrangedDataHeap, arrangedDataStack, sizeof(float) * position);
        return arrangedDataHeap;
    }
    else if(returnType == 1) // Condition 2
    {
        int *arrangedSectorIndexHeap = (int*) calloc(position, sizeof(int));
        memcpy(arrangedSectorIndexHeap, arrangedSectorIndexStack, sizeof(int) * position);
        return arrangedSectorIndexHeap;
    }
    else if(returnType == 2) // Condition 3
    {
        sectorIndexTracker = arrangedSectorIndexStack[position - 1];
        float *XhighestDataHeap = (float*) malloc(sizeof(float));
        *XhighestDataHeap = arrangedDataStack[position - 1];
        return XhighestDataHeap;
    }
}


// Change the algorithm where the first data is set to the lowest first instead of higheset as initial lowest
// Learn about binary search and all the sorting algorithms
float lowesthighest(float * gdp, int selectedYr, int lowestORhighest) // Not working now, currently being modified
{
    /* Input parameters:
    (1) selectedYr is the year to loop through all the sectors.
    (2) lowestORhighest specifies if the lowest GDP of the year or the highest
    GDP should be returned. Input 0 for lowest and input 1 for highest*/
    
    max = 0.0; // change this to use inital values from data set instead of using assumptions
    selectedYr -= earliestYr;
    for(int i = 0; i<numberOfSectors ; i++)
        if(max < *(gdp + (i * (latestYr - earliestYr + 1)) + selectedYr))
        {
            max = *(gdp + (i * (latestYr - earliestYr + 1)) + selectedYr);
            sectorIndexTracker = i;
        }
    if(lowestORhighest) // Check if user wants the highest GDP data
        return max;
    
    lowest = max; // Assuming the biggest possible value to be lowest first
    // Change above initialization

    for(int i = 0; i<numberOfSectors ; i++)
        if(lowest > *(gdp + (i * (latestYr - earliestYr + 1)) + selectedYr))
        {
            lowest = *(gdp + (i * (latestYr - earliestYr + 1)) + selectedYr);
            sectorIndexTracker = i;
        }
    return lowest;

    // See if there is any other faster algorithm for this type of sorting


    // See if you can use the function to read a value by reference and modify it, so that I
    // can get both the largest and smallest at the same time even if the function can only return one value at once

    // step 1 determine if user is trying to find the highest or lowest or both
    switch(lowestORhighest)
    {
        case /*highest*/:
        for(int i = 0; i</*what I want to loop through*/; /*My loop variable action*/)
        {
            if(max < *(gdp + (i * (latestYr - 1 + earliestYr)) + selectedYr))
            {
                max = *(gdp + (i * (latestYr - earliestYr + 1)) + selectedYr);
                sectorIndexTracker = i;
            }
        }
    }
}

float comparer(float * gdp, int comparisonType, int sectorIndex, int year)
{
    /* Input:
        comparisonType:
        (0) to compare selected sector's GDP performance of a particular year to
        that year's average GDP performance across all available recorded sectors.
        (1) to compare the selected sector's GDP performance of a particular year to the
        average_performace(average GDP data) of the same sector over all recorded years.
        (2) to compare growth rate across all years and all sectors to find sector with
        the highest raw growth per consecutive year in terms of GDP.
        (3) same comparison as (2), except the comparison would be made in terms of
        percentage growth per sector between consecutive years.
        (4) to compare the growth rate of yearly averages regardless of sector


        sectorIndex and year:
        If the values are not utilised like in case 2, any values can be passed, but for clarity
        pass either 0 or comparisonType for easier standaridised function implementation.
    */

    /* See if using integer promotion and stuff to catergorise 2 n 3 tgt would be appropriate*/
    int sectorJumper = latestYr - earliestYr + 1; // Used for 'jumping' through years in a 1D array to simulate a 2D one
    switch(comparisonType)
    {
        case 0:
            return *(gdp + (sectorIndex * sectorJumper) + year) / AvrgOfYear(gdp, year) * 100.0;
            break;
        case 1:
            return *(gdp + (sectorIndex * sectorJumper) + year) / AvrgOfSector(gdp, sectorIndex, earliestYr, latestYr) * 100.0;
            break;
        case 2:
            highestGrowth(gdp, 0); break;
        case 3:
            highestGrowth(gdp, 1); break;

        default:
            errorHandler(0.1);
            break;
    }
}