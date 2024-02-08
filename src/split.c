/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:37:12 by paubotargue       #+#    #+#             */
/*   Updated: 2024/01/10 11:47:54 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **split, size_t i)
{
	while (i-- > 0)
		free(split[i]);
	free(split);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	end;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	end = ft_strlen(s + start);
	if (end < len)
		len = end;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[start + i] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	checkwords(char const *s, char c)
{
	int	numwords;
	int	i;

	numwords = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			numwords++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (numwords);
}

char	**createwords(char const *s, char c, char **split)
{
	int	i;
	int	last;

	i = 0;
	while (*s)
	{
		last = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			s++;
			last++;
		}
		if (last > 0)
		{
			split[i] = ft_substr(s - last, 0, last);
			if (!split[i])
				return (ft_free(split, i));
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc((checkwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = (createwords(s, c, split));
	return (split);
}
