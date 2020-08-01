#include<stdbool.h>

#ifndef HELPERS_H_
#define HELPERS_H_

void record_result(int** results, int num, int n, double time);
int* generate_random_array(int n);
bool is_sorted(int* a, int n);


#endif