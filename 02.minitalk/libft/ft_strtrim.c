/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:12:06 by ade-tole          #+#    #+#             */
/*   Updated: 2023/07/27 21:23:49 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	first;
	size_t	last;
	size_t	i;

	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_isinset(s1[first], set))
		first++;
	while (last > first && ft_isinset(s1[last - 1], set))
		last--;
	str = (char *)malloc(sizeof(*s1) * (last - first + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (first < last)
	{
		str[i] = s1[first];
		i++;
		first++;
	}
	str[i] = '\0';
	return (str);
}
