/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:23:45 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/27 20:23:47 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>//RM!!!!!

int	ft_mousezoom(int keysym, int x, int y, t_data *fractal)
{
	if (keysym == ON_MOUSEUP)
	{
		fractal->zoom *= 0.9;
		if (fractal->zoom > 0.005)
			fractal->iterations *= 1.05;
	}
	else if (keysym == ON_MOUSEDOWN)
	{
		fractal->zoom *= 1.1;
		if (fractal->zoom < 0.005)//FIX!!!!!!
			fractal->iterations *= 0.95;
	}
	fractal->shift_x += ((double)x - WIDTH / 2) / (WIDTH / 2) * fractal->zoom;
	fractal->shift_y += ((double)y - HEIGHT / 2) / (HEIGHT / 2) * fractal->zoom;
	printf("zoom:%lf|iterations:%d\n", fractal->zoom, fractal->iterations);//RM!!!!!!
	return (0);
}

int	ft_keypressed(int keysym, t_data *fractal)
{
	printf("%d\n", keysym);//RM!!!!!
	if (keysym == K_ESC)
		ft_exit(fractal);
	if (keysym == K_W || keysym == K_UARR)
		fractal->shift_y -= 0.1 * fractal->zoom;
	if (keysym == K_S || keysym == K_DARR)
		fractal->shift_y += 0.1 * fractal->zoom;
	if (keysym == K_D || keysym == K_RARR)
		fractal->shift_x += 0.1 * fractal->zoom;
	if (keysym == K_A || keysym == K_LARR)
		fractal->shift_x -= 0.1 * fractal->zoom;
	if (fractal->set == 2 && keysym == K_O)
		fractal->julia_re -= 0.01;
	if (fractal->set == 2 && keysym == K_P)
		fractal->julia_re += 0.01;
	if (fractal->set == 2 && keysym == K_K)
		fractal->julia_im -= 0.01;
	if (fractal->set == 2 && keysym == K_L)
		fractal->julia_im += 0.01;
	return (0);
}
