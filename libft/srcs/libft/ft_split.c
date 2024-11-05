/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_words(char *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	*copy_word(char *src, int length)
{
	char	*word;
	int		i;

	word = (char *)malloc((length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	add_word(char **result, char *str, char sep)
{
	int	length;
	int	i;
	int	word_index;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			length = 0;
			while (str[i + length] && str[i + length] != sep)
				length++;
			result[word_index] = copy_word(&str[i], length);
			i += length;
			word_index++;
		}
		else
			i++;
	}
	result[word_index] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	char	*p;

	p = (char *)s;
	word_count = count_words(p, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	add_word(result, p, c);
	return (result);
}
