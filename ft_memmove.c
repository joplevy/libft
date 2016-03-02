/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 18:39:13 by jplevy            #+#    #+#             */
/*   Updated: 2016/01/04 18:50:57 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	if (dst && src)
	{
		dst1 = (unsigned char *)dst;
		src1 = (unsigned char *)src;
		if (src > dst)
		{
			dst1 = dst1 + len;
			src1 = src1 + len;
			while (len--)
				*--dst1 = *--src1;
		}
		else
			ft_memcpy(dst1, src1, len);
	}
	return (dst);
}
