#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **a;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	a = malloc((1 + numwords) * sizeof(char *));
	if (!d)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		a[j] = malloc((k + 1) * sizeof(char));
		if (!a[j])
		{
			for (k = 0; k < j; k++)
				free(a[k]);
			free(a);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			a[j][m] = str[i++];
		a[j][m] = 0;
	}
	a[j] = NULL;
	return (a);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char b)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
<<<<<<< HEAD
		if ((str[i] != b && str[i + 1] ==b) ||
=======
		if ((str[i] != b && str[i + 1] == b) ||
>>>>>>> 222c35732d94a6911771719543b4a4b41abf439b
				    (str[i] != b && !str[i + 1]) || str[i + 1] == b)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == b && str[i] != b)
			i++;
		k = 0;
		while (str[i + k] != b && str[i + k] && str[i + k] != b)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
