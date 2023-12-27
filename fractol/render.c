/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:19:21 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/27 20:19:23 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_fractal(t_data *fractal)
{
	if (fractal->set == 1)
		render_mandelbrot(fractal);
	else if (fractal->set == 2)
		render_julia(fractal);
	return (1);
}

int	ft_getcolor(int i, t_data *fractal)//COLOR SHIFT
{
	int	trgb;

	trgb = i * 100 / 42;
	trgb = trgb * 255;
	trgb = trgb / 100 * fractal->zoom;
	return (trgb << 16);
}

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->mlx_addr + (y * img->ln_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
