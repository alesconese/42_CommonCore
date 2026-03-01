/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:20 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/14 12:19:24 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

void	char_bin(char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_putstr_fd("Error. Format: ./client <server PID> \
<string to send>\n", 1), 1);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		char_bin(*argv[2], pid);
		argv[2]++;
	}
	return (0);
}
