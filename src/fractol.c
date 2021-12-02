#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

/* fractolの計算処理などを記述 */
void      draw(t_mlx *mlx)
{
  int i;
  int j;

  // 次の座標を中心にしたい。
  int a = 300 / 2;
  int b = 300 / 2;
  //mlx_mouse_get_pos(mlx->mlx, mlx->win, &a, &b);
  //printf("x: %d, y: %d\n", a, b);

  //printf("max_re: %f min_re: %f max_im: %f min_im: %f\n", mlx->max_re, mlx->min_re, mlx->max_im, mlx->min_im);
  i = 0;
  while (i < mlx->width)
  {
    //double x = (( (i + a/2) * (mlx->max_re - mlx->min_re)) / mlx->width) - ((mlx->max_re - mlx->min_re)/ 2);
    //double x = (( (i + mlx->x_pos) * (mlx->max_re - mlx->min_re)) / mlx->width) - ((mlx->max_re - mlx->min_re)/ 2);
    //double x = ((i * (mlx->max_re - mlx->min_re)) / mlx->width) - ((mlx->max_re - mlx->min_re) / 2);
    double x = ((i * (mlx->max_re - mlx->min_re)) / mlx->width) + mlx->min_re;
    j = 0;
    while (j < mlx->height)
    {
      //double y = (( (j + b/2) * (mlx->max_im - mlx->min_im)) / mlx->height) - ((mlx->max_im - mlx->min_im) / 2);
      //double y = (( (j + mlx->y_pos) * (mlx->max_im - mlx->min_im)) / mlx->height) - ((mlx->max_im - mlx->min_im) / 2);
      //double y = ((j * (mlx->max_im - mlx->min_im)) / mlx->height) - ((mlx->max_im - mlx->min_im) / 2);
      double y = ((j * (mlx->max_im - mlx->min_im)) / mlx->height) + mlx->min_im;

      /**
       * mandelbrot
       */
      double res = calc_Mandelbrot(x, y, mlx);

      /**
       * julia
       */
      //double res = calc_Julia(x, y, mlx);

      if (res >= 20)
        my_mlx_pixecl_put(&mlx->img, i, j, res * 10);
      else if (res >= 10)
        my_mlx_pixecl_put(&mlx->img, i, j, (res * 20));
      else if (res >= 0)
        my_mlx_pixecl_put(&mlx->img, i, j, (res * 20));
      else
        my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFFFFF);

      // Good 拡大してみると分かる
      //if (res % 10 == 0)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFA3A3);
      //else if (res % 10 == 1)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFA3D1);
      //else if (res % 10 == 2)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFA3FF);
      //else if (res % 10 == 3)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3A3FF);
      //else if (res % 10 == 4)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3FFFF);
      //else if (res % 10 == 5)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3FFD1);
      //else if (res % 10 == 6)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00A3FFA3);
      //else if (res % 10 == 7)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00D1FFA3);
      //else if (res % 10 == 8)
      //  my_mlx_pixecl_put(&mlx->img, i, j, 0x00FFFFA3);
      //else if (res % 10 == 9)

      //int k;
      //k = 0;
      //// RGBの調整で開始時の色を選べる
      //// kの大きさの調整で色の変化の勾配を調節
      //while (k < 500)
      //{
      //  if (res == k)
      //    my_mlx_pixecl_put(&mlx->img, i, j, create_trgb(0, 100, 255, 100) - k * 1000);
      //  k++;
      //}

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
  return (-1);
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
  while (i < mlx->iter)
  {
    z = complex_add(complex_multi(z, z), c);
    //a = complex_add(complex_multi(complex_multi(complex_multi(a, a), a), a), z);
    if (complex_abs(z) >= 2) // 収束
      return (i);
    i++;
  }
  return (-1);
}
