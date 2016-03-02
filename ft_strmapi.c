/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:41:59 by jplevy            #+#    #+#             */
/*   Updated: 2016/01/11 19:43:32 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				nstr[i] = f((unsigned int)i, s[i]);
				i++;
			}
			return (nstr);
		}
	}
	return (NULL);
}
