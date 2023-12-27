/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:19:48 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/27 20:19:50 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isjulia(double z_re, double z_im, t_data *fractal)
{
	double	tmp;
	int		i;

	i = 1;
	while (i <= fractal->iterations)
	{
		if ((z_re * z_re + z_im * z_im) > 4)
			return (i);
		tmp = 2 * z_re * z_im + fractal->julia_im;
		z_re = (z_re * z_re) - (z_im * z_im) + fractal->julia_re;
		z_im = tmp;
		i++;
	}
	return (0);
}

void	render_julia(t_data *fractal)
{
	int		y;
	int		x;
	double	z_im;
	double	z_re;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		z_im = (2.0 - (double)y * (2.0 - (-2.0)) / HEIGHT) \
				* fractal->zoom - fractal->shift_y;
		while (++x < WIDTH)
		{
			z_re = (-2.0 + (double)x * (2.0 - (-2.0)) / WIDTH) \
					* fractal->zoom + fractal->shift_x;
			if (ft_isjulia(z_re, z_im, fractal) == 0)
				ft_put_pixel(&fractal->img, x, y, 0x000000);
			else
				ft_put_pixel(&fractal->img, x, y, \
						ft_getcolor(ft_isjulia(z_re, z_im, fractal), fractal));
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, \
			fractal->img.mlx_img, 0, 0);
}
