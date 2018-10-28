#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *array, size_t size);
int i_pow(int x, int y);
int get_max(int *arr, size_t size);
int *bucket_sorted(int *arr, int it, size_t size);
void print_array(const int *array, size_t size);

#endif
