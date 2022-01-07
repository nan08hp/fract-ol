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
			return ((1 - pow(1 - (c / mlx->iter), 9)) * 255);
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
		double x0 = ((i * (mlx->max_re - mlx->min_re)) / mlx->width) + mlx->min_re;
		j = 0;
		while (j < mlx->height)
		{
			double y0 = ((j * (mlx->max_im - mlx->min_im)) / mlx->height) + mlx->min_im;

			/**
			 * mandelbrot
			 */
			double res = calc_Mandelbrot(x0, y0, mlx);

			/**
			 * tricorn
			 */
			//double res = calc_Tricorn(x, y, mlx);

			/**
			 * julia
			 */
			//double res = calc_Julia(x, y, mlx);

			my_mlx_pixecl_put(&mlx->img, i, j, res);
			//my_mlx_pixecl_put(&mlx->img, i, j, ((int)res << 16 | 0 << 8 | (int)(res * 0.8)));

			j++;
		}
		i++;
	}
}

/* julia */
int calc_Julia(double x, double y, t_mlx *mlx)
{
	int c;



	c = 0;
	while (c < mlx->iter)
	{
		double tmp = x * x - y * y - 0.3;
		y = 2 * x * y - 0.63;
		x = tmp;
		if (x * x + y * y > 4.0) // 収束
			return ((int)(120 + 20 * y) << 16 | (int)(120 + 20 * y) << 8 | (int)(120 + 20 * y));
		//return ((1 - pow((1 - (c / mlx->iter)), 9)) * 255);
		c++;
	}
	return (0);
}

/* Mandelbrot */
int calc_Mandelbrot(double a, double b, t_mlx *mlx)
{
	double i;
	double x = 0;
	double y = 0;
	double d;

	i = 0;
	d = 8;
	while (i < mlx->iter)
	{
		double tmp = pow(x, 2) - pow(y, 2) + a;
		y = 2.0 * x * y + b;
		x = tmp;

		if (d > pow(y, 2) + pow(x - 0.1, 2))
		{
			//d = pow(x, 2) + pow(y, 2);
			d = pow(y, 2) + pow(x - 0.1, 2);
			//d = pow(x - 1, 2); // > 100
		}

		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			//double log_zn = logl(x * x + y * y) / 2.0;
			//double nu = logl(log_zn / logl(2.0)) / logl(2.0);
			double nu = i - log(log(pow(x, 2) + pow(y, 2))) + 4.0;

			return ((pow((1 - d / 8), 99) * 255));

			//return ((int)((0.5 + 0.5 * cos(3.0 + 0.15 * i)) * 255) << 16 | (int)((0.5 + 0.5 * cos(3.0 + 0.15 * i)) * 255) << 8 | (int)((0.5 + 0.5 * cos(3.0 + 0.15 * i)) * 255));
			//return ((int)((0.5 + 0.5 * cos(3.0 + 0.15 * i)) * 255) << 16 | (int)((0.5 + 0.5 * cos(3.0 + 0.15 * i + 0.6)) * 255) << 8 | (int)((0.5 + 0.5 * cos(3.0 + 0.15 * i + 1)) * 255));
			//return ((int)((0.5 + 0.5 * cos(3.0 + 0.15 * nu)) * 255) << 16 | (int)((0.5 + 0.5 * cos(3.0 + 0.15 * nu + 0.6)) * 255) << 8 | (int)((0.5 + 0.5 * cos(3.0 + 0.15 * nu + 1)) * 255)); // smooth

			//return ((int)((1 - pow((1 - (i / mlx->iter)), 9)) * 255) << 16);
			//return ((int)((1 - pow((1 - ((i + 1 - nu) / mlx->iter)), 40)) * 255) << 16); // Smooth One

			//return ((1 - (1 - (i / mlx->iter))) * 255);
			//return ((int)((1 - pow((1 - (i / mlx->iter)), 40)) * 255) << 16);
			//return ((1 - pow((1 - (i / mlx->iter)), 1)) * 16777215);

			//return (cr(i * 9));
			//return ((int)(1 - ((i / 100) * 255)) << 8);
			//return ((int)((i / mlx->iter) * 255) << 16 | (int)(((i / mlx->iter) * 255) * 0.2) << 8 | (int)(((i / mlx->iter) * 255) * 0.7)); // rgb //  //return (1 - ((i / 100) * 255));


			// Perrinperson
			//return ((int)(x * x * 64) << 16 | (int)(y * y * 64) << 8 | 0);
			// Metalic
			//return ((int)(120 + 20 * y) << 16 | (int)(120 + 20 * y) << 8 | (int)(120 + 20 * y));
		}

		i++;
	}

	//return (0);
	return ((pow((1 - d / 8), 99) * 255));
}
