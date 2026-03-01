/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:41:58 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/02 20:05:15 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_error(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	arg_error(t_node **a, char *str)
{
	if (!*str)
		free_error(a);
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!*str)
			free_error(a);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			free_error(a);
		str++;
	}
}

void	repeat_error(t_node **a, int nbr)
{
	t_node	*tmp;

	if (!a)
		return ;
	tmp = *a;
	while (tmp)
	{
		if (nbr == tmp->data)
			free_error(a);
		tmp = tmp->next;
	}
}
