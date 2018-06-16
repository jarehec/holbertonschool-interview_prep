#include "slide_line.h"

/**
 * shift_ints_left - moves all ints to the left
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
 * shift_ints_right - moves all ints to the right
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
	size_t i;

	if (!line || size < 1)
		return (0);
	switch (direction)
	{
		case SLIDE_LEFT:
			shift_ints_left(line, size);
			for (i = 0; i < size - 1; i++)
			{
				if (line[i] == line[i + 1])
				{
					line[i + 1] *= 2;
					line[i] = 0;
					++i;
				}
			}
			shift_ints_left(line, size);
			break;
		case SLIDE_RIGHT:
			shift_ints_right(line, size);
			for (i = size - 1; i + 1 > 1; i--)
			{
				if (line[i] == line[i - 1])
				{
					line[i - 1] *= 2;
					line[i] = 0;
					--i;
				}
			}
			shift_ints_right(line, size);
			break;
	}
	return (1);
}
