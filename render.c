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
	shift_color(fractal, 0);
	if (fractal->set == 1)
		render_mandelbrot(fractal);
	else if (fractal->set == 2)
		render_julia(fractal);
	else if (fractal->set == 3)
		render_burningship(fractal);
	return (1);
}

static void	ft_huetorgb1(float *r, float *g, float *b, int hue)
{
	if (hue < 60)
	{
		*r = 1.0;
		*g = (float)hue / 60;
		*b = 0;
	}
	else if (hue < 120)
	{
		*r = 1 - ((float)hue - 60) / 60;
		*g = 1.0;
		*b = 0;
	}
	else if (hue < 180)
	{
		*r = 0;
		*g = 1.0;
		*b = ((float)hue - 120) / 60;
	}
}

static void	ft_huetorgb2(float *r, float *g, float *b, int hue)
{
	if (hue < 240)
	{
		*r = 0;
		*g = 1 - ((float)hue - 180) / 60;
		*b = 1.0;
	}
	else if (hue < 300)
	{
		*r = ((float)hue - 240) / 60;
		*g = 0;
		*b = 1.0;
	}
	else
	{
		*r = 1.0;
		*g = 0;
		*b = 1 - ((float)hue - 300) / 60;
	}
}

int	ft_getcolor(int i, t_data *fractal)
{
	float	r;
	float	g;
	float	b;

	if (i == fractal->iterations)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		if (fractal->color < 180)
			ft_huetorgb1(&r, &g, &b, fractal->color);
		else
			ft_huetorgb2(&r, &g, &b, fractal->color);
		r *= (float)i / fractal->iterations;
		g *= (float)i / fractal->iterations;
		b *= (float)i / fractal->iterations;
	}
	return ((unsigned char)(r * 255) << 16 | (unsigned char)(g * 255) << 8 \
			| (unsigned char)(b * 255));
}

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->mlx_addr + (y * img->ln_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
