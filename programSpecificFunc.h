#ifndef programSpecificFunc_H
#define programSpecificFunc_H

void sectorNamePrinter(int sectorIndex);
float AvrgOfSector(float * gdp, int sectorIndex, int startYr, int endYr);
float AvrgOfYear(float * gdp, int year);
float growthRate(int growthType);
float consecutiveGrowth(int sectorIndex, int startYr, int growthType);
void * XhighestGDP(float * gdp, int selectedYr, int position, int returnType);
float lowesthighest(float * gdp, int selectedYr, int lowestORhighest);
float comparer(float * gdp, int comparisonType, int sectorIndex, int year);

#endif