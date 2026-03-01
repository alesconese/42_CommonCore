/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:29:16 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/02 19:30:16 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = init_stack(&stack_a, argv);
	if (!stack_a)
	{
		free_stack(&stack_a);
		exit (1);
	}
	if (!ft_lstsorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
