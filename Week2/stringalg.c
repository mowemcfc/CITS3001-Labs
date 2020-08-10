#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

// Naive String matching algorithm implementation
// Credit to CLRS Introduction to Algorithms textbook for pseudocode
// O(m(n - m + 1)) Worst Case complexity

int naive(char* T, char* P, int** matches) {
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
            (*matches)[matchCount] = s;
            ++matchCount;
        }
    }

    return matchCount;
}

// Implementation of Rabin-Karp string matching algorithm
// Credit to CLRS Introduction to Algorithms textbook for pseudocode
// O(nm) Worst-Case Complexity, O(m + n) expected time
int rabinKarp(char* T, char* P, int q, int d, int** matches) {
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
                (*matches)[matchCount] = s;
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

// Pi array computation function for Knuth-Morris-Pratt string match
int* computePrefix(char* P) {
    int m = strlen(P);
    int* pi = malloc(m * sizeof(int));
    pi[0] = 0;

    int k = 0;

    for(int q = 2; q < m; ++q) {
        while ((k > 0) && (P[k+1] != P[q])) {
            k = pi[k];

            if(P[k+1] == P[q]) {
                ++k;
            }

            pi[q] = k;
        } 
    }

    return pi;
}

// Implementation of Knuth-Morris-Pratt string match - modelled after the Finite Automaton Matcher
// Credit to CLRS Introduction to Algorithms textbook for pseudocode
//
int knuthMorrisPratt(char* T, char* P, int** matches) {
    int n = strlen(T);
    int m = strlen(P);
    int* pi = computePrefix(P);
    int q = 0;

    int matchCount = 0;

    for(int i = 1; i < n-1; ++i) {
        while ((q > 0) && (P[q + 1] != T[i])) {
            q = pi[q];

            if(P[q+1] == T[i]) {
                ++q;
            }

            if(q == m) {
                (*matches)[matchCount] = i - m;
                ++matchCount;
                q = pi[q];
            }
        }
    }
    return matchCount;
}