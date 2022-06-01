/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:39:50 by konagash          #+#    #+#             */
/*   Updated: 2022/02/19 18:11:13 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calc_screen_pos_x(int pos, t_mlx *mlx)
{
	return (((pos * (mlx->max_re - mlx->min_re)) / mlx->width) + mlx->min_re);
}

double	calc_screen_pos_y(int pos, t_mlx *mlx)
{
	return (((pos * (mlx->max_im - mlx->min_im)) / mlx->height) + mlx->min_im);
}
