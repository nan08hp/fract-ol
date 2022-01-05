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

int get_mouse(int x, int y, void *mlx)
{
  //printf("x: %d y: %d\n", x, y);
}

int get_point(int x, int y, t_mlx mlx)
{
  //printf("x: %d y: %d\n", x, y);
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
  static int count;
  //printf("button: %d\n", button);
  if (button == MOUSE_UP) {
    double re = x * ((mlx->max_re - mlx->min_re) / mlx->height) + mlx->min_re;
    double im = y * ((mlx->max_im - mlx->min_im) / mlx->width) + mlx->min_im;
    mlx->max_re = re + ((mlx->max_re - re) / 1.1);
    mlx->min_re = re + ((mlx->min_re - re) / 1.1);
    mlx->max_im = im + ((mlx->max_im - im) / 1.1);
    mlx->min_im = im + ((mlx->min_im - im) / 1.1);
    mlx->iter += 10;
    //printf("re: %f max: %f min: %f\n", re, mlx->max_re, mlx->min_re);
    count++;
    //printf("%dth\n", count);

    //printf("ZOOM IN\n");
  } else if (button == MOUSE_DOWN) {
    double re = x * ((mlx->max_re - mlx->min_re) / mlx->height) + mlx->min_re;
    double im = y * ((mlx->max_im - mlx->min_im) / mlx->width) + mlx->min_im;
    mlx->max_re = re + ((mlx->max_re - re) * 1.1);
    mlx->min_re = re + ((mlx->min_re - re) * 1.1);
    mlx->max_im = im + ((mlx->max_im - im) * 1.1);
    mlx->min_im = im + ((mlx->min_im - im) * 1.1);
    mlx->iter -= 10;

    //printf("ZOOM OUT\n");
  }
}
