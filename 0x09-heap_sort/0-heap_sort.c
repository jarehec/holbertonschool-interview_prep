#include "sort.h"


/**
* swap - swaps the value of a and b
* @a: value at a
* @b: value at b
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * max_heapify - maintains max heap property
 * @array: pointer to array
 * @i: index of array
 * @size: right index
 * @total: number of elements
 */
void max_heapify(int *array, size_t i, size_t size, size_t total)
{
	size_t left = LEFT(i), right = RIGHT(i), max = i;

	if (left < size && array[left] > array[i])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, total);
		max_heapify(array, max, size, total);
	}
}

/**
 * build_max_heap - builds a max heap from an array
 * @array: array of integers
 * @size: number of elements
 */
void build_max_heap(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, i, size, size);
}


/**
 * heap_sort - sorts an array using the heapsort algorithm
 * @array: array of integers
 * @size: number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	build_max_heap(array, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[i], &array[0]);
		print_array(array, size);
		max_heapify(array, 0, i, size);
	}
}
