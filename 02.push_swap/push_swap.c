/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:06:05 by ade-tole          #+#    #+#             */
/*   Updated: 2023/11/30 19:10:45 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	set_index(t_node *stack)
{
	int	i;
	int	stack_half;

	stack_half = ft_lstsize(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= stack_half)
			stack->upper_half = TRUE;
		else
			stack->upper_half = FALSE;
		i++;
		stack = stack->next;
	}
}

static	void	set_target(t_node *a, t_node *b)
{
	t_node	*tmp;
	t_node	*target;
	int		target_value;

	while (b)
	{
		target_value = INT_MAX;
		tmp = a;
		while (tmp)
		{
			if (b->data < tmp->data && tmp->data < target_value)
			{
				target_value = tmp->data;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (target_value == INT_MAX)
			b->target = ft_lstsmallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

static	void	comp_price(t_node *b, int size_a, int size_b)
{
	int	r_price;
	int	rr_price;

	if (b->index > b->target->index)
		r_price = b->index;
	else
		r_price = b->target->index;
	if ((size_b - b->index) > (size_a - b->target->index))
		rr_price = size_b - b->index;
	else
		rr_price = size_a - b->target->index;
	if (r_price < rr_price)
		b->push_price = r_price;
	else
		b->push_price = rr_price;
}

static	void	set_price(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		if (b->upper_half && b->target->upper_half)
		{
			if (b->index > b->target->index)
				b->push_price = b->index;
			else
				b->push_price = b->target->index;
		}
		else if (!b->upper_half && !b->target->upper_half)
		{
			if ((size_b - b->index) > (size_a - b->target->index))
				b->push_price = size_b - b->index;
			else
				b->push_price = size_a - b->target->index;
		}
		else
			comp_price(b, size_a, size_b);
		b = b->next;
	}
}

void	push_swap(t_node **a, t_node **b)
{
	int		size_a;
	t_node	*smallest;

	size_a = ft_lstsize(*a);
	while (size_a-- > 3)
		pb(a, b);
	sort_3(a);
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target(*a, *b);
		set_price(*a, *b);
		move_cheapest(a, b);
	}
	set_index(*a);
	smallest = ft_lstsmallest(*a);
	if (smallest->upper_half)
		while (smallest != *a)
			ra(a);
	else
		while (smallest != *a)
			rra(a);
}
