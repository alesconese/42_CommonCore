/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:34:37 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/29 16:34:38 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_ismandelbrot(double c_re, double c_im, t_data *fractal)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = c_re;
	z_im = c_im;
	i = 0;
	while (i < fractal->iterations)
	{
		if ((z_re * z_re + z_im * z_im) > 4)
			return (i);
		tmp = 2 * z_re * z_im + c_im;
		z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = tmp;
		i++;
	}
	return (i);
}

void	render_mandelbrot(t_data *fractal)
{
	int		y;
	int		x;
	double	c_im;
	double	c_re;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		c_im = (2.0 - (double)y * (2.0 - (-2.0)) / HEIGHT) \
				* fractal->zoom - fractal->shift_y;
		while (++x < WIDTH)
		{
			c_re = (-2.0 + (double)x * (2.0 - (-2.0)) / WIDTH) \
					* fractal->zoom + fractal->shift_x;
			ft_put_pixel(&fractal->img, x, y, \
					ft_getcolor(ft_ismandelbrot(c_re, c_im, fractal), fractal));
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, \
			fractal->img.mlx_img, 0, 0);
}
