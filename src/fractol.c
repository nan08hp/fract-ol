#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

int cr(int i)
{
    int cr = (i % 256) * (255 - (i % 256)) / 65;
}

int calc_Tricorn(double a, double b, t_mlx *mlx)
{
  double c;
  double x = 0;
  double y = 0;

  c = 0;
  while (c < mlx->iter)
  {
    double tmp = x * x - (-y) * (-y) + a;
    y = 2 * x * (-y) + b;
    x = tmp;

    if (x * x + y * y > 4.0)
    {
      return ((1 - pow(1 - (c / mlx->iter))) * 255);
    }
    c++;
  }
  return (0);
}

/* fractolの計算処理などを記述 */
void      draw(t_mlx *mlx)
{
  int i;
  int j;

  i = 0;
  while (i < mlx->width)
  {
    double x = ((i * (mlx->max_re - mlx->min_re)) / mlx->width) + mlx->min_re;
    j = 0;
    while (j < mlx->height)
    {
      double y = ((j * (mlx->max_im - mlx->min_im)) / mlx->height) + mlx->min_im;

      /**
       * mandelbrot
       */
      double res = calc_Mandelbrot(x, y, mlx);

      /**
       * tricorn
       */
      //double res = calc_Tricorn(x, y, mlx);

      /**
       * julia
       */
      //double res = calc_Julia(x, y, mlx);

      my_mlx_pixecl_put(&mlx->img, i, j, res);


      //if (res >= 20)
      //  my_mlx_pixecl_put(&mlx->img, i, j, res * 5);
      //else if (res >= 10)
      //  my_mlx_pixecl_put(&mlx->img, i, j, (res * 10));
      //else if (res >= 0)
      //  my_mlx_pixecl_put(&mlx->img, i, j, (res * 20));
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFFFFF);

      j++;
    }
    i++;
  }
}

/* julia */
int calc_Julia(double x, double y, t_mlx *mlx)
{
  t_complex z;
  t_complex c; // ガウス平面上の点(a,b)をcと置く。
  int i;

  /**
   * 参考リンク
   * mandelbrotとjuliaの条件比較の表が非常に参考になる。
   * http://mt-soft.sakura.ne.jp/kyozai/excel_vba/320_vba_high/11_julia/main.html
   */

  z.a = x;
  z.b = y;

  /* cは外部から決める必要性がある。*/
  c.a = -0.3;
  c.b = -0.63;
  i = 0;
  while (i < mlx->iter)
  {
    z = complex_add(complex_multi(z, z), c);
    //a = complex_add(complex_multi(complex_multi(complex_multi(a, a), a), a), z);
    if (complex_abs(z) >= 2) // 収束
      return (i);
    i++;
  }
  return (0);
}

/* Mandelbrot */
int calc_Mandelbrot(double a, double b, t_mlx *mlx)
{
  double i;
  double x = 0;
  double y = 0;

  i = 0;
  while (i < mlx->iter)
  {
    double tmp = x * x - y * y + a;
    y = 2.0 * x * y + b;
    x = tmp;
    //printf("%d x: %f y: %f a: %f b: %f\n", (int)i, x, y, a, b);

    if (x * x + y * y > 4.0)
    {
      //printf("iter: %f\n", i);
      //return ((1 - (1 - (i / mlx->iter))) * 255);
      return ((1 - pow((1 - (i / mlx->iter)), 9)) * 255);

      //return ((i / mlx->iter) * 16777215);
      //return (cr(i * 9));
      //return (i);
      //return ((int)((i / mlx->iter) * 255) << 16 | (int)(((i / mlx->iter) * 255) * 0.2) << 8 | (int)(((i / mlx->iter) * 255) * 0.7)); // rgb
      //return (1 - ((i / 100) * 255));
      //return ((int)(1 - ((i / 100) * 255)) << 8);
    }

    // Coloring Func
    //if (x * x + y * y > 16.0) 
    //{
    //    //double log_zn = logl(x * x + y * y) / 2.0;
    //    //double nu = logl(log_zn / logl(2.0)) / logl(2.0);
    //    //return (i - nu);
    //    //return ((int)(i - nu) << 16 | (int)(i - nu + 100) << 8 | (int)(i - nu + 40)); // rgb
    //    
    //    //return i;
    //    //return ((int)i << 16 | (int)i  << 8 | (int)i); // rgb
    //}

    i++;
  }

  return (0);
}
