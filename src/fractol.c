#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

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
       * julia
       */
      //double res = calc_Julia(x, y, mlx);

      //fractal_coloring();
      if (res == -1)
	      my_mlx_pixecl_put(&mlx->img, i, j, 0x00000000);
      else
	      my_mlx_pixecl_put(&mlx->img, i, j, 0x0000FF00 * res);

      //if (res >= 20)
      //  my_mlx_pixecl_put(&mlx->img, i, j, res * 20);
      //else if (res >= 10)
      //  my_mlx_pixecl_put(&mlx->img, i, j, (res * 20));
      //else if (res >= 0)
      //  my_mlx_pixecl_put(&mlx->img, i, j, (res * 20));
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00000000);

      // Best One?
      //if (res >= 20)
      //  my_mlx_pixecl_put(&mlx->img, i, j, res * 10);
      //else if (res >= 10)
      //  my_mlx_pixecl_put(&mlx->img, i, j, (res * 20));
      //else if (res >= 0)
      //  my_mlx_pixecl_put(&mlx->img, i, j, (res * 20));
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFFFFF);

      //if (res >= 90)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFA3A3);
      //else if (res >= 80)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFA3D1);
      //else if (res >= 70)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFA3FF);
      //else if (res >= 60)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3A3FF);
      //else if (res >= 50)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3FFFF);
      //else if (res >= 40)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3FFD1);
      //else if (res >= 30)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3FFA3);
      //else if (res >= 20)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00D1FFA3);
      //else if (res >= 10)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFFFA3);
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00000000);

      //if (res >= 90)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 80)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 70)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 60)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 50)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 40)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 30)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 20)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else if (res >= 10)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFFFFF);

      //if (res >= 30)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res * 100);
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);

      //if (res >= 30)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res * 100);
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0050B985 + res);
      
      //if (res >= 90)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res);
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res);

      //if (res >= 90)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res * 90);
      //else if (res >= 50)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res * 50);
      //else if (res >= 30)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res * 30);
      //else if (res >= 20)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res * 20);
      //else if (res >= 10)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res * 10);
      //else if (res >= 5)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res * 5);
      //else
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x0043811D + res);

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
int calc_Mandelbrot(double x, double y, t_mlx *mlx)
{
  t_complex z;
  t_complex c; // ガウス平面上の点(a,b)をcと置く。
  int i;

  /**
   * 参考リンク
   * https://tomari.org/main/java/kyokusen/mandelbrot.html
   */

  z.a = 0;
  z.b = 0;
  c.a = x;
  c.b = y;
  i = 0;

  t_complex point; // Vec (Orbit Trap)
  point.a = 0;
  point.b = 0;

  while (i < mlx->iter)
  {
    z = complex_add(complex_multi(z, z), c);

    if (complex_abs(z) >= 2) // 収束
    {
      return (i);
    }
    i++;
  }

  return (0);
}
