#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

// Implementation of Merge Sort merge helper
// Credit to https://www.geeksforgeeks.org/merge-sort/ for pseudocode
void merge(int *array, int l, int mid, int r)
{
    int i, j, k; 
    int n1 = mid - l + 1; 
    int n2 = r - mid; 
  
    // create temp arrays
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays L and R
    for (i = 0; i < n1; i++) 
        L[i] = array[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = array[mid + 1 + j]; 
  
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            array[k] = L[i]; 
            i++; 
        } 
        else { 
            array[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        array[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        array[k] = R[j]; 
        j++; 
        k++; 
    } 
}

// Implementation of Merge Sort
// Credit to https://www.geeksforgeeks.org/merge-sort/ for pseudocode
void mergeSort(int *array, int l, int r)
{
    if(l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(array, l, mid);
        mergeSort(array, mid + 1, r);

        merge(array, l, mid, r);
    }

    return;
}


