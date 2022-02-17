/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:20:29 by konagash          #+#    #+#             */
/*   Updated: 2022/02/17 04:17:15 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

void	my_mlx_pixecl_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	exit(0);
}

void	init(t_mlx *mlx)
{
	mlx->width = 600;
	mlx->height = 600;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "fract-ol");
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
			&mlx->img.line_length, &mlx->img.endian);
	mlx->max_re = 2;
	mlx->min_re = -2;
	mlx->max_im = 2;
	mlx->min_im = -2;
	mlx->iter = 100;
	mlx->mouse_pos_x = -0.3;
	mlx->mouse_pos_y = -0.63;
	mlx->color = Cos;
}

int	main_loop(t_mlx *mlx)
{
	draw(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2 || !parse_fractal(argv[1], &mlx))
	{
		printf("Usage: ./fract-ol [mandelbrot|julia|tricorn]\n");
		return (1);
	}
	init(&mlx);
	mlx_hook(mlx.win, 6, 1L << 6, get_mouse, &mlx);
	mlx_mouse_hook(mlx.win, hook_mouse, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_mlx, &mlx);
	mlx_key_hook(mlx.win, hook_key, &mlx);
	mlx_loop_hook(mlx.mlx, &main_loop, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
