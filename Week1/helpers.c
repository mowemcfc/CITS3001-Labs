#include<stdbool.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

// Formats input result array into readable format and prints to stdout
void report_results(double** results, int n) 
{
    for(int i = 0; i < n; i++){
        printf("\n Test: %d, size: %d, time: %lf", (int)results[i][0], (int)results[i][1], results[i][2]);
    }

    return;
}

// Allocates memory for test result array
void alloc_results_memory(double*** results, int rows, int cols){
    *results = (double **)malloc(rows*sizeof(double*));
    for(int i=0; i<rows; i++){
        (*results)[i] = (double*) malloc(cols * sizeof(double));
    }

    return;
}

// Takes array of test results and appends new entry
void record_result(double*** results, int test_num, int n, double time)
{
    (*results)[test_num][0] = (double)test_num;
    (*results)[test_num][1] = (double)n;
    (*results)[test_num][2] = time;
    return;
}

// Generates random integer array of length n
void populate_random_int_array(int** a, int n) 
{
    int randNum;
    time_t t;
    *a = malloc(n * sizeof(int));
    srand((unsigned) time(&t));

    for (int i = 0; i < n; i ++) {
        randNum = rand() % 1000;
        (*a)[i] = randNum;
    }

}

// Checks if given array is in ascending order
bool is_sorted(int* a, int n)
{
    bool sorted = true;

    for(int i = 0; i < n-1; i++){
        if(a[i+1] < a[i]){
            sorted = false;
            break;
        }
    }

    return sorted;
}