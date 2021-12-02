#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

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

  mlx->iter = 100;

  return (0);
}

int main_parse(t_mlx *mlx)
{
  draw(mlx);
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

int main(int argc, char **argv)
{
  t_mlx mlx;
  init(&mlx);
  //draw(&mlx);
  //mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);

  //mlx_hook(mlx.win, 4, 1L << 2, hook_mouse, &mlx); // マウスの位置を取得
  mlx_mouse_hook(mlx.win, hook_mouse, &mlx); // １つ上と同じ
  //mlx_hook(mlx.win, 2, 1L << 0, hook_keydown, &mlx); // 押されたボタンを検知
  //mlx_key_hook(mlx.win, hook_keydown, &mlx); // １つ上と同じ
  mlx_hook(mlx.win, 17, 1L << 17, exit_mlx, &mlx); // ウィンドウを閉じた際の動作
  mlx_loop_hook(mlx.mlx, &main_parse, &mlx); // 描画のイベントを設定
  mlx_loop(mlx.mlx);

  return (1);
}
