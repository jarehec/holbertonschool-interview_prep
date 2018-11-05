#include "sort.h"

/**
 * merge - merges a and b in sorted order
 * @a: int array
 * @b: int array
 * @low: start index
 * @mid: middle index
 * @high: end index
 */
void merge(int *a, int *b, size_t low, size_t mid, size_t high)
{
	size_t l1 = low, l2 = mid, i;

	for (i = low; i < high; i++)
		a[i] = b[i];

	printf("Merging...\n[left]: ");
	print_array(&a[low], mid - low);
	printf("[right]: ");
	print_array(&a[mid], high - mid);

	for (i = low; i < high; i++)
	{
		if (l1 < mid && (l2 >= high || a[l1] <= a[l2]))
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}
	printf("[Done]: ");
	print_array(&b[low], high - low);
}

/**
 * split_merge - splits the array into halves
 * @a: int array
 * @b: int array
 * @low: start index
 * @high: end index
 */
void split_merge(int *a, int *b, size_t low, size_t high)
{
	size_t mid;

	if (high - low < 2)
		return;

	mid = (low + high) / 2;
	split_merge(a, b, low, mid);
	split_merge(a, b, mid, high);
	merge(b, a, low, mid, high);
}

/**
 * merge_sort - sorts an array using the merge sort algorithm
 * @array: array to sort
 * @size: number of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;
	size_t i;

	if (!array || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	for (i = 0; i < size; i++)
		buffer[i] = array[i];

	split_merge(array, buffer, 0, size);
	free(buffer);
}
