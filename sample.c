#include "./includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

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

  //mlx->iter = 30;
  //mlx->iter = 100; // Too Few
  mlx->iter = 500; // Good
  //mlx->iter = 1000; // Good

  return (0);
}

int main_parse(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
  return (0);
}

int main(int argc, char **argv)
{
  t_mlx mlx;
  init(&mlx);

  mlx_hook(mlx.win, 17, 1L << 17, exit_mlx, &mlx); // ウィンドウを閉じた際の動作
  //mlx_hook(mlx.win, 2, 1L << 0, exit_mlx, &mlx);
  mlx_loop_hook(mlx.mlx, &main_parse, &mlx); // 描画のイベントを設定
  mlx_loop(mlx.mlx);

  return (1);
}
