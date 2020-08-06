#ifndef STRINGALG_H_
#define STRINGALG_H_

int naive(char* T, char* P, int** result);
int rabinKarp(char* T, char* P, int q, int d, int** result);
int knuthMorrisPratt(char* T, char* P);
void computePrefix(char* P);

#endif
