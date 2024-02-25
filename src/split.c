/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:43:35 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/16 12:14:56 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (NULL);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '\t'))
			words++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
	}
	return (words);
}

void	check_string(char **new, char *str)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	words = -1;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		if (j < i)
		{
			new[++words] = (char *)malloc(sizeof(char ) * ((i - j) + 1));
			if (!new[words])
			{
				free_array(new);
				return ;
			}
			ft_strncpy(new[words], &str[j], i - j);
		}
	}
	new[words + 1] = NULL;
}

char	**ft_split(char *str)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!new)
		return (NULL);
	check_string(new, str);
	return (new);
}
