#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

#define PARENT(X) (X >> 1)
#define LEFT(X) ((X << 1) + 1)
#define RIGHT(X) ((X << 1) + 2)


void build_max_heap(int *array, size_t size);
void heap_sort(int *array, size_t size);
void max_heapify(int *array, size_t index, size_t size, size_t total);
void swap(int *a, int *b);
void print_array(int*, size_t);

#endif /* SORT_H */
