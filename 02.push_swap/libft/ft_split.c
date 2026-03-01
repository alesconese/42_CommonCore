/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:07:16 by ade-tole          #+#    #+#             */
/*   Updated: 2023/08/11 22:36:15 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_array_malloc(char const *s, char c, size_t i)
{
	char	**split;
	size_t	n;
	int		flag;

	n = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			n++;
		}
		i++;
	}
	split = (char **)malloc(sizeof(s) * (n + 1));
	if (!split)
		return (NULL);
	return (split);
}

static	void	*ft_free_split(char **split, size_t n)
{
	while (n)
	{
		n--;
		free((void *)split[n]);
	}
	free (split);
	return (NULL);
}

static	void	*ft_fill_last(char **split, char const *s, size_t start, 
		size_t n)
{
	size_t	i;

	i = start;
	if (s[start])
	{
		while (s[i])
			i++;
		split[n] = ft_substr(s, start, i - start);
		if (!split[n])
			return (ft_free_split(split, n));
		n++;
	}
	split[n] = 0;
	return (split);
}

static	void	*ft_fill_split(char **split, char const *s, char c, size_t i)
{
	size_t	n;
	size_t	start;

	n = 0;
	start = i;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
		{
			split[n] = ft_substr(s, start, i - start);
			if (!split[n])
				return (ft_free_split(split, n));
			n++;
			while (s[i] == c)
				i++;
			start = i;
			i--;
		}
		i++;
	}
	if (!(ft_fill_last(split, s, start, n)))
		return (NULL);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		break ;
	}
	split = ft_array_malloc(s, c, i);
	if (!split)
		return (NULL);
	ft_fill_split(split, s, c, i);
	if (!split)
		return (NULL);
	return (split);
}
/*
#include <stdio.h>

int	main(void){
	char	**split = ft_split("hello", ' ');
	int		i = 0;

	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}

	return (0);
}*/
