/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:06:44 by konagash          #+#    #+#             */
/*   Updated: 2022/02/23 20:11:07 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	get_mouse(int x, int y, t_mlx *mlx)
{
	mlx->mouse_pos_x = calc_screen_pos_x(x, mlx);
	mlx->mouse_pos_y = calc_screen_pos_y(y, mlx);
	return (0);
}

static void	zoom_in(double re, double im, t_mlx *mlx)
{
	mlx->max_re = re + ((mlx->max_re - re) / 1.1);
	mlx->min_re = re + ((mlx->min_re - re) / 1.1);
	mlx->max_im = im + ((mlx->max_im - im) / 1.1);
	mlx->min_im = im + ((mlx->min_im - im) / 1.1);
	mlx->iter += sqrt(mlx->iter);
}

static void	zoom_out(double re, double im, t_mlx *mlx)
{
	mlx->max_re = re + ((mlx->max_re - re) * 1.1);
	mlx->min_re = re + ((mlx->min_re - re) * 1.1);
	mlx->max_im = im + ((mlx->max_im - im) * 1.1);
	mlx->min_im = im + ((mlx->min_im - im) * 1.1);
	if (mlx->iter > 100)
		mlx->iter -= sqrt(mlx->iter);
}

int	hook_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	re;
	double	im;

	re = calc_screen_pos_x(x, mlx);
	im = calc_screen_pos_y(y, mlx);
	if (button == MOUSE_UP)
		zoom_in(re, im, mlx);
	else if (button == MOUSE_DOWN)
		zoom_out(re, im, mlx);
	return (0);
}
