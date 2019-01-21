#include "holberton.h"
#include <stdio.h>


/**
 * str_len - gets the length of a string recursively
 * @str: pointer to beginning of string
 * @len: length counter, initially 0
 * Return: number of characters in the string
 */
int str_len(char *str, int len)
{
	return (*str ? str_len(str + 1, ++len) : len);
}


/**
 * walk - does magic
 * @s1: string
 * @s2: string pattern
 * @offset: offset
 * Return: int
 */
int walk(char *s1, char *s2, int *offset)
{
	int ret = 0, tmp;



	if (!str_len(s1, 0) || !str_len(s2, 0))
		return (1);
	if (*s1 == *s2)
		return (walk(++s1, ++s2, offset));

	if (*s2 == '*')
	{
		if (s2[1] == '*')
			return (walk(s1, ++s2, offset));


		if (*s1 == s2[*offset + 1])
		{
			tmp = *offset + 1;
			ret = walk(s1 + 1, s2, &tmp);

			if (ret == 1)
				return (1);
			return (walk(s1 + *offset, s2, offset));
		}
		else
		{
			tmp = 1;
			return (walk(s1 + *offset, s2, &tmp));
		}
	}
	else
		return (0);
	return (ret);
}


/**
 * wildcmp - compares two strings, accounting for wildcards
 * @s1: string 1
 * @s2: string 2
 * Return: boolean
 */
int wildcmp(char *s1, char *s2)
{
	int i = 0;

	i = walk(s1, s2, &i) == 1;

	return (i);
}
