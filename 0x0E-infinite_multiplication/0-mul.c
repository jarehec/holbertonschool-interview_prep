#include "holberton.h"
#include <stdio.h>

/**
 * _isdigit - checks if string is a number
 * @s: string
 * Return: 0 on sucess, else -1
 */
int _isdigit(char *s)
{
	int i = 0;

	if (!s)
		return (-1);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (0);
}

/**
 * _strlen - gets the lemgth of a string
 * @str: char *
 * Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t i = 0;

	if (str)
		for (; str[i]; i++)
			;
	return (i);
}

/**
 * _puts - prints a string followed by a newline
 * @str: char *
 */
void _puts(char *str)
{
	size_t i = 0;

	if (str)
		for (; str[i]; i++)
			_putchar(str[i]);
	_putchar('\n');
}

/**
 * main - Entry point
 * @argc: number of args
 * @argv: string of pointers
 * Return: status code
 */
int main(int argc, char **argv)
{
	char *result = NULL, *top, *bottom;
	int carry = 0, l_len, r_len, i, j, tmp;

	if (argc != 3 || _isdigit(argv[1]) != 0 || _isdigit(argv[2]) != 0)
	{
		_puts("Error");
		exit(98);
	}

	l_len = _strlen(argv[1]);
	r_len = _strlen(argv[2]);
	result = malloc(sizeof(char) * (l_len + r_len));
	if (!result)
	{
		_puts("Error");
		exit(98);
	}

	for (i = 0; i < l_len + r_len; i++)
		result[i] = '0';

	top = l_len > r_len ? argv[1] : argv[2];
	bottom = l_len > r_len ? argv[2] : argv[1];

	for (i = (l_len > r_len ? r_len : l_len) - 1; i >= 0; i--)
	{
		for (j = (l_len > r_len ? l_len : r_len) - 1; j >= 0; j--)
		{
			tmp = (bottom[i] - '0') * (top[j] - '0');
			tmp += (result[(i + j + 1)] - '0') + carry;
			carry = tmp / 10;
			result[(i + j + 1)] = (tmp % 10) + '0';
		}
		if (carry != 0)
			result[i] = carry + '0';
		carry = 0;
	}
	result[0] == '0' ? ++result : 0;
	_puts(result);

	return (0);
}
