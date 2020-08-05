#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int naive(char* T, char* P, int** result) {
    bool match;
    int matchCount = 0;

    int n = strlen(T);
    int m = strlen(P);

    for(int s = 0; s < n - m; ++s) {
        int j;
        match = true;

        for(j = 0; j < m; ++j) { // 
            if (T[s+j] != P[j]) {
                match = false;
            }
        }

        if (match == true) {
            (*result)[matchCount] = s;
            ++matchCount;
        }
    }

    return matchCount;
}