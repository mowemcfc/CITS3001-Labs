#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

// Naive String matching algorithm implementation
// Credit to https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/ for pseudocode
// O(m(n - m + 1)) Worst Case complexity

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

// Implementation of Rabin-Karp string matching algorithm
// Credit to https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/ for pseudocode
// O(nm) Worst-Case Complexity, O(m + n) expected time
int rabinKarp(char* T, char* P, int q, int d, int** result) {
    int n = strlen(T);
    int m = strlen(P);

    int p0 = 0; // p''
    int z = 0; // z'
    int h = (int)pow(2,m-1) % q;

    int matchCount = 0;

    // preprocessing step for initial p'', z' value assignment
    for(int i = 0; i < m; ++i) {
        p0 = (d * p0 + P[i]) % q; // requires conversion of char to int representation
        z = (d * z + T[i]) % q;
    }

    for(int s = 0; s <= n-m; ++s) {
        if(z == p0) { // if hashes mod q match ...
            int j;
            for(j = 0; j < m; ++j) { // compare strings value by value, break at mismatch
                if (T[s+j] != P[j]) {
                    break;
                }
            }

            if(j == m) { // if j == length of pattern, we have a match
                (*result)[matchCount] = s;
                ++matchCount;
            }
        }

        if(s < n-m) {
            z = (d*(z-T[s]*h) + T[s+m]) % q; // rolling z' calculation as we 'window shift' across T

            if(z<0) { // z' can sometimes be negative, so we can address this by adding q
                z += q;
            }
        }
    }

    return matchCount;
}

// Implementation of Knuth-Morris-Pratt string match
// Credit to CLRS Textbook for pseudocode
//
int knuthMorrisPratt(char* T, char* P) {

    return 0;
}

void computePrefix(char* P) {

    return;
}