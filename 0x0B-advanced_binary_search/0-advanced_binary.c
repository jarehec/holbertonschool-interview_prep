#include "search_algos.h"


/**
 * print_array - prints an array of ints
 * @array: pointer of array
 * @size: number of elements
 */
void print_array(int *array, size_t size)
{
	size_t i = 0;

	printf("Searching in array: ");
	for (; i < size; i++)
		i + 1 < size ?
			printf("%d, ", array[i]) :
			printf("%d\n", array[i]);
}

/**
 * binary_search - helper for advanced_binary
 * @array: array of ints
 * @val: val to search
 * @left: left index
 * @right: right index
 * Return: first index of val
 */
int binary_search(int *array, int val, size_t left, size_t right)
{
	size_t mid = (left + (right - 1)) / 2;

	print_array(&array[left], right - left);
	if (array[left] == val && left == mid)
		return (left);

	if (left + 1 == right || right == left)
		return (-1);

	if (array[mid] > val)
		return (binary_search(array, val, left, mid - 1));

	if (array[mid] < val)
		return (binary_search(array, val, mid + 1, right));

	if (array[mid] == val && array[mid - 1] == val)
		return (binary_search(array, val, left, mid + 1));

	if (array[mid] == val && array[mid + 1] == val)
		return (binary_search(array, val, mid, right));

	return (array[mid] == val ? val : -1);
}


/**
 * advanced_binary - finds the first index of a value
 * @array: pointer to int array
 * @size: number of elements in array
 * @value: value to search
 * Return: index of value or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);
	return (binary_search(array, value, 0, size));
}
