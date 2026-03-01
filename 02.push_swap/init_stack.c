/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:45:25 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/02 20:05:12 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	return (sign * nbr);
}

t_node	*init_stack(t_node **head, char **argv)
{
	long	nbr;
	t_node	*new_node;
	t_node	*prev_node;
	int		i;

	i = 0;
	while (argv[++i])
	{
		arg_error(head, argv[i]);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(head);
		repeat_error(head, (int)nbr);
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return (0);
		ft_lstaddnode(head, new_node, prev_node, (int)nbr);
		prev_node = new_node;
	}
	return (*head);
}
