#include "substring.h"

/**
 * not_in - return 1 if 'q' not in array 'arr'
 * @arr: an array of ints
 * @len: the length of arr
 * @q: the value to check for
 * Return: 1 if value not found, else 0
 */
int not_in(int *arr, int len, int q)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == q)
			return (0);
	}
	return (1);
}

/**
 * str_match - match word as a substring of str
 * @str: a string
 * @word: an array of words
 * Return: 1 if word is a substring of str, 0 otherwise
 */
int str_match(char const *str, char const *word)
{
	int i = 0;

	for (i = 0; *(word + i) != '\0'; i++)
	{
		if (*(str + i) != *(word + i))
			return (0);
	}
	return (1);
}

/**
 * full_match - find if a substring match occurs at a single location
 * @s: a string
 * @words: an array of words
 * @nb_words: the number of elements in parameter 'words'
 * @word_len: the length of each word
 * Return: 1 if a full match of a substring made of 'words' exists, 0 otherwise
 */
int full_match(char const *s, char const **words, int nb_words, int word_len)
{
	int *done;
	int done_len = 0;
	int found = 0;
	int match = 1;
	int j, k, l;
	int aint;

	done = malloc(sizeof(int) * nb_words);

	for (l = 0; l < nb_words; l++)
		done[l] = -1;

	for (j = 0; j < nb_words; j++)
	{
		found = 0;
		for (k = 0; k < nb_words; k++)
		{
			aint = not_in(done, done_len, k);
			if (aint && str_match((s + (j * word_len)), words[k]))
			{
				done[done_len] = k;
				done_len++;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			match = 0;
			break;
		}
	}
	free(done);
	return (match);
}

/**
 * find_substring - finds all the possible substrings containing a list of
 * words, within a given string.
 * @s: the string to scan
 * @words: the array of words all substrings must be a concatenation
 * arrangement of
 * @nb_words: the number of elements in the array @words
 * @n:  the address at which to store the number of elements in the
 * returned array.
 * Return:  allocated array, storing each index in s, at which a substring
 * was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result;
	int str_len = 0;
	int word_len = 0;
	int i;

	*n = 0;
	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		str_len++;
	for (i = 0; words[0][i] != '\0'; i++)
		word_len++;

	result = malloc(sizeof(int) * str_len);
	if (result == NULL)
		return (NULL);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (full_match(s + i, words, nb_words, word_len))
		{
			result[*n] = i;
			*n = *n + 1;
		}
	}

	if (*n == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}
