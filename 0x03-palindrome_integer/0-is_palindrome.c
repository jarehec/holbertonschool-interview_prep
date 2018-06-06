#include "palindrome.h"

/**
 * i_len - gets the length of an int
 * @n: integer
 * Return: length of the integer
 */
unsigned int i_len(int n)
{
	unsigned int len = 0;

	for (; n > 0; n /= 10)
		len++;
	return (len);
}

/**
 * i_pow - calculates x to the power of y
 * @x: integer
 * @y: integer
 * Return: x^y
 */
unsigned int i_pow(int x, int y)
{
	unsigned int result = 1;

	for (; y > 0; y--)
		result *= x;
	return (result);
}

/**
 * is_palindrome - checks if an integer is a palindrome
 * @n: unsigned integer
 * Return: boolean
 */
int is_palindrome(unsigned long n)
{
	unsigned int offset, int_len, i = 1;

	if (i_len(n) < 2)
		return (1);
	int_len = i_pow(10, (i_len(n) - 1));
	offset = int_len;
	while (i < int_len)
	{
		if ((n / (int_len / i)) % 10 != (n / (int_len / offset)) % 10)
			return (0);
		i *= 10;
		offset /= 10;
	}
	return (1);
}
