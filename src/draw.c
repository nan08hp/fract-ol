/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:48:07 by konagash          #+#    #+#             */
/*   Updated: 2022/02/20 05:43:56 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h" 
#include <math.h>

static double	color_range_cos(double i, double r, double g, double b)
{
	return ((int)((0.5 + 0.5 * cos(3.0 + 0.15 * i + r)) * 255) << 16 \
			| (int)((0.5 + 0.5 * cos(3.0 + 0.15 * i + g)) * 255) << 8 \
			| (int)((0.5 + 0.5 * cos(3.0 + 0.15 * i + b)) * 255));
}

static double	color_range_sin(double i, double r, double g, double b)
{
	return ((int)((0.5 + 0.5 * sin(3.0 + 0.15 * i + r)) * 255) << 16 \
			| (int)((0.5 + 0.5 * sin(3.0 + 0.15 * i + g)) * 255) << 8 \
			| (int)((0.5 + 0.5 * sin(3.0 + 0.15 * i + b)) * 255));
}

static double	calc_smooth_param(double i, double x2, double y2, t_mlx *mlx)
{
	if (mlx->color == CosSmooth1 || mlx->color == SinSmooth1)
		return (i - log(log((x2) + (y2))) + 4.0);
	else if (mlx->color == CosSmooth2 || mlx->color == SinSmooth2)
		return (sqrt(i));
	else
		return (i);
}

double	calc_color_range(double i, double x2, double y2, t_mlx *mlx)
{
	double	s;

	s = calc_smooth_param(i, x2, y2, mlx);
	if (mlx->color == Cos || mlx->color == CosSmooth1 || \
		mlx->color == CosSmooth2)
		return (color_range_cos(s, 0, 0.6, 1));
	else if (mlx->color == Sin || mlx->color == SinSmooth1 || \
		mlx->color == SinSmooth2)
		return (color_range_sin(s, 0, 0.6, 1));
	return (-1);
}

void	draw(t_mlx *mlx)
{
	double	x;
	double	y;
	double	res;
	int		i;
	int		j;

	i = 0;
	while (i < mlx->width)
	{
		x = calc_screen_pos_x(i, mlx);
		j = 0;
		while (j < mlx->height)
		{
			y = calc_screen_pos_y(j, mlx);
			res = select_calc_fractal(x, y, mlx);
			if (res == -1)
			{
				ft_putstr_fd("Error: Unknown fractal or color range", 2);
				exit(1);
			}
			my_mlx_pixecl_put(&mlx->img, i, j, res);
			j++;
		}
		i++;
	}
}
