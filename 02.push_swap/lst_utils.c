/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:50:31 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/02 19:55:24 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (stack)
		{
			stack = stack->next;
			i++;
		}
	}
	return (i);
}

t_node	*ft_lstsmallest(t_node *stack)
{
	t_node	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->data < smallest->data)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_node	*ft_lstlast(t_node *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_lstsorted(t_node *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_lstaddnode(t_node **a, t_node *new_node, t_node *prev_node, int nbr)
{
	new_node->data = nbr;
	new_node->next = NULL;
	if (!*a)
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		prev_node->next = new_node;
		new_node->prev = prev_node;
	}
}
