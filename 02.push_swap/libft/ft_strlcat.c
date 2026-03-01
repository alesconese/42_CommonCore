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
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char src[] = "hello world";
	char dst[10] = "4242";
	char dst1[10] = "4242";

	printf("%lu\n", strlcat(dst, src, 0));
	printf("%lu\n", ft_strlcat(dst1, src, 0));
	printf("%s\n", dst);
	printf("%s\n", dst1);

	return 0;
}*/
