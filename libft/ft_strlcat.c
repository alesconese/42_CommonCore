/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:55:43 by ade-tole          #+#    #+#             */
/*   Updated: 2023/06/26 14:39:08 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;
	size_t	j;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	j = lendst;
	i = 0;
	while (src[i] != '\0' && j < dstsize - 1 && dstsize > 0)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	if (dstsize < lendst)
		lendst = dstsize;
	return (lendst + lensrc);
}
