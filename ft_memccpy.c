/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:10:48 by jplevy            #+#    #+#             */
/*   Updated: 2016/01/11 19:31:51 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*temp1;
	char			*temp2;
	unsigned char	val;
	size_t			i;

	i = 0;
	val = (unsigned char)c;
	temp1 = (char *)src;
	temp2 = (char *)dst;
	while (i < n)
	{
		temp2[i] = temp1[i];
		if (temp1[i] == val)
			return (&(temp1[i + 1]));
		i++;
	}
	return (NULL);
}
