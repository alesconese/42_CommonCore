/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:33:48 by ade-tole          #+#    #+#             */
/*   Updated: 2023/12/29 16:33:52 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_argerror(void)
{
	ft_putstr_fd("Error. Format: ./fractol mandelbrot OR \
./fractol julia <c.real> <c.i> OR ./fractol burningship", 1);
	exit(1);
}

static void	ft_instructions(char *set)
{
	ft_putstr_fd("---FRACTOL---\n\n", 1);
	ft_putstr_fd("Generating -", 1);
	ft_putstr_fd(set, 1);
	ft_putstr_fd("- set\n\n---INSTRUCTIONS---\n", 1);
	ft_putstr_fd("- Press ESC to close the program\n", 1);
	ft_putstr_fd("- Zoom IN/OUT with Mouse Wheel\n", 1);
	ft_putstr_fd("- Move with Arrows or WASD\n", 1);
	ft_putstr_fd("- Use +/- to change resolution\n", 1);
	if (!ft_strncmp(set, "julia", 5))
	{
		ft_putstr_fd("- Press O/P to modify real component\n", 1);
		ft_putstr_fd("- Press K/L to modify imaginary component\n", 1);
	}
	ft_putstr_fd("- Press SPACE to turn color shifting ON/OFF\n", 1);
}

static double	ft_atodouble(char *str)
{
	int		sign;
	double	nbr_int;
	double	nbr_dec;
	double	dec_pos;

	sign = 1;
	nbr_int = 0;
	nbr_dec = 0;
	dec_pos = 1;
	if (!(*str == '-' | *str >= '0' && *str <= '9'))
		ft_argerror();
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		nbr_int = (nbr_int * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		dec_pos /= 10;
		nbr_dec = nbr_dec + ((*str++ - 48) * dec_pos);
	}
	return ((nbr_int + nbr_dec) * sign);
}

static void	init_fractal(t_data *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		exit(1);
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, \
			"fractol");
	if (!fractal->mlx_win)
		exit(1);
	fractal->img.mlx_img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.mlx_img)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
		exit(1);
	}
	fractal->img.mlx_addr = mlx_get_data_addr(fractal->img.mlx_img, \
			&fractal->img.bpp, &fractal->img.ln_len, &fractal->img.endian);
	fractal->zoom = 1.0;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->iterations = 32;
	fractal->color = 240;
}

int	main(int argc, char **argv)
{
	t_data	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot\0", 11))
		fractal.set = 1;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia\0", 6))
	{
		fractal.set = 2;
		fractal.julia_re = ft_atodouble(argv[2]);
		fractal.julia_im = ft_atodouble(argv[3]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "burningship\0", 12))
		fractal.set = 3;
	else
		ft_argerror();
	ft_instructions(argv[1]);
	init_fractal(&fractal);
	mlx_loop_hook(fractal.mlx_ptr, &render_fractal, &fractal);
	mlx_key_hook(fractal.mlx_win, &ft_keypressed, &fractal);
	mlx_mouse_hook(fractal.mlx_win, &ft_mousezoom, &fractal);
	mlx_hook(fractal.mlx_win, ON_DESTROY, 0, &ft_exit, &fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
