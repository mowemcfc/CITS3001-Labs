#ifndef STRINGALG_H_
#define STRINGALG_H_

int naive(char* T, char* P, int** matches);
int rabinKarp(char* T, char* P, int q, int d, int** matches);
int knuthMorrisPratt(char* T, char* P, int** matches);
void computePrefix(char* P);

#endif
