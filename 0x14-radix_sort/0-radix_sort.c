#include "sort.h"

/**
 * i_pow - calculates x to the power of y
 * @x: integer
 * @y: integer
 * Return: x^y
 */
int i_pow(int x, int y)
{
	int result = 1;

	for (; y > 0; y--)
		result *= x;
	return (result);
}

/**
 * bucket_sorted - sorts the numbers in a bucket
 * @arr: integer array
 * @it: iterator
 * @size: number of elements
 * Return: integer
 */
int *bucket_sorted(int *arr, int it, size_t size)
{
	int i, j, digit, **buckets = NULL;
	size_t b_size;

	if (!arr || size < 2)
		return (NULL);

	b_size = (size < 10) ? 10 : size;
	buckets = malloc(sizeof(int *) * b_size);
	if (!buckets)
		return (NULL);

	for (i = 0; (size_t)i < b_size ; i++)
	{
		buckets[i] = malloc(sizeof(int) * 10);
		if (!buckets[i])
		{
			for (--i; i >= 0; i--)
				free(buckets[i]);
			return (NULL);
		}
		for (j = 0; j < 10; j++)
			buckets[i][j] = -1;
	}
	for (i = 0; (size_t)i < size; i++)
	{
		digit = (arr[i] / i_pow(10, it)) % 10;
		for (j = 0; buckets[digit][j] != -1; j++)
			;
		buckets[digit][j] = arr[i];
	}
	for (i = 0, digit = 0; (size_t)i < b_size; i++)
		for (j = 0; buckets[i][j] != -1; j++)
		{
			arr[digit] = buckets[i][j];
			digit++;
		}
	for (i = 0; (size_t)i < b_size; i++)
		free(buckets[i]);
	free(buckets);
	return (arr);
}

/**
 * get_max - gets the largest int in an array
 * @arr: array of ints
 * @size: number of elements
 * Return: integer
 */
int get_max(int *arr, size_t size)
{
	int max;

	if (!arr || size < 2)
		return (0);

	for (max = arr[0], --size; size > 1; size--)
		max = arr[size] > max ? arr[size] : max;

	return (max);
}


/**
 * radix_sort - sorts an array of integers using the radix sort algorithm
 * @array: array of integers
 * @size: number of elements in the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int it, max = get_max(array, size);

	if (!array || size < 2)
		return;

	for (it = 0; i_pow(10, it) <= max; it++)
	{
		bucket_sorted(array, it, size);
		print_array(array, size);
	}
}
