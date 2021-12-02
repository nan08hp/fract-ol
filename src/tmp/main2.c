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
  mlx->width = 400;
  mlx->height = 400;
  mlx->mlx = mlx_init();
  mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "fract-ol");
  mlx->img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
  mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);

  //float size = 0.05; // 拡大時に利用。小さくすると拡大する
  //float size = 0.1; // 拡大時に利用。小さくすると拡大する
  //float size = 4; // 1辺の大きさ
  mlx->size = 4;
  //float size = 0.05;

  return (0);
}


int main(int argc, char **argv)
{
  //t_mlx   *mlx;

  //// 呼び出し先の関数でmallocしたい場合はダブルポインタ
  //mlx = malloc(sizeof(t_mlx));
  //if (mlx == NULL)
  //  return (1);
  //init(mlx);
  //draw(mlx);
  //mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);

  t_mlx mlx;
  init(&mlx);
  draw(&mlx);
  mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);

  //mlx_key_hook(mlx->win, hook_keydown, mlx);
  //mlx_hook(mlx->win, 6, 1L << 6, get_mouse, mlx); // マウスの位置を取得
  //mlx_hook(mlx.win, 6, 1L << 6, get_point, &mlx); // マウスの位置を取得
  //mlx_mouse_hook(mlx.win, get_point, &mlx); // マウスの位置を取得

  //mlx_hook(mlx->win, 4, 1L << 2, hook_mouse, mlx);
  //mlx_hook(mlx->win, 17, 1L << 17, exit_mlx, mlx);
  //mlx_loop(mlx->mlx);
  
  //mlx_hook(mlx.win, 4, 1L << 2, hook_mouse, &mlx); // マウスの位置を取得
  mlx_mouse_hook(mlx.win, hook_mouse, &mlx); // １つ上と同じ
  //mlx_hook(mlx.win, 2, 1L << 0, hook_keydown, &mlx); // 押されたボタンを検知
  mlx_key_hook(mlx.win, hook_keydown, &mlx); // １つ上と同じ
  mlx_hook(mlx.win, 17, 1L << 17, exit_mlx, &mlx); // ウィンドウを閉じた際の動作
  mlx_loop_hook(); // 再描画のイベントを設定
  mlx_loop(mlx.mlx);

  return (1);
}
