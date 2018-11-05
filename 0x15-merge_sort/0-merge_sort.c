#include "sort.h"

/**
 * merge - merges a and b in sorted order
 * @a: int array
 * @b: int array
 * @low: start index
 * @mid: middle index
 * @high: end index
 * @size: number of elements in array
 */
void merge(int *a, int *b, size_t low, size_t mid, size_t high, size_t size)
{
	size_t l1 = low, l2 = mid + 1, i;

	for (i = low; i <= high; i++)
		b[i] = a[i];

	/* printf("low: %lu, mid: %lu, high: %lu\n", low, mid, high);*/

	printf("Merging...\n[left]: ");
	print_array(&b[low], high - low);
	printf("[right]: ");
	print_array(&b[mid + 1], size - mid);
	for (i = low; i <= high; i++)
	{
		if (l1 > mid)
			a[i] = b[l2++];
		else if (l2 > high)
			a[i] = b[l1++];
		else if (b[l2] < b[l1])
			a[i] = b[l2++];
		else
			a[i] = b[l1++];
	}
	printf("[Done]: ");
	print_array(&a[low], size - low);
	/* getchar();*/
}

/**
 * split_merge - splits the array into halves
 * @a: int array
 * @b: int array
 * @low: start index
 * @high: end index
 * @size: number of elements in array
 */
void split_merge(int *a, int *b, size_t low, size_t high, size_t size)
{
	size_t mid;

	if (high <= low)
		return;

	mid = (low + high) / 2;
	split_merge(a, b, low, mid, size);
	split_merge(a, b, mid + 1, high, size);
	merge(a, b, low, mid, high, size);
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

	split_merge(array, buffer, 0, size - 1, size);
	free(buffer);
}
