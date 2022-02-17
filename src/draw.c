/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:48:07 by konagash          #+#    #+#             */
/*   Updated: 2022/02/16 10:42:09 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h" 

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

double	calc_color_range(double i, double x, double y, t_mlx *mlx)
{
	double	nu;
	double	s;

	nu = i - log(log((x * x) + (y * y))) + 4.0;
	s = sqrt(i);
	if (mlx->color == Cos)
		return (color_range_cos(i, 0, 0.6, 1));
	else if (mlx->color == CosSmooth1)
		return (color_range_cos(nu, 0, 0.6, 1));
	else if (mlx->color == CosSmooth2)
		return (color_range_cos(s, 0, 0.6, 1));
	else if (mlx->color == Sin)
		return (color_range_sin(i, 0, 0.6, 1));
	else if (mlx->color == SinSmooth1)
		return (color_range_sin(nu, 0, 0.6, 1));
	else if (mlx->color == SinSmooth2)
		return (color_range_sin(s, 0, 0.6, 1));
	else if (mlx->color == Perrinperson)
		return ((int)(x * x * 64) << 16 | (int)(y * y * 64) << 8 | 0);
	else if (mlx->color == Metalic)
		return ((int)(120 + 20 * y) << 16 | (int)(120 + 20 * y) << 8 \
				| (int)(120 + 20 * y));
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
			res = select_fractal(x, y, mlx);
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
