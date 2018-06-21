#ifndef MENGER_H
#define MENGER_H
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void menger(int level);
void free_grid(char **grid, size_t size);
void print_grid(char **grid, size_t size);
void fill_perimeter(char **block, char **grid, size_t size);

#endif
