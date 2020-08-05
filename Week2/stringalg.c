#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

// Naive String matching algorithm implementation
// Credit to https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/ for pseudocode

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

int rabinKarp(char* T, char* P, int q, int** result) {
    int n = strlen(T);
    int m = strlen(P);

    int p0 = 0; // p''
    int z = 0; // z'

    int matchCount = 0;

    // preprocessing step for pattern conversion to hash value mod q
    for(int j = 0; j < m-1; ++j) {
        p0 = (p0 * 10 + (P[j] -'0')) % q; // requires conversion of char to int representation
    }

    for(int j = 0; j < m-2; ++j) {
        z = (z * 10 + (T[j] - '0')) % q; // get hash mod q for first substring in T
    }

    for(int s = 0; s < n-m; ++s) {
        z = (z % (int)pow(10, m-1) * 10 + (T[s + m - 1] - '0')) % q; // rolling hash value as we 'window slide' over T

        printf("s: %d, z: %d, p0: %d \n", s, z, p0);
        if(z == p0) { // if hashes mod q match ...
            int j;
            for(j = 0; j < m; ++j) { // compare strings value by value, break at mismatch
                if (T[s+j] != P[j]) {
                    break;
                }
            }

            if(j == m) { // if j == length of pattern, we have a match
                (*result)[matchCount] = s;
                matchCount++;
            }
        }
    }


    return matchCount;
}