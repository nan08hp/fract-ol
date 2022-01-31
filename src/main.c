#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

void my_mlx_pixecl_put(t_data *data, int x, int y, int color)
{
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

int create_trgb(int t, int r, int g, int b)
{
  return (t << 24 | r << 16 | g << 8 | b);
}

int		exit_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	exit(0);
}

int    init(t_mlx *mlx)
{
  mlx->width = 600;
  mlx->height = 600;
  mlx->mlx = mlx_init();
  mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "fract-ol");
  mlx->img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
  mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
  mlx->size = 4; // 描画範囲 (虚数部と実数部ともに同じ値なので、正方形になる)

  // 実数
  mlx->max_re = 2;
  mlx->min_re = -2;
  // 虚数
  mlx->max_im = 2;
  mlx->min_im = -2;

  mlx->iter = 500; // Good
  

  mlx->mouse_pos_x = -0.3;
  mlx->mouse_pos_y = -0.63;

  return (0);
}

int main_parse(t_mlx *mlx)
{
  draw(mlx);
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

int parse_fractal(char *f, t_mlx *mlx)
{
	if (!strncmp(f, "mandelbrot" , 10))
	{
		printf("mandelbrot\n");
		mlx->type = mandelbrot;
	}
	else if (!strncmp(f, "julia" , 5))
	{
		printf("julia\n");
		mlx->type = julia;
	}
	else if (!strncmp(f, "tricorn" , 7))
	{
		printf("tricorn\n");
		mlx->type = tricorn;
	}
	else
	{
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
  t_mlx mlx;

  if (argc != 2)
  {
	  printf("Useage: ./fract-ol [mandelbrot|julia|tricorn]\n");
	  return (0);
  }

  //printf("%s\n", argv[1]);
  parse_fractal(argv[1], &mlx);

  init(&mlx);
  mlx_hook(mlx.win, 6, 1L << 6, get_mouse, &mlx); // マウスの位置を取得 For Julia
  mlx_mouse_hook(mlx.win, hook_mouse, &mlx);
  mlx_hook(mlx.win, 17, 1L << 17, exit_mlx, &mlx); // ウィンドウを閉じた際の動作
  mlx_key_hook(mlx.win, close_win, &mlx);
  mlx_loop_hook(mlx.mlx, &main_parse, &mlx); // 描画のイベントを設定
  mlx_loop(mlx.mlx);

  return (1);
}
