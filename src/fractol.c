/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:40:35 by konagash          #+#    #+#             */
/*   Updated: 2022/02/20 05:51:24 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	parse_fractal(char *f, t_mlx *mlx)
{
	if (!ft_strncmp(f, "mandelbrot", 11))
		mlx->type = Mandelbrot;
	else if (!ft_strncmp(f, "julia", 6))
		mlx->type = Julia;
	else if (!ft_strncmp(f, "tricorn", 8))
		mlx->type = Tricorn;
	else
		return (0);
	return (1);
}

double	select_calc_fractal(double x, double y, t_mlx *mlx)
{
	if (mlx->type == Mandelbrot)
		return (calc_mandelbrot(x, y, mlx));
	else if (mlx->type == Julia)
		return (calc_julia(x, y, mlx));
	else if (mlx->type == Tricorn)
		return (calc_tricorn(x, y, mlx));
	else
		return (-1);
}

double	calc_mandelbrot(double a, double b, t_mlx *mlx)
{
	double	i;
	double	x;
	double	y;
	double	tmp;

	x = 0;
	y = 0;
	i = 0;
	while (i < mlx->iter)
	{
		tmp = x * x - y * y + a;
		y = 2.0 * x * y + b;
		x = tmp;
		if (x * x + y * y > 4.0)
			return (calc_color_range(i, x * x, y * y, mlx));
		i++;
	}
	return (0);
}

double	calc_julia(double x, double y, t_mlx *mlx)
{
	double	i;
	double	tmp;

	i = 0;
	while (i < mlx->iter)
	{
		tmp = x * x - y * y - mlx->mouse_pos_x;
		y = 2 * x * y - mlx->mouse_pos_y;
		x = tmp;
		if (x * x + y * y > 4.0)
			return (calc_color_range(i, x * x, y * y, mlx));
		i++;
	}
	return (0);
}

double	calc_tricorn(double a, double b, t_mlx *mlx)
{
	double	i;
	double	x;
	double	y;
	double	tmp;

	x = 0;
	y = 0;
	i = 0;
	while (i < mlx->iter)
	{
		tmp = x * x - y * y + a;
		y = 2.0 * x * (-y) + b;
		x = tmp;
		if (x * x + y * y > 4.0)
			return (calc_color_range(i, x * x, y * y, mlx));
		i++;
	}
	return (0);
}
