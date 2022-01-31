#ifndef FRACTOL_H
# define FRACTOL_H
//# include <mlx.h>
# include "../minilibx-linux/mlx.h"
//# include <X11/Xlib.h>
//# include <sys/ipc.h>
//# include <sys/shm.h>
//# include <X11/extensions/XShm.h>
# include <math.h>

# define KEY_R_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_L_ARROW 65363
# define KEY_DOWN_ARROW 65364

# define KEY_Q 113
# define KEY_ESC 65307

# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef enum
{
	mandelbrot,
	julia,
	tricorn,
}	t_fractal;

typedef struct s_data 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}              t_data;

typedef struct  s_mlx
{
    int         width;
    int         height;
    void        *mlx;
    void        *win;
    t_data      img;
    double         size; // 現状不要。下のパラメータに置き換えたため。

    double	mouse_pos_x;
    double	mouse_pos_y;

    double      max_re;
    double      min_re;
    double      max_im;
    double      min_im;
    
    t_fractal	type;

    double      iter;
}               t_mlx;

typedef struct  s_complex
{
    double  a;
    double  b;
}               t_complex;

/* 複素数 */
t_complex      complex_add(t_complex x, t_complex y);
t_complex      complex_sub(t_complex x, t_complex y);
t_complex      complex_multi(t_complex x, t_complex y);
double         complex_abs(t_complex x);

/* hook関連 */
int hook_keydown(int key, void *mlx);
int close_win(int key, void *mlx);
int get_mouse(int x, int y, t_mlx *mlx);
int get_point(int x, int y, t_mlx mlx);
int hook_mouse(int button, int x, int y, t_mlx *mlx);

/* fractolの描画・計算 */
int calc_Mandelbrot(double a, double b, t_mlx *mlx);
//int calc_Mandelbrot(double *x, double *y, double a, double b, t_mlx *mlx);
int calc_Julia(double x, double y, t_mlx *mlx);
void      draw(t_mlx *mlx);

/* 描画・色の処理 */
void my_mlx_pixecl_put(t_data *data, int x, int y, int color);
int create_trgb(int t, int r, int g, int b);

int		exit_mlx(t_mlx *mlx);

#endif
