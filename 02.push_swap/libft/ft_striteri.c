/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:57:33 by ade-tole          #+#    #+#             */
/*   Updated: 2023/08/04 18:43:09 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (s && f && i < len)
	{
		(*f)(i, s);
		s++;
		i++;
	}
}
/*
void	iter(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

#include <stdio.h>
#include <string.h>

int main(void){
	char	*str;

	str = (char*)malloc(sizeof(*str) * 12);
	if (!str)
		return (0);
	else
	{
		strcpy(str, "LoReM iPsUm");
		ft_striteri(str, *iter);
		printf("%s\n", str);
	}
	return (0);
}*/
