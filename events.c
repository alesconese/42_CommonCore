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
		if (fractal->zoom > 0.005 && fractal->iterations > 32)
			fractal->iterations *= 0.95;
	}
	fractal->shift_x += ((double)x - WIDTH / 2) / (WIDTH / 2) * fractal->zoom;
	if (fractal->set != 3)
		fractal->shift_y += ((double)y - HEIGHT / 2) / (HEIGHT / 2) \
				* fractal->zoom;
	else
		fractal->shift_y -= ((double)y - HEIGHT / 2) / (HEIGHT / 2) \
				* fractal->zoom;
	return (0);
}

void	shift_color(t_data *fractal, int sw)
{
	static int	shift = -1;

	if (sw)
		shift = -shift;
	if (shift > 0)
		fractal->color++;
	if (fractal->color > 360)
		fractal->color = 0;
}

int	ft_keypressed(int keysym, t_data *fractal)
{
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
	if (keysym == K_PLUS)
		fractal->iterations *= 1.05;
	if (keysym == K_MINUS)
		fractal->iterations *= 0.95;
	if (keysym == K_SPACE)
		shift_color(fractal, 1);
	return (0);
}
