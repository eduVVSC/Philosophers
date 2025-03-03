/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_redux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:35:24 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/14 14:03:59 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*populate_str(char const *s, int start, int end);
static int	count_words(char const *s, char c);
static int	check_case44(const char *str, int i);
static int	exec_loop(char const *s, char **arr, char c, int nr_words);

/* Split made to handle ' ' as an argument */
char	**ft_split_redux(char const *s, char c)
{
	char	**arr;
	int		nr_words;

	nr_words = count_words(s, c);
	arr = (char **)malloc((nr_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (exec_loop(s, arr, c, nr_words) == -1)
		return (ft_free_double_arr(&arr), NULL);
	arr[nr_words] = NULL;
	return (arr);
}

static int	exec_loop(char const *s, char **arr, char c, int nr_words)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = -1;
	while (j < nr_words)
	{
		if (s[i] != c && index < 0)
			index = i;
		if ((s[i] == c || i == (int)ft_strlen(s)) && index >= 0)
		{
			i += check_case44(s, i);
			arr[j] = populate_str(s, index, i);
			if (arr[j] == NULL)
				return (-1);
			j++;
			index = -1;
		}
		i++;
	}
	return (0);
}

/*Checks for the next quote and returns the difference between
current position and last quote position*/
static int	check_case44(const char *str, int i)
{
	int	close_quote;

	close_quote = 0;
	if (str[i - 1] == '\'')
	{
		while (str[i + close_quote] != '\'' || str[i + close_quote] == '\0')
			close_quote++;
	}
	return (close_quote);
}

static char	*populate_str(char const *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while ((i + start) < end)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}

/*Implemented a loop inside the condition to count
words to check if a quote was found,
and if so, it keeps iterating until it finds another quote*/
static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			if (s[i] == '\'')
			{
				while (s[i] != '\'' && s[i])
					i++;
				if (s[i + 1] == '\0')
					words++;
			}
			else
				words++;
		}
		i++;
	}
	return (words);
}
