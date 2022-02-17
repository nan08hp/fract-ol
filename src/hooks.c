/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 07:06:22 by konagash          #+#    #+#             */
/*   Updated: 2022/02/16 10:44:26 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	select_color(t_mlx *mlx)
{
	if (mlx->color == 7)
	{
		mlx->color = 0;
		return ;
	}
	mlx->color += 1;
}

int	hook_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit_mlx(mlx);
	else if (key == KEY_UP_ARROW)
	{
		mlx->min_im -= (mlx->max_re - mlx->min_re) * 0.01;
		mlx->max_im -= (mlx->max_re - mlx->min_re) * 0.01;
	}
	else if (key == KEY_DOWN_ARROW)
	{
		mlx->min_im += (mlx->max_re - mlx->min_re) * 0.01;
		mlx->max_im += (mlx->max_re - mlx->min_re) * 0.01;
	}
	else if (key == KEY_R_ARROW)
	{
		mlx->min_re += (mlx->max_re - mlx->min_re) * 0.01;
		mlx->max_re += (mlx->max_re - mlx->min_re) * 0.01;
	}
	else if (key == KEY_L_ARROW)
	{
		mlx->min_re -= (mlx->max_re - mlx->min_re) * 0.01;
		mlx->max_re -= (mlx->max_re - mlx->min_re) * 0.01;
	}
	else if (key == KEY_TAB)
		select_color(mlx);
	return (0);
}

int	get_mouse(int x, int y, t_mlx *mlx)
{
	mlx->mouse_pos_x = calc_screen_pos_x(x, mlx);
	mlx->mouse_pos_y = calc_screen_pos_y(y, mlx);
	return (0);
}

int	hook_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	re;
	double	im;

	if (button == MOUSE_UP)
	{
		re = calc_screen_pos_x(x, mlx);
		im = calc_screen_pos_y(y, mlx);
		mlx->max_re = re + ((mlx->max_re - re) / 1.1);
		mlx->min_re = re + ((mlx->min_re - re) / 1.1);
		mlx->max_im = im + ((mlx->max_im - im) / 1.1);
		mlx->min_im = im + ((mlx->min_im - im) / 1.1);
		mlx->iter += sqrt(mlx->iter);
	}
	else if (button == MOUSE_DOWN)
	{
		re = calc_screen_pos_x(x, mlx);
		im = calc_screen_pos_y(y, mlx);
		mlx->max_re = re + ((mlx->max_re - re) * 1.1);
		mlx->min_re = re + ((mlx->min_re - re) * 1.1);
		mlx->max_im = im + ((mlx->max_im - im) * 1.1);
		mlx->min_im = im + ((mlx->min_im - im) * 1.1);
		if (mlx->iter > 100)
			mlx->iter -= sqrt(mlx->iter);
	}
	return (0);
}
