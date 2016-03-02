/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:22:51 by jplevy            #+#    #+#             */
/*   Updated: 2016/01/15 19:11:30 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_words(char const *s, char sep)
{
	size_t	ret;

	ret = 0;
	while (s && *s)
	{
		if (*s == sep)
			s++;
		if (*s != sep)
		{
			ret++;
			while (*s != sep)
				s++;
		}
	}
	return (ret);
}

static int		ft_word_size(char *s, char sep)
{
	int		i;
	int		size;
	int		inw;

	i = 0;
	inw = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != sep && inw == 0)
			inw = 1;
		if (s[i] != sep && inw == 1)
			size++;
		if (s[i] == sep && inw == 1)
			return (size);
		i++;
	}
	return (size);
}

static char		*ft_write_word(char *str, char **nstr, char *tab, char c)
{
	int		inw;
	int		i;

	inw = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*str != c && inw == 0)
			inw = 1;
		if (*str != c && inw == 1)
		{
			tab[i] = *str;
			i++;
		}
		if (*str == c && inw == 1)
		{
			tab[i] = '\0';
			*nstr = str;
			return (tab);
		}
		str++;
	}
	tab[i] = '\0';
	*nstr = str;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	size_t	nw;
	size_t	cw;

	nw = ft_count_words(s, c);
	str = (char*)s;
	tab = (char**)malloc(sizeof(char*) * (nw + 1));
	cw = 0;
	while (cw < nw)
	{
		tab[cw] = (char*)malloc(sizeof(char) * (ft_word_size(str, c) + 1));
		ft_write_word(str, &str, tab[cw], c);
		cw++;
	}
	tab[cw] = NULL;
	return (tab);
}
