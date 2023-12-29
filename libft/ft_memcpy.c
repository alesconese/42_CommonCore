/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:02:36 by ade-tole          #+#    #+#             */
/*   Updated: 2023/08/10 20:56:50 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstc;
	char	*srcc;

	if (!dst && !src)
		return (dst);
	dstc = (char *)dst;
	srcc = (char *)src;
	while (n > 0)
	{
		*dstc = *srcc;
		dstc++;
		srcc++;
		n--;
	}
	return (dst);
}
