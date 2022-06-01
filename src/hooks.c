/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 07:06:22 by konagash          #+#    #+#             */
/*   Updated: 2022/02/23 20:09:12 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	select_color(t_mlx *mlx)
{
	if (mlx->color == 5)
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
