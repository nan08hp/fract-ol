/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:25:42 by konagash          #+#    #+#             */
/*   Updated: 2022/02/17 04:17:39 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define KEY_R_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_L_ARROW 65363
# define KEY_DOWN_ARROW 65364 
# define KEY_Q 113
# define KEY_ESC 65307
# define KEY_TAB 65289
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef enum e_fractal_type
{
	Mandelbrot,
	Julia,
	Tricorn,
}	t_fractal;

typedef enum e_color_range
{
	Cos,
	CosSmooth1,
	CosSmooth2,
	Sin,
	SinSmooth1,
	SinSmooth2,
	Perrinperson,
	Metalic,
}	t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	t_data		img;
	double		mouse_pos_x;
	double		mouse_pos_y;
	double		max_re;
	double		min_re;
	double		max_im;
	double		min_im;
	long		iter;
	t_color		color;
	t_fractal	type;
}	t_mlx;

/* hook関連 */
int		hook_keydown(int key, void *mlx);
int		hook_key(int key, t_mlx *mlx);
int		get_mouse(int x, int y, t_mlx *mlx);
int		get_point(int x, int y, t_mlx mlx);
int		hook_mouse(int button, int x, int y, t_mlx *mlx);

/* fractolの描画・計算 */
double	calc_mandelbrot(double a, double b, t_mlx *mlx);
double	calc_julia(double x, double y, t_mlx *mlx);
double	calc_tricorn(double a, double b, t_mlx *mlx);
double	calc_screen_pos_x(int pos, t_mlx *mlx);
double	calc_screen_pos_y(int pos, t_mlx *mlx);
double	calc_color_range(double i, double x, double y, t_mlx *mlx);
int		parse_fractal(char *f, t_mlx *mlx);
double	select_fractal(double screen_x, double screen_y, t_mlx *mlx);
void	draw(t_mlx *mlx);

/* 描画・色の処理 */
void	my_mlx_pixecl_put(t_data *data, int x, int y, int color);
int		exit_mlx(t_mlx *mlx);
void	init(t_mlx *mlx);
int		main_loop(t_mlx *mlx);

#endif
