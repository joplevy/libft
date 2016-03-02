/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:11:45 by jplevy            #+#    #+#             */
/*   Updated: 2016/01/11 19:30:26 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*nstr;
	size_t	i;

	if ((nstr = (char *)malloc(sizeof(char) * ft_strlen(s))))
	{
		if (s && f)
		{
			i = 0;
			while (i < ft_strlen(s))
			{
				nstr[i] = f(s[i]);
				i++;
			}
			return (nstr);
		}
	}
	return (NULL);
}
