#include<stdbool.h>

#ifndef HELPERS_H_
#define HELPERS_H_

void alloc_results_memory(double*** results, int rows, int cols);
void record_result(double** results, int num, int n, double time);
void populate_random_int_array(int** a, int n);
bool is_sorted(int* a, int n);


#endif