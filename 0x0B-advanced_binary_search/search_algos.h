#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS
#include <stdio.h>
#include <stddef.h>

int advanced_binary(int *array, size_t size, int value);
int binary_search(int *array, int val, size_t left, size_t right);
void print_array(int *array, size_t size);
#endif
