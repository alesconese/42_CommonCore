/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:42:02 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/19 13:42:05 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*mlx_img;
	void	*mlx_addr;
	int		bpp;
	int		ln_len;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
	int		set;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_re;
	double	julia_im;
	int		iterations;
}				t_data;

enum
{
	ON_DESTROY		=	17,
	ON_MOUSEUP		=	5,
	ON_MOUSEDOWN	=	4,
	K_ESC			=	53,
	K_W				=	13,
	K_A				=	0,
	K_S				=	1,
	K_D				=	2,
	K_LARR			=	123,
	K_RARR			=	124,
	K_DARR			=	125,
	K_UARR			=	126,
	K_O				=	31,
	K_P				=	35,
	K_K				=	40,
	K_L				=	37
};

int		render_fractal(t_data *fractal);

void	render_mandelbrot(t_data *fractal);

void	render_julia(t_data *fractal);

void	ft_put_pixel(t_img *img, int x, int y, int color);

int		ft_getcolor(int i, t_data *fractal);

int		ft_mousezoom(int keysym, int x, int y, t_data *fractal);

int		ft_keypressed(int keysym, t_data *fractal);

int		ft_exit(t_data *fractal);

#endif