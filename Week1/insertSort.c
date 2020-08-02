#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertSort.h"

// CITS3001 Week 1 Labsheet
// Basic implementation of Insert Sort
// Credit to https://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_algorithm.htm for pseudocode

void insertSort(int** array, int len)
{

    for(int i = 1; i < len; i++){
        int insertVal = (*array)[i];
        int holePos = i;

        while((holePos > 0) && ((*array)[holePos-1] > insertVal)){
            (*array)[holePos] = (*array)[holePos-1];
            holePos--;
        }

        (*array)[holePos] = insertVal;
    }

}

