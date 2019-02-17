#include "substring.h"

/**
* str_eq - checks if two strings are equal
* @s1: string input
* @s2: string input
* @n: length of s1 and s2
* Return: 1 if equal, else 0
*/
int str_eq(const char *s1, const char *s2, int n)
{
	for (--n; s1[n] == s2[n] && n >= 0; --n)
	;

	return (n == -1);
}

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
* reset - clears a string
* @str: string input
* @size: length of str
*/
void reset(char *str, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		str[i] = '0';
}

/**
* find_substring - finds all the possible substrings of words in a given string
* @s: string input
* @words: words to find
* @nb_words: number of words
* @n: number of found substrings
* Return: array of indices, else null
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, word_len, todo = nb_words, start = 0, matched = 0, *result;
	char flag = 0, *marker = NULL;

	if (!s || !*words || nb_words < 1 || (str_len(words[0]) > str_len(s)))
		return (NULL);

	word_len = str_len(words[0]);
	marker = calloc(nb_words, sizeof(char));
	if (!marker)
		return (NULL);

	result = calloc(str_len(s) - (word_len * nb_words), sizeof(int));
	if (!result)
	{
		free(marker);
		return (NULL);
	}

	for (i = 0; i <= str_len(s) - word_len; )
	{
		flag = 0;
		for (j = 0; j < nb_words && flag == 0; ++j)
		{
			if (marker[j] != '1' && str_eq(s + i, words[j], word_len))
				flag = 1, marker[j] = '1', --todo;
		}
		if (todo == 0 || flag != 1)
		{
			todo == 0 ? result[matched++] = start : 0;
			reset(marker, nb_words);
			todo = nb_words;
			start += word_len;
			i = start;
		}
		else
			i += word_len;
	}
	free(marker);
	*n = matched;
	return (result);
}
