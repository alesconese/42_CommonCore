/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:03:34 by ade-tole          #+#    #+#             */
/*   Updated: 2023/08/02 20:17:48 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digits(int n)
{
	if (n / 10 == 0)
		return (1);
	else
		return (1 + get_digits(n / 10));
}

char	*fill(int n, int neg)
{
	size_t	digits;
	char	*str;

	digits = get_digits(n) + neg;
	str = (char *)malloc (digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[digits - 1] = '0' + (n % 10);
		n = n / 10;
		digits--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		min;

	neg = 0;
	min = 0;
	if (n == -2147483648)
	{
		min = 1;
		n++;
	}
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str = fill(n, neg);
	if (!str)
		return (NULL);
	if (neg)
		str[0] = '-';
	if (min)
		str[10]++;
	return (str);
}
