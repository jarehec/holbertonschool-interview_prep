#include "regex.h"

/**
* str_len - returns the length of a string
* @s: string input
* Return: length of s
*/
int str_len(const char *s)
{
	unsigned int len;

	for (len = 0; s[len] != '\0'; len++)
	;

	return (len);
}

/**
 * regex_match - compares a string and a pattern
 * @str: string to analyze
 * @pattern: search pattern
 * Return: 1 if string matches pattern, else 0
 */
int regex_match(char const *str, char const *pattern)
{
	int i, prev, pos;

	for (i = 0, prev = 0, pos = 0; i < str_len(str); ++i)
	{
		if (!pattern[pos])
			return (0);
		else if ((pattern[pos] == '.') || (pattern[pos] == str[i]))
			++pos;
		else if (pattern[pos] == '*')
			prev = (prev == 0 ? i : prev);
		else if (pattern[pos] != str[i])
		{
			if (prev != 0)
			{
				i = prev + 1;
				prev = 0;
			}
			else
				return (0);
		}
	}
	return (1);
}
