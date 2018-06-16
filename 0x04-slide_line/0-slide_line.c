#include "slide_line.h"

/**
 * combine_left - combines identical ints moving leftward
 * @arr: a pointer to an integer array
 * @size: number of items in the array
 */
void combine_left(int *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			arr[i + 1] *= 2;
			arr[i] = 0;
			++i;
		}
	}
}

/**
 * combine_right - combines identical ints moving rightward
 * @arr: a pointer to an integer array
 * @size: number of items in the array
 */
void combine_right(int *arr, size_t size)
{
	size_t i;

	for (i = size - 1; i + 1 > 1; i--)
	{
		if (arr[i] == arr[i - 1])
		{
			arr[i - 1] *= 2;
			arr[i] = 0;
			--i;
		}
	}
}

/**
 * shift_ints_left - moves all ints leftward
 * @arr: a pointer to an integer array
 * @size: number of items in the array
 */
void shift_ints_left(int *arr, size_t size)
{
	size_t i, tmp;

	for (i = 1; i < size; i++)
	{
		if (arr[i] != 0)
		{
			tmp = i;
			while (arr[i - 1] == 0 && i > 0)
			{
				arr[i - 1] = arr[i];
				arr[i] = 0;
				--i;
			}
			i = tmp;
		}
	}
}

/**
 * shift_ints_right - moves all ints rightward
 * @arr: a pointer to an integer array
 * @size: number of items in the array
 */
void shift_ints_right(int *arr, size_t size)
{
	size_t i, tmp;

	for (i = size - 2; i + 1 > 0; i--)
	{
		if (arr[i] != 0)
		{
			tmp = i;
			while (arr[i + 1] == 0 && i < size - 1)
			{
				arr[i + 1] = arr[i];
				arr[i] = 0;
				++i;
			}
			i = tmp;
		}
	}
}

/**
 * slide_line - slides a line to a direction, adding indentical ints
 * @line: a pointer to an array of ints
 * @size: number of elements in the array
 * @direction: left or right
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size < 1)
		return (0);
	switch (direction)
	{
		case SLIDE_LEFT:
			shift_ints_left(line, size);
			combine_left(line, size);
			shift_ints_left(line, size);
			break;
		case SLIDE_RIGHT:
			shift_ints_right(line, size);
			combine_right(line, size);
			shift_ints_right(line, size);
	}
	return (1);
}
