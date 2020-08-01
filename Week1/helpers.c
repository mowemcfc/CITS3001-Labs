#include<stdbool.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
// Generates random integer array of length n
int* generate_random_array(int n) 
{
    int randNum;
    int* a = malloc(n*sizeof(int));
    time_t t;

    srand((unsigned) time(&t));

    for (int i = 0; i < n; i ++) {
        randNum = rand() % 1000;
        a[i] = randNum;
    }

    return a;
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