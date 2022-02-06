#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

/* hooks関連のものを記述 */

int hook_keydown(int key, void *mlx)
{
  printf("%d\n", key);
  if (key == 'a')
    printf("aが押されました\n");
}

int hook_key(int key, t_mlx *mlx)
{
  if (key == KEY_ESC)
  {
	  exit_mlx(mlx);
  }
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
}

int get_mouse(int x, int y, t_mlx *mlx)
{
  //printf("x: %d y: %d\n", x, y);
  mlx->mouse_pos_x = ((x * (mlx->max_re - mlx->min_re)) / mlx->width) + mlx->min_re;;
  mlx->mouse_pos_y = ((y * (mlx->max_im - mlx->min_im)) / mlx->height) + mlx->min_im;
  //printf("mouse_x: %f mouse_y: %f\n", mlx->mouse_pos_x, mlx->mouse_pos_y);
}

int get_point(int x, int y, t_mlx mlx)
{
  printf("x: %d y: %d\n", x, y);
}

int abs(int n) {
  if (n >= 0) {
    return (n);
  } else {
    return (-n);
  }
}

int hook_mouse(int button, int x, int y, t_mlx *mlx)
{
  if (button == MOUSE_UP) {
    double re = x * ((mlx->max_re - mlx->min_re) / mlx->height) + mlx->min_re;
    double im = y * ((mlx->max_im - mlx->min_im) / mlx->width) + mlx->min_im;
    mlx->max_re = re + ((mlx->max_re - re) / 1.1);
    mlx->min_re = re + ((mlx->min_re - re) / 1.1);
    mlx->max_im = im + ((mlx->max_im - im) / 1.1);
    mlx->min_im = im + ((mlx->min_im - im) / 1.1);
    mlx->iter += 100;
    //mlx->iter += mlx->iter;
    //printf("re: %f max: %f min: %f\n", re, mlx->max_re, mlx->min_re);
  } else if (button == MOUSE_DOWN) {
    double re = x * ((mlx->max_re - mlx->min_re) / mlx->height) + mlx->min_re;
    double im = y * ((mlx->max_im - mlx->min_im) / mlx->width) + mlx->min_im;
    mlx->max_re = re + ((mlx->max_re - re) * 1.1);
    mlx->min_re = re + ((mlx->min_re - re) * 1.1);
    mlx->max_im = im + ((mlx->max_im - im) * 1.1);
    mlx->min_im = im + ((mlx->min_im - im) * 1.1);
    if (mlx->iter > 100)
    	mlx->iter -= 100;
    //mlx->iter -= mlx->iter;

    //printf("ZOOM OUT\n");
  }
}
